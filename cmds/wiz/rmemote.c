// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <daemons.h>

inherit CMD;

private void main(string str) {
    string rule;
    if ( !is_directory(wiz_dir(this_user())) )
    {
        out("�Բ���ֻ��ȫְ��ʦ����ɾ�� emote��\n");
        return;
    }

    if (!str) {
        out("�÷���rmemote <verb>\n");
        return;
    }
    sscanf(str, "%s %s", str, rule);
    if (SOUL_D->remove_emote(str, rule))
        out("ɾ���ɹ���\n");
    else out("ɾ��ʧ�ܡ�\n");
}

