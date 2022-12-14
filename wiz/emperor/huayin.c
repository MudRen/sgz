([ /* sizeof() == 33 */
  "riverarea" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 2 */
          "/sgdomain/job/fishing/yufu" : 1,
          "/sgdomain/job/fishing/pound" : 1,
        ]),
      "l" : "
    这是一座窄窄的木桥，看上去似乎刚造不久，要不然走上去还真
有点心惊胆战呢。从桥上往下看，是一条清清的小河，水静静地流淌
着，清澈无比，你还可以看到有许多鱼儿在水底嬉戏。桥上还站着一
个人，看打扮是个渔夫。

",
      "b" : "%^YELLOW%^木桥%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 1 */
          "north" : "southopen",
        ]),
    ]),
  "vhall" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 2 */
          "/sgdomain/npc/shuijing.c" : 1,
          "/sgdomain/modules/m_board.c" : ({ /* sizeof() == 3 */
              1,
              "%^H_GREEN%^新手指%^H_BLUE%^南%^RESET%^",
              "newbie"
            }),
        ]),
      "l" : "
    这里是一间草庐，主人是这个村子里有名的智者--水镜先生。你
放眼看去，只见地上铺着张草席，摆有一几，上面安着一把瑶琴。一
个黑色的香炉放在屋角，整个房间都弥漫着清香。你可以看到东面有
一扇门，通往一间木屋。 

 %^H_GREEN%^新手请先看看%^RESET%^： %^H_CYAN%^help newbie%^RESET%^，%^H_CYAN%^help starts%^RESET%^，%^H_CYAN%^help introduce%^RESET%^。
 新手如果有不懂问题，最好通过 %^H_CYAN%^newbie %^H_YELLOW%^【新手】 %^RESET%^频道进行询问。

",
      "b" : "%^YELLOW%^草庐%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "west" : "vcenter",
        ]),
    ]),
  "vdangpu" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/obj/other/gaoshi.c" : 1,
        ]),
      "l" : "
    这是华阴村的当铺，和其他地方的当铺一样，一进门就可以看到
那独特的一人高的柜台，你必须掂起脚才能将东西送上去。由于连年
战乱，老百姓的日子越来越苦，所以进出当铺的人也多了起来，以至
于门槛都被踏破了。你可以看见在一旁的墙上有一张告示(gaoshi)。

",
      "b" : "%^YELLOW%^当铺%^RESET%^",
      "t" : 2,
      "e" : ([ /* sizeof() == 1 */
          "south" : "vdagu_chang",
        ]),
    ]),
  "vcenter" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/modules/m_board.c" : ({ /* sizeof() == 3 */
              1,
              "%^YELLOW%^巫师通告%^RESET%^",
              "progress"
            }),
        ]),
      "l" : "
    这是小村的中心，往北一直走有一片农田，而向南可以发现一条
小河。西面是一条小路，而东边则是一位智者的居所，平时村民们有
什么紧要的事都会找他商议。

",
      "b" : "%^YELLOW%^小村中心%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 4 */
          "east" : "vhall",
          "south" : "vnangxiao_hang",
          "west" : "vxl",
          "north" : "vroad1",
        ]),
    ]),
  "vnangxiao_hang" : ([ /* sizeof() == 5 */
      "o" : ([ ]),
      "l" : "
    这是一条幽静的小巷，与小村内其他道路不同的是，这里的路面
铺着细细的石子，而且压得十分平整。小巷的东首可以看见一座大大
的庭院，里面住的绝对不是穷人家。西面的一间破屋子里可以听到朗
朗的念书声。往北走是小村的中心，南面就是村口了。

",
      "b" : "%^YELLOW%^小巷%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 4 */
          "east" : "vzhangda_hu",
          "south" : "southopen",
          "west" : "vclassroom",
          "north" : "vcenter",
        ]),
    ]),
  "venter" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/modules/m_board.c" : ({ /* sizeof() == 3 */
              1,
              "西歧帝国通告",
              "nation.west"
            }),
        ]),
      "l" : "
    这是一间简朴的木屋，室内非常宽敞，简单地摆置着一张大大的
木桌和几条板凳，两面的墙上挂着几幅画，虽不是出自名人手笔，但
也比较耐看。这里便是华阴村村长平时待的地方，村里的官员们有了
要紧的事也总是到这里来商量。

",
      "b" : "%^YELLOW%^村长家%^RESET%^",
      "e" : ([ /* sizeof() == 2 */
          "east" : "vshuxia",
          "west" : "hy_lf",
        ]),
    ]),
  "vhuo_tang" : ([ /* sizeof() == 4 */
      "o" : ([ ]),
      "l" : "
    这个厅便是后堂了，不算很大，但布置得非常齐整而又精致，也
许是因为张小姐的闺房就在楼上的缘故。靠着墙依着一张水柳木的方
桌，上面摆着一套茶具，桌子边上是两张高背木椅。椅子旁安着只小
巧的木几，上面是一只细瓷花瓶。你可以看到一边有楼梯通向二楼。

",
      "b" : "%^YELLOW%^后堂%^RESET%^",
      "e" : ([ /* sizeof() == 2 */
          "up" : "vmiss_room",
          "west" : "vliving",
        ]),
    ]),
  "vroad1" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/modules/m_board.c" : ({ /* sizeof() == 3 */
              1,
              "三国榜文",
              "caolu"
            }),
        ]),
      "l" : "
    这是小村的一个路口，向北边望去可以看到一株树冠异常高大的
槐树，而往南边一直走就是小村中心了。西面是座废弃了的磨坊，而
东面则通向一片打谷场。

",
      "b" : "%^YELLOW%^路口%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 4 */
          "east" : "vdagu_chang",
          "south" : "vcenter",
          "west" : "vmill",
          "north" : "vshuxia",
        ]),
    ]),
  "vkitchen" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 5 */
          "/sgdomain/job/digsoil/barrel.c" : 4,
          "/sgdomain/obj/other/luzi" : 1,
          "/sgdomain/job/feedgoat/knife.c" : 2,
          "/sgdomain/job/chopwoods/chuniang" : 1,
          "/sgdomain/job/digsoil/hoe.c" : 2,
        ]),
      "l" : "
    一跨进这间屋子，你就闻到了一股油烟味儿，直冲鼻子，看样子
这里是间厨房。靠墙用泥巴糊起了一只大灶，灶头上凌乱地放着些葱
姜什么的。灶角则堆放着些柴火，是用来生火的。你看到一位厨娘正
忙前忙后，烧饭做菜。

",
      "b" : "%^YELLOW%^厨房%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "north" : "vliving",
        ]),
    ]),
  "vfield" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 2 */
          "/sgdomain/npc/farmer" : 1,
          "/sgdomain/job/digsoil/soil" : 1,
        ]),
      "l" : "
    这里是华阴村的东首，几乎没有人住在这里。你所能看见的就是
一片广阔的土地，有几名农夫正在土地上辛勤地劳作。不过华阴这一
带，地广人稀，土地翻得还不透彻，所以每年的收成都不理想。看来
他们正需要人手帮忙。

",
      "b" : "%^YELLOW%^农田%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 1 */
          "south" : "vshuxia",
        ]),
    ]),
  "vsl" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/job/chopwoods/woods.c" : 1,
        ]),
      "l" : "
    眼前是一片树林，也不知是谁在多少年前种的，不过现在看来野
生野长的相当茂盛。平时东面小村里的村民会到这里来砍些柴火回去
烧火作饭，不过多数时候这里都是静悄悄的，只能听到那些不知名的
小鸟在『啾啾』地唱。

",
      "b" : "%^YELLOW%^树林%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 2 */
          "east" : "vxl",
          "west" : "vsl1",
        ]),
    ]),
  "vmill" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 5 */
          "/sgdomain/job/makedoufu/fan.c" : 1,
          "/sgdomain/job/makedoufu/mutong.c" : 1,
          "/sgdomain/job/makedoufu/shimo.c" : 1,
          "/sgdomain/job/makedoufu/guozi.c" : 1,
          "/sgdomain/job/makedoufu/gfz.c" : 1,
        ]),
      "l" : "
    这是一间相当陈旧的磨坊，磨坊中间有一只沉重的石磨，看样子
拉磨的驴再也找不回来了，只有靠自己来推磨了，你不由想起了那句
有钱能使。。。的俗话。从磨坊的门看出去能看到一棵高大的槐树。

",
      "b" : "%^YELLOW%^磨坊%^RESET%^",
      "e" : ([ /* sizeof() == 2 */
          "down" : "vcave",
          "east" : "vroad1",
        ]),
    ]),
  "vweapon_room" : ([ /* sizeof() == 4 */
      "o" : ([ ]),
      "l" : "
    这实在是间相当简陋的屋子。屋子中央是一只烧铁用的炉子，墙
角是一只用来冷却的水缸，一旁便是架得高高包着铁皮的桌子，铁匠
就是在这上面敲打那些铁砧的。

",
      "b" : "%^YELLOW%^铁匠铺%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "south" : "vxl",
        ]),
    ]),
  "vkedian" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/obj/other/bed" : 1,
        ]),
      "l" : "
    这里是华阴村的客店，是为过路的旅人提供休息的地方，店里收
拾的还算干净，没有其他什么摆设，只是安放着人们休息所最需要的
东西——床。你可以放心地在这里睡上一觉，然后继续赶路。

",
      "b" : "%^YELLOW%^客店%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "east" : "southopen",
        ]),
    ]),
  "vhuaishu_shang" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/obj/other/sticks" : 1,
        ]),
      "l" : "
    老槐树枝叶茂盛，在树顶形成一宁静幽雅的天然树屋，你不禁赞
叹到：真是一个好所在。不过当你往下看的时侯，觉得有点头晕，好
象太高了一点。

",
      "b" : "%^YELLOW%^槐树上%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "down" : "vshuxia",
        ]),
    ]),
  "vshuxia" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 2 */
          "/sgdomain/job/choppork/zth.c" : 1,
          "/sgdomain/npc/kid2" : 1,
        ]),
      "l" : "
    村前的一块空地上长着一棵大槐树，有三人环抱那么粗，看上去
至少有好几百岁。村中的小孩常在树下嬉耍。夏日傍晚之时，也常有
村中长者坐在树下纳凉长谈。北边是一片农田，东边有个小池塘，西
面有间木屋，南面通向华阴村。

",
      "b" : "%^YELLOW%^老槐树%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 5 */
          "east" : "vchitang_bian",
          "south" : "vroad1",
          "up" : "vhuaishu_shang",
          "west" : "venter",
          "north" : "vfield",
        ]),
    ]),
  "southopen" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/modules/m_board" : ({ /* sizeof() == 3 */
              1,
              "三国排名榜",
              "ranks"
            }),
        ]),
      "l" : "
    这里是一个华阴村的最南面，再往南有一条小河拦住去路，不过
上面有一座木桥。往北面就可以进入小村的中心了。你可以听到东面
传来一阵阵的马嘶，那是驿站所在。如果你累了，也可以到西面的客
店去休息一会儿。

",
      "b" : "%^YELLOW%^南村口%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 4 */
          "east" : "vyizhan",
          "south" : "riverarea",
          "west" : "vkedian",
          "north" : "vnangxiao_hang",
        ]),
    ]),
  "vmiss_room" : ([ /* sizeof() == 4 */
      "o" : ([ ]),
      "l" : "
    一股香气，不可避免地钻入了你的鼻子，令你有些晕晕乎乎的感
觉。没错，这里便是主人的女儿——张小姐的闺房。四处的摆设都是
那么的精致，床上挂的是绣了花的帐子，一旁是一个雕着镂空图案的
梳妆台，从上面搁着的铜镜你似乎能看到自己的身影。待在这间房间
里，你不由得轻手轻脚起来。

",
      "b" : "%^YELLOW%^闺房%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "down" : "vhuo_tang",
        ]),
    ]),
  "vzhang_fang" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/job/digsoil/sir" : 1,
        ]),
      "l" : "
    一走进这间屋子，你就觉得有点不自在。一张长长的木桌后面坐
着一位精瘦的穿着长袍的中年人，正用他那眯缝眼上上下下地打量着
你。桌子上堆着一些帐本，一旁还有一把用铜皮镶边的算盘，原来这
里就是帐房。

",
      "b" : "%^YELLOW%^帐房%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "south" : "vliving",
        ]),
    ]),
  "vwood_room" : ([ /* sizeof() == 4 */
      "o" : ([ ]),
      "l" : "
    你走进了一间简单的屋子，说它简单其实一点也不过分，因为它
空空荡荡，除了一张桌子和椅子以外什么都没有，只是屋子中央背着
手站着的那个人引起了你的注意。

",
      "b" : "%^YELLOW%^木屋%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "south" : "vzhu_lin",
        ]),
    ]),
  "vchitang_bian" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 3 */
          "/sgdomain/job/feedgoat/yang.c" : 1,
          "/sgdomain/job/feedgoat/grass.c" : 1,
          "/sgdomain/obj/other/vpool" : 1,
        ]),
      "l" : "
    你现在正站在景色秀丽，碧波荡漾的池塘边。每年的夏季，池中
荷花盛开，娇艳多姿，令人驻足。轻风徐徐吹来，令池面泛起阵阵涟
漪。你突然有种想痛痛快快在池塘内游一番的欲望。

",
      "b" : "%^YELLOW%^池塘边%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 1 */
          "west" : "vshuxia",
        ]),
    ]),
  "vyizhan" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 1 */
          "sgdomain/yizhan/mafu.c" : 1,
        ]),
      "l" : "
    说是驿站，其实不过是间简陋的用茅草和木条搭起来的棚棚，棚
下用粗粗的竹子围起，权且作为马栏，驿站用的马就随便地放养在里
面。一边站着一个小伙子，看上去象是赶大车的，你如果想去什么地
方的话，可以问问他。

",
      "b" : "%^YELLOW%^驿站%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "west" : "southopen",
        ]),
    ]),
  "vzhu_lin" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/modules/m_charnpc/guard" : 1,
        ]),
      "l" : "
    这是个秘不透风的小竹林，你踩在林中的落叶上，偶尔发出『沙
沙』的声音；从竹叶间透过的丝丝阳光在空中形成一个个光斑，好似
蝴蝶在飞舞。你深深吸了口气，暂时忘记了人间的烦恼。对了，这里
还有一间木屋，进去看看吧。

",
      "b" : "%^H_GREEN%^竹林%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 2 */
          "enter" : "vdagu_chang",
          "north" : "vwood_room",
        ]),
    ]),
  "vsl1" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/job/chopwoods/woods.c" : 1,
        ]),
      "l" : "
    眼前是一片树林，也不知是谁在多少年前种的，不过现在看来野
生野长的相当茂盛。平时东面小村里的村民会到这里来砍些柴火回去
烧火作饭，不过多数时候这里都是静悄悄的，只能听到那些不知名的
小鸟在『啾啾』地唱。

",
      "b" : "%^YELLOW%^树林%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 1 */
          "east" : "vsl",
        ]),
    ]),
  "vclassroom" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/npc/kongyiji" : 1,
        ]),
      "l" : "
    一间不大不小的草房，看起来破旧不堪。屋内摆着几张矮小的木
桌和板凳，几个小孩童趴在上面。有的在『呓呓呀呀』地念书，有的
则三三两两在一起互相打闹。一边的椅子上坐着个瘦瘦的老头，看打
扮象个书生的样子，似乎对一切都漠不关心，只是盯着手中拿的一本
发黄的破书。

",
      "b" : "%^YELLOW%^村私塾%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "east" : "vnangxiao_hang",
        ]),
    ]),
  "vstore" : ([ /* sizeof() == 4 */
      "o" : ([ ]),
      "l" : "
    你走进村中唯一的一个小店，因为村中人少，这里的生意也不太
好。店小二正懒洋洋地坐在一旁打瞌睡。房间的一角有个大水缸。看
来可以灌水。

",
      "b" : "%^YELLOW%^小店%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "north" : "vxl",
        ]),
    ]),
  "vliving" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/npc/zyuanwai" : 1,
        ]),
      "l" : "
    这是一间宽敞的厅堂，平时主人就在这里接待客人，虽然是大户
人家，但布置得也不奢华，只是简单的两排高靠木椅，一边的茶几上
茶具齐备。转过一旁的屏风大概就是后堂了，而走出前庭的门便是院
子了。

",
      "b" : "%^YELLOW%^前庭%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 4 */
          "east" : "vhuo_tang",
          "south" : "vkitchen",
          "west" : "vzhangda_hu",
          "north" : "vzhang_fang",
        ]),
    ]),
  "hy_lf" : ([ /* sizeof() == 4 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/prison/yuzu.c" : 1,
        ]),
      "l" : "
",
      "b" : "%^YELLOW%^牢房%^RESET%^",
      "e" : ([ /* sizeof() == 1 */
          "out" : "/a/huayin/vroad1",
        ]),
    ]),
  "vcave" : ([ /* sizeof() == 4 */
      "o" : ([ ]),
      "l" : "
    你借着光亮看去，四周的墙壁非常粗糙，隐隐地渗出水来。水滴
落在地板上，发出『哒哒』的声音，令人凭空产生种奇怪的感觉。当
你发觉这里看上去没有任何出口时，不由得心中一沉。

",
      "b" : "%^YELLOW%^密道%^RESET%^",
      "e" : ([ /* sizeof() == 2 */
          "down" : "/wiz/suicide/horseroom",
          "up" : "vmill",
        ]),
    ]),
  "vdagu_chang" : ([ /* sizeof() == 5 */
      "o" : ([ ]),
      "l" : "
    你走到一个打谷场中，打谷场中间有一个高高的麦垛，农夫们都
回家休息去了，这里静悄悄的，只有几只鸡在地上找麦粒吃，谷场东
面有一片小竹林，竹林中隐隐可以看到几间小房子。南面有一间新建
的房子，好象是钱庄。

",
      "b" : "%^YELLOW%^打谷场%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 4 */
          "east" : "vzhu_lin",
          "south" : "vbank",
          "west" : "vroad1",
          "north" : "vdangpu",
        ]),
    ]),
  "vbank" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 1 */
          "/sgdomain/obj/other/sign.c" : 1,
        ]),
      "l" : "
    这里是华阴村唯一的钱庄，由于信誉良好，故生意相当不错。你
还没跨进门槛，就看到一面大大的门幅：王记。在钱庄内，每个人都
自觉地保持安静，办完事就离开。只有两三个年轻力壮的小伙子，踱
着步四处巡视着。你注意到墙上贴着一则告示(gaoshi)。

",
      "b" : "%^YELLOW%^钱庄%^RESET%^",
      "t" : 3,
      "e" : ([ /* sizeof() == 1 */
          "north" : "vdagu_chang",
        ]),
    ]),
  "vzhangda_hu" : ([ /* sizeof() == 5 */
      "o" : ([ ]),
      "l" : "
    这里一片开阔，结实的黄泥地上铺着六角形的石砖，显得异常的
整洁，平时还有家丁打扫。一旁的空地上种着几株槐树，高高大大的
似乎也有些年月了。东面是一间宽敞的屋子，是主人用来迎接客人的
地方，而向西走出门去就是小巷了。

",
      "b" : "%^YELLOW%^前院%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 2 */
          "east" : "vliving",
          "west" : "vnangxiao_hang",
        ]),
    ]),
  "vxl" : ([ /* sizeof() == 5 */
      "o" : ([ /* sizeof() == 2 */
          "/sgdomain/job/weavesandals/straws.c" : 1,
          "/sgdomain/job/weavesandals/oldman.c" : 1,
        ]),
      "l" : "
    这是一条小路，平时一下雨就变得泥泞不堪，没法走路，所以现
在村民们在路上铺了不少稻草，总算是好了一些。小路的南面有家小
铺子，东面就是村中心，向西一直走是片树林。

",
      "b" : "%^YELLOW%^小路%^RESET%^",
      "t" : 1,
      "e" : ([ /* sizeof() == 4 */
          "east" : "vcenter",
          "south" : "vstore",
          "west" : "vsl",
          "north" : "vweapon_room",
        ]),
    ]),
])
