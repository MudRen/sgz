#include <mudlib.h>
#include <daemons.h>

#define WARMAP_GENERATOR "/wiz/flee/menu/makemap.c"
#define TMP_DIR          "/tmp/tmp_warroom/"
#define FILE		 "inherit \"/wiz/flee/warjob/out_war_grid.c\";"

inherit CMD;
inherit M_GRAMMAR;

private void main()
{
	int i, j;
	string fn;
	mapping *mapinfo;
	mixed data, tmp;
	object war_grid, room1;

	mapinfo = ({(["shape":4, "size":20, "type":"��" ]), 
			(["shape":4, "size":20, "type":"��" ]),
			(["shape":4, "size":20, "type":"��" ]),
			(["shape":4, "size":20, "type":"��" ]),
			(["shape":4, "size":20, "type":"��" ]),
			(["shape":4, "size":20, "type":"��" ]),});
	fn = TMP_DIR+this_body()->query_primary_id()+".c";
	if( file_size(fn)!=-1 ) rm(fn);
	write_file(fn, FILE);

	war_grid = load_object(fn);
	data = load_object(WARMAP_GENERATOR)->main(mapinfo, 0, 0);
	war_grid->create_new_warmap("PLAYER_"+this_body()->query_primary_id(), data);
	tmp = ({ });
	for(i=0; i<sizeof(data); i++){
		tmp+= ({({ }) });
		for(j=0; j<sizeof(data[i]); j++){
			tmp[i]+= ({ (["m":data[i][j], "t":({ }), ]) });
		}
	}
	if( MAP_D->add_tmp_city("PLAYER_"+this_body()->query_primary_id(), tmp)!=1 ){
		write("too many tmp warmap already! \n");
		return;
	}

	room1 = war_grid->virtual_create("1/1");
	this_body()->move(room1);

	return;
}
