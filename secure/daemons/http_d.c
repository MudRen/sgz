// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * Originally the utility port handler for the i3 router 
 * Cowl@Orion
 *
 * 11-19-95 Cowl: Added args for gateways
 * 12-27-95 Cowl: added home dirs for wizards and converted
 *                to a web server ( almost )
 * 01-05-96 Cowl: Converted socket to a binary, for graphics
 *                save for a minor bug, convert_to_actual_path() works.
 * 01-07-96 Cowl: fixed convert_to_actual_path()
 *                added gateway security 
 * TODO: 
 *      * Hit logging and related stats
 *      * Support for multiple arguments to cgis
 *      * Support for large (larger than max buffer size) files
 *      * Better Error handling (only 404 so far ;) )
 */

#include <ports.h>
#include <socket.h>
#include <http_d.h>

private static object http_sock;

// figures out what is being requested, and how to get there
private nomask string convert_to_actual_path(string path) {
    string file;
    if(path == "/")
        return HTTP_ROOT+"/"+DEFAULT_PAGE;
    if(path[<1] == '/')
        path = path[0..<2];
if(path[<4..<1]==".cgi") path=path[0..<4]+"c";
    if(path[<1] == 'c') /* this is ugly, but works for now */
        file = SECURE_CGI_DIR+"/"+explode(path, "/")[<1];
    else {
        if(path[1] == '~') {
            string user;
            if(sscanf(path[2..], "%s/%s", user, file) == 2)
                file = WIZ_DIR+"/"+user+HTTP_USER_HOME+"/"+file;
            else
                file = WIZ_DIR+"/"+path[2..]+HTTP_USER_HOME;
        }
        else 
            file = HTTP_ROOT+path;
    }
    /* if its a dir, so we want the default page */
    if(file_size(file) == -2) 
        (file[<1] == '/') ? file += DEFAULT_PAGE : file += "/" +
DEFAULT_PAGE;
    return file;
}

private nomask void http_read(object socket, buffer data) {
    string ver, file, extention, args, request;

    if (!data) return;
    // initial connect
    request = read_buffer(data);
    if ( !request )
        return;

    // We arent doing anything with the HTTP version  
    if ( sscanf(request, "GET %s %s", file, ver) !=2 )
        return;
    sscanf(file, "%s?=%s", file, args);
    file = convert_to_actual_path(file);
	if(sizeof(args)) args=WEB_D->url_decode(args);

    if ( file_size(file) < 1 ) {
        socket->send("<title>404 Not found</title><h1>404 Not found<h1>"+
                     "<p>The requested URL was not found\n");
        socket->remove();
        return;
    }
    sscanf(file, "%s.%s", file, extention);
    // if it's extention is '.c' then we assume it is a gateway and
    // we send the output of the gateway object's main() to the client.
    // if the extention is anything other than '.c' we'll treat it as
    // an HTML document. gateways can only be called from a secure dir.
    switch(extention) {
        string result, err;
        case "c":
        case "cgi":
            if(args)
                err = catch(result = call_other(file, "main", args));
            else
                err = catch(result = call_other(file, "main"));
            if ( !result )
                result = "<title>ERROR</title><h1>Error in gateway</h1>" +err;
            socket->send(result+"\n");
            socket->remove();
            break;
		case "gif": {
			string send;
			send=sprintf("HTTP/1.1 200 OK\r\n"
               "Server: Lima/1.0\r\n"
               "Connection: close\r\n"
               "Content-Type: %s\r\n"
               "Content-Length: %i\r\n"
               "\r\n",
               "image/gif",
               file_size(file+"."+extention));
			  socket->send(send);
			  socket->send(read_buffer(file+"."+extention));
			  socket->remove();
			}
			break;
        default:
            socket->send(read_buffer(file+"."+extention));
            socket->remove();
            break;
    }
}

private nomask void http_close(object socket) {
    // add logging or something later 
}

nomask void remove() {
    http_sock->remove();
}

nomask void create() {
    string ret;
    ret = catch(http_sock = new(SOCKET, SKT_STYLE_LISTEN_B, PORT_HTTP, 
                                (: http_read :), (: http_close :)));
    if ( ret ) {
        if ( http_sock ) {
            http_sock->remove();
            http_sock = 0;
        }
        error(ret);
    }
}

// added to stop daemon from cleaning itself up

int clean_up() {
    return 0;
}
