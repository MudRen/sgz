// base.c for players by fire on 30/Jan/2000

inherit CMD;

private void main()
{
        string f_name;
        object ob;
        f_name=file_name(this_body()->query_room());
        if(f_name!="/a/huayin/vhall") {
                write("ֻ�дӲ�«���ܽ��벩��ݡ�\n");
                return;
        }

        this_body()->simple_action("$N������ݳ�ʥȥ�ˡ�\n");

     ob = load_object("/sgdomain/museum/yard");
         if(objectp(ob)) {
                        this_body()->move(ob);
                this_body()->do_game_command("look");
                        this_body()->other_action("$N�����˲����\n");
         }
     return;
}

