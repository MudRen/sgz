// /wiz/roro/workroom.c
// roro 1999

inherit ROOM;
#include <ansi.h>
void setup(){
    set_area("roro_home");
    set_light(50);
    set_brief("云渺海");
    set_long("远处,是一片飘渺不定的云海.如丝,如梦,就象"
"人生一样让人琢磨不定.来到这里,我们一起感受大自然的神奇,"
"领略清风带给我们的舒畅.聆听花儿的呼吸,享受小鸟的耳语,亘"
"古的星空下,我们写下自己的传奇.感谢上苍赐于我们生命,让我"
"们可以谱写自己的乐章,阳光下,我们快乐高歌,月光下,我们演绎"
"人生,生命如此美妙,让人甘之如饴,我们无悔无怨的付出,只为一"
"段燃情的岁月,人生坎坷,我们淡然以对,看破红尘,依然笑傲江湖."
"用平静的心去感悟世界的精彩,留下的是一份刻骨铭心的爱."
"         梦醒时分,我终于明白,爱并非是无至尽的.");

    set_exits( ([
        "out" :  "/domains/std/wizroom.c"
            ]) );
}                
string query_board()
{
     return "/wiz/roro/workroom.c";
}


