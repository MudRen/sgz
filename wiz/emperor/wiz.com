---
����: Fire
��Ŀ: play
����: Sun Dec 20 04:25:42 1998
���ڹ����ƻ�
ʥ�������ϵ��ˣ����˾������꣬��һ��ʱ�伸λWIZ��������
�����Ǽƻ�����һ����ʽ���Ų��԰棬Ϊ�˲�ʹ��һ�ƻ��ٶ�
���ڣ�������Ҫ����һ���Ĺ�����ȷһ�¡�
������ȷһ�㣬���԰治����ʽ�棬����Ҫ������еĲ��֣�
ֻ��Ҫ�������ܹ������ֳɳ�����������Ĳ������ݾ����ˡ�
������һ�����ֳ�Ϊ���֣���һ���̴�ԼΪһ�����£�����Ӧ��
�������һЩ�µ����ݡ�
�����ڵ���ʽ�棬���ǻ���Ҫ��ʵ�������²��֣�
1 ����ϵͳ��
1.1 ��������������е���Ұ����ļ�������ȱ�ٵĲ��֣�����
ʹ�����ļ����������ᡣ
1.2 ���µĲ�����ɺ󣬿���WIZ���踽����Ӧ����Ұ�����
1.3 ��������ָ�ʹ֮����ʵ�á�
2 Basic JOB
�ƻ���10�ֲ�ͬ�Ļ���JOB����Ҫ�����ǽ�Ǯ������һ�������ͼ��ܡ�
3 MId level JOB
�м�JOB�ּ����ࣺս����(������ѵ�����˷�)��������(����ũҵ��
��ҵ�����֣���ҵ��)����ҵó��(������Ʒ����ҵͶ��)����������
(��飬Ѳ�ߣ����ţ��������ˣ�����)��
4 ����
���������£���ҳ����
��Ϊʱ��������ǲ�������ɸ�������ݣ�ֻҪ���������������
��80%�������Կ��Ų��԰��ˡ�
�����ţ�
�ҽ��������ϵͳ��ͬʱдһЩ���������£��Ҳ���������ҳ��Ҳ��
��Ҳ��JAKEY��æ���Ƚ�������д���ˣ��Ϳ����õ���MUD��BBS����
������ȥɢ��
����JOB�Ѿ����������ʣ�µ���������Ͽ����հᣬ��Щ��Ҫ��ROW
�����Һ�FLEE�ᾡ��֧�֡�FLEE�ľȻ𣬺��������Ӿ���ԸĽ�һ
�µ�����JOB��ROW������Ʋ�Ь����Щ����ɺ�ֻ���ڼ������Ϳ���
�ɼƻ�(XIXI)
�м������Ƚϸ��ӣ��ҽ�����ս�������ҵó�ס�FLEE�����ؿ�����
�����壬������Ҫ�������������ͬʱ������߸��˵ļ���������
��Ҫ��ߵ���(��������)��ʵ����FLEE��������������м�JOB������
ϣ���м�JOB�ܹ������ܵ������е�char_d,area_d,��ϵͳ�໥�ܺϣ�
��Ҳ���ڿ�ʼ���ʱ��Щ���ѣ������ڳ�Զ�ķ�չ������ġ������
�ᾡ��֧��FLEE��ʹ������JOB��������ϵͳ���ܺϡ�Task_d �Ƚ��鷳
���Ҳ�̫�ȶ�����char_d��ƵýϿɿ���������������˭�ļȶ�����
����ɣ�˭�͸���ɡ�
������WIZ����Ҫ���Ƶ������䡣
�ֽ׶ι�����Ҫ������Щ��addoil all


---
����: Tset
��Ŀ: temp leave
����: Sat Dec 19 21:26:02 1998
leave about 1 month...maybe back earlier :)


---
����: Tset
��Ŀ: fishing job done
����: Wed Dec 16 01:26:26 1998
as title...please check
ask of the �ظ���Сʱ������Լ�����...this latency
period should be default...hope flee can add it in JOBD
somewhere, since feedgoat, chopwoods, waterflower, and
now fishing all assume this


---
����: Tset
��Ŀ: >good work tset
����: Wed Dec 16 01:22:09 1998
void stop_busy()
	stops busy time


---
����: Stefan
��Ŀ: >any comments?
����: Mon Dec 14 17:44:06 1998
This sounds terrific!!!!

Microsoft wants to buy out TMI-2 and LPC, and want all the existing
LPC based mud to cease operation, that is VERY FUNNY!!!

This memo was dated august 1998, what is current status?
I am eager to know more...

Let's see if Microsoft can dominate the MUD world.


---
����: Tset
��Ŀ: about busy time
����: Sat Dec 12 22:27:38 1998
void start_busy(int n, mixed msg)
    n - busy length
    msg - busy message to be shown to user

eg, start_busy(30, ({ "��æ�ú��ء�"", "���Ķ��ã������ܡ�" }))

mixed query_busy(int shown)

Right now all verbs are disabled if user are busy, so
can't move, can't do score, etc, but commands are not
disabled, so user can chat and talk.  Note this will create
some problems with commands under /cmds/player/, a way
to solve the problem is in the command, use the function
check_condition(), and if it doesn't return 0, return what
that function returns.  This can be applied to fly.c (you
cannot fly when you are busy).  Also, anyone needs a way
to interrupt busy time?


---
����: Flee
��Ŀ: good work tset
����: Sun Dec 13 22:02:01 1998
yeah, i need the way to interupt one's busy.. :)
addoil test.


---
����: Stefan
��Ŀ: I will be back
����: Wed Dec 16 16:26:37 1998
Early January. I will be on holiday leave.

stefan


---
����: Yuner
��Ŀ: Leave
����: Sat Dec 26 06:20:59 1998



---
����: Tset
��Ŀ: posts from the other sanguo mud(6)
����: Sun Nov 29 21:48:42 1998
[29] һЩ������������Ľ���                   �����(darken)(Thu Nov 12)
----------------------------------------------------------------------
                     һЩ������������Ľ���

���������еĽ�����ʷ��д�Ĳ��࣬���ü�д�㡣

����

����  ����һ��ʱ���ǹ����޵ģ�����Ҳдһд����
������ȫ���εĽ��죬��ı�ԣ�Ҳ�������������ģ�
Ϊ�������롣��������ƽ��ƽ�ҵ�������������á�
str 90��int 80��def 80

����  Ԭ�ܵ��½������ĳ��������������ɣ�������
���׸�װ�ε�����Ҳ����ж����㣬������նɱ
�����鵽���Ǹ������ұ����ҵ���
str 90��int 20��def 30

�ĳ�  �������������ͽ���������ն���ĸ����꣬
������һ����ɱ��ɥ�������鵽���Ǹ������ұ���
�ҵ���
str 90��int 30��def 30

ɳĦ��  �Ϸ����������䣬������������־�м�����
ʹһ�����������鵽�ɶ��Ϸ�ȥ�ҡ�
str 80��int 50��def 40

����  ��谽��죬�ں��ŷɵ�����Ĳ��������ᣬ����
�ŷɣ����������������ڳɶ��������ߣ���Ӯ�˾���
�õ���
str 80��int 70��def 60

����  ��谽��죬��������Է���������ɱ����ͳ����
�������������������ĵ��ǽ������鵽����ȥ�ң�����
�����ķ������������������롣(�ÿ���:))
str 60��int 80��def 70

�ӵ�  ���ڲ������ں��������Ǳ��ܲ��ҵ������ܡ���
����׷��սʱ���������ˮ����ɢ������һ�˳��Ϲ���
��С������ɱ�ز��ɶ�����������������������ɱ��
�����ں����ҵ����ҵ�һ��(����)�����ʹ�á�
str 90��int 40��def 30

����

�ź�  Ԭ�ܽ��죬�������˲ܲ١�����ƽ�ط��أ�ʱ�ĺ�
Ԩ���������ܵ�����廢��������ȴ��֧�ŵ��ܲٴ����
�ȡ���������Ƥ�����ҵ���
str 80��int 70��def 80

����  ������κ�Ľ��죬Ӧ�ò�����д�ģ�����ͻȻ�뵽
��ǰ����д������Ҫ����һ�� :)  �����ڿ�������ɽʱ��
�²֣�����ǧ��������������ʮ���˵��ڳ²����ϣ�ʹ
֮���ݲ������Ѷ��˱���yeg ˵��ʱ���ӣ��Ͳ�д�����ˡ�
str 60��int 80��def 80

�߸�  Ԭ������ܳ��Ľ��죬���ز��ݣ��ں�����ܲٵ�
�����ս���࣬���˲ܾ��ͽ��ֽ�������ܾ��Ĳ߷�����
������Ǽ����ɱ�������ڽ��������ҵ���
str 70��int 70��def 80

����

���  Ԭ��ıʿ��ֱ�Բ��䣬����Ԭ����ɱ���ܲ��ڹٶ�ʤ
���ᣬ��̾�������������ñ��֮�ƣ�ʤ����δ��֪����
�����ܲ�Ҳ�ɵ����ֵ�ıʿ����������Ƥ�����ҵ���
str 20��int 90��def 30

����  Ԭ��ıʿ����Ԭ���н������������ң�ȴҲ������
�á���������ƶ��������ɡ��ٶɱ������������������ܲ�
ն�ס������ڳ�����Ѱ�ҡ�
str 30��int 80��def 20

¬ֲ  ��ĩ�ĺ��ڴ��壬��߾ųߣ�������ӣ���ŶԶ�׿
�ķ��������ϳ���͢���Ს���������ڳ����ҵ���
str 50��int 90��def 30

��������Խ  ����ı��ͣ�������ʿ���ھ��ݽ�����Ͷ���ܲ�
���Ǿ�����һ���Ĵ��壬��������������������һ���ҵ���
str 20��int 80��def 20

�й�����
       ���г��������� npc ���У�manage ���ٶȱ����������
���в��ȵļӿ죬������lsp��


---
����: Fire
��Ŀ: about money
����: Mon Nov 30 16:26:30 1998
Now i have adjust sth for the money.
so a ppl can not give money to other
ppl and npc and can not drop money.
If we need some npc can accpet money and
for quest and job (such as Kong Yiji) 
then we can use the function set_accept_money(1);
in the setup of that npc and this can also
be call after the object is created
if an living( can be npc and player) has been
set as accept money others can use give amt monty to sb
(emaple: give 5 silver to kong) to give that
living money
cheers


---
����: Fire
��Ŀ: the new warroom desc
����: Tue Dec  1 15:43:59 1998
Tset has finished the new desc of war room, all I can
say that it is amazing and splendid.
But there are still something that can be added
to improve the display. for example. now
a ppl can see the approxmate number of solider
in this ceil, but he can't see how many troops
and which troops are in this cell. later
we will add cmd so that two troop can merge into one
and one troop can split to two and also 
can send command to NPC controled troop
and we will discuss that later
thank tset
admire tset
addoil tset


---
����: Fire
��Ŀ: char's auto action
����: Tue Dec  1 17:39:50 1998
I have make npc char can auto move and do
semote in fact we can do it more complex
this is in /sgdomain/modules/m_charnpc/m_charaction.c
any suggestion ?


---
����: Fire
��Ŀ: huayin viliage moved !!!
����: Wed Dec  2 16:28:42 1998
I have moved huayin viliage (the viliage when ppl login)
to /sgdomain/area/guan/huayin/ so all the sanguo area
now is under /sgdomain/area. Now it seem ok, If 
someone find something wield, please let me know.

Thanks


---
����: Fire
��Ŀ: About yizhan
����: Wed Dec  2 16:33:27 1998
Group has done a very nice work.
Sweat group
But there are something need to be noticed
1 huayin viliage (the start point) doesn't have yizhan
2 luoyang has two yizhan (one is old fake one) one is 
  new one
3 all the area map doesn't show the position of yizhan

Could Group please concern them and solve them as soon
as possible. when these are done. the fly will become
the wizards luxury. grin
addoil group


---
����: Row
��Ŀ: about yizhan
����: Wed Dec  2 20:06:51 1998
��վ �

    ���������ˮ�ǵ���վ�ˣ�һƬææµµ�������˺���˻����
ԯ�ꤡ�����ż���������һ����̨������Ļ����æ�������к���
�ˣ���̨���ǽ��������ֽ��������ŵ����صļ�Ŀ�������治ʱ��
�����߽��߳������ﻹͣ���Ÿ��ִ��õ������������ȥ���Ƕ���
���ˡ�

hi group,

there is yizhan in some cities which i made b4 to put mafu and
carter, now it's ur work :), i would like u put them in the original
yizhan, coz i already had them shown in the map. for those cities
i did not put yizhan, please rewrite the map and copy the desc
from the original ones. i know this will bring u extra work, but i
will be appreciated if u do it. thank u very much.

                                         row


---
����: Fire
��Ŀ: the files under /daemons
����: Sat Dec  5 13:28:29 1998
I clear all the back up files under /daemons in order to
make i rest clear and find that there are two files
stranger under /daemons
one is [get]  another is [get *] don't know what are these 
and can't use more to check. 
could stefan please have a check and if useless please remove
them?
thanks


---
����: Fire
��Ŀ: about the clean up
����: Wed Dec  9 17:37:11 1998
I am not sure how the clean_up works, but
it really keep the total number of the objects
in a reason range. for my obversion. now the total
number of objects is keep about 1000 or so in the
system. If there are much more than 1000 objects
in the memory, then the system will high possible
use clean_up to destroy some objects
this is harmful to some job systems and war, since
because some time the object record some situation 
and if this object disapperad and reappear some setting
may be not right. for example, if you ask somebody
for a job, then your name is recorded as the employee
in the employer object. but then if this employer
is destoried and reappear, you can't be remember as
his employee. this will cause bugs.
Now I have make some adjustment in the object.c
and container.c and add two functions
int query_clean_up()
void set_clean_up(int p)
the first one we don't bother it in most case( the
system will handle)
but for the second one, if you don't want your object
be clean_uped so just add
set_clean_up(1); in your object's code.
then it will not be destoried unless you intend to
do so (hope this works)
please check:
/sgdomain/job/digsoil/sir.c and
/sgdomain/job/digsoil/soil.c for reference
best regards


---
����: Group
��Ŀ: water flower
����: Thu Dec 10 05:16:42 1998
waterflower job has been finished. 
i put the hua jiang in luoyang ly_dhl
the directry is waterflower/
please check it. if no problem, i will finish the help file soon.


---
����: Fire
��Ŀ: about feedgoat
����: Thu Dec 10 15:26:31 1998
that is a very good work, addoil flee
but there is a little bug
1 when you give grass to goat and if you don't have grass
then will give error message
like this
[errors] (firex) Error logged to /log/runtime
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /sgdomain/job/feedgoat/goat#7564 at line 38
if you have two grass withyou will cause similar bugs
2 from the employee the message is :
> С���ڲ��ԵĽ���������ȥ������ǿ��ˡ�
shoud be > С������Ľ���������ȥ������ǿ��ˡ�

anyway this is a very nice job
addoil flee


---
����: Fire
��Ŀ: >water flower
����: Thu Dec 10 15:35:00 1998
On Thu Dec 10 05:16:42 1998 Group wrote post #281:
> waterflower job has been finished. 
> i put the hua jiang in luoyang ly_dhl
> the directry is waterflower/
> please check it. if no problem, i will finish the help file soon.
good group,
write your help about this job and let's players
to test
addoil xixi


---
����: Tset
��Ŀ: >water flower
����: Thu Dec 10 18:21:44 1998
it seems to be that you should "turn bottle", instead of
"turn bowl", ��ˮ��, ���ǵ�����


---
����: Fire
��Ŀ: about the chopwoods
����: Thu Dec 10 20:46:39 1998
the chopwoods is a very nice job finished by row
now we have three basic jobs
and tset and group are develop two more
I think that about 10 basic job is enough
then we can move to medium level jobs
addoil all


---
����: Group
��Ŀ: re 259
����: Thu Dec 10 21:51:12 1998
actually what i want to use is "water bowl".
when i ask flee, he said that better not increase more verbs, hence i use
turn instead of water. if turn bowl is not that good, i will think ti improve
it.


---
����: Tset
��Ŀ: any comments?
����: Sat Dec 12 18:43:25 1998
just saw this somewhere...wonder what you guys all think
about this issue...comments?


Time:    Wed Apr  1 02:00:52 1998                Post-id: 4 (15 Last)
Poster:  Blue
Subject: Important (driver-related and other)

Dear all,

I have received the following email on which I'd be interested in  
your comments.  Please read my notes at the bottom before following
up.


From s-craigb@microsoft.com  Tue Mar 31 16:32:04 1998
Message-ID: <C83BD0BB1BBED01198AF00805F196034312507@WSH-03-MSG>
From: "Craig Barham" <s-craigb@microsoft.com>  
To: "'Leigh Caldwell'" <BLUE@INTERNATION.CO.UK>
Subject: FWD: RE: TMI-2 product and LPC licence
Date: Tue Mar 31 16:31:25 -0800
X-Priority: 2
X-Mailer: Internet Mail Service (5.0.1458.30)

Mike Barber wrote:
> I think we should go ahead and begin negotiations.  I've discussed
> it with Legal and they say that the issues are real but
> surmountable.  We had a similar situation with <name of other
> product deleted> and it was settled with no major ramifications.
> My estimated budgets are quoted below.


Dear Mr. Caldwell

As you know from your discussions with Mike and Nassad over recent 
weeks, I am the Strategy Director for the Online Community Group at
Microsoft, and as such I am the person you'll be dealing with in  
the proposed acquisition or license of your TMI-2 product and
associated interpreter software.  My aim will be to find a way in
which both of our strategic objectives for the development of this
sector can be served.

Mike has given you an idea of some of the potential that we've been
seeing here, but to give you a coherent idea of how we see this
developing, here is my own take on each topic.


  COMMUNITY INTEGRATION - Hotmail/MSN
  -----------------------------------

As you know, our strategy for MSN is shifting from content
production to community-building.  The recent acquisition of
Hotmail was initiated for this reason, but we also intend to offer
several facilities and technologies unique to MSN and not readily
duplicated by others in the market.  One of these will be a
realtime interactive environment.  In order to reach market quickly
and create the potential that we believe exists, we need an
existing environment, easily configured and with a developer base.
TMI-2 fits.

We intend to host TMI-2 environments on all Hotmail and MSN
servers, with a Windows-based frontend client.  Of course, we need
to be reassured that the technology can handle traffic of between
20,000 and 50,000 simultaneous users at any time, but the
demonstrations you have shown to my colleagues have satisfied them  
that the only limit will be the NT backend's user capacity.  With
input from our own engineers, we feel confident that the product
can be optimized to ensure fast response at these levels.


  LANGUAGE TOOLS
  -------------- 

As a leader in the development tools market, Microsoft wishes to   
continue to expand its Visual products range with new languages.   
In addition, we will need development environments for the new    
community facilities on Hotmail/MSN, and as the major development
languages for the TMI-2 product, LPC and LPscript appear to be the
appropriate starting points.

In order to enable Community Operators on Hotmail and MSN to create
the kind of applications that we believe will build the realtime   
user base, we propose to create Visual LPC and Visual LPscript 
packages.  While development tools are not my area of expertise, my
conversations with executives from that division indicate that our
Visual C++ and/or Visual J++ products can easily be adapted to
LPC and that Visual Interdev will provide a suitable base for 
LPscript integration.


  TECHNOLOGY POSITION
  -------------------

The final reason behind our proposed acquisition is the need for
Microsoft to maintain its position at the forefront of software
technology.  Our position has always been to develop or acquire
the leading product in every market, and it is as a continuation of
our technology policy that we propose to integrate TMI-2, the
leader in easy-to-build, highly extensible realtime environments,
into our product range and service offering.  It is crucial that   
we remain informed of further technological developments in the   
MUD sector, in order that we can ensure TMI-2 benefits from the
advances gained by competitive, second-tier products.  We will  
aggressively market TMI-2 to ensure that its commercial position
remains unchallenged, but it will be your role as
technology
consultants to the project to ensure that any and all new ideas
that emerge in the sector are integrated into our product
sufficiently quickly to destroy any lead another product might
gain.  Where source code is available in the public domain or
where its licensing terms are unenforceable, we will incorporate
technology directly.  Otherwise, you will be expected to
duplicate functionality as necessary.


  LICENSING
  ---------

Of course one of the issues that needs to be resolved ASAP is that 
of the license.  Our understanding is that you and Mr. Wouters have
control of the license for TMI-2, but that the licenses for the
primary interpretation software for the TMI-2 language LPC are not 
held solely by you.  We will expect you to expedite the process of
gaining control of these licenses, and the budget available is
commensurate with the urgency of this task.  Our legal advisers'
analysis of the source code in question indicates that there are
four parties, primarily Mr. Hollebeek and Mr. Pensj|, and secondarily
Mr. Garnett and Mr. Richards, who have a legally defensible claim on
the source code for the "MudOS" implementation of the LPC API.  We
believe that the other contributors have no legal rights in the
source code as it currently stands, as the extent of their
contribution in the current code is negligible.  We are prepared to
defend this position in court if necessary.

However, as we have indicated to you, exclusivity is extremely 
important to us.  We therefore wish to examine the rights of others
to create and promote compatible technology.  In particular, I
understand that a Mr. Rennecke and a Mr. Croes have compatible
products.  With Mr. Pensj|'s rights purchased, we will attempt to
prevent these parties from distributing their product, but funds   
will be available for purchase of that intellectual property if   
necessary.

On a similar theme, we will also expect all MUD servers currently
using TMI-2 or LPC technology to cease operation by the end of

August 1998.  However, as a gesture of goodwill to the community,
we will be willing to rebrand a number (around 12) of these as
Microsoft Community Games and to allow them to continue to operate
on MSN servers.


  BUDGET
  ------
  
The figure that you quoted to Nassad as an estimate for the overall
licensing costs is simply beyond our means.  And as an acquisition
of this kind by Microsoft has a very significant PR and marketing  
value for a company such as yours, we would expect that to be taken
into account in determining a purchase price.  However, we are 
willing to make available US$5.5 million for the outright purchase 
of all rights in TMI-2 and the interpretation software mentioned  
above.  There will be a separate budget to finance the development
of individual community environments on MSN/Hotmail; this will be
in the region of US$120,000 per annum for each environment.

Please get back to me this week with a status report on the above
issues, and a signed NDA.


Regards,
        Craig Barham
        Strategy Director, Online Community
        Microsoft


-------------- Forwarded message ends --------------


Basically I want to know: what do you think of this?  I haven't   
signed the nondisclosure agreement yet, and so I am still free to
post this.  I have to admit I am not sure of their legal ground,
but there is plenty of money available and we are willing to
discuss a settlement with anyone with a genuine copyright claim.

I need to respond to them by Friday, so make any comments as soon
as possible.

Of course I'll be contacting Lars, Beek, Truilkan and Cygnus
directly, and Dworkin and Amylaar shortly afterwards.  Any other
interested parties would be advised to provide information as soon
as possible.

Regards,
        Leigh Caldwell
        Blue@TMI-2


--
------------------------------------------------------------------------
  information        |  Leigh Caldwell, managing director, Internation.
    innovation       |   Allied House, 45 Hatton Garden, London, U.K.
      integration    |          +44-171-242-3200 (fax 3033)
        Internation. |  blue@internation.co.uk   www.internation.co.uk
------------------------------------------------------------------------
(181-199 100%) [h]:
(driver.misc:4:#4) 11 unread [q?lLmghsSprRfFncUMDut#g] >


---
����: Tset
��Ŀ: posts from the other sanguo site(5)
����: Sun Nov 29 21:48:00 1998
[26] �ԣϣ�  �佫                             �����(darken)(Tue Nov 10)
----------------------------------------------------------------------
                              �ԣϣС����佫


����
κ������
       ��������Զ��ԭΪ��ԭ�����������Ѷ�׿�ᣬ��ԭ��ɱ����
�������������Ӫ���ܲ��������ᣬ����ɲ�������Ȱ�併֮
�������ó����䣬�Ҹ�ı�ԡ�ָ���������ǲܲ������õĽ���֮
һ���Ϸ�֮�ۣ��԰˰����������Ȩ�����ʮ��������������
���ڹ��𽵲�����֮��ɺ��ѡ��ҵĽ����ǼӸ����� dummy npc
��С�棬κ����������ɱ������������ܲ���ʾ�ᣬ���ӵ����
�ɡ������صĳ��ѹ����Ҳ� refresh (yeg �� idea)������� stat
���£�
���� 80���ǻ� 70������ 100�����ڷ��ء��سǡ�
lsp 80 �� 100

����
�ⷽ������Ϳ����������£����һ�����κ������
       ����ԭΪ�ܲ�����ָ�ӹ٣�����ܲٲ��������ߣ��ǲܲ���
��ǿ��ĵ�һ���ء����׽���˲ܾ��Ӵ���������⡣���ھ�Ӫ
���������ǲܲ�����Ҫ�ĺ��ڲ�����������вܲٵ����
��������һ����Ѱ�����ܵõ�������� stat��
���� 20���ǻ� 90������ 20������������ı��
lsp 50 ���ҡ�

�񡢿���
       �����Ͳ��ö�˵�˰ɣ�һ���ľ�Ӫ�����˲ţ�������ʱ����
����������é®(�����д���)�Ŀ������������������һ��������
����Ҫ�����ܸ��������������˰�������ľ������������ܿɼ�
һ�㡣�����ڵõ����������ᵽ����һ����Ѳ���ٵ���������
�õ�������� stat��
���� 30���ǻ� 100������60������������ı
lsp 60 - 80 ���ҡ�

�赲
��Ȼ������ȹ�������ǿ��������Ҳ���ܺ��ӡ�

κ������
       ����ʱ�ٶ�֮սʱ�ܾ�����ָ�ӹ٣������Լ��ٵı����ֵ�Ԭ
���е�һ�ǽ��߸ɣ��������ڰ������£�����ܲ��ڹٶ���ս����
ѹ�������������Ǹ�����䣬�����þ����ҵ�������� stats��
���� 70�� �ǻ� 70������ 90�������赲��
lsp 80 -- 100 ���ҡ�
�񡢹���
       �����ڽ���ʱһ�ȶ��Եֵ������������������ܾܲ��ڽ�
�����ʡ��ӵ¼������谡���Ȼ�ȣ������½�֮����һֱ�������Ƿ�
����֮�Ƶ���μ���ս����½ѷ�İ��ȳ²�֮�Ʒ����ܱ�ɱ������һ
��ʼ�������������Ҫ�ˡ������ stats
���� 90���ǻ� 70������ 80�������赲��
lsp 100 ���ҡ�

����
����һ������Ȼ�Ƕ�������ĵ����ɡ�½ѷ�����ֺ�Ϸ��

�⡢����
       ����������˫ȫ����������³�������ζ�������߶�������½
ѷ�����ʩչ���ȳ²�֮�ƣ�ʹ����ս��֮�ƵĹ������������һ
��ʼ��������ȨҪ�ˡ������ stats��
���� 80���ǻ� 80������ 50�����ڷ����������
lsp 100 ���ҡ�

�⡢½ѷ
       ������½ѷ�ܹ���֮�²���׸������������սʱ��ʹ�÷�����
���ݴ���֮�ƻ������������������ñ���ûʲô��������ѷһҹ��
�������롣����������֮���ڲ�ɣһ�������ҵ�������� stats��
���� 20���ǻ� 90������ 30�����ڷ����������
lsp 80 ���ҡ�
ͻ��

κ���ֽ�
       �ֽ�����Ǩ����Ķ�С������ȴ��󣬴�սʱ���ڵ�һ�߶�ս
����սʱרע�������ģ���֪��ƣ�͡��ǲܲٵĳ���ǰ�档�ں���
�Ը߸ɣ���ƽ�ض���������ڶ���褣��ٶɶ�Ԭ̷��ȫ��������
��һ���ȣ������ͻ���ϵ�ָ���������ڲܲٺ����ơ�����һ��
ʼ������ܲ�Ҫ�ˡ������ stats��
���� 80���ǻ� 30������ 50������ͻ����ͻΧ��
lsp 80 ���ҡ�

Ϊʲô�󲿷���κ�����죿�ⲻ����ƫ�ģ�һ��ܲٻ����ˣ�����
�ҶԲܾ����˽⣬������ˡ��н���򷴶ԣ��� post �������
�ο��ο��ɡ�



---
����: Tset
��Ŀ: posts from the other sanguo site(4)
����: Sun Nov 29 21:47:16 1998
[24]   ���а� -- ͳ˧ƪ (by �����(darken))   Ҷ��(yeg)(Mon Nov 09)
----------------------------------------------------------------------
                           ���а� -- ͳ˧ƪ

        ͳ˧�����Ϻ��������е�ͳԦ����࣬����ͳ˧������
��ı�����ǡ��侲���жϣ����������ǿ����飬�ܴ���ǿ ��)
Ҳ�� wiz ���Ǽ�����Щ������ս���ʤ�ܡ�

κ

�ܲ�  ���ö�˵���ܲ�������ʱ�������ľ��¼ң�������Ҳ�ʰ�
�·磬˵�������ܲ��ñ����ݸ����䡣���ܲ������ñ���Ҳ����
���ˣ���˲������˲��١��ڹٶ���ʮ��֮һ�ı����򵹵�ʱ
����ϯ����Ԭ�ܣ������������˺��ñ�������д��κ��ע����
(�ֳ�Ϊ�ϵ�����)������ʷ������ߵ���������ϧ�����ʹ��
���鼥Ц��һ��֮���յ��ˣ����ʧ����(*slogan zhangsong :))

����  ��Ӫ���ټ���ı���ν��졣�ܲ������Լ��ñ��߳������
�ܰѲ����������ָ�ӣ�ȴû�и����Ƕ���һ�����ϰ���ᣬ��
�Բ�Ӫ�Ľ��ٶ�벻������ָ�ӡ�����ȴ�����ڳ��ˣ�����˫ȫ��
�����ı�Զ����൱�����⣬���񺺵����ơ�

����  ǰ���post���ᵽ�����԰˰�����ƶ���ʮ����������
ͳ˧�ɼ�һ����

����  Ԭ����Ӫ�Ľ���������ɽ��Ϊ��ָ�ӣ������ĺ�Ԩ��ն��
�����ţ�����һ����ܲٱ��ţ�һ�����н��·���ʮ���侲��
��ʱ��ס�˺��С��Ϳ���

���  �����Ӫ�Ľ��������������ǲܲ�����Ϊ��������ջ�
�Ի������μ�Ϊ��Ϥ���ߴ��λ�ս��

�ڽ��ͳ���  ��Ӫ�������ǽ������ܲܲ����Σ�Ҳ��������һ�档
һ���ڽ���ʿ������ı����һ���в����ĵĲܲ�Ҳ��ʾ�������š�
��������Ҳ�����Ҳܲٷֱ棬��ս�еķ������ú�Ž����ܲ١�
��������ƪ��������˲���׸����

��

����  ����������ˡ������������˲��࣬��ȻҪд��ʲôʱ�� :)
��������ȫ���εĽ��죬����������������ͳ˧��Ȼ����

����  �������Ტ��Ϊ����ʱ���ġ�ս�񡱵�Ȼ�ǵ�ͳ���󽫵�
���ġ�����ؼ������������������ж����ĳ��Ҳ��ͳԦ���ߵ�
ԭ��

��ά  ��ʲô������ô����ô������˫ȫ�� ��)
��ά������ˮ����ӳ�����ݿ����������񡣿��������������
���ڸ���������������һ��ʮ��ǿ�Ľ�����

��

½ѷ  ½ѷ�������������ھ�ͨı�Զ�������ί��Ϊ���죬���κ��
���š���䡣½ѷ������������ɱ��ս��֮�ƵĹ��𣬲���С����

����  ���ɱ�����򣬵�����Ȩ��³��Ĺ�Ȱ�����ſ�����飬����
�ɾͷǷ��������������벻���ļ��⡣

���  �����ѵ�һ�����˲ţ����ñ����������ܲ١��������ۣ���
�����ʿ���˲ܲ����µİ���������ϧ���差����սʱ�����ʡ�
��ξ���ʸ���У�����������



---
����: Tset
��Ŀ: posts from the other sanguo site(3)
����: Sun Nov 29 21:46:44 1998
[22] ���а�  --  ıʿƪ                       �����(darken)(Sun Nov 08)
----------------------------------------------------------------------
                          ���а�  --  ıʿƪ
        �Թű����������ս������֮�����Ǳ�����߳ɾͣ����
˵����ıʿ����Ҫ��

κ

�ܲ�  ���˵�ż�񣬵�Ȼ��д�� :)  �ܲٱ���������Լ���õĲ�
ı��������Ҳ�ܶ��������˲š��ܲ�����ʱ��ᰮ���飬������
���;�������ʽ�������񣬱�����ǿ���ˡ����������ǲ���
��ҵ�������˵����������ˣ����ǳ˻���һ���������� :)

����  ʮ�ֳ�ɫ�Ĳ�ı��������������ȫ��λ��ıʿ����ս��
�������⽻���м��ѵı��֡��ǻ�ֱ������͵Ŀ�����˾��ܲ��
�ܲ��ڳ�ڴ��ʱ��̾���������ǹ���Т�ڴˣ��㲻����˴��
�ˡ����ɼ��ܲٶԹ��ε����ء�

����  �ҵ����뷨�Ҳ����Ǹ��֣����������һ����������κ��Ԫ
�ϼ�ı��������Ӫ�ľ�Ӣ���������õģ���������Ϸ־�š�����
�ȵȡ��������������ܲٳ���Զ���ǣ����������ش�Ӫ��

����  ��������ֶ�ӣ�����ս���������ܲ�������ս������������
Ļ���С�Ψһһ��������û��������ڳ�ڣ��ܲ�ȴ������˸���
���̡�

����  ���Ҳ������ˡ����ܾ�ıʿ�����ֶ��֡�����
���ĺ�ԭ����ȶıʿ����ȶ������Ͷ�����壬��һ��Ͷ���ܲ١�Ҳ
����ս���������������ĵ������֮սʱ���Խ�����������ؽ�
�꣬�ܲٱ�����ڲ����ĺ�֮�ԣ���֮�������Ρ�

��

�����  �ܲ١�˾��ܲ����Ҫ�Ķ��֡��ܲٹ�����������˷�ɢ����
���Ӿ��ݡ�(�ܲٲ�һ��͵õ��ˡ�������ܲ��п���������)������
����ة����ֵ������Σ��Ե�ʱ��κ��ʵ���Աȣ����ܺ�κ������
�й���ʵ���ǵ�ʱ֮�˲š�

��ͳ  ������ͳ������ͷ������ʿ����֪��ʷ�ϼ��ټ��������¼���
��˵����������±���ʸ���ж�����

����������  Ҳ��������ıʿ������ʷ����ī���٣�֮�������Ǿ���
����ʿ��Ҳ���ǳ�����κ���ģ�����д����������� :)

��

���  ���ı��������褣��ڳ��һ����������Ӵ�ܲܲ��ݺỪ��
�İ����������м�ǿ�ļ�������ʱ�˵��������������ɹˡ���

³��  ��Ȼ�����������б���д�ɵ������۸����Ϻ��ˣ���������ʷ
����ɹ����⽻�ҡ����ġ��辣�ݡ�ս����ʮ�ָ����ģ��ǳ��й���
�۹⡣��ʱ�ܾ���ǿ�����������¡�ı��Ҳ���ѣ���û���Լ��ĵ��̣�
���������κ����ϧ��������Ȩ�۹�϶�ǳ���޷�����ά����Լ��

���ѡ��ź�  �ͳƽ������ŵ���ʿ�����������������漫ǿ��������Ϊ
�ײܶ�����ô�����á�



---
����: Tset
��Ŀ: posts from the other sanguo site (2)
����: Sun Nov 29 21:46:08 1998
[17] ���а� -- ����ƪ                         �����(darken)(Thu Nov 05)
----------------------------------------------------------------------
                                  ���а� -- ����ƪ
      ���ڴ�Ҷ�ϲ�����˳�������һ��ʿ�����سǣ�������дд���ء�

����������Խ��Խǰ�棬���Թ��ҷֿ���

κ

����  ������Ӫ�Ľ������ڲܲ���������ʱ�غϷʣ��԰˰�������ƶ���
��Ȩ���ʵ�ʮ�������ܲ��º�۲���Σ��޵�������Զ��ǳ���Ҳ����

����  ����˵��κ������ķ��ؽ��죬��֪Ϊ��ĬĬ�������ٶ�֮սʱ��
�����Բ�����ǧ���䣬�ڰ���ɿڳɹ��ĵֵ�Ԭ���Ľܳ�����߸�����
������ã�����ܾ�������ѹ����

����  �ܶ��˶���Ϊ�����ǲ�ı����ʵ���ǽ����������ı�ٳ�����
�ܲ�ѡΪĻ�š������ڽ��ͳ�Ϊ��Ӫ�������ǽ����ܲٶ�������ʱ����
��������ӭ�������߶�ȫ����(��ʱ�ܲٵĴ�Ӫ)���ѣ�������ʣ�²���
ʮ��֮һ�ĳ��й�ͬ�����������ŵ��ܲٴ�����������Ͳ�С�� 

��

����  �������ɵ���������ܳ��Ľ���֮һ������ɽ֮ս������ն���ĺ�
Ԩ������׷�����ӵ�����Ӫ���У����Ʊ��٣����ҳ�ս���ʹ�Ӫ�ţ�
����վ���ſڣ��ܾ����мƣ����ˡ����Ƴû���ɱ����ܾ����ղ�����ʧ�� 

��

���  ���֮սʱ���ٰܲ��������£�����Ե���(����)������(���һ��
�ĵ��η磬�򳤽������γ�)�����ƣ��������˰Ѳٰܲ������س����Ա���
������Ĭ��

��̩  ��̩����Ȩ������ʱ��ͬ�磬��ʱ��߽�һ��С�ǽ���Ȩ��������
ɽ������Ȩ��̩�ޱ������ó��ˣ�ɽ��Լǧ��ˣ���̩�Բ�����ʮ���ɱ���
�ᣬ�������໤Ȩ�����������¾�����Ȩȫ����ˡ�



---
����: Tset
��Ŀ: posts from the other sanguo site
����: Sun Nov 29 21:44:11 1998
anding    ����    ����   
ba        ��      ��ܲ
chaisang  ��ɣ    ��ٷ
fa        ����    ���
fu        ��      ����
gongan    ����    ��ʿ��
henei     ����    ����
hengyang  ����    Ԭط
hongnong  ��ũ    ����
hu        ��      �ϰٻ�
huiji     ���    ����
ji        ��      ����
jiangzhou ����    ����
jianning  ����    ���
jinyang   ����    ���
luo       ��      ��
pingyuan  ƽԭ    ����
puyang    ���    ����
runan     ����    ����
shangyong ��ӹ    ����
tianshui  ��ˮ    ��ά
wudu      �䶼    �
xiapi     ����    �µ�

[31] �ֶ�����                                 �����(darken)(Fri Nov 13)
----------------------------------------------------------------------
                �ֶ�����
����̫�ء�Ԭ��
����̫�ء�����
����������̫�ء����
ԥ�ݴ�ʷ������
���ݴ�ʷ�����
����̫�ء�����
����̫�ء��ų�
����̫�ء����
ɽ��̫�ء�Ԭ��
�ñ��ࡢ����
�ɶ�̫�ء������
���佫�����ܲ�
�Ὣ��������̫�ء�Ԭ��
����Т��������

���¾��Ų�û����ʽ�μӣ�����Ҳ����׿һ��ѹ�� :)
�󽫾����ʸ���
������������
������������
����������ѫ
���ݴ�ʷ������
����̫�ء�����


[32] 18·���������                           ҹ��(nightboy)(Fri Nov 13)
----------------------------------------------------------------------
1. �󽫾�����̫��Ԭ��
2�����ݴ�ʷ���
3��ԥ�ݴ�ʷ���
4�����ݴ�ʷ���
5������̫������
6������̫������
7������̫�����
8��ɽ��̫��Ԭ��
9���ñ��౫��
10������̫�ؿ���
11������̫���ų���
12�����ݴ�ʷ��ǫ
13������̫������
14����ƽ̫�ع����
15���ϵ�̫�����
16���ڳ̺ɳ̫����ᡣ
17������̫��Ԭ��
18���ܲ�



---
����: Fire
��Ŀ: demote yue
����: Sun Nov 29 18:23:54 1998
yue has been demoted becouse hasn't worked here for
a long time and abuse wiz power.
she is the first wiz demoted by the decision of
wiz committee ( the vote results is 4:1)
she will continue work in the old site and when



---
����: Fire
��Ŀ: leave of ccc
����: Sun Nov 29 16:56:54 1998
ccc will take a month of leave


---
����: Yue
��Ŀ: what happened?
����: Sun Nov 29 09:50:31 1998
when i login today i was in:
���� ���ڣ�west
    ����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ı�����ȥ��
�����Ҽ�Ӳ���ƺ����Ǹ������ɣ�ֻ���ϱ��8���һ��С�ţ�����
���˸����ƴ�Ķ��������ͷ��õġ�
what happened? what did i do? sigh


---
����: Fire
��Ŀ: about the path
����: Thu Nov 26 14:17:59 1998
����·����
���MUD��һ�����崴���MUD������ÿһ����ʦ����һ��
����·������·����Ҫ���ڲ��ԣ���ѧϰ����һ����������
��Ӧ�ð����Ƶ�/sgdomains/�µ����·��������ϵͳ·���¡�
��������������Ĺ����Э������������෿�䣬NPC����
/wiz/fire/·���£�����Ҫ������ʷԭ��ͬʱ�����ֽ׶�����
̫�࣬�ڲ�����������(��������Ҫ����ת�Ƶ����ʵĵط�)��
��������Щ���Ĵ��룬�����Ǵ�����˵�С��ߣ�������Ӧ
�����ŵ�/sgdomains/֮�¡�����������һ���ļ�/include/path.h
������������·���ĺ꣬Ϊ�˹淶���뾡��ʵ����Щ�ꡣ
Best regards��
fire


---
����: Fire
��Ŀ: new suggestion about mache and mafu
����: Wed Nov 25 16:52:47 1998
Now i have added two function 
get_distance(string beg,string end)
and get_all_distance(string beg)
in area_d.c
for get_distance(beg,end) the beg and end are two areas
if one is not exist return -1 if from beg can not
reach end ( this should be impossible) return -2
else return the distance between them
if beg== end return 0
the get_all_distance will return a mapping
which show the distance to all area which can be reached
to test them just use
@AREA_D->get_distance("changan","luoyang")
@AREA_D->get_all_distance("changan")
it is very simple to use so I strongly suggest
to use them to improve the mache system
therefore the price and busy time for one
ppl go from one area to another area should
depends on the distance
Addoil flee and group


---
����: Fire
��Ŀ: about mache and mafu
����: Wed Nov 25 15:33:17 1998
the mache and mafu which flee has designed are very
nice, Here is some of my suggestion
1 create a modle file for mafu and mache and put them 
 under /sgdomain/modules
2 create some mafu npc under the path of /sgdomain/npc/mafu
 which inherited m_mafu
3 create some mache obj under the path of /sgdomain/obj/mache
  this maybe not unnessary, but can make some variety
4 in eace area, select a suitable room (if don't have then create one)
and put a mafu in
5 create some random display in the process of mache's moving
6 after that I will disable fly for player. . . 

NOTE: 1,2,3,5 just suggestion :) may be your guys have better
ideas. But 4 is necessary and i hope we can do 6 ASAP :)
addoil flee and group

one more thing if we don't want look the beauty desc for some
npc such as: ���(mafu)����ݰף����ͦ�Σ���һ��Ӣ�����꣡
just add one sentence in the obj file: set_sg_rongmao(-1);


---
����: Flee
��Ŀ: �� finished
����: Wed Nov 25 04:28:15 1998
�� for transport finished.
�� --> /wiz/flee/misc/mache.c and 
mafu --> /wiz/flee/misc/mafu.c.
if two area r directly connected, the time cost
is 10 seconds and money cost is 10 silver.
otherwise, time cost is 20 seconds and money
cost is 20 silver.


---
����: Fire
��Ŀ: current tasks
����: Tue Nov 24 22:27:33 1998
1. finish low level jobs and mid level jobs (flee and row)
2. Add merchant sell horse and bow and food and stuff (fire)
3. Add ��վ system so change fly to wiz and advanced player (group)
4. add cmd so the general can control npc troop's action (fire)
5. manual arrange troops (fire)
6. new desc for warroom (tset)
7. new suggestion on localmeeting such as buy horse, buy buy bow (fire)
8. buy stuff become a job (fire)
9. train troops as a job 
10. national meeting
11. auto movement for offline chars


---
����: Fire
��Ŀ: mergeable object
����: Tue Nov 24 22:16:18 1998
mergeable objects can auto merge together when
in one place such as array and firewoods
to use it just inherit M_MERAGEABLE 
and please refer /sgdomain/job/chopwoods/firewoods.c
the module is in /sgdomain/modules/m_merageable.c


---
����: Fire
��Ŀ: >re last application
����: Tue Nov 24 15:09:45 1998
On Tue Nov 24 01:26:50 1998 Lei wrote post #255:
> All applications sound very nice... However, we know there are 
> only a few good wizards...
> 
> maybe we should promote them as temp wizard... 1 month later evaluate their
> work and give final
> decision, ok?
> 
That is a good suggestion
I will add this in the wizard rules
thanks lei
xixi


---
����: Fire
��Ŀ: welcome new wizards
����: Tue Nov 24 16:16:39 1998
now ccc and laoda are new wizards
according to the wizard rules they will
have two weeks learn time
and after one month, the wizard committee
will exam their thier work to see if they
are qualified as wizards here


---
����: Fire
��Ŀ: JOB JOB
����: Fri Nov 13 15:14:22 1998
Job System Design
Job system includes four parts:
1. a module file
   Because one ppl's job record can include a lot of information
so it is unpractical to keep all this information in the char_d,
which will keep on memory all the time. so we need a m_job.c as
a module file which define the ppl's job record and all the related
functions. The record include the number of one kind job this ppl
has finished, the last time of this kind of job has been finished
and the situation of current doing jobs.
2. a main job daemon
   We will have many different types of jobs so the situation can
be very complex therefor we need a daemon to handle all the most 
common information and behaviors for the jobs. These information
will include these following information.
Job ID: each kind of job has one identical english name
Job Name: a chinese name for this job
Requirement: some job need a certain requirement, some can be set as
          numbers some may need a function to define the requirement
Reward: The reward is the most important part for the job system
        In fact a player does all this mainly for the reward. In order
        to keep the reward fair and blance. we can check this file to
        manage the whole picture of the rewards.
3. seperate job process contral files
   The jobs can cover a lot different actions. For one job it usually
includes following steps:
   The first step is ask for the job.
   The second and the main step is do the job, this may include several
   sub steps
   The last step is finish job and go ask reward or resign the job (
some time got penishment)
The real process for different jobs could be quite different. So we need
a lot of creative and imaginable work here.
4. robot checking
In order to make the job more attractive and reward the real player, we 
need a robot checking program. each time when a player finish a job, the
system will give him one question. if he can get the right answer then get
the reward if not fail.
Task arrangement
For the job system, I suggest the following task arrangement:
I will do the module file coding. Flee will be responable to the daemon file
Row finish the first several small jobs (such as chop firewood and shoulder 
water). and we will exchange the ideas frequently and make the whole system
run. after the frame is finished then we can develop more job and insert in
this system (like plug in ?)
File allocation:
model file: /sgdomain/modules/m_job.c
daemons file: /daemons/job_d.c
process file: /sgdomain/job/<jobname>/*.*
Previous work:
Flee has done two jobs already the extinguish fire and spy. when the
frame work
is finish those two jobs need got a little modify and fit in the whole system
Schedule:
before the end of November,1999 finish the frame work


---
����: Fire
��Ŀ: new feature for char
����: Thu Nov 12 22:35:18 1998
new feature localcontribution has been added
in char_d.c
use function get_char(p_id,"localcontribution") 
and set_char(p_id,"localcontribution",p_val) to operate it
and if for other area use :
setchar_localcontribution(string p_id,int para_value,string p_area)
and getchar_localcontribution(string p_id,string p_area)


---
����: Fire
��Ŀ: depromote wizard
����: Tue Nov 10 18:25:00 1998
ziguang   �Ϲ�      ��ʦ  ���ߣ���ʮ����         166.111.5.7
according to the wiz rule,
ziguang will be depromote from wizard


---
����: Fire
��Ŀ: about the job
����: Tue Nov 10 18:22:48 1998
��������Ҹ��˲�����
��Ҹ��˲��������¼��֣�
���   ����          ����           ��ע
1      ��            ��
2      ����          100000000
3      ��������      10000000
4      ���ҹ���      10000000
5      �������ܵȼ�   100           ������츳����(����)
6      �󷨵ȼ�      100           (��������)
7      ��ı�ȼ�      100           (��������)
8      ���⼼��      100           (��������)
9      �ҳ�          100           (�Ա������ҳϣ��������ǹ�ϵ)
10     ��ְ          9             ����
��ҽ׶Σ���ҵ��������̿ɷ�Ϊ���½׶Σ�
1 ��������Ϊ��ɫ��δ�ܵ���֮ǰ
2 �м����ط���Ա
3 �߼����ط������͢(����)��Ա
4 ��������Ϊ����
����ڲ�ͬ�Ľ׶���Ŀ�꣬��������Զ�������ͬ��
1 ������
Ŀ�꣺���յ��ء�
����������񡢷�����ˮ��(������������Ǯ����ѧϰ)
���š��ͻ������š���̽�ȵȣ��м�����1������ҳ϶ȣ��������������ף�
���ٵĻ���������
1 �������ܵȼ�ȫ������30
2 �������״���10
3 ��������10
4 �ҳ�(��ĳ���Ĺ�ϵ)����50
������ʽ��
�������   �ر�        ��Լʱ�� ��̼��ʱ�� ����ظ����� ����
��������   10silver   1-5min   1 min      5(ÿ��)     ����ǰ
�м�����1���������� 1  1-5min   1 min      5(ÿ��)     ����ǰ
          ���� 1   
          �ҳ� 2
���ͣ�
1 ����ظ�������ָ����ĳһ���������ĳһ�ࡣ
2 ȡ��ˮ���ĸ�Ǯ���ܣ�ÿһ��Ǯ�������Լ�����
3 ����playerȡ�������ҳ��Զ����ӹ��ܣ��෴Ҫ�������Զ����������ʱ�䲻
 ���������ͻή���ܵʹӶ�������ְ���������λ��
5 ���ֽ���ѧϰ�������ܵ�ѧ��Լ 150 silver ���Դ�Լ��Ҫ��15�γ�������
  ��������ѧ��
6 ���ִ�Լ���10���м�����1�ﵽ���ٵ����Ҫ��


---
����: Row
��Ŀ: fomular for job
����: Tue Nov 10 00:26:51 1998
  Basic fomular for job system in SanGuo

  Job category 1: provided at the starting status

  Requirements: none

  Rewards: 1000 * ( N - n ) + 100 * random(10)

  Purnishments: none

  1000: basic currency unit
  N: total lenth of time limit
  n: time used by player to finished the job

  Note: if N = n, ( N - n ) part will not be counted.

  eg: If a player finishs his job in 4 mins (he was asked
  to finish it within 6 mins, or we can count it  as  mu
  day in order to be more realistic), his rewards will be:
  (random(10) assumed to be 4)
           1000 * ( 6 - 4 ) + 100 * random(10)
         = 2000 + 400
         = 2400
         = 24 silver

  Job category 2: provided when a player becomes a char.

  Requirements: player as a char.

  Rewards:
  1. Money: 2500 * ( N - n ) + 100 * random(10)
  2. Loyalty: 2 * ( N - n ) + 1 * random(3)
  3. Reputation: 2 * ( N - n ) + 1 * random(2)
  4. Local distribution: 2 * ( N - n ) + 1 * random(3)
  5. Skill point: 5 * ( N - n ) + 1 * random(2)

  Purnishments:
  1. Loyalty: 2 * random(5)
  2. Reputation: 2 * random(3)
  3. Money (optional): 1500 * random(4) + 50 * random(5)

  Job category 3: provided when a player becomes a med-
  ranked officer.

  Requirements: player as a med-ranked officer, loyalty
  80+, reputation 200+, local distribution 300+, skills
  lvl 20+.

  Rewards:
  1. Money: 10000 * ( N - n ) + 500 * random(10) + salary
            * random(2)
  2. Loyalty: 2 * ( N - n ) + 1 * random(3)
  3. Reputation: 4 * ( N - n ) + 2 * random(3)
  4. Local distribution: 4 * ( N - n ) + 2 * random(4)
  5. Skill point: 10 * ( N - n ) + 2 * random(4)

  Purnishments:
  1. Loyalty: 2 * random(8)
  2. Reputation: 4 * random(5)
  3. Money (optional): 5000 * random(8) + 250 * random(5)

  Job category 4: provided when a player becomes a high-
  ranked officer.

  Requirements: player as a high-ranked officer, loyalty
  100, reputation 2000+, local distribution 3000+, skills
  lvl 60+.

  Rewards:
  1. Money: 50000 * ( N - n) + 3000 * random(10) + salary
            * random(3)
  2. Loyalty: 3 * ( N - n ) + 1 * random(4)
  3. Reputation: 10 * ( N - n) + 5 * random(5)
  4. Local distribution: 10 * ( N - n) + 5 * random(8)
  5. Skill point: 20 * ( N -n ) + 5 * random(8)
  6. Misc (optional): certain special objects.

  Purnishments:
  1. Loyalty: 5 * random(10) + 1 * random(5)
  2. Reputation: 10 * random(10) + 1 * random(10)
  3. Money (optional): 25000 * random(10) +1500 * random(10)
                       + salary * random(2)
  4. Misc (optional): certain special objects.

  Job category 5: provided when a player becomes mayor or
  jeneral of a city.

  Requirements: player as mayor or jeneral-ranked, loyalty
  100, reputation 10000+, local distribution 15000+, skills
  lvl 90+.

  Rewards:
  1. Money: 100000 * ( N - n ) + 5000 * random(10) +
            salary * random(4)
  2. Loyalty: 5 * ( N - n ) + 2 * random(4)
  3. Reputation: 20 * ( N - n ) + 10 * random(5)
  4. Local distribution: 20 * ( N - n ) + 10 * random(10)
  5. Nation distribution: 10 * ( N - n ) + 5 * random(5)
  6. Skill point: 40 * ( N - n ) + 10 * random(10)
  7. Misc (optional): certain special objects, certain
                      city.

  Purnishments:
  1. Loyalty: 5 * random(10) + 1 * random(10)
  2. Reputation: 20 * random(10) + 3 * random(10)
  3. Money (optional): 50000 * random(10) + 2500 * random(10)
                       + salary * random(3)
  4. Misc (optional): certain special objects, certain city.

  Job category 6: provided when a player becomes a king.

  Requirements: player as a king, reputation 50000+, local
  distribution 100000+, nation distribution 10000+, skills
  lvl 120+.

  Rewards:
  1. Money: 500000 * ( N - n ) + 20000 * random(10) +
            salary * random(5)
  2. Reputation: 50 * ( N - n ) + 10 * random(10)
  3. Local distribution: 40 * ( N - n ) + 20 * random(10)
  4. Nation distribution: 20 * ( N - n ) + 10 * random(10)
  5. Skill point: 100 * ( N - n ) + 15 * random(10)
  6. Misc (optional): certain special objects, certain
                      title from the emperor.

  Purnishments:
  1. Reputation: 50 * random(10) + 7 * random(10)
  2. Money (optional): 250000 * random(10) + 10000 *
                       random(10) + salary * random(4)
  3. Misc (optional): certain special objects, certain title.

  Note: For there are many ranks in SanGuo, so in each category,
  we could plus 1 to ( N - n ) for a higher rank.  Same manner in
  purnishments.

  As I do not understand other fomular in SanGuo very well and
  my mathsmatics is also not good :P, this fomular may be too
  simple or unreasonable, so I only provide my idea, hope some-
  one else could optimize it. :)


---
����: Fire
��Ŀ: supplement for the job system
����: Fri Nov 13 19:07:54 1998
Supplement of the Job
Two more tasks.
for the Daemon we need a menu to operate with the daemon database(
such as insert, delete, modify and check)(Flee's work)
For the module we need a cmd used for player to check the current
job situation and history record. (Fire's work)


---
����: Ultra
��Ŀ: stefan �Ƿ�������ɶ�npc��������,
����: Tue Nov 17 15:06:45 1998
chat* kick xxx֮���
�Ƚ�����˼


---
����: Fire
��Ŀ: depromote wizard
����: Sat Nov 21 01:46:08 1998
bamboo    ���      ��ʦ  ���ߣ���ʮ��           202.98.119.215
according to wizrule
bamboo is depromoted to player


---
����: Ultra
��Ŀ: ��������ϵͳ.
����: Sat Nov 21 07:44:33 1998
�������Ҹ��˹�������ϵͳ��һЩ�뷨,ϣ�����������еķ�����ͬ����.

һ.ǿ���Ը�����:

����������Ժ�.��ν���ٲ�Ϊ��������Ȼ�ؼ�������.
���쵼�߻���һ��ʱ���ڷָ���һ��������,ͬʱҲ����
ͨ��һ������Ϸ���̲���һ��������.
��:
  ͶƱͨ����"���ַ���"�Ľ����,����������������ҾͿ��Ա�
���䵽"���ַ���",�������,ֻҪ��ɾ��н���,������������Ŀ
����Ҳ���,���߲������������,����������ҾͿ�����������������
�����Һܾ�û�н�������,�����Ļ��ͻᱻ���ȼ�.��֮���н���.

����������ķ�ʽһ���Ǹ�����ҵĵȼ�����ҵĹ���������.���Ĺ�
Խ����ɵ������Ҳ�߼�.����������ٻ����԰�������ɸ��Լ�������
�������ͻ����Լ���,��Ȼ�������ʧ�ܵĻ�,���ܾͻᱻ�ͷ�.

���ַ�ʽҲ������������,ask �쵼 about work.��ȻҲ���ܳ���Ŀǰû��
������ִ�������.����Ҫ����ҿ���������ͨ��ĳЩ�����������Լ���
��������.
��������ʽ:
   
   ��������:	����Ҫ��ɵĹ���
   Ҫ������:    ��ֻ��ĳЩ�˲ſ�����ɵ��޶�����
   ʱ��    :	��Ҫ�ڶ೤ʱ�������
   �������:	������һ������ָ��,���ж��Ƿ����.
		������
                "����" : "��ֵ"
                �����Ľṹ,
                ֻҪ����"����"="��ֵ"�ͱ�ʾ����.

  
   �����������������ص�ʹ��"quest/work/����",����ֻҪ����ж���
Щ�����Ϳ���.


1.�쵼�Զ�������
     (1).���ܹ���
         <1>.�Լ����.
         <2>.���Լ��������.����ǽ�����ת��,����ɹ�����,��Ҫ����ɵ�
            ����������趨����ұ���,Ҳ���ǿ�������,���������ɺ�
            ��������,���߱���������,���������͸��Ƶ����Լ�����. 
            һ����ɺ�,��ȥ������,�����Ϳ��Ը��㽱��.

     (2).�ܾ�����
         <1>.���˽���
	 <2>.Ҫ����ָù���

     �쵼Ҳ����ǿ��Ҫ����,����ֻ�н��� 


2.ͨ������,�쵼�������,�����Ĺ��������������˶����Խ���,�����ǹ̶�ĳЩ��
   ��������.
      (1).�������Ҫ����.
      (2).��ָ�ɹ���.  
��.��ͳ����
һ�����Ǵ�rpg.��Ž��������������й켣��.

1.��ĳ���ĳ��,����ĳ�������Ϣ
2.��ĳ����ĳ��,������õ���Ϣ���߶���
3.�Լ����ĳ��,���Եõ�����
4.��ĳ��������ĳ��,��ͬ�õ�ĳ�����Ϣ

��ŵö�Ӧ��������:

    ��ĳ���ĳ��:
                ask sb about st(what are you want)
                ���ַ�ʽ��fy��quest������ͬ	

                "�����"   :  ĳ����Ҫ�Ķ���
                "ʱ��"     :  ��������ʱ��

                fy�л����϶��ǹ̶�һ���������������Ķ���.������������ֻҪ
		�̳�QUESTS��npc������.

    ��Ϣ�Ļ��:
                ��Ϣ��Mud�зǳ���Ҫ,�������һЩ�¼�,������Ҳ�һ��֪��,
                ������mud����һ��ר���ṩ��Ϣ����.
                ���¼�������,�Ͱ���Ϣ������Ϣ����.
                 
                 ����:
                      Npc allknow(��֪��)
                    
                      һ��npc(lu bu)�õ��˱���(bao wu),����ϵͳ��lu bu �õ�
�����������������������������Ϣ������Ϣ���С�ͬʱ��������ĳ��char��
id�浽��Ϣ��


                      һ����ң�
                      ask allknow about bao wu
����������������������(ϵͳ��ʼѰ�����ߵ�char,����Ѱ�ҿ�lu bu�����c
har,���߸���
������������������������Ϣ���е�char) �õ�һ��id,
                      allknow �����㡡char ����֪�������Ϣ��
                      ����ҵ�char��
                      ask char about baowu ,����char �͸������ݿ��
���ݸ�����ң�
                      ��ȻҲ���ܽ������Ϣת����һ��char.������Ҿ�
��Ҫ��Ѱ����һ��
����������������������char .֪����ɣ�

                      "����"     :   ���ask xxx aobut ����
                      "��"     :   ���ظ���ҵô�

      ��������:
                 Ҫ����һ���ݹ�Ľṹ������������ÿһ���Ϳ��ܴ�Ŀ
ǰ��char�õ���һ��
		 ����.ֻҪ������apply ����һ��char,�����Ϳ��Խ����������


      ��ĳ����ĳ��:
                 
                 ask npc about can i help you 
                 npc�����㣬�Ͻ�Ƿ����ʮ������������û����ɣ����ǽ��
                 npc give u jieju 
                 go laojiang 
                 ask laojiang about ��Ǯ   
                 give jieju to laojiang
                 laojiang give u 50 silver
                 goto npc
                 give 50 silver to npc
                 npc tell u goto xiaman u can find ultra
                 ��ϲ�㣬������ɣ�

                 ������һ�����ӣ���Ҫ�ǿ��������ƣ�Ҫ��Ƴ�ʲô��ʽ���ѣ�
   

      �Լ����ĳ�£�
                
                 ��ԭ�е��뷨
                 ������񡢷�����ˮ��(������������Ǯ����ѧϰ)
                 ���š��ͻ������š���̽�ȵ� ֮��ġ�

 
       �����ɣ�     

                 ��Ҫ�������������ϵ���ң���һ��ʱ����ͬʱ��ɣ�������������
�� �������������������ƣ�һ����ҿ��ܲ���ͬʱ���������ص����������û����
��   ������������������������,�����͸�����˼��Ҳ�͸������ںϣ��ɾ͸Ҹ�ǿ��

                
��Ϣ����Ҫ�ԣ�

       mud����һ�����ĵ���Ϣ���ŵ��Ǹ��ֵ���Ϣ.
       ÿ����ҵõ�һ����Ϣ�����Էŵ��Լ�����Ϣ���У�
������ �����û�����ҾͿ���������Ϣ��
 
                "��ʾ"      :    "��������"

       ask ultra about "��ʾ"
          <1>.Ultra���ƶ�"��ʾ"Ҳû��ʲô��ʶ
          <2>.������Ϣ����Ҫ��100 gold

       price "��ʾ" 1000 (1000ΪǮ����λΪcoin,��������ת��)
          Ϊ��Ϣ����

       buy "��ʾ" from ultra
       sell "��ʾ" to mm

       buyҪsellerͬ�⣬Ҳ����sellerҪ����sell����Ч������buy��ʱ�򶨼�Ϊ����



---
����: Fire
��Ŀ: a wiz application
����: Sun Nov 22 19:11:40 1998
fire
    ����һ��רҵ����Ա����Ҫ��������д����Ŀ��������ʹ�õĿ�������
��VC5.0.���Լ�������һ̨���ԣ�Ŀǰ��װ�Ĳ���ϵͳ��linux,����ֻ��������
�����С�����mud��Ҫ����������es2,���������Ѿ���ȥ�ˣ��������id ��xyk.
Ŀǰ�����Ҹ��𼸸���Ŀ��ʵʩ�����Թ����Ƚ�æ��ÿ���ſ�����1��1.5��Сʱ
�Ŀ���ʱ�䣬����������Ҳ���ԡ�
    ��Ҫ����������,лл��
��ǰ�Ѿ�������ͬ�����ݣ�����һֱδ�յ������������ط�һ�Ρ����⣬����
���ʱ��������һֱΪ0������û�п������ӵİ취�����ᣬ��������������
�Ժ�ƽ�����Ŀǰû�а취����������ָ�̡����س��Ų��У�
                                HU JIONG

what are your guy's ideas ?
please


---
����: Fire
��Ŀ: JOBϵͳ��ƹ淶
����: Sun Nov 22 20:39:58 1998
Ŀǰ����ȵ�����֮һ����JOBϵͳ��FLEE�Ѿ����������
JOB����Ҳд��һ��������ROWҲ��������һ��JOB��JOB��
��Ϊ��MUD��Ϊ��Ҫ��ϵͳ֮һ��Ϊ��֤JOBϵͳ�Ĺ�֤��
������ƽ�⣬��������¹淶��������µ�JOBʱ��ϣ������
�淶����������ɵ�JOB������Ϻ��淶���ڸĶ������ǰ��
�£����޸�ʹ֮���ع淶��
�淶�ļ��� /help/wizard/sanguo/jobrules
����help jobrules����


---
����: Fire
��Ŀ: about the wizard committee
����: Sun Nov 22 21:30:22 1998
the plan of the wizard is announced more than one week
seem nobody respond and commont on it. is this silence
means support or against ?
I hope all wizards can be active to the development
and the management of this MUD  too.
wake up, all. If your guys continues keeping on
silience I will assume you all support what I have
planed. :)
so please don't regret later :)


---
����: Fire
��Ŀ: a new wizard application
����: Mon Nov 23 18:22:16 1998
�����Ϊ��ʦ
������LaoDa(��mud�У�
�Ա���
���䣺29
ѧ������ѧ����
���Ӣ���ѧ�￼���ļ�����������Щ��Ĺ����������ձ��˴򽻵���Ӣ��
��������Ȼ�˲����٣����ⶮ������ܶ�����ûʲô�ã�
������Դ�ѧ��ҵ������һֱ���±�̹�������ͨUNIX����ͨC��C++����ȻҲ����
      ���ٱ�ģ���VB��FORTRAN֮�ࡣ
Ŀ�ģ���̫�˽�MUD��̨�α�����ģ������ú�ѧϰһ�£����Բ���������롣
������ÿ������ڹ�MUD��ʱ�����������3Сʱ�����˽ڼ��ա�
��������Ȼ��ͨ�ˡ�����ͨ��ʷ����ʵ��������
EMAIL��yulei@eastmail.com


---
����: Lei
��Ŀ: re last application
����: Tue Nov 24 01:26:50 1998
All applications sound very nice... However, we know there are 
only a few good wizards...

maybe we should promote them as temp wizard... 1 month later evaluate their
work and give final
decision, ok?



---
����: Fire
��Ŀ: about the job
����: Mon Nov  2 19:50:44 1998
������������Ʒ���
��������һ��ȫ�µ�MUD�����˲��ò�ͬ��MUD LIB�⣬����Ҫ���ص�����Ϸ����
�Ĵ��¡�
��ͬ���������������������MUD����MUD�Ĳ��ص��ǡ���̬���͡���������
������MUD���ص����ڸ��˵��������������μǣ�����һ����ң���Ҫ������
���˵ĵ��У��书�ȼ��������������ȵȡ������֮�䴦����Զ�����״̬��
һ����ֻҪ�㹻���������߿����Ϳ��Գ�Ϊһ����������Ҽ�����꣬Ħ��
�������ڸ��˵�ϲ�ã�����Ϸ�Ľ�ɫû��̫���ϵ�����ڴ�MUD�����ڱ���
���˲�����ͬʱ���ص�ǿ�������͹��ҵĲ�������Ϊһ����ң�������ҪŬ��
��߸��˵ĸ���ȼ�������Ҫ������ߵ�������ҵ�ʵ������������ͬһ����
����Ҿͻ��г��ö����ܵĹ�ϵ��ͬʱΪ��ά��һ��ǿ��Ĺ��ң�����һ����
����ǲ��еġ���Ҽ���Ž��뼯���ǻ��ǳɹ��Ĺؼ���
��ˣ��ڱ�MUD�еĸ��ֽ�������Щ����BUG��д�����ROBOT�����ܹ�Э��
�Ž᱾����ң�ͬʱ���������ڸ��жԹ�֮��ľ���ս�����⽻���ܵ���ʵ��
�ҡ�
Ϊ��ʵ����������Ϸ���룬����Ϊ������ϵͳ��Ҫ�����ڵͼ����м��׶Σ�
����ҵ��˸߼��׶Σ�Ҫô�ǹ�����Ҫô���س�����ʱ��Щ���˲��������彫
����Լ�����������Ҫ�Ĺ����ǹ����¼���Ա���������أ�����ͳһ��
����ROW��Ƶ�����ϵͳ���һ�����ͬ��ϣ��ROW�ܹ�����һ�������������
Ч��Χ�Լ���������Ը���ͬ����������Χ�ȽϾ���������빫ʽ��


---
����: Tset
��Ŀ: >wizlist
����: Mon Nov  2 18:29:51 1998
On Wed Oct 28 05:17:48 1998 Lei wrote post #233:
> Could any1 write a wizlist?
> Since we promote and depromote wiz often... We can't tell who is wiz by
> typing ls /wiz leh...
> 
i added the wizlist to /cmds/player, this is a temporary
solution only, and this command takes some time to run,
this is the scale down version of listuser, which scans
all user data (note listuser is wiz only command now).


---
����: Row
��Ŀ: ideas -- about job system
����: Mon Nov  2 18:10:51 1998
������MUD �У�����ϵͳ��Ҳ�ɳ�Ϊ����ϵͳ��������Ҫ����Ϊ����������ͬ
����������Ϸ�������󲿷־����������������ϣ���������Ϊ����ṩ�Ĺ���
ϵͳ����ǳ����ܡ��걸�Լ��ḻ��������Ҫ������ҵķ�չ���̲��ϵĵ���
��������������ҵĽŲ�������Ϊ�����еĹ���ϵͳ������ٽ�ϵͳ��ս��
ϵͳ��ѧϰϵͳ�Ƚ��ܵ���ϵ��һ���������ҶԹ���ϵͳ�ṹ��һ�����룬
����Ҳο������ۡ�

����Ҹս������������ʱ�򣬿���˵�����޷��ġ�ĬĬ���ţ����Կ������
Щ��������ʹ��Ҷ������Ϸ��Щ��������Ϥ�������лὫ��������Ϊ��ҵ�
��ʼ�ص㣬�������κγǳأ�Ҳ����˵��һ�������ĵص㡣ֻ�е�����ڻ���
���ڴﵽһ���ȼ��������뿪�����������ȥ�����������������Բο�����ʱ
������ʷ������Ҵ���ͽ׼��ĵ�ũ����������������������񡢷ŷ���
ʲô�ģ�����׬һЩǮ���Ա㵽ѧ����ѧϰһЩ�����ļ�������������ı���
��ս���ȣ������ǵ�ѵ������Ӧ���и����Ϻ���ʷ�ĳƺ�����ȥѧϰ��������
�գ�ǹ���������ȡ�Ҳ����˵��������ڳ���Ϊ�Լ����ķ�չ������һ��
Ŀ�ꡪ�����Ļ���ϰ�䣨���ǿ��Խ��������ּ�����Ƶû�����ƣ�Ҳ���ǵ�
��ҵ�һ��ѧ���ļ���������ģ���ѧ����ļ���ʱ���൱�����ѣ���Ҫ��ʮ
����������ʮ���ľ�����Ҳ��ʹ�������һֱ���Ŵ��ĵķ���չ����Ȼ����
�����Ĵ��䣬����ʱ����ʧ����������Լ�Ȩ���ˡ����������Ҫ�ǲ�������
������汸����ȫ�ų������������ҲΪ���ķֹ����»�������Ȼ�������
��֮���������ȫ�űض��ǻ����൱�Ĺ�����ˣ����ȵ���Ҵﵽ����Ҫ���
�ȼ��������ͨ�����ڴ��ڵ���վ��·���൱����Ŷ���Ǻǣ�ȥ������ϣ��ȥ
���ݿ���һ����չ��

����������

�������ࣺ������񡢷�����ˮ�ȣ�ϸ������
������������
�����ر���Ǯ

����ҵ������ǵĸ��ݵأ���ɵ����ص�������ı��һ��ְλ���ģ���������
�ͣ��䣬�����������ֻ����ֵȡ���ʱ������д�����߻������ܵĽ׶Σ�
��������׶�������ȡ�Ĺ���Ҳ��һЩ�Ƚϼ򵥵����ࣨ�����������������
�ӡ����ס�һ�����ɷ�Ϊ�������׼����ҹ��ף�Ϊ��������������������
�������ף�����ɹ��ҷ��������ͻ����ӹ��ҹ��ס������ס�Ҳ����Ϊ���
��λ���������б�׼����

�м�����һ��

�������ࣺ���š��ͻ������š���̽�ȵȣ�ϣ�����и�������ࣩ
����������������Ӿ�
�����ر���Ǯ���ҳ϶ȡ���������������

����Ҿ���һ��ʱ�������Լ��ļ��ܼ��������ԣ�����������ˡ����˽׶���
��ȡ�Ĺ���Ҳ����Ӧ����Ѷȡ������Ĺٿ��԰�����������֮�ڹ���һ��ʯ
��ʳ����Ȼ�����ó��ϵͳ��ϵ��������ұ�����������������Ա��ˣ���
����������ҵ�����Ǯֻ���٣�����࣬�Ƕ�����Ĳ���ֻ���Լ��е�������
��֮�󻹱��븺��Ѻ�˻سǣ�·�ϳ���ʲô���ӵĻ��ֻ�Բ��˶����ߡ����
���԰����������������ڶ������֧�����������ľ�ļ����϶����Լ�һ�ֲ�
�졣

�м���������

�������ࣺ��������������ȵ�
�����������ȼ������м�����һ�涨������
�����ر���Ǯ��������Ʒ���ҳ϶ȡ���������������

��ҵĹ�Խ��Խ�󣬹���ҲԽ��Խ���ӡ���ʱ����ָ�����һ���Ƚ��ۺϵ�Ŀ
�����������ɡ����磬ָ������ڹ涨ʱ����ʹ�õ��ص�ũҵ����������ĳ
���������������ڹ涨ʱ���ڽ�ʿ����ѵ������ߵ����ٶ��ٵȵȡ�

�м���������

�������ࣺ����������������ѵ����Ѱ���ȵ�
����������������һ�������涨����
�����ر���ͬ��

����ҵĹٹ���������һ���ı�Ȩ�Ժ󣬾ͻ�ָʹ���ȥ���ǰ�կ��Ҳ����
Ϊ��Ĺ������������ˣ���Ȼ��ǰ�����׶������Ҳ��μ�ս�ۣ�ֻ��������
�Ը�������ʽ�������ھͿ�������������ֿ����ˡ���׼��һ��ս�ۻ��൱��
�ӣ���Ҫ�����������ĳ����Ϸ����Ȳ�ʤ�㡣

�߼�����һ��

�������ࣺ���ǰ�կ���Ѻ���ʹ�ȵ�
���������������߼���ְ��
�����ر���ͬ�ϡ����ҹ��ס��ͳ�

���ӵ���Լ��ĳ��У��Ϳ���ʵ�й�����Ҳ��һ�ֹ��������еĸ����Բ���
�ԡ��ȵ���ҵ�ʵ����ǿ�������Լ�ӵ�ж������ϵĳǳأ�������Զ�������
�ư��ˣ���Ȼ��ҵ�ĳ�������ǳ��������������᲻ͣ���ַ��㣬�����Ĺ���
Ҳ��û��٣����������İ�ҵ���Ҳ��һ�ֿ��顣�����������ȵ�ʱ��
�����Ҫ������Ƿ�����Щ����ǰ�����Ĺ������������Ļʵ�Ҳ�᲻ʱ���ʼ�
�㣬����һЩ����ȥ��ɣ���������Ϊ�Ĺ�������������ȥ�ַ�����������ȥ
ƽϢĳ����ĳ��֮���ս�ң����������ڹ涨��ʱ�����Ͻ������ʲ���ʳ���
�Թ����Ժ����֣�����������ȥΪ��Ѱ��ĳ����Ҳû��˵���������챦�ȵȡ�

�߼���������

�������ࣺ�ʵ��ʼ�����ȵ�
��������������
�����ر���ͬ�ϡ��;����

���ϱ�������������гɳ���չ�������������׶μ������ܵ����񣬵�Ȼ����
��ֻ��һ���൱���ԵĿ�ܣ������ĵȼ��ȸ������д���һ����ʵ�����ơ���
���ڹ���ϵͳ��˵���Ƚϵ͵ȼ��Ĺ���ƽʱ�Ϳ�����ȡ�����ϸߵȼ��Ĺ�����
����ĳ���ض�����·�����ȡ�������ڵ��������ϣ������еĹ�������������
����ɣ�Ҳ����˵��������������һ�����񣬱�����Ϣһ��ʱ�䣨ǿ�ȵģ�
�Ǻǣ��Ժ�ſ�����ȡ��һ�����񣬶���������񲻻����һ����ͬ����Ϊ��
�ǲ���ʹ����л��������һЩ������֮���������������������������
�õ��˻ر��Ժ�Ҳ������ʱ��ȥ�����Լ���������ν�����ϵͳ��Ƶú�����
������Ҫ���ǵ�ϸ�ĳﻮ�͹�˼��

������ש����ϣ����λ��ʦ�ܼ�������һ��������⡣



---
����: Lei
��Ŀ: wizlist
����: Wed Oct 28 05:17:48 1998
Could any1 write a wizlist?
Since we promote and depromote wiz often... We can't tell who is wiz by
typing ls /wiz leh...



---
����: Stefan
��Ŀ: >ideas(about money and channal)
����: Wed Oct 21 21:02:37 1998
���ڽ�Ǯ����ʵ��������ֲ��Զ�����û��Ҫ�����ֶ���Ǯ�����ϡ�
�±������Ѿ����������ˣ�Ǯֻ�����ڱ���װ��������������;�ϡ�
���Ӧ�������ȥ�� quest �ˣ��������ƽ�ܣ��������ݣ�����̫
����־���У���������������Ǯȥ�����������ü�Ǯ������׬һ�ʡ�
ͨ���ʻ�����Ҳ�Ǳ���ģ�����ٺ»�ȣ���������͸֧�ʹ�ɲ����ˡ��б��µ�ȥ
��Ǯ�

���⣬����Ŀǰ��ҥ�Է�����Ϣ�ǱȽϺ��ʵģ����ÿ����Ϣ��׼
ȷ�Ļ����ѶȻή�͵ģ��������˼�ðҥ���������Ҳ�ǿ������̵ġ���ʱ�����
Ϣ�Ļ���ô��ͨ�����������ݣ��������յ���Ϣ�ˣ���Ȼ�������� mud ������ʱ����
���Ƴ٣���������Ϣ������������һ����ˮ�֣��������֡�Ҫ��ȷ��
ĳ�����Ƿ���ʵ���������ڳ���������ң�������̽�Ӵ�̽�����ԡ�


---
����: Group
��Ŀ: re 204
����: Wed Oct 21 20:58:14 1998
need thank me first, it is me who catch nono from xkx...
grin


---
����: Fire
��Ŀ: new wizards
����: Wed Oct 21 16:30:32 1998
now we have a new wizards: nono
he is pretty good at the history of sanguo
so I am sure he will contribute a lot in this mud
let's give him(her?) a warm welcome
xixi


---
����: Row
��Ŀ: ideas(about money and channal)
����: Wed Oct 21 03:58:25 1998
���ڽ�Ǯ��

�ֽ����MUD ���ָյ�¼��ʱ�������ֿտյģ������������
Ҫ����ͨ����ʲô����׬Ǯ�������ַ�����Զ��Զ��Ƚ���
�����������������Ƿ���һ��ˮ��������ʹ����ҿ�����Ǯ��
������������һ��trick ��Ҳ����ĳ�˿��Ե�¼�������ˣ���
Ǯ��Ȼ�����е�Ǯ������һ��id�������ܿ��Ǹ�id�ͻ���
�൱����Ҫ֪��Ǯ�������Ƿǳ����õģ������Ļ������ʹ��
trick ��id��ռ�ܶ���ˣ����ö���֪���ܶ���Ҷ���֪����
��trick ��Ȼ�󡣡������Ǻǣ����룬��Ҳ����Ϊʲô������
ȡ������ֵ�¼��Ǯׯ����10 silver ����Ҫԭ��ɡ����ԣ�
Ϊ�˷�ֹ��һ�㣬�ҽ���ȡ�����еĲ����ƶȣ���ȡ�Ƚ��Ļ�
�ʡ������ƶȣ�Ҳ����˵��ȡ��ʵ�ڵĽ�Ǯ�����е�������ֻ
�������Ǯׯ�ʻ��ﻮ�ʣ���Ȼ�ʻ���ûǮ��ʱ��Ͳ��ܽ���
�����ˣ�����һ�������ǻ����Կ���͸֧�����������öȹ�
�õĻ�����ô�ǲ���Ǯׯ�Ĵ��ھͲ���Ҫ���أ����ǣ����ǿ�
�������ֻ����Ǯׯ��ʱ����ܲ��ʣ�����������ҽ��ж���
����ȵȣ���֮�Ժ����֮��Ͳ��ᷢ���κν�Ǯ��ϵ�ˡ���
�εĽ��׶�����ͨ�������������ˣ���Ȼ����һ���Ƚ��ִ���
����������ʧΪһ����������š�

����ϵͳ��������Ϣ��

����һ��ϵͳ��������Ϣ������ĳ����Ǩ�����������飬����
ս��ʲô�ģ�������ҥ�Ե���ʽ������������ǿ���ʹ��ҥ��
Ƶ���ģ������Щ���ĵ����������㷢������Ϣ�Ļ�������
�����������ҵ���ʧ������һ�£���������ңԶ���������
�Ļ���ͻȻ����ҥ��˵�Լ��Ķ�������Ҫ�����ˣ��ɵ���Ͱ�
�ظϻ�ȥ��ʱ��ȴ���ַ�ƽ�˾����������һ��ҥ�ԣ����
��ô�룿�ǲ��Ǻ���ѽ�����ԣ��ҽ��齫�����������Ϣ�鵽
һ����Ҳ���ʹ�õ�Ƶ���������磺������־�����������Ϊ
�Ĵ���ʦ�������Ͳ�����ɻ����ˣ���Ȼ���Ժ�Ҳ�Ͳ�������
ҥ�����ƻ�ĳЩ�����˵��ж��ˣ������룬�������ĺô�����
���ڻ����ģ������ܻ��б�İ취�Ը������˵ġ�

���Ͻ���ɷ�ʩ�У�ϣ������ʦͬ�ʷ�������


---
����: Fire
��Ŀ: about thw warroom.c
����: Mon Oct 19 19:07:49 1998
each area has a warroom.c please becareful
don't delete it


---
����: Stefan
��Ŀ: lib broken
����: Mon Oct 26 16:51:54 1998
machine crashed, and last backup is not new enough.
Fire, if you can fix it, just try your luck, otherwise, I will
replace data file with old ones from the backup.


---
����: Stefan
��Ŀ: >lib broken
����: Mon Oct 26 17:00:37 1998
On Mon Oct 26 16:51:54 1998 Stefan wrote post #230:
> machine crashed, and last backup is not new enough.
> Fire, if you can fix it, just try your luck, otherwise, I will
> replace data file with old ones from the backup.

It seems very strange to me that countries.o actually contains
data from an empty troops.o, while troops.o contains gabage data.

I replaced countries.o with the backup on 22nd September. And cleared
troops.o to empty.

Any recently updates to countries.o since 22nd Sep has been lost.
Sorry for this, I should keep a backup every week.

stefan


---
����: Fire
��Ŀ: good job flee
����: Tue Oct 27 16:27:44 1998
flee has done very good job
addoil all
I am sorry that i have to prepare my exam
so can just come here for idling and fix bug
I will be free after exam (if i can pass them)
then will be a long holiday, very nice
addoil all
sorry for the delay


---
����: Stefan
��Ŀ: verb parsing
����: Thu Oct 29 03:56:23 1998
I did a heavy investigation to the driver's verb parsing machenism,
and finally conclude that it is NOT THE RIGHT WAY of handling this.

I will rewrite all verbs, and all other wizards, please do not make
changes to verbs from now on, until this rewriting is finished.
The estimated time for this is 1 month, because my parents are
coming to visit me, so my time are booked by them :P 

Sorry for any inconvenience it may cause, and thanks for coopration!

stefan


---
����: Fire
��Ŀ: >verb parsing
����: Thu Oct 29 16:56:37 1998
how about the cmd ?
i mean the command in /cmds/player and /cmds/wiz and /sgdomain/cmd ?
where those affect your work ?


---
����: Stefan
��Ŀ: >>verb parsing
����: Fri Oct 30 23:03:17 1998
cmd will not affect my work.
I will try to do it at another place, after it is stable,
I will merge back changes to here.


---
����: Fire
��Ŀ: welcome new wizards
����: Wed Oct 14 16:36:30 1998
Now bamboo has been promoted as a new wizard
welcome and hope a nice time



---
����: Fire
��Ŀ: depromote wizards
����: Wed Oct 14 16:31:32 1998
ryan      ����      ��ʦ  ���ߣ���ʮ����         newgate.mitel.com
according to wizrules
ryan has been depromoted to player

fire


---
����: Row
��Ŀ: to group
����: Fri Oct  9 06:36:27 1998
group, check your mail (in lima) please.


---
����: Stefan
��Ŀ: fire.h
����: Wed Sep 30 05:31:19 1998
Last crash was due to a careless editing of /include/mudlib.h
I believe fire added fire.h to mudlib.h, but in fire.h, there is
a Macro definition of min and max, which conflicts with simul_efun
definition of min & max in simul_efuns/misc.c 

Note that mudlib.h is a system wide include file that used by all
programs, even a small conflict there will cause everything to hang.
I've removed "fire.h" from "mudlib.h", simply because "fire.h" is only
San Guo specific including file, it is not a system wide thing.

It is obviously a simple thing to add 'fire.h' to 'mudlib.h' so as
to avoid "#include "/wiz/fire/fire.h" everywhere. But, please remember
good structure always comes before convenience consideration.

I also suggest that fire.h shall have another name, for example,
"sanguo.h" and shall be moved to /include instead of fire's own dir.
It is already used heavily under every sanguo related code, not only
fire's own including file already.

By removing 'fire.h' out of 'mudlib.h', some code may be broken, 
all wizs please check if anything is wrong...

stefan


---
����: Lcm
��Ŀ: trade + ideas
����: Mon Sep 21 11:40:29 1998
Design for business
-------------------

goods to trade:
horse, bow, rice(food)

Objectives
----------
1 allow country or area to manipulate their resources
2 allow player to improve their skills and reputation

Other ideas (optional)
3 use traders to distribute quests (sell quests)
4 combine with a bandit system, goods can be stolen by 
  bandits in the area
traders will request the help
  to retrieve the goods -> initiate a war to bandits


Details
-------
only areas that are level 3 to 5 have traders

nw - longxi, xiliang, tianshui
nc - qinchuan, anding, xianyang, jingyang
c  - changan, hongnong, luoyang
ne - taiyuan, shangdang

The areas are grouped into regions
to facilitate the traders route.
Each trader in general will visit each region in random order
and then visit each area in the region in random order

due to a higher demand of goods sold by the trader
certain areas are avoided because of war or the safety level
is low - bandits)

we may allow the adjustment of traders frequencies to test
the system, whether there are sufficient traders.

When each trader moves to a new area, their new location
will be announced.
Officers (players) in the area can ask for a local meeting
to decide whether to sell or buy certain goods.
In the meeting, the officers will vote whether to approve
the suggestion, if approved, the player who suggests will
get the task. 
and how much goods

Once approved, the trader will be summoned to the meeting place
to begin the trading.

The trader can be classified into 2 types:
- money-minded ����
- normal

Each trader may deal with only 1 type of good or all types.


For the money-minded, his selling price quote is always high
price may be based on the demand for the good, the safety
level and the finance of the area.

The player can accept the price. (Trade done)
or refused and suggest another price.
If the suggested price is low, the trader may left (Trade incomplete)
If price is close to trader price, trader may accept (Trade done)
otherwise, trader will give player a second chance.

The player should now suggest a price in-between. (normal to high)
The trader will consider this price based primary on your
negotiation skill(we can use meili) and also other factors.

If trader accept new price (Trade done)
If refused (Trade incomplete)
--- Trade over ---


For the normal trader, his selling price may be high or normal
price based on demand for the good, the safety level

The player can accept the price. (Trade done)
or refused and suggest another price.
If the suggested price is low (selling price normal), or
if the suggested price is normal (selling price high),
the trader may left and refused to come back for a year
Trade incomplete, -> player is auto-demoted

If price is close to trader price, trader may accept (Trade done)
otherwise, trader will give player a second chance.

The player should now suggest a price in-between.
The trader consider this price based primary on your
negotiation skill(a lesser factor this time)

If trader accept new price (Trade done)
If refused (Trade incomplete)
or refused to come back for a year (price is not close)
 -> player is auto-demoted
--- Trade over ---

Optional scenario after trade done:
Leader ask for any other matter.
If another player thinks the price is too high,
he can lodge a complain to the leader to demote the first player(buyer)

The leader figures out the finance condition and the price
and decide whether the price is indeed too high.
If it is, the player(buyer) is demoted (this will not apply
 to a player that uses the second chance to agree on the price)
If it is not, the player who complains may be demoted

--- Complain over ---

Benefits, punishments

accept immediately - reputation up, trader give a quest
trader accept 1st quote - reputation, meili up
trader accept 2nd quote - reputation, meili, zhimou up
trader left - reputation, meili down
demoted(auto) - reputation drop a level, meili, zhimou down

--- ---

The traders may now sell the quest
ask trader about quest

Quite similar flow if player sell goods to trader

Do we have a quest system now?
How about bandits? (Player can be bandits)

lcm


---
����: Stefan
��Ŀ: >help
����: Mon Sep 21 22:22:51 1998
It is not a bug in your fire extinguisher, it is the problem with
current verb parsing system. You have to specify "first" "second"
object when there are more than one in the room.

I will redo the verb parsing system, dunno when can finish.


---
����: Stefan
��Ŀ: >trade + ideas
����: Mon Sep 21 22:31:38 1998
Lcm's plan says: price is determined by the regional demand of the
goods, and safty etc. I think can also add in another factor,
that is the trader's own ��֧ƽ�⡣ If they trader has many to sell,
he would offer it at
a lower price, if he has already sold a lot, he would not care to
negotiate already.


---
����: Stefan
��Ŀ: wrap to be disabled?
����: Mon Sep 21 22:49:25 1998
Because wrap is unable to wrap colored text correctly, should it
be disabled? Anybody is using wrap now?


---
����: Fire
��Ŀ: support stefan
����: Mon Sep 21 22:50:13 1998
disable wrap is a great idea


---
����: Tset
��Ŀ: >wrap to be disabled?
����: Wed Sep 23 23:55:48 1998
i remember wrapping tends to add an indent after the
first line, which used to give me great troubles in
simpterm :( 


---
����: Fire
��Ŀ: re fire.h
����: Wed Sep 30 20:55:01 1998
It is my mistake to make the system crush
I appology for my mistake
now i have done the following thing to
solve this problem. hope it will not cause
further problem
1 i cp fire.h into /include as sanguo.h
now the fire.h just include one sentence
#include <sanguo.h>
2 since min and max are function in misc.c
so i rename the macro min and max as bmin and bmax
3 i still make the mudlib.h inherit sanguo.h
the reason is that :
a we can use the macro in sanguo.h in cmd line
that will be very nice for testing
b some files may need the macro in sanguo.h
to work properly, now we don't have time
to correct them all
c in order to avoid the same problem
again i suggest that we don't add anything
in the sanguo.h. and when we have energy to
arrange the code then we can move the macros
in the sangou.h to the suitable place


---
����: Flee
��Ŀ: how can force a npc do a command ?
����: Sun Oct  4 02:10:36 1998
seems do_game_command, do_game_commanda and force_me
functions do not apply for npcs.


---
����: Fire
��Ŀ: network problem
����: Mon Oct  5 02:57:11 1998
hi every one
I should make the player can fight
in the war already, but recently
i am pretty busy, and our university
has install new firewall software
so sometime i can't access the internet properly
sorry for the delay


---
����: Flee
��Ŀ: ask responda
����: Mon Oct  5 03:33:51 1998
i find that for some cmds in /cmds/verbs and /cmds/player
do not apply for the function responda.
such as go.c 
why and how can sovlve it ?


---
����: Fire
��Ŀ: re: about the responds
����: Mon Oct  5 21:31:31 1998
that is true for responda it has its limit
because it need the shell to parse the command
and then run it. some time may cause conflict with
the system secure. so in order to make the npc
act, the best way is to call the action function
directly
for example if you want an npc to go to some place
just call
ob->do_go_somewhere(str)



---
����: Fire
��Ŀ: about the move of npc char
����: Mon Oct  5 21:36:15 1998
now i make the npcchar also inherit 
m_smartmove so it can move now
> @CHAR_D->find_char("benben")->responda("go out")
С�����������뿪�ˡ�


---
����: Flee
��Ŀ: help
����: Mon Sep 21 04:39:38 1998
there a bug in fire extinguisher.
for example, if two person, each of them bring an
extinguisher, when one of them try to turn it.
the driver will ask him ' which one u want to turn'
seems that the two is on one person.

why ?


---
����: Flee
��Ŀ: can not learn jbhj
����: Sat Sep 19 09:04:11 1998
in the daemon "/daemons/learncheck_d" does not have
that choice, learn jbhj is prohabited now :(.

can fire add this.
thx


---
����: Fire
��Ŀ: start war
����: Tue Sep 15 00:49:37 1998
now i modified part of flee's map_d and move it to
/daemons 
this file is used to handle map part of the war
the room part will be handle by
/sgdomain/modules/war_grid.c (hasn't finished)
we still need troop_d.c to handle the troops
and many works in task_d.c
addoil all


---
����: Flee
��Ŀ: about war
����: Mon Sep 14 09:38:24 1998
have a look at /wiz/flee/txt/war1


---
����: Fire
��Ŀ: depromte wizs
����: Mon Sep 14 02:23:48 1998
according to the wiz rules
testing, softwind and shaoyng are
depromote to player for not appearing for more than
30 days


---
����: Fire
��Ŀ: i find a mud with 598 players online, what a world
����: Wed Sep  9 05:53:25 1998
donot know if our system can support so many ppls


---
����: Stefan
��Ŀ: plan on DMS
����: Tue Sep  8 09:53:28 1998
Document Management System (DMS)

DMS maintains 4 kinds of documents:

1. posts on bulletin board. (currently we call it news)
2. mails of every players.
3. help files on specific topics.
4. help files automatically generated from source codes.

DMS has a completely different presentation from current system.
DMS will work with documents written in Simple Markup Format.
DMS enables documents browsing on WWW.
DMS is easy to update, and easy to maintain.

(I). User Interface.

    1. User type 'bbs' to read bbs, 'mail' to read mail, 'help' 
       to browse 'help', or type 'dms' to go to DMS directly.

    2. Generally, DMS behaves the same way as current help, but
       it will show �ŢƢǢȢɢʢˢ̢͢΢ϢТѢҢӢԢբ֢ע�
       to mark any "links" the user can follow. (just like HTML)
       On one page, 20 such markers should be enough already.
       Users can type in digits to go to that link. Marked links
       will show up in BOLD so as to get attention.
       Therefore DMS will use a different MORE to view documents.

    3. WWW interfacing.
       DMS will has a CGI component that act as a document locator
       on the Web. Links will be shown as HTML links, and user
       just have to click to go on.

(II). Document Serial Number (DSN) & Markers.

    1. All documents will have a DSN assigned, so that it will 
       be uniquely identified by that DSN. DSN does not include  
       auto-generated documents, which will only use markers. 
       DSN is generally hidden from the presentation, but if a
       user wants it, he/she can still check it out and use it
       as a reference to existing posts/documents.

    2. Markers will have the form "<R=...> some subject </R>".
       Pure <R> </R> will only hightlights "some subject" by
       bolding the font. the ... will be the actual link, either
       a DSN or something of the form:
          POST/boardname/.../articlenumber
          HELP/player/.../help file name
          HELP/wizard/.../help file name
          HELP/admin/.../help file name
       Note that MAIL is supposed to be private and can not be
       referenced in the marker.
    
    3. Because of such markers, all documents will be wrapped
       automatically. In order to do a correct wrapping, two
       other markers are needed:
          <P>       another paragraph   
          <T> </T>  4-space indentation 
       All HELP files shall follow this format. 
       But for POST, especially for user's post, plain text is
       also acceptable. But once some text contains a marker,
       it will be treated as a MARKED text instead of PLAIN text.


(III). Documents Auto Generated From Source Code.
       In every program, you can write your own inline documentation
       that will be collected by DMS. In any program's comments,
       you write:

        //:MODULE
        //This is the description of this module.
        //$$ Note: helpsys style directives can be included
        //see: another_module

        //:FUNCTION funcname
        //This is the doc for function funcname

        //:COMMAND
        //This is the doc for the command

        //:HOOK
        //This documents a hook called with call_hooks

        //:EXAMPLE
        //This is an example to illustrate some code.

       When DMS goes to collect all inline documentations, it
       will automatically catergorize your comments into help files
       for modules, for functions, for command, for hooks, for  
       code examples etc. Actually, this is what current doc_d.c
       does. We (document group wizs) will help to add helps to  
       all commands in this way. But it will be really helpful   
       if you write such inline comments in any of your programs.


(III). Schedule.
    1. Write DMS menus & parsers.
    2. Make news & mail working.
    3. Write help files.
    4. Get inline docs to all commands.
    5. Get WWW cgi part working.

    2, 3 & 4 can be done at the same time. And we need more wizs
    to join us in writing help files. 5 has the lowest priority,
    let's finish 1 - 4 first :)

Any suggestions or comments?

stefan


---
����: Stefan
��Ŀ: help files
����: Sun Sep  6 22:06:14 1998
Welcome any of you to write help files, please put them in /help/player/
and make sure:
1. It does not confict with existing help file name, or you want to
    replace the existing one.
2. At the last line, add "last reviewed: <your name>"

We (me & yue) will review all help files after new document system is up.


---
����: Tset
��Ŀ: back
����: Mon Sep  7 04:00:37 1998
Wow, so many new messages, addoil everyone!
Just get back from my summer (my modem is too lag), seems
I will start shifting through all new changes.  So I
guess I would like to take responsibility for number 7,
�ߣ� ���� , since I personally can't stand typos (being
as picky as I am) and bugs.  I will help out in the 
OBJECT (#4) and #5, maybe even #6, if I do find time
to do those.
The GRID_SERVER needs to add a lot, my personal idea is
to add associated points to each place, ie, ����.  Maybe
even movement cost.  Otherwise, I suggest use such system
for most non-critical room development, and it is very
easy to make a maze out of it :).


---
����: Fire
��Ŀ: the help
����: Wed Sep  9 07:20:18 1998
I moved all the help file from sgdomain/txt/help
to /help/player/sanguo/
now most help files can be access from cmd help
and help 
for map and fly
there are some difference 
since if you use map and fly will display all the
help txt and the availiabel fly and map area
and they are dynamical so the help fly and help
area just display a hint info


---
����: Row
��Ŀ: lvl 1 area all finished
����: Fri Sep 11 02:25:31 1998
now all lvl 1 areas have been finished, including :
jieting, tongguan, hangu, didao, chencang.
please test.
now move to lvl 2 areas.:)


---
����: Fire
��Ŀ: nice work, row
����: Fri Sep 11 02:50:05 1998
addoil row


---
����: Flee
��Ŀ: works
����: Thu Sep 17 04:31:03 1998
i will write some place for ppl improve skill :)
and i want to access the /sgdamain/area/ so i can 
directly make changes.

thx.


---
����: Fire
��Ŀ: flee is add to the Mudlib
����: Thu Sep 17 20:38:02 1998
as title


---
����: Fire
��Ŀ: ˭�����ask.c �ˣ�
����: Fri Sep 18 09:08:25 1998
ǰһ��ʱ�����޸���ask.cʹ����settle,position,
zgxy,bfxy and wxxyʱʵ��ǡ���ĺ�����Ӷ����Ǽ�
�� ������Դ�������<settle>����Ϣ��
����֪��˭���µ�ask.c��ɾ���˻���һ���ǳ��ɵİ汾
������ҵ��°汾����û�������
�����Ҫǿ��һ�㣬��һ���ļ�����Ҫ��̫�࿽������ʱ
�໥���ǻ���鷳��
лл


---
����: Fire
��Ŀ: about the help
����: Sun Sep  6 08:41:22 1998
sorry, i move it to /help/player/newbie


---
����: Fire
��Ŀ: about the rumor
����: Sun Sep  6 01:02:08 1998
today, i disable the announce of the sender after a
rumor, since that extra announce make us disturbed
if in the future we find some guys realy always use
rumor to send nausty message then we can add this feature
back

cheers


---
����: Fire
��Ŀ: about title
����: Sat Sep  5 07:58:28 1998
the usage of cmd is a little confused
the first time i design it is because i don't
want to create so many verb or cmmd under /cmds
so make some new commend (especially those just used for
sg under) cmd.
now i find the cmd is easy to manay and document.
because you can use cmd list to list all the
cmd and use cmd help <cmd> to display the help file
and also it is related a little easier to write a new
command in this way. 
so i have a idea, in current stage we will not increase
more verbs( since we already have enough verbs)
chat* shake
if need some new commend just put it under /sgdomain/cmd
of couse this will make player input 3 more chars
but in this mud, player will not input as many cmd as
in other muds, this will not cause much unconvinent
the problem of title in menu has been fixed


---
����: Stefan
��Ŀ: map in html :)
����: Sat Sep  5 00:43:00 1998
This is a fantastic idea :)

Since we have HTTP server, and CGI can be wrote in LPC, why not
write a CGI that shows current sanguo map? which city belongs to whom,
how to go from one to another... We can even use some graphics,
some colors.

We can shift some of our mud helps/docs/queries to the web.

what do you guys think?


---
����: Stefan
��Ŀ: about cmd
����: Sat Sep  5 00:10:57 1998
I thought cmd is only meant for San Guo military/country related
commands. Things like 'cmd nick' should be directly 'nick' ba?

Also, is 'cmd' a temporary thing? Since we shall move towards menus.


---
����: Stefan
��Ŀ: about title
����: Sat Sep  5 00:03:16 1998
I feel that �� something is not aproperiate. Old lima's title is flexible, 
and es2 style title is also okey. Actually I prefer es2 style.

Also, fire please be sure you changed all related stuff with title,
not only by removing command 'title'. for example, player can
still use 'menu' to set title, in which $N will still appear.


---
����: Fire
��Ŀ: about the task
����: Fri Sep  4 22:40:57 1998
use help tasklist to check the list of task
we have noticed that the following wizards don't have
register any task yet
yuner     �ƶ�      ��ʦ  ���ߣ�ʮ��Сʱ         delta.ntu.edu.sg
tset      Է�      ��ʦ  ���ߣ�������Сʱ       128.42.75.29
ultra     ����ְ�  ��ʦ  ���ߣ�������Сʱ       202.101.104.246
net       �����  ��ʦ  ���ߣ������ʮ��Сʱ   165.91.210.69
benben    С����    ��ʦ  ���ߣ�����ʮ��Сʱ     203.127.166.57
roc       ����Ϊ��  ��ʦ  ���ߣ�����ʮ��Сʱ     202.96.158.246
ryan      ����      ��ʦ  ���ߣ�������Сʱ       newgate.mitel.com
group     ����      ��ʦ  ���ߣ�����ʮ��Сʱ     leonis.nus.edu.sg
testing   ����      ��ʦ  ���ߣ���ʮ����         mirage.irdu.nus.edu.sg
shaoyng   ����ͤ    ��ʦ  ���ߣ���ʮ����         141.217.54.11
softwind  �ͷ�      ��ʦ  ���ߣ���ʮ��           202.99.8.123

hope you can regist a task within this month




---
����: Row
��Ŀ: about title
����: Fri Sep  4 09:15:13 1998
��ʵ���Բ�������mudʹ�ñȽ϶��whoģʽ:
������who, ֻ��ʾ����������ҵ�����id��Ӣ��id,��:����(row)  �һ�(fire)
������who -l���г�����������ҵļ���Ϣ,��:
���ʶ����¡�  �������󽫾��������޵С����� �֡���ҹ��(row)
 (����)  (���ڼ����)(�Զ��Ĵº�)(����id) (��)  (Ӣ��id)

�����Ҫ��ansi��ɫ��������,�Դﵽ��Ŀ��Ŀ��.

����who -w���г�����������ʦ��id.
����Ҳ�������������Ĳ����г�������Ϣ.

������room�е�����:
�������󽫾��������޵С�����

ϣ���������и��õĽ���.


---
����: Stefan
��Ŀ: DMS report
����: Wed Sep  2 22:15:55 1998
Currently, Yue & I are doing DMS (document management system).
Here is a short plan for all wizs to review:

TITLE: Document Management System
Hmm, let's classify those documents first, here are several 
categories I have in mind:
1. player commands help.  
2. General mud help.                                
3. San Guo help.
   This is specifically to this San Guo mud.

The above is for players, now for wizs:
1. Rules, regulations, notices, etc.
2. General help on mud building.
3. LPC help.
4. Lima specific help on functions, securities, etc.
5. San Guo construction reports/plans/progress/subjects/etc.   
    
Above are only meant for helps, now for general documents:
1. Code documentation. Coders should write it, but need us to remind them.
2. News archive. News system shall be rewritten to fit in with our 
   general document system. Currently News group will blow up soon
   when news become larger & larger.
3. Mail archive. Current mail system works fine already, but might
   need some changes in order to integrate together with the document
   management system.
Any good suggestions? What I plan to do is such a system that:
* enables user to quickly browse through documents of any kind,
  of course, depending on his/her privileges, and easy to make
  references.
* has a powerful search tool to get to answers of any problems.    
* will be something like HELP in Windows, but of course, we can    
  not have links for users to click, but we can do it in some
  other way, for example, use annotations such as �٢ڢ� to mark  
  links, and user just has to type 1 2 3 to go to that link...

Addoil!



---
����: Fire
��Ŀ: where is it
����: Wed Sep  2 21:40:00 1998
stefan, what is the address for another sanguo


---
����: Stefan
��Ŀ: just had a look of the other sg
����: Wed Sep  2 03:15:56 1998
It is still LP mud. Descriptions look cool :)
Have not got time to play deeply, but already saw a lot of things
such as typos, simple errors, etc.

I feel pretty messy there. 


---
����: Fire
��Ŀ: depromte wizards
����: Tue Sep  1 03:02:03 1998
according to current wiz rules
pickle, super and testjig didn't come here
for more than one month without any reason
so will depromote them to player,
if they still want to work here as wizards
need to re-apply


---
����: Fire
��Ŀ: new wiz
����: Thu Aug 27 03:36:13 1998
now ryan is accepted as a new wizard,
welcome ryan
liz can't work here for some time
as he asked, we change him back as a player
when he has time and want to work here again
will re-promote him
addoil every one.


---
����: Fire
��Ŀ: lei will be responsible to the �ˣ� ����       
����: Thu Aug 27 03:47:51 1998
addoil lei
hope to see your page soon
addoil lei


---
����: Fire
��Ŀ: new wizard
����: Sun Aug 30 20:11:45 1998
as lcm asked, we promote him back to wizard again
his first task is help row to do some area code


---
����: Fire
��Ŀ: help for player
����: Sun Sep  6 08:35:44 1998
now i begin to write help for players
the first one is /help/player/starts
can stefan suggestion will to put them and is there
any special requirement


---
����: Flee
��Ŀ: about task
����: Tue Aug 25 06:22:03 1998
i will will continue working at war system, but i am
very very busy now. MID-TERM EXAM and three project
which have to be finished by the end of next month :(
anyway, i will try my best to finish in the coming recess.


---
����: Stefan
��Ŀ: >tasklist
����: Tue Aug 25 05:10:39 1998
I would like to take the Person-In-Charge post for MUD OS ��ײ�MUD LIB
And also �ĵ�����



---
����: Fire
��Ŀ: tasklist
����: Tue Aug 25 03:43:30 1998
please use help tasklist
to check current tasklist
very important,


---
����: Fire
��Ŀ: the day of open
����: Tue Aug 25 03:06:41 1998
we will do our best to open this mud a test version
by the day of 1/11/1998
I am very sorry for nearly haven't done anything the
past few days.( really busy)
but i will give a clear tasklist by the end of this
week, and all wizs if still want to work here can
try to find some suitable tasks.
addoil every one


---
����: Fire
��Ŀ: to all wizs
����: Sun Aug 23 22:00:06 1998
please don't change players parameters just for fun
if for test popuse, after test, then change it back
to original status.
some time the change will cause the system in
confused situation and will lead to bug
this mud current has many potental bug, so we
need make sure it can run in normal situation
propoly and then test some unusual situation
if now, some change will lead illegual change
to some data will cause the system in quite
conflict status and cast a lot time to find
the reason. i really don't want to limit
some wiz's power just for he(she) misuse his(her)
power. but i will give a warning here, if i find
any wiz modify data just for fun and cause
this system in confused situation, i will depromote
him to player.


---
����: Fire
��Ŀ: about the email address
����: Thu Aug 20 20:34:23 1998
all wizards please give you email address
so that if you didn't can't login here
and we also have sth to inform, that will be
a good way to contact


---
����: Fire
��Ŀ: about the document system
����: Tue Aug 25 18:39:55 1998
the document part of current tasklist has three tasks
one is about the 1�� ͳһ����HELPϵͳ
i think this could be document system.
now in this mud there has some conflict about the
document. one is the location, the other is the
access method. the old lima put all the document
in /help. but we have put some of our own document
in /sgdomain/txt.
the other conflict is about the access
for the old lima it use help <subject> to
display the document's content but for some of
our help file we use different way 
for example we use fly and map to display
the help file of "fly" and "map" and use
map <id> or map <here> to display a content of certain
map. and use cmd help [subject] to display the help
file for certain command.
so I think that we'd need to re-arrange the document system
and I also suggest that we can keep both way to access
the documents, since that will be more convinent for
players.
anyway, I believe stefan will do very good job
and he will be responsible to the document part and
i will help him to write some player help files
addoil


---
����: Fire
��Ŀ: about the war
����: Tue Aug 25 18:41:52 1998
the war is very hard part for this mud
and i think flee will have a very busy time
and if don't mind, i will help him in some part
for the war, and he will be responsible for
the war system
addoil


---
����: Yue
��Ŀ: task
����: Tue Aug 25 21:18:23 1998
i take ���� �ĵ�


---
����: Row
��Ŀ: my task
����: Tue Aug 25 22:41:04 1998
i will be responsable for part 4: area building.
welcome for any assisstance.
thx


---
����: Stefan
��Ŀ: >task
����: Tue Aug 25 22:54:34 1998
�Ǿ���˵ yue �Ժ���ҳ�һ�뷹� :)

Ŀǰ��������� fire ��˵��summarize ���£�
1. ���������� help��һ���� /help ��һ���� /sgdomain����ʵ������
�ֿ�Ҳ�ã����� lima �� sg �Ĳ��ظ����ֻ����ˡ���Ȼ���� help ʱ
Ҫ�����������֡�
2. �ܶ� help �ĵ���Ҫ��д����������Ϊ��ǰ����Ӣ�ģ�������Ϊ�ܶ��Ѿ�
�������ˡ����ﻹ����Һ���ʦ�� help�����߶���Ҫ����
3. �Զ��ĵ��Ĳ�����doc_d �ᶨ�ڲ�ѯ���ֵ�Դ�룬������ժȡ���涨
��ʽд�� comments �е� help ���ݡ�����һ���ܺõ� feature, ������
�е� bug��������ʦ����д code ʱ�� help Ҳд�� comments �У����
ʡȥ�ܶ� update help file �Ĺ�����
4. ��ʦ�� help Ŀǰ��˵����ҵ�Ҫ��Ҫ������ ultra �͸���˵ lima
�� es2 �кܴ�̶��ϵĲ��û�к��ʵ� help�������޴����֡�

Yue, �һ� mail ����������һ�·ֹ������⣬������������ĵ�������
��˵��

-stefan


---
����: Fire
��Ŀ: tasklist updated
����: Tue Aug 25 23:13:50 1998
I will do ���� �¼�������   
and help document and war in some parts
and balance the progress of different parts


---
����: Stefan
��Ŀ: changes in messages and emotes
����: Wed Aug 26 04:20:32 1998
I noticed that "verb LIV" if LIV is yourself, it is replaced by "STR",
but I do not think this is a good change, because "emote yourself" is
just a tradition inherited from ESII style, nothing really fundamental.
I believe to simplify such message will be better. So I changed it
back. And now if "stefan hit stefan", it will use the rule for "hit LIV".

Though many emotes currently may turn to strange message if you do actions
to yourself, I am editing all emotes, and will remove all "verb STR" in
the emotes. Therefore, after I am done, it will not cause trouble again.

I made changes to m_messages.c and made a similar rule as for the
original Lima LIB, and also compatible to fire's change. Please see
/sgdomain/txt/other/newemoterule.txt for details.

Any suggestions are welcome.


---
����: Lei
��Ŀ: webpage and advertisement
����: Wed Aug 26 05:19:58 1998
I will be incharge of HomePage and Advertisement
The HomePage will be finished in mid-Nov which I think is not late
for the openning.
On the other hand, I will write some posts in BBS and other muds to
advertise ourselves.



---
����: Stefan
��Ŀ: emote updates
����: Wed Aug 26 11:30:39 1998
Please note that I deleted some emotes which I think not 
very approperiate... 

If you made that and you want it back, just add it back 
using new emote rule. I would appologize for that.



---
����: Stefan
��Ŀ: ansi color again
����: Wed Aug 26 11:33:58 1998
Well, actually I logged changes in didlog already, but for those
who do not read didlog (why ignore it when you login?)...

/include/ansi.h is changed to map to lima's color scheme.
There are some colors missing compared to the original ansi.h,
which are mainly background and composite colors.

Sorry if it happens to break your code. Please notify me if anything
goes wrong...


---
����: Fire
��Ŀ: about the m_messages
����: Tue Aug 18 20:53:44 1998
that system has been used for a long time
please refer the post on progress [6]
 6. the semote system                   [Fire       on Dec 31]


---
����: Fire
��Ŀ: who has changed m_messages recently
����: Tue Aug 18 20:44:50 1998
please change it back
please use showemote temote to check
the defination of all the chars
or see the file /sgdomain/txt/other/semoterule.txt
to get details
all the semote and the action has been build
on such rules
if not familiar with it, at least can ask
change without compitable will cause countless bugs


---
����: Fire
��Ŀ: re: bugs
����: Tue Aug 18 20:24:21 1998
that bug about the long long list has been fixed.
in /sgdomain/modules/m_ask.c


---
����: Stefan
��Ŀ: bugs
����: Tue Aug 18 05:26:48 1998
cat /data/players/c/cdd.o, look at the long long list, too many
duplicates.. something bad in the code ?


---
����: Stefan
��Ŀ: >about war
����: Tue Aug 18 05:19:36 1998
����Ϊ fire �� plan ���Ǻ������ͬС�죬�ҷǳ���������ʽ��
RPG ս��ģʽ��Anyway, just my personal feeling.

������������ upload �������������������û������ʽ����ʽս����
���Ҽ����棬�ܴ�̶���ʤ����ȡ��������ɱ��Ӻδ�������
�����������Ͻ�������ս���Ա�÷ǳ����ӡ�������ͨ��������
�޷���ʡ��֮��Ĺ������հ�����ʽ��ս�����úܸ��ӣ���û
�кܶ���˳��������С�

��Ȼ�����ش�����˵�����������һ����Ͼ�������ʽ��ս����
�У��Ҳ������Գ��Ǹ���������ȥ��

���⣬Ҳ���λ��ʦ������ڣ������������ :)


---
����: Fire
��Ŀ: about war
����: Mon Aug 17 23:14:28 1998
setfan �Ľ�����Щ����
���ڹ���ս��ϵͳ���������룬����Ҷ��Ὠ��
��Ҫ���룺
1 ս������Ҫ�ɷ���ϵͳ��ʾ��
2 ��������Map��ƣ�Map��������Ҳ��ĵ�ǰս
�µ�ȫ������͸���ϵͳ�ģ���ϵͳ�����乹��
��Mapһһ��Ӧ��
3 ÿһ��ս��ɫ��Ӧһ֧���ӣ���Ҳ����һ֧��
���а���������ɫ��
4 ÿһ������һ���Ļ��������������ڷ�������
���򷢶�����ʱ������һ���Ļ���������������
�㽫�޷��ƶ��͹������������ָ��Ŀ������ɲ�
�ӵ�ʿ����ѵ���Ⱦ�����
�������룺
5 Ϊ��ǿϵͳ�Ŀ����ԣ��������¸�������
1 ������Ϊ���֣�
A Զ�̹��������� ��Խһ�䷿���б��
  �ҷ�����λ��M�����ù�������λ��CGIKOQSW
  ���ĵ���
B ��ͨ�������ҷ�λ��M
  ����ͨ����λ��HLNR�ĵ���
C ǿ�� ������Χͬ��ͨ����
D ���� ������Χͬ��ͨ����
  ABCDE
  FGHIJ
  KLMNO
  PQRST
  UVWXY  
ͼ 1
2 �Ӿ���Χ��üһ���Ӷ���һ�����Ӿ���Χ
��Χ��Сȡ�����ӽ������ı��
ʹ�õ�ͼ����ʱ������ʾȫ�����Σ�ȫ����
�����ӣ���ȫ���ҷ������Ӿ���Χ�ڵĵз�
���ӡ�(������ӳ���)
3 ��Χ��
  һ������ֻ�����������ĸ����ڣ���ĳһ
���ез����ӣ�������˷��ƶ�(����
�ѵ������)��һ�������ķ����е�������
����Χ״̬��
4 ���ˣ�
  ��һ�����ƶ�����ͼ��Ե��ͬʱ�õ���
�б��������ڵ��������ѡ���ˡ�
5 ��˧���´�ָ�������
����ҿ��ƵĲ�����ϵͳAI������ָ����
����������ӵľ����ж���


---
����: Fire
��Ŀ: addoil stefan
����: Mon Aug 17 17:55:43 1998
sweat stefan


---
����: Stefan
��Ŀ: verb parsing
����: Mon Aug 17 07:14:06 1998
This is tough :( The code inside the driver is really messy, and I plan to
code a parser in LPC, let's pray the it will not affect the speed.


---
����: Stefan
��Ŀ: �� map ��ս��������
����: Mon Aug 17 00:56:46 1998
����Ϊ�� MUD �е�ս��û�б�Ҫ�� map ������ԭ���ǣ�
1. ��û�����ӿ����ԣ������Ҫ������ map ��������һ�����ƶ�����
�൱���������Ҷ����е� lag ��������޷����ܵġ�
2. ��û���ṩ����Ĺ��ܡ���ν���о�������ν���üƷŻ�ȫ����
�������еķ���ϵͳ��ʵ�֣�û�б�Ҫ�ڷ���ϵͳ֮���ֽ���һ�������
map ϵͳ��
3. �����ʺ� realtime�����������ж��ķ�ʽû�� realtime ��Ҫ���
��ʱ�ԡ����˵�������ɲ����������������ƣ���ô�Ʊ����� map ����
����ͻ�Ŀ����ԣ���������ִ����鷳������������������Ǻ��� MUD
��������ʲô���������壬�����壬�ڰ���� MUD script �ȱȽ��ǣ�Ϊ
ʲôû�����棬������ΪҪ������ map��̫�鷳��
4. ������ʵ��ս���ĸ��ӻ����� map ��һ����ȥ�����˵��ж�һĿ��Ȼ��û��
���ܿ��ԣ�ȱ�� realtime �������Ժʹ̼��ԡ�
5. ����Υ���� MUD �ı��ԡ����� MUD ��ó��ľ���ͼ�λ����򵥵�
ASCII ͼ����������һЦ�����ԣ�����������Ϣ�ͱ��������ݱ�ļ���ս
�����Բ��㣬���Ҫ�� map������ȥ��ͼ�� MUD ���ã���ó����в���
�á�
6. ���������ĽǶȳ��������������ķ��ա����������еķ���ϵͳ����
�������˸��Ӷȣ�������һ��ս����ս����Ҳ���Լ������֣���������֮
���ս�����Ա����ֳ�����ս����ս��һ�������� map �ĽǶȣ�һ�� map
�Ϸ�����ս��������С�ĵ�λ�ˡ�
7. �� map �������޷����о�ͬ����ͬ��������һ�ε������ܻ�����
ʮ������ͨ���о������Զ������������ʱ�䣬���ڰ� turn ������ map ��
ս�У�������ֻ�ÿ��ŵȵ��������ż�����

��Ȼ�����з������ʽ��սҲ��һЩ����������⣬���ǣ�
1. �����Щ���⻨�ѵĴ���ҪԶС���� map �����ѵġ�
2. ������ map ʵ�ֵĹ��ܣ���������ʵ�֡�
3. ��������ʵ������һ�ι��ǣ�������ĸ�����һ��������ĸ���
ͬ��ս�������� map , һ����Ҫ����һ���ŵĴ������ٴ򣬲�Ȼ����
���佫ȫ���е���һ���ŵ�ս����ȥ�ˣ��޷����������� map ��ս
�����ʵ�����������

��������������Ϊ�� map ����ʽ���ı� MUD ��ʵ��ս������һ��
ʵ�ʿ��еķ�����


---
����: Fire
��Ŀ: re:flee about the map_d
����: Sat Aug 15 20:39:39 1998
hi flee, you have done a very good work
I checked your code and find most are very good
here i have some suggestion:
1 if you can input chinese, it's better to make
the return message in chinese, since we are now
is developing a chinese version lima mudlib
but this is not a big problem, since most the
return message from the daemon just used for the wizs
2 about the int get_full_map(string city_name)
in fact this is used to display the map to the viewer
I think this part need more sophisticated
onec the map has been loaded, it usually not need
to change the content of cells. for example
if a cell is grass, it should be grass all the
time. when an army occupy that cell, when you display
this map, you should display the army in that position
but in your map, you should know that part is still grass
. so when that army moves to other place, you should
display that part grass again. In this case, we should
disign the view of map in that way, if no army occupy
in one cell, just display that cell as the original content
if we find that an army is in that cell, the view should
display the armies . . .
and we also hope that the view part can show the frame and
some basic hints for commond
3 about the char of map
I have designed the character code for warmap
please refer /sgdomain/txt/other/warmap.txt for details
if you want to add something new or modify it
please inform me
thanks


---
����: Flee
��Ŀ: about war
����: Sat Aug 15 10:12:39 1998
i have write a map daemon for map managerment, now 
it can add a map of a city by reading in a txt file,
delete a city map from save data file,
by given x ,y coordinate number, return where there is,
set coneten of x , y point, 
printf the map from save data file,



---
����: Fire
��Ŀ: re: stefan
����: Thu Aug 13 20:33:50 1998
sorry to use english,
because input chinese is really hard.
about stefan's suggestion, i have the following explain
1 about the char_d
in fact the char_d.c is just another copy of semote_d.c
i used exeractly the same technology for the system to 
handle the semotes.
stefan suggested to make seperate plain txt file to
hold all the data for all chars( player and npc)
just like current file system to hold all the players
information. 
now i will try to list the advantage and disadvantage
1) current system will keep two copy for the player chars
data.
that is right, some data will be kept in both the chars.o
and the players own files. This is due a problem but if 
when the replicated data are quite small, it is also under
control
2) current system will keep more data in the memory
that is ture. because when the system is reboot
it will load all the data into the memory. but this
is not a serious problem. as i have mentioned before
a record in char_d just about the same size of a semote
and we know in the lima bean, it has 2345 semotes, that
means it has 2000 record of semote in the memory and will
not cause any problem of memory shortage, so, we don't need
to mind much about the memory useage about the records of chars
since we can use some methords to limit the total number of chars
3) current system is easy to manage.
if we want to add a new field, it's quite easy to write a small
program to make sure that all the record have been updated.
4) easy to program
In char_d.c there are some function quite easy to use
they are:
get_char(<char_id>,<parameter>)
set_char(<char_id>,<parameter>,<value>)
put_char(<char_id>,<file name of the room>)
find_char(<char_id>)
remove_char(<char_id>)
so it is quite easy to use these function for program
5) conculsion
I think stefan's suggestion is quite good,
if it can make still keep the advantage of current advantage
as mentioned in 3) and 4) it will be a good attempt to optimize
the system. any way if just modify the char_d and create some
new files then we can try to realize his suggestion. but if it
will make us to adjust many other files such in /sgdomain/event
and /sgdomain/cmd and other daemons, I think perhaps we can
keep this feature in our next version.
2 about objects
In old lima, when one player quit , he 
will keep all his stuff. now it is me to add the feature
for ppl to lost most of his stuff. the reason for that is
seem the clean_up doesn't work, so if not in this way , we 
will have more and more rubbish in this mud, unless wizs to 
update a room or reboot or dest some objects. any reason is
that we don't have a good parse of object. so if we have one
object more that two, will sometimes cause confused problem.
and i still keep one way to solve this problem is one player
really want to keep some kind of stuff
wizs can add     set_is_keeping(1); in that object's file
then that object will not be thrown when ppl quit.
so all the ���� can be set to that feature.
3 about NPC char ����ں�ʹ���ظ� (ʵ�������ڸ��ﶼ�Ҳ�����) 
that is just a minor feature to test the system's ability to 
handle the npc chars, so it quite easy to disable and we can
keep this discuss in later time
4 about the mud
for sg mud, we can have two methods to play, one is��stratage method
another is tactics. for stratage, a player will stand in a higher
position to view the whole picture and to player just like most
sg pc game, in that case what a ppl concer is the development 
of an area, the useage of chars and the relations to other country
and the war. but for a tactics view (just like in most current mud)
what a ppl concern is to buy food( even chicken lag) to drink to
sleep to recover hp, and find npc to fight . . . 
so that is quite different from here.
In this mud we will most focus on the stratage part, and just put 
a litter force on the tactics part. so when a ppl become a char and
get a position, he will have salary even he is offline, and a char
should not concern about his common armor and weapon and horse,
all of this will be automatally loaded when he need that.
In this mud, the relationship among players will be very very important
in other chinese mud, all the ����Ӣ��.
a ppl can become a high hand without others,( unless need others to tell
some secret or help to broke npc's weapon) but in this mud, one ppl must
join a country to develop. and he must learn how to cooperate with other
ppl in this country and to realize a same dream. one who want to success
in this mud must know how to support others and how to keep others support
him. so it is really exciting and new. . . .
I still have some other ideas about the wiz committee and player committee
In this mud, I hope we can deal the conflict between players and wizs 
fairly. I hope all players come here come enjoy this game and dont' get
harmed by playing this mud. . . .


---
����: Flee
��Ŀ: question
����: Sat Aug 15 03:10:24 1998
mapping test = ([ ({ x, y }): .... , .....]) 
is this kind of map allowed ?
it seems that i can not get the value by
test[ ({ x, y }) ],

why ?


---
����: Flee
��Ŀ: war 2
����: Sun Aug 16 03:42:31 1998
please read /wiz/flee/txt/war, there are some
of my ideas about map_d.


---
����: Fire
��Ŀ: re:flee
����: Sun Aug 16 04:28:57 1998
seem a good idea
addoil
one suggestion:
if you use cell to install all the information
so it's better change the type of each cell from
string to mixed. 
so it can store different type of information
if just a map, then use a char or a int to install
the basic message, if include more complex informatin
then use a map to hold it.
anyway, the mixed will give the developer maxmum
flexible and will not consumre much resource


---
����: Stefan
��Ŀ: Who changed m_messages.c ?
����: Thu Aug 13 03:06:06 1998
I found that things like $No1 $No2 etc does not work any more.
This is bad, next time, please be careful about the original features
when you change something, better keep old features if you do not
know what exactly they are..

Anyway, I have to find a copy from one of the backups, then
compare, then make those changes properly fit...


---
����: Stefan
��Ŀ: weather made a channel
����: Thu Jul 30 01:41:10 1998
As title. And also, I removed all individual color in day_d.c and
channel/cmd.c
If you want to use color, please set ansi.

tset, please note that no_weather_msg etc will be obsolete from now on.

I removed weather.c because it is no longer used.


---
����: Stefan
��Ŀ: ˭���� menu ?
����: Sat Jul 25 04:08:52 1998
̫�������üǣ������ã������һ������������������ menu��

�����У�
1. ���� feelings (emote) �� menu.
2. ���� char �� menu. (setchar, etc. etc.)
3. �������� menu. (setcountry, listcountry, listarea, setarea, etc.etc.)

���Բ������еļ��� menu ���������� mail, imenu, news, admtool �ȵȡ�

������ʦ�������ֵĺû��ᣬ������������(post һ�� news ˵�������ͺ���)


---
����: Fire
��Ŀ: a very good area: jieting
����: Thu Jul 16 22:42:53 1998
jieting is a very good area,
other wizs can refer it to write your areas
because jieting is just a level 1 area
so 5 rooms are pretty suitable to it
here i will give a table for wizs to
refer
level   rooms
1      4-7
2     4-10
3    5-15
4    10-20
5    20-50
the room number here just a suggestion
if anywizs have his own ideas about his
area, can adjust this number
here i want to mention several things
need to concern:
1 about set_area
in each area, we need all the rooms
in that area include one sentence
set_area("<area_id>")
and the area_id should keep the same
for all the rooms in this area
for example, all the room in jieting
need include one sentence:
set_area("jieting")
2 path
for areas with level 4 and 5
place path under /sgdomain/area/cities/<area_id>
for example changan will be in
/sgdomain/area/cities/changan
for areas with level 3
please put in under /sgdomain/area/town/<area_id>
for areas with level 1 and level 2
place it under /sgdomain/area/guan/<area_id>
to check a area's level please use:
listarea /1;
or info a <area_id>
2
3 meeting room and fly room
for each area, we need at least two important rooms
meeting room and fly room
the meeting room is an in_door room
and the fly room in a out_door room
meeting room is the place where all the local meeting
are hold and in sometime the leader of this area will
stay
the fly room is used for player to use fly <area_id>
to fly to that place, and used for that place to
distrubite army
4 map
each area need a local map
with the name is <area_id>.map
and should be placed on /sgdomain/txt/maps/
5 setarea
when one area has been or halfly has been finished
use setarea to install the information into the
system
useage:
setarea <area_id> map <area_id>
setarea <area_id> fly <fly_room>
setarea <area_id> meeting <meeting_room>
setarea <area_id> path <the path>
for example
setarea jieting map jieting
setarea jieting fly jt_area
setarea jieting meeting jt_ysht
setarea jieting path /sgdomain/area/guan/jieting/
setarea jieting area jieting

6 any wiz has any problem about writing areas
please ask me or just post here
thanks


---
����: Fire
��Ŀ: about events
����: Sun Jul 19 22:19:51 1998
About the event
This is a dynamical mud, and all the dynamic data will be stored in
three tables, and these tables will be handled by three basic
daemons char_d.c area_d.c and country_d.c. To modify these dynamical
data will be and will only be through calling the functions in these
daemons. Well, since these data will become more and more and the
relationship will become extremely complex with the process of the
construction. It becomes quite hard and unreliable to put all the
codes in the three daemons. Now, a new concept will be introduced
into our mud. That is event.
What is event? 
An event is something happened which will cause the system to update
the dynamic data of this mud.
Elements of event
An event has following elements: trigger, condition check, result,
announcement, and code position.
Triggers:
In this mud, there will be 3 different kinds of trigger:
1 triggers issued by wizards
 This is just used when some data will be initialised, corrected, or
tested. Now wizards can send certain command to launch nearly all
events, from the most complex one to the simplest one, that is quite
convenient for the testing, but may sometime cause the system data
in confused situation. In the following development some limitation
will be added to reduce the probability of these errors.
2 triggers by the system
The system will atomically trigger many events, such as the local
area development and the unemployed npc char move from an area to
another.
3 triggers by the players or half by player and half by the system
This is the most complex situation, many events will be trigged by
players certain action. For example, if a player want to establish a
new country. 
Condition Check:
When a trigger has been sent, the system need to check if the
condition is suitable for such an event, or sometime, with the same
trigger, under different situation, different events will happened.
Result:
I think that no explanation needed for this part.
Announcement:
It includes two parts: the target and the method.
When a certain event has happened, the system need use certain
method to inform certain players. 
Code Position:
Currently, all the code for the existed events are put in that three
daemons, as we know, there will be perhaps nearly one half hundred
event designed, so put all these code in that three daemon will be
quite inconvenient, so a new path /sgdomain/event/
Will be used to store all the new code for events, and for most
events (especially for those complex ones) , it is suggested to use
one separate program to handle just one event.
Fire
July 20, 98


---
����: Fire
��Ŀ: list for events
����: Sun Jul 19 23:32:03 1998
List of event
1
Name: adjust_product_level
Trigger: day_d->ai_d
Condition the third day of every month
Result: update the level of product( agriculture, industry, and
business) for every area
Announcement: None
Code Position: country_d and area_d
2
Name: adjust_safe_level();
Trigger: day_d->ai_d
Condition the first day of every month
Result: update the level of safe for every area
Announcement: None
Code Position: country_d and area_d
3
Name: adjust_military_level();
Trigger: day_d->ai_d
Condition the fifth day of every month
Result: update the level of military (moral and train) for every area
Announcement: None
Code Position: country_d and area_d
4
Name: adjust_population();
Trigger: day_d->ai_d
Condition the 9th day of every month
Result: update the pupulation for every area
Announcement: None
Code Position: country_d and area_d
5
Name: area_check and char_check
Trigger: day_d->ai_d
Condition the second day of every month
Result: check the integrity of char and area database
	May trigger the certain events:
Such as auto local leader promotion
And the reduce of safe level for a certain areas
Announcement: None or chat
Code Position: country_d and area_d
Note: this event need further concern
6
Name: LEADER_APPEAR 
Trigger: day_d->ai_d
Condition the 1th hour of every day
That area has no special event such as war or local meeting
That char is an npc or a offline char
That char does not do other business such as war or meeting
Result: The leader of local area will appear in the meeting room 
Of that area
Announcement: to that room in simple_action
Code Position: area_d
7
Name: LEADER_DISAPPEAR 
Trigger: day_d->ai_d
Condition the 3rd hour of every day
That area has no special event such as war or local meeting
That char is an npc or a offline char
That char does not do other business such as war or meeting
Result: The leader of local area will disappear in the meeting room 
Of that area
Announcement: to that room in simple_action
Code Position: area_d
8
Name: save_data
Trigger: day_d->ai_d
Condition every hour
Result: The database will be saved if there has some thing changed
Announcement: None
Code Position: area_d, char_d, country_d
9
Name: LOCAL_INCOME & NATION_INCOME
Trigger: day_d->ai_d
Condition 10th day of every month
Result: the local officer will get pay, the local area will get
harvest gold and product
(If in September also food ) and also calculate the consume of local
food gold and product, is not enough will cause the lose of local
soldier and reduce the loyalty of local officer. 
Announcement: chat to all user and rumor to all user(if not enough goods)
Code Position: area_d, country_d
10
Name: EVENT_NPCCHAR_MOVE
Trigger: ai_d-> event_creater
Condition random based. 
Probability :1 over EVENT_MAX
Result: an unemployed npc char moves to an neighbour  area
Announcement: rumor to all user 
Code Position: area_d


---
����: Fire
��Ŀ: about event
����: Sun Jul 19 23:33:50 1998
the post about event is stored in /sgdomain/text/other/
please go there to check the last updated files
about the events


---
����: Flee
��Ŀ: menus
����: Mon Jul 27 05:41:03 1998
i have code a menu for emote which located at
my home dir with name emotemenu. it wasn't finished
because all the functions of semote.c , addemote.c
and delemote.c are declared as private.
and i can not solve it via soul_d.c for soul_d.c have
a previous_object check.

PLZ check it, if it is OK, i will start code the
following two.


addoil all


---
����: Flee
��Ŀ: emote menu finished
����: Wed Jul 29 10:13:22 1998
i finish emote menu today.
now the menu can list, find, delete and edit emote now.
which is overlaped cmds such as addemote.c, rmemote.c,
semote.c and feelings.

info me if any bug inside.


---
����: Fire
��Ŀ: admire stefan
����: Fri Jul 31 21:58:12 1998
can you tell me where did you find that "?"
beg stefan
thank stefan


---
����: Fire
��Ŀ: about areas
����: Fri Jul 31 22:49:08 1998
now most areas in the northwest part has
its own meeting room and fly room
so it can make the system to do the next development
but some areas don't have map, so
any wiz, if you are developing one area
please finish your map first
today i have find 2 very good maps
one is didao and one is chencang
but i am pretty sorry i don't know who made
them
so if any one finish some work, don't forget
put your name at the bein of that file
and i find ultra has made nearly all the rooms
for didao already, so i select ultra's didao version
then the old didao map will be still reserved 
perhaps for other areas, and the chencang
i find the map, but seem no body has made the rooms
so i just make two empty room there for meeting
and fly purpose
the wiz who finish the map of chencang
please contact me and i expect that you can
finish the whole area
thanks
fire


---
����: Flee
��Ŀ: char menu finished
����: Tue Aug  4 06:35:48 1998
i have finish character managerment menu located
at /wiz/flee/menu/charmenu. u can use /wiz/flee/cmds/char
to check it out.

but i still doubt that when i set my wuli to 100,
my wuli change to 244 in factor. why ?


---
����: Stefan
��Ŀ: wizards management
����: Tue Aug 11 06:02:26 1998
������������ܲ��ð죬����Ϊ�����Ĺ�ϵ��������������֣�
fire ��Ϊ����Ҫ��д code �ɽ���Ҳû�кܶ๤�������ʸ�λ��
ʦ��������ô���ˡ�

�ҿ�����������

1. ÿ����ʦ����ְλ�ߵͣ�����������Σ�ÿ�˶����Լ���Ŀ¼
�½�һ����Ϊ report ���ļ���������¼�����������飬�и����
���У�����̫��ϸ��

2. ��� report �ĵ��һ��� fire ÿ����¼��һ�£�һ������
��һ�´�ҵĽ��ȣ���һ����Ҳ�����ô�����Ҷ���һ�¡�����
һ����ʲôҲ���ɣ�δ��������Ҳ˵����ȥ�� :)

��ʱ��ͬ���գ���ǰ���� Lima ��ʱ�����Ǹ��������ʵģ���
λ������ȥ���������������ô�Ҳ�Ǹ�Ŀ�꣬�����Ѿ�С�гɹ�
�ˣ�����Ҳ��ϣ���ܹ���֯һ��ʵ���͵� team ���濪��������

ʱ�䲻�Ǹ����ɣ�ʱ�����٣���һ�������и������Сʱ��Ϊ����
��һ�������ɣ������Сʱ���԰���д�ü��� help �ĵ��ء�
Ҫ��һ���������СʱҲ�ò�������������� wiz ���Ƕ����������?

���λ���������������������û��ʲô��������Ǿ�ִ���ˡ�
��Ϊһ�� server ���ṩ�ߺ������ mudlib �ṩ�ߣ���һֱ����
����ʦ������ṩ�ܴ�����ɶȣ�������������Ҳ���ǰ취������
�� fire �۵���Ѫ��?? Ҳϣ�����֧�֡����ʵ��������������
���ģ���Ҳ������ʦ����ְ���� :)

-stefan


---
����: Stefan
��Ŀ: �Ҷ���Ŀǰ char ���������
����: Tue Aug 11 07:03:04 1998
������һЩ���˵Ŀ�����˵���˾��� slap �� :)

����ͳһһ�����ƣ���Ҫ�� NPC �������������佫�ȣ������� NPC Char ���档
��һ��ǽ� player��������������˶��Ӷ��� logout ʱ��Ϊ NPC ���������ģ���
�³�֮Ϊ NPC player.

1. Ŀǰ�� char_d �ڹ��� NPC Char �� NPC player ������ data������ͳһ����
��������Ϊ��������һЩ�ײ������ȣ�NPC player ����һ�� data ����Ϊ����
player ���������ģ����� char_d �п��ܻ������ͻ����Ȼ����������£�����
�� load player �� switch ���ߵ�ʱ�����Լ�������� data ��һ�µ����������
����һ�� mud ���� crash, disk failure �ȵȵ����⣬���ͬ�� data �����ݣ�
һ�����˷ѿռ䣬��һ���治���������ȻĿǰ data ������࣬����ʵ�ʵ�
������ѽ���Ϊʲô������������ʱ��������ܷ����������أ��ڶ����ײ��ǹ�
�� NPC char�����һ������Ҫ�����ǵ���һ���������ڿ���֮�ڣ���ô���� char_d
��Ҫ���޸ģ�����ע�⣬����޸ı��迼�ǵ��� char_d save �� data����Ϊ��
char_d �� array ����ͬ�ˣ��� data ����ͨ��һ��ת���Ĺ��̲���Ϊ�� char_d
���á�����û��ʲô����������©���ģ����������ķ�ʽ����������������ײ�
���ǹ��� NPC char�����������������һЩ�������ұ���ͨ�� char_d��������ֱ
���� NPC object �ϸĶ�������Ȼ���Ǹ������⣬�������� NPC player �Ĵ���ȴ
����ͬ����Ȼ����˵ NPC player �� NPC char �ǵ�ͬ�ĸ��Ϊʲô����ķ�
ʽ��ͬ�أ�

�ҵĽ��飺
�� NPC char ��һ���ӽ� NPC player���� NPC char �� object data ֱ�� save
�� /data/players/ ����ȥ���� char_d �Ĺ��ܻ�����ͬ���������� save �Լ���
data�����ǳ䵱һ�� cache ��ʽ�Ļ��壬�Ա���ÿ�� clone һ�� NPC char ȴֻ
Ϊ�����е�һ�����ݡ������� char_d Ҫ����ʱ��char_d ������Ŀǰ�� memory
�����ң�����ҵ��ˣ���ֱ�� query ��Ȼ������ݴ����㣻���û���ҵ�����ô
˵����� NPC char �� NPC player ��û�б� load��char_d ��ȥ����Լ��� data
cache�������������Ҫ����� object �����ݣ��Ͱ��������㣬���û���Ǿ�ȥ
clone һ�����ٰ����ݴ��ء��� char_d ���� query ʱ������Ӧ�� update ����
data cache����� cache ʵ����������Ŀǰ�� array��ֻ�����ǲ��洢��Ӳ����
�ġ��������ϵ������ײ���û���ˡ�����ר�� performance ���ԣ�������ʵ����
���������Ӷ��ٲ���Ҫ�� clone����Ϊ��� cache �� size �ǿɵ��ģ����Էŵ�
�ܴ��Ǻ�Ŀǰ�������û��������� cache ���� 100k����ô������ FIFO
���㷨 clear ���ɵġ���֮�� performance �Ϸǳ���

��������ˣ�������һ�� char_d �������Ӻܶ๦�ܣ���Ŀǰ�޷������ġ�����
�� player logout ʱ�� inventory loss, ������ȫ����������������� inventory
loss Ŀǰ�� player ת�� NPC player ʱ���޷�����ģ���ǳ�û�е�������
�����ڶ��� char �� query �Ͽ������������ query��������Ŀǰ�� array ��
��̫��Ҳ���޷��ﵽ�ġ��������ǿ��Ծܾ������ѡ�����е� NPC char �� NPC
player������ player ���������֣�����ĿǰҲ��������

����Ϊ�ҵĵ�һ�����顣������...

2. ����ΪĿǰ NPC char ����ں�ʹ���ظ� (ʵ�������ڸ��ﶼ�Ҳ�����) ��
�����߼�������û�������κο����ԣ����������еĳ���һ����ֻ����� frustration.
ҹ�о�����˵���ɣ������㲻��������һ�� NPC char �д�����ʱ��·����һ��
��Ǿ���ʧ�����˰�? ����һ�ڵ� clone remove clone remove Ҳ����ʲô���¡�
������û��������ʱֹͣ������ NPC char ��ʧ�͹�����һ��㡣

3. �Ҽ������ inventory ȫ�� save������ʶ�ܶ� English mudder, ����һ��
˵ logout ʱ����Ҫ������������û��Ȥ������ MUD������һ�����������Ե���
�ǣ����μǵķ�����������һ�����⣬����������ǣ�ΪʲôҪ��������
������ʲô unique item �㲻�� player �õ��˾;�Ϊ˽�У��������ǵ� MUD
�� player ��� NPC player ����������Ϸ���Ҫ�ᱦ�������𣬸����߼���Ҳ
����ȤЩ����ȻΪʲôҪ�� dynamic mud? �������˵Ϊ�˲��õȼ��͵� player
�úõ� armor or weapon, ��ô������ armor �� weapon �����ƣ�ֻ��ӵ�ж�
��������ʹ�þͳ��ˡ����˵ ES2 based mud һ�����ϴ�һ��������������
���� ES2 lib д�Ĳ�����Diablo ������ɣ���ô��� armor �� weapon, ��
���ǲ����ܶ��������ϡ�

д�˺ܶ࣬��֪�����û�����Ķ��ꣿ :-) ���������...

stefan


---
����: Stefan
��Ŀ: >�Ҷ���Ŀǰ char ���������
����: Tue Aug 11 07:09:32 1998
����... :)

ES2 lib ֮������ inventory loss ������⣬�������û�а취���� recursive
objects saving���� Lima �������������ܣ���ð� :)


---
����: Fire
��Ŀ: i can't read my mail
����: Tue Jul 14 08:39:20 1998
>>�������ʼ���<<
���������־��
--�һ�ļ�-- [���ڣ�out]
    �һ��Ǹ������ؼҵ��ˣ�Ҫ��������������ɲ����ף��������
ûʲôֵǮ�Ķ��������ǽ�Ϻ�����һ�����֣����Կ�����
һ��ֽ��(zhitiao)
�һ����԰塾����76�����ԡ�
> mail
--- LimaLib Mailer ---
Current headers:
N 70  stefan          (Tue Jul 14) disk failure
[70 of 70] �ż���
*Bad argument 1 to explode()
Expected: string Got: 0.
Trace written to /log/runtime
[errors] (fire) Error logged to /log/runtime
[errors] *Bad argument 1 to explode()
         *Expected: string Got: 0.
[errors] /secure/obj/mailers/standard#9 (secure/obj/mailers/mailer.c
) at line 105

this is what i got
i know that stefan send me an mail
but when i try to read it
it got some error message
i  shutdown and try again
the same thing happened
can stefan have a check. what cause this problem
thanks


---
����: Stefan
��Ŀ: >shaoying's application
����: Sat Jul  4 01:15:57 1998
I agree with fire that we are still in recruiting wizs stage, and 
we need more active working wizs :) 

-stefan


---
����: Fire
��Ŀ: you are right
����: Mon Jun  1 10:03:44 1998
lity's suggestion is right
now i am designing the struct of player and npc
then will be the cities and countries
currently, we can post some ideas about country and
country
when these ideas become mature and the npc
and player's struct nearly determined
we will begin design the cities and countries


---
����: Ljty
��Ŀ: ���ڽṹ
����: Sun May 31 15:15:36 1998
����Ϊ����NPC��player�Ľṹ��, ��Ҫ�г��еĽṹ.
Ҳ���ǳ��е�������.

����player�Ľṹ��������, һ�Ǹ���, ���ǲ���.

�ֽ��npc��inherit monster��, Ҫ������.

just ����.

* addoil


---
����: Stefan
��Ŀ: Task list
����: Sun May 31 08:07:48 1998
help tasklist

�����Ҫ����ģ�������������������һ��ĸ����˻����ˣ���ֱ��
�Ķ� /help/wizard/tasklist �ļ�������������־����ˡ�

(ע������ format, �������� :)

-stefan


---
����: Yue
��Ŀ: about semote
����: Sun Jun  7 23:28:20 1998
i use random to check some semote
i find a semote r big-5 coded
who ever made that, tell me about that semote, thanks
Yue


---
����: Lei
��Ŀ: testjig
����: Mon Jun  8 07:32:55 1998
I propose to promote Testjig as a wizard.
Testjig is a EE final year student. As i know, he will be 
free in coming 6 months. Testjig is also very interested in mud writing.
I believe he is good enough to be one of us. 
PS: Testjig is from the same school with yuner and me and same city with 
Stefan and Benben. It is convenient for our work.



---
����: Fire
��Ŀ: support lei
����: Tue Jun  9 05:37:39 1998
welcome testjig


---
����: Stefan
��Ŀ: testjig promoted to wiz
����: Thu Jun 11 04:03:09 1998
Addoil to testjig!


---
����: Fire
��Ŀ: shaoying's application
����: Wed Jul  1 20:55:58 1998
Hi, every one, i have just received shaoying's
application for joining our development team
I think we need new wizs to join, because
in the soon future we will have a lot of works to do
so, please post here to disscuss his application
thanks

shaoying's applicaiotn
Hi Larry,
Should I write a much former application letter to be a wizard?
I like SG since I was a kid. Shang Hai Tu Shu Chu Ban She has published a
set of picture-book of SG. The pictures attracted me deeply. I played the
most original SG when I was in my sophomore. SG, XYJ are the 2 topics I
like very much.
I also have strong background in C/C++/Java. So, it would not be very
tough for me to get well along with MUD programming, which I desired to
learn long time ago.
And I do think that SG, a strategy MUD has a wonderful prospective since
this is the 1st, as I know, MUD that bravely explores in a newer topic of
MUD. I have read some articles from BBS about strategic MUD, some
proposals etc. So I have some basic idea on that and would love to
contribute my knowledge and time in it.
Thank you for your consideration. 


---
����: Fire
��Ŀ: cdd want to apply wiz's position
����: Mon Jul  6 07:48:06 1998
is there any one support him ?


---
����: Fire
��Ŀ: new application
����: Thu Jul  9 07:30:35 1998
Hi,���������ʽ���뵱�༭����Ϊ��������Ʊ�ҵ��ÿ����������3Сʱ����֪��Ҫ
��ʲô������������������idΪzc)
                    ���˹�����
how about this guy,
anyone has any ideas ?


---
����: Fire
��Ŀ: shaoyng and benben are added into Mudlib domain group
����: Thu Jul  9 09:32:49 1998
because they need write some code for new areas
they have been granted the priviliate


---
����: Fire
��Ŀ: suggestion about the name of file
����: Sun Jul 12 02:22:50 1998
in order to make the contral easier.
when wizs design new obj( a room, npc, or obj)
please don't make the length of the file name
no more than 10 letters
thanks


---
����: Stefan
��Ŀ: ������
����: Tue Jul 14 23:01:04 1998
I put a copy of cracked ������ in /ftp/pub, check it out!!!
It is a zipped file of 1.9M, should be easy to download by Modem...

It is a real time game, unlike most ���� games, and I think the
ս����ʽ is a very good example for our mud.

For PC only, not for Mac :)

-stefan


---
����: Ultra
��Ŀ: sorry to all
����: Thu Jul 16 09:13:12 1998
���������ϸ�Ŀ�������post��֪�����Ѿ�����ʦ�ˡ�
thank
�����ұȽ��Ƴ��ľ���client server�Ķ���
������ʲô��Ҫ����mail me 
wink
addoil


---
����: Fire
��Ŀ: thank you all
����: Sat May 30 18:59:20 1998
thank you all for you trust and support
Before I came here, I knew nothing about mud programming
Now, I have learned sth at here, but to the whole system
I only know a little. without all wizards help and support
I can do nothing.
hope we can work together happily and open this mud at
a sooner future.
thanks all
bow

fire


---
����: Stefan
��Ŀ: >need more priviliage
����: Sat May 30 09:32:13 1998
Fire is promoted to Admin. Let's all wish he'll do well enough
to keep Admin.

Fire: be careful not to get anything screwed :)

-stefan


---
����: Fire
��Ŀ: need more priviliage
����: Fri May 29 19:26:42 1998
Now i begin to develop the mudlib,
and find that i meet many inconvenience because
many paths such as /trans, /includes, and /data that
i have no right to write.
I apply the position of admin. 
I will use this power to contribute this mud
I have done sth for this mud
but unfortunatly that I haven't finished it
I will continune work here until the day that
the Chinese MUD ���� opened offically for players
please consider my application and please consider
the current situation of this mud.
thanks


---
����: Fire
��Ŀ: simplity the system
����: Fri May 29 08:58:23 1998
according to sg's requirement
many thing in player's files are useless
nearly all in race.c and human.c are deleted
and some in body.c also been delete
please notice is there anything wrong
thank


---
����: Fire
��Ŀ: plan of work of next step
����: Tue May 26 04:27:22 1998
Plan for next work:
draft of plan for the work of next step.
1. rewrite the struct of the players and npc.
delete those unused para and give a full docu
of these paras
2. modify the cmd system
reduce the number of cmds and simplity the useage
of cmds and give standard of cmds
3. help system.
include help for player and help for wizards
4. the struct of cities and country
and the struct of centra_contral system and AI  system

details:
1. we will have three kinds or level of npcs
1.1 simple npc
this kind of npc is used as store keepers, servant girl
kids. . .
it can't fight, perhaps can answer question and decorate
cities. (fight means fight in the war )
1.2 fight npc
the difference from this npc to the simple npc is that
this kind of npc can fight, so it has much more gifts
but it will not be controled by the centre contral 
system. some brigand and officer belong to this kind
1.3 full document npc
this kind of npc has nearly as much paras as players
and they will be controled by the centre control
system.
all the famous general and officer will belong to
this kind
1.4 players. some ppl will become npc in certain situation
this will be discuss later.
1.5 relation of npcs and players
player inherit full document npc inherit fight npc 
inherit simple npc.
2 cmds
2.1 all cmds will have help and examples
use <cmd> ? will display the help and example
2.2 simplity and reduce the number of cmds
2.3 add several menu based cmd used for
check information and give complex cmds such as
rearange the army and genernals
2.4 add one universial cmd "use"
which can be used for many objects
3 help system
3.1 the first part is help for wizs
this help should include detailed plan and desc for
all different systems. and when some new parts
are modified, will use sth similar autodocu to
update the help documents
3.2 cmd and menus based help system for player
this will make play to find and read help
quickly and easily
4. centre control
4.1 struct of country and cities
this is the core of this game. all ppl and npc should work
for one city or country except a little �޹�����
the system will update the data of all country and cities
regularly. based on some suiteable formula.
the development of a city will depend on the ability
of the leader of the country and the city and other officers
in this city. the king and mayor can adjust some police
of the city, but most of these will be done automatically.
so.
4.2 AI and central control
for NPC country and cities. this game will give a reasonalbe
AI to make them deal with some situation
any wizs interested in any part of this plan, please post your
ideas.
I will begin this work within next week .


---
����: Stefan
��Ŀ: WIZ Shell
����: Mon May 25 02:25:36 1998
Pickle, Yuner, Yue have been granted to use Wiz shell. If anyof you 
has any trouble logging in, let me know.

-stefan


---
����: Yuner
��Ŀ: �ҵ�һ�㽨��
����: Wed May 13 07:26:17 1998
���˴�ҵ�ʱ���ʵ���Ǻ��Ѵյ�һ��������Ҳ���£�Ҫ��IHPT��
�����������ܵ���Ȼ�ܺã�Ҫ�ǲ��ܵ�ȫ�����������˰����д��
post�У�Ȼ������ʱ������ʱ������ʱ�����������֪�����ܷ��ֲ�
��Ҳ��ܵ�ȫ��ȱ����


---
����: Pickle
��Ŀ: response to fire
����: Wed May 13 02:22:04 1998
�һ��������Ҳ��⣬���뵱��ʦȻ��û��Ӧ����˭���ܲ��ˡ�
��ǰ�Ĺ�ȥ�͹�ȥ�ˣ�����ν�����Ժ��Ҿ��ô����û�������
һ���ӣ������һ���˵�ġ�if i am under this situation again,
i am sure i will do what i have done exactly.�� �ҾͲ�̫
����ˡ�����˼��˵����б����ʦ���룬�㻹�ǻ�����ô��

�Ҳ�����������ģ����Ҿ���������ʦ�Ƿǳ���Ҫ�ģ���ϣ����
�ǲ�Ҫ̫������һ�㡣һ������ʦ��û�б�̼���������Ҫ����
��but on the other hand, will also not harm to this mud��
�ǲ��Եģ����������ʦ�ڲ���ϵ���ã��������һ�������д
�Ķ���Ҳ�ǻ���ì�ܣ������д�˸������޵еĶ��ƣ�Ȼ������
һ�ѹ�棬������Ҷ�ϲ��������ˣ�Ȼ������Ҳ�����д�˸�
ì��һ�¾��ܴ���������ơ���ô����Ϸ������ì���ˡ�ֻ�Ǽ�
���ٸ����ӣ��������µĻ��������С�£�����Ҳ��ϸ˵�ˡ���
�����һ����ʦ��ʱ����ڶ����϶����ɻ������û���κε�
���壬�����������ˣ����ǿ�������Ȼ�������������ʦ��԰��
�������ǻ�û�����͡��������һ�㡣�µ���ʦ����ʱû�����
���ѹ������������µ���ʦ˿����֪����Ϸ�Ĺ��죬һ�㲻��
lpc ���ԣ�����д��������������д��һЩ������������Ķ�����
��ʱ����������Գ�������һ������������ĵġ���֪������Ϊ
���и��˾��顣

���ˣ��ҷϻ�Ҳ˵�ù����ˡ���������Сʱ���֣�ֻ��ϣ����
�����㹻��ʶ����ʦ�����Ž����Ҫ�ԡ�ǧ��Ҫ��������ո�
�˾���û�ô�Ҳ�����л���������һ��diverse �������û��
����ž��ǻ����ˡ�

pickle



---
����: Fire
��Ŀ: re pickle
����: Wed May 13 21:49:06 1998
��������ҵ�post���������ڴ��Ĳ�̫һ��
û��ϵ����������Ƕദһ��ʱ��ͻ�����˽�
�һ�������������ͬʱ������Ҫ�����飬��
��������������
xixi


---
����: Fire
��Ŀ: the first wiz meeting
����: Thu May 14 01:10:28 1998
the first wiz meeting
just pickle, yuner and i were here
and nothing can be decided
sigh


---
����: Fire
��Ŀ: agree stefan
����: Thu May 14 06:30:19 1998
we need work together to build the base part
then others can be consider later


---
����: Stefan
��Ŀ: Site shiftment
����: Fri May 22 04:52:15 1998
���ｫ����������ʱ�� site������̫����������������˵������ :)

���Ѿ������� Wiz Shell �� port �� 3001. Ҫ��������ʦ֪ͨ��һ����
�һ����һ���ʻ����������붼��������ͬ��

������ Wiz Shell �� security ���ܺ� Lima ���ݣ������κ���ʦֻ�� edit ���Լ�
Ŀ¼�µĶ��������� /open �� /tmp. ���������һ���Ĳ��㣬��Ϊ��
��Ҫ�Ȱ�Ҫ�Ķ����ļ� copy  �����Լ�Ŀ¼�£��Ĺ�֮���� copy ��ȥ��
Ȼ����� update .

�ұ���ϲ���� ed ������ vi :) �����Ҳ���ʹ�� Wiz Shell�������
ʲô���� mail ���Ҿͺ��ˡ�

-stefan


---
����: Stefan
��Ŀ: >plan of work of next step
����: Fri May 29 03:16:50 1998
���� fire �ļƻ�����������ͬ�⣬��Ҳ��һЩ��������Ŀ�б���
��Ӧ�ÿ�ʼ��ÿ���˷ָ�����˭��ʲô����Ҷ���������ҳ�������
���������� :)


�ҵ�����һЩҲ����Ҫ���ģ�

1. Newsgroup rebuild. ���ڵ� newsgroup ��ȡ�ķ����������ĵ���
����һ���ļ��������̫�ã������ǵ��ĵ�Խ��Խ��ʱ�����ù���
�ҵ��뷨�ǣ�ÿһ���ĵ�һ���ļ�����һ�� news id �����ļ�������
��Ҫ�ṩһ�����е� newsgroup ���·����� migration.

2. ϵͳ�����ͳһ������ domain, group, channel �ȵ��ƺ����ڲ�ͬ
�������뷨��Ϊ�˱�����ɻ��ң��б�Ҫͳһһ�¡�

3. Ansi color clean-up. ��ֱֹ��ʹ�� color code��һ�ɸ�Ϊ user
configurable ����ɫ������

4. Verb parsing. Ҫ�� much much smarter �ķ������������磺
wield sword �����ǿ��Լ����ϵ� sword������ pick up sword ��Ȼ��
�ȿ����ϵ� sword. ������Ҫ���� my sword, my 1st sword ֮��Ķ���
���޶� sword �ķ�Χ��

5. һЩС����Ĵ������� inactive ��������ڣ�ȴû���κεط��õ�
��� flag. ���� verbose �����⣬��ʹ�� verbose �ص���more �� 100% ��
ʱ�������ǻ�ͣס������ enter, ���� ls ʱ��Ϊ���㡣

���кܶ�Ҫ���ģ�һʱҲ������ȫ����λ��ʦ����Ҳ�г�һЩҪ�Ľ���
�ط���Ȼ�����Ǵ�����ֹ������� fire �� plan, �����й�����æ
һ�����...

-stefan



---
����: Fire
��Ŀ: my work
����: Fri May 29 05:07:57 1998
from now i will begin to arrange the paras of players and npcs
and i will give a detailed list of all the paras
, functions and the relations among them
about stefan's plan, i support hime
I think perhaps stefan is the best person
to do these work
addoil stefan


---
����: Pickle
��Ŀ: Ҳ��˵����
����: Tue May 12 03:04:46 1998
��Ȼ�һ����������ص��£���Ҳ�������졣

�ǵ��ʼʱ���Ǵ��һ�𶨵Ĺ���Ҫ����������ʦǰ
Ҫ����������Ĵ����ͬ�⣬���������������򲻻��ա�
Ҳ�����ҼǴ��ˣ������ƺ��һ���������ֹһ�ε�����
������������ʦ�����ҽ����ͬ�⿪������ʦ������Σ�
�⣮����

���о���д������Ҳ֪����Ҷ�æ����ϣ���Ժ���д
�Ƚ���Ҫ�ĳ���ʱ����������һ�¡��������ڵĹ���ϵͳ
�ҾͲ��ر���ͬ��������

in any case, i don't intend to sound very hostile,
if i do, that's because my chinese is very poor. :(
i just want to discuss opinions, and hope that in
the future we all respect each other. :) i know
that i haven't been around all that much and i probably
have no business ָ�ֻ��� about others' hard work. :(
i had a very rough semester, please forgive my lack
of attendance. i will return to china for several
weeks after the end of my term, dunno whether i can
come to the mud when i'm in china. i hope i can. if
not, then y'all will hear a bunch from me in the next
week and then hear nothing until the end of july le.:(

pickle



---
����: Ljty
��Ŀ: new site is very fast
����: Mon May 11 04:27:27 1998
This site to me is also ok, not lag, but new site is 
really fast to me. I like it.

��һ�ζ��е�æ, û������. sigh, ʱ������������.
sorry, addoil all.


---
����: Yue
��Ŀ: another question
����: Sat May  9 11:01:51 1998
 list
��������������Ʒ�� 

--------------------------------------------------------
          ��������             ��Ǯ
      ��Ƥ�ƴ�(skin)          һ�����ӡ�
һ������ȹ(skirt)          ʮ�����ӡ�
���������(zhu)          �������ӡ�
��ͷ����ѥ(xue)          �������ӡ�
������ۼ����������(yuyi)          ��ʮ�����ӡ�
          ����(buyi)          �������ӡ�
--------------------------------------------------------
��������Ҫ��ʲô
why those message r so messy?


---
����: Stefan
��Ŀ: My apology to Fire and Ljty
����: Sat May  9 22:43:08 1998
First of all, I have to apologise to you two that I did not inform
you before I repositioned all the wizards. I spoke to lei, yuner, pickle
about the change before I did it, and I did not see objections

Secondly, a little explanation of what I did...

As the person who setup this lima, I warned Lei before he organized
a team to build a mud upon lima that, please do not do any
naughty things that will break the base mudlib. Then I gave him the
right to build a mud here and I did not interfere anything you guys
after that, until one day I checked the ftp log and found Pier ftped
back all source codes. I was wondering why this could happen if everything
is on the track, so I checked security system and found all security
protections were broken.

I realised that nobody really understood the security in lima yet,
and there were too many admins around, one su to another reading emails,
and other naughty things ( I wont mention here cause I am not sure
whether what I was told is true or not ). I would not care what you
guys do among yourself, but I was very angry that the whole source
codes were stolen and yet nobody was aware of that. So I decided to
fix the security hole. I posted these things before I did the fix.

After the fix, I thought about giving back Admin to those who owned
it, but then I dismissed the idea because I do not want to see anyone
who do know how the security system works to be the admin here, it
will surely harm the mudlib. So I decided to hold back the Admin position.

I hope I am understood here, the whole intention is to protect this
mud, as I said again and again, I will not participate in your ����
domain building and will not disturb you guys in any manner. But I will
make sure the mud is not messed up.

In fact, after the change, does anyone really feel very inconvenient
when coding things? The parts protected by Admin privilege are not
supposed to be touched under normal circumstances. The only thing really
different is that you need to get my approval to change those "core" codes
of the mudlib and you are not allowed to fumble with security any more.

I am not concerned of any surreal power or position illusions, like
the 'arch' position before. It did nothing but made a nice description
in finger. Do read the security documentions if you really want
to know how security system works here.

Actually, I like fire's post, he asked me to apologise openly. Everyone
please speak up if you have something to say.

-stefan


---
����: Stefan
��Ŀ: new site
����: Sun May 10 02:57:46 1998
A new site is up at sing.wistar.upenn.edu 5000.

Keep it as a secret :) I do not want Upenn people to find out.

But a trouble is, I can not set up intermud communication between
these two muds. We need a Imud3 router to do so, but I asked in the 
Lima Bean site, they are not going to reveal the source code of it.

So, it is hard for us to keep consistent between two muds, especially
news and mail. I am thinking of shutting down current one and only 
focus at the other one. 

What do you guys think? How is the speed over there? Please do not 
post things there or changes codes there, I might transfer all the things
here to there again.

-stefan


---
����: Pickle
��Ŀ: other site
����: Sun May 10 17:24:18 1998
the other site is incredibly fast for me, especially when compared
to this site. :( i hope we switch... *addoil stefan


---
����: Yue
��Ŀ: new site
����: Sun May 10 18:13:26 1998
then newsite is so so fast
fell like localhost, snicker
* addoil


---
����: Yue
��Ŀ: here's ftp only can upload 400 k max
����: Sun May 10 21:22:18 1998
as title


---
����: Stefan
��Ŀ: >here's ftp only can upload 400 k max
����: Sun May 10 22:48:43 1998
Yeah, I noticed already. I'll fix it up ASAP.


---
����: Ljty
��Ŀ: to pickle
����: Tue May 12 04:49:45 1998
pickleҲ���fire������wiz. Ҳ���������ѪҺ��. ˵ʵ
�������������Ĳ�̫��. ������wizҲ������µ�ת��. fire
����wiz�����Ǻ����, �ڳ���ǰ��//modified by stefan
��, �󲿷ֶ���//by fire . ͬ����. �������Ȩ��, ������
������Ȩ�޴�С, ���������Ĺ���. ��������û����������
���. ���Ͷ��, ������ǻ������, ƾ������ɲ��ƶ�
��˵��, Ч��̫��, �Ͼ���Ҷ�����Ը��, ˭Ҳ���ù���.
����ʱ�䶼�ܽ�, ���������滨ʱ��������, �����������
�𾴵�. ��Ȼ�Ҳ�����wiz�����۸���. ���Ҳ�ϣ��ʲô������,
Ч��̫��, ����ƽʱ�ѵ�һ��. Ҫ����̫��, ��Ĳ����޸�
������.

ϣ��stefan�ڹ����������µ㹦��.



---
����: Pickle
��Ŀ: re ljty
����: Tue May 12 05:51:28 1998
hmm.. �Ҳ��Ƿ���ɧ�����Ҳ��ں��һ��Ƿ��Ǹ����Щ������Ҫ��
��������Ϊ������ʦ�Ǽ��ǳ���Ҫ�����顣�����ʦ֮���ϵ����
�ǽ��� mud�������󲻱㡣Ҳ������paranoid�������������μǵ�
����ʹ��ʮ���¾�����

���Ǵ���Ϸ�Ƕ��������Ӹ��˷��������Ҿ��ø�ֵ������һЩ����
��������һ��ɾ�Ҫ�������أ����ܾ��á��ţ���Ϊ���յ���ʦ
�����Լ��ܣ��Ͳ��ø����˴��к��ˡ���Ҳ������Ϸ�����ǶԵģ�
������һ�ֶԱ��˵Ĳ����ء��������ñ��˵������̫��Ҫ����
�Ͱ�������������ʦ����ƽ�񡣲�Ҫ��Ӧ�˺�������Ȼ����֮����

�й�������Ϸ��Ƶ����飬��ͬ�⣺���������������ۡ�����ֻ��
ָ��Щ��Ҫ�����飬����˵ս��ϵͳ�����ָ�����������Ҳ�ͬ
�⣬��ô������д�¶���ʱ�Ჽ����������֮��������ۺ��ˣ���
���ܿ��ǵ��Ķ��������ǹ��ˣ���ô�����°빤����

�֣�����Щ���������и��룬��������һ��������ɧ������ᡣ

pickle



---
����: Ljty
��Ŀ: ͬ��pickle
����: Tue May 12 10:07:02 1998
����������Ҫ��ǿһ�¹���, pickle��˵��Ҳ�е���.
���ǵ�meeting����Ҫ.

sorry, addoil.


---
����: Fire
��Ŀ: bigman stefan
����: Tue May 12 20:33:02 1998
after i made my last post, i feel a litter upset
perhaps i am too rude to ask stefan to apologize openly
but to my surprise, he realy did that
so bigman stefan
no matter what one does probably will cause some ppl
unhappy, it's quite nature and can't avoided
but if we can discuss openly and can admit it oneself's
mistake then everything is ok
I like stefan's style, and i will work here.
sw
becuase he is a honest person and be worth of trust
to pickle's complain, i feel very sorry for that
I know some times i disobey what we have agreed before
especially to recruit new wizs.
before i come here, i apply to be wizs in other muds
but receive no respond, i am very sad with that experience
so when other ppl ask, i really know his feeling and
I just didn't want to hurt him. I know, in most case
new wizs without suitable programming background and
enough time will contribute few to our mud
but on the other hand, will also not harm to this mud
so, it's really hard for me to refuse his application
of course, i should discuss this with other admines.
but during sometime, it's quite hard to find other admines
to discuss. so. . .
I know this is my mistake, if there is a penalty system here
i would be glad to undertake that, but anyway, if i
am under this situation again, i am sure i will do
what i have done exactly.
sorry pickle
perhaps i am not a suitable person to do administation work
so, as stefan modify this system, this will never happen
snickle


---
����: Fire
��Ŀ: new lima is super fast
����: Tue May 12 21:00:05 1998
admire stefan
xixi


---
����: Yuner
��Ŀ: hoho
����: Sat May  9 03:20:19 1998
How about do the webpage after the basic frame is done?


---
����: Lei
��Ŀ: hmm...
����: Sat May  9 01:24:32 1998

For something really bad, I won't go back to China this June:(
So I will have enought time to work here. 2 things I want to do:
1. The detailed plan mentioned by fire
2. A webpage of this mud
I think the plan should be quite important and everybody has own ideas
about that. Pls post our your ideas completely if you are interested, 

About the webpage... You may think it is to early to do that now. Anyway
I am very interested in writing webpage now:) Also if you have any ideas 
about webpages, just feel free to speak out pleas.



---
����: Fire
��Ŀ: Re: Yue about bug
����: Fri May  8 23:59:52 1998
I check the code and find 3 problems.
1 in /std/modules/m_wearable.c
  when one remove the cloth
  the ppl will release the slot
  but for none cloth not within living object
  this will cause error
  i have add some code to fix that
2 the jia.c in /wiz/yue/obj/ is not
  an object for this mud
  much code are not compitable with mudlib
  here. so i remove it out off the list
  of add_object in ly_zahp.c
3 the third problem is about the code style
  now i hope all code to be wich the same style
  so we have special path for all objects
  it's better to put your object in the suitable
  path and if you refer this object
  use macro defined in /include/path.h to
  replace the absolute path such as /wiz/yue/obj.
  the detail paths macro, please refer 
  /include/path.h
thank you yue
bow
kiss yue


---
����: Stefan
��Ŀ: HTTP server
����: Thu May  7 22:14:57 1998
check out our Web server.

http://guanine.krdl.org.sg:5080/

Lei, you can set up our Web page now :)


---
����: Pickle
��Ŀ: lag
����: Thu May  7 02:13:04 1998
my connection to this site is extremely lag, if we can open
another place, that would be great...


---
����: Stefan
��Ŀ: Wizard Panel
����: Wed May  6 23:04:31 1998
Now, lei, yuner, fire, ljty, tset, pickle, yue are members of Mudlib domain.

Lei becomes domain lord, with the title �ܱ�.
All others become ����.

I think we should open discussion to all, so that we can sort out
things before it gets screwed. That is what this newsgroup wiz.com is for.

Notice that, newsgroups with the name wiz.* will only be readable by
wizards. Players can not read them by using "news". Although we have some
"wizard only" messages in other newsgroups, I think for the time being,
just let it be, since we are still under development. But, if you 
have something that is only supposed to be read by wizards, please 
post it here.

-stefan


---
����: Stefan
��Ŀ: security stuffs
����: Mon May  4 01:20:13 1998
Because I've not tested all, if you encounter any problem with
the security system, just drop me a mail. 

Welcome any doubts regarding the security things, you can 
send me mail or post your question, I will try to clear your doubts.

-stefan


---
����: Yue
��Ŀ: i have same problem b4
����: Sat May  2 16:01:54 1998
as title.


---
����: Fire
��Ŀ: about mail
����: Fri May  1 22:06:52 1998
today i check my mudmail here
I find a mail that even i didn't read it 
but also marked readed 
so must some one login  as fire or su fire to do
so
even this system can't support definate secure for
private
but, i think we'd better do it by ourselves
thanks guys


---
����: Fire
��Ŀ: now wizard can't shutdown
����: Mon May  4 18:46:54 1998
as title
sigh
slogan


---
����: Stefan
��Ŀ: yue became member of Mudlib domain
����: Tue May  5 03:43:19 1998
Now Mudlib domain has the following members:

yuner, fire, lei, pickle, tset, ljty, yue

Anybody wants to take the domain lord position? -:)


---
����: Yue
��Ŀ: too lag
����: Tue May  5 21:26:32 1998
here is too lag for working, b4 i fell good, what happened?


---
����: Fire
��Ŀ: sorry from fire
����: Fri May  8 02:58:45 1998
I am sorry for do nothing for this mud for several weeks.
I am really a little busy these days about my study,
but i will continue to do my best here
Now, several wizs are quite familiar with this mudlib
so i think it's not quite difficult to write
code for certain matters. Now the most ergent thing
we need is a detailed plan
I have promised to give a draft
and i will continue to do it.
ljty will give a plan for war.
These days, Stefan has changed something for the system.
as he suggested, we need discuss openly.
So i have sth to say.
I know he has enough reasons and right to do
what he has done.
but i can't say that i dn't feel even a littler unhappy for that.
now, except himself, all other arches has beed depromoted 
to wiz.
perhaps this will contribute to the safety of this mud
and also I hope it can contribute to the building of this mud
but, I think before he changed that, he should have
enough time to discuss with us or at least inform us. 
I dn't know others, but at least i didn't hear anything
from that.
I think that we are all members in a whole group
the uniform aims for all of us is just to make a
wonderful mud. And we are equal in someway.
I think it's quite rude to do such a big thing without discussing
with other members in this group.
I am sorry to say that.
but I hope to hear of his open appologize 
To do like a man to do !
fire


---
����: Yue
��Ŀ: about npc's hp
����: Fri May  8 19:23:03 1998
in the code i typed in
        int hp = random(150);
        hp += 200;
        set_cur_hp(hp);
        set_cur_max_hp(hp);
        set_max_hp(hp);
buy when i clone it out
hp first bing
���ܴ����������䡣
��Ѫ��   0 /   0 (   0 )  ʿ����    0 /    0
���֣�( ---- ) ʿ����  0  ս������0 
���ʣ�    �����ƽ�        ���ݣ�    ��ʯ

something wrong in set_hp()...


---
����: Yue
��Ŀ: bug!
����: Fri May  8 21:25:57 1998
update here
(i''m in /sgdomain/area/cities/luoyang/ly_zahp)
*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/catch
v
[errors] (yue) Error logged to /log/catch
[errors] (yue) Error logged to /log/catch
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /wiz/yue/obj/buyi#261 (std/modules/m_wearable.c) at line 57

*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/catch
[errors] (yue) Error logged to /log/catch
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /wiz/yue/obj/yuyi#262 (std/modules/m_wearable.c) at line 57

*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/catch
[errors] (yue) Error logged to /log/catch
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /wiz/yue/obj/xue#263 (std/modules/m_wearable.c) at line 57

*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/catch
[errors] (yue) Error logged to /log/catch
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /wiz/yue/obj/zhu#264 (std/modules/m_wearable.c) at line 57

## ------- wiz/yue/obj/jia.c:4
## Cannot #include command.h
## #include <command.h>
## ------- wiz/yue/obj/jia.c:6
## parse error
## inherit CLOTH;
##              ^
what happened to that room?
i checked everything but still cant find out what's wrong


---
����: Yuner
��Ŀ: Announcement
����: Wed Apr 29 08:42:10 1998
 I am sorry that seems the mail system here has no security. Everyone can use
su to do the user-change. So if you want to talk very private
things, i suggest
u to use other mail systems.
#bell
#bell
  �ٹ�Щ���ӣ��ҾͿ����ˣ�Ҳ����Ͷ�빤����.:) *jump


---
����: Stefan
��Ŀ: security system broken
����: Mon Apr 20 03:47:57 1998
When did this happen? It is too bad that I just noticed it.
I'll fix it up ASAP. 

I urge you guys to be considerate, do not do bad things intentionally.

And also, pier, please send me an email explaining
that why you ftped all the source code back?

I have to say, you can extract all the info from the source code
but you can not set up another lima with it.



---
����: Ljty
��Ŀ: ���ڹ��س�
����: Fri Apr 10 07:44:05 1998
���������飬����ϵͳ�����������ݵǳ�¥��ս.
���ط�����ʯ, ���������ʯskill. ��ʯͷ.

���⻹�����Ӿ�ص���ս���ط����ڳ���Ӧ��.���
�����л��Ǻ������ص�.��ص��ǱȽ�Σ�յ�.

����ָ����ϵͳ���ŵ���ɺ�, �һ���post ����.

������ʲô���س�idea.��mail ljty�����post
����, ������ȡ�Ѻõ�idea code ����. thanks.



---
����: Ljty
��Ŀ: ����:����ս��
����: Wed Apr  8 04:13:51 1998
   ���뻹Ҫ�貿�ӵ��ƶ������������. ��ͬ����
A/D��һ��, �ƶ�����Ҳ��һ��. ���൱�ڸ��˵ľ���.
�������ʵ�ʸ�·���ʹʿ������. ����������.A/D
and �ƶ���, �ɳ�������󷨲���. ���Ҹ�����Ҳ��
һ��, ������벽�����ľͲ�Ӧһ��. ���������Ҫ
����, ���������򹭼�.�ȵ�.



---
����: Ljty
��Ŀ: ս��
����: Tue Apr  7 16:03:22 1998
����һ�����ս�����뷨. ������Ҫ��npc. ����
��ϣ����һЩս���ϵ���.

����ΪҪ�����б���������������ѵ���ȣ�ʿ��
�������������ʦ����.

���������ɹ�ְ��, ���ڱ������������Ҫ������
, ļ��. ���������᳣��, �����, ������������
��, ��ļ��Ҫgold. �����ı�����recover. ֻ����
���ַ�ʽ, ��ѵ���ȿ�ѵ�����, ������, ��ʦ����
�й�, �ߵĻ���ѵ���Ŀ�, ��ʿ����ʱ��recover, ��
�����ھ��������ݳ���������. �;��ɼ�ǿʿ��.

ѵ���ȸ�, ʿ���߻����������ʦ����Ӱ�����, ��
ǰ�ɵ���, �Է���Ӧ, ����ɱ���Է�, ��ʤս��, ��
��ܶԷ�, �Է�ʿ����. ��Է���Ը������Է�ʿ����.
����������. ��һ��ʿ��������, �Ͱ�, ����������
׽.���˾��ɶԷ�������.

�������öԷ�, �Է��ı�����֮һ�ɹ�˳��, ��Ҫ��ѵ
������ʿ�����Խ�. ������֮һ�ع�. ��������֮һ��
�߲���.
�����ҿ����������warfight, zhenbing,(����),
mubingļ��.�⼸��file.������ͬ��Ļ�.

�����������, npcҲ�ñ���.


---
����: Fire
��Ŀ: welcome new wiz
����: Tue Apr  7 05:01:42 1998
with the agreement of lei
now, we have a new wiz, xuan
he is an admin of xkx in peking university
his join will greatly improve our wiz team force
chat* welcome xuan
chat* addoil xuan


---
����: Fire
��Ŀ: good job, ljty
����: Tue Apr  7 04:54:40 1998
horse is another lift of fighter
ljty has done such a good job within so short time
thank ljty
addoil ljty


---
����: Yue
��Ŀ: about es2's mudlib
����: Sun Apr  5 00:51:06 1998
i upload my es2 mudlib to w web site
is in http://www.freeyellow.com/members3/mudsoftware/es2.tgz
use winzip to open it


---
����: Row
��Ŀ: weapon produced
����: Sat Mar 28 02:01:25 1998
based on the weapon database, i produced several weapons.
pls check the files at /wiz/row/obj/weapon .

�����ϴ��ţ�
  һ�����ǵ�(qixing dao)
  һ��������ì(tiejishe mao)
  һ���������е�(sanjianliangren dao)
  һ���������µ�(qinglongyanyue dao)
  һ������(blade)
  һ���ֵ�(gang dao)
  һ���󿳵�(dakan dao)
  һ������޼�Ƕ�(tiejili guduo)
  һ�˻�ͷ����ǹ(hutougoulian qiang)
  һ����(da fu)
  һ���ɰ���ì(zhangbashe mao)
  һ��˫���(shuangtie ji)
  һ�������(liuxing chui)
  һ�˷��컭�(fangtianhua ji)
  һ�˳�ǹ(chang qiang)
  һ��������(xuanhua fu)
  һ������ǹ(liangyin qiang)
  һ�˳��(chang ji)

haha.
                           row


---
����: Fire
��Ŀ: thank row
����: Wed Mar 25 07:44:31 1998
thank row for your very good work
could you please make weapons with your desc
you can consult files under /sgdomain/obj/weapon
perhaps you need write some fight information for 
some kind of weapon such as ��
this should check the file of /daemons/messages_d.c
thanks
bow row


---
����: Fire
��Ŀ: about race
����: Wed Mar 25 07:26:22 1998
the old lima has many races, but infact most
of them are useless for current sg
now in the sg, for NPC there are mainly two types
one is inherit from LIVING and
the other is inherit from MONSTER
in fact MONSTER is inherited from LIVING
so all the features that livings have will be
included in MONSTER
the main different from monster and living is
that the monster can fight but
the living can't
so you can kill �ϻ�ţ and ���� because
they are inherited from monster but 
you can't kill ��ͯ and ��С�� because they 
inherit living
In this Mud, currently the animal would not
be considered (except horse) since no much
animals in the book of ����
about the �ϻ�ţ��it's just a test object
don't take it seriously, from every aspect
it is a common NPC.
most of the hp and other setup functions
are in the file /sgdomain/modules/m_sggift.c
you can use this function to initiate the feature
of a npc 
for example add set_sg_max_hp(100); in your npc file
will make the npc has the max_hp 100
but since there are many many data need to be 
initiated for a NPC, so we will develop
the classify function to seperate
the NPC into several groups
then just use several fun can performe all 
the initiation for a certain NPC
but this work will be done later.
I am sorry that i didn't give detailed
help file for mudlib functions that i have
introdued. I think some sample obj files can
solve this kind of problem better.
after the fight system, i will give a set
of samples to demonstrate the useage of most
mudlib function that need to be frequently used
thanks

fire


---
����: Row
��Ŀ: about npc's hp
����: Mon Mar 23 05:17:44 1998
i think human NPC's hp should like players, but it is
unreasonable that a animal like an ox will has the hp like
humam being. so...just like other mud, make a animal race, gather
all animals into one category. that will be more clear to identify.

                                          row
,


---
����: Row
��Ŀ: about fight msg
����: Thu Apr  2 08:30:36 1998
����Ϊ�������е�fight msg ���Բ���ES2 ϵͳ���趨
���������������£�

Ӱ�������տеþ���ļ��ȹ�ͷ����¶�׹⣬�͵ض�׼���е��ұۻ��˹�ȥ��
(this line is hit msg)                                ^^^^
��������΢��*����*��
(this line is result msg)
( �������˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ� )
(this line is status msg)
����ע����Ӱ���ߵ��ж�����ͼѰ�һ�����֡�
(this line is wait msg)
������Ӱ���ߵ����ֺݺݵ�����һ�ţ�
(this line is hit msg)
���Ǳ�Ӱ���߸��ˡ�
(this line is parry msg)
Ӱ���߼����й���ʧ�󣬳û�����������

���Է���ES2 �ֳ���ͬ�Ĺ�����λ���������С�^^^^��
�Ǻ���ָ�ģ�ÿ�ι����������ָ��һ����λ������*
 ***����ָ���ľ����˺������ˡ���ͬ��������ɵ���
��Ҳ�ǲ�ͬ�ġ��罣������ɴ��ˣ���������ɿ�
�ˣ�������������˵ȵȡ����һ���������������
fight msg Ҳ��ȽϷḻ������̫�ᷭ����ȥ��ǧƪһ
���ˡ������Ҿ��ÿ��Բ���ES2 ���书(skills)ϵͳ��
������Σ������е��佫������Ҫ�书֧�ֵģ��ɲ���
�κ�������һ���ı�������ʹ��ͬ�������������ͬ��
���˺��ˡ�����ν�����﷦ζ���˷�ʱ�䡢��������
��������Ǻ��ˣ���֮������skillsϵͳ�������佫
�ȼ��ǿ��еġ�

���ԣ����е�fight system�����뾭������ĵ�������
���ƣ�ϣ����Ҷ���ý��顣

                                  row


---
����: Yue
��Ŀ: agree row!
����: Thu Apr  2 22:57:37 1998
i agree row i have lots combat file on ES2 if u guys want
made combat like ES2 i can support.
Yue


---
����: Pickle
��Ŀ: wizshell
����: Mon Apr 27 20:58:55 1998
stefan,

is there anyway you can install wizshell in this machine?
i'm very very lazy. :PPP i don't like ftp in and out and
update and edit->ftp in again if there's a small error...
anyway, i think it isn't _too_ difficult to get a wizshell
installed?

give it a shot?

*joythank stefan

pickle


---
����: Yue
��Ŀ: NPC's hp ...
����: Mon Mar 23 00:30:40 1998
�ϻ�ţ(niu) (i cloned out this NPC)
> hp niu
��Ѫ��   0 /   0 (   0 )  ʿ����    0 /    0
���֣�( ---- ) ʿ����  0  ս������0 
���ʣ�    �����ƽ�        ���ݣ�    ��ʯ
hmm
NPC should have hp like players ...


---
����: Row
��Ŀ: more weapon database
����: Sun Mar 22 07:26:21 1998
weapon database is basically set up.
pls check /wiz/row/txt/weapon.txt
any better suggestion is welcomed.

                    row.


---
����: Yue
��Ŀ: a good site about mud �༭����
����: Sat Feb 21 15:07:58 1998
i just found out a really good site about mud �༭����
http://www.etic.net.cn/mud/
enjoy!


---
����: Xiaoxi
��Ŀ: ����
����: Fri Feb  6 10:51:47 1998
���괺���� ����Ұݸ�����
xixi


---
����: Row
��Ŀ: ������ͼ
����: Wed Jan 14 07:04:49 1998
������ʱ���ܵ�ͼ���ϲ��֡��Ѿ��깤��

/wiz/row/txt/main_map1.txt


                         row


---
����: Row
��Ŀ: �Ի��ͼ
����: Tue Jan 13 07:55:22 1998
�ο����ٹ�˾��Ʒ�ġ�����־IV�������˻����ˡ�����
ʱ���ܵ�ͼ���������������Ѿ��깤�������ڱ��˵ĵ�
��֪ʶ�����ḻ�����ص��޷�һһ�����Ҳ��©��
������Ҫ�ĵ�����ϣ�����ָ����

�����ο���/wiz/row/txt/main_map.txt

                                      row


---
����: Yue
��Ŀ: where have list of 'inherit'?
����: Sat Jan 10 20:54:28 1998
as title


---
����: Row
��Ŀ: �����ǵ�ͼ����
����: Mon Jan  5 10:08:16 1998
�����ǵ�ͼ������ɣ�/wiz/row/txt/luoyang-map.txt
ʱ��ִ٣�����Ƿȱ��ϣ�����ָ�����Ա�Ľ���

                                         row


---
����: Jiezhao
��Ŀ: bug
����: Fri Jan  2 17:29:16 1998
errors ((none)) Error logged to /log/runtime
errors *Owner (/obj/pshell#821) of function pointer is destructed.
errors none (0) at :0
that is every time sb logon and quit i saw this


---
����: Row
��Ŀ: about channel
����: Fri Jan  2 08:42:47 1998
������Ϊ���Խ���ݺ��channel ��ʶ������������ͳ
�ġ����ġ���ȡ�������ơ��۵��������ȸ���ѧ���Ĵ�
�㡣
����Ϊ�������һЩ�ʻ㣬�����ο���

newbie�����á��������������滻��
tell��reply �����á���̸�����滻��
chat�����á��۾����������滻��
say ���ԡ����㼺�������滻��
ʱ������á������ǳ�������ҹ��á����滻��
���˻��������������״�����趨���������������ü�
�ĳɹ��ʼ��������ã������á�����仯�����滻��

��ש����ϣ����ҿ����ṩ���õĴʻ㼰�뷨��

                                  row


---
����: Jiezhao
��Ŀ: sanguo's webpage
����: Mon Dec 29 19:02:13 1997
��Һã�
�Һ��������˸������ļ�ҳ��
���ڳ����׶Σ�����������������
������ҡ�

webpage address: http://members.aol.com/sanguozhi/sanguo.html
everyone please go there and check it out
tell me what you think.

P.S. it's still under construction :)


---
����: Xiaoxi
��Ŀ: �뷨
����: Sat Jan 10 11:01:26 1998
�����������ҷ���һ���뷨��hehe
��������Ϊ���������д��һ��ս�Ե�MUD��
�Ѷ��Ǻܴ�ġ��������и����ȣ���д����
��ң����ɶȺܴ��MUD���ҵ��������¡�
1. ���� fight ������ʽ����߽�Ǯ��������
��ҵ��书��������fight ������
����һ�£����輸����ݣ����ϰ������
��ǮΪ��ʽ��Ǯ�Ķ��پ�������ѧ���٣�
Ǯ����Դ������ҿ���ͨ��ɱһЩҰ������
��Ǯ����������ҿ���ͨ����������Ұ��
������Ǯ������
2. ���Ǯ����Ҫ����Ϊ��ʹ��ҿ���ѡ��
���̡�Ҳ���Ǽ���һ�����˵�ϵͳ������
���Ծ�����������Ǯ�������մ󺽺�ϵͳ��
����֮�����۲��ǹ̶��ģ��������ۣ�
���������ĺû��������ģ�Ҳ���ǳ���֮��
�������ǲ�һ���ġ���ȻǮ�ǲ������ġ�
������Ǯ�󣬿��Թͱ��ڣ�������ɱ�֡�
�����ڵĳ�͢Ҫ��˰�����磺����Ҫ��
��һ��ս����Ϊ�����裬���������˲�ʩ
3. ��������ϵͳ�������ɸ���������裬
��������Ϊ��������ҿ����������Ľ���
��ȡ����������ɺ󣬳��������ݶ���
�ý�Ǯ�����������ζ��������������ﵽ
һ���̶ȣ��ſ������һ������Ҫ����
�����ɼ���ѣ����磺�տ�ʼ��������
������Ҫ�Ⱦƣ�ɱһҰ��Ϊ���񣬵�
����Թ���ĳ����Ϊһ����
4����ϵͳ�У������������Ϊ�������磺��
���ɱ��ĳ�����е��سǽ��죬��ҿ�
������Ϊ������ϵͳ���Ƶ��������һ�
����������̡�hehe
��д��ô��ɣ�ͷ�е��Σ��뷨�ܴ󣬲�֪��
��˵�𣬴�����Ұɣ��������⣡ok???;   


---
����: Yue
��Ŀ: ...
����: Wed Feb 11 00:22:22 1998
i want work on inherit(weapon)
where have list of inherit?
i want write come new inherit like blade whip ...
Yue.


---
����: Row
��Ŀ: ���ڡ��������еľ���
����: Sun Mar  8 07:48:09 1998
�����Թ����֮���ս��Ϊ���ߵġ�������MUD ��˵��������һ��
�������ص�Ҫ�ء���Ŀǰ���е�����MUD ��ͬ���ǣ�������������
����һ��ƾ��һ��֮������Դ����µ����硣������뵥ǹƥ����
��������׸ֵ����Ʊ��࿹��Ļ��������˵Ҳ���ף��㽫������
���ѿ� (���������ڲܾ��м������������ƣ�����Ҷ����������
����ô�õ���������ȫ����Ϊ�ܲٵİ���) ������ӵ��һ֧ǿ����
�ľ��ӣ������ڡ��������гɹ��Ĺؼ���

���ӱ�̵ĽǶ�����������δ����������һ���Ƚϸ��ӵ������
ȷʵ�Ƿǳ����ֵġ����Ҹ��˵Ĺ۵㣬��Ҳ��������Լ��ľ���ֻ
��HPֵ�����������򵥵����������֣�Ҳ��������ɽ�����������
��ɱֻͨ���������ֵ����������֣�������̫�����ˡ�������Ҫʹ
�������������ֱ�ۣ���Ӧ��������ܹ������������ؿ����Լ�
������ľ��ӣ����ҿ��԰����Լ�����Ը��֧����ӵ��ж������
һ�����������ӡ���Ƴ�һ�������NPC ����OBJ ��Ƚ����롣��
���ھ�����ʿ������Ŀ�������������������仯�����Ծͱ�����
�𡰾��š��͡�ʿ���������Թ涨��50�����ϵġ�ʿ���� (������
�ֿ�����) �����һ���ɳ�֮Ϊ�����š�������ӵ�бȽ�����
�����幥�������������ȣ������Ļ���50�˱��ǡ����š�ʿ������
���ޣ������޿��Զ�Ϊ5000�˻�10000�ˡ� ��ĳ������ӵ�е�ʿ��
������50�ˣ����������¾Ͳ�����Ϊһ�����Ŷ�ʵʩ��Ч���ж���
���Ҳ���ӵ���൱�ڡ����š��Ĺ�����������������Ϊһ�����ţ�
���Խ��ա�����ָ� (Military Group Cmds)����ԭ�ش�������
�졢����ͻ���ȵȡ���Ȼ�����ǿ���������ҽ�һ��5000�˵ľ�
�ŷָ�����ɸ�������Ŀ�ľ��ţ��Ա�ʵʩ�������������ж���
��ͬʱΪ�˷�ֹ���������������100 ��50�˾��ţ����ǿ��Թ�
��ÿ�����Ŷ�������һ�����ϣ��������µĽ�����죬��������ô
�ཫ��Ͳ������ˣ��׻�˵��ǧ���׵ã�һ�������

����������þ��ŵĸ������ԣ�����Ϊ�������Ⱦ�����Ƶ���ʿ��
�����ԣ��繥����(attack power)��������(attack ability)����
����(defend power)��������(defend ability)�������(dexter-
ity) (�������Ե������й���ʿ����ƣ�Ͷȣ�������Ϊ���硶����
�С��о��������ã�����������ƣ�Ͷȵĳ��ֽ���ʹ��Ϸ��ø���
��ʵ�ԣ�ÿ����ÿ��һ���£�ÿ��һ��·��������һ����ƣ�Ͷȣ�
������ʹ����ʱ��Ϣ��Ϊ��Ҫ�����ڡ��������ڲ����ܳ���ʹ����
���ָ����������ԾͲ��ᷢ�������������²�˯���û������档
�ڡ�������������������Լ��������װ������ʹ�õĹ��߶���
��Ӱ��ƣ�Ͷ����ӵĶ��ټ��ָ��Ŀ����������ԣ�һ����������
��������ɱ�һ���ؼײ������Ĵ�ö࣬���ļ��Ҳ�����ö࣬
��ͬʱ��������С�öࡣ��Ȼ����Ըߣ�������Ҳ�ܵõ�����Ĳ�
�䣬�����ϵ�����Ҳ�����˸��ֱ��֣�װ�����Ե�������ˡ�����
���̵��ص㡣) ��ʿ��(moral) �ȵȣ�ͬʱ����һЩ�������ֱ��
�˽�����ԣ������(nationality) ������(subordinate of)��װ
��(armed with)��Ŀǰ���ܵ�ָ��(current status)����Ӧ������
(describe)�ȵȡ��������˵���ʿ����λ�������ͨ������������
������������ŵĸ������ԣ���������Գ���һЩ�����İٷֱ�ʹ
����Ӻ��������쵼���ŵĽ��챾�������Ҳ���ԶԾ��ŵ�����
�ж�������ã����ͽ��ŷ������������ͻ��и�ǿ��ͻ��������

����һ��ս������Ҫ������ֵ��໥��ϣ���Ҫ���쾡���ط���ÿ
λ����ĸ���������ʿ�����������ԣ���Ҫ������ս������Ч
�Ĳ��ԣ��������ܳ�Ϊս�ֵ�������

�����Ǳ��˶Ծ�����Ƶ�һЩ�򵥿��������ڸ�����ּ���ϸ����
����ƽ������Ժ������ϣ���ܹ���ש�������λ��ͬ����һ��
���Ĳ���ս��������MUD ��

                                                  row


---
����: Yue
��Ŀ: why i can save my file at my own dir?
����: Mon Dec 29 18:58:00 1997
as title


---
����: Yue
��Ŀ: please keep my job
����: Fri Dec 26 18:19:13 1997
wiz told me about i'm kid can't be wiz
sigh
whynot
i really want be a wiz
i need learn C here
here is very good place to learn C
so i really want be wiz
so please keep my job


---
����: Dan
��Ŀ: ����
����: Tue Dec 23 06:40:58 1997
��û����������������ֻ�ð��Լ����뷨����/wiz/dan/note/sanguo.c��
��ҿ����Լ�ȥ����˭��æ�������


---
����: Stefan
��Ŀ: Directory Structure
����: Wed Apr 16 04:20:14 1997
(ת����documentation)
        ----secure    Objects that need high security level, such as
        |             master.c and security daemon, etc.
        |             
        |--daemons    all the daemons besides those in /secure
        |
        |--include    include files used by all the lib programs.
        |
        |-----data    player data, mail data, news data and etc.
        |
        |------std    all the standard objects and modules which is
        |             designed to be inherited.
        |             
        |------obj    some ready to use objects at the mudlib level,
        |             such as mailbox, shells etc. 
(root)--|             
        |-----cmds    all player and wizard commands.
        |
        |----trans    objects that needs to bypass security check.
        |             (transparent to security manager)
        |             
        |--domains    all the rooms, npcs, objects of individual areas.
        |
        |------wiz    all the wizard directories.
        |
        |------log    all the system log files.
        |
        |------ftp    the ftp directory for anonymous ftps.
        |
        |-----help    help files for commands, efuns, and wizard tools.
        |
        |------WWW    WWW related stuffs.
        |
        -------tmp    just a trash bin.


---
����: Lei
��Ŀ: color
����: Thu Dec 25 04:37:58 1997
can set color now.
add #include <ansi.h> first.
then like "+HIW+" to color and end by "+NOR+"
You can go to /wiz/lei/txt/color.txt to get what color we can use.



---
����: Yuner
��Ŀ: wiz rules
����: Sun Dec 28 10:10:41 1997
Wiz rules are ready now, all wizs including Admin please follow the rules,
if anything happened, please settle it according to the rules, for
more details
please go through /wiz/yuner/WIZ_RULE.
After that i have to leave here as i said 2 weeks ago, lei, fire and
pickle will
in charge the whole mud, after i quit, my opinion will not be
counted into Admin
's discuss unless i come back and join the group again. Addoil all!


---
����: Row
��Ŀ: about addemote
����: Mon Dec 29 00:57:47 1997
�ڼ�įӢ���У�addemote���������õģ�
ָ���ʽ : addemote 0 0 emote
 
���ָ������޸� emote ���г�������. 

-p ��������г�ָ�� emote ������. �г���˳�����
�� emote ʱ��ͬ.

-d ��ɾ����emote. ��Ȼֻ������WIZ���Ǹ�emote���Լ�д�ġ�
 
���� emote ѶϢʱ��������Ŀ: û��Ŀ��, ָ��Ŀ����Ƕ��Լ�. ��
������ĳ��ѶϢ, ��ֱ���ڿհ������� '.' ����.
 
 
�༭ emote ʱ���������µķ�������ʾ:
 
      $N              - name of emoter ���������˵�����
      $n              - name of target Ŀ�������
      $P              - pronoun of emoter ���������˵Ĵ���
      $p              - pronoun of target Ŀ��ĵĴ���
      $S              - ���Լ������ query_self
      $s              - ���Լ��ļ��� query_self_rude
      $C              - ���Լ��ı��ֹ�ϵ
      $c              - �Ա��˵ı��ֹ�ϵ
      $R              - �Ա��˵���� query_resprct
      $r              - �Ա��˵ļ��� query_resprct_rude

���Բο��¡�

                                      row
                                     97,12,29


---
����: Yuner
��Ŀ: To all new wizs
����: Sun Dec 21 21:46:39 1997
At start, please ask those senior wizs if u have any problem, don't try to
clone those *.c which is not a moveable obj and don't mistype the filetype
espically the *.c (eg. WELCOME is a txt file, don't type the name as welcome.c
which can cause system fault). To get familar with here, the best
way is to ask
other wizs, read the news, know the structure of directories first, then the 
files in the dirs and their uses, after that, u can try to do some simple 
rooms, npcs or objs, for higher level, u can try some new features which u 
think can use in our ��  ��  ־ :) , but remember, if u want to
change anything
related to important system files, please discuss with Admin first,
and remember
to do a backup file, if u are using edit, please use I command to
log all u did
into log file, then if sth is wrong, we can know where is wrong and fix it
�� ��  ־ is a exciting topic and a whole new area in the world of mud, it
is a ս������Ϸ�����̳���������pc game���ŵ㣬����ʹ���е��˶�Ŀһ�£�����˵
�ǿ�������Mud���Ⱥӣ���ҿ��������﷢�ӷḻ������������������Ķ��˶�ɣ�
���е���һ�ж������ڴ�ҵ�Ŭ��! *addoil all!


---
����: Lei
��Ŀ: login.file
����: Sat Dec 20 01:28:45 1997
                 ����Lima֮����
��ӭ�����������Lima֮���������硣
���������Ϸ�����ڽ��쵱�С�ͬʱ����Ҳ��Ҫ���İ���
��֧�֡�����������������ĺ�����Ȥ��������һ����
UNIX��C��C++�Ļ�������ô���Ǻܻ�ӭ��ӭ��������ǵı༭���顣
��Ȼ��ֻ����һЩ�õĵ��ӣ�Ҳ����д���������ǡ�
��mudmail��Lei or Fire.���ǻ���һ������֮�ڃ����𸴡�



---
����: Fire
��Ŀ: �ҵ����������
����: Sat Dec 13 17:41:35 1997
1. ȡ��pot
pot�ĸ������֣�����ʵ�к������������Ӧ�Ķ�����
ͽ�ܿ���ʱʱ��ʦ��ѧϰ��(ֻҪ���㹻�ľ���)ѧϰ���ٶ���ɴﵽ����ߵȼ�
�ɾ���(����)���������⣬��ѧ���Ķ�������ֻ�������ϵģ����������Ǻܴ�
ֻ���ڳ�ֵ�ʵ������������������ʾ������
2. ȡ��ս��������ķ�ʽ��
������MUD�У�������Ҫ��ս���еã����ԣ�һ��ս�����ǳ�����ʱ��Խ��Խ�á�
����Ϊ����Ӧ��ɱ�����ֻ��ܶ���ʱ��ã�������ҲŻᾡ��ѧ�������ķ���
ͬʱҪ����ʤ��
3.������Ȼ�з���񣬿ɴ�ԭ������ȡһЩ�زģ������ؽ����ڴΣ�Ҳ����̫
���ԭ������������ʹû�����������Ҵ��ںܲ����ĵ�λ
�վ�������񡷲����������͡������С�
4. ��������Ҫר��ѧ����Ϊ�����master�ɴӲ�ͬ��masterѧ��ͬ������
��һ��Ҫ��ʦ��������Ҫ���һЩquest��task����ѧ������������ȼ�Ҫ��
��һ���ɶȲ��С�
ѧ��߼����������ͼ��ľͿ���adadon����


---
����: Lei
��Ŀ: �����ķ�չ����
����: Fri Dec 12 07:04:10 1997
���ڵ�������س����������������������������򴳳�һƬ��վ�
���ò�����ɾ��ˡ�Ҳ��Ϊ��ˣ�����ѡ����Lima��Ϊ��������û�и���
�����������ES2���Ͼ�ES2��ʮ��ǰ�Ĳ����Limaֻ����������ѡ���
������Lima�кܶ��Ƚ��ĵط�����Ϊ�Ҳ����У�Ҳ���ض�˵��

��������̸��������ʹ������ڹ������⣬�þ���ķ���������ϷĿ����
���ı���Ĳġ����ڿ������ϵĿ�����Ǿ���ķ����Ѿ����飬������Ϊ
�������ѷ�ֹ���ʹ�û����ˣ��������ǿ϶�����ʹ�á�
Ŀǰ��Ϊ������ҵ���XYJ��NKϵͳ�����Ƶ�TASK��QUESTϵͳ���Ҹ�����
ΪNK���TASK����õ�ѡ�񡣶�һ������ң�TASK�Ǻܺ�ʱ�ġ����ǿ���
���һЩ��������֮�������ÿ�����ɶ����в�ͬ����������һ����
�ֿ���ͨ�������Щ������Ϥ���Σ���˳�����ȵ��е��ֵĽ׶Ρ��һ���
��Ӧ��ǿ��GROUP WORK(��֪������Ҫ�����)����֮��һ����ҾͿ�����
��һЩ����ɱǿ������֮��������ⲻ���Ա�����NK����������TASK��
Χ��������NKӦ�����ڳ�Ϊ�и���֮��ɱ��Щ�������յ�NPC�����������
��NPC��úܣ��ֶ�����ö�������ʱ����ұ������ȫ��NK���Ǿ��顣
�������ͷ��ƺ����ƣ���ʵ����ȴ���ྶͥ�������ɹ��±��������ġ�

���������Ҫ������̣����̣�����֮�̺ͽؽ̣�����һа������������
֯����������������������������һ��һа�������룬һ�������ѡ��ʦ
��ʱӵ���Լ������ɣ����Ժ�Ҳ��������ѡ������Ͷ����������ΪŰ����
ɽ֮ǰ����Ҫ���ʦ�����õ�����ͬʱNK��������֯�Ժ�Ϊ��֯������
�������Գ�����ս��

��Ϸ���ռ�Ŀ�Ŀ���ѧѧ���μǡ���ÿ��ս������һ��QUEST��������
һ��QUEST�����Զ������ɱ༭(��ʦ)�������緽һ���֣����ڰ�������
���³��裬������������Ҳ���������ʷʹ�������������ˣ�ͬʱ������
����Ҳ������ʷ�ᡣ���ǵ�Ȼ��ѹ���������һ�㡣

��һƪ�һ�д������������롣�ϻ�һ�䣬��ʲô�����Ͽ���������
���Ǻ�һ�����ۣ��Ծ�����õķ�����


---
����: Stefan
��Ŀ: >About Score
����: Thu Dec 11 23:54:45 1997
why nobody try to see what's here in lima already? the gifts, the hp, etc...
You'll be surprised if you look into the gifts here :)


---
����: Lei
��Ŀ: About Score
����: Thu Dec 11 07:35:22 1997
I think no need to display XYJ's. Here I want to show you ��įӢ��.
������[ 17]     ��ʶ��[ 15]     ���ԣ�[ 22]
��Ե��[ 23]     ��Ե��[ 22]     ���ǣ�[ 21]
Seems �� is not important which is not mentioned in XYJ either.
Becoz these gift is about how to get exp. and fighting system will
be written by Kane. So it'd better to decide what we need after Kane
come back.
Anyway I think ������[ 17] ���ԣ�[ 22]��Ե��[ 23]  ���ǣ�[ 21]
are needed in FSB. Do you think anything else should be added?
Another part of score is quite interesting... It also can attract
players to work for it.
----------------------------
In XYJ: ս�������� 9527 (+0)           ս�������� 10766 (+2)
(I dislike this. Becoz in real fight, anything can happened... If we
keep these figures, players will keep qurying why... can beat ...)
�У˵������ӣ� ��ʮһ��ʮ������ʱ��
�У˵��м��٣� ʮ����һ�ٰ�ʮ������ʱ��
�Σ˵������ӣ� ��ʮ������ʮ�����ʱ��
This is quite interesting...
We definetely will use M-#M-NM-#M-KM-5M-@M-PM-P since player will
get exp mainly by
this way when he or she is a mid-highhand. About �У˵������ӣ�, I prefer
whole wiz group to make a decision.
----------------------------
In XKX : ��  ��     206  ���������� 140    (It is about what kind of
NPC you kill)
�㵽ĿǰΪֹ�ܹ�ɱ�� 312 ���ˣ������� 36 ����������ҡ�

�㵽ĿǰΪֹ�ܹ����� 17 �Σ����� 10 ��������������
(This is an old way... but not attractive... XYJ does not have it
at all, but I will prefer ��įӢ�� style.)
---------------------------
��įӢ�� : ���������� 1                �ϴ����� ��� ֮��
^^^^^^^
(This is quite interesting, Make you remember who killed you)
���������� 0  [0/0] (sounds better than ��������: )
And we may use another name which relates to FSB
Need how Fengyun works... Sunnie may help to add FY's resource...
My idea is we will follow other muds, but not follow a pecific mud...
We will choose best and most reasonbale hp, score to our players...
This is just my opinions, I hope other wiz will have better ideas. If
we can make sth spcecial, that is real ͻ�ơ�
Anyway, pls post your idea any time, and then we can discuss:)



---
����: Lei
��Ŀ: HP system
����: Thu Dec 11 02:41:31 1997
Now I am beginning to write hp and score.
First of all, we need to make sure what we need.

About HP
2 most popular mud's hp as following:
About ������
----------------------------------------------------
���� 765/  765 (100%)    ������  966 /  966 (+1)
���� 661/  661 (100%)    ������ 1164 / 1164 (+0)
ʳ� 241/  300         Ǳ�ܣ�   16 /  133
��ˮ�� 261/  300         ���飺 109716
----------------------------------------------------
About ���μ�
----------------------------------------------------
��Ѫ�� 196/  196 (100%)    ������    0 /    0 (+0)
���� 169/  184 (100%)    ������    0 /    0 (+0)
ʳ� 256/  240           Ǳ�ܣ� 82
��ˮ�� 196/  240           ���У� ��ʮ����
----------------------------------------------------
We can see ��������ʳ���ˮ�� all are basic elements...
Ǳ�ܣ����飺 are same with Ǳ�ܣ� ���У� which also is basic elements.

���⼸��Ԫ���Ͽ������ǲ��ò�����ǰ�˵Ľ�ӡ����Ȼ�����˭���뵽�����ȡ
�����ǽ������ǵ�һ��ͻ�ơ��ֵܽ��ã���������

Pots and Exp also is basic elements, which we must have. However, we
can say it in a different way in Chinese.

������������ֵ�������µĵط����Ҹ�����Ϊ�����ǿ��Բ�Ҫ�ġ���Ϊ�ڷ����
û�������书�������ڼ��������⡣�������������飬�����������Ĺ��ܶ�����
�ɷ�����ȡ����Ҳ����˵�Ѷ��ߺ�һ���������ǿ��Խ���������е�ģʽ����ǰ
�����еľ�����ͬ���衣������һ�����á��������������������б༭��������
Ϸ�Ѷ���Ϊ��

Ҳ����˵�������з�����ģʽӦ����:
���� 0/    0 (100%)
���� 0/    0 (100%)
������ 0 /    0 (+0)
ʳ� 0/  240           Ǳ�ܣ� 100
��ˮ�� 0/  240           ����(����)�� 0
-------------------------------------------------------



---
����: Fire
��Ŀ: about semote
����: Thu Dec  4 08:47:26 1997
i am writing new semotes
there must be many mistakes and shortages
anyone has any ideas or find anything wrong
please post here
thank for your help
xixi


---
����: Lei
��Ŀ: С��
����: Mon Dec  8 04:33:41 1997
���һ��Ŭ�������£��µ�����semote�Ѿ���ɣ������Ҵ�����������
�༭������ʾ��ֿ��л�⡣
�����һ�Ҳ�����������Լ��ĵ�һ�����䡣����һ���༭�ǵĶȼ�
�塣��������һ��С���Ŀ�������±༭����Ϥ��д�����һЩ��NPC�ĳ�
��Ŀǰ��Ҫ���һ��Է���ڽ��н��칤����������˭�����Լ���������ǡ�
��Ȼ��Ϊ�������±༭���������������һЩ�碣�����ϣ���ϱ༭�ǣ�
��STEFAN, SNOWCAT,PICKLE�������Ԯ�֣���һ����Щ�ط���Ҫ�ý�����Щ
��������һ�ַ�������á�
��һ���ǵ�KANE�������дSKILLS&FIGHT&KILL�ĳ����ڴ�֮ǰ��ϣ��
STEFAN��������һ�㣬����Ҫ�������꣬����һ�㣬�պ������Ĺ�����������
��һЩ�����͸ɰɣ���л�ˡ�



---
����: Lei
��Ŀ: ����
����: Mon Dec 15 03:58:03 1997
These several days I was adviced to write Mud of Sanguo, and I think it is 
a good idea. Reasons following:
1: Mud based on ES2 can hardly beyond XKX,XYJ,FY. These 3 muds have their 
own features, and a lot wiz have worked for it for a long time...hmm...
So if we want to explore a new theme, it is very difficult to dingstinguish 
with these 3 muds and very difficult to beyond them.
2: FSB is not a bad idea. FSB book supplys us a full background, we need not
to think about new ideas. However, it is not so pupular as Jingyong books.
As we all known, XKX is most successful chinese mud until now. I think its 
success partly comes from well-known Jingyong novels. Although FSB
has a strong
background, it is still lack of ֪���ȡ�
3: Sanguo also has a very good ֪���� for its successful PC games. I supporse
that every1 plays mud who also play PC games. To a chinese PC game
player, there 
is less 10% possibilities who has never played Sanguo games.
4. Fire mentioned Sanguo may be too difficult to do. Yes, it is.
   But just now I realize that why we have not used ES2 as our
mudlib but Lima?
becoz every1 of here want to make a good mud, but not follow others.
If we just 
try to write FSB, and we also want to beyond XKX,XYJ,FY... I think it is also 
a very difficult work, not a bit less difficult than Sanguo.
So we not focus our energy on a new topic? Nobody do that before.

Addoil... I will post completely steps what we will do for Sanguo if
you support 
my opinion. If any1 of you think FSB is still better, just post ur opinions or
send me a mudmail.
Regards!



---
����: Sunnie
��Ŀ: @_@
����: Tue Dec 16 04:56:34 1997
�ݶ��˼�λ��ʦ�����Ժ��������������ɵ�Ҳ�����Ū����̸̸�Լ����뷨��
�������Ϊ��Ϸ�����ݣ�֪�����Բ����Զ�����ӹ������С˵����ڣ�
��������Ϊ��������Ϥ��Ҳ�Ȳ������μǡ���������ҵĽǶ��������ⲻ�ܲ���
�Ǹ�ȱ�������Ǵ���һ���棬���ܷ����ܸ���Ϸ������߸���ķ�����ء��Խ�
ӹС˵Ϊ�����������У��Թ���С˵Ϊ�����ķ��ƣ��Լ�������ɮȡ���ı����
�μǣ����������֮������δ����ԭ����ڵ����ƣ���Ϸ���������һЩ��ԭ��
�����ĸĶ���������������������Ϊ����������·������������ǰ�����Գ�Խ��
Ҳ�������κ����⡣��ʱ���Ҳ��ò�Ҫ��һ�¶�������ϵ�С���ʵ�϶������²�
��ȡ����ĳ��֪����С˵������������ڵ���ƣ��书�Ĺ�˼����������˼����
������ǰһ���ĸо����ڵ�ʱ��˵����������ȫ��ͬ��������ò���ֵġ����ǵ�
��Ϸ�Ƿ��ܿ���һ��ո�µ���أ����Ⱦ���ȡ�ġ�Ϊʲô����һ��Ҫ��ĳ����Ϊ
����֪��С˵Ϊ�����أ���λ��ʦ������ţ����ɱ�д�����Լ��Ĺ��¡�����Դ
�����һ��һ���磬һҶһ���������������������������¡��͵���Ҽ��崴
��һ��С˵�ɡ�����С˵�����ݣ��ƺ��������壬��а��������������������
�⣬�м䴩��ЩӢ�����̣���Ů�鳤֮�ࡣ������λ�����ѳ����������뷨��
��˼�����ٺò�����
�Ҵ����ԣ�������ש����


---
����: Yuner
��Ŀ: about sanguo
����: Sun Dec 21 01:15:50 1997
Stefan has pointed out the difficulty of doing sanguo,but lei fire have a good
solution to take the bing as a variable of player, just like the old version 
of san guo pc game. The problem is, there is only 1 type of bing, or 1 group  
of bing belong to u, if u want to define 3 groups of bing as a gift of player
,how to order them to act different things? But i believe this pro
can be solvved
if we can think and dicuss it carefully, other problems such frame
or how to combine pc game with mud, how to distinguish the pc game with 
mud,since for pc game, play once, then game over,but for mud, we need players
to continue their play, this is also a pro. Lei mentioned another pro, if we 
follow the form of TK(tai ge li zhi zhuan),1 player can have 1 city
if he is strong,but when he is not on line, how to deal with his
city? put a dummy? or close his city?also a problem....so we need
all wizs to give ur suggestions to solutions to those problems,if we
can do this job, we will be another annihilator grouup since we make
a whole new area of mud!addoil!


---
����: Stefan
��Ŀ: A Short Introduction To LPmud Programming For Newbie Wizard
����: Wed Apr 16 04:17:09 1997
(ת����documentation)

        Maybe you are new to mud programming, but you should already
have some experiences of playing mud. I assume that you know what is
a mud and how a mud interacts with players. This introduction does  
not cover LPC programming, for which you can always refer to the books
I put in the /help/LPC directory.


How does a LPmud work?

        A LPmud consists of two parts, one is the driver (we are
using MudOS driver) and the other one is the LPC library. When a mud
is started up, the driver will load an object called master.c and
master.c will tell the driver to load some other objects into memory
and run them. The driver will keep running until a shutdown()
function call or a bug makes the driver crash.

        A driver is merely to keep running LPC bytecode (if bytecode is
not in memory, the driver will compile LPC program into bytecode first)
and to provide system calls to LPC objects, such as an incoming connection
request or heartbeat and call_out pending functions (refer to LPC
books if you need to know what are heartbeat and call_out).

        All the LPC programs form a so-called mud library, or in short,
mudlib. There is no particular rules on how the lib should be coded, but
all existing LP mudlibs follow the same structure, more or less.

    master.c    It is the first object loaded into memory, it initializes
                the whole mud, defines system routines and starts up
                daemons. If it fails, the mud won't start up.
            
simul_efun.c    It provides functions that override existing efuns (
                external functions, provided by the driver), defines
                new functions that will act as if they were efuns
                through out all the LPC programs in the mud. They are
                called simulated efuns. 
                
     daemons    Daemons are programs (LPC objects) that provide basic
                services to all other LPC objects, there may only exist
                one object for each daemon (daemons are not clonable). 
                Things like listening to the port to accept outside
                connections, security management and combat processing,
                are all written as daemons.
            
     objects    An LPC program can create an object. If there is a call
                to an object before it exists in memory, the driver will
                compile its program to bytecode, load it into memory and
                then execute the function call. It is called a master
                copy of that object. If this object is cloned, the driver
                does not compile the program one more time, instead, it  
                creates a copy of the master copy and use it. Objects    
                form the world of LPmud.


---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Group
��Ŀ: thanks a lot
����: Sat Mar  6 01:27:42 1999



---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Group
��Ŀ: thanks a lot
����: Sat Mar  6 01:27:42 1999



---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Group
��Ŀ: thanks a lot
����: Sat Mar  6 01:27:42 1999



---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Group
��Ŀ: thanks a lot
����: Sat Mar  6 01:27:42 1999



---
����: Group
��Ŀ: thanks a lot
����: Sat Mar  6 01:27:42 1999



---
����: Group
��Ŀ: thanks a lot
����: Sat Mar  6 01:27:42 1999



---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Group
��Ŀ: thanks a lot
����: Sat Mar  6 01:27:42 1999



---
����: Group
��Ŀ: thanks a lot
����: Sat Mar  6 01:27:42 1999



---
����: Fire
��Ŀ: row and group's wiz position have been re assigned
����: Wed Mar  3 19:55:46 1999
I will work in next week,
addoil all
NEVER GIVE UP


---
����: Fire
��Ŀ: about the area ����
����: Thu Mar 11 02:53:05 1999
I change the area in to be the same as area_id
this will reduce lots of troubles


---
����: Fire
��Ŀ: about the path
����: Sun Mar 14 03:44:56 1999
for current mudlib construction
most files are under /sgdomain
but still some important files under /daemons
and /std, 
for /std the most interesting part is /std/modules
so I think that we probably need make them
under Mudlib:sth and so on


---
����: Stefan
��Ŀ: about security level here
����: Sun Mar 14 01:36:21 1999
Since the mud crashed, part of the security system is not up to date,
I am rearranging it...

/sgdomain is under privilege Mudlib:sanguo, which has been added
to group and flee, you two please check if you can modify things
under /sgdomain. 

Other 'alive' wizs, if you want it also, please let me know.

PS: /monster, I think should be moved to under /sgdomain

stefan


---
����: Fire
��Ŀ: ��������Ľ��顣
����: Tue Mar 16 05:12:03 1999
Ŀǰ���ڲ��԰����19�������󲿷��Ѿ��깤������longxi,
taiyuan, xianyang �������л���ֻ���������䡣�ر���̫ԭ��
��ͼ��û�С�Ϊ��׼�������Ƴ����԰棬������Ҫ���������Щ
�����衣
���幤�����£�
1 ����������������ķ��ݱ�д���������Լ򵥡�
2 ����һЩ�����ķ��ݣ�����ʹÿһ��������һ���Ĺ��ܡ�ͬʱʹ
  �����ķ����������価��������Ĳο��������
3 ɾ��û�����ӵĳ���
4 ����NPC��һЩOBJ (����Ҫ������ϵͳЭ��)
���������������ο���:
��������      �����   �еȳ���    ����     ��ׯ    �ؿ�
������          1        1          1        1       1
���ϳ�          1        1          1        1       1
��վ            1        1          1        1       1
����            1        1          1        1       1
�͵�            1        1          1        1       1
����            1        0          0        0       0
����            1        0          0        0       0     
��            1        1          1        0       0
��װ��          1        1          0        0       0
������          1        1          0        0       0
���׵�          1        0          0        0       0
�÷��          1        0          0        0       0
������          1        0          0        0       0
���            1        0          0        0       0
����            1        0          0        0       0
�鱦��          1        0          0        0       0
ҩ��            1        0          0        0       0
��������       30-50    30-40      15-30     10-20   10-20 
�ǽ�ɫNPC��    10-15    5-10       5-10      2-5     2-5


---
����: Fire
��Ŀ: �����й����ƻ����ܽ�
����: Thu Mar 18 18:30:32 1999
1 middle level job and basic level job
�����Ѿ���������̫���ɷ����м������һ
��̫���ɷ��������񡣵������ǻ���Ҫ����
����������Ϊ��Ҫ���м�������Ϊ���
����ǰ��ʱ��̡ܶ���������ϣ����һ����
��������������̫���ɷ����м����������
̫���ɷ��ĳ�������
һЩ�����ɼ� man jobrules �� man jobhint
����Ŀ���Ҫ��flee,rou��group ����fire
��Э����̺Ͳ��ԡ�
2 ������ɫNPC��
�����yuyin ��Ŭ���£���ɫNPC�������Ѿ�
�ﵽ��53��(�� listchar /1 /v is_tmp 0 /v type 0)
��ѯ��yuyin����Ҫ�������ӽ�ɫNPC�Ĺ�����
��ȡ��������ʹ��ɫNPC�������ﵽ100������
Ҳ���ǲ��԰���Խ��ܵ���Ŀ��������19������
ƽ��һ������������ɫNPC���Ǻ���ġ�
3 ������ҳ��
��jams(swallow) ��Ŭ���£�������������һ��
��ҳ��һ���ܲ���ĵ�ַ��http://sgz.yesite.com/
��ͨ�ż��죬���������ʹﵽ80(���а����ҵ�
10�Σ�hoho)��������ǽ�������һ�����кô���
jams�Ĺ�������Ҫ��������ҳ�ϣ��������ͼ�ΰ壬
�������µ����ݡ�ͬʱ����ʹ��lima�ṩ��CGI��ʹ��
�������ҳ�Ͽ���ֱ����ɶ�lima�İ���(����Խ�ʡ
һ��ѵ��ı����¹���)��ֱ�Ӷ�lima���԰塣������
����һ���ض���ɫ����ݣ���ˮ������������MUD
�ĵ�ǰ����
4 ��Ұ���
����֪����������MUD���ڴ��·������кܸ���������
���������ʼ���ǻ���1-5֮�䣬��������MUD��û�б�
����ҵ��ˡ�(���Լ��ô�����)��������������������
ʮ�����ҵ���ҡ�������������δ�����ϵͳ����һ
���ܴ�Ŀ��顣�����кܶ�û�о�����Ҽ������ƣ�
�����Щ����Ҷ���Щ��Ƹе����⣬�����ǽ�����
��չһ�����кô���������������������ǵ���©��ʹ
����Ҳ��ܳ���˽����ǵ���ƣ�������⣬���ܻ��
���ǵĽ�����������Ӱ�졣�����������guanfengΪ��
ʦ��ר�Ŵ��½�������ҺͰ�������ҵĹ�����������
���ǵĺ��Ŀ�����û���꣬���Ի������˴��ģ������
����̫������ҡ��ܱ���ʮ����������߾Ϳ����ˡ�
5 ��ȫϵͳ��
�Դ��ϴε�����ϵͳ��������Щ��ˬ�졣
a finger ������ʾ��������
b ���Ҳ������finger �鵽������Ϣ
c ���� cmd suicide �ˡ�
d ���������ʦʱ������ʦ��auto logout �� auto login
  ��su ���������ص�BUG ϣ��stefan��հ���ЩBUG fix
һ�¡�
6 �������衣
�����������Ѿ�д��һ���������� man areahint����������
���������д�����Ǽ�����Ĳ��£������ڴ����ر��лrow
��group��benben������ǿ�������������ĵ��������ս
����ͼ����ơ������ҽ���benben ������µĵ���������һ
Щ���书�ܣ�����ƽ�⣬��ͼ���µĹ�����ͬʱϣ���Դ˹���
����Ȥ��WIZ������Ԥ������Ȼ��һ������Ĺ�������Ҳ��һ
����Լ򵥣��������֣���Ч��Ĺ�����hoho
7 ��NPC
���ǵĴ󲿷ֵ����������̣����ڽ��ϣ�����ëë�ģ��������
һЩ�򵥵�NPC��ŮѾ�ߣ������ȡ����������̫�鷳��������
�������ˡ�˭Ҫϲ����Ҳ�����ø��㡣
8 ����NPC��
��ЩNPC��ͬ�ڽ�ɫNPC��(������)Ҳ��ͬ�ڼ�NPC���С����
ˮ���ȡ�������CHAR_Dֱ�ӿ��ƣ�������Ԥ����������������
NPC�������ˣ�С�к������ˣ�ǿ����С͵�ȡ�����NPC��ƽ�
���ӣ���������CHAR_D���ƣ��ɲ�Ԥ���ӵ�JOBϵͳ��ͬʱ����
�ǳ��������ԡ���������м�JOB����ʦ����ÿ����������
����NPC�ļ��ɡ�
9 ��Ʒϵͳ
���ϵͳ����һֱ�Ƚϱ��������������ǵĽ�ɫ�����ϵͳ�Ѿ�
���ڳ���(�������ַǳ���Ҫ���Ǳ�MUD�ľ�������WIZ�뻨ʱ����
�⡣�����ļ���/daemons/char_d.c /daemons/area_d.c �Լ�
/daemons/char_d/ /daemons/area_d/�µ������ļ����������Ǽ�
����Ʒϵͳ���������������֣�
a ��ʳ����
b ��װװ�ײ���
c ��������
d ��ƥ����
e �鼮����
f ���ﲿ��
�ⲿ�ֺ�ս��ϵͳ��HPϵͳ��SKILLϵͳ�зǳ���Ĺ�ϵ����fire
��������ƺ�Э��������
10 ���һ��飬����ս�����������
����һ���ǳ���������������ֹ�ϵ�ǳ����ӵ�һ���֡�������󲿷�
�������Ѿ����ˡ��ڿ����ɡ�


---
����: Stefan
��Ŀ: ���ּ����
����: Fri Mar 19 23:38:36 1999
�������Ƚ�Ӱ������ :)
���λд��ʱ���������...

�������е� feelings �Ҵ�ǰ��������������¼ӵ�һЩ�в��ٴ��ֺͱ������⣬��˭
�ӵģ����Ժ�������� :)

���������������ĵ����뾡����ȫ�Ǳ�㣬������á������ǣ�



---
����: Stefan
��Ŀ: ���ּ����
����: Fri Mar 19 23:38:36 1999
�������Ƚ�Ӱ������ :)
���λд��ʱ���������...

�������е� feelings �Ҵ�ǰ��������������¼ӵ�һЩ�в��ٴ��ֺͱ������⣬��˭
�ӵģ����Ժ�������� :)

���������������ĵ����뾡����ȫ�Ǳ�㣬������á������ǣ�



---
����: Stefan
��Ŀ: ���ּ����
����: Fri Mar 19 23:38:36 1999
�������Ƚ�Ӱ������ :)
���λд��ʱ���������...

�������е� feelings �Ҵ�ǰ��������������¼ӵ�һЩ�в��ٴ��ֺͱ������⣬��˭
�ӵģ����Ժ�������� :)

���������������ĵ����뾡����ȫ�Ǳ�㣬������á������ǣ�



---
����: Row
��Ŀ: about ���ּ����
����: Sat Mar 20 07:16:23 1999
����������ּ��޸ı��Ĺ�����:)
chat* raise row


---
����: Fire
��Ŀ: �����й����ƻ����ܽ�
����: Thu Mar 18 18:30:32 1999
1 middle level job and basic level job
�����Ѿ���������̫���ɷ����м������һ
��̫���ɷ��������񡣵������ǻ���Ҫ����
����������Ϊ��Ҫ���м�������Ϊ���
����ǰ��ʱ��̡ܶ���������ϣ����һ����
��������������̫���ɷ����м����������
̫���ɷ��ĳ�������
һЩ�����ɼ� man jobrules �� man jobhint
����Ŀ���Ҫ��flee,rou��group ����fire
��Э����̺Ͳ��ԡ�
2 ������ɫNPC��
�����yuyin ��Ŭ���£���ɫNPC�������Ѿ�
�ﵽ��53��(�� listchar /1 /v is_tmp 0 /v type 0)
��ѯ��yuyin����Ҫ�������ӽ�ɫNPC�Ĺ�����
��ȡ��������ʹ��ɫNPC�������ﵽ100������
Ҳ���ǲ��԰���Խ��ܵ���Ŀ��������19������
ƽ��һ������������ɫNPC���Ǻ���ġ�
3 ������ҳ��
��jams(swallow) ��Ŭ���£�������������һ��
��ҳ��һ���ܲ���ĵ�ַ��http://sgz.yesite.com/
��ͨ�ż��죬���������ʹﵽ80(���а����ҵ�
10�Σ�hoho)��������ǽ�������һ�����кô���
jams�Ĺ�������Ҫ��������ҳ�ϣ��������ͼ�ΰ壬
�������µ����ݡ�ͬʱ����ʹ��lima�ṩ��CGI��ʹ��
�������ҳ�Ͽ���ֱ����ɶ�lima�İ���(����Խ�ʡ
һ��ѵ��ı����¹���)��ֱ�Ӷ�lima���԰塣������
����һ���ض���ɫ����ݣ���ˮ������������MUD
�ĵ�ǰ����
4 ��Ұ���
����֪����������MUD���ڴ��·������кܸ���������
���������ʼ���ǻ���1-5֮�䣬��������MUD��û�б�
����ҵ��ˡ�(���Լ��ô�����)��������������������
ʮ�����ҵ���ҡ�������������δ�����ϵͳ����һ
���ܴ�Ŀ��顣�����кܶ�û�о�����Ҽ������ƣ�
�����Щ����Ҷ���Щ��Ƹе����⣬�����ǽ�����
��չһ�����кô���������������������ǵ���©��ʹ
����Ҳ��ܳ���˽����ǵ���ƣ�������⣬���ܻ��
���ǵĽ�����������Ӱ�졣�����������guanfengΪ��
ʦ��ר�Ŵ��½�������ҺͰ�������ҵĹ�����������
���ǵĺ��Ŀ�����û���꣬���Ի������˴��ģ������
����̫������ҡ��ܱ���ʮ����������߾Ϳ����ˡ�
5 ��ȫϵͳ��
�Դ��ϴε�����ϵͳ��������Щ��ˬ�졣
a finger ������ʾ��������
b ���Ҳ������finger �鵽������Ϣ
c ���� cmd suicide �ˡ�
d ���������ʦʱ������ʦ��auto logout �� auto login
  ��su ���������ص�BUG ϣ��stefan��հ���ЩBUG fix
һ�¡�
6 �������衣
�����������Ѿ�д��һ���������� man areahint����������
���������д�����Ǽ�����Ĳ��£������ڴ����ر��лrow
��group��benben������ǿ�������������ĵ��������ս
����ͼ����ơ������ҽ���benben ������µĵ���������һ
Щ���书�ܣ�����ƽ�⣬��ͼ���µĹ�����ͬʱϣ���Դ˹���
����Ȥ��WIZ������Ԥ������Ȼ��һ������Ĺ�������Ҳ��һ
����Լ򵥣��������֣���Ч��Ĺ�����hoho
7 ��NPC
���ǵĴ󲿷ֵ����������̣����ڽ��ϣ�����ëë�ģ��������
һЩ�򵥵�NPC��ŮѾ�ߣ������ȡ����������̫�鷳��������
�������ˡ�˭Ҫϲ����Ҳ�����ø��㡣
8 ����NPC��
��ЩNPC��ͬ�ڽ�ɫNPC��(������)Ҳ��ͬ�ڼ�NPC���С����
ˮ���ȡ�������CHAR_Dֱ�ӿ��ƣ�������Ԥ����������������
NPC�������ˣ�С�к������ˣ�ǿ����С͵�ȡ�����NPC��ƽ�
���ӣ���������CHAR_D���ƣ��ɲ�Ԥ���ӵ�JOBϵͳ��ͬʱ����
�ǳ��������ԡ���������м�JOB����ʦ����ÿ����������
����NPC�ļ��ɡ�
9 ��Ʒϵͳ
���ϵͳ����һֱ�Ƚϱ��������������ǵĽ�ɫ�����ϵͳ�Ѿ�
���ڳ���(�������ַǳ���Ҫ���Ǳ�MUD�ľ�������WIZ�뻨ʱ����
�⡣�����ļ���/daemons/char_d.c /daemons/area_d.c �Լ�
/daemons/char_d/ /daemons/area_d/�µ������ļ����������Ǽ�
����Ʒϵͳ���������������֣�
a ��ʳ����
b ��װװ�ײ���
c ��������
d ��ƥ����
e �鼮����
f ���ﲿ��
�ⲿ�ֺ�ս��ϵͳ��HPϵͳ��SKILLϵͳ�зǳ���Ĺ�ϵ����fire
��������ƺ�Э��������
10 ���һ��飬����ս�����������
����һ���ǳ���������������ֹ�ϵ�ǳ����ӵ�һ���֡�������󲿷�
�������Ѿ����ˡ��ڿ����ɡ�


---
����: Fire
��Ŀ: �µ�OBJϵͳ: daemon OBJ
����: Sun Mar 21 04:32:14 1999
Ϊ�˼�ǿOBJϵͳ�Ĺ���������һ���µ�OBJϵͳ��
��Ҫ��daemon �ļ� /daemons/obj_d.c��master OBJ
�ļ����ɡ�ͬʱΪ�˱�����ʦ�Ĺ�����Ҫ����һ��
������ɾ���ģ���Ϊһ���һ�������ߡ�����ּ�
������������һ������µ�daemon OBJϵͳ(��ƣ�
D-OBJϵͳ)��
�ŵ㣺
1 ���ڲ�ѯ
��һ�����ļ�Ϊ������OBJϵͳ�У����Ҫ�������ϵ
ͳ���ж����ֲ�ͬ��ʳ������ֲ�ͬ�Ľ������ס�
����ͨ������һ�������׻ش�����⡣�ر��ǵ�����
���ɢ�䵽��ͬ��·��ʱ���������͸��ѡ�����
D-OBJ�С���ѯ�������ֻ��һ��ָ��Ϳ��Եõ�����
��׼ȷ����Ϣ��
2 ����ƽ�����������
����������Ʒ�Ĳ������洢��һ����daemon���ݿ��С�
���Ӳ�����ƽ���������ǳ��򵥡�
3 �ǳ�����ʵ�����������µ���Ʒ�����ڴ󲿷ֵ�OBJ
��ֻ�����ݿ��е�һ����¼���������ͷǳ����ס����
���������Ʊ��ｫ�ǳ����ס�
4 ��ʦ������clone��Ʒ������Ҫ��·�������ļ�����
ֱ��cl id �����ˡ�
5 ���ļ�����Ҫ��������ƷҲ�᷽����ࡣ
ȱ�㣺
1 ��Ҫ�������ϵͳ����VALUE��inventory, home desc
store and dangpu. keeping 
2 ��ͬ��Ʒ�����ò�ͬ����ID
3 ������Ʒ����Ҫ��ͳ�ļ�OBJϵͳ֧�֡�
���ۣ�
�ڱ�MUD�����ǽ�ͬʱʹ������OBJϵͳ����������OBJ��
�ļ�OBJ���������OBJ��D_OBJ��
����
����Ҫ�Ĺ�����/daemons/obj_d �У���Ҫ�ο��������
master OBJ�ļ�����/sgdomain/obj/foodandrink/woutou.c
��ʦ����������cl ���ƺͲ�ѯ��Ʒ�����µĲ˵���������
������


---
����: Fire
��Ŀ: �µ�OBJϵͳ: daemon OBJ
����: Sun Mar 21 04:32:14 1999
Ϊ�˼�ǿOBJϵͳ�Ĺ���������һ���µ�OBJϵͳ��
��Ҫ��daemon �ļ� /daemons/obj_d.c��master OBJ
�ļ����ɡ�ͬʱΪ�˱�����ʦ�Ĺ�����Ҫ����һ��
������ɾ���ģ���Ϊһ���һ�������ߡ�����ּ�
������������һ������µ�daemon OBJϵͳ(��ƣ�
D-OBJϵͳ)��
�ŵ㣺
1 ���ڲ�ѯ
��һ�����ļ�Ϊ������OBJϵͳ�У����Ҫ�������ϵ
ͳ���ж����ֲ�ͬ��ʳ������ֲ�ͬ�Ľ������ס�
����ͨ������һ�������׻ش�����⡣�ر��ǵ�����
���ɢ�䵽��ͬ��·��ʱ���������͸��ѡ�����
D-OBJ�С���ѯ�������ֻ��һ��ָ��Ϳ��Եõ�����
��׼ȷ����Ϣ��
2 ����ƽ�����������
����������Ʒ�Ĳ������洢��һ����daemon���ݿ��С�
���Ӳ�����ƽ���������ǳ��򵥡�
3 �ǳ�����ʵ�����������µ���Ʒ�����ڴ󲿷ֵ�OBJ
��ֻ�����ݿ��е�һ����¼���������ͷǳ����ס����
���������Ʊ��ｫ�ǳ����ס�
4 ��ʦ������clone��Ʒ������Ҫ��·�������ļ�����
ֱ��cl id �����ˡ�
5 ���ļ�����Ҫ��������ƷҲ�᷽����ࡣ
ȱ�㣺
1 ��Ҫ�������ϵͳ����VALUE��inventory, home desc
store and dangpu. keeping 
2 ��ͬ��Ʒ�����ò�ͬ����ID
3 ������Ʒ����Ҫ��ͳ�ļ�OBJϵͳ֧�֡�
���ۣ�
�ڱ�MUD�����ǽ�ͬʱʹ������OBJϵͳ����������OBJ��
�ļ�OBJ���������OBJ��D_OBJ��
����
����Ҫ�Ĺ�����/daemons/obj_d �У���Ҫ�ο��������
master OBJ�ļ�����/sgdomain/obj/foodandrink/woutou.c
��ʦ����������cl ���ƺͲ�ѯ��Ʒ�����µĲ˵���������
������


---
����: Fire
��Ŀ: �µ�OBJϵͳ: daemon OBJ
����: Sun Mar 21 04:32:14 1999
Ϊ�˼�ǿOBJϵͳ�Ĺ���������һ���µ�OBJϵͳ��
��Ҫ��daemon �ļ� /daemons/obj_d.c��master OBJ
�ļ����ɡ�ͬʱΪ�˱�����ʦ�Ĺ�����Ҫ����һ��
������ɾ���ģ���Ϊһ���һ�������ߡ�����ּ�
������������һ������µ�daemon OBJϵͳ(��ƣ�
D-OBJϵͳ)��
�ŵ㣺
1 ���ڲ�ѯ
��һ�����ļ�Ϊ������OBJϵͳ�У����Ҫ�������ϵ
ͳ���ж����ֲ�ͬ��ʳ������ֲ�ͬ�Ľ������ס�
����ͨ������һ�������׻ش�����⡣�ر��ǵ�����
���ɢ�䵽��ͬ��·��ʱ���������͸��ѡ�����
D-OBJ�С���ѯ�������ֻ��һ��ָ��Ϳ��Եõ�����
��׼ȷ����Ϣ��
2 ����ƽ�����������
����������Ʒ�Ĳ������洢��һ����daemon���ݿ��С�
���Ӳ�����ƽ���������ǳ��򵥡�
3 �ǳ�����ʵ�����������µ���Ʒ�����ڴ󲿷ֵ�OBJ
��ֻ�����ݿ��е�һ����¼���������ͷǳ����ס����
���������Ʊ��ｫ�ǳ����ס�
4 ��ʦ������clone��Ʒ������Ҫ��·�������ļ�����
ֱ��cl id �����ˡ�
5 ���ļ�����Ҫ��������ƷҲ�᷽����ࡣ
ȱ�㣺
1 ��Ҫ�������ϵͳ����VALUE��inventory, home desc
store and dangpu. keeping 
2 ��ͬ��Ʒ�����ò�ͬ����ID
3 ������Ʒ����Ҫ��ͳ�ļ�OBJϵͳ֧�֡�
���ۣ�
�ڱ�MUD�����ǽ�ͬʱʹ������OBJϵͳ����������OBJ��
�ļ�OBJ���������OBJ��D_OBJ��
����
����Ҫ�Ĺ�����/daemons/obj_d �У���Ҫ�ο��������
master OBJ�ļ�����/sgdomain/obj/foodandrink/woutou.c
��ʦ����������cl ���ƺͲ�ѯ��Ʒ�����µĲ˵���������
������


---
����: Fire
��Ŀ: �µ�OBJϵͳ: daemon OBJ
����: Sun Mar 21 04:32:14 1999
Ϊ�˼�ǿOBJϵͳ�Ĺ���������һ���µ�OBJϵͳ��
��Ҫ��daemon �ļ� /daemons/obj_d.c��master OBJ
�ļ����ɡ�ͬʱΪ�˱�����ʦ�Ĺ�����Ҫ����һ��
������ɾ���ģ���Ϊһ���һ�������ߡ�����ּ�
������������һ������µ�daemon OBJϵͳ(��ƣ�
D-OBJϵͳ)��
�ŵ㣺
1 ���ڲ�ѯ
��һ�����ļ�Ϊ������OBJϵͳ�У����Ҫ�������ϵ
ͳ���ж����ֲ�ͬ��ʳ������ֲ�ͬ�Ľ������ס�
����ͨ������һ�������׻ش�����⡣�ر��ǵ�����
���ɢ�䵽��ͬ��·��ʱ���������͸��ѡ�����
D-OBJ�С���ѯ�������ֻ��һ��ָ��Ϳ��Եõ�����
��׼ȷ����Ϣ��
2 ����ƽ�����������
����������Ʒ�Ĳ������洢��һ����daemon���ݿ��С�
���Ӳ�����ƽ���������ǳ��򵥡�
3 �ǳ�����ʵ�����������µ���Ʒ�����ڴ󲿷ֵ�OBJ
��ֻ�����ݿ��е�һ����¼���������ͷǳ����ס����
���������Ʊ��ｫ�ǳ����ס�
4 ��ʦ������clone��Ʒ������Ҫ��·�������ļ�����
ֱ��cl id �����ˡ�
5 ���ļ�����Ҫ��������ƷҲ�᷽����ࡣ
ȱ�㣺
1 ��Ҫ�������ϵͳ����VALUE��inventory, home desc
store and dangpu. keeping 
2 ��ͬ��Ʒ�����ò�ͬ����ID
3 ������Ʒ����Ҫ��ͳ�ļ�OBJϵͳ֧�֡�
���ۣ�
�ڱ�MUD�����ǽ�ͬʱʹ������OBJϵͳ����������OBJ��
�ļ�OBJ���������OBJ��D_OBJ��
����
����Ҫ�Ĺ�����/daemons/obj_d �У���Ҫ�ο��������
master OBJ�ļ�����/sgdomain/obj/foodandrink/woutou.c
��ʦ����������cl ���ƺͲ�ѯ��Ʒ�����µĲ˵���������
������


---
����: Fire
��Ŀ: �µ�OBJϵͳ: daemon OBJ
����: Sun Mar 21 04:32:14 1999
Ϊ�˼�ǿOBJϵͳ�Ĺ���������һ���µ�OBJϵͳ��
��Ҫ��daemon �ļ� /daemons/obj_d.c��master OBJ
�ļ����ɡ�ͬʱΪ�˱�����ʦ�Ĺ�����Ҫ����һ��
������ɾ���ģ���Ϊһ���һ�������ߡ�����ּ�
������������һ������µ�daemon OBJϵͳ(��ƣ�
D-OBJϵͳ)��
�ŵ㣺
1 ���ڲ�ѯ
��һ�����ļ�Ϊ������OBJϵͳ�У����Ҫ�������ϵ
ͳ���ж����ֲ�ͬ��ʳ������ֲ�ͬ�Ľ������ס�
����ͨ������һ�������׻ش�����⡣�ر��ǵ�����
���ɢ�䵽��ͬ��·��ʱ���������͸��ѡ�����
D-OBJ�С���ѯ�������ֻ��һ��ָ��Ϳ��Եõ�����
��׼ȷ����Ϣ��
2 ����ƽ�����������
����������Ʒ�Ĳ������洢��һ����daemon���ݿ��С�
���Ӳ�����ƽ���������ǳ��򵥡�
3 �ǳ�����ʵ�����������µ���Ʒ�����ڴ󲿷ֵ�OBJ
��ֻ�����ݿ��е�һ����¼���������ͷǳ����ס����
���������Ʊ��ｫ�ǳ����ס�
4 ��ʦ������clone��Ʒ������Ҫ��·�������ļ�����
ֱ��cl id �����ˡ�
5 ���ļ�����Ҫ��������ƷҲ�᷽����ࡣ
ȱ�㣺
1 ��Ҫ�������ϵͳ����VALUE��inventory, home desc
store and dangpu. keeping 
2 ��ͬ��Ʒ�����ò�ͬ����ID
3 ������Ʒ����Ҫ��ͳ�ļ�OBJϵͳ֧�֡�
���ۣ�
�ڱ�MUD�����ǽ�ͬʱʹ������OBJϵͳ����������OBJ��
�ļ�OBJ���������OBJ��D_OBJ��
����
����Ҫ�Ĺ�����/daemons/obj_d �У���Ҫ�ο��������
master OBJ�ļ�����/sgdomain/obj/foodandrink/woutou.c
��ʦ����������cl ���ƺͲ�ѯ��Ʒ�����µĲ˵���������
������


---
����: Fire
��Ŀ: ��ƥ�����
����: Mon Mar 22 22:57:33 1999
��ƥ��
level  =  att_abi    value         ����
1           1        100000-       ������С����
2           2        500000-       �Ʊ��������
3           3        1000000-      ������, �ڿ���
4           4        5000000-      ������ս��
5           5        10000000-     ǧ����
------------�����Ǳ���ȫ��unique-----------------------
6           6
7           7                      ��¬
8           8                      ��Ӱ
9           9                      צ�Ʒɵ�
10          10                     ����       

���ƽ����ο�


---
����: Fire
��Ŀ: �µ�OBJϵͳ: daemon OBJ
����: Sun Mar 21 04:32:14 1999
Ϊ�˼�ǿOBJϵͳ�Ĺ���������һ���µ�OBJϵͳ��
��Ҫ��daemon �ļ� /daemons/obj_d.c��master OBJ
�ļ����ɡ�ͬʱΪ�˱�����ʦ�Ĺ�����Ҫ����һ��
������ɾ���ģ���Ϊһ���һ�������ߡ�����ּ�
������������һ������µ�daemon OBJϵͳ(��ƣ�
D-OBJϵͳ)��
�ŵ㣺
1 ���ڲ�ѯ
��һ�����ļ�Ϊ������OBJϵͳ�У����Ҫ�������ϵ
ͳ���ж����ֲ�ͬ��ʳ������ֲ�ͬ�Ľ������ס�
����ͨ������һ�������׻ش�����⡣�ر��ǵ�����
���ɢ�䵽��ͬ��·��ʱ���������͸��ѡ�����
D-OBJ�С���ѯ�������ֻ��һ��ָ��Ϳ��Եõ�����
��׼ȷ����Ϣ��
2 ����ƽ�����������
����������Ʒ�Ĳ������洢��һ����daemon���ݿ��С�
���Ӳ�����ƽ���������ǳ��򵥡�
3 �ǳ�����ʵ�����������µ���Ʒ�����ڴ󲿷ֵ�OBJ
��ֻ�����ݿ��е�һ����¼���������ͷǳ����ס����
���������Ʊ��ｫ�ǳ����ס�
4 ��ʦ������clone��Ʒ������Ҫ��·�������ļ�����
ֱ��cl id �����ˡ�
5 ���ļ�����Ҫ��������ƷҲ�᷽����ࡣ
ȱ�㣺
1 ��Ҫ�������ϵͳ����VALUE��inventory, home desc
store and dangpu. keeping 
2 ��ͬ��Ʒ�����ò�ͬ����ID
3 ������Ʒ����Ҫ��ͳ�ļ�OBJϵͳ֧�֡�
���ۣ�
�ڱ�MUD�����ǽ�ͬʱʹ������OBJϵͳ����������OBJ��
�ļ�OBJ���������OBJ��D_OBJ��
����
����Ҫ�Ĺ�����/daemons/obj_d �У���Ҫ�ο��������
master OBJ�ļ�����/sgdomain/obj/foodandrink/woutou.c
��ʦ����������cl ���ƺͲ�ѯ��Ʒ�����µĲ˵���������
������


---
����: Fire
��Ŀ: ��ƥ�����
����: Mon Mar 22 22:57:33 1999
��ƥ��
level  =  att_abi    value         ����
1           1        100000-       ������С����
2           2        500000-       �Ʊ��������
3           3        1000000-      ������, �ڿ���
4           4        5000000-      ������ս��
5           5        10000000-     ǧ����
------------�����Ǳ���ȫ��unique-----------------------
6           6
7           7                      ��¬
8           8                      ��Ӱ
9           9                      צ�Ʒɵ�
10          10                     ����       

���ƽ����ο�


---
����: Fire
��Ŀ: ��ƥ�����
����: Mon Mar 22 22:57:33 1999
��ƥ��
level  =  att_abi    value         ����
1           1        100000-       ������С����
2           2        500000-       �Ʊ��������
3           3        1000000-      ������, �ڿ���
4           4        5000000-      ������ս��
5           5        10000000-     ǧ����
------------�����Ǳ���ȫ��unique-----------------------
6           6
7           7                      ��¬
8           8                      ��Ӱ
9           9                      צ�Ʒɵ�
10          10                     ����       

���ƽ����ο�


---
����: Fire
��Ŀ: cl �÷�
����: Mon Mar 22 21:59:04 1999
cl ������÷���
cl ��һ��ר��D_OBJ(daemons object)��Ƶ���ʦָ�
����������;:
cl                    ��ʾ������Ʒ�嵥
cl <type|sub_type>    ��ʾ���и�����������Ʒ�嵥��
   ���磺
   cl food            ��ʾ����ʳ��
   cl blade           ��ʾ���е�������
cl <id>               ����һ����Ʒ
   ���磺
   cl shaobing        ����һ�ձ�
Ϊ�����ͻ����Ʒ��ID��Ҫ�����������ͬ������blade,food�ȡ�


---
����: Mimi
��Ŀ: ��������
����: Mon Mar 22 17:31:49 1999
level     att_abi    att_pow   size   value            ����
1          1         1-5       20-80  500-             ����
2          1-2       3-8              2000-10000       �ֵ�
3          1-3       5-10             50000-100000     ��
4          2-4       8-15             200000-500000    ����
5          3-5       10-20            1000000-         ս��
----------------��������Ϊ���ȫ��unique-------------------
6          4-6       20-30              
7          5-7       25-35
8          6-8       30-40                   
9          7-9       35-45
10         10        50                        �����������µ�
��������=size/2


---
����: Fire
��Ŀ: �µ�OBJϵͳ: daemon OBJ
����: Sun Mar 21 04:32:14 1999
Ϊ�˼�ǿOBJϵͳ�Ĺ���������һ���µ�OBJϵͳ��
��Ҫ��daemon �ļ� /daemons/obj_d.c��master OBJ
�ļ����ɡ�ͬʱΪ�˱�����ʦ�Ĺ�����Ҫ����һ��
������ɾ���ģ���Ϊһ���һ�������ߡ�����ּ�
������������һ������µ�daemon OBJϵͳ(��ƣ�
D-OBJϵͳ)��
�ŵ㣺
1 ���ڲ�ѯ
��һ�����ļ�Ϊ������OBJϵͳ�У����Ҫ�������ϵ
ͳ���ж����ֲ�ͬ��ʳ������ֲ�ͬ�Ľ������ס�
����ͨ������һ�������׻ش�����⡣�ر��ǵ�����
���ɢ�䵽��ͬ��·��ʱ���������͸��ѡ�����
D-OBJ�С���ѯ�������ֻ��һ��ָ��Ϳ��Եõ�����
��׼ȷ����Ϣ��
2 ����ƽ�����������
����������Ʒ�Ĳ������洢��һ����daemon���ݿ��С�
���Ӳ�����ƽ���������ǳ��򵥡�
3 �ǳ�����ʵ�����������µ���Ʒ�����ڴ󲿷ֵ�OBJ
��ֻ�����ݿ��е�һ����¼���������ͷǳ����ס����
���������Ʊ��ｫ�ǳ����ס�
4 ��ʦ������clone��Ʒ������Ҫ��·�������ļ�����
ֱ��cl id �����ˡ�
5 ���ļ�����Ҫ��������ƷҲ�᷽����ࡣ
ȱ�㣺
1 ��Ҫ�������ϵͳ����VALUE��inventory, home desc
store and dangpu. keeping 
2 ��ͬ��Ʒ�����ò�ͬ����ID
3 ������Ʒ����Ҫ��ͳ�ļ�OBJϵͳ֧�֡�
���ۣ�
�ڱ�MUD�����ǽ�ͬʱʹ������OBJϵͳ����������OBJ��
�ļ�OBJ���������OBJ��D_OBJ��
����
����Ҫ�Ĺ�����/daemons/obj_d �У���Ҫ�ο��������
master OBJ�ļ�����/sgdomain/obj/foodandrink/woutou.c
��ʦ����������cl ���ƺͲ�ѯ��Ʒ�����µĲ˵���������
������


---
����: Fire
��Ŀ: admire guanfeng
����: Tue Mar 23 21:46:50 1999
guanfeng creat so many great objects
good work guanfeng

addoil all


---
����: Fire
��Ŀ: great work, flee
����: Wed Mar 24 21:32:18 1999
admire flee
addoil
and let's jams make a link from main homepage to here
and we perhaps still need a like from the help to
our main home page
hoho


---
����: Fire
��Ŀ: about the cmd of cl
����: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
����: Fire
��Ŀ: about the cmd of cl
����: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
����: Fire
��Ŀ: about the cmd of cl
����: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
����: Fire
��Ŀ: about the cmd of cl
����: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
����: Fire
��Ŀ: about the cmd of cl
����: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Fire
��Ŀ: about special stuff
����: Thu Apr  1 19:59:31 1999
look zhang fei
�ŷ��������죬С�з��ۣ�����һ����ª�����ӡ�
������ȥ����ʮ���ꡣ
ֻ���ŷɣ�
�ֳ�С��(xiaofu)��
ͷ��Ƥñ(pimao)��
��̤�ҹ����ҹ��Ь(yeguangxie)��
������(buyi)��
����һ����ʦ������(workcloth)�

laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Fire
��Ŀ: about special stuff
����: Thu Apr  1 19:59:31 1999
look zhang fei
�ŷ��������죬С�з��ۣ�����һ����ª�����ӡ�
������ȥ����ʮ���ꡣ
ֻ���ŷɣ�
�ֳ�С��(xiaofu)��
ͷ��Ƥñ(pimao)��
��̤�ҹ����ҹ��Ь(yeguangxie)��
������(buyi)��
����һ����ʦ������(workcloth)�

laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Fire
��Ŀ: about special stuff
����: Thu Apr  1 19:59:31 1999
look zhang fei
�ŷ��������죬С�з��ۣ�����һ����ª�����ӡ�
������ȥ����ʮ���ꡣ
ֻ���ŷɣ�
�ֳ�С��(xiaofu)��
ͷ��Ƥñ(pimao)��
��̤�ҹ����ҹ��Ь(yeguangxie)��
������(buyi)��
����һ����ʦ������(workcloth)�

laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Fire
��Ŀ: about special stuff
����: Thu Apr  1 19:59:31 1999
look zhang fei
�ŷ��������죬С�з��ۣ�����һ����ª�����ӡ�
������ȥ����ʮ���ꡣ
ֻ���ŷɣ�
�ֳ�С��(xiaofu)��
ͷ��Ƥñ(pimao)��
��̤�ҹ����ҹ��Ь(yeguangxie)��
������(buyi)��
����һ����ʦ������(workcloth)�

laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Fire
��Ŀ: about special stuff
����: Thu Apr  1 19:59:31 1999
look zhang fei
�ŷ��������죬С�з��ۣ�����һ����ª�����ӡ�
������ȥ����ʮ���ꡣ
ֻ���ŷɣ�
�ֳ�С��(xiaofu)��
ͷ��Ƥñ(pimao)��
��̤�ҹ����ҹ��Ь(yeguangxie)��
������(buyi)��
����һ����ʦ������(workcloth)�

laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
����: Fire
��Ŀ: about special stuff
����: Thu Apr  1 19:59:31 1999
look zhang fei
�ŷ��������죬С�з��ۣ�����һ����ª�����ӡ�
������ȥ����ʮ���ꡣ
ֻ���ŷɣ�
�ֳ�С��(xiaofu)��
ͷ��Ƥñ(pimao)��
��̤�ҹ����ҹ��Ь(yeguangxie)��
������(buyi)��
����һ����ʦ������(workcloth)�

laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Yuyin
��Ŀ: agree fire and agree yolk
����: Tue Apr  6 03:06:47 1999
addoil fire, addoil yolk


---
����: Yuyin
��Ŀ: agree fire and agree yolk
����: Tue Apr  6 03:06:47 1999
addoil fire, addoil yolk


---
����: Yuyin
��Ŀ: һ����� fight ϵͳ�Ľ��� 
����: Sat Apr  3 03:38:55 1999
���ڵ� fight ϵͳ�Ҿ��Ļ�����û����.
1 �Ҿ���Ӧ�ü�һ����У������ҵġ�����ȡ���
2 Ӧ����ѧһ���书��������Ҫ�ࡣ


---
����: Fire
��Ŀ: an example of the cgi
����: Tue Mar 30 22:47:56 1999
I have modified the 
/WWW/help.html and /WWW/cgi/sg_help.c
so they use the tricky extension of cgi in the 
reference. 

When you code more cgi and html use cgis, please
follow this way.

xixi


---
����: Fire
��Ŀ: about the cgi
����: Tue Mar 30 22:44:43 1999
because in some browser, the extension of .c
is connected with download a c sourcefile or plug in.
so our cgi can not work poparly in all the browsers.
now i have made some change, hope this can solve this
problem.

1 the cgi file still put in the /WWW/cgi/ with the extension
  of .c
2 to reference use /cgi/*.cgi

I have adjust the convert code in http_d.c
  so the daemon will auto replace cgi with c.
  but this will make the browsers feel comfortable
if due with .cgi

hoho

addoil


---
����: Fire
��Ŀ: about the cmd of cl
����: Sat Mar 27 07:15:37 1999
I modified a little about the command of cl
now use cl can see the level of that obj
and also can see the total number of objs
addoil all


---
����: Fire
��Ŀ: the color of chat and weather
����: Thu Apr  1 18:51:47 1999
some players complain that the color for those
two channel too dim, so i changed them to high light color
hoho :)


---
����: Fire
��Ŀ: about special stuff
����: Thu Apr  1 19:59:31 1999
look zhang fei
�ŷ��������죬С�з��ۣ�����һ����ª�����ӡ�
������ȥ����ʮ���ꡣ
ֻ���ŷɣ�
�ֳ�С��(xiaofu)��
ͷ��Ƥñ(pimao)��
��̤�ҹ����ҹ��Ь(yeguangxie)��
������(buyi)��
����һ����ʦ������(workcloth)�

laugh

I think for those special stuff, we can set their level
to -1, so npc will not random pick them up

hoho :)



---
����: Fire
��Ŀ: ��һPOST��һ�����
����: Fri Mar 26 17:45:15 1999
���ڹ�������is_tmp=1
��


---
����: Fire
��Ŀ: great work, flee
����: Wed Mar 24 21:32:18 1999
admire flee
addoil
and let's jams make a link from main homepage to here
and we perhaps still need a like from the help to
our main home page
hoho


---
����: Fire
��Ŀ: �·����׵Ĳ������
����: Thu Mar 25 00:47:32 1999
���� "armors"
level   att_abi     def_pow      size      value    ����
1	 0	     8           20        10000    �ټ�
2       -1           10          50        50000    ����
3       -1           15          60       100000    ͭ�� 
4       -2           18          70       500000    ����
5       -2           20          80      1000000    ���
-----------------------------------------------------------------
6       -1           22          70       �޼�      δ�� 
7       -2           24          80       �޼�      δ��
8       -2           26          80       �޼�      δ��
9       -1           28          50       �޼�      δ��
10      0            30          40       �޼�      δ��
���� "torso"
level    def_pow    size    value     ����
0        1          5       0         ����
0        2          5       1000      ����
1        2          5      10000      �ٷ�
2        3          5      50000      ˿��ٷ�
3        4         10     100000      ����ٷ�
4        5         10     500000      ��쵹ٷ�
5        5         10    1000000      ���� (�����ǹ���)
------------------------------------------------------------------
6
7
8
9  
10     ��ȱ
ͷ�� "head"
level    def_pow    size    value     ����
0        1          5       0         ��ñ
0        2          5       1000      Ƥ��
1        2         10      10000      ����
2        3         10      50000      ͭ��
3        4         15     100000      ����
4        5         15     500000      ���
5        5         15    1000000      ���� (�����ǹ���)
------------------------------------------------------------------
6- 10 ��ȱ
Ь "feet"
level    def_pow    size    value     ����
0        0          5          0      ��Ь
0        1          5       1000      ��Ь
1        1          5      10000      ��ѥ
2        2          5      50000      Ƥѥ
3        2          5     100000      ��ѥ
4        3          5     500000      սѥ
5        3          5    1000000      ��ѥ (�����ǹ���)
------------------------------------------------------------------
6- 10 ��ȱ
���� "brest" ��õ���
���� "arms"  
��ָ "hands"
��װ "legs" ȹ�ӵȣ�
��Щ���Ǳ���ģ�����������ƣ�����ûʲô������;��
��Ҫ����quest�ͷḻ�г���
def_pow    size    value     ����
0-2        5-10       0-100000

�������ƽ����ο���������������µ���Ʒ��
��ϣ����Ʒ������Ҫ��̫��ƫ�롣


---
����: Fire
��Ŀ: ��������
����: Fri Mar 26 00:12:39 1999
maker ����
maker ��һ�ֹ��������������һ��Ь�������������½���������ѵ��ʦ��
����һ�������ɫNPC��(Ҳ��char_d����)�������ɫNPC��������������
������
1 is_maker (int) = 1 ��ʾ�� maker       ���ܸ���
2 is_tmp   (int) = 0 ��ʾ�� �ǽ�ɫNPC   ���ܸ���
3 ask_list (string) ������������������ʲô�����
  ��ȱʡֵ����Ϊ�˶Ի���Ȼ�����ר����ơ�
  ȱʡֵ: $N��$T�������֣�$m����$S���������������Щʲô����\n
4 ask_buy  (string) ����������������
  ��ȱʡֵ����Ϊ�˶Ի���Ȼ�����ר����ơ�
  ȱʡֵ: $N��$T�������֣�$m��$S�����������\n
5 ask_order  (string) ������䶨�����������
  ��ȱʡֵ����Ϊ�˶Ի���Ȼ�����ר����ơ�
  ȱʡֵ: $N��$T�������֣�$m��$S�붨����������\n
6 ask_fix  (string) �������Ҫ���޸Ķ��������
  ��ȱʡֵ����Ϊ�˶Ի���Ȼ�����ר����ơ�
  ȱʡֵ: $N��$T�������֣�$m��$S����м����������ܲ��ܰ�æ��һ�ġ�\n
7 ask_good  (string) �������Ҫ��ȡ�������
  ��ȱʡֵ����Ϊ�˶Ի���Ȼ�����ר����ơ�
  ȱʡֵ: $N��$T�������֣�$m��$S�Ķ���������\n
8 long :  (string) �ù��������
  ��ȱʡֵ����Ϊ����Ȼ�����ӱ仯�����ר����ơ�
  ȱʡֵ: һ����æ������ת�Ĺ�����\n
9 m_ack:  (string array) �ù�����һЩ���⶯���������һ��ƿ�����
��NPC�Ե�������
  �����һ����������Ƴɣ�
  ({
      "$N����󴸣����������ش���������\n",
      "$N����һ��ɽ�������������Ҵ�����ĵ�����һ������������ı�����\n",
      "$N����һ���ոմ��ĵ����޵����õ����õ���\n",
  })
  ���ӵ��������û�����ơ�������ֻ��һ�䣬Ҳһ����������ʽ��
  ȱʡֵ: "һ����æ������ת�Ĺ�����\n"
10 shd_room: (string) �������ڵķ��䡣���û����һ��������ڷ����޷�ȷ����
11 goods: (string array) �ù������������Ķ�����
   �����һ����С�����½��������ǣ�
   ({ "buyi", "changpao",})
12 orders: (mapping) ��Ҷ���ļ�¼����ϵͳ����ά����
����ID����Ϊ��char_d���ƣ�����ÿһ�����˵�ID����Ψһ�ģ�ͬʱ���ÿ
��ID����������ɡ��磺
������(zhang tiejiang)��������(baojian wang)��СЬ��(xiao xiejiang) ..
�ȡ�


---
����: Fire
��Ŀ: ����ϵͳ
����: Sat Mar 27 03:28:04 1999
����ϵͳ��maker system
����ϵͳ��һ����D_OBJϵͳ������ص�����ǽ�ɫNPCϵͳ������char_d
��һ����ϵͳ��������ļ���/sgdomain/modules/m_charnpc/maker.c��
һ�����˾���һ������������Ʒ��NPC�����ľ�����ݿ�����һ���÷죬
һ��Ь����һ��������һ����ʦ����һ��ѵ��ʦ����һ������������
���Խ������»��
1 ������Ʒ�������̵������ƣ������̵�ϵͳҪ���������ºô���
  a ϵͳ֪��ʲô������ʲô�ط������ġ�
  b �����ڳ������������ĳһ���˿���������Ʒ���ࡣ
  c ��a b �����ԣ����Գ������������ںδ��������Ʒ������Ƹ��ӵ�
    JOB
2 ������Ʒ����ҿ��ڽ��˴�ר��Ϊ�Լ�������Ʒ�����Ƶ���ƷҪ�����
  �󣬵���Ϊ��Ϊ�Լ��ض��ģ����Բ����������ܶ�Ҳ���ܸ��ˡ�������
  ���������ߺ�ϵͳ���Զ����ء����仰˵�����ǲ�����һ����Ҷ�һ
  ��(��һ����)��Ʒֻ����һ���Ƕ��ơ�Ҳ����˵������ȶ���һ�����£�
  �»��ֶ���һ�����ۡ���ô���¾Ͳ������ض�������߾Ͳ����Զ���
  �ء�
3 �޸���Ʒ������Ͷ������ƣ��������ڵ���������һ�ѵ�����Ȼ��ϣ��
  �˵�������������ǰ���Ѵ˵���������Լ��Ķ����������ѵ�����
  �߾ʹ��¼��ء���Ȼ���޸���ƷҪ�ȶ��Ʊ���һЩ��
4 �ɶ��Ƶ���Ʒ�͵ȼ���
  �ɶ��Ƶ���Ʒ�����࣬�������¼׺���ƥ(����Ҳ�����鼮��)
5 �ȼ���
  Ŀǰ�Ĺ��оż�(��officer_d)
  ��Ʒ(��������ƥ������Ҳ��11�� 0-10)
  ����(����settle)ֻ�ܶ� 0 ����Ʒ
  1,2 ����Աֻ�ܶ� 1 ����Ʒ
  3,4 ����Աֻ�ܶ� 2 ����Ʒ
  5,6 ����Աֻ�ܶ� 3 ����Ʒ
  7,8 ����Աֻ�ܶ� 4 ����Ʒ
  9��(����) ֻ�ܶ� 5 ����Ʒ
  6-10 ����Ʒȫ�Ƕ�һ�ı��ֻ��ͨ������������á�
6 ��Ʒ����������
  ��Ϊ�У��ͼ���ԱҪ���У��߼���Ա�ٵö࣬��������Ʒ���ʱ��������
  �ͼ������Ʒ��������ÿһ��(������)��Ʒ������������
  0 ����Ʒ 3-5
  1 ����Ʒ 3-5
  2 ����Ʒ 3-5
  3 ����Ʒ 2-3
  4 ����Ʒ 1-2
  5 ����Ʒ 1-2
  6-10 ÿ��0-1�����С�����ÿһ��(������)��Ʒ������Լ��15-30֮�䡣
7 ��������
  ��ͬ��������������ĵȼ������佳����Ŀ���£�
  ��������        ������
  1,2 �غʹ�ׯ    1-2
  3 ����          2-3
  4 �еȳ���      3-4
  5 �����        5-
  ÿһ���˴�Լ������3-5�ֲ�ͬ����Ʒ��(���ÿһ���˶���һ�����ĳ��
  Ʒֻ����������)
8 ���˱༭��(makereditor)
  ���˱༭����һ���ǳ�����򵥵Ľ�����ƹ��ߡ�����ʹ�ð�����
  man makereditor


---
����: Fire
��Ŀ: ���˱༭������
����: Sat Mar 27 03:51:29 1999
1 ��makereditor�������˱༭��
2 ��Ҫ���ܣ�n�����½��ˣ�e�༭���н��ˡ�
3 ����ID�����������֣��м���һ�ո��� yang tiejiang
4 �������ͣ�  
  m)  �༭��������(m) ������ͣ���������
  g)  �༭�����Ա�(g) ȱʡ����
  a)  �༭��������(a) ȱʡ��15-50 ֮���漴
  l)  �༭������ò(l) ���Ǳ��룬����õ������
  r)  �༭��������(r) �������ڵķ��䣬ȱʡ���Ǳ༭���ڵ�һ�����Ӵν���
      ʱ�༭�����ڵķ��䡣�޸�ʱ�����·�����ļ���(����·������������չ
      ������/sgdomain/area/guan/huayin/vzhangda_hu)��һ���޸ķ����Ǳ༭
      ���ȵ�Ϊ�˹���������µķ��䣬Ȼ���ڱ༭��������ʱ����here
  o)  �༭������Ʒ(o) ��������Ҫ��һ�������������һ���Ӳ˵������а���
      ������Ʒ��ɾ����Ʒ���г���Ʒ�ȹ��ܡ�һ����ʾ�������������Ʒ��ID��
      ������༭����һ���Ƶ�����������ڲ��˳��ñ༭����������ã�
      !cl blade �쿴���е����嵥��ע��һ����Ҫ����"!"
  w)  �༭��������(w) 
      ����ʹ�ù�����ʱ��˵һЩ������һЩ���������Ǳ���ĵ��������Ӳ���Ȥζ��
  s)  ���̷���(s)         u)  �����̷���(u)  ���ý�������
5 �ù������֡�
  ���������ڷ��䣬�������û�г��֣��� update here �����ͻ���֣���������
  ������BUG�ˡ�
6 ���й����б�
  �˳������༭�����ã�
  @listchar /1 /v is_maker 1


---
����: Fire
��Ŀ: ��ʦ����
����: Sat Mar 27 03:53:56 1999
һЩ������MUD�йصİ����ı�(����)���ѷ���
/help/wizard/sanguo/ ���»�ӭ��������


---
����: Group
��Ŀ: fire
����: Sat Mar 27 05:47:10 1999
i done letter.c in job/letter directry, please check it, and open it for test.


---
����: Fire
��Ŀ: about the new job of letter
����: Sat Mar 27 07:06:20 1999
group finished a new job, letter.
I think this is not bad.
I modified some code to make the result more simple. 
only a little problem is that this job is called
����, but we don't have an object of letter.
so a little wicked. anyway, this is a new job.
thank group
addoil all


---
����: Yuyin
��Ŀ: agree yolk
����: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
����: Yuyin
��Ŀ: agree yolk
����: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
����: Yuyin
��Ŀ: agree yolk
����: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
����: Row
��Ŀ: >һ�㽨��
����: Thu Apr  8 05:49:47 1999
there is a cmd called plan..u can write ur plan in it, and ur
progress as well.


---
����: Yuyin
��Ŀ: agree yolk
����: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
����: Fire
��Ŀ: about plan
����: Sat Apr 10 21:47:04 1999
wiz can use "man tasklist" to view the plan


---
����: Flee
��Ŀ: permission need
����: Sun Apr 11 03:19:37 1999
i need the permission of /daemons/ and /cmds/
to modify some code .


---
����: Flee
��Ŀ: >> about tasklist
����: Sun Apr 11 03:18:35 1999
agree .. :)


---
����: Fire
��Ŀ: about tasklist
����: Sun Apr 11 02:42:58 1999
>�����׵۹�������������ࡰ���ˡ����������е�
>ˮ�����������й��٣����ӣ����Դ����common
>quest system�����е��˶�����������Ҫ����
������������˼���Ҽƻ��漰����������һЩ����
�е����˿����������ĳһ����
Ȼ����rumor֪ͨ
Ȼ������ҵ���ѧϰ�������ܻ�������һ��Ҫ��
�����ɺ����ͻ�̸����һ��ܡ�
����һ�����ֻ��һ�Σ�ֱ�����´δ��³��֡�
��Щ���˳�����������������ܽ��⣬������ͨͳ�̣ܽ���һ��
��һ��

����������ô����


---
����: Yuyin
��Ŀ: agree yolk
����: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
����: Fire
��Ŀ: about tasklist
����: Sun Apr 11 02:42:58 1999
>�����׵۹�������������ࡰ���ˡ����������е�
>ˮ�����������й��٣����ӣ����Դ����common
>quest system�����е��˶�����������Ҫ����
������������˼���Ҽƻ��漰����������һЩ����
�е����˿����������ĳһ����
Ȼ����rumor֪ͨ
Ȼ������ҵ���ѧϰ�������ܻ�������һ��Ҫ��
�����ɺ����ͻ�̸����һ��ܡ�
����һ�����ֻ��һ�Σ�ֱ�����´δ��³��֡�
��Щ���˳�����������������ܽ��⣬������ͨͳ�̣ܽ���һ��
��һ��

����������ô����


---
����: Yuyin
��Ŀ: agree yolk
����: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
����: Fire
��Ŀ: about tasklist
����: Sun Apr 11 02:42:58 1999
>�����׵۹�������������ࡰ���ˡ����������е�
>ˮ�����������й��٣����ӣ����Դ����common
>quest system�����е��˶�����������Ҫ����
������������˼���Ҽƻ��漰����������һЩ����
�е����˿����������ĳһ����
Ȼ����rumor֪ͨ
Ȼ������ҵ���ѧϰ�������ܻ�������һ��Ҫ��
�����ɺ����ͻ�̸����һ��ܡ�
����һ�����ֻ��һ�Σ�ֱ�����´δ��³��֡�
��Щ���˳�����������������ܽ��⣬������ͨͳ�̣ܽ���һ��
��һ��

����������ô����


---
����: Row
��Ŀ: tasklist
����: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as �趫��), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
����: Row
��Ŀ: tasklist
����: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as �趫��), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
����: Row
��Ŀ: tasklist
����: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as �趫��), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
����: Yuyin
��Ŀ: �ҵ�homepage 
����: Mon Apr 12 08:55:16 1999
�ҵ� homepage has not be connect to our homepage 
wallow please hurry
to connect my homepage
yu-yuyin.163.net


---
����: Row
��Ŀ: tasklist
����: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as �趫��), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
����: Yuyin
��Ŀ: �ҵ�homepage 
����: Mon Apr 12 08:55:16 1999
�ҵ� homepage has not be connect to our homepage 
wallow please hurry
to connect my homepage
yu-yuyin.163.net


---
����: Row
��Ŀ: tasklist
����: Sun Apr 11 10:28:42 1999
i am curruntly responsible for 2-b and i will take 1-a,
when i finish these two, i will try to take more.
ps: i agree with flee that it will not be so realistic
if we have sth such as magic power, but we can make it
thru other ways, i e, change or forcast the weather by
ceremony (such as �趫��), cure urself or increase ur hp
by medicine, but those ji or medicine is not so easy to
learn or get, u may need to finish some difficult tasks or
quests assigned my some special npc as shuijing.



---
����: Yuyin
��Ŀ: �ҵ�homepage 
����: Mon Apr 12 08:55:16 1999
�ҵ� homepage has not be connect to our homepage 
wallow please hurry
to connect my homepage
yu-yuyin.163.net


---
����: Yuyin
��Ŀ: agree yolk
����: Thu Apr  8 01:11:52 1999
agree yolk
addoil fire


---
����: Yuyin
��Ŀ: һ�㽨��
����: Thu Apr  8 01:25:52 1999
����Ӧ�ý�һ��������wiz��¼�����ǵĽ���


---
����: Row
��Ŀ: >һ�㽨��
����: Thu Apr  8 05:49:47 1999
there is a cmd called plan..u can write ur plan in it, and ur
progress as well.


---
����: Fire
��Ŀ: plan
����: Sat Apr 10 21:46:24 1999
�����ܽ������¼ƻ�
1  job system
   ��������13���м�JOB���������ã�������ЩJOB�ڽ����͹��̷���
   ����Щ����������JOB�������¹�����
   a  �򻯳���JOB��ʹ֮���죬����������
   b  �Ľ�landlord���������������JOB
   c  ����������D_OBJ��maker�йص��������JOB
2  NPC��
   �����Ѿ�����101����ɫNPC����31��maker�����Ǵ����Ҫ150����
   ɫNPC��60�����ҵ�maker������NPC�����¹�����
   a  ���ӽ�ɫNPC��
   b  ���ӵ���maker
   c  ����NPC�����ߡ�
   d  ���������NPC(����������)
3  ������ҳ��
   �����������������ܲ����CGI��һ��ͼ��������ҳ��ҳ��������ҳ
   �����¼ƻ���
   a  ����ͼ��棬Ϊ��MUD���һ��ͼ�ꡣ
   b  ���Ӹ����CGI�������������ͼ��ɫ�����ȡ�
4  �������衣
   ���ڸ������Ľ����Ѿ�������ϵ�����һЩ������MAP��������Ҫ��ǿ��
5  ��Ʒϵͳ(D_OBJ)
   ���ڵ�D_OBJ����food, weapon, cloth, drink, horse�������࣬ͬ
   ʱweapon������blade, spear, hammer, sword, ji, axe�����ࡣcloth
   ����armor, brest, torso, head, legs, hands, arms, feet ������
   �ࡣ�ⲿ�ֵ����ݻ���Ҫ��ǿ��
   Ŀǰ�Ѿ�����173����Ʒ��Ҳ����Ҫ200-300����Ʒ��ͬʱ���makers
   ��JOBϵͳ��
   �����迼���µ�OBJ����ҩ��鼮�ȡ�
6  ս��ϵͳ��
   ��MUD��ӵ�һ��ϵͳ�������¹�����
   a ���뵥��
   b �����ı
   c ����ս������������ͳͷ���
   d ����ս����ʽ��
   e �����󷨡�
   f �������ݣ��˱��ȹ��ܡ�
7  ����
   a ���Ӹ��࣬���ḻ��������
   b ����У������ҿ��������ҵ����ʵ�NPC������
8  �µ�ϵͳ��
   a ����ϵͳ(�����ĳЩ���Ͽ��Ի��һ���������㣬����Щ����������
     ��ĳЩ���ܣ���ҿ�����һЩ���������������ƣ���ĳ�أ���������
     �ȣ�Ԥ���������ı������ȡ�
   b �׵۹����׵ۿ��������Һ͵������Ұ������񣬳ɹ�������񣬻�
     ���Ծٰ�����ᡣ
   c �λþ����и����鼮����ҿ���һ����Χ��ѡһ�������ʹ��Ӧ�ĵȼ�
     ��һ���������λþ���������֧�֡�
   d ���һ���
     ���һ��鲻��Ҫ�����п����߼���һ�𣬶���ʹ��һ��ר�ŵĹ���Ƶ��
     �����С�
   e ��ҳ�Ϊ̫��
����WIZ���Ķ��˼ƻ�����ѡ���Լ��Ĺ�����ѡ�ú���POST����POSTһ����ϸ
�ļƻ���лл��


---
����: Fire
��Ŀ: about plan
����: Sat Apr 10 21:47:04 1999
wiz can use "man tasklist" to view the plan


---
����: Fire
��Ŀ: about tasklist
����: Sun Apr 11 02:42:58 1999
>�����׵۹�������������ࡰ���ˡ����������е�
>ˮ�����������й��٣����ӣ����Դ����common
>quest system�����е��˶�����������Ҫ����
������������˼���Ҽƻ��漰����������һЩ����
�е����˿����������ĳһ����
Ȼ����rumor֪ͨ
Ȼ������ҵ���ѧϰ�������ܻ�������һ��Ҫ��
�����ɺ����ͻ�̸����һ��ܡ�
����һ�����ֻ��һ�Σ�ֱ�����´δ��³��֡�
��Щ���˳�����������������ܽ��⣬������ͨͳ�̣ܽ���һ��
��һ��

����������ô����


---
����: Fire
��Ŀ: ����˾��Ľ���
����: Tue Apr 13 11:16:43 1999
��������
1)      ����ս��
        ������ʱ��������У���֣���ΰ����(zhu)�л������������а����
�����н��������ϻ����ټױ����������а�������ȵȶ����ر𾫱���ϣ��
�� Mud ���ܹ�������
���飺
        ����������������ױ���
        ���ڵ���ң����������10���ױ���ֻҪ��һָ��(��װ����)��
ƾ������еļ��ܺͽ�Ǯ����Ҿ��ܸ�װ�Լ���ϲ���Ĳ��ӡ�һ����װ�ˣ���
�ҾͲ����ٸĳ��������ӡ����������ȫ��������ױ���Ȼ�������¿�ʼ��װ
���ӡ�
        ֻ�е��ϳ�͢���٣�������㹻��Ǯ�ͼ��ܣ����ܹ�ѵ����ǿ���Լ�
�ľ��������磺
        ���⾫��        �ر�Ʒ  ��Ҽ���
        У����  ����            ������dodge ����20 ����
        ������  ׿��            ׿�귨������20����
        �����  ����            �����ͻ���ˮ�Ʋ�20 ����
        ������  ��ǹ            ǹ��������20����
        �ټױ�  �ټ�            �����ͻ���ˮ��20����
        ��һ�ж�������(wiz)�ġ����ǿ���� ֻ��Ҫ����õ�ͬ�������Ϳɡ�
        ���У�����ÿ����ҵļ�����5�㣬��������1����
        �����(1 ��)    ��Ҽ��� ����(20) �� ����ˮ�� (20)
        �����(2 ��)    ��Ҽ��� ����(25) �� ����ˮ�� (25)
        �����(3 ��)    ��Ҽ��� ����(30) �� ����ˮ�� (30)
        ���������ˣ���������������������Ҳ��������Ȼ�������ױ���ÿ��
����Ҳ����ͨ�ױ����˺ܶࡣ
        ���ˣ� ��ʱս������ʳ��һ����Ҫ���ݡ�ϣ���´�ս�����������ٺ����ݡ�
2)      ������
        ���ù��ٹ�˾(KOEI)����־5 ���󷨡�
        ����ÿһ��������������󷨡�
        ÿһ�����(NEWBIE JUST LOGIN) һ��ʼ�ͻ�һ���󷨡������ߵ���
�ҿ�        ��WIZ ��Ҫһ���Լ�ϲ�����󷨡�
        ��2 ���󷨿����κ���(NPC OR PLAYER) ѧϰ���� 3
����(������)��       WIZ �Դ������ֻ���ڳ���ս��������ս������
����ս�����鳤��һ��ˮ׼���Ϳ���WIZ ѧϰ��
3)      ����
        �������У����������������ͳ�����Σ������ȶ���һ����ɽ��ˮ��
���й��̣���֪�ܲ��ܰ������е���һ��(JOB)
        (JOB) JOURNEY
        �ر���ƥ����ʳ�����ױ���
        ��Ϸʱ��һ���¡�һ��֪���ظ�����
        �ص㲻���κζ��У���������ʱ��������С�ط�
        ����һ�������Ҵ�ͬ�ױ���ɽ��ˮ�������Լ��ļ��ܡ���ɽ��ˮ
�У���һ�����
        1)      ս������      ��Ǯ����ʳ��            ���ι�����
        2)      ʥ�Ͷ��塣      ʤ��                  ����������
        3)      ���ɽ��        ��ͬ�ױ���ɽ��          
                                �ɹ�                            ����ѧ������
                                                               ���ױ�ѵ����
                                ʧ��                            �����½��ܶ�
        4)      ��ˮ����        ��ͬ�ױ���ˮ            
                               �ɹ�                           
���������ι�����
                               ʧ��                            �����½��ܶ�
        5)      ż��ʥ��        ���ʥ������            ���󷨾���100
                                                               ��������1 �� 
                                                              
(�κμ��ܣ�������
                                                              
WXXY��BFXY OR ZGXY)
                               ���ʥ������            һ����½�1��
        6)      ��̨����        ����ʤ                  ��������������ѧ����
                               ����                            ����ѧ����
        7)      �ν���Ӥ        �ɹ�                            ������ˮ��
                                ʧ��                           
�������ҳϣ�ˮ���½�
       8)      �����ƽ        ��ͬ�ױ����н���å
                               �ɹ�                            ����ѧ������
                                                             ���ױ�ѵ����
                                ʧ��                            �����½�
        9)      ɱ�Ǿ�ͯ        �ɹ�                           
�κ�һ��ܳ�����150
                               ʧ��                           
�����½�                
        ������һЩС���飬WIZ �Ƿ���ã� ȫ��WIZ�������


---
����: Fire
��Ŀ: ����˾��Ľ���
����: Tue Apr 13 11:16:43 1999
��������
1)      ����ս��
        ������ʱ��������У���֣���ΰ����(zhu)�л������������а����
�����н��������ϻ����ټױ����������а�������ȵȶ����ر𾫱���ϣ��
�� Mud ���ܹ�������
���飺
        ����������������ױ���
        ���ڵ���ң����������10���ױ���ֻҪ��һָ��(��װ����)��
ƾ������еļ��ܺͽ�Ǯ����Ҿ��ܸ�װ�Լ���ϲ���Ĳ��ӡ�һ����װ�ˣ���
�ҾͲ����ٸĳ��������ӡ����������ȫ��������ױ���Ȼ�������¿�ʼ��װ
���ӡ�
        ֻ�е��ϳ�͢���٣�������㹻��Ǯ�ͼ��ܣ����ܹ�ѵ����ǿ���Լ�
�ľ��������磺
        ���⾫��        �ر�Ʒ  ��Ҽ���
        У����  ����            ������dodge ����20 ����
        ������  ׿��            ׿�귨������20����
        �����  ����            �����ͻ���ˮ�Ʋ�20 ����
        ������  ��ǹ            ǹ��������20����
        �ټױ�  �ټ�            �����ͻ���ˮ��20����
        ��һ�ж�������(wiz)�ġ����ǿ���� ֻ��Ҫ����õ�ͬ�������Ϳɡ�
        ���У�����ÿ����ҵļ�����5�㣬��������1����
        �����(1 ��)    ��Ҽ��� ����(20) �� ����ˮ�� (20)
        �����(2 ��)    ��Ҽ��� ����(25) �� ����ˮ�� (25)
        �����(3 ��)    ��Ҽ��� ����(30) �� ����ˮ�� (30)
        ���������ˣ���������������������Ҳ��������Ȼ�������ױ���ÿ��
����Ҳ����ͨ�ױ����˺ܶࡣ
        ���ˣ� ��ʱս������ʳ��һ����Ҫ���ݡ�ϣ���´�ս�����������ٺ����ݡ�
2)      ������
        ���ù��ٹ�˾(KOEI)����־5 ���󷨡�
        ����ÿһ��������������󷨡�
        ÿһ�����(NEWBIE JUST LOGIN) һ��ʼ�ͻ�һ���󷨡������ߵ���
�ҿ�        ��WIZ ��Ҫһ���Լ�ϲ�����󷨡�
        ��2 ���󷨿����κ���(NPC OR PLAYER) ѧϰ���� 3
����(������)��       WIZ �Դ������ֻ���ڳ���ս��������ս������
����ս�����鳤��һ��ˮ׼���Ϳ���WIZ ѧϰ��
3)      ����
        �������У����������������ͳ�����Σ������ȶ���һ����ɽ��ˮ��
���й��̣���֪�ܲ��ܰ������е���һ��(JOB)
        (JOB) JOURNEY
        �ر���ƥ����ʳ�����ױ���
        ��Ϸʱ��һ���¡�һ��֪���ظ�����
        �ص㲻���κζ��У���������ʱ��������С�ط�
        ����һ�������Ҵ�ͬ�ױ���ɽ��ˮ�������Լ��ļ��ܡ���ɽ��ˮ
�У���һ�����
        1)      ս������      ��Ǯ����ʳ��            ���ι�����
        2)      ʥ�Ͷ��塣      ʤ��                  ����������
        3)      ���ɽ��        ��ͬ�ױ���ɽ��          
                                �ɹ�                            ����ѧ������
                                                               ���ױ�ѵ����
                                ʧ��                            �����½��ܶ�
        4)      ��ˮ����        ��ͬ�ױ���ˮ            
                               �ɹ�                           
���������ι�����
                               ʧ��                            �����½��ܶ�
        5)      ż��ʥ��        ���ʥ������            ���󷨾���100
                                                               ��������1 �� 
                                                              
(�κμ��ܣ�������
                                                              
WXXY��BFXY OR ZGXY)
                               ���ʥ������            һ����½�1��
        6)      ��̨����        ����ʤ                  ��������������ѧ����
                               ����                            ����ѧ����
        7)      �ν���Ӥ        �ɹ�                            ������ˮ��
                                ʧ��                           
�������ҳϣ�ˮ���½�
       8)      �����ƽ        ��ͬ�ױ����н���å
                               �ɹ�                            ����ѧ������
                                                             ���ױ�ѵ����
                                ʧ��                            �����½�
        9)      ɱ�Ǿ�ͯ        �ɹ�                           
�κ�һ��ܳ�����150
                               ʧ��                           
�����½�                
        ������һЩС���飬WIZ �Ƿ���ã� ȫ��WIZ�������


---
����: Row
��Ŀ: >����˾��Ľ���
����: Tue Apr 13 22:47:16 1999
����˾��Ľ���ǳ��ĺã����������ױ������⣬�Ҽǵ���ǰ��
fire���۹���Ҳ���Ǹ��ױ��䱸��Ӧ��װ�������ʹ���ǳ�Ϊ��Ӧ
�Ĳ��ӣ������ݿ�������һ���м�job������fire˵��ս��Ҳ��
��������ϵͳ��������flee�᳢�Եģ������Ǹ��ǳ���Ȥ����
�飬ֻ����Ŀǰ�ƺ���û��ʱ������ɡ�:)


---
����: Fire
��Ŀ: ����˾��Ľ���
����: Tue Apr 13 11:16:43 1999
��������
1)      ����ս��
        ������ʱ��������У���֣���ΰ����(zhu)�л������������а����
�����н��������ϻ����ټױ����������а�������ȵȶ����ر𾫱���ϣ��
�� Mud ���ܹ�������
���飺
        ����������������ױ���
        ���ڵ���ң����������10���ױ���ֻҪ��һָ��(��װ����)��
ƾ������еļ��ܺͽ�Ǯ����Ҿ��ܸ�װ�Լ���ϲ���Ĳ��ӡ�һ����װ�ˣ���
�ҾͲ����ٸĳ��������ӡ����������ȫ��������ױ���Ȼ�������¿�ʼ��װ
���ӡ�
        ֻ�е��ϳ�͢���٣�������㹻��Ǯ�ͼ��ܣ����ܹ�ѵ����ǿ���Լ�
�ľ��������磺
        ���⾫��        �ر�Ʒ  ��Ҽ���
        У����  ����            ������dodge ����20 ����
        ������  ׿��            ׿�귨������20����
        �����  ����            �����ͻ���ˮ�Ʋ�20 ����
        ������  ��ǹ            ǹ��������20����
        �ټױ�  �ټ�            �����ͻ���ˮ��20����
        ��һ�ж�������(wiz)�ġ����ǿ���� ֻ��Ҫ����õ�ͬ�������Ϳɡ�
        ���У�����ÿ����ҵļ�����5�㣬��������1����
        �����(1 ��)    ��Ҽ��� ����(20) �� ����ˮ�� (20)
        �����(2 ��)    ��Ҽ��� ����(25) �� ����ˮ�� (25)
        �����(3 ��)    ��Ҽ��� ����(30) �� ����ˮ�� (30)
        ���������ˣ���������������������Ҳ��������Ȼ�������ױ���ÿ��
����Ҳ����ͨ�ױ����˺ܶࡣ
        ���ˣ� ��ʱս������ʳ��һ����Ҫ���ݡ�ϣ���´�ս�����������ٺ����ݡ�
2)      ������
        ���ù��ٹ�˾(KOEI)����־5 ���󷨡�
        ����ÿһ��������������󷨡�
        ÿһ�����(NEWBIE JUST LOGIN) һ��ʼ�ͻ�һ���󷨡������ߵ���
�ҿ�        ��WIZ ��Ҫһ���Լ�ϲ�����󷨡�
        ��2 ���󷨿����κ���(NPC OR PLAYER) ѧϰ���� 3
����(������)��       WIZ �Դ������ֻ���ڳ���ս��������ս������
����ս�����鳤��һ��ˮ׼���Ϳ���WIZ ѧϰ��
3)      ����
        �������У����������������ͳ�����Σ������ȶ���һ����ɽ��ˮ��
���й��̣���֪�ܲ��ܰ������е���һ��(JOB)
        (JOB) JOURNEY
        �ر���ƥ����ʳ�����ױ���
        ��Ϸʱ��һ���¡�һ��֪���ظ�����
        �ص㲻���κζ��У���������ʱ��������С�ط�
        ����һ�������Ҵ�ͬ�ױ���ɽ��ˮ�������Լ��ļ��ܡ���ɽ��ˮ
�У���һ�����
        1)      ս������      ��Ǯ����ʳ��            ���ι�����
        2)      ʥ�Ͷ��塣      ʤ��                  ����������
        3)      ���ɽ��        ��ͬ�ױ���ɽ��          
                                �ɹ�                            ����ѧ������
                                                               ���ױ�ѵ����
                                ʧ��                            �����½��ܶ�
        4)      ��ˮ����        ��ͬ�ױ���ˮ            
                               �ɹ�                           
���������ι�����
                               ʧ��                            �����½��ܶ�
        5)      ż��ʥ��        ���ʥ������            ���󷨾���100
                                                               ��������1 �� 
                                                              
(�κμ��ܣ�������
                                                              
WXXY��BFXY OR ZGXY)
                               ���ʥ������            һ����½�1��
        6)      ��̨����        ����ʤ                  ��������������ѧ����
                               ����                            ����ѧ����
        7)      �ν���Ӥ        �ɹ�                            ������ˮ��
                                ʧ��                           
�������ҳϣ�ˮ���½�
       8)      �����ƽ        ��ͬ�ױ����н���å
                               �ɹ�                            ����ѧ������
                                                             ���ױ�ѵ����
                                ʧ��                            �����½�
        9)      ɱ�Ǿ�ͯ        �ɹ�                           
�κ�һ��ܳ�����150
                               ʧ��                           
�����½�                
        ������һЩС���飬WIZ �Ƿ���ã� ȫ��WIZ�������


---
����: Row
��Ŀ: >����˾��Ľ���
����: Tue Apr 13 22:47:16 1999
����˾��Ľ���ǳ��ĺã����������ױ������⣬�Ҽǵ���ǰ��
fire���۹���Ҳ���Ǹ��ױ��䱸��Ӧ��װ�������ʹ���ǳ�Ϊ��Ӧ
�Ĳ��ӣ������ݿ�������һ���м�job������fire˵��ս��Ҳ��
��������ϵͳ��������flee�᳢�Եģ������Ǹ��ǳ���Ȥ����
�飬ֻ����Ŀǰ�ƺ���û��ʱ������ɡ�:)


---
����: Fire
��Ŀ: ����˾��Ľ���
����: Tue Apr 13 11:16:43 1999
��������
1)      ����ս��
        ������ʱ��������У���֣���ΰ����(zhu)�л������������а����
�����н��������ϻ����ټױ����������а�������ȵȶ����ر𾫱���ϣ��
�� Mud ���ܹ�������
���飺
        ����������������ױ���
        ���ڵ���ң����������10���ױ���ֻҪ��һָ��(��װ����)��
ƾ������еļ��ܺͽ�Ǯ����Ҿ��ܸ�װ�Լ���ϲ���Ĳ��ӡ�һ����װ�ˣ���
�ҾͲ����ٸĳ��������ӡ����������ȫ��������ױ���Ȼ�������¿�ʼ��װ
���ӡ�
        ֻ�е��ϳ�͢���٣�������㹻��Ǯ�ͼ��ܣ����ܹ�ѵ����ǿ���Լ�
�ľ��������磺
        ���⾫��        �ر�Ʒ  ��Ҽ���
        У����  ����            ������dodge ����20 ����
        ������  ׿��            ׿�귨������20����
        �����  ����            �����ͻ���ˮ�Ʋ�20 ����
        ������  ��ǹ            ǹ��������20����
        �ټױ�  �ټ�            �����ͻ���ˮ��20����
        ��һ�ж�������(wiz)�ġ����ǿ���� ֻ��Ҫ����õ�ͬ�������Ϳɡ�
        ���У�����ÿ����ҵļ�����5�㣬��������1����
        �����(1 ��)    ��Ҽ��� ����(20) �� ����ˮ�� (20)
        �����(2 ��)    ��Ҽ��� ����(25) �� ����ˮ�� (25)
        �����(3 ��)    ��Ҽ��� ����(30) �� ����ˮ�� (30)
        ���������ˣ���������������������Ҳ��������Ȼ�������ױ���ÿ��
����Ҳ����ͨ�ױ����˺ܶࡣ
        ���ˣ� ��ʱս������ʳ��һ����Ҫ���ݡ�ϣ���´�ս�����������ٺ����ݡ�
2)      ������
        ���ù��ٹ�˾(KOEI)����־5 ���󷨡�
        ����ÿһ��������������󷨡�
        ÿһ�����(NEWBIE JUST LOGIN) һ��ʼ�ͻ�һ���󷨡������ߵ���
�ҿ�        ��WIZ ��Ҫһ���Լ�ϲ�����󷨡�
        ��2 ���󷨿����κ���(NPC OR PLAYER) ѧϰ���� 3
����(������)��       WIZ �Դ������ֻ���ڳ���ս��������ս������
����ս�����鳤��һ��ˮ׼���Ϳ���WIZ ѧϰ��
3)      ����
        �������У����������������ͳ�����Σ������ȶ���һ����ɽ��ˮ��
���й��̣���֪�ܲ��ܰ������е���һ��(JOB)
        (JOB) JOURNEY
        �ر���ƥ����ʳ�����ױ���
        ��Ϸʱ��һ���¡�һ��֪���ظ�����
        �ص㲻���κζ��У���������ʱ��������С�ط�
        ����һ�������Ҵ�ͬ�ױ���ɽ��ˮ�������Լ��ļ��ܡ���ɽ��ˮ
�У���һ�����
        1)      ս������      ��Ǯ����ʳ��            ���ι�����
        2)      ʥ�Ͷ��塣      ʤ��                  ����������
        3)      ���ɽ��        ��ͬ�ױ���ɽ��          
                                �ɹ�                            ����ѧ������
                                                               ���ױ�ѵ����
                                ʧ��                            �����½��ܶ�
        4)      ��ˮ����        ��ͬ�ױ���ˮ            
                               �ɹ�                           
���������ι�����
                               ʧ��                            �����½��ܶ�
        5)      ż��ʥ��        ���ʥ������            ���󷨾���100
                                                               ��������1 �� 
                                                              
(�κμ��ܣ�������
                                                              
WXXY��BFXY OR ZGXY)
                               ���ʥ������            һ����½�1��
        6)      ��̨����        ����ʤ                  ��������������ѧ����
                               ����                            ����ѧ����
        7)      �ν���Ӥ        �ɹ�                            ������ˮ��
                                ʧ��                           
�������ҳϣ�ˮ���½�
       8)      �����ƽ        ��ͬ�ױ����н���å
                               �ɹ�                            ����ѧ������
                                                             ���ױ�ѵ����
                                ʧ��                            �����½�
        9)      ɱ�Ǿ�ͯ        �ɹ�                           
�κ�һ��ܳ�����150
                               ʧ��                           
�����½�                
        ������һЩС���飬WIZ �Ƿ���ã� ȫ��WIZ�������


---
����: Row
��Ŀ: >����˾��Ľ���
����: Tue Apr 13 22:47:16 1999
����˾��Ľ���ǳ��ĺã����������ױ������⣬�Ҽǵ���ǰ��
fire���۹���Ҳ���Ǹ��ױ��䱸��Ӧ��װ�������ʹ���ǳ�Ϊ��Ӧ
�Ĳ��ӣ������ݿ�������һ���м�job������fire˵��ս��Ҳ��
��������ϵͳ��������flee�᳢�Եģ������Ǹ��ǳ���Ȥ����
�飬ֻ����Ŀǰ�ƺ���û��ʱ������ɡ�:)


---
����: Fire
��Ŀ: ����SGSYS
����: Fri Apr 16 00:03:55 1999
����SGSYS
  SGSYS��һ���ǳ�����ļ�س��������ڼ��ĳЩ���в��֡�
  ������ڵ����İ�����ѵ����ʿ�������ǿ���ǿ�������ֵ��
  200���������ǿ��ܲ���ע�⵽ĳЩʹ��ֵͻ�ɵ�BUG����ˣ�
  ��ϵͳ�м�����һ�䣬����ֵ�������ֵ������ǿ����Ϊ���
  ֵ��ͬʱ��SGSYS����������WIZע�⡣ע��������һ������
  �ĳ�ֵ����һ��BUG��
SGSYS���÷���
  �ڳ�����ֱ�Ӽ��ϣ�
  SGSYS("���ѵ�����");
���ӣ�(ѡ�� /daemons/area_d.c)
	case "train":
	case "morale":
	case "safe":
		if(para_value>200) {
			SGSYS(sprintf("%s��%s���ߣ�ֵΪ:%d����ǿ��Ϊ200",p_id,para_name,
			para_value));
			para_value=200;
		}
       areas[p_id][para_name]=para_value;
       p_ret="�����������óɹ���\n";
       break;

ִ�н����
  ��ϵͳ��������أ�xianyang��safe���ߣ�ֵΪ:300����ǿ��Ϊ200
���ԣ�/daemons/area_d


---
����: Flee
��Ŀ: agree fire
����: Sun Apr 18 01:08:11 1999
i feel that the basic job is even
harder than middle job, it surely make
new players hard to start.


---
����: Fire
��Ŀ: about current job
����: Sat Apr 17 20:32:41 1999
ʲô�ǵ�ǰ����ȵĹ�����
    ��MUD�ӿ�ʼ�����������Ѿ��������ˡ������ڻ�������ʽ�������
������˵��һ�����ҡ����ڣ�����Ϊ�������Ϸ�гɳ������ѻ������߱�
�ˡ���������Ŀǰ����Ҫ�ĺ��Ĺ�������ɱ��벿�֣��Ż����в��֣���
���������Ų��֡�Ȼ��ʹ��MUD���翪�š�����ҽ�������ƻ����µ�
�ƻ�����£�
1   ĿǰΨһ����Ľϴ���µ�ϵͳ�ǹ��һ��飬�����Ѿ����˹���Ƶ��(na)
    ���һ��齫�ڹ���Ƶ���н��С����һ������Ҫ�������ڵ���������
    �������ʵȡ��⽻��Ȼ��Ȥ�������Ǳ���ġ���ʽ���ź��ڿ��ǡ�
2   Ŀǰ��ս���Ѿ��ǳ����ӣ������кܶ�Ǳ��BUG������Ϊ����ս������
    ǰֻ�ų�BUG���Ż���ʽ�����NPC����(�����Ƿ��ط�NPC����)��AI��
    ���ڼ�ı���󷨣�˽�˱��������ֱ��֣������ͱ�������������һ��
    �Ƴٵ���ʽ���ź�
3   ���е�JOB��QUEST(��Ӿ�����)�ȣ�ȫҪ����һ�£��޳�BUG������
    HELP�ļ���
4   ���Ż��������ߵ�������Ҳ����Ŀǰ����Ҫ�Ĺ��������ǵ�MUD�Դ�
    �������ֶ�̫�����ѡ�û����ʦ�����ֵİ������ܶ໹û�����Ǿ�֪
    �Ѷ����ˡ������������������������������һ����Ҫԭ���ر���
    POST��һ���Ǿ���500+POST��˭�ܿ��ꣿ
5   �ḻJOB���࣬����D_OBJ���Ǻ���������������JOB�ġ�
6   �����Ż���������19���������󲿷ֶ������ˣ���������ЩС���⡣
    �еĵ���û��˯���ĵط����е�û�й�ˮ�õط����͵�ͼ��һ�µȡ�
    �ҽ���ÿ��WIZ��������������������Щ���⡣��֤�����Ļ������衣
    ��֤�����ͼ��һ�¡�(�ҽ��������������ͳ������ء�)
7   ��ҳ��һ��Ҫ�á�����CGI�����ĸ��¾Ͳ���̫��������ˡ�
��ҿ�����ʲô�����


---
����: Guanfeng
��Ŀ: none
����: Sat Apr 17 17:34:59 1999
���޳ɶ���ֵĽ���,�����Ҿ��ÿ������Ӹ�����֮��������job
Ѻ������ٲſ��Ե��Σ������ľţ�������Դ���ʡ������ʱ��

�Ĺٺ���ٵ�jobӦ�ø�����ɫ����Ҫ̫����ͬ


---
����: Fire
��Ŀ: >��ս�����ӵ�һ�����顣
����: Sat Apr 17 04:41:58 1999
�е���
xixi :)


---
����: Group
��Ŀ: ��ս�����ӵ�һ�����顣
����: Sat Apr 17 04:39:43 1999
��֪����������ս�������ˡ������Ϸû�У��������Ǿ���
�����Ϸ�й��ڱ��ֵ��趨ֵ�������������á�����ģʽ����
�������ģ����б�һ���������������������������Ϊ������
�����������Ϊ���������������Ϊ�������������������
���ֵķ�չ����һ�ֿƼ��������ǿ���ͨ��������ֿƼ�����
��������ɷ�չ�Լ��ı��֡����ֱ���Ӧ���ɸ��ԵĶ����ļ�
�����ƣ������������������������ֵ��ζ�������Ӱ�죬�Լ�
ı�ĵֿ���������֮�������ԣ�ͳ���������������������
���󷨡������ȵȡ��������ڹ���Ҳ���ڷ�չ�����⣬��Щ
���в�����Ƴ�Ϊ���ر���֣����������������ҵ�ķ���
ˮ�������������󹭱��ȵȡ�����������������������һ��
����ϵͳ�����������������Ϳ����Զ����и��������������
ʹ���ע�⵽��ս��֮��ķ�չ���֣�ʹ��Ϸ���ж�������
�������ۡ�


flee, group.


---
����: Row
��Ŀ: 1 suggestion
����: Wed Apr 21 03:05:19 1999
���������ÿ�����ߵ�ʱ������յ���Ϸ���䲻����
��һЩ��Ϣ��������¼��еĹ��ҽ�����������ĳ��
��ĳ��ռ��ȵȣ�������ʦ����Ϸ���ֵ��޸ģ�ʡȴ
����ҿ�post���鷳��
����ʦ�������߾����յ�ĳĳ����Ϸ�ĸĶ��ȵȣ���
������ͬ����ʽ��ϵͳ��Ϣ�Զ�����������ʦҲ�ɱ�
д��Ϣ����

�����Ϊ��Σ�


---
����: Flee
��Ŀ: agree row 
����: Wed Apr 21 04:59:26 1999
as title.


---
����: Fire
��Ŀ: >1 suggestion
����: Wed Apr 21 23:04:07 1999
On Wed Apr 21 03:05:19 1999 Row wrote post #346:
> ���������ÿ�����ߵ�ʱ������յ���Ϸ���䲻����
> ��һЩ��Ϣ��������¼��еĹ��ҽ�����������ĳ��
> ��ĳ��ռ��ȵȣ�������ʦ����Ϸ���ֵ��޸ģ�ʡȴ
> ����ҿ�post���鷳��
> ����ʦ�������߾����յ�ĳĳ����Ϸ�ĸĶ��ȵȣ���
> ������ͬ����ʽ��ϵͳ��Ϣ�Զ�����������ʦҲ�ɱ�
> д��Ϣ����
> 
> �����Ϊ��Σ�

good idea, will add it



---
����: Row
��Ŀ: >һ�����
����: Fri Apr 23 23:55:30 1999
ȷʵ����ȱarea��yuyin�Ƿ���Բ���map southwest�����е�
cities�ӳ��У�������ð�southwest�ĵ�ͼ��������ʱ�ڵ�ͼ
��������ȫ��
addoil yuyin


---
����: Yuyin
��Ŀ: һ�����
����: Fri Apr 23 23:50:14 1999
�Ҿ������ڵ� npc �Ѿ��㹻��,
��Ϊ�������ڶ��˲��ٵ� player
������һ���Ǿ���ʮ����ʮ����������
������������Ӧ�ð� system ����,
��Ϊ���ڵ� area ����,�� area �����Ժ�,�ټ� npc ������
addoil fire
addoil row
addoil flee
addoil swallow


---
����: Row
��Ŀ: some player's suggestion
����: Fri Apr 23 01:24:55 1999
1. suggest to make cmd call/(6) functional, but it will cost
u more money compare with findbody thru boy.
2. suggest to add "ban war" in "pos" menu, a taishou should
be about to ban his officer to declare war to others when
he is offline, but may only last for few hours.


---
����: Fire
��Ŀ: for makers
����: Thu Apr 22 08:09:56 1999
please use "cl list" to check obj maker information


---
����: Row
��Ŀ: checking typo under /help/player/sanguo/
����: Thu Apr 29 01:49:04 1999
as title.


---
����: Fire
��Ŀ: about OBJ and MAKER
����: Wed Apr 28 04:28:49 1999
����OBJ��MAKER
wizard �� check <obj_id> ���Է�������Щ������������
��OBJ��ͬʱ�� cl list ��makereditor �е�list ���ܿ���
�г�OBJ��MAKER�Ķ�Ӧ��ϵ����Щ�����԰�������ƽ������
�Ĺ�ϵ��
�����м�������ԭ��
1 ֻ�еȼ�0-5����Ʒ�ɱ���������
2 һ��������������Ʒ��������7
3 ÿһ��0-5������Ʒ������һ������������
4 ��Ʒ�ȼ���������������Ķ�Ӧ��ϵ
   ��Ʒ�ȼ�     ��������������������    ȫ��������������
   0            3-5                      8-15
   1            2-5                      8-15
   2            1-4                      6-10
   3            1-4                      4-8
   4            1-2                      4-6
   5            0-1                      1-3
�������ǿ�Ϊ��ҷ��䲻ͬ�Ѷȵ�JOB
xixi:)


---
����: Fire
��Ŀ: the bug of random emote for a on line players
����: Wed Apr 28 00:43:59 1999
has been fixed.
it is in the ev_randdisapp.c
because now I use a new method to judge online or
not so that the old filed "status" in char_d
is obsoluted

xixi

thank row


---
����: Row
��Ŀ: typo
����: Tue Apr 27 03:27:06 1999
i checked all files under /sgdomain/event/, anybody who
wanna change those files, pls download b4 upload. thx.


---
����: Row
��Ŀ: files under /sgdomain/cmd/ checked over
����: Tue Apr 27 04:46:21 1999
as title.


---
����: Row
��Ŀ: idea
����: Wed May  5 03:55:58 1999
Ŀǰ�ĳ���ϵͳ��flyroom��meetingroom�����˽�����
����һ��goroom��ר��Ϊ���������ģ�Ҳ���ǿ���ƥ����
վ����ĳһ���е���ҡ����goroomһ�����ڳ��⣬��Ϊ
���ǵ����������Ѷȣ���ҽ��������������������أ���
����goroomͨ���õصĵ�·�����������Զ������ҶԸ�
�����Ѻó̶ȣ�������ĳֵ��������У�����ʱ������ٶ�
��ѡ��ɱ������������������Ŷ������¸����������ֵ����
��������������ֵ�����Ի��������ٰ�ù���ʿ���룬������
��һ��αװ���ܣ��ȵȣ���Ȼ�����ǰٷְٳɹ��ġ�����һ
����job���Ѷ������ˣ����˷�չ���ٶ�Ҳ�������֮���ˡ�

��λ��Ϊ��Σ�


---
����: Row
��Ŀ: some change
����: Wed May  5 04:55:39 1999
for the convenience of coding, i moved yizhan files
to /sgdomain/yizhan/...


---
����: Fire
��Ŀ: about the new areas
����: Wed May  5 23:27:52 1999
now we have about 24 new areas in southwest.
please don't touch them now. I will create a tool
to auto set all the basic things for them. when I finish it (perhaps
today or tomorrow) then I will post here.
addoil


---
����: Fire
��Ŀ: about board
����: Thu May  6 10:32:49 1999
I adjust sth in the news system.
1 for many not very useful groups, I put all the messages to the
  archie and then remove those groups.
2 for the most frequent news group such as caolu and wiz.com, I
  set the archie time as 90 days, (caolu 30 days) this means any
  message in these group post certain days before will be moved
  to the archie, this will save us a lot memory
3 make news command as wizards command
4 each country will automacally has its own group and the board
  put on every meeting room
5 some change for player's board, detail see help board.


---
����: Group
��Ŀ: ��������
����: Fri May  7 10:00:02 1999
�����Ѿ���ɣ����ʱ�����ǽ�����й�ս����һ���ָ���
���幤���ƻ����£�
1�� �Ľ�TROOP_D ʹ����Ӧ���µĲ���ϵͳ��
2�� ��ɸ��ֱ��ֵ�����Լ�������п����ı��֡�
3�� ������ֵ�����������ɺ�POST�����Թ����ۡ�
4�� ��ɸ��ּ�ı����ɺ�POST������ơ�
5�� ��ɸ������Լ���Բ��ӵ�Ӱ�졣
6�� �������ʱ�䣬�����һЩ�Ͳ����йصĸ���������

���������Ļ�����ӭPOST��

flee, group


---
����: Fire
��Ŀ: >��������
����: Mon May 10 20:06:29 1999
On Fri May  7 10:00:02 1999 Group wrote post #362:
> �����Ѿ���ɣ����ʱ�����ǽ�����й�ս����һ���ָ���
> ���幤���ƻ����£�
> 1�� �Ľ�TROOP_D ʹ����Ӧ���µĲ���ϵͳ��
> 2�� ��ɸ��ֱ��ֵ�����Լ�������п����ı��֡�
> 3�� ������ֵ�����������ɺ�POST�����Թ����ۡ�
> 4�� ��ɸ��ּ�ı����ɺ�POST������ơ�
> 5�� ��ɸ������Լ���Բ��ӵ�Ӱ�졣
> 6�� �������ʱ�䣬�����һЩ�Ͳ����йصĸ���������
> 
> ���������Ļ�����ӭPOST��
> 
> flee, group

good, good

just a little suggestion:

1 make the defence part a little strong than the attack part

2 be careful no obvious bug the player controled troop too superior
to npc troops

addoil

:)


---
����: Fire
��Ŀ: about the change of troop_d.c
����: Wed May 12 02:06:45 1999
hi flee,

Isugggest that you just modify the original troop_d at it's original location
 because i may change it too. if we have two copy, we may cover each
other and caouse conflict.
and because you are not familiar to the troop_d.c
so when you add sth, add the comment on the function or centance you
added. if you remove or modify some
sentence, also make comment so if got confilct, easy to locate and
change back. 
addoil flee


---
����: Flee
��Ŀ: to fire, about troop_d
����: Tue May 11 23:40:17 1999
i have read the original troop_d and change it a 
little bit, i put the new one under /wiz/flee/
troop/troop_d.c. there are tow featuer i made
first is adding a function called recover energy
instead using warai_d. second is when remove troop
because now troop have many types.
I just found that even testing the new troop_D is 
very difficult, cos too many daemons interact with it .. :(
please have a look.


---
����: Row
��Ŀ: war has bug?
����: Thu May 13 23:50:40 1999
i put war.c as war.bak now, so that banned war, pls check for the bug

if war a 0 soldier, or 0 npc area, will auto lose however u have more soldiers


---
����: Fire
��Ŀ: about the board of newbie
����: Wed May 12 23:09:51 1999
the board for newbie will be only used to give
some very nice organized help files, so for general
post, please post in the caolu board.

xixi:)

thanks



---
����: Group
��Ŀ: �����б�
����: Wed May 12 23:36:57 1999
��������֮�б�����ɣ���/WIZ/GROUP/TROOPS �¡��ļ���
ΪUPGRADE��UPGRADE1�������Ǹ���ҿ��ġ�


---
����: Group
��Ŀ: shutdown
����: Mon Jun 14 03:10:11 1999
system shutdown 2 times for no reason. 

please check.
group


---
����: Fire
��Ŀ: the color welcome file
����: Sat Jun 12 02:47:44 1999
ice and i create a new color welcome page
now I put it under /sgdomain/txt/welcome/WELCOME.txt

this is our mud's face, so welome any suggestion and
discussion


---
����: Fire
��Ŀ: reboot without any reason
����: Fri Jun 11 22:44:15 1999
����ʱ��                ��ʮ��������ʮһ������ʮʱ��ʮ����
����������              ��ʮ��������ʮһ������ʮʱ��ʮ����
��������ʱ��Ϊ          ��ʮ������
> ��ϵͳ�������ƽ���������

say crush ?
say i just reboot several mins before

then it reboot without and message, crush or ?


---
����: Ice
��Ŀ: about ������
����: Sat Jun 12 12:50:13 1999
if a king travel around in his nation and set all black list in cities,
then seems a little bit ����? 


---
����: Fire
��Ŀ: ����ice�Ľ���
����: Mon Jun 14 09:07:32 1999
ice ������һ���ǳ�ȫ��Ľ��飬���д����ԡ�
��ʹ����������ǰ��һЩPOST����඼�кܶ�����˼����ơ�
�����ź���������Ŀǰ�����������ޣ�������ཨ�鲻������
ʵ�֡���ʵ�Ⲣ����һ���������е����⣬����KOEI��������
ÿһ�嶼��Щ��������Ҳ����ȥЩ������������ȫ�İ汾��û�еġ�
���뿪������������ʱ�������Ҳ��һ�����ء�


��������˵���ǣ����ǲ�����������һ��ʮȫʮ�������������MUD��
���Ǳ���ѧ����ȡ��Ŀǰ����汾���������Ѿ��൱�ḻ��
֮Ҫ����һЩ�������Ͳ���ϵͳ�Ĳ������ƣ��Ϳ��Գ�Ϊһ��������MUD��
���ⲻ�������ǾͲ�������Щ�µģ�����˼��ϵͳ��������Ŀǰ
����Ҫ�������ǣ�
1  ����BUG
2  �����Ŀհ�
3  ����һЩ�����͹�ʽ��ʼ��ƽ�⣬����
4  �ĵ��ͽ����������
5  Ҳ�ɿ���һЩ��Զ����ģ���Ȥ����ơ��磺���ѣ��������

�����Щ�����ǾͿ�����ʽ�����ˡ�����Щ���ӵģ���Ȥ����ƿ��Էŵ���һ��
�汾��


˵����ô�࣬����Ҫ�������ǣ��ų�BUG :)


---
����: Flee
��Ŀ: >> agree fire
����: Mon Jun 14 09:44:07 1999
agree with fire .. :)
there r many many thing we can use, but for
now, the most important thing is bug-fix and
make formular more reasonable.
of cos, any comments, suggestion and plan are  
welcomed anytime .. :0
addoil all.


---
����: Row
��Ŀ: >>> agree fire
����: Mon Jun 14 11:41:58 1999
On Mon Jun 14 09:44:07 1999 Flee wrote post #501:
> agree with fire .. :)
> there r many many thing we can use, but for
> now, the most important thing is bug-fix and
> make formular more reasonable.
> of cos, any comments, suggestion and plan are  
> welcomed anytime .. :0
> addoil all.

anyway, i really hope that the new combat sys i
discussed w/ flee can be create in the first version.
addoil all.


---
����: Row
��Ŀ: new bug in war?
����: Thu Jun 10 23:15:28 1999
the troop's morale become 0 when in battle field...
what happened...flee or fire pls check,
fire, is that becoz of u changed commando's file?


---
����: Row
��Ŀ: ͳһ��
����: Thu Jun 10 08:29:29 1999
���Ѿ���cdd ���Э�飬����ʱ������wdoll��derek��cnl��
��ͳһȫ�������Ҹ��˴�Ӧ�����������ڣ��������ľ�����
��֪�Ƿ�õ���ҵ��Ͽɡ����ԣ�����Ϊ���ڲ����޸��κ�
�����ݣ��ؼ����������ʱ���ص㿼��һ��ս����������
ƽ���ϵ���޸�bug ������ϵͳ�����һ��Ŭ��ѽ��


---
����: Fire
��Ŀ: ��������
����: Thu Jun 10 07:23:05 1999
������������MUD��POST��һ�±�MUD��һЩ����POST
��ֻ�᲻�ᱻɾ����Ҳ��֪�᲻����Ч����:)


---
����: Fire
��Ŀ: bug ?
����: Thu Jun 10 06:53:24 1999
today i tested the train and find two thing strange
1 �һ����һ����
���д󽫣�
�һ�����������ա��һ��ֺٺ�(fire)
�һ��������ٻ��ڣ��ְ���(mimi)
 ���֡�  ������ ѵ��  ʿ����������
 �±�     712    45     0    11 

how the morale becomes 0 ?

2 when i look find the enemty troop display as D
it should be A

strange
strange


---
����: Fire
��Ŀ: �����ƶ����Ĳ�����
����: Thu Jun 10 06:45:41 1999
һ֧�������Ļ�������30����һ���ƶ���Ҫ����20
������ͬʱ��ˮ������22��ƽԭ����20���������Ҳ̫С��
:)


---
����: Row
��Ŀ: ����ּ�
����: Mon Jun  7 22:40:53 1999
Ϊ��ʹ����־�����ʵ�ķ���չ���ҽ���ʵ�������
�ң�Ҳ�������Ҫô���ģ�Ҫô���䣬�����ٵ�Ҳ����
��������ͬ�ķ�չ��·��

��Ϊ�����������У�����˫ȫ������ʵ���Ƿ�ë�۽ǣ�
��֮���٣�������Ŀǰ���ǵ���ң������϶��Ǳ�����
������ѧ������ͷ���������ڲ��õĽ�������������ı
����90���ϵĹ�Ա�洦�ɼ������˶��Ƕ����֣�������
������ս������ɱ�У����ܿ�����������ʩ��ı������
�������ϡ�

�����ҽ��齫ϵͳ���¶���һ�¡�Ŀǰ�츳���Ƽ��ܵ�
���Ĺ��ܱ�������ѧ������Ӧ����������ٵ���������
����Ҫ�������󣻱���������Ӧ��ı�����Ĺٵ�������
�ݼ���Ҫ�������󣻶��ι�������Ӧ�����������Ĺ�Ҳ
����ٵ��������ݼ�����������ѧ���ι������ﵽ31
���Ϳɵ���٣����������ι������ﵽ31���Ϳ��Ե���
�١��ڴ˱���Ҫ������ҵ��ǣ�������٣����ñ���
��������Ļ��Ὣ����٣������������������軨�ѵ�
����Ҳ������������ѧ�������ı����Ĺٵ����Ҳ��һ
�������ι�����û�����ơ�

��Ȼ������������˼ң���ô����ϵͳ��Ҳ��Ҫ�ּҡ�
�Ĺ������Ĺ�������������Ĳ�ͬ���Ĺ���Ҫ��������
��������ٴ����������̣���Ѱ�����ˡ���˵�н��ȹ�
����Ҫ�ǿ������ĸߵͣ����߶������������������ʵ
��Ŀ����ȷ�����������������ľ��档

��������ս����Ϊ�˹�ƽ��������ǿ��Խ�������˼��
��ı����Ҳ��һ�¹���Ҳ����˵���Ĺ�����ļ�ı����
������Ĳ�ͬ���Ĺٵļ�ƫ��������磺���ԡ�����
�ȵȣ���ٵļ�ıƫ���ڸ���һ·���磺���衢�ܷ���
�ȣ���һ��ļ�ı���ơ�ˮ�ơ���ʯ�����������µ�
��ֻҪ�ⲿ�������������Ա�Կ�ʹ�á����佫�е�
������Ȩ���Ĺ����������ı�ı��¡���ˣ���ս����
Ҳ����ʵ�������������ͬɱ�еľ����ˡ�

���������ϣ��������۲��������ơ�


---
����: Fire
��Ŀ: >about history_d.c
����: Mon Jun  7 19:48:24 1999
On Mon Jun  7 00:24:53 1999 Row wrote post #478:
> ���ڵ�history�����Ǻ�����������ʾ�������ƺ���̫
> ���Ķ����Ⱥ�˳���ǲ��Ǹ�Ϊ�����緢����������ʾ
> �ȽϺ�һ�㣿

support row ;)


---
����: Group
��Ŀ: about emperor
����: Mon Jun  7 01:35:19 1999
fire, it seems emperor still cant be refreshed when the system
reboot, p check it..:)

group


---
����: Stefan
��Ŀ: suicide
����: Tue Jun  8 02:25:15 1999
command suicide now works. I moved it from /sgdomain/cmd/ to /cmds/player
and it is the USER_D that handles the suicide, there is no longer a 
SUICIDE_D. 


---
����: Flee
��Ŀ: >>����ּ�
����: Tue Jun  8 03:23:32 1999
agreed.
classify officers to two type, each of them
have their own goodpoints and shortpoints.
so the only way to success is coorpation
this will be our game more intresting and attrative.


---
����: Ice
��Ŀ: about soldier amount after war
����: Tue Jun  8 18:30:06 1999
luoyang has 38k b4 war, and because liyu just used 1 soldier to 
defend, after war, there are still 38k soldier in luoyang,
pls notice this problem when fire and flee check the war files
8O~~


---
����: Fire
��Ŀ: >about soldier amount after war
����: Tue Jun  8 20:14:57 1999
On Tue Jun  8 18:30:06 1999 Ice wrote post #485:
> luoyang has 38k b4 war, and because liyu just used 1 soldier to 
> defend, after war, there are still 38k soldier in luoyang,
> pls notice this problem when fire and flee check the war files
> 8O~~

this bug fixed


---
����: Fire
��Ŀ: two systems of troop types
����: Tue Jun  8 20:47:59 1999
I examed group's code and find it hastwo systems
1 is that we just recruit footman and under certain condition
  it can updated to  other types of troop and other type can continue update
2 the second system is that we can recruit certain type of troops
  in certain area.

both systems are good, but we will mainly stick on the first
system and the second system will be considered later.


---
����: Group
��Ŀ: about upgrade
����: Wed Jun  9 02:26:44 1999
there actually only got 1 system
all troops recruited will be footman, and when it's morale and train
increased,
and there are enough equip to use, they can upgrade to 2nd level troops.
same as 3rd type. 
but for 4th level troops, they are limited by some area. that means
the 3rd level troops which can be only upgraded in certain city.
we set the special cities all around the whole map to ensure the balance. 
this is the way to limit the number of most powerful troops.

if got other quetions, please post it..:)

group


---
����: Group
��Ŀ: about the move 
����: Fri Jun 11 09:10:45 1999
actually the difference of the moving consuming is dependent on troop types,
and since there are quite a number of troops and we design that higher troops
should be better than lower troops, there are some unbalance about
the moving consuption.
and now the recover mostly dependent on the morale and train, which
makes the troops recover very fast.
fire, you can just balance the consuption as well as the recover to
a reasonable speed, and which can show the different advantages for 
different troops.

actually i think maybe use 100 as the up limit maybe better, since
can have more difference between troops. 

hope can see the upper level troops moving in the war...:P

addoil..:)
group


---
����: Flee
��Ŀ: >>about history_d.c   
����: Mon Jun  7 01:00:17 1999
changed.
..


---
����: Row
��Ŀ: about history_d.c
����: Mon Jun  7 00:24:53 1999
���ڵ�history�����Ǻ�����������ʾ�������ƺ���̫
���Ķ����Ⱥ�˳���ǲ��Ǹ�Ϊ�����緢����������ʾ
�ȽϺ�һ�㣿


---
����: Ice
��Ŀ: about multi-log in war
����: Sat Jun  5 10:28:59 1999
Let me give an example,
yunnan used to have over 2k armies, and jianning has 800,
a player control 2 ids, one in jianning, and one in yunnan,
then in 1 min, yunnan is over, because he use the id in yunnan 
to use the least army he can use.  At that time, some players jumped, 
query me that if multi-log in war is legal, then i talked to that 
player, he said because some players used this method to get cities
from his nation, he just followed the same way to do it.
I think if we don't try to control this problem, it might become a 
very bad circulation, because this kind of actions is erasing our meaning
of war, just like we play SAN5, if we control all king ID, we can unify
in 30 mins then finish the game, but that's meaningless.
I think we can use the pos
add an option like forbid war or make some kinds of low lv id cannot get
involve in war so easy.
That's it.


---
����: Fire
��Ŀ: about war
����: Sat Jun  5 09:41:54 1999
about war, I will do the following adjustment
1 create a daemon ttype_d.c to handle all the defination about troops
  this ttype_d.c can be called by warai_d->query_troop()
  so many code still keep compitable
  this function also read all infos from group's troops files
2 define the upper limite of a char's max number of soldiers
3 arrange and document all the fomula for the war system
4 give a detailed help file


---
����: Fire
��Ŀ: about the desc in room
����: Sat Jun  5 07:50:57 1999
I adjust the display in room
so a player with long name and many colors will not get his name 
displayed in two lines.
xixi ;), so row can change his guard's desc to his original designs :)


---
����: Fire
��Ŀ: about the war
����: Sat Jun  5 07:09:27 1999
����ϸ���˿�flee �� group ����ս���Ͷ���ֵ�code
�����������͹�˼������
��������ԭ�����˼·����Щ����
@CHAR_D->get_char("cdd","colth")

������Щ�ط�����ǰ�������Щ��һ��
����������һЩ���Ժ�Ǳ����BUG��
�����Ҽƻ���һ�����ҵ�ʱ������һ�����е�ս��ϵͳ��
�ڱ���flee,group�¼ӵ����ݵĻ����ϣ�������ս��ϵͳ��һ
�ι淶����һ�»��ĵ�����
ͬʱ�����������ĵ���
ͬʱ�����µ�ϵͳ��ƺ�ϵͳ����ϣ���������µĿ��Ų��裺
1 ϵͳ��˼�����������ϵͳĿ�ĺ���Ҫ���̣��������һ��
  �µ�JOB��ϵͳ��˼��Ҫָ�ù����ĵȼ������󣬹������룬
  ִ�к���ȡ����Ĵ��¹��̣���ָ��
2 ��ʽ����ʽһ��Ҫ��ȷ���ر��Ƕ�������ս������������
  ���Ÿ��������ϵͳ��һ��Ҫ�ѹ�ʽ���г�����
3 ʵ�ַ�����һ��ϵͳ���ж���ʵ�ַ������ھ�����֮ǰ
  Ҫ��һ����ʲô����ʵ����Ϊ������Ч���ɿ�����Ҫ�г�һ
  �������ļ�����Ҫ�޸ĵ��ļ��嵥��
4 ��4�����Ǳ�д���롣
5 ��Ҫ���ǲ��Ժ͸���ҵİ����ļ���:)



---
����: Fire
��Ŀ: >about multilog in war
����: Sat Jun  5 05:48:21 1999
On Fri Jun  4 15:16:53 1999 Ice wrote post #470:
> multilog in war made a lot of trouble, so I hope we can post
> a serious warning in caolu, or in the history_d, otherwise will
> discourage players to continue playing this mud.  I think we will make it
> not so easy to multilog to win a war, but now, we don't want to lose our
> player as well, so please consider to make a serious warnning for the
present
> situation.

what is the serious of mult-login in war ?
can you explain it more specific, so let's see can we don some thing
to solve this problem :)


---
����: Flee
��Ŀ: about fight
����: Sat Jun  5 01:51:48 1999
the damage of hit in fight should be reconsidered,
cos most players got good armor, the damage now is
less than player's recover. today, i saw cdd fight with
cnl, they fight for around 5 mininutes, both kee is
still higher than 200.


---
����: Ice
��Ŀ: about multilog in war
����: Fri Jun  4 15:16:53 1999
multilog in war made a lot of trouble, so I hope we can post
a serious warning in caolu, or in the history_d, otherwise will
discourage players to continue playing this mud.  I think we will make it
not so easy to multilog to win a war, but now, we don't want to lose our
player as well, so please consider to make a serious warnning for the present
situation.


---
����: Fire
��Ŀ: about ftp
����: Thu Jun  3 09:39:17 1999
when you upload and download, please remember to use
ascii mode. 
ascii mode. 
thank :)


---
����: Fire
��Ŀ: the bug in the war about attack no leader area
����: Thu Jun  3 09:22:32 1999
is fixed
please report other bugs :)


---
����: Flee
��Ŀ: more about war
����: Thu Jun  3 09:09:47 1999
cmd retreat is located at /sgdomain/cmd/retreat
upgrade and divide cmds is still under my dir
not test yet .. :)


---
����: Fire
��Ŀ: i try war one more time
����: Thu Jun  3 08:22:50 1999
seem that bug of can't retrieve soldier's number is fixed

addoil


---
����: Fire
��Ŀ: another bug in war
����: Thu Jun  3 08:16:46 1999
when look, some time i find our side's troop
got enemy troop's color
:P


---
����: Fire
��Ŀ: about the bug in the war
����: Thu Jun  3 08:06:08 1999
some times the function int get_soldier_total_number(int p_id) in
troop_d seems got wrong answer.
now i have make some adjustment,
see the result in one war is right
some time if we test if one mapping or an array is empty
we use if(!maping) and so, seem this function is not very safe
the safest way is use if(!sizeof(maping))
addoil :)


---
����: Flee
��Ŀ: about war
����: Sun Jun  6 02:06:24 1999
1) Area_d
   the troops are stored use a mapping.
2) Troop_d
   which controls a mapping, it stores all information about 
   all troops. key is it serials number, value is a mapping
   too, in this mapping, keys are general, side, ... ect. and 
   soldier, which is also a mapping, keys are the troops type,
   values are detailed information such as energy, .. ect.
3) Ttypes_d
   which store detailed information of various type of troops. 
   such as energy recover in deffirrence satuation, requeirment 
   of upgrading and basic attack value, .. ect.
4) Warai_d
   which controls the interaction of troops, attack, deffence
   .. etc. it inherit condition.c and apply.c these are used 
   to control some special properties of troops
5) Process of war.
   a) At localmeeting, declare war, create a war task controled
      by task_d.
   b) After localmeeting, go to attack arrange stage.
   c) Use AREA_D->query_area(x,"troop") to get al troops availble.
      and all generals for attack.
   d) Input.c which controls the input process.
   e) If no general left, no troop left or the leader decide, attack
      arrange stage over, def_arrange.c create troops based on 
      informantion stored in task_d.
   f) All troops of attack are moved to the warmap of deffence city
   g) Defence arrange step starts, similar as attack arrange, but
      defence site has one more type of troop, citizen.
   h) Defence troops are moved to the warmap, war starts.
   i) Troop_d check all troops are legal or not(decided by task_d).
      if not, remove that troop. at the same time, it will recover
      troop's energy via ttype_d. and update troop's condition via
      warai_d.
   j) Warai_d takes care of troop move, and use troop_d to substrate
      the energy need by using ttype_d.
   k) Attack is controled by warai_d, when send a attack cmd, warai_d
      first check whether it is possible, then check the type of attack
      and calculated the damage based on informantion from troop_d and
      ttype_d, and also query the troop's condition and applied damage,
      after that, get the deffence ability of defence troop via troop_d
      and ttype_d plus condition and applied defence. finally do attack
      and check NO of soliders. if it is zero, remove that troop.
   l) During the war process, check_result.c of ev_war keep checking
      both side of troops. if no defence troop left, declare attack
      site win; if no attack troop left or the no leader' troop,
      declare deffence site win.
   m) At end of war, all troops are removed by troop_d, soldier then
      stored use area_d.
6) About apply.c and condition.c
   Both of them are part of warai_d.c, apply.c is used to add some
   temporary properties of troop and will upgraded by troop_d at 
   troop checking. condition can be treated as a complex apply.
7) types of war
   Now only two type of wars, one is bandit attack, another is city
   attack, we can add more type of wars by changing check_result.c


---
����: Fire
��Ŀ: about the war
����: Thu Jun  3 07:20:59 1999
hi flee,
what is the command for update troop,
seperate troop and retreat ?
thanks :)


---
����: Fire
��Ŀ: what is this ?
����: Thu Jun  3 06:55:56 1999
���������¼ǡ�
�������������������Ѯ
��һ�������佫���Դ�������������(babu)�ڵȼ��ı����л�ʤ���ؽ���
�ƽ�ʮ��������100�㣬�ҳ�10�㡣�����˼���Ŭ���������������¡�

is it a new system, or just a rumor :)


---
����: Flee
��Ŀ: changes of war
����: Thu Jun  3 00:31:01 1999
1) area_d, change the data type of solider from 
int to mapping;
2) troop_d, change remove_troops and create new
function recover_eng instead of use warai_d;
3) warai_d, change check_move, the energy cost
will depends on the type of troops;
4) files under /sgdomain/event/war
modify four files, def_input, def_arrange, att_input 
and att_arrange.
remove all parts of max_soldier, max_horse .. ect
instead use area_d to get the troop availble

   



---
����: Fire
��Ŀ: about the query_ilog_time()
����: Wed Jun  2 22:22:28 1999
now i updated it so players can also use that function
so the time login will be recorded :)
cheers


---
����: Ice
��Ŀ: ���ڳ�͢��ְ���ݿ���ְ
����: Wed Jun  2 22:21:56 1999
����ʱ����������֮�ƣ��Լ�һȺ��XX��������XX�����ȵȵȵȣ�

ة�ࣺ�ٹ�֮������ܲ١������֮�����ƹ�һ�������������¡�
      ة����������ʷ���൱�����鳤���Լ������ξ���

���У��ֳ�ɢ�ﳣ�̣����ӻʵ۳���������ң������׽����£�
      �ɷ�Ϊ���С����̡���������ɣ��������鹲ƽ���¡�

��ʷ������Ϊ��ʷ��򣬸���Ϊ��ʷ��ة��������������ʷ������
      ִ����ʷ������ʷ����������ʷ����ְ��˾��������Υ����
      �ߣ��Կɵ�����

���飺����Ϊ�������Ͻ����������ˡ��������������������
      ���飬�ƹܵ������顣

����ʡ������Ϊ������࣬�����������ɡ�����ͨ�����˼������ɡ�
      ���ܳ�֮͢��Ҫ��������گ��Ĵ�������������顣

����ࣺ����Ϊ������ة��ר������ͼ�飬���������ɺ�У���ɡ�

P.S. ��Ҫ�ֵȼ�����ֻ�ǲ���ժ¼����˳��Ϊة�ࡢ��ʷ��ة��
     ���С������������ࡢ����ࡣ

�󽫾������ƾ��£����賤ʷ����սʱ��Ϊ������ʷ��

���ｫ�������ｫ������������λ�ڴ󽫾�֮�¡�

ǰ�������ҽ�������һ����սʱ�����������ƺţ����Խ�����
    ����ȡ�̵ĺ��ˡ���Ҫ�������λ����������������ƽ��
    ��֮�¡������������������ϡ�����...blah blah��


�ݿ����ƣ�

��ʷ���ƹ�һ�ݵľ�����Ȩ����Ͻ��ݡ����С����������ܡ�����
      �ȡ�

By considering we need to show info n xxx in one scroll, I 
just take some names for short, hope u all can have a discussion
on it.



---
����: Fire
��Ŀ: about the new limitation in learn
����: Wed Jun  2 22:07:42 1999
I have checked the code, that is right
in order to learn skills from level 42 to level 43 need literate of 61
and since shampoo just have literate of 58, so can't learn
now becase even player has enough exp, if not enough
literate, can't update, so i make the update
will not consume all the exp, in case many exp have to be wasted
about the color of exp, it is designed for average level of gift, as 21
if player's skill is more than 21 can learn even the exp is not blue
if the gift is less than 21, may can't learn even the color is blue
I may adjust this later

xixi :)


---
����: Fire
��Ŀ: >about history_d
����: Wed Jun  2 21:54:02 1999
On Wed Jun  2 08:32:47 1999 Flee wrote post #456:
> it works for wizard, but when i use a dummy to test
> he can get all the messages, seem the function query_ilog_time
> not work for players.
> can fire check that.
> BTW, the following event will be recorded
> independence, war victory, war defeated, country distroied

I will check that.
any problem is the order of dispay msg
it seems not sorted, I am not quite sure :)


---
����: Fire
��Ŀ: about login
����: Tue Jun  1 21:08:38 1999
for the login, i have done the follow adjustment
1 set the max length of chinese name and id to 8
2 set the player can't use id such as "here", "me" and "who"
3 players can't use current real npc char's name as chinese 
  name, such as �ŷ� 
4 new comers will have full hp , food and drink


---
����: Flee
��Ŀ: to fire
����: Wed Jun  2 00:50:11 1999
i have created a history daemons and put it at
/daemons/histroy_d.c. which is use to record historic
event and wiz can post some very important message
in order to do this, should modify the /std/body.c
function finish_enter_game(), so players can see what
happend when they wear off line. PLZ check if any bugs.
and about the war, there r two obvious bugs, one is if
the deffence area does not have soldier or generals, the
attck site will auto lose. the other bug is TROOP_D can
not get the correct number of soilders, although, by using
troop_d->query_troops() can see the correct number. inf u
have time. please check that.


---
����: Stefan
��Ŀ: >about login
����: Wed Jun  2 03:01:55 1999
On Tue Jun  1 21:08:38 1999 Fire wrote post #448:
> for the login, i have done the follow adjustment
> 1 set the max length of chinese name and id to 8
> 2 set the player can't use id such as "here", "me" and "who"
> 3 players can't use current real npc char's name as chinese 
>   name, such as �ŷ� 
> 4 new comers will have full hp , food and drink

The original code is more flexible in banish ids, you can use
admtool to setup what are the ids to ban, just "here" "me" and "who"
are not sufficent... Please consider it :)


---
����: Fire
��Ŀ: about war
����: Wed Jun  2 06:32:08 1999
Hi flee,
when i have time, I will begin to check the updated 
war system, 
now i am not quite sure what you have done.
could you please write a help file about the update
now i know that troops can updated, but not
very clear how to do it, and don't have much time
to search, so please write a clear help

about the history_d, I think it's better to set a cmd
to read. if not, when login, especially for newbies
will have too many msg.


---
����: Fire
��Ŀ: about ban names
����: Wed Jun  2 06:36:23 1999
stefan is right, we have that function in admtool :)
so anyone has any suggestion for what kind of id should
be baned ?
xixi :)


---
����: Flee
��Ŀ: war and history_d
����: Wed Jun  2 06:38:33 1999
i will write a ducument about recently change of war
about history_d, i still think we should force players
to see. cos lots of players doesn't read post, they
may miss some important change and keepings asking wiz.
and in history_d, the news will be filtered, players can 
only see the msg posted when they r off line.
for newbies, it true that the history log will be quite
long, since we use sb->more() to force players read, 
if they really don't want to, they can just type  
'q' to quit from long log.


---
����: Fire
��Ŀ: about the history_d
����: Wed Jun  2 07:11:05 1999
I have add two macros for quick use those function
for wiz announce, use WIZ("information")
for history event use HIS("information")
when a player login, those information will be displayed
xixi :)


---
����: Ice
��Ŀ: about login new id
����: Wed Jun  2 08:00:28 1999
avoid to use same name of objs, otherwise "eat mantou",
"�����ҧ������ͷѽ��",
when sb use mantou as his id....:PP
*smirk


---
����: Flee
��Ŀ: about history_d
����: Wed Jun  2 08:32:47 1999
it works for wizard, but when i use a dummy to test
he can get all the messages, seem the function query_ilog_time
not work for players.
can fire check that.
BTW, the following event will be recorded
independence, war victory, war defeated, country distroied


---
����: Fire
��Ŀ: add color for ������ʵ����
����: Tue Jun  1 19:56:18 1999
now for real char in sanguo,
if you use CHAR_D->get_char(id,"name") will
return colored name, this will help players to
identify who is the real sanguo char and who is a player
for some function if we just want the name and don't
want any color information. please use
CHAR_D->get_char(id,"r_name")
but for most code, use colored name is fine
:)


---
����: Fire
��Ŀ: char_d ����
����: Mon May 31 21:09:18 1999
chat_d is used to store the bigest mapping in this mud.
some information is useless for some tmp chars
such as loyalty, gift and skills
I have add some code in char_d and events
to remove those useless data
some of the code will be active during further calls
so let's hope the size of char_d can decrease some
:0


---
����: Fire
��Ŀ: a typical bug for array operation
����: Mon May 31 19:20:36 1999
please see the bug
 *result of array addition is greater than maximum array size.
/sgdomain/job/zuoci/zuo_tool#91370 at line 153

the code is :  main_rooms = main_rooms + ({ tmp_main_rooms });
this is a very common bug for array operation.
because if just use array add, it may have duplicated entries in one array
so a safe way is �ȼ����ټӡ�
the code should be:
main_room-=({tmp_main_rooms});
main_room+=({tmp_main_rooms});

be careful for this common bugs

:)


---
����: Fire
��Ŀ: about the jail
����: Sun May 30 20:56:20 1999
hi row,
please write the player's help file for your jail
system :)

we need a full document for the job and new system.
hoho 


---
����: Fire
��Ŀ: about king system
����: Sun May 30 20:59:48 1999
I have add one call in ev_guy.c
and that call will be called regularly
so we can be sure we have a king in our system all the time
to drive the king system going

addoil group :)


---
����: Fire
��Ŀ: admire flee
����: Sun May 30 21:37:22 1999
admire flee, 
I have checked your code for zuoci
the idea and the way to realize is so great
admire flee
addoil flee :)


---
����: Flee
��Ŀ: >>�����ڼ�quest
����: Sun May 30 21:49:12 1999
the items wanted r less than level 4, it should
not be very expensive. however, i only check for
a few items, not sure about the average prize .. :)


---
����: Fire
��Ŀ: a little suggestion about the xian ren's job
����: Sun May 30 21:51:39 1999
1 when the job is finished, the tools should be removed
2 when look the tool, should give some hint and desc
rather than �����(zhu bang)������ûʲô����ġ
xixi :)


---
����: Flee
��Ŀ: >a little suggestion about the xian ren's job
����: Sun May 30 21:55:56 1999
On Sun May 30 21:51:39 1999 Fire wrote post #436:
> 1 when the job is finished, the tools should be removed
> 2 when look the tool, should give some hint and desc
> rather than �����(zhu bang)������ûʲô����ġ
> xixi :)
1) cos some player may quit during job, they may lost
their tool at that time, in such case they can not finish
their job. so i make all tools valueable, players can sell
them after job. others may buy from pawnshop.
2) will add some descption soon .. :)


---
����: Fire
��Ŀ: about lose of obj
����: Sun May 30 21:59:37 1999
for an obj, if we don't want it is lost during
the quit or disconnect, can just add one sentence in that obj
set_is_keeping(1);
then this obj will be kept after login


---
����: Fire
��Ŀ: about give sth to npc
����: Sun May 30 22:17:57 1999
in the xian ren's jobs
there is a cmd as give sth to <xianren>
after that process, that obj should be destruct
if not, then what will npc will be overweight
then might cause bugs and increase system burden

xixi :)


---
����: Fire
��Ŀ: about put_prison
����: Mon May 31 07:04:59 1999
I have modified a little in catch.c and yuzu.c
so now we use one call to send a char to prison
it is in /daemons/char_d/appear.c
the function is:
//:FUNCTION put_prison
// put a char to prison, 
// para p_id the id of the prisoner, it must be given
// p_time how long in jail, default is 5
// p_area in which jail, default is the area of current room of the char
// p_msg the message to put in jail has default value
// so the easiest way to send a char to prison is 
// CHAR_D->put_prison(p_id);

so for further development, please call CHAR_D->put_prison
to send a char to prison.
xixi :)


---
����: Fire
��Ŀ: about xianren xitong
����: Mon May 31 09:28:01 1999
I add a file /sgdomain/modules/m_charnpc/xianran/xianren_act.c
for xianren to inherit, this module will enable xianren to do
semote, do chat, do say, do moving and move among areas
for xianren in order to have a full feature
please refer /sgdomain/event/huatuo/huatuo.c
I also modifed the /sgdomain/event/ev_xianren.c
so it will be maintain 


---
����: Group
��Ŀ: kingwar ready
����: Mon May 31 10:09:48 1999
����ϵͳ�����help kingwar
��BUG�뱨�档
any idea any please tell me.
group


---
����: Fire
��Ŀ: about the sg_skilllearn_d.c
����: Mon May 31 23:39:46 1999
I have updated the sg_skilllearn_d.c
the most important change is that now the skill level
is related to the literate.
and also the consume of experience is realted to the gift


---
����: Fire
��Ŀ: about help
����: Mon May 31 23:45:54 1999
��лgroup�������kwar��ʱ�ṩ��help�ĵ���
������������͸Ķ������ϵͳ��ϣ�������WIZ��ʱ�ṩ
�͸�����ص�help�ĵ���
����ע������ڼ���help �ļ���
��Ҫupdate /daemons/sghelp_d.c 
���Ҫ��helpediter�����������ƺͽ�����ط����ϵ��
лл��)


---
����: Stefan
��Ŀ: CPU Usage
����: Fri May 28 16:51:18 1999
Recently there are some complains on the mud speed, I think we should give it
some attention.

First of all, this server is not dedicated to this MUD alone, some 
other people are also using it for their own purposes. 

Secondly, this server is not fast machine, but we get the access for
free. The network connection is generally fast enough.

Regarding CPU load, it was not like this before, I think it is our
program that adds some burden to the servers, too many loaded objects
in the memory, complicated and highly frequent call_out(), etc. etc.
If the memory usage goes up too high, it will tend to use swap space
for virtual memory, which involves heavy disk access and slows down
the overall speed.

I've discussed with fire a year or two ago regarding this matter, 
at that time we do not have any statistics to project our future 
system load, and it was a hard task to manage. But now, seems that
we are running into this problem, it is time for us to re-think about 
it.

Here are my suggestions to reduce system load:
1. avoid disk access as much as you can. For example, if you are going
to save something onto the disk, dont save unnecessary data; when you
dont have to save something, or you can save it later on, use the economic
method if you can.

2. avoid compilcated calculation in one function call. MUD is not
a multi-threaded system, if one of your code takes too much time to
execute, it will appear very lag to other players. For instance, currently
DOC_D is such a program that scans all programs for documentation,
it is executed
once after several hours, and when it is running, after it scans one
file, it uses call_outs for the next one.
In such a way, it gives chances for other program to be executed "on time". 

3. avoid complicated call_out. If you can do something efficently without
call_out, do so. If you can combine several call_outs together, do so. 
If you can delay a call_out to a later time, do so. Currently there are often
40 to 50 call_outs pending when less than 10 people online. And many
of them requires execution in a very short time (1 or 2 seconds). If
we are going to handle 70 people,
I don't know how many call_outs will be there, but it is not a small
number.

4. avoid loading unused objects into the memory. Though there is a clean_up
function to clean up most rooms, I have found it quite strange. We should
not always depend on the clean_up to remove the object from memory for
the time being, until this problem is solved by me :PP (*addoil stefan)
One way is to avoid loading objects, another way is to dicard objects
once they are not needed.

It is time for us to optimise our own code, otherwise, somebody please
find a faster machine with good internet connection? :-)


---
����: Ice
��Ŀ: about "who"
����: Fri May 28 16:46:02 1999
����ͨ���֡�̫ԭ��������������(joy) [���� 4 Сʱ]                   
           

������1����
��������������������������������������������������������������������������
��������������������������������������������������������������������������


but not in list


---
����: Stefan
��Ŀ: quest
����: Fri May 28 16:24:45 1999
Ice �ᵽ��һЩ����ܲ����һ��и��뷨�������й� quest �İ���Ӧ��
�ŵ���Ϸ����ȥ��player Ӧ�����ò� help �Ϳ���֪����һ����ʲô��
�������� player ��ô֪����Щ quest����������ںϵ���Ϸ��ȥ��
��ĳЩ�ط���Щ��ʾ��������ȫ��д�� help �ĵ��


---
����: Ice
��Ŀ: about new changes
����: Fri May 28 14:56:27 1999
������ccbb������һ�����ֵĳɳ����̣���һЩ������Ҫ�Ľ��ĵط���

��һ�����ǵİ����ļ����²�����ʱ���ö�ʱ�򲻵ò�Ҫ���ֿ�post��
���������������г���200�����ԱȽ����ѡ������ҿ�������һ�����ڵİ�������
��֪����ôcode�� *blush  anyone has time, show me bah...:)

�ڶ������ڶ��˺ö�ú���Ĺ��������лʵ��ټ�(but seems now still has bug..;()
���������ǲ��Ǹ���һ��help quest����Ϊ��ǰ��û��help quest�ģ�ȫ��Ҫ�����
���߲��У�����waterflower..:PPP�������ǣ���Ȼ��quest���ǲ����ֲ�������ô����he
lp��
����ֻ��quest���Ǻǣ����Ҿ��ü�Ȼ���˾͸������������ô���������...:)
so waiting for ur comments, if no objection, let me try create the topic
and work on it

����������ҵ�ʱ�����û��ʲô��Ϣ�����û������ͬʱ����Щquest����������
ʲô�ط�Ҳ��֪�����������˵Ĺ�������ȷʵ�Ƚ�����ɣ��ر������ڵĳ��ж��ˣ�
����ڳ���֮��û��Ŀ����й��Ǻ����ҵ�ĳЩ��Ʒ��������Ҫ��һЩhints��
�ǲ��ǿ�������boy�Ĺ��ܣ�������һ�����Ƶİ�����������ҿ��Դ��������˺���Ʒ��
�ĵص㣬��������һ����Ҫ50�����ӣ� *grin��Ȼ��˵����ĳ�ݻ�ĳ�������Ǹ���С��
�ķ�Χ����������Լ��ң����ڵ���Ʒһ�㶼��ֻ��һ�����п����򵽣�ֻ��Ҫ�����
��һ���ݻ���ҾͿ����ˡ�Ϊʲô��Ҫ50�����ӣ���Ϊ��ʵ�Ұ����еĳ�ʳƷ������֮��
����Ʒ���ԱȽ����߼��ķ�ʽ�ֲ�����ֻ������һ������ajhorse�ȵȣ���Ȼ��Ը���룬
��ô�͸�����ඡ�Ȼ��ΪʲôҪ�ǹ��Һ��ݣ���Ϊ�ݿ�������ֻ����һ����ܣ������
���뻹�бȽϳ���һ�����ӣ�������Ҫ�ù�����ӦӦ�����Ժ��ݿ�������˿��Բ��С�
��Ȼ�������boy�Ļ�����50���������ƺ�̫����һ�㣬�ܲ�����boyר�����ˣ��շѵ�
����
�����������ṩ��Ʒ��Ϣ�����˵��ټ���������շ�һ���ƽ���ˣ�*smirk��

�����ǹ���quest zuo ci �ģ���������һ���������ӵҵ�һֱ�ܵ�������˵�����ϵĳ�
�У�
�ǲ����ܸĳ����Ŀ�귿����ͬһ�������ڵľ��á������ϵķ��򡱣�������ǣ�����
������Χ�ĳ��С�����������󵼣�����Ҿ����Ǹ���ʾû��ʲô�á�

������ *handshake


---
����: Row
��Ŀ: about prison
����: Fri May 28 05:39:27 1999
with the help of flee and ice, i finally finished the
prison and make every area has one. the file is under
/sgdomain/prison/yuzu.c
pls check if has bug.

and...i think prison can be used in many ways, after catch
the player, just set two para of player, and move him
to prison then it will block him from certain time.
CHAR_D->set_char(<id>,"in_prison",<time period>)
CHAR_D->set_char(<id>,"be_caught",<time>)
in_prison indicates the time period that the prisoner 
should stay in the prison, and the be_caught indicates
when the player is being caught.

now every area has a "prison" room.


---
����: Row
��Ŀ: about prison again
����: Fri May 28 05:40:19 1999
only work for char


---
����: Ice
��Ŀ: Reseted something
����: Fri May 28 08:45:20 1999
Changed ��վ����լ������һЩ INDOOR �� OUTDOOR room �����ã�
�Ա��ò�ҩ�Ĳ��õ���վȥ�ڿӡ�

Reseted most SW cities' population as the following:
Lv 1  2000
Lv 2 5000
Lv 3 10000
Lv 4 50000
Lv 5 100000



---
����: Ice
��Ŀ: SW national tax adjusted
����: Fri May 28 09:36:49 1999
I adjusted it as 10 of each city


---
����: Ice
��Ŀ: �������ϳ��з�չ���������巢չ
����: Fri May 28 19:40:24 1999
���쿴����ɽ�����ڹ�ռ��Ȼ�󵱵�ûǮû�����ж���ͷҪ������һЩ
�����ϵ͵ĳ��и�һ�£���ת��һ�룬�������Ҳδ�ع��ã���Ϊ���ڵ�
״��������С���л����������壬����������Ұ�ĵ�ռ��ǣ�û��ʲô
Ұ��ռС�ǵ��������������ǲ��Ǹ����濼��һ�£������ĳ��и����ƽ��
��Ϊ����������ֻԸ�⵽�б��ϵĴ���й�����������ɺõĳ���Խ�ã�
�õ�Խ�ã������ⲻ������ϣ������������

��ʵ�����ϻ�û�н���õ�ʱ���Ҿ;��ò�Ӧ������ҽ�פ�����������
�����ң����������Ҫ���ֿ��Ŷ��ϺͶ������������Ǿ��������е�ͼ
���֮�����������������ȫ�����ã����򣬻��ǲ�Ҫ����ҽ�פ�ĺá�
�ǲ��ǰ����Ӷ����ĳ��е�neighbourȡ���Ϳ����ˣ����У�������ϵ�
�����ǲ��Ǹ��и��˶ϣ��������һ�°ɣ��һ����Ҹġ�.... :PPPP



---
����: Ice
��Ŀ: �����ڼ�quest
����: Sun May 30 06:26:41 1999
һ���С���飬��Ϊǣ�浽��Ʒ�İ��ţ����Ա���ӵ���Ǽ���Ʒ��
��ô�����Ҫ�����ǡ��ʹڡ��������Ҫ��һ�ٽ���ʹ�����ɣ�
�ƺ��ò���ʧ���ǲ��Ǹĳ�ʳ���������Ŀ��������ǽ��ܵ��ˣ�
��Ϊ����������µĲ���̫���صģ��硰ü�⵶���������������
�Ĳ��ǵ���Ҳû���ã�ʳ�ﻹ���ԳԻ���� ....:)


---
����: Group
��Ŀ: sorry
����: Sun May 30 11:33:28 1999
these days got a little busy in communications...hence sorry...
i will finish the war job as soon as possible in next week.

sorry again for the delay..:P

group


---
����: Group
��Ŀ: about king
����: Sun May 30 11:37:25 1999
there is a little problem about king.
since the ev_king is called by the object "king",
when the mud is just began, there is no "king" actually, because the
room of the king
is never refreshed since no player can get to the place.
is that possible to make the room to be loaded whenever the mud is reboot?
hence the event can auto begin.

please help..:)

group


---
����: Fire
��Ŀ: >CPU Usage
����: Sun May 30 20:13:42 1999
I will do the following things to reduce the system burden.
1 add self_hide in the char_d
so that most npc chars when no ppl go around
can hide and discard the related room

2 change the m_age, now we use a call_out for each
player to grow his age, this will be changed as hp system
the age will be update until when you are checking it


---
����: Fire
��Ŀ: >�������ϳ��з�չ���������巢չ
����: Sun May 30 20:16:21 1999
On Fri May 28 19:40:24 1999 Ice wrote post #424:
> ���쿴����ɽ�����ڹ�ռ��Ȼ�󵱵�ûǮû�����ж���ͷҪ������һЩ
> �����ϵ͵ĳ��и�һ�£���ת��һ�룬�������Ҳδ�ع��ã���Ϊ���ڵ�
> ״��������С���л����������壬����������Ұ�ĵ�ռ��ǣ�û��ʲô
> Ұ��ռС�ǵ��������������ǲ��Ǹ����濼��һ�£������ĳ��и����ƽ��
> ��Ϊ����������ֻԸ�⵽�б��ϵĴ���й�����������ɺõĳ���Խ�ã�
> �õ�Խ�ã������ⲻ������ϣ������������
> 
> ��ʵ�����ϻ�û�н���õ�ʱ���Ҿ;��ò�Ӧ������ҽ�פ�����������
> �����ң����������Ҫ���ֿ��Ŷ��ϺͶ������������Ǿ��������е�ͼ
> ���֮�����������������ȫ�����ã����򣬻��ǲ�Ҫ����ҽ�פ�ĺá�
> �ǲ��ǰ����Ӷ����ĳ��е�neighbourȡ���Ϳ����ˣ����У�������ϵ�
> �����ǲ��Ǹ��и��˶ϣ��������һ�°ɣ��һ����Ҹġ�.... :PPPP
> 

MUD is a very complex self-contain system
so we don't need worry too much about the initial value
if the formula for the self-development is reasonable
it will reach a suitable balance status.
now we open the SW for players, then we can observe
our development, see if it reliable. and if has
bug to crush this system. so don't worry too much
about it lah.

xixi


---
����: Fire
��Ŀ: about the xianren's job
����: Sun May 30 20:20:10 1999
it's amazing for flee to develop so many xianren's job
so, please give the related help files :)
and those xianren's job well be in one certan class of help as special_job

xixi


---
����: Fire
��Ŀ: for the CPU concersion
����: Sun May 30 20:51:45 1999
I add a function my_clean in m_m_charaction.c to
force the char call environment clean up
in siteration situation, hope this can help to reduce the cpu useage
xixi :)


---
����: Fire
��Ŀ: new functions
����: Thu May 27 22:11:07 1999
this_body()->query_literate() return literate value
this_body()->query_literate_str() return string desc of literate value

CHAR_D->get_char(id,"level") ���ع�ְ��С 0 to 9


---
����: Row
��Ŀ: to flee & group
����: Thu May 27 20:57:14 1999
seems we still has bug in war and train, since war
is very important, pls check. thx.


---
����: Fire
��Ŀ: >>> bug or ?
����: Mon May 24 18:40:22 1999
On Mon May 24 07:10:30 1999 Flee wrote post #398:
> no sure about the reason, but for the bug cnl
> encounter, it is beacuse the city he attacked
> does not have a warroom.c under city dir.
> so the attack troop can not move the warfield
> TROOP_D will remove thire troop and ev_war:check_result
> determine that attack troop are defeated
> 
> i check all the cities and add warroom.c for those
> do not have.

there is a cmd in /wiz/fire/cmds/ can auto all the warroom
sorry don't mention that before



---
����: Ice
��Ŀ: �����ݿ��б�
����: Tue May 25 19:36:28 1999
��������������ʮ���ݾ�ʮ�ſ���

���ݣ�����������
���أ����ǣ��׾�����ƽ������ɽ����ƽ��

���ݣ������Ŀ���
��Ƥ��ƽԭ����ӣ����š�

���ݣ�����������
���ϣ�������������

���ݣ������忤��
�������������գ����������

ԥ�ݣ������Ŀ���
������ۣ����ϣ��ٶɡ�

���ݣ������忤��
���ݣ�С�棬���������꣬��а��

���ݣ������Ŀ���
̫ԭ���ϵ������Źأ�������

˾���������߿���
���������ιأ����أ��ųأ���ũ���𣬲����¡�

Ӻ�ݣ������˿���
����������ԭ����أ����ȹأ����أ�������������������

���ݣ������˿���
������¤������ˮ���ҵ�����ͤ���������ش����²֡�

���ݣ������˿���
���У���ɽ�����ͣ���ƽ�أ�����ɽ���������������ǡ�

���ݣ�����������
�ɶ�������أ����ݣ����������������ϡ�

�����ݣ������߿���
��������ӹ����Ұ���Ϫ�������£����ģ���ڡ�

�Ͼ��ݣ������˿���
���꣬���꣬���������ݣ����꣬���꣬��ɳ��������

۫�ݣ�����������
®��������ɽ��������۶������ɣ��ԥ�¡�

���ݣ������߿���
��ҵ���ٴ������ǣ����������ڣ��⿤�������

���ݣ�����������
�Ϻ������֣�®�ꡣ


��Ϊ���ݴ�С��һ�����������Ժ����������ʷ��ʱ�����ǵ�Ȩ��ҲӦ�ò�ͬ��
*smirk


---
����: Fire
��Ŀ: about ice's suggestion
����: Tue May 25 20:55:54 1999
ice's suggestions are very nice.
we will try to introduce some in our system later
addoil :)


---
����: Group
��Ŀ: ���׵�ϵͳ��
����: Wed May 26 07:29:06 1999
help king.
please give comments.

group


---
����: Fire
��Ŀ: about the ev_king
����: Wed May 26 23:21:20 1999
group's king is very nice, 
it's amazing that he can finish that
in such a short time.
I have checked the code, it is very nice.
just a little problem.
if there is a player connected but not login then
will have ask 0 to come etc, I have modified a little in the auto_run
and make comment, hope can solve this problem. another problem is
that if a player is on a meeting or on war.
he perhaps can't come within 10 mintues
so need to check if that player is on task
this can be done by check !(EV_CHAR_D)->get_char(id,"task")
perhaps need check that.
anyway, good job group
addoil
another problem is for the install of help
now i use help new and find emperor don't have a chinese title
so need use helpediter to edit for suitable title and links
xixi :)


---
����: Ice
��Ŀ: ideas about new jobs
����: Thu May 27 01:20:07 1999
�м������ݻ�

ask taishou about job,answer arson to taishou
̫�ض���˵�����鷳�㵽�ɶ���һ�ѻ�

��������󵽻������ѣ���������ȼ���ڻ��Ϩ����ǰ
����ɶ�����ݻ�

���ݻ�ķ���ֻ��һ�������������Ŀ����еķ����ȡ
һ�����ݻ���Ҫcmd arson here����cmd spy hereһ����
��Ҫһ������busy time���Ҳ��Կ����ݻ�ķ������ʾ��
�ݻ�ʧ�ܡ��Ҷ��˾���ʾ�ݻ�ɹ������ݻ�ɹ���Ŀ�����
�����½�2�����ʡ�����ʳ��ʧ1��5%��

�ɹ���������ȡ����Ŀ����еķ�����Ŀ���ɲ���spy�Ľ�����

�ͼ������Ȼ�

ask taishou about job,answer fireman to taishou
̫�ض���˵�����ã��ã���������Ҫ���˾Ȼ���ô�㿴����
�����Ż��ˣ��Ͽ�ȥ����ѡ�

���û�б��ݻ�̫�ػش𣺱���������û�л��֡��������
������һ�ѻ𣬺ٺ١�

�Ȼ���������ڵĳ������žȻ���򣬽��������ŵĹ�Ա�ĳ�
����ˮ���ģ�����Ҫ��ÿ����������һ�����Կɼ��Ŀ���װˮ
�ĵط���

����������Թ̶�һЩ������findbody�����ϻ�����ƵĽ�����
�����еľȻ�job��ԭ�Ȼ�job cancel��officer ֻ������߻�
����ƺ��ṩˮ����



---
����: Ice
��Ŀ: btw, arson can be caught
����: Thu May 27 01:22:30 1999
arson job can be caught, and I think the current cmd catch xxx has some bugs
ppl in patrol sometimes cannot catch thief or player spying and whispering


---
����: Fire
��Ŀ: about the job of arson
����: Thu May 27 01:24:57 1999
a very nice job,
who want do it ?
addoil :)


---
����: Ice
��Ŀ: about cmd resign a job
����: Thu May 27 01:42:17 1999
for example, if sb get a job from xu zijiang, to search buyi,
then player feel hard to do it, then they cmd resign that job
until the xian ren ask him to search a mantou, then it's not reasonable

but if it's only for mid-lv job, that's fine, otherwise may do some adjustment
to xu zijiang's job

if the ppl choose to resign a job, or he missed the xian ren, make
it available
again for player 20-30 mins later

btw, just now a player complain that he gave up the xian ren job,
but wait 1 hour
still cannot do the same quest again, so flee pls consider to change
it bah...:)


---
����: Ice
��Ŀ: about the current merchant settings
����: Thu May 27 01:47:37 1999
because we have many new stuffs on sale now, sometimes it's hard to buy sth
like food and stuffs, which are important to keep a city

so I suggest to devide the merchant selling to 2 categories
each merchant may bring 1-2 kinds of basic goods like food, stuffs, horse,
bow, or some basic upgrade stuffs that is not so expensive
the advanced category has also 1-2 kinds of higher lv of upgrade stuffs


---
����: Fire
��Ŀ: about the obj
����: Thu May 27 02:30:56 1999
we need a npc can give players the hint where to find
certain obj, 
this is not a free service :)
hoho


---
����: Group
��Ŀ: re fire
����: Thu May 27 06:10:17 1999
xixi, first should thank flee for his help.
i add 1 more function in to check whether the body 
got is wiz or not. later emperor will not call wiz at all
and i change the delay time to 30 minutes according to the 
players in war and  train.

and i want to add a function to make the rumor call the player 
every 2 minutes.

xixi
group


---
����: Flee
��Ŀ: about xu zijiang
����: Thu May 27 06:25:08 1999
i make xu a character now, who has property is_tmp = 1
and is_xianren = 1. and code a event ev_xianren, which
will random place this xianrens. in order to do that,
i modifed ai_d.c


---
����: Stefan
��Ŀ: For those who want to know LPC
����: Thu May 27 14:13:43 1999
There is a recently development of LPC, or similar to LPC, a
programming language
called PIKE. If you are interested, you can take a look at
http://pike.idonex.se/



---
����: Group
��Ŀ: ���˼���
����: Mon May 24 07:41:42 1999
�������������õ���Ʒ�Ѿ����뵽�����˵��������С�
���������

group..:)


---
����: Flee
��Ŀ: >> bug or ?
����: Mon May 24 07:10:30 1999
no sure about the reason, but for the bug cnl
encounter, it is beacuse the city he attacked
does not have a warroom.c under city dir.
so the attack troop can not move the warfield
TROOP_D will remove thire troop and ev_war:check_result
determine that attack troop are defeated

i check all the cities and add warroom.c for those
do not have.


---
����: Flee
��Ŀ: >> about commando
����: Mon May 24 07:06:18 1999
now I change it back to original formulor,
the nuumber of commando is the minumum of 
safe*100 and population/10

xixi .. :)


---
����: Ice
��Ŀ: ���ڰ����ļ�������
����: Sun May 23 22:14:19 1999
�ҽ����������Ұ����ļ���Ŀ���������ģ�
��Ϊ�����ļ����ֱ��� help jinnang1, help jinnang2, help jinnang 3
�иտ�ʼ�ڱ�mud������٣����ٺ��������֣�
��Ҫ��������post������ָ�����á�
��ϣ���������ָս����®ʱ��shuijing������Ŀ���־���ʾ���µĻ���
�����Ķ�help newbie �� help starts��
������Ǿ��������ѣ����������������ң������ڱ�Ҫ��ʱ��źô�����ѽ��
%^H_YELLOW%^����һ%^RESET%^ (help jinnang1) ��������������Ǻ�
%^H_MAGENTA%^���Ҷ�%^RESET%^ (help jinnang2) ���ٱض�
%^H_BLUE%^������%^RESET%^ (help jinnang3) �º�����

������ܣ��һᾡ�����ָ�����Щ�ļ�������Ҫsb help me to put it in
sanguo domain

���⣬�Ҿ���������˽��ң���®���ְ������ǲ��ǿ��Ը�Ϊϵͳ��Ϣ������
��һЩ���µĸ���������֪ͨ���Ͳ��������post�������壬�������ڵ����ְ�����
�ƺ�û����Ӧ�е����ã�ÿ�ζ�Ҫ�� trans player there to see

�����⣬landlord �� �����ļ��ǲ�����Ҫ����һ�£���������û��һ�����ö���
ȫ��Ҫ�Ҹ������� d 1 1, d 2 2, d 3 3, q



---
����: Fire
��Ŀ: about the shortage of food, gold and stuff
����: Sun May 23 20:36:46 1999
for an area, if the food, gold and stuff are not enough to
support the troop, i think the soldiers should leave rather
than just reduce the morale and train.

what you guys think about this

xixi :)


---
����: Fire
��Ŀ: >����ʳ�������
����: Sun May 23 20:04:58 1999
On Sun May 23 10:48:20 1999 Ice wrote post #392:
> lv 0 for those food and drinks for fun
> lv 1 is the most common food for ppl, like mantou, blah blah
> lv 2 is for mid lv income ppl to eat and drink, if they want
> lv 3 food are the most expensive, for ppl who really want to eat them....:P
> 
> I don't mean to add some new categories, just seperate them by prices
> and I will try to add some new food and drinks according to the coming
> �׵۹� new quest
> 
> *smirk

good point
addoil :0


---
����: Ice
��Ŀ: P.S.
����: Sun May 23 11:39:37 1999
I respect the payout of who made those objs, 
I modify them just to make them in sequence,
(mostly to guanfeng, i guess...:P)
anyway, sorry to bring any inconvenience.


---
����: Ice
��Ŀ: ����ʳ�������
����: Sun May 23 10:48:20 1999
lv 0 for those food and drinks for fun
lv 1 is the most common food for ppl, like mantou, blah blah
lv 2 is for mid lv income ppl to eat and drink, if they want
lv 3 food are the most expensive, for ppl who really want to eat them....:P

I don't mean to add some new categories, just seperate them by prices
and I will try to add some new food and drinks according to the coming
�׵۹� new quest

*smirk


---
����: Fire
��Ŀ: bug or ?
����: Sun May 23 09:51:51 1999
�������λ���������ˣ����ٵ���Ӫ���������
�������˾�Ӫ��
׼��������������ͬ�еĽ�����
��Чֵ�У���cctv,mimi,guanfeng��
ȱʡֵ�ǣ���cctv��
mimi,guanfeng
�����벽��������
��Ч��Χ����0--6154��
ȱʡֵ�ǣ���879��
�����벿��פ��λ�á�
��Чֵ�У����Ƕ���e ������w �Ǳ���n ���ϣ�s ��
ȱʡֵ�ǣ���e��
�Ƿ�����±��ţ�
��Чֵ�У���Yes|No��
ȱʡֵ�ǣ���Yes��
����¾��š�������þ��Ž�����
��Чֵ�У���cctv,mimi,guanfeng��
ȱʡֵ�ǣ���cctv��
�����ġ�õ�壺�쵰�����
�����벽��������
��Ч��Χ����0--6154��
ȱʡֵ�ǣ���1025��
�����벿��פ��λ�á�
��Чֵ�У����Ƕ���e ������w �Ǳ���n ���ϣ�s ��
ȱʡֵ�ǣ���e��
��ȵ���������ڣ�
����������ְ�ڣ�
�Ƿ�����±��ţ�
��Чֵ�У���Yes|No��
ȱʡֵ�ǣ���Yes��
����¾��š�������þ��Ž�����
��Чֵ�У���mimi,guanfeng��
ȱʡֵ�ǣ���mimi��
�������˵�����ٵ�һǧ���ʮ��������������
�����������
�����벽��������
��Ч��Χ����0--5129��
ȱʡֵ�ǣ���1025��
�����벿��פ��λ�á�
��Чֵ�У����Ƕ���e ������w �Ǳ���n ���ϣ�s ��
ȱʡֵ�ǣ���e��
��ȵ������ں��ڣ�
���ڴ����ĩ���ڣ�
�Ƿ�����±��ţ�
��Чֵ�У���Yes|No��
ȱʡֵ�ǣ���Yes��
��Ի���˵�����ٵ�һǧ���ʮ��������������
���ڴ�������
����¾��š�������þ��Ž�����
��Чֵ�У���guanfeng��
ȱʡֵ�ǣ���guanfeng��
�����벽��������
��Ч��Χ����0--4104��
ȱʡֵ�ǣ���1026��
�����벿��פ��λ�á�
��Чֵ�У����Ƕ���e ������w �Ǳ���n ���ϣ�s ��
ȱʡֵ�ǣ���e��
��ȵ����ŵ��Ⱥ��ڣ�
�ŵ��ȴ������ְ�ڣ�
��ȵ���ȫ�彫ʿ��Ҫ����ɱ�У������������ͣ�
���콫ʿ����ս����
��ҥ�ԡ�ĳ�ˣ��һ�����ǧ����ʮ����ʿ��ɶ�ɱ��������
> 
> ����ŵ���˵�����ٵ�һǧ���ʮ���������������
�ŵ��ȴ�������
��ҥ�ԡ�ĳ�ˣ������ʾ�������ս�����һ��ö������ף��Ǳ��Ӵܡ��ɶ���
��ϲ�칦��
�����ġ��������һ�ƥ�����ҷ���һ���������������´Σ������������޻أ�
�����ġ��һ𣺷�����������Ҫ��˲����Ҷ�������������ߣ�

I just finish the arrange troop and didn't war
yet, then it announce i am defeated 
so is that a bug, or i make any mistake in the arrange 


---
����: Fire
��Ŀ: bug or ?
����: Sun May 23 09:50:02 1999
�������λ���������ˣ����ٵ���Ӫ���������
�������˾�Ӫ��
׼��������������ͬ�еĽ�����
��Чֵ�У���cctv,mimi,guanfeng��
ȱʡֵ�ǣ���cctv��
mimi,guanfeng
�����벽��������
��Ч��Χ����0--6154��
ȱʡֵ�ǣ���879��
�����벿��פ��λ�á�
��Чֵ�У����Ƕ���e ������w �Ǳ���n ���ϣ�s ��
ȱʡֵ�ǣ���e��
�Ƿ�����±��ţ�
��Чֵ�У���Yes|No��
ȱʡֵ�ǣ���Yes��
����¾��š�������þ��Ž�����
��Чֵ�У���cctv,mimi,guanfeng��
ȱʡֵ�ǣ���cctv��
�����ġ�õ�壺�쵰�����
�����벽��������
��Ч��Χ����0--6154��
ȱʡֵ�ǣ���1025��
�����벿��פ��λ�á�
��Чֵ�У����Ƕ���e ������w �Ǳ���n ���ϣ�s ��
ȱʡֵ�ǣ���e��
��ȵ���������ڣ�
����������ְ�ڣ�
�Ƿ�����±��ţ�
��Чֵ�У���Yes|No��
ȱʡֵ�ǣ���Yes��
����¾��š�������þ��Ž�����
��Чֵ�У���mimi,guanfeng��
ȱʡֵ�ǣ���mimi��
�������˵�����ٵ�һǧ���ʮ��������������
�����������
�����벽��������
��Ч��Χ����0--5129��
ȱʡֵ�ǣ���1025��
�����벿��פ��λ�á�
��Чֵ�У����Ƕ���e ������w �Ǳ���n ���ϣ�s ��
ȱʡֵ�ǣ���e��
��ȵ������ں��ڣ�
���ڴ����ĩ���ڣ�
�Ƿ�����±��ţ�
��Чֵ�У���Yes|No��
ȱʡֵ�ǣ���Yes��
��Ի���˵�����ٵ�һǧ���ʮ��������������
���ڴ�������
����¾��š�������þ��Ž�����
��Чֵ�У���guanfeng��
ȱʡֵ�ǣ���guanfeng��
�����벽��������
��Ч��Χ����0--4104��
ȱʡֵ�ǣ���1026��
�����벿��פ��λ�á�
��Чֵ�У����Ƕ���e ������w �Ǳ���n ���ϣ�s ��
ȱʡֵ�ǣ���e��
��ȵ����ŵ��Ⱥ��ڣ�
�ŵ��ȴ������ְ�ڣ�
��ȵ���ȫ�彫ʿ��Ҫ����ɱ�У������������ͣ�
���콫ʿ����ս����
��ҥ�ԡ�ĳ�ˣ��һ�����ǧ����ʮ����ʿ��ɶ�ɱ��������
> 
> ����ŵ���˵�����ٵ�һǧ���ʮ���������������
�ŵ��ȴ�������
��ҥ�ԡ�ĳ�ˣ������ʾ�������ս�����һ��ö������ף��Ǳ��Ӵܡ��ɶ���
��ϲ�칦��
�����ġ��������һ�ƥ�����ҷ���һ���������������´Σ������������޻أ�
�����ġ��һ𣺷�����������Ҫ��˲����Ҷ�������������ߣ�


---
����: Fire
��Ŀ: about commando
����: Sun May 23 08:38:26 1999
In flee's post:
2) Add commando to defence troop. the defence army
will get commando. the number of it is 10% of city's
population

In the old war system, the number of commando still
related to the safe level of that city and also has
a upper limit. I think that is more reasonable
xixi :)
and when the new war system is ready
please make a detailed help file in chinese
and please headline the difference from the previous
version. thanks



---
����: Ice
��Ŀ: �����׵۹�quest������
����: Sat May 22 20:09:45 1999
�Ҿ����׵۹���quest��Ƚ���Ȥ������һЩ�뷨��;�����ǲ�֪���ܲ���code������

���ȣ�Ҫ�����quest����ұ�����2�����ϵĵط�
��ְ������ү���佫�����ܵ��׵۹����������ͬʱ
�������׵۹��ſ�����Щ�ϰ��������������������
���ó�Ҫ�ȴ�ͨ�ؽڲ��ܽ������������ʧ�ܣ���ô
��ЩǮ��׻��ˡ�*grin

�ڶ��������quest���ʹͷ��Ʃ��ÿ�γɹ�֮���ʹ�ʮ���ƽ���ʮ����
�𲻵ȣ�������Ҫ�����
��������ɵ�Ч�ʾ���������Ϊ������������������
�Ȳ�һ���������Ҿ���ʱ���Ч�ʱȽ��ѿ��ƣ�����
�⻹��������Ʃ��1000�������������ӣ���һ��500����
�Ը߻ر�������������׵۹��ſ�ͨ���Ŷӡ�*smirk

�����������quest������һЩ������������������
���׵���С����Ҫ�Ķ������Ҿ������ǹ�˵��XX���и�
��û����ô���棬���ҵ��뷨�ٸ����ӣ��������ҵ�
�������ˣ�������һ���ƽ�֮��õ����»ش𣺴�բз
ô����˵�ھ���һ�������򵽡�Ȼ����Ҿ�Ҫ�����ݵ�
������������ȥlist�������ҵ���Ҫ�����Ʒ��Ȼ���
ȥ�����֪�������᲻�����˸�������������ʱ����
������

���ҵ���ʦ�������潲��ҪЭ�����ƿ����ƶȣ�Ҳ�Ǻ�
����ĵ������Ӧ�ģ�����ʱ�����ݿ��������ڵ�ʡ��
�����Լ��ĵط����죬����ӵ��һ��������Ȩ��Ϊʲô
�һ������Ҫ����ƶ��أ���Ϊ�ڵ����ϵ�ʱ�򣬸տ�
ʼ�����Ծ����Žᣬ��������Ϊ�������������ƵĹ�
ְ�ƶ����������ɢ���������־����ϷĿ�Ĳ�����Ҫ
���������Ϸ�ɹ���������Ҫ�����������۹�֮�⣬��
Ҫ��һ�����������£�Ҫ�������Ž����Լ���Χ��Ҫ��
������һ����Ȩ���������ѡ�εط�̫�صȡ�

������ÿ����������ֿ����ƶȣ��ҿ����������Ѽ���
����Ϸ���ִ棨�򽫻���ڣ��ĳ���������ʱ���Ļ���
�ֳ��ݣ�Ȼ������coding���Ҷ���Ϸ�������һ����֪��
���Բ�֪�������᲻������ܴ����ѡ�

ʣ�µĹ�˼����������ƶȵĻ����ϵģ�Ʃ��ʹ������
info p list ���Բ鿴���ݵ����ƣ�����ֻ�е�һ����
��ռ����һ���ݵ����г��У��ù�������������XX����
��XX�ݴ�ʷ�ȡ�


�ޣ����л��У�������׵۹�quest��Ҫ����Ѽ�����
��һ���obj������ȥ�ң�����maker��ʱ��ž�������
��obj���٣������ظ����ظ�ȥ������ҿ�����obj�Ļ���
�ٺ١����������ǽ������˸����ɿ��������������ǳ�

���ˣ���ҿ���ǵÿ��responseѽ�����¿����ֿ쵽
�ˣ�*fear, *escape




---
����: Fire
��Ŀ: about set_msgs
����: Fri May 21 19:51:14 1999
@.me->set_msgs("clone","$N�Կճ������񰡣�������$o�ɡ�\n$O���������\n")
this is set the msg for clone.
for more msg, please use review

and $O is used for the name of obj, it is a little different from
$o


---
����: Fire
��Ŀ: about $O
����: Fri May 21 20:19:50 1999
$O means:
"һ"+unit+name


---
����: Fire
��Ŀ: about the cpu
����: Fri May 21 22:38:37 1999
because now we have more and more npc char.
the old way to make them auto_action is use
call_out in each npc obj. 
but this will make system more than 300 call_out
it used a lot cpu and memory resouce.
some time the cpu usage is up to 10%
now I changed this machine from a daemon called
charheart_d.c under /daemons/
now the npc useage is below 2%
hoho :)


---
����: Fire
��Ŀ: ��ϲ flee and group
����: Sat May 22 09:31:56 1999
you guy do very quick work.
very good. 
now i change a little in area_d
so the AREA_D->get_area(<a_id>,"soldier") will
return the summary of number of all troops
so the info and list will return the real number of solderis

addoil :)


---
����: Fire
��Ŀ: some suggestion about the war and troops
����: Tue May 18 20:16:20 1999
It is obviously that the war system is the most complex 
system in this mudlib. so it is very common to get confused and
cause bugs when
try to install some new features.
I am sorry that I can't give more help recently because I am
too busy, and update this system need more concertrated.
Here I have some suggestion, hope they can help flee and group
to update the war and troop system.

1. about the soldier number.
   the soldier number for a certain area is stored in the area_d.
and there are many programs call them. but most are inqure and just
a few are set. for the inquire. they use function as:
AREA_D->get_area(a_id,"soldier");
and in area_d, this function can be overrided by a specific function.
so you need modify the area_d. in the get_area function. when the
parameter is soldier. then call another function such as
get_area_soldier(a_id).
and in this function return the summary of troop numbers.
so many program need to check the soldier numbers don't need to be
modified. and we will remove the parameter of soldier in the area_d
databased.

2 for the set soldier number function, it is much more difficult.
I still don't know what your guys idea. 
so you need write very clear and seperate functions to handle this process
and also about the troop changes. so I suggested you
write a seperate file under /daemons/area_d/ and this file will be
inherited by area_d.c
3 about the troop type.
  I have checked groups files under /wiz/group/troops
I think use seperate file to define seperate troop type is not a good idea
because if we want to add a common parameter for all the troops,
then we need update all the files and we may miss some files
and some files may have bugs but because that type of soldier not appear
frequently, so we didn't notice that.
and so on. 
so I strongly suggest to use a daemon to handle all the different
types of troop. we have many samples for this skill.

4 anyway, it is nice to try to modify the most complex part of the mudlib
but be careful and discuss more if make big decision.

addoil :)


---
����: Fire
��Ŀ: >localmeeting
����: Tue May 18 20:01:24 1999
On Tue May 18 11:50:46 1999 Row wrote post #375:
> some player said he was called to attend meeting while
> he was doing a job(spy), sure he cannot get back and lost
> sth....is player supposed to be set to no need to attend
> meeting while doing job? pls check.

This is a little difficult. because the system hard to know if
the player is doing jobs or not.
but for our meeting system, it does have some problems.
so in the future, we probably need a parameter means
can't attend meeting.
but that need further consideration


---
����: Row
��Ŀ: localmeeting
����: Tue May 18 11:50:46 1999
some player said he was called to attend meeting while
he was doing a job(spy), sure he cannot get back and lost
sth....is player supposed to be set to no need to attend
meeting while doing job? pls check.


---
����: Fire
��Ŀ: about the war bug
����: Tue May 18 08:40:32 1999
because of the war bug,
I disabled the bandit attack temporaly
when the bug fixed, then re open
addoil all


---
����: Row
��Ŀ: serious problem
����: Tue May 18 01:01:15 1999
now the bug of war is becoming more serious, after several
bandits attacking, the soldier of an area was exceeding to
100000+
and used up the food and good of that area, whoever fire
or flee is online, pls look into it ASAP, thx


---
����: Flee
��Ŀ: current work
����: Mon May 17 03:21:10 1999
i use a mapping to store various typs of troops
and at the same time, the number of solider is 
still stored as integer. that is why the No of 
solider increase after bandit attack.
in order to solve this, there r many files got to
be modified.
about the strage file under /sgdoamin/event/war,
that is a reult of greping in that directory.
i have tried to remove it, but failed .. :(
i will try to fix that bug as soon as possible
and report any change in time .. :)

addoil all 


---
����: Fire
��Ŀ: a new wiz tools
����: Mon May 17 00:54:41 1999
a new wizard tool buzzer is created under
/cmds/wiz/ this is used to quick create rooms for sanguo area
test in new areas and see how it works, hoho
:)


---
����: Fire
��Ŀ: what is it?
����: Sun May 16 20:20:39 1999
when I use ls command under the path of /sgdomain/event/war/
then there is a file called "set_task("task_id". . . . .".
what is it ?
who create it ?


---
����: Fire
��Ŀ: flee, please check your code
����: Sun May 16 20:36:44 1999
Hi, flee

Please check your code for the war arrangement.
during the war arrangement, if we have 1000 soldiers
and we arrange 500 for the war, then this area will just have
500 soldiers left. then after the war, if we have 200 soldier
survived after the war, then our area should have 700 soldiers 
totaly. but now, your code doesn't submit the soldiers after the
arrangement. so this area will have 1200 soldiers after the war, 
This is a BIG BUG.
please fix it as soon as possible.
recently, my computer is broken, and I am terribley busy,
so I am sorry that i can't help you to fix this bug.
In fact, I dont' that it is a good idea to modify war system
now, bucause it is too complex now, and to write a new one will be
easier than modify old codes
I am sure that our war system need more features, but to add them
need a fully understand of the
old code's struture. but if you really like to imporve war system,
that is also fine.
just be careful and fully test the new stuffs. and be aware of that
some modification may cause other systems working incorrectly.

addoil :)


---
����: Row
��Ŀ: ����
����: Wed May 19 23:01:15 1999
������ÿ��������ڴ���һ��������һ�Ǳ��ڼ�ǿ
�����������ӹ������Ѷȣ�������ҾͲ����ڵ�

��Ҫ�������£�
�����������������ĳ�غ󣬼���������ķ�
��ʱ��������Ƿ�Ϊ���ع�Ա��������ʿ�����ǣ�
��ȫͨ���������򱻸�֪ask guard about enter

ask guard about enter �Ժ󣬼������뵱�ص�
���ҹ�ϵ��������40(������)��ȫͨ��������
��40�������ѡ������ҿ�ѡ���¸����������
10����50���ƽ𲻵ȣ�������ι����������ȡֵ
�жϣ����������������ѧ��������λ�ߵͼ���װ
���ȼ������ȡֵ�жϣ�Ȱ����������ϱ���������
��λ�ߵ��漴ȡֵ�жϡ����ɹ�����У������ɹ�
��ͣ��ԭ��(��Ͷ���������Ҫ���һ������)��

Ϊ��֤����ͨ�̣�����ȡ�ù����������ҽ����
̫�ش��õ�һ�����ƣ���Ŀ�ĵ�ʱ��������Ҫ���
����������ʾ��������ɽ���(���Ƴ�ʾ�����ʧ)��

���⻹������һЩ��ص�ָ���һ������������
������ӭ������һ������������Ϊ���죬������
���������趨������ڲ���ӭ����֮�е���ҾͲ�
�ܽ���ù���


---
����: Group
��Ŀ: war system
����: Thu May 20 00:44:49 1999
we will try our best to finish the thing in a week, but cant garentee....
if we cant finish it in a week, is that possible to open a test site
in another
port of same machine for testing?

hope can be done.
group


---
����: Fire
��Ŀ: about the char_d
����: Thu May 20 22:32:38 1999
I have modified char_d.c and char_obj.c
hope can fixed the bug in the char system.
please keep an eye on it, if still have the similar bugs


---
����: Ice
��Ŀ: ˽�� �����Ƥ���
����: Fri May 21 08:47:25 1999
���ڣ��������������е�POST����ʼ�������Ϸ���˸�����˽⣬
Ҳ�����кö��ڵ�PLAYERʱ��֪����IDEA��*grin
��֮�������뵱��ʦ������������Ϸ�������ƺ�����ʷʵ��
�������ҡ���������ʷ����papaya��wiz����Ϊ�������Ծ�ͷ��
���������ҵ������������һЩ dirty jobs and some suggestion,
�տ�������post����û�����������Ի�û���������ʲô����...:P
anyway, I am new here..:)
And my current task is to make maker in all SW cities
That's it.

������ա�


---
����: Row
��Ŀ: ����
����: Fri May 21 12:42:57 1999
��Ϸ�Ľ����Ǻ���Ҫ�ģ����Կ����б�Ҫ�������һ�����ǵ����ڵ�
���棬�������Ҹ��˵������ϣ�����Ҳ�Ѹ��Ե�������������ۡ�


%^H_YELLOW%^��ĥ����%^H_CYAN%^����ڣ�east��%^RESET%^

    ����һ���൱�¾ɵ�ĥ����ĥ���м���һֻ���ص�ʯĥ��������
��ĥ��¿��Ҳ�Ҳ������ˣ�ֻ�п��Լ�����ĥ�ˣ��㲻���������Ǿ�
��Ǯ��ʹ���������׻�����ĥ�����ſ���ȥ�ܿ���һ�øߴ�Ļ�����

%^H_GREEN%^����ɫ��%^H_RED%^̫�����߹�������ϡ�%^RESET%^


---
����: Tset
��Ŀ: >����
����: Fri May 21 12:50:09 1999
On Fri May 21 12:42:57 1999 Row wrote post #382:
> ��Ϸ�Ľ����Ǻ���Ҫ�ģ����Կ����б�Ҫ�������һ�����ǵ����ڵ�
> ���棬�������Ҹ��˵������ϣ�����Ҳ�Ѹ��Ե�������������ۡ�
> 
> 
> %^H_YELLOW%^��ĥ����%^H_CYAN%^����ڣ�east��%^RESET%^
> 
>     ����һ���൱�¾ɵ�ĥ����ĥ���м���һֻ���ص�ʯĥ��������
> ��ĥ��¿��Ҳ�Ҳ������ˣ�ֻ�п��Լ�����ĥ�ˣ��㲻���������Ǿ�
> ��Ǯ��ʹ���������׻�����ĥ�����ſ���ȥ�ܿ���һ�øߴ�Ļ�����
> 
> %^H_GREEN%^����ɫ��%^H_RED%^̫�����߹�������ϡ�%^RESET%^
the room exit color is user definable, if u really
want to overwrite it, at the end of set_brief add the colour code.
Also, there is always some of us that don't support full
chinese characters...thos special ones are ����, maybe
use some more general ones?

row's ��� is pretty good actually :)


---
����: Fire
��Ŀ: >����bug
����: Tue Jun 15 20:14:45 1999
On Tue Jun 15 10:00:40 1999 Zhanpu wrote post #503:
> ���Ѿ���������!;��ȷ��Ҫ�滻��n
> ������ʦ�б���  ������3����;��������������������������������������������
����
> ��������������������������;��С���Ĳɡ�ĩ�յ۹�������ү���������桹������(
zhan
> pu)                 ;��С���Ĳɡ�ĩ�յ۹�������ү���������桹������(zhanpu
)   
>              ;��С���Ĳɡ��һ��������̫����������ǧ��(ice) �             
   
>    ;����������������������������������������������������������������������
����
> 
> �����Ϳ��ܳ��ּ�����ͬ��id
> �����˼��Σ�������������,����żȻ��
> ������������bug

Wiz ����ͬʱ��¼��Ρ�
���Ǳ�MUD��һ���ص㡣����ǲ��еġ�
�����������ǵ�charϵͳ����¼���λ�����BUG
���Բ������¼���λ����ϡ�:)


---
����: Stefan
��Ŀ: >����bug
����: Tue Jun 15 16:14:51 1999
On Tue Jun 15 10:00:40 1999 Zhanpu wrote post #503:
> ���Ѿ���������!;��ȷ��Ҫ�滻��n
> ������ʦ�б���  ������3����;��������������������������������������������
����
> ��������������������������;��С���Ĳɡ�ĩ�յ۹�������ү���������桹������(
zhan
> pu)                 ;��С���Ĳɡ�ĩ�յ۹�������ү���������桹������(zhanpu
)   
>              ;��С���Ĳɡ��һ��������̫����������ǧ��(ice) �             
   
>    ;����������������������������������������������������������������������
����
> 
> �����Ϳ��ܳ��ּ�����ͬ��id
> �����˼��Σ�������������,����żȻ��
> ������������bug

������� bug��Ϊ�˷����������ʦ�ǿ���ͬʱ login ����˵ģ���ҾͲ����ˡ�


---
����: Zhanpu
��Ŀ: ����bug
����: Tue Jun 15 10:00:40 1999
���Ѿ���������!;��ȷ��Ҫ�滻��n
������ʦ�б���  ������3����;������������������������������������������������
��������������������������;��С���Ĳɡ�ĩ�յ۹�������ү���������桹������(zhan
pu)                 ;��С���Ĳɡ�ĩ�յ۹�������ү���������桹������(zhanpu)   
             ;��С���Ĳɡ��һ��������̫����������ǧ��(ice) �                 
   ;��������������������������������������������������������������������������

�����Ϳ��ܳ��ּ�����ͬ��id
�����˼��Σ�������������,����żȻ��
������������bug


---
����: Group
��Ŀ: applyleave
����: Tue Jun 15 23:21:43 1999
need go back to China for holiday, hence have to leave for 
almost 1 month. i will try to access here when i at home.

addoil all..:)


---
����: Fire
��Ŀ: ��������µ�����
����: Wed Jun 16 01:32:04 1999
1 add area
@AREA_D->add_area(<a_id>)
2 set level
@AREA_D->set_area(<a_id>,"level",<level>)
3 set name
@AREA_D->set_area(<a_id>,"name",<name>)
4 set path and so on
/cmds/area/initarea
5 create warroom
/cmds/area/createwarroom
����4,5������������������һ��ִ�С�
6 ��buzzer���췿��
7 ����meeting,fly,go,market,prison�ȡ�


---
����: Fire
��Ŀ: about ��ְ
����: Wed Jun 16 01:11:51 1999
�ط���ְ��һ������취��
���ſ�����Խ��Խ��Ĺ�����Ҫ��Ա�任������
���Ƕ��ڵط���ְ�������ܵ���ְ��ȱ���Ϲ�
�ʸ�����ƣ�ʵ��һЩ���ܺ��鷳����������
��BUG������������ְ��һ������Դ��ؼ�
������Ѷȡ�
��ְ��ID�� R_SG, ��ֵΪ 1000
�����÷���
CHAR_D->set_char(<id>,"ranklocal",R_SG);


---
����: Fire
��Ŀ: >applyleave
����: Wed Jun 16 00:18:48 1999
On Tue Jun 15 23:21:43 1999 Group wrote post #506:
> need go back to China for holiday, hence have to leave for 
> almost 1 month. i will try to access here when i at home.
> 
> addoil all..:)

hi group,

have a good time :)

we are waiting for you, addoil :)


---
����: Row
��Ŀ: sample hp
����: Sat Jun 19 02:14:44 1999
��������״��������̬��������

����Ѫ��   340 / 340 ( 340 )
�Ѿ����   484 / 484 ( 484 )
��ʳ���     0 / 200
����ˮ��     0 / 200

������������������������־��


---
����: Fire
��Ŀ: about char
����: Sat Jun 19 07:20:51 1999
because we have about 100 area
so we have about 100 boy, 100 guard and 300 guy
ids in char_d. that is about 500 records
which will cause the char_d operation much slower
so i change them, so there will be no record for
boy, guard and guys. and i have also adjust most
related job file and body files this may cause
some bug. please keep one eye on it
:)


---
����: Row
��Ŀ: save memory and finish job
����: Sat Jun 19 01:36:51 1999
fire, u compress the npc's action, but seems player cannot finish job
leh, coz everytime they wanna find a npc, the boy will tell him
there r a lot of xxxx becoz of the npc is sleeping, pls check it.


---
����: Row
��Ŀ: sample score
����: Sat Jun 19 01:20:31 1999
�򣽣�����������������  ��  ��  ����������������������
��                                                  ��
������    �䡿����ʮ��       ����    �𡿣���       ��
������    ������18           ����    ı����29       ��
������    ������50           ����    ò����50       ��
���������书����37<+9>       ��ɱ �� ������13<+50>  ��
������ �� ������28<+43>                             ��
���������ֵܡ�����           ���ᷢ���ӡ�����       ��
������ �� �������һ��       ���� �� �ء�������     ��
������͢��ְ��������ʦ       ���ط���ְ����������ְ ��
����ٺ    »����5            ����    �ϡ���100      ��
������    ��������¹��ԭ(18911)                     ��
������ѧ����������ͨ����(11)                        ��
��                                                  ��
�򣽣�������������������  ��  ־����������������������

i've tried to add color in it, but the display always messed
up, anyway, is this pattern good? if so, i will try to adjust
the score lah. hehe..


---
����: Fire
��Ŀ: a useful function
����: Fri Jun 18 21:32:02 1999
����MUD��CPU����������MUD��CPU������ö�
һ�����õĺ����ǣ�time_expression
��һ���ֵ���ʱ�����磬��λ����������̸��
������첽�뿪�ˡ�
����������ڲ�����һ��������ִ��ʱ�䡣���磺
@time_expression(CHAR_D->find_char("zhang fei"))
���Բ���CHAR_D->find_char("zhang fei") ��ִ��ʱ�䡣
�Ż�ǰ��ִ��ʱ��Լ��5xxx micro second
�Ż����ִ��ʱ��Լ��4xx micro second
����ˡ�:)


---
����: Stefan
��Ŀ: Graphics MUD 
����: Fri Jun 18 14:45:37 1999
http://www.pchome.com.tw/news/880421/19990421-6.html

This is an old news, but it mentioned graphics  San Guo from KOEI.
Recently GKK (Graphics King of Kings) will be publicly released in Taiwan,
and they will charge users for playing it.


---
����: Fire
��Ŀ: compare our mud with xyj
����: Thu Jun 17 07:14:44 1999
xyj has about 60 players online and
with the status is :
���� 71 λ��������У�ϵͳ������19.55 cmds/s, 1.67 comp lines/s

our mud with about 10 ppl on line
the status is:
0.75 cmds/s, 80.77 comp lines/s

our comp lines/s is much bigger than XYJ's



---
����: Fire
��Ŀ: the stuffs in area_d
����: Thu Jun 17 06:33:36 1999
because there are many types of stuff in area_d
so i change it to a map "st" in area_d
can use AREA_D->get_area(<id>,"st") get the whole thing in one area
the old function AREA_D->get_area(<id>,<stuff id>)
and AREA_D->set_area(<id>,<stuff id>,<num>) still working


---
����: Stefan
��Ŀ: about crash
����: Wed Jun 16 15:55:58 1999
Our driver log shows a lot of pending messages for net_dead users,
I have changed user object so that messages sending to net_dead user
will not be sent out. 

This obviously is not the direct cause for crashes, if you witnesses
a crash, please describe what you saw :)


---
����: Stefan
��Ŀ: >error caught in log
����: Wed Jun 16 15:52:37 1999
On Wed Jun 16 15:48:11 1999 Stefan wrote post #512:
> object /sgdomain/area/guan/huayin/vkitchen: eval_cost too big 1000000
> object /secure/simul_efun: eval_cost too big 1000000
> object /sgdomain/obj/foodanddrink/shuihu#32453: eval_cost too big 1000000
> 
> This means there is infinite loop, and may cause everything else to hang.

I've looked at those files, both vkitchen and shuihu are just inheriting
other modules or objects under std/. This means something fundemental
is screwed up. This kind of error is hard to trace... :(

All please be careful to avoid infinite loops in your coding.


---
����: Stefan
��Ŀ: error caught in log
����: Wed Jun 16 15:48:11 1999
object /sgdomain/area/guan/huayin/vkitchen: eval_cost too big 1000000
object /secure/simul_efun: eval_cost too big 1000000
object /sgdomain/obj/foodanddrink/shuihu#32453: eval_cost too big 1000000

This means there is infinite loop, and may cause everything else to hang.


---
����: Fire
��Ŀ: the command of cpu
����: Thu Jun 17 07:28:13 1999
I updated the command of cpu
so it will give more information


---
����: Row
��Ŀ: about area development
����: Thu Jun 17 23:23:41 1999
ǰһ��������ĵ�ʱ����ᵽ�˹��ڵ�����չ��һЩ���Ե�
�޸ģ��Ҹ�����Ϊ�൱�á��������ұȽ�æ�������������Ͳ�
����һ�£�ϣ��û�в��

���ڵĵ�����չ��ʽ�൱�ĸ��ӣ����й�ҵ����ҵ��ũҵ��ֵ
Ӧ����ռ�Ƚ��صı�����(û����ϸ����ʽ����֪���ǲ���)��
��Ŀǰ��Ҳ�û��һЩ�����ķ����������Щָ������������
���Լ�һЩ������ʵ�֣����翪������Ĺ����Ϳ������ũҵ
ֵ�ȵȡ�Ϊ���չ������أ����齫����ֵ��ģʽ�ĳ�����
����Ҽ���ֵ�ĵȼ�/ ����ֵģʽ����ɹ����������Ӧ��
��ֵ��������ֵ�ﵽҪ���Ժ���ȼ��������ؼ���������
��ʽ���Ȳ���̫��Ҳ����̫���ס��һ������ǣ��ȼ���* ��
����* ����ֵ��

����ͨ��ʲô��������չ��Ӧ��ֵ�����⣬��Ҫ�࿼�ǿ��ǡ�
�һ��ڽ�����д���ƻ���


---
����: Fire
��Ŀ: a new wiz tool
����: Fri Jun 18 10:17:52 1999
cutter used for create npc char quickly
just type "cutter", all is easy


---
����: Fire
��Ŀ: I will begin the stuff and base system (���ʺ���������)
����: Fri Jun 18 10:19:14 1999
the main daemons is /daemons/stuff_d.c


---
����: Row
��Ŀ: something in war
����: Wed Jun 16 12:12:46 1999
fire, maybe becoz u changed pos, now attacking part in war,
only ���� can see warinfo, not others
and...after war, only the officer in the leader's troop will
be assign as the occupied area's officer and get rewards.
is that the right thing?


---
����: Row
��Ŀ: >���ء���Ʒ
����: Tue Jun 22 04:58:13 1999
this file is:
/sgdomain/txt/stuff_sys.txt

can check it anytime and adjust it.
addoil


---
����: Row
��Ŀ: ���ء���Ʒ
����: Tue Jun 22 04:39:30 1999
��ice�İ����£���������һ�»��ء���Ʒ���嵥��
���أ�

һ����ԭ���������أ��Զ�����һ��ԭ�ϣ�

�ֳ�����ʯ����ͭ�������Գ���������ũ������԰

�������ӹ��������ӹ��ͽ�����ԭ�ϣ���Ϊ���Ʒ��

��ľ������ʯ����ұ��������ͭ�������׳�

��������Ʒ��������һ������ͽ��������ϣ���Ϊ��Ʒ��

��������ѱ������ͷ����Ƴ����پ߳�

��Ʒ��

һ����ԭ�ϣ��Ӹ�����������������

ԭľ��ʯ�ϡ�ͭ��ʯ������ʯ�����������ʳ��ˮ��������

���������Ʒ�������ӹ���

ľ�ġ���ʯ��Բʯ����������ͭ����Ƥ�����⡢�޽�

��������Ʒ��������ϳ����Ŀ���ֱ��ʹ�ü��������ӵı�
      ��Ʒ��

ľ�ˡ���������������Ƭ��ͭƬ�����ء�����ս���ơ�
�ټס�����


���ں��ֻ��ز������ֲ�Ʒ�Ƿǳ�����ģ��������һ�¸��ֳ�Ʒ
����ϼ�����;��

ǹͷ+ľ��-->��ǹ��������ǹ����
��Ƭ+��Ƥ-->���ף�����������
��Ƭ+ľ��-->���������ӵ�����
���ƣ��������Ʊ���
��Ƥ+�޽�+��Ƥ-->���������λ������
ս�����������
ͭƬ+��Ƭ+��Ƥ-->�ؼף������ؼ������
��+ľ��+����-->����������������
ʮ��ľ��+ʮ������+ʮ����Ƭ-->ս��������ս����
��Ƥ+�޽�-->Ƥ�ף��������׹�����
��Ƥ-->ˮ��������ˮ����
��+�޽�-->ǿ�����������
����+ľ��-->���У�����ɽ����
����-->���У�����ˮ����

(�����Ƕ���������������Ҫ��������Ʒ������������������������
���)
�磺Բʯ+ľ��-->��ʯ��

��+����+ˮ��+��ʳ+���������������й�Ա��������ʿ������Ա��
�ҳϡ�

�������Ƿ��ȣ����÷�ʯ+ľ��+����Լ�̳Ƿ���ÿһ�ξ���ս��
���ƻ����Ƿ��Ƚ��͡�

���п��ܵĻ��������������ϵͳ����ԭ�еȼ���ˮƽ�ϣ��ﵽһ��
��Ҫ�󣬱�����ҵ��ָ�������٣�������һ�����ʽ���Ʒ���Ϳ�����
��һ������������(A��B��C) ��ÿ���ȼ�����ָ���������ơ�2C��ָ
������3A���п��ܵġ����һ���ÿ��У�����������ۡ�

�����Ǽ򵥵Ĺ�����Ʒ�����ص��嵥�����ھ����������ʱ�䡢����
�ȵ���Ҫ�����ۡ�������©�򲻺���ĵط����뼰ʱָ����

���ڶ�Ӧ�Ĺ��������ϣ��������и�����


---
����: Row
��Ŀ: >some ideas about gini
����: Tue Jun 22 00:27:07 1999
agree ice


---
����: Ice
��Ŀ: some ideas about gini
����: Tue Jun 22 00:07:54 1999
I dun know the functions that fire may plan to add on gini,
just some personal ideas here..:O~

gini
��ӻ����ͳ�һյ��������ƣ������Ӳ��˲�. . . . 
һ�����̴ӵ���ð���������ػ���һ����ɫ��־��顣

gini help
����˵�ҿ��Ը������µ���ʾ��
1���Ҹ�����ûǮ����ô�죿��gini money
2���Ҹ���ô�Ǹ��������أ���gini skills
blah blah

gini money
����˵��ûǮѽ����ȻҪ������Ǯ�����Ķ�����ѵ����ѽ��
���Ͷ���������������û�У�����help money�ɡ�
������͵͵�����㣺��˵������һЩ���˵Ĺ������н���
�ĳ���Ӵ������help xianren�ɡ�

gini skills
����˵����������ѽ��������ڻ�������һ��ʱ����ܳ�ʦඣ�
��׬��Ǯ���ҿ��Ѽ����һ��ѧ�ʣ�����������ż����Ļ�������
����Ա��ѧѧ��ѧ��������30����Ч��֮�����Ҫѧ��ֻ�е���ඡ�
blah blah

this kind of help is not formal help file, but can be indicators,
so just for get the idea of ����, gini can do it now..:)
how do u guys think about it?


---
����: Fire
��Ŀ: >�������˹���
����: Mon Jun 21 23:57:43 1999
On Mon Jun 21 23:52:05 1999 Ice wrote post #536:
> �Ҿ������˹����Ǻ��ʺ��������ģ���Ϊ����һ�㲻��Ϥ��ͼ�ͳ��У�
> ���˹���ʹ�����л�����ȫ����Χ�����Σ��������ڵĻ�����������
> ���������ˣ������˵Ĺ���һ���������������ף�����Ҿ��ø�
> �����ƹ����˹��������ڵ�������û������Ӧ�İ����ļ�����Ʒ����
> ��ָ�����һ�����������ɰ����ļ���������Ʒ�����ָ����Ҫ����
> ���ݿ��ƶȣ�Ȼ������һ���������ڵ�NPC�����Ը�������ĸ�������
> ��Ҫ�Ķ�����������������ÿ���ݵ���������һ��������ָ�������ȫ
> ����Χ����Ʒ�ķֲ���
> 
> but the point is need code the province system first, then create
> the NPC, but seems now everyone is busy... :PPP, so who can code it yah?
> * fool

* point ice :)


---
����: Ice
��Ŀ: �������˹���
����: Mon Jun 21 23:52:05 1999
�Ҿ������˹����Ǻ��ʺ��������ģ���Ϊ����һ�㲻��Ϥ��ͼ�ͳ��У�
���˹���ʹ�����л�����ȫ����Χ�����Σ��������ڵĻ�����������
���������ˣ������˵Ĺ���һ���������������ף�����Ҿ��ø�
�����ƹ����˹��������ڵ�������û������Ӧ�İ����ļ�����Ʒ����
��ָ�����һ�����������ɰ����ļ���������Ʒ�����ָ����Ҫ����
���ݿ��ƶȣ�Ȼ������һ���������ڵ�NPC�����Ը�������ĸ�������
��Ҫ�Ķ�����������������ÿ���ݵ���������һ��������ָ�������ȫ
����Χ����Ʒ�ķֲ���

but the point is need code the province system first, then create
the NPC, but seems now everyone is busy... :PPP, so who can code it yah?
* fool


---
����: Fire
��Ŀ: >gini ��������
����: Mon Jun 21 21:27:18 1999
On Mon Jun 21 16:50:54 1999 Stefan wrote post #534:
> ���ҷǳ� annoying��˵����Ƶ��̫�ߡ�
*blush

I will adjust it
can row please help to correct some words :)



---
����: Stefan
��Ŀ: gini ��������
����: Mon Jun 21 16:50:54 1999
���ҷǳ� annoying��˵����Ƶ��̫�ߡ�


---
����: Fire
��Ŀ: ��������ϵͳ
����: Mon Jun 21 06:29:36 1999
����flee��������ϵͳ�����룬�е�������˼�ܺã����Һ�ROW��ICEǰ����
���۵�ϵͳ����������ݵģ�ֻ���ڲ���ϸ������һЩ�仯���������벹��
һЩ���顣
1 ���ڲɼ�ҵ�ͼӹ�ҵ��
      ʵ���ϣ��������Ǻ����Ƶ�ϵͳ��������㶼����һ����������Ļ�
  ��(�ڲɼ�ҵ�����������󳡣��ڼӹ�ҵ���ǹ���������������)���Ϳ���
  ���������ʡ�����ͬ���ǣ��ӹ�������Ҫԭ�ϣ����ɼ���������Ҫԭ�ϣ�
  �ӹ����ؿ����ڴ󲿷ֵ������죬���ɼ�������һЩ�������ơ������С
  �Ĳ�ͬ�����ڲ������������֣�������ϵͳ������ϵͳ�Ķ����������࣬
  �������غ��������ʡ������ݸ�ʽ���£�
      ���ʵĶ����ʽ��
        spear :   // ��ǹ
         ([  "name" : "��ǹ",
             "base" : // ����������ǹ�Ļ���
                ({  : // �˴���������Ҫ����ĳЩ���ʶ��ֻ��ض�������
                   ([ "type" : "weapon plant", // ������
                      "level" : 2 // �ñ���������С�ȼ�
                   )]
                )}
             "quality" : 20, // һ�����������׼��
             "consume" :     // ������Ҫ����
               ([ "gold" : 10 // ʮ����
                  "spear pole" : 20  // ǹ��
                  "spear head" : 20  // ǹͷ
                  "power" : 500 // ����������������һ������󵫺�
                                // ��Ҫ�Ĳ�������ͬ�Ĺ�����������
                                // ��ģ��ͬ���䵥λʱ�������ṩ��
                                // ������Ҳ��ͬ�����һ�������ĵ�
                                // λ��������50����ô����Ҫʮ����
                                // λʱ��������10�˳�ǹ����������
                // ���ļ��㣬��Ҫһ������ƽ��Ĺ�ʽ����Ҫ�ۺϹ���
                // �ĵȼ��������˿ڣ�������Ա���������ܵȼ������
                // ��JOB�����ء�
                ]),
           ])
                           
     ���ض����ʽ��
       "ironmine" : // ����
          ([ "name" : "����",
             "area" : ({ "taiyuan","jianning",. . .}),
                    // �ɽ�������صĵ��������û�У����ʾ���ܵ�
                    // �����ơ�
             "level" : 3 // �ɽ���������ص���͵����ȼ���
             "lev1" :  // ����һ����Ҫ������
                ([ "population" : 10000, // �����˿�һ������
                   "safe" : 70, // ���ذ����� 70 ����
                   "gold" :10000, // ��Ҫ�� 10000
                   "energyout" : 10, // ����������
                   "time" : 600, // ��Ҫ600����ɽ���
                ]),
             "lev2" :  // ����������Ҫ������
                ([ "population" : 15000, // �����˿�һ��������
                   "safe" : 90, // ���ذ����� 90 ����
                   "gold" :10000, // ��Ҫ�� 10000
                   "energyout" : 20, // ����������
                   "time" : 600, // ��Ҫ600���������
                ]),
             "lev3" :  // ����������Ҫ������
                ([ "population" : 20000, // �����˿���������
                   "safe" : 100, // ���ذ����� 100 ����
                   "gold" :10000, // ��Ҫ�� 10000
                   "energyout" : 30, // ����������
                   "time" : 600, // ��Ҫ600���������
                ])
          ]) // ���ܻ���Ҫ����һЩ����������
2 ����˽�к͹��С�
  ����һ������Ȥ�����룬����Ҫ����ϸ�Ķ��塣���磺
      a. ˭����ӵ��˽�˲�ҵ��
      b. ���ӵ��˽�˲�ҵ��������ʲô��
      c. ӵ��˽�˲�ҵ�ĺô���ʲô��
      d. ��û�бײ���
      e. ���ݴ洢λ�ã���ʽ��
      f. �͹��в�ҵ�Ĺ�ϵ��
3 ������ʽ��
  ������ʽ���������֣�
      a. ȫ�Զ�����Ŀǰ����ʳ��������ʱ���У�������ҷ��¡�
         �ŵ㣺��Ƽ򵥣������ײ���BUG��
         ȱ�㣺���û��̫��Ĳ��롣
         �ʺϳ�����ҽ��٣�һ�����Ҫ�չ˴󲿷ֵ��������Ρ�
      b. ȫ�ֶ�����Ŀǰ������ϵͳ
         �ŵ㣺ǿ����Ҳ��룬�����Ľ������ҵĸ��������ȡ�
         ȱ�㣺NPC��û���û�м�ֵ��ϵͳ������̫ƽ�⡣
         �ʺ���ҷǳ�������Σ��������ķ�չ����ҵ��໥������
         �໥��Լ�ﵽƽ�⡣
      c. ���Զ�����Щ��Ŀǰ��ս��ϵͳ����Ҷ��Լ��Ĳ�����ȫȨ
         ���ƣ���NPC����Ҳ���൱��ս������
         �ŵ㣺�������Ǳ�MUD������ģʽ��
         ȱ�㣺�����Ѷȴ�������BUG
    ����Ϊ��Ҫ����������ϵͳ��ò��õ�����������ʽ����û����Ҹ�Ԥ
    �����ֻ�����ٸ�Ԥ��ǰ���£�ϵͳҲ����ݵ��������ȣ��˿ڣ�NPC��
    Ա�ļ��ܵȼ������أ�����Ҳ�����һ�������������������Ҹ�Ԥ��
    ���ͨ������JOB������ʹ�������ߣ���Ʒ�ṹ���ḻ������ƺͱ����
    ��һ����С��
4  ������ҵ������ҵ
   flee������ɵ�С����maker���е���ҵ�ж����д��⣬������Ϊ��Ӧ��
   ֻ��һ�������Ҹ��˻��һ��С����ҵϵͳ�����ģ����ҵ�����
   Ӧ��ͨ���Թ����̶�Ϊ�������ҵϵͳ���������䣬���������½��飺
     a. ��������ڱ����ڽ��С�
     b. �������յ�������ڡ�
     c. ����Ҫ�ɹ��һ�����׼��
     d. ��������У������Ա�ĵ�����Ϊ0��������ְ��ΪR_SG(=1000)����
        ���Ͳ���������������飬ս����ɧ�š�
5  ��ѡ
   �ұ����븺����һ���ֵ���ƣ��������ϰ�����ˣ�û��̫��ʱ�䣬������
   ����Ҫ��������Ұ�������(gini)����ƣ�������һ���־���flee����row
   ice��group�μӣ�����һЩ������ϵͳ�����Եĵ���������ϣ�����������flee
   ����һЩ��ϸ��POST:)���⻹�а����ļ����ı�������޸��ϵ����ݽṹ����
   overrideһЩ�ϵĺ�����ʹ���ǻ����Թ�����ȷ�������Ϳ��Լ�����ຯ����
   ����������


---
����: Fire
��Ŀ: a very difficult bug
����: Sun Jun 20 05:33:29 1999
a very difficult bug has be catched in char_d
sweat :)
char_d is the core daemon, should be bug free !!


---
����: Flee
��Ŀ: about bao dating
����: Sat Jun 26 03:23:49 1999
ok now, check it at /sgdomain/modules/m_charnpc/xianren


---
����: Row
��Ŀ: >����(cmd jieyi)
����: Wed Jun 23 05:00:46 1999
��ƪ�������������ȱ�˵㶫����
���������Ʒ��
��С������ĳ���������򵽣�����һ�ѣ������̸첲:)��
          ��Ѫ���뺣�룻
��


---
����: Row
��Ŀ: objects for jieyi
����: Wed Jun 23 05:48:38 1999
i have created ��¯ and �㣺
/wiz/row/obj/xianglu.c
/wiz/row/obj/incense.c

fire check check to see see if they r useful bah..xixi.


---
����: Fire
��Ŀ: >objects for jieyi
����: Wed Jun 23 06:53:03 1999
On Wed Jun 23 05:48:38 1999 Row wrote post #545:
> i have created ��¯ and �㣺
> /wiz/row/obj/xianglu.c
> /wiz/row/obj/incense.c
> 
> fire check check to see see if they r useful bah..xixi.

good point, will consider it next week :)



---
����: Fire
��Ŀ: to row
����: Wed Jun 23 07:29:30 1999
sorry row,
I upload the gini_d.c
and i forget to download it first, so may be 
some ������ֻ����ˡ�
sorry

when you have time, can you help me to fix them again :)


---
����: Ice
��Ŀ: ����rumors�Ľ���
����: Thu Jun 24 19:35:40 1999
�����������ģ�

���Ƚ��������ƶȣ��Լ�һ����һ�İ��������������ǻᵽ���ߵģ���
���ڵ�����һ������֪��������Ʒ��ʲô�ط������򵽡�

��boy���һ��ܣ�ask boy about rumors

ask boy about rumors
�����ƤС�к��ʵ�������֪�����û����˵ʲô��Ϣ��
��ƤС�к�����һЦ������������һЩ������֪��ʲôѽ��
��ƤС�к�˵����֪��������Щ�˵�������
1����������2�����ӣ�3�����ӽ���4���ڼ���5����ȡ�
��������ѡ��1
��ƤС�к�����������ѽ��������˵��������������
��ƤС�к��ֲ�˵���ˡ�
������Բߣ�1����Ǯ��0�����ˡ�
1
//if give money, it can be randomly range from 5 to 10 silver
�����ĵ�ƤС�к���ͷ˵������������ӣ��㰮��ô������ô���ɡ�
��ƤС�к����˵�����������
�����ƤС�к��������ӡ�
��ƤС�к�˵������˵���������������ȥ�ˡ�
0
//if not give money
��Ե�ƤС�к��������ˣ���ôһ��С��ҲҪǮ���ߣ�
��ƤС�к�һ���Ĳ������ߣ�С�����Ժ�����ҡ�
��ƤС�к���ǰ���ؽ���һ��ץס������Բ������������ؽ�������������

��ѯ��boyҥ����Ϊ������ҿ����ҵ�����������Ҫ�����˹�����ʱ�򣬲�
���ȼ�ʮ���ӵ�ҥ�ԣ��������ǻ����Լ���Ѱ���̶ӵ�ѡ����ִ��ҥ
��Ƶ��һ��ʹ�á�


//go luoyang, find ������
ask bao dating about something
�������������һ�Ϲ�����С������һ��������಻֪�δ��ɵã�������ָ�̡�
����������˹����˵����Ҫ��ʲô����ѽ��
������Ҫ����Ʒ��ID
�������ʲô��Ʒ��buyi
����������Ҳ��¡�
���������ˡ��ٺ١�һЦ�����ҵ�Ȼ֪����ֻ��������������������
������������һ�ۣ�û��˵��ȥ��
������Բߣ�1����Ǯ��0��������
0
//no money no talk
����ԥ��һ�£��԰�����˵��ʵ�ڲ�����˼��С�������ͷ�ȽϽ���
���������ߡ���һ����һ�����������ӣ������Լ������Ұɣ����ҡ�
1
//if give money, random from 10 to 50 silver
��������Ц����æ��һ������׼���õĺ���Ž��������Ļ��
����˰�������ʮ�������ӡ�
�������������ϷŹ��ˣ��ã��͸�����ɣ�������Ӻ�ݣ�yongzhou��һ�������򵽡�

info p yongzhou
������changan����         ����ԭ��wuzhangyuan����
��أ�wuguan����          ���ȹأ�hangu����
���أ�tongguan����        ������huayin����
������jingyang����        ������xianyang����

��ʵ�ϲ��²�ֹ��Ӻ�ݿ����򵽣�������������и���Ʒ�������ݣ�province����
�����һ��������
������������������С�������������ҵ�������Χ���ṩ��Ʒ��Ϣ����Ҫ����ĳ
Щ��Ʒ����ҡ�




---
����: Ice
��Ŀ: �ݿ��б�
����: Thu Jun 24 19:36:32 1999
��������������ʮ���ݾ�ʮ�ſ���

���ݣ�����������
���أ����ǣ��׾�����ƽ������ɽ����ƽ��

���ݣ������Ŀ���
��Ƥ��ƽԭ����ӣ����š�

���ݣ�����������
���ϣ�������������

���ݣ������忤��
�������������գ����������

ԥ�ݣ������Ŀ���
������ۣ����ϣ��ٶɡ�

���ݣ������忤��
���ݣ�С�棬���������꣬��а��

���ݣ������Ŀ���
̫ԭ���ϵ������Źأ�������

˾���������߿���
���������ιأ����أ��ųأ���ũ���𣬲����¡�

Ӻ�ݣ������˿���
����������ԭ����أ����ȹأ����أ�������������������

���ݣ������˿���
������¤������ˮ���ҵ�����ͤ���������ش����²֡�

���ݣ������˿���
���У���ɽ�����ͣ���ƽ�أ�����ɽ���������������ǡ�

���ݣ�����������
�ɶ�������أ����ݣ����������������ϡ�

�����ݣ������߿���
��������ӹ����Ұ���Ϫ�������£����ģ���ڡ�

�Ͼ��ݣ������˿���
���꣬���꣬���������ݣ����꣬���꣬��ɳ��������

۫�ݣ�����������
®��������ɽ��������۶������ɣ��ԥ�¡�

���ݣ������߿���
��ҵ���ٴ������ǣ����������ڣ��⿤�������

���ݣ�����������
�Ϻ������֣�®�ꡣ




���ڵ�һ�Ŀ�������Ϊ�������׸�ʲô�ġ� * fool


---
����: Ice
��Ŀ: �ݿ��ֲ�ͼ
����: Thu Jun 24 19:37:33 1999
                      ������ʱ�����ݷֲ�ͼ��
�򣽣�����������������������������������������������������������������
��                              ��������������������������������������
��      ����          ������������       ��              ��       ����
��      ��������      �� ��  �� ���������Щ��������Щ��������Щ����ȡ�
��  ������    ��      ��  ��������      ����      ����      �� �� ����
��  ����    �ݩ��������ةЩ�        ��  ��      �ݩ�      �ݩ� �� ����
��  ���Щ����Щ� Ӻ     �� ˾       �����ة��Щ����ة��������ة����ȡ�
��    ��    ����     �� ��          ��ԥ  �ݩ�    ��        ��    ����
��    ����  �ݩ����������ة�����������  �����ة����������������Щ�����
�����Щ�      �� ��                 ������   ��               ��    ��
����������������           ��           ����������       ��   ��    ��
���� ��       ��������������������  ��  ��  ۫  ������������  ��    ��
����          ��                ���Щ�����      ��        ��  ��    ��
����       �� ����   ��   �ݩ������ة�����      ��        ������    ��
����          ��            �� ��    �� ��  ��  ��                  ��
���������������ة������������ة����������ة�������                  ��
�򣽣�����������������������������������������������������������������


draft


---
����: Fire
��Ŀ: ֧���ݵ����
����: Fri Jun 25 02:18:11 1999
�ҽ�д���룬ICE������Ϣ


---
����: Ice
��Ŀ: �������˹������޸�
����: Fri Jun 25 10:48:40 1999
1. �ڼ������İ��ţ�should be goods available in makers
today i tried yuji's job, but it required �ӵ�, which i just made yesterday, 
not in makers yet;
2. ������˹����Ľ��ӽ���
xuzijiang -> 2 gold //because need travel in many cities, need
entrance fee for officers
huatuo -> 2 gold //because need travel in cities
zuoci -> 2 gold //same as above
yuji -> 4 gold //because need both travel and buy objs

3. yuji's job's objs should be changed to lv 0 -> lv 2, which may
sell after job done

addoil flee
* smirk


---
����: Ice
��Ŀ: some comments of gini old
����: Fri Jun 25 20:34:29 1999
���� gini old ��Ŀ������ȷ�ģ������Ƿ񷽷��Ͽ��ԸĽ�һ�¡�
ÿ����Ҷ���Ȩ��ѡ��ﲻ�������֣��Լ���ΰ�����Ҫ�ڰ�
�ͻ�����棬���������ʧ֮��ѡ�����ƺ����������һ���ֵ�
Ȩ����Ʃ�����������뱻���˴���Ҫר����ĳһ�������ʱ��һ
���ӱ�ץȥ�ˣ����ֿ�Ц���õĸо���
���⣬�������жϰ����Ƿ���Ч���Ƿǳ����۵����⣬����������
���˰�����࣬�������һ�仰����ˣ��ǡ�����

�����Ƚ����ѡ�����أ�ֱ�����µ������Ľ��Ź���ʹ�á�

addoil.:P


---
����: Ice
��Ŀ: suggestion of gini
����: Tue Jun 22 22:38:53 1999
//After login

ͻȻð��һ�����̣������У�һ����ɫ����ݸ���һյ��ƣ�˵����
������ı����񣬵�����Ҫ��ʱ��ֻҪ���� %^H_BLUE%^gini%^RESET%^ �Ҿͻ�����㡣

//then gini auto hide, or add a sentence as following
��ɫ����˵�������������ڲ���Ҫ�ң�ֻҪ���� %^H_BLUE%^gini
away%^RESET%^ �Ҿ�
��ص�����

//gini appear
gini
��һ����ƣ���ɫ���鼱æ��Զ��Ʈ����
��ɫ���鿴���㣬̾�˿������ðɣ��ҿ��Ը���������Щ��ʾ��
1���������֣���ô�棿��%^H_BLUE%^gini newbie%^RESET%^
2���Ҹ�����ûǮ����ô�죿��%^H_BLUE%^gini money%^RESET%^
3���Ҹ���ô���Ӹ��������أ���%^H_BLUE%^gini skills%^RESET%^
4��ʲô��������ѽ����%^H_BLUE%^gini job%^RESET%^
5����Ҫ��ܣ���Ҫ�����书����%^H_BLUE%^gini fight%^RESET%^
6����Ҫ���٣���%^H_BLUE%^gini dangguan%^RESET%^
7���ҵ����ˣ�Ȼ���أ�%^H_BLUE%^gini officer%^RESET%^
8����Ҫ���̣���ô��%^H_BLUE%^gini war%^RESET%^

//gini's tips
gini newbie
��ɫ�����������������ͷ��������ѽ���ȿ��� %^H_BLUE%^help newbie%^RESET%^ ��
�� %^H_BLUE%^help starts%^RESET%^ �ɣ��úü�סһЩ���Ʃ�� map, ask

gini money
��ɫ����˵��ûǮѽ����ȻҪ������Ǯ�����Ķ�����ѵ����ѽ��
���Ͷ���������������û�У����� %^H_BLUE%^help money%^RESET%^ �ɡ�
��ɫ������͵͵�����㣺��˵������һЩ���˵Ĺ������ͺܸ�Ӵ��

gini skills
��ɫ����˵����������ѽ��������ڻ�������һ��ʱ����ܳ�ʦඣ�
��׬��Ǯ���ҿ��Ѽ����һ��ѧ�ʣ�����������ż����Ļ���������
��Ա��ѧѧ��ѧ�������� 30 ����Ч��֮�����Ҫѧ��ֻ�е����ˡ�
����ȿ��� %^H_BLUE%^help learn%^RESET%^ ��

gini job
��ɫ����˵������������������û����ȿ��� %^H_BLUE%^help basicjob%^RESET%^��
����Ĺ����ѶȲ�һ������������㾻�����׵����Ļ����ٺ٣���ô
�����ѧ�����ͺ������ˣ����� %^H_BLUE%^help robot%^RESET%^�ɡ�
��ɫ����������üͷ���ֶ���˵������û�иɹ���ģ�����������
��ɫ����ѹ������������˵����ͳ��ع��������ף������ż�����
���ǡ��������ֻ�������ֹ����Ļ�����ѧ����һ�����������ԡ�����

gini fight
��ɫ�������һ��˵�����������Ǻ�����ηѽ����������Ҫ����ͷ
���ˡ�����ֻ�е��㶨����֮����ܴ�ܣ���ζ��� %^H_BLUE%^help
settle%^RESET%^ ��
������֮�󣬿��Կ��� %^H_BLUE%^help fight%^RESET%^������ѽ��

gini dangguan
��ɫ����������������ͷ���⺢������־��������һ������ǰ;��
�ðɣ����� %^H_BLUE%^help position%^RESET%^ �ɡ�
��ɫ�����������㵽һ��˵������Ҫ�ȶ��ӣ�����������̫���ˣ�
û��˭��Ҫ��ģ����У��������Ҫ�ﵽ%^H_RED%^С������%^RESET%^���ܵ��ٵġ�

gini officer
��ɫ�������һ���ֵ�����ϲ��ϲ��
��ɫ����Ц��һ������ɫ�������ٲ�ֹ��Ϊ�Լ�����ҪΪ���ң�Ϊ
����������룬�������û�к��³��ġ�
��ɫ�������ɫ����һ�����ȿ��� %^H_BLUE%^help midjob%^RESET%^ ��Ȼ��Ŭ��
�����������Լ��������;��飬���ܳ�Ϊְλ���ߵĹ�Ա��
��ɫ�����۾�����ʼ�����ˣ�����ÿ���¶���нٺ���� %^H_BLUE%^info
me%^RESET%^
�Ϳ��Բ鵽�������ȡнٺ���Կ��� %^H_BLUEhelp money%^RESET%^ ��
%^H_BLUE%^help myarmy%^RESET%^��
����нٺ���������Լ����ױ���
��ɫ����˵�����ǲ���������ҥ�����濴��ĳĳ�ط������ٿ��ط���
�飬�����Ҫ����Ļ������濴�� %^H_BLUE%^help meeting%^RESET%^����������ص�
�����ļ��ɣ��㲻���겢��ס��û���˰������ġ�

gini war
��ɫ����������üͷ��Ҫ���̣���μӹ�ѵ���Ҫ��û�еĻ�����
Ȱ�㻹���ȿ� %^H_BLUE%^help train%^RESET%^ �� %^H_BLUE%^help war%^RESET%^��
����İ������������ٴ��̰ɡ�

         chat talking, now xianren's chat talkings are too simple, and gini's
         talking is meanless to player, because no one will notice them and no
         on will like to keep him flooding his screen.
         of gini's talking, it should be shown like the help.
//it's a draft version, but i think it can be put as urgent use at
present, I will
  try add more related tips to newbie later, and i will adjust the
related help.

how are u guys' comment?
* fool



---
����: Row
��Ŀ: ����(cmd jieyi)
����: Wed Jun 23 03:29:36 1999
���Ѿ���ƽԭ�����ų�����������һ����԰��ר��Ϊ��ҽ�
����衣���ڽ���ľ�����̣��������£�

��������Ҫ����Ʒ������
�㣺������ĳ�ص��������ҵ�������һ��������light ����
    �㣬Ȼ�������¯��
��¯���ͷ�����԰��������㣬��һ�γ�����ʮ���ӣ�Ҳ
      ����˵����ֻ��ÿ��ʮ����һ�Σ�
          ��Ѫ���뺣�룻
���룺���оƣ���ĳ�ؾƹ����򵽣�����һֻ�������ʱ��
      ������ʢ��Ҵ̱ۺ����Ѫ����ʾ���ġ�

���岽�裺
����������Ʒ(�㡢��С��������)��������԰��
����һ�˼��룺cmd jieyi��
��ʾ�ʣ���˭���壿
���룺id1,id2(һ��idҲ�ɣ��������������������Ϊ��)��
      ͬʱ����Ϣ���������ˣ�ĳĳ��ĳĳ��������壬��
      ���Ӧ��
����ͬ�⣬��ֹ���̣���ͬ�⣬����������Ʒ�Ƿ���룬
������Ҫ�����¹���ȫ���Զ�����(���˶���busy)��

ϵͳ�����������䣬Ȼ�������곤�����ж���
��ȡ��һ֦�㣬����¯�ϵ�ȼ��
��ȡ��һ֦�㣬����¯�ϵ�ȼ��
��ȡ��һ֦�㣬����¯�ϵ�ȼ��
�ס��ҡ���һ��˫�־����������ϥ��أ�����������ס��ҡ�
������Ȼ���գ��Ƚ�Ϊ�ֵܣ���ͬ��Э����������Σ���ϱ���
�ң��°�����������ͬ��ͬ��ͬ������ֻԸͬ��ͬ��ͬ������
���������ʵ�����ġ��������������˹�¾��
�ıϣ��Լ�Ϊ�֣���Ϊ�Σ���Ϊ�ܡ��������Ӷ�Ц���������
��¯�������������и������룬���γ���С���ڱ���һ�̣�
����Ѫ���룬��ͷһ���������Ӵ�����·�ϲ��ټ�į��

���˺��㡢������ݻ٣���¯����ʮ�������ޣ����������ã�
��¯�������ƣ������������ù��������һ�¡�

�����Ǵ�ŵ��뷨�����в����Ķ�����ָ����


---
����: Fire
��Ŀ: about the guard
����: Tue Jun 29 23:21:19 1999
in order to save our cpu resource
I make the guard like a common npc
and remove the call   "/sgdomain/event/ev_guard"->aut_appear() from
ai_d.c to reduce the cpu burden
but now we need ice help to add the guard to all the go rooms
you can check the code in huayin's go room

if not finish this and no gurad appeard in 
some areas we can use the command
  "/sgdomain/event/ev_guard"->aut_appear() manualy to create those guards

addoil ice

escape


---
����: Ice
��Ŀ: some changes i have made and going to make
����: Sun Jun 27 16:11:13 1999
added the gold reward for most xianren jobs, from N -> N+random(N).
because nowadays xianren jobs cannot attract enough player to do it
frequently, and actually these jobs are very nice, can make newbie be
more familiar with the maps and functions of finding ppl and objs, and for
most low level officer can make it as a income resource.

I will update most helps with colored cmds.


---
����: Fire
��Ŀ: ��Ҫ����
����: Sun Jun 27 07:36:35 1999
���˱������ʿ��������������û���½���
�Ҽ����������area_d�е�һ������set_area_soldier
�����ˡ������������Ҽ���ǰ������һ��������������ʧ
�ܿ�����˭��С����һ���Ͼɵİ汾uploadʱ���������ǵ��ˡ�
������������ǰҲ�۲쵽���Σ��Ҹ���Ҳ�����������:)
�������ڹ���WIZ�϶࣬��������͸����̷�����
������ע�⣺�ٸ����ļ�ǰһ��Ҫ
%^H_RED%^��download,���޸ģ���upload%^RESET%^��
ͬʱ�ж���WIZ����ʱҪ%^H_RED%^�˽�˴�����ʲô��%^RESET%^

adddoil :)


---
����: Fire
��Ŀ: admire ice
����: Sun Jun 27 07:02:40 1999
����ŷ���ice update ����˶��help�ļ�
addmire ice:
)
�´�update help ����Ը�һ���̶̵� post :)
addoil


---
����: Fire
��Ŀ: a little bug in xianren
����: Sun Jun 27 06:55:12 1999
> [errors] (eata) Error logged to /log/runtime
[errors] *Array index out of bounds.
[errors] /sgdomain/job/xuzijiang/xianren#6496 at line 147

I checked the code seem because one of the maker
have no goods, so cause that bug


---
����: Fire
��Ŀ: the bug about outof data in black list
����: Sun Jun 27 05:57:21 1999
when a player enter this city
the list will be updated and remove out of data chars
so this will be not a big problem

the bug about ������Ա can't removed from black list
is fixed


---
����: Ice
��Ŀ: some suggestion of current existing jobs
����: Sun Jun 27 02:03:32 1999
�������

��Ϊ�ڲ�ͬ�ĳ��в����Է���λ��������ɱȽϴ�����ţ�
����Ƿ��ܽ����Ŀ�귿�䲻�������ڳ��е�ʱ����ʾ��

�ƺ�����Χ�����ĳ��С� neighbour cities
�ƺ�����Χ��Զ�ĳ��С� more than 1 linked cities in between
�ƺ��ڼ�Զ�ĳ��С� all others


���˻���

�а�������ͷ���ˣ�����ͷ���һ��ҩ��ȴ���Ƿ���Ҫ��ģ�
����û�г��� 100% ���ǲ���ϵͳ�ж�ҩ���ڵ��ˣ���������
��֪ʲôԭ�򣨿����Ǹ������⣩��ҩ��û������
P

suggest change��
���ڵ�һ����ɫ��ζ��ҩ�ݣ����ֲ�����Ҫ�ҵģ�
�ְ������ˡ�
then dest yaocao

and at the point player got yaocao, chutou will be broken, and
will add yaocao, then the loadings won't be a problem, i guess..:D

����

���ĳһ������õ��˽����Ĺ������ֲ�ȥ���Ļ����������
�ƺ�Ҫ�ȱȽϾò���ȥ����set the busy time shorter?

addoil yah .....:O~~


---
����: Fire
��Ŀ: a big improvement in char_d
����: Tue Jun 29 07:33:04 1999
char_d �б�MUD����mapping.
�������ʱ��һ��������check_char
����ָ��������������ĳһ�����Ľ�ɫ�嵥
���磺 check_char("area","luoyang") ���������ж�����
�����Ľ�ɫ�嵥����һ�����ǳ����õ���ΪҪ����
ȫ�����ݿ�����ǳ���ʱ��
�һ�������MUD�������Ե����ʹ���ָ���йء�
��ΪΪ��ʵ�ֶ�̬������ɫ�Ĺ��ܣ������з���
��updateʱ����Ҫ��������������char_d�в��ҵ�ǰ�ڱ�����
�Ľ�ɫ�嵥����Ϊ��������ǧ�ķ��䣬��εĲ�ѯ���ϵͳ��ɾ޴�
��ѹ�����Һܻ�����������ε�����
��������char_d��������һ���µ�mapping���ڸ��Ƽ���
�����ɫ�嵥�����ܣ��Ľ���ļ�������
��ԭ���ĺ�������300��400��:)
��ԭ���ĺ�������300��400��:),���������淽�����ԣ�
@time_expression(CHAR_D->check_char("room","daf"))
�Ƚ� @time_expression(CHAR_D->check_char("name","daf"))
�ͻᷢ�ַ���ļ����ٶȻ�öࡣ
ϣ��������Լ������⵱���¼���
ע����Ϊ��ȡ�˺���override���������������ĳ����������
addoil :)


---
����: Fire
��Ŀ: ����ս��
����: Sat Jun 26 12:14:09 1999
û��ս������MUD��û������
�����������壬����ս��һ��
һ����̼��г�����һ����۲�BUGS


---
����: Fire
��Ŀ: help need
����: Sat Jun 26 11:41:17 1999
jail and guard are two interesting system
please give player's help document :)


---
����: Row
��Ŀ: ��������
����: Sat Jun 26 13:46:18 1999
�Ҵ����ڶ����ü����ȼ����ĵ���������Ƹ̫�أ�����
һ����������ҿ���Σ�


---
����: Ice
��Ŀ: agree row
����: Sat Jun 26 15:20:35 1999
as title


---
����: Flee
��Ŀ: >>agree row
����: Sun Jun 27 00:38:21 1999
as title .. :)


---
����: Ice
��Ŀ: suggest change of local positions
����: Thu Jul  8 15:12:32 1999
pls check /wiz/ice/txt/local_position.txt out, for some
unknown reasons, some parts cannot be shown while i post
it, sorry for any inconvenience...:P


---
����: Ice
��Ŀ: an idea about safety after war
����: Thu Jul  8 13:44:16 1999
suddenly get an idea of safety after war, though i didn't check
the formula, in my observation, safety will drop to about 30 sth
after war, but it sounds too average.

suggest to change to this way:

I think safety is a kind of ӵ���� of that city, so higher safety
b4 war, after the enemy get the city, lower safety remaining
by
contrast, lower safety b4 war, higher after:

I think it can be (300-safety)/5 after war, or we can add a +random(10)

* smirk

addoil ..:)



---
����: Fire
��Ŀ: some char_d function updated
����: Thu Jul  8 00:13:34 1999
I updated the following function
CHAR_D->check_char("area",<a_id>)
CHAR_D->check_char_area(<parea>,<value>,,<a_id>)
CHAR_D->check_char("nation",<n_id>)
CHAR_D->check_char_nation(<parea>,<value>,,<n_id>)
AERA_D->get_area(<a_id>,"leader">

so those functions now are 100 - 300 times quicker than before

but the first time to run them, maybe the same speed as before
if the second or following times to run them, much quicker

don't know if any potential bugs :(
addoil


---
����: Fire
��Ŀ: about check_char
����: Wed Jul  7 22:36:08 1999
because check_char is a very very time consuming function
I have adjusted following events to avoid it
1 npc_move is moved from char_d to a seperate event
 ev_npc_move and it is called by the npc's heart
 so much quicker
2 ev_position, it is used called by ai_d
  now it is directly called by the npc's heart
  so quicker
3 ev_leave it is the same as ev_position
4 ev_donate
  for npc donate, i adjust the auto_donate
  now it is 10 times quicker than the old one


---
����: Ice
��Ŀ: about money
����: Wed Jul  7 13:39:18 1999
I think money should have weight, when a player get too much money
on hand, he is supposed to suffer heavy weight, like carrying 20k gold
on hand, it's not possible for a humanbeing.  

well, on the other hands, nowadays more and more player kings, and I think
we have to notice that king can keep withdrawing gold from national reserve
while a city's safety is 0.  Being king now sounds like a way to get
fast money
and good equipments, i think that's not our orginal wishes...:P
suggest to change to the following possible ways:
1. add a limit that king can withdraw from national reserve,
  for example, a king can withdraw at most 10 times per mudday, and the safety
   will drop using the currently existing method.
2. when an area's safety drop to 0, it will cause a ���ң� which can expand to
   its neighbourhood cities, make their safety drop in a higher
speed than normal.
3. when safety of that city drops to 0, king cannot withdraw there anymore.
4. or some other ways, (* grin), when a king withdraw too much, all
cities belong
   to him will drop safety .....:P

well, liyu complained that king has no money and now ice complain
king should have
limits of withdrawing....:PPP
* escape


---
����: Ice
��Ŀ: a discovery of landlord job
����: Wed Jul  7 13:26:44 1999
I think the idea of reward workers to increase their efficiency
is nice, but it makes a way to give money between players, like this

�������˵�����úøɣ���������������������ӡ�;�����˼��Ƭ�̣��ӱ�
Ŭ���ĸ��������
�������ϴ���������Ʒ(���أ�0%)��
  ʮ����Ǯ(coin)
  ������ʮ��������(gold)
  һ�����(gini lamp)
  ʮ��������(silver)


* fool, addoil ..:P


---
����: Fire
��Ŀ: ս��Ҫ����.
����: Tue Jul  6 05:51:10 1999
��һ�ܵ������ص����ų���֪��ս��BUG��ͬʱ��һЩ�����ڷ��ص����ԡ�


---
����: Fire
��Ŀ: ����������
����: Sun Jul  4 03:16:33 1999
�� ���� ��  ������ʱ�䣺��ʮ������������������ʱʮ��֣�
����ID�б���  Ŀǰ��������45��
��������������������������������������������������������������������������
С��(xiaobai)      ����(rabbit)       ����(erfolg)       �������(tianji)
���۲�(cool)       ����(ice)          С��(sue)          ������(blueelf)
����(york)         Ӣ��(yingx)        ����(liuxing)      ����(bunnys)
����(frake)        �·�(boat)         ����(coo)          �Ȼ(remorse)
���(firea)        С��(boney)        Ҷ��(yer)          �λü�(sabah)
�Ʒ���(eata)       ��������(sbboy)    צ��(java)         ���(zudi)
��˫(loney)        ��(dajiang)      Ѱ��(wqin)         �ʵ�(king)
��(dpn)            �׿���(hahaha)     ����(meimei)       Ӣ��(pcm)
�һ�(fire)         ����(fearless)     ����(flute)        ����(carefree)
����(hhrr)         ����(lsz)          ����(beddog)       �¸�(braver)
��(thjo)         ��Ϸ����(helpm)    �����(xixixi)     �Ž�(grouper)

*great
*addoil :)


---
����: Ice
��Ŀ: agree flee
����: Sat Jul  3 10:51:33 1999
how about this

if keep enter in chatting 3 time the same sentence, the player's channel will
be tuned, need 5 player's votes to reopen, vote will appear in rumor.

ps: i think the color of welcome page is nice..:)
   when i got up and saw my system reconnect, the welcome page was changed,
   I thought i was still in dream, u did an incredible job..:)
admire, fool


---
����: Flee
��Ŀ: about flooding
����: Sat Jul  3 04:27:34 1999
should change CHAT and other channels to prohibat flooding.


---
����: Flee
��Ŀ: about logo page
����: Sat Jul  3 00:37:05 1999
yestoday i had created some new welcome page .. :)
i put them under /sgdomain/txt/welcome. there are
logo1.txt, logo2.txt .. etc. of the four, i prefer
logo4.txt and i think it is the best of the all
so i use the logo4.txt as the new welcome page
but the color used is not so good .. :(
can ice do something to improve 

addoil ice


---
����: Flee
��Ŀ: cmd wizlist ok now
����: Sat Jul  3 02:19:22 1999
those wizards did not login for more than 30 days
will be highlighted with red .. :)


---
����: Ice
��Ŀ: ����ϵͳ����С����
����: Sat Jul  3 23:52:42 1999
�������ڵ�����Խ��Խ�࣬��һ�������ҲԽ��Խ�࣬���齫�ִ��
�������ܻ���ڵĹ�����һЩϵͳ�ķ��ࣺ

1���ִ�ĳ���������

�����������żҴ壨�������Ĺ���ֻ�ṩ��Ǯ����ѧ������������һ
���治�ø��ģ�ֻ����Ҫ����һЩ�����ص�͹���������������
�ֵ���Ŀ������ֻ��һ��������ԶԶ���㲻�����󣬲�������һЩ��
�������������ˮ���ӳ�����ˮ����ˮ��ÿһ����busy time ֮�ࣩ
blah blah �Ĺ���(* doubt)������ǰ����Ҫ�ȳ��� ������ -%1000��
������档

2�����˹���

�������˹�������������׬Ǯ�������ģ������֮��Ϊ����Ψһ����
�����Ĺ��̣����ֻ�Ƚ����׶Ե�ͼ��Ϥ������(* grin)����ʵ����
���˹���ֻҪ���հ���������Լ���Ŭ���������ϲ��ѡ�ǰ�����ǳ�
��棬���ӽ�������û¶��Ͳ����ˣ��ڼ�Ҫ��İ�����Ʒ��Щ��ֻ
�ǡ�����ֻӦ�����У��˼��ܵü����š����������0��1������Ʒ��
��Ϊ�����2������ƷҲ���ó�can_sell�Ļ������б���Ĵ��������

3�����˹���

�ص����ص��ˣ����������˵�ġ������ڵ�״���£����еĹ�Ա����
���ڱ�����������ְ�����ƺ���̫����Ҫ��ְӦ��Ҫ������������
׼�ɣ����Խ����������ְ���趨�����ӵ������׵�Ҫ���������
Ҫ���γ�͢��ְ��Ӧ��Ҫ��Ӧ�Ĺ��ҹ��ף���ô�ط���ְҲ�����ݵ�
�����װɡ���������֣���ô����ͨ�������˹������ӵ������ף���
�Ĺٺ���ٵ�Ҫ�����10���ˣ�ֻҪ�����������˹�����ֻ���ӵ���
���׺����������Ϳ��Գ�Ϊ���ع�Ա������������ְ��Ա����Ҫ���
�������ְ����ҹ������Լ�������ˣ��ΣУù��ҵ���Ҫ�������
����������ɹ�ʦ�������統��̫�������˲����Զ�¼ȡ�������ʧ
�ܡ�(* smirk)

4���м�����

�����ص�˵���ˣ�û��ʲôҪ�ٲ���ġ�(* face)




---
����: Ice
��Ŀ: about login name
����: Sun Jul  4 00:15:25 1999
I think login chinese names should include cannot use the 
current existing NPC names and player names, otherwise make
pretty confusing to all.


---
����: Fire
��Ŀ: >about login name
����: Sun Jul  4 00:17:24 1999
On Sun Jul  4 00:15:25 1999 Ice wrote post #581:
> I think login chinese names should include cannot use the 
> current existing NPC names and player names, otherwise make
> pretty confusing to all.

this is a good suggestion,
but there is no good way yet to test
if a chinese name has been used or not by other players
unless that player has settle down.

maybe later, will try to build some thing to track all the used
chinese id


---
����: Ice
��Ŀ: changed some setting of xianren job
����: Sun Jul  4 13:52:41 1999
because the zuo_tool and hua_tool are frequent used tools,
and their hp consumption seems too high to newbie, i set
zuo_tool from hp-25 to hp-15, hua_tool from hp-25 to hp-10.
see see if it's reasonable..:PPP


---
����: Fire
��Ŀ: about the load of daemons
����: Mon Jul  5 07:30:53 1999
I find that during reboot, because oud mud has to load
a lot daemons and many daemons includes big mapping
so it is quite time consuming. and during this time
if some players login (this is quite often, becuase once
the mud is crashed and reboot, all players want to relogin
as quick as possible) then because not all daemons has been
initialized propoly, then may cause a lot bugs.

for daemons, because they don't have environment, so if
called by the clean_up, may be destroyed (not quite sure) then
if need reload it may take a long time, so I add clean_up
with return 0 (means never clean_up) in most big daemons
don't know if this may help our muds speed or crash problems
some way.



---
����: Fire
��Ŀ: ��������԰
����: Mon Jul  5 07:42:10 1999
-------------------------------------------------------------------------
Reice snores majesticly  [idle 8h]                         
Crystal Meth  [idle 6h]                                    
Antilles has the right to remain silent.  [idle 22h]       
Lucy in the Sky with Diamonds!  [idle 4d]
Fire Fire  will burn all the world.         
Hellmonger (ok ok) contemplates becoming 'Fatty Spice Who Can't  [idle 16h]
Weed, Midhir, and fifteen naked women.  [idle 2h]          
Ket can't beat her computer at chess, so she tried kickboxing  [idle 6h]
Wodan sleeps  [idle 2h]                                    
Rassilon  [idle 9h]                                        
Yaynu goto reddragon.org 3000  [idle 1w]                   
Danatos  the Devil Prince  [idle 6h]                
Everyone could use a little more Beer.  [idle 14h]         
-------------------------------------------------------------------------

this is what i see in the lima bean (our mudlib's birth place)

you can see all ppl are idling, most several hours, 1 for 1 day
and 1 even got 1 week !. 
that is really a paradise of idlers :)
but anyway i find the help file about lima in that place are much more
than here. so if you guys have time, it's a good idea to go there and
have a look. read their post and browse the help files
or just idle there :)

the address is %^H_RED%^lima.mudlib.org%^RESET%^



---
����: Fire
��Ŀ: the port is %^H_RED%^7878
����: Mon Jul  5 07:43:36 1999
sorry, forget in last post :(


---
����: Fire
��Ŀ: һ��������Ч��debug ���ߡ�
����: Mon Jul  5 08:15:28 1999
�Ҹո�������MUD�з���һ���ǳ���Ч��debug����
�����������%^H_RED%^man dbx%^RESET%^


---
����: Fire
��Ŀ: about zi
����: Tue Jul  6 23:02:53 1999
we have two npc's zi are same,
both liu ba and sima wang's zi are �ӳ�
so cause that bug
consider


---
����: Row
��Ŀ: base&job
����: Wed Jun 30 23:14:24 1999
�����ҵ�Ŭ���£�������Ʒϵͳ�ĵ�һ�����غ͹���
����ˡ�
admire flee
addoil flee
�ҿ���һ�£��������ǿ��԰ѿ�������(landlord)��
��ֲׯ��(farming) ������������ϵ����( ��ʵ����
˵�����Ѿ�����������ϵ��) ����������ֲׯ�ڵ���
��أ����ķ��̶ֳ�ȡ���ڵ���ũҵֵ�ĸߵͣ���ũ
ҵֵ����һС�������ɵ��ص�NPC ���������˿ڵ���
�������ƣ���Ҫ���ǿ�������������( �����ǰ����
�ؽ�ũҵֵ�ȸ�Ϊxxx/xxx����ʽ������)�����￪��
��Խ�࣬ũҵֵԽ�ߣ��ܹ���ֲׯ�ڵ��ǿ�ص����
��Խ��ҲԽ���֣���ֵҲ��Խ�ߡ�

������ֲׯ�ڵĹ�������Щ���鲻֪���ܲ���ʵ�֡�
Ϊ��ʹ�˹���������ʵ�������������ڵļ���ϵͳ��
ֻ���ڴ������ļ�������ֲׯ��( �����Ĳ�����֪��
�Բ��ԣ���P)���������죬ϵͳ�Զ�����ׯ�ڵ�״̬
��ȷ���ճɡ���������ֲׯ�ڵĹ���������һЩʵ
���ԵĹ��������粥�֡����ݵȡ���ƽʱ�ᷢ��һЩ
�����˻�ʲô�ģ�����̫Ƶ������Ҫ��Ҽ�ʱ����

���ڻ��غ͹���ϣ����Ҷ����ۣ�ʹ�����ơ�


---
����: Flute
��Ŀ: byebye all
����: Wed Jun 30 11:40:30 1999
ȥҲ����ȥ�������������ˮ��ˮ�����ʱ,�ؿ����

��ɽ���ã���ˮ���������Ǻ�����ڡ�
             ˮ�ƹ���ˮ�������� 
            �ͣգ�ʱ�䣺����־���ٶ�ʮ����ʮ������Ѯ��


---
����: Flee
��Ŀ: problem of start_busy
����: Wed Jun 30 08:32:19 1999
if use user->modal_push( function, "xxx"),
then the function will take care of use's input,
start_busy is useless in this case

can fire fix this


---
����: Flee
��Ŀ: first job of new stuff system 
����: Wed Jun 30 08:36:49 1999
farm is ready now, all the files r under
/wiz/flee/farm/. to check it. first @.xx->add_job("do_farm")
then ask farmer about order, the job will start.
the most important part is the function do_reward which
is at the end of /wiz/flee/farm/farmer.c. the function
control the gold cost and food obtain. please check 
whether it is reasonable or not


---
����: Flee
��Ŀ: some ideas
����: Wed Jun 30 08:46:08 1999
��stuff_d��ÿһ����Դ��һ��mapping����ӵ������
��Դ�ĵ�����farm:([ "area":(["changan":1000, ...
����1000��һ��ʱ���ڿ���ȡ��������Դ�����ֵ
���������е�����������ؾ��������磺ũҵ����
�ȣ�npc character��etc����һ��call_out�����ƣ���
�����ȿ�����Ӳ������������Ķ�Ӧ���ֻ��½���
�������ʹ��ũ�������͵�����ũҵ�����ȡ�


---
����: Flee
��Ŀ: why disable cmd save ?
����: Thu Jul  1 06:55:19 1999
as title .


---
����: Ice
��Ŀ: a little discovery
����: Fri Jul  2 15:12:50 1999
maybe bcoz the guard is changed from char to obj, the cmd of
ask xianren about entry is useless, now can ask xianren about enter,
i have adjusted the help xuzijiang.


---
����: Fire
��Ŀ: about maker
����: Sun Jul 18 05:31:19 1999
> ��С�����ĵظ��������˵�����������ˣ�������������һ�����ʵ�Ұζ��
list
��Ե�С���������֣���С�����ñ������������������Щʲô����
��С��������֪������ҪЩʲô��
��Ʒ����             �����          ������          �޸ļ�
--------------------------------------------------------------------
��ͷ(mantou)         һ������        --------        --------
���ϴ�(jnchun)       ��������        --------        --------
�ص㣺 �����ǵ�ͼ��
����ͶԻ�Ӧ����Щ��ϵ��:)


---
����: Fire
��Ŀ: about bugao
����: Sun Jul 18 04:38:58 1999
row's suggestion is good, but now not easy to create
a suitable basic level job. I have adjust the bugao
a little. 
1 the interval time chagnd form 30-60 to 60-120 second
2 dispalyer from 4 - 7 times
3 affect, 25 % no harm , 25 % drop 1 25 % increase 1 25 % incrase 2
  so the average harm is drop 0.25 per time and the total
  harm is about 1 - 1.7 safe drop per job
from 1 - 3 it become less harmful and less flood

when we have other suitable  job we can consider 
replace it, but now because the process of this job
is very easy, so it is suitable for basic level
players :)
addoil


---
����: Row
��Ŀ: ���ڲ���
����: Sat Jul 17 23:44:57 1999
���ڵĲ��湤�������ǵ�����ǰ�ģ������ƺ��ر���
�ף���ҿ�ʼ��Թ����һ������dummies �Ĺ�������
�ң�ʮ�ε�ҥ�Ժ͹����Ƶ�������flood ��������
�����޸�һ�����job �����罫��������ĳ�midjob��
Ȼ����guard �����һ�£�guard �����ץס���ϴ�
�в�����ˣ�ԭ�������һ��αװ�ļ��ܣ�����������
�����������һ�£���
�ּ���������ǰ��job �������Щ���Լ��������浫��
���������޺��Ĺ�������Ҫ�������Լ��ĵ������׺�����
�ȵȣ�Ҫ��Ȼ��������������dummies��
fire������Σ�


---
����: Fire
��Ŀ: >about requirements of settle
����: Sat Jul 17 05:38:38 1999
On Sat Jul 17 04:16:40 1999 Ice wrote post #630:
> now the standard of settle and be officer r almost the same, suggest to
> lower the settle requirement from 30, 30, 30 to 20, 20, 20.

the require for settle is not high 
20 20 and 20 is the average new login level :)

the problem is increase the requirement for become an officer

addoil


---
����: Fire
��Ŀ: Virtual room system
����: Fri Jul 16 12:42:02 1999
because i think the crash may caused by the number of room files
we have about 100 areas so i think we will have more than 2000
room files. 
now i change it to virtual file system. the main server is
"/a/area_server.c"
in order to get a list of an area's file
use : AREA(<a_id>)->get_room("list")
I will add some tools for the new room system, it is quite like
our daemons but a lilttle different. it will be more flexible
addoil :)


---
����: Row
��Ŀ: war_idea.txt
����: Fri Jul 16 04:20:16 1999
last post is saved in /wiz/row/txt/war_idea.txt


---
����: Ice
��Ŀ: formula of safety after war
����: Fri Jul 16 10:38:28 1999
���������У�

�����ݣ�  ��400 - safety b4 war�� / 10
���سɹ���safety b4 war + 20

�������У�

�����ɹ���no change
����ʧ�ܣ�safety b4 war - 30

�������У�

�����ɹ���no change
����ʧ�ܣ�safety b4 war - 20

Э�����У�

Э���ɹ���safety b4 war + 10
Э��ʧ�ܣ�safety b4 war - 10



�����ˣ� slogan row, row said he would did it..:(


---
����: Row
��Ŀ: >formula of safety after war
����: Fri Jul 16 23:16:33 1999
maybe i forgot that...sorry ice..:P


---
����: Ice
��Ŀ: emote on obj
����: Sat Jul 17 03:42:28 1999
when emote target is obj:
$n -> ��
$R -> ����
$r -> ����

* escape


---
����: Fire
��Ŀ: >emote on obj
����: Sat Jul 17 03:45:03 1999
On Sat Jul 17 03:42:28 1999 Ice wrote post #628:
> when emote target is obj:
> $n -> ��
> $R -> ����
> $r -> ����
> 
> * escape

�е���
�е���


---
����: Ice
��Ŀ: about requirements of settle
����: Sat Jul 17 04:16:40 1999
now the standard of settle and be officer r almost the same, suggest to
lower the settle requirement from 30, 30, 30 to 20, 20, 20.


---
����: Ice
��Ŀ: about info a <a_id>
����: Sat Jul 17 07:26:20 1999
if this body is a king, he is supposed to see all available info
of each city in his nation


---
����: Fire
��Ŀ: about zuo ci's job
����: Sat Jul 17 07:56:40 1999
I have updated zuo ci's job to fit in
the new area system :)


---
����: Fire
��Ŀ: �Ѽ��ĳ������������Խ��Խ���ȶ���:(
����: Sat Jul 17 20:21:29 1999
who
�� ���� ��  ������ʱ�䣺��ʮ��������ʮ���������ʱʮ�˷֣�
����ID�б���  Ŀǰ��������21��
��������������������������������������������������������������������������
С��(xiaozi)       С��(xiaobai)      ����(biyue)        ����(fearless)
С��(wurzeln)      ����(rabbit)       �ݰ�ʦү(cbshiye)  צ��(java)
�·�(boat)         ������(eyesight)   ����(ice)          ����(lsk)
�һ�(fire)         ��ͷ��(daitoue)    ��˫(loney)        ��ɽ����(reverie)
С��(lgun)         ����(wangling)     ����(carefree)     �ö�(richel)
cpu
CPU usage: 6.32%
Mud status is
Sentences:                            48      768
Objects:                            6265  3254280
Prog blocks:                         805  1290352
<Array statistics disabled, no information available>
Mappings:                          93237  8126476
Mappings(nodes):                  168267
Interactives:                         21   133140
Obj table overhead:                 6004   432028
call out:                            220     6160 (current length 102)
                                         --------
Total:                                   13243204
load average:
2.82 cmds/s, 6.05 comp lines/s
��Ʒ������
@sizeof(objects())
5924
> time
����ʱ��                ��ʮ��������ʮ���������ʱʮ�߷�
����������              ��ʮ��������ʮ����������ʱ��ʮ�ķ�
��������ʱ��Ϊ          ʮ��Сʱ��ʮ������ʮ������


---
����: Row
��Ŀ: ս������Զ�����⡣
����: Fri Jul 16 04:16:42 1999
���¹۵���ҪΪ�����ṩ�����������޸ġ�

                       ս������
                                 
                       ������ս N-->cannot cmd war
                          ��Y
                   ���������ٿ�����
            ���������������੤������������
         ����90       Ǯ����֧��   ѵ���Ⱥ�ʿ��
            ��        ����ʿ����   ������60��
            ��        һ�����ϡ�        ��
            ���������������੤������������
                         Y��N--> cannot cmd war
            ���������������੤������������
        Ŀ������ڽ�   ��������    Ŀ������ڽ�
        �б����ǳأ�      ��       ���˹��ǳأ�
        ��ͬ������        ��       ���빲ͬ����
            ��            ��       �˹�Y��N-->���˹���over
        �������л���      ��       �������л���
      �������ة�����      ��      �������ة�����
 ����90   ѵ��ʿ������60  ��   ����90    ѵ��ʿ������60
      �������Щ�����      ��      �������Щ�����
           Y��N, over     ��           Y��N,over
      cmd assistwar    cmd war     cmd assistwar
            ���������������੤������������
           �ֱ�     �ֱ�����������     �ֱ�
      over N��Y          Y��N,all over.Y��N,assist over
            ���������������੤������������
         ����ս����ȫ��������ս���ӵ���ʳ����
                          ��
                          ս
        �������������������ة�����������������
      ����ʤ                       �����ܻ�������������
��ս����ռ��ǳأ�����         ����δ������֮���ӳ���ԭפ�أ�
�������ӳ���ԭפ�أ�ս         ��ս���а����½����������а���
��ռ��������Ϊ15��           ��Ȼ���ͷ����롣
        �������������������Щ�����������������
                       war over

һ����ս������������pos �����ö���ʱ���ڲ���ս���������������
    �Ҳ������ߣ���������ͬ�������������������������ش��Ĭ
    �ϲ�ͬ�⣻��������������pos ���趨�����ΪNPC �����ǹ�ʦ
    �����ˡ�
�������������ƹ�Ա��������������ʽ������������
    ��Ҫ����*50+�ط���λ�ȼ�*50+���ҹ�λ�ȼ�*50+����ƺ�ϵ��*50
    �ȼ�����Ե����ֿ��ԸĶ�����Ҫ�ǿ������ĸߵͣ���λϵ����Ϊ
    ��������ǿ�������ڹ�λ����Ǩ�����ϸ�Ҫ��ģ�����Ҳ�������
    ̫���׵��������Ҫ�����������ģ��Ĺ�ȡ�������������ȡ��ѧ
    �����������Ϳ����������Ŀ�ĵķ�չ���������ɹ�λҲ���з���
    ���ˡ�
����Я�������ͽ���Ӧ���ս�����Ѷ�����ʵ�ԣ�����ս������Я��
    �������������(��ѡ��������;)��ÿ��������ĵ���ʳ���𣬾�
    ����������������������ʿ������ڼƲߣ�ÿʩһ����Ҫ��Ǯ����
    Щ�Ʋ���Ҫ�������ʣ����磺��ʯ��Ҫ��Բʯ������������Ǿ���
    �ġ�Ǯ��һ�����Ĵ�����ÿ�����ʿ�����ܣ�������������ò�Ҫ
    �½�ʿ����������ս��ʿ��Ϊ����������ˡ�
    �������ÿ30�뽵һ��ʿ�������⣬��Ȼ��ս��Ӧ�ûָ���սʤ
    ����Ӧ�����൱��ʿ�����Ƿ������ս��ʱ��һЩ����(��ʱ)����
    ʿ���ļƲߣ��������ȵȡ�������е��趨����Ϊ�˸��������
    �ѶȵĻ������ܻ�ʹ����ɥʧ���ģ����Կ����ʵ��������һ�¡�
�ġ���ͬ������ֻ����Ҫ���ڽ�Ŀ������ĸ��ϳ���������ͬ��������
    ͬ����������ս�����ֱ����֮�󣬱�����������Զ��ٿ����飬
    �����Ƿ������˭����ȵ�(����ʱ���)��
�塢��Ŀ�������Χ���˹�����ʱ����Ҫ���˹�����������ȥһ������
    �Ľ��������ʡ���������Ʒ���˹��յ�������ٿ��������ۣ���
    �ﲻ������Ҫ����ֱ�Ӿܾ�����ͨ���������
������ս����Я������������Ӧ�������ޣ��Կ���ά��ս��һСʱΪ
    ��(Ӧ���趨��ս����һСʱ����ʤ�����������ս)���������ޣ�
    �����ĵ��������ɺ�ɨȫ������Ϊ���Բ�ͣ�����������̶�����
    �����Ƴ�����Ŀ�����д��顣
�ߡ�����̽�У����е�cmd warinfo ���ṩ���Ѿ���������״��������
    ��������ʿ������������Ŀ�ȣ�����ʵս��������Ҳ������ս��
    ���Ѷȡ���ˣ�����ս��������һ����̽��������cmd scout��
    ��һ֧С�ֶӳ�ȥ��̽( �����ø��˵��ױ����Ǻǣ��ֵ���Ҳ��ս
    ���ˣ�һ��ʮ�ˣ�ʧ�����ȥ���ɹ���ָ�������ָ�� )����ʵ��
    ����ģ��磺̽�������о�����ȫ�����𡣻�̽�������ػأ�̽
    �õо��鱨��ÿ�θ�ָ�����һ���Ľ𣬳ɹ����������в�ս��
    Ա���츳Ϊ��׼��̽�õ��鱨���Ա���ʮ����ӡ�ֻ��̽�гɹ���
    ����cmd warinfo �������鱨���Լ�ʹ��cmd warmap�����ӷ�λ��
    ��Ȼ��ֻ�ܿ����Ѿ���λ���о�ֻ�н�����Ұ����ܿ�����Ҳ����
    �ڷ�����������⣬̽��ֻ�������һ�Σ����ϴγɹ�������
    ʧЧ�������̽��
�ˡ�����սʤ��������ڶ����ڴﵽ����90���ٶȳ����������ƺ���
    ̫���������Ը����ܹ��������߰����Ľ������Ӧ�����¿���
    �£�
    ˰�ʣ��޶�ÿ�ε������Ȳ��ɳ���20����������˰��ÿ����ֻ��
          ����һ�Ρ�
    ̽�ã�û�����⡣
    ���֣�û�����⡣
    Ѳ�ߣ�û�����⡣
    �þ����þ���ʿ����׹�����ò������뵱���˿ڣ������ӵط�
          ������

                       ս������

         �ڽ��й�������ս�������ٿ�������������
            ���������������੤������������
        �������ڽ�     ��������    �������ڽ�
        �б����ǳأ�      ��       ���˹��ǳأ�
        ��ͬ���ء�        ��       ����ͬ����
            ��            ��       �˹�Y��N���˹���over
        Э�����л���      ��       Э�����л���
      �������ة�����      ��      �������ة�����
 ����60   ѵ��ʿ������60  ��   ����60    ѵ��ʿ������60
      �������Щ�����      ��      �������Щ�����
           Y��N, over     ��           Y��N,over
            ���������������੤������������
           �ֱ�          �ֱ�          �ֱ�
      over N��Y           ��           Y��N,assist over
            ���������������੤������������
     ����ս�������з��ز������ĸó�����ӵ�е�Ǯ��
              �������������ة����������� 
      �������ز�����           Э�����ӳ��ַ�ʽ��
      ��˧�ʻ�ǳ���           �����������ƣ����
      ����ս����               �ֲ���Ұ�⡣
              �������������Щ�����������
                          ս
              �������������ة����������� 
     ���سɹ�������������  ����ʧ�ܣ�Э�����ӳ���ԭפ��
                           Э�����а������䡣
              �������������Щ�����������
                       war over

һ�������ص�����Χ�б�����������������Э�����ֱ���Ϻ�Э��
    �����Զ��ٿ����顣���ﵽ����������μ�Э����
�����������ز��ӵķֱ���Ҫ�����ָĶ���
    1�� �趨��С������������Ϊ����������20% ����������Ӱ���
        �͵����˿�����������������Է�ֹĳЩ�������ڷ���ʱ��
        ��ֻ�����������ӷ��أ���Ϊ�ڷ��ػ�����ϵͳ�Զ��趨��
        �ߵĹ�Աͳ�첿�ӡ�
    2�� �������й�Աȫ����ս�������ƺ������ NPC����Ļ�����
        ���߻�NPC��Աȫ��������Ž������档
�����ǳع���ս�������ڵ����ڼ��Ϸ����ȵ��趨������ز��ӿ���
    �����ĵ����ϵ��档���ҽ���ǽ����Ϊʵ���赲������ȱ���
    ���������ȣ�����ƽʱ����������ǽ�Ĺ���������Ϊ200 ������
    �������뷨��һ�ǽ���ǽ���óɷ��ط��������⴩Խ��ͣ������
    ������뽫��ǽ�ķ��ضȽ�Ϊ0 ����ͨ������������Ӧ��߷���
    �������������ط��ڳ�ǽ�Ͽ���ֱ�ӹ�������������뷨���ŵ�
    �Ǳ�̱Ƚϼ򵥣����������棻���Ǳ�̿��ܱȽϸ��ӵģ�һ��
    San3��San4����ǽ�ͳ���Ϊ����ƽ�ص��赲����ط����ڲ��
    �ϳ�ǽ�󣬽�����ֱ�ӳ��Ǻ���ֱ�ӹ����ķ�ʽ���й���������
    �ù�������ʯ�ƣ�������Ҫ�ӵл���Ҫ��ͬһƽ���ϵļ�ı�಻
    ��ʹ�ã�����ֻ�ܴ��ڲ�������³�ǽ�����ط�ͨ����ǽ������
    cmd entercity���������Ѿ����Ӵ��ڲ�cmd opendoor �����ܽ�
    �룻��Զ��ԣ��������ӿ���ѡ��һ�����Ż��ƣ�Ȼ��Ӹ�ȱ
    �ڽ��룬������һ�����ڲ࣬Ҳʹ��cmd opendoor�����Ƿ�����
    �����ӣ�����������ս���ĶԿ��Ժ�Э���ԡ���Ȼ�����Ұս��
    ���Ͳ��ؿ����ˡ�
�ġ���²�����⣺Ŀǰ��ս���������ǰ��˾͵����ˣ�û�з�²��һ
    �������Ϊ�Ѿ������η������²������Ӧ�ÿ���ʵ�֡�����
    �������������ľ��Ž��춼�л����Ϊ�з���²��Ȼ�󱻷��Ľ�
    �콫���η������һ��ʱ�䡣Ȼ��й�����Ȱ���������������
    ��²��������һ������÷�²��Ϊ���ˡ�

                     ��ս��ֱ�������

���ˣ���Ϊ���ڵķ�չ�����Ѿ���Ҫ��Ϊ��ҹ����Ĺ��ң��������
      �ԵжԶȻ��Ѻö��������ƺ���û���õģ������Ƚ���������
      �ɲ��ܳ���Ϧ�ĵ��ƶȣ����������ˣ����ܻ�����ս������
      ��ս����Ȼ����Ϊ����ҹ�����������ʱ��Լ�����������ǲ�
      ��ϣ����Լ��Ϊ��Ϸ����ô�Ϳ�������һЩ�ͷ���
      Ʃ�磬��������Ϊ10�꣬����Ϊ1 �꣬�����һ����ͬ���ڼ�
      ��Լ����ȫ�������½�5%�����н����Ա�ҳ϶��½�5%������
      ����ʿ���½�10�ȵȡ����ڵжԶȻ��Ѻöȣ������ڽ����ƻ�
      ����ʱ���ֳ����������Ա�����й�ɢ��ҥ�ԡ��߷����ƻ���
      ������ݻ�ȵȵĹ������ߵжԶȵĹ��ҽ����Ϊ���ȿ��Ƕ�
      �󣬵жԶȺ��Ѻö��ж��ɸù���Ա�������������ɸù���Ա
      ��ƽ����й���ϵ����Ϊ��׼������
      ������Ԯ�������ڸò���Ϊ���Ƿ�Χ����Ϊ���⹦����δ���ƣ�
      ������Ȼ�������������������Ѻù���֮�以����������ϵ
      ��ã������ֻ�ǰ�Ǯ��������ȥ��ʲô��ʧҲû�С�

���֣�ÿ����ʷʱ�ڶ������֣�����������Ϸ�����ûһ��û����
      �ֵģ�����Ӧ�ü���������Ӱ����е�ָ����
      �����к�ˮ���ȳ桢���ߡ�쫷�ȵȣ�������ʧ����ͬ��Ψһ
      ��ͬ�ľ���һ����Ӱ�쵱�ذ���������������ֵ��������ĳ
      Щ��ǿ�����Ĺ�����Ч�����ܼӱ�����롣
�˻������ڵ�������̫С��ģ�ˣ�ȱ������֯���쵼��Ⱥ�����ף���
      ͣ����С��С�ֵĽ׶Σ���Ҫ���Ǵ�����չ׳�����ȣ�����
      ���Էֿ����˺ͺ������࣬�����������������е����˺ͻƽ�
      ��������޺���С�����ꣻ������������Ӧ����������������
      �ĺ�ͬ־�����Žǡ���Զ־�������ϻ�ͬ־�ϸ���˵Ӧ������
      �����ˣ���һ��ĺ��������ر�����ʱ���������ݣ�ϡ���Ϳ
      ����ĳЩս�ۣ���ĳЩ�ò�����ĳ���ϴ��һ�յȵȣ���֮һ
      �仰��˵�������ǽ��������Ĺ��׾޴�

�ƻ����������ڵ��ƻ�������û��Ŀ�ģ�û��Ч���ģ���Ϊ�����Ҳ�
          �������ָ�򣬴���Ϊ����ָ���Ŭ����������Щ������
          �ƣ�Ʃ�磬������ָ����ĳЩ�ݽ����ƻ�����Ȼ��������
          ����ר�õ�menu�����������ã���������һ������Ȩ��
          ������һЩ�ƻ�������
    ���������ڻ���û�����⡣
    ɿ�������͵й��гǵİ�����������Ϊ�������ֹ�й�����������
          ͬ����ҪĿ���ԡ�
    �߷���û�����⡣
    �µ��뷨��
    ҥ�ԣ���̫�ش��������Ӷ�������Ŀ����е�����ҥ������ppl��
          ��ҥ������officer Ҳ��ҥ���������ó������ppl��ҥ��
          �����򵱸óǹ�Ա̽�þ���ʱʧ�ܵĻ������ӣ���officer
          ��ҥ�ɹ�������ӳ�NPC��Ǯ�ֲ��Լ����ҵ�ʱ�䣬�Ӷ�ʹ
          �г��˲���ʧ���µ��㡣
    �ݻ��ݻ𽵰�����������ָ������Ǯ�����ʡ�
    �ƻ����ƻ��Ǿ����ƻ��й��ĳǷ��ȣ��Լ�˵��������˳��ǣ��͵
          ��ʯ��ľ������
    ������ٿ��ط����飬�ɳ���Ա���²���ڳ�̫�ؽ��档

����һЩ�йص�ϵͳ��
��Ʒϵͳ������һ��������ĵ���ϵͳ��addoil flee��
����ϵͳ����Ҫ���ۡ�


---
����: Fire
��Ŀ: %^H_RED%^The real bug
����: Fri Jul 16 04:06:24 1999
%^H_RED%^Too many open files
we need reduce the number of files in our mud.

addoil :)


---
����: Row
��Ŀ: not crash?
����: Thu Jul 15 21:35:15 1999
��������ʱ��Ϊ          ʮ��Сʱ��ʮ�߷���ʮ������

does that indicates the train cause the crash?


---
����: Fire
��Ŀ: >about recruit
����: Wed Jul 14 19:21:20 1999
On Wed Jul 14 18:15:36 1999 Ice wrote post #612:
> hmm, recruit 1 ppl in city will drop 1 safety, is that too much?
> or we can use drop more population instead of drop safety?
> like 1% drop of current population, bcoz most ppl recruit in small city,
> but no one manage in small city, the safety will drop to 0 in no time.

that is a point, will set can't recruit if safety small than
20 and population less than 500

is this ok ?


---
����: Ice
��Ŀ: about recruit
����: Wed Jul 14 18:15:36 1999
hmm, recruit 1 ppl in city will drop 1 safety, is that too much?
or we can use drop more population instead of drop safety?
like 1% drop of current population, bcoz most ppl recruit in small city,
but no one manage in small city, the safety will drop to 0 in no time.


---
����: Ice
��Ŀ: about morale after war
����: Tue Jul 13 23:48:36 1999
now war will drop morale every 30 secs, it's fine, but after
the war wins, system adds only 20 morale on the remaining
morale after war, it sounds not so convenience.

suggest to change to this way:
if war wins, the winner side will get morale as morale b4 war + 20
bcoz nowadays train is too hard to add, one train adds only 4-5 points
even tasks all finished, or we can make the train add morale little bit
faster ....:P


---
����: Ice
��Ŀ: about chat to npc and obj
����: Tue Jul 13 22:21:51 1999
I think if set to can chat * with NPC or obj in the same room
will be better, otherwise it's kind of confusing, and ppl may
use it for some other usage

�����ġ��Զ���һ�����ڵ���С���ƨƨ�ϣ�ӡ��һ�������Ьӡ��
�����ġ��Զ���һ�����ڻ������˵�ƨƨ�ϣ�ӡ��һ�������Ьӡ��
�����ġ��������ĵ�����ָ���˴����ؾ��񣬿������ľͷһ�����޷�Ӧ��
�����ġ����۾�(smiling)��all screen messy now

so fire pls consider to change it, dun make it for unproper usage bah

like "set notell" bah..:P

btw: make a vote system to control flooding bah, and add a setting
like "set notell" bah..:P

oh, they poke for recruiting..:P


---
����: Fire
��Ŀ: very serious bug
����: Wed Jul 14 07:32:31 1999
today, when i login i find the system is in the mess
a very serious bug come
it has many unusually things
1 system will give error messge every 1 second
  the screen is full of errors, so i have to
  turn off the errors channel
2 when i use who i find two players without id
��������������������������������������������������������������������������
С��(xiaobai)      �����ĺ�(aeolus)   �׶�����(0)        ����(gb)
һ��(yila)         ����(hotdog)       ����(afan)         ����(dun)
�����(zhjz)       ��ӥ(ying)         �ݷ�(dubai)        ����(rabbit)
�һ�(fire)         �Ʒ���(roro)       ����(luoyan)       ��ӥ(zhiwei)
�λü�(sabah)      ��ң����(wslu)     ���۲�(cool)       ����(zlong)
����(zxcs)         ����(xiaojie)      С��(xiaozi)       
�׿���(hahaha)     ����(two)          �绨(pcc)          
����(luna)         Ӣ��(pcm)          �Ȼ(remorse)      

then some time later, one is disappeard but still one player without id
3 all system call can't work
 I can't use cmd such as cpu, dbxwhere and even update
 all give full screen error message
4 but players can continue play, strange

5 can't shutdown

6 at last I have to login the unix and kill the process
7 then all information in channel.o gone
  we still have all the channel but information gone
  in this case, mean every can listen wiz and announce
 if they use chan wiz /on
the whole process is very strange, i think
our system should crash, but so wrong, even can't crash
. . . . . .

let's keep an eye on the system and catch that mysterious
bug asap. 


---
����: Fire
��Ŀ: about the crash
����: Wed Jul 14 21:11:57 1999
the unreason crash is a real headache for this mud
now i use day_d to create a log for this mud
the log file is in /data/daemons/daylog
it will record some system information every 4 mins
hope it can help to catch the reason of crashing
any part is let's try to disable some function
to test if they caused the crash

I think war system is suspected and xianren's job
  also have a little suspected. so let's begin from
  this two system, first will disable xianren for one
 day if still crash, then disable trian, war for one or two days
 if still crash, then will try to disable other systems
 until find the right reason
 and do your guys have any suggestions ?
 
addoil :)


---
����: Ice
��Ŀ: agree fire
����: Wed Jul 14 21:15:58 1999
as title


---
����: Row
��Ŀ: >about the crash
����: Wed Jul 14 21:47:20 1999
agree fire, the crash for no reason really frastrated
everybody, we need to clear it...
addoil:)


---
����: Ice
��Ŀ: about crash
����: Wed Jul 14 22:05:23 1999
last time tset asked me to warn stefan that the "^M" at the end
of every line caused crash, and asked stefan find a way to remove them.
take it as reference bah
addoil ...:)


---
����: Ice
��Ŀ: introduction of fate system
����: Thu Jul 15 01:06:15 1999
I think the fate system can give a good control of where will
have disaster, fortune, or even bandit instead of totally random
spreadout.

pls more /wiz/ice/txt/fate.txt to check it out.

ps: it might be different of the real fate in life, i know only little
about the real one, just took some info that may help us out, so don't
show it out, * blush, * escape


---
����: Row
��Ŀ: >not crash?
����: Thu Jul 15 21:44:40 1999
On Thu Jul 15 21:35:15 1999 Row wrote post #620:
> ��������ʱ��Ϊ          ʮ��Сʱ��ʮ�߷���ʮ������
> 
> does that indicates the train cause the crash?

grrr...several mins later, crash again...seems
there is other reason....


---
����: Fire
��Ŀ: about the black list
����: Tue Jul 13 09:34:47 1999
i find a bug in the pos for black list
i fixed it, hope it is because that cause the problem of
disappear of blacklist


---
����: Fire
��Ŀ: about ice's suggestion
����: Mon Jul 12 22:42:02 1999
ice's suggestion is good in some aspect,
but i still prefer make player guess who
is spy by the players action in the mud
rather than information other than the game itself

so i against his suggestion :)

now the result is 2:1 need 1 or two vote to
give final decision
addoil


---
����: Fire
��Ŀ: goto ���������
����: Mon Jul 12 10:05:50 1999
����goto�ɵ����µط���
1 goto <player>
2 goto <char> ���磺goto diao chan
3 goto <file name of room>
4 goto <obj_id> ���磺goto luzi (����¯�ӵķ���)
goto han di �����۵Ĺ���ȡ�


---
����: Fire
��Ŀ: %^H_RED%^��һ��ע��%^RESET%^
����: Mon Jul 12 08:54:05 1999
��Ϊ�������ڹ���WIZ�϶ࡣ
����ļ���Ҷ������޸ģ�
������update�ļ�ǰ��һ��Ҫ��download
�ر���event,daemons,modules,jobs�ȡ�
%^H_RED%^�мǣ��мǡ�


---
����: Fire
��Ŀ: ����ev_lincome
����: Mon Jul 12 08:11:28 1999
ϵͳ��һ��������ÿ�¼�������������룬
���ٱ����Σ���Ա���ױ����Ρ�
��ȥ��������һ����ȫ���꣬�������������
too long eval����
���ڲ���call_out�����ƣ�һ������һ������
�ؼ��㣬�ѹ�ȥҪ��һ˲����ɵĹ���������
�����߷��ӵ�ʱ�䣬������ϵͳ˲�����ѹ��
ϣ������ʹϵͳ�����ȶ���

�����ڹ��������У�����ֻ�ܽ𣬵������ܽ��������ʡ�



---
����: Ice
��Ŀ: suggestion of king withdrawals
����: Sun Jul 11 15:50:49 1999
add a restriction that if the area's safety is <30, cannot withdraw
gold from reserve.  however, king is supposed to withdraw gold
anytime, but it can related the king's private asset with his city's
status more tightly.


---
����: Ice
��Ŀ: a sudden idea about spy job
����: Sun Jul 11 19:17:21 1999
since nowadays spy job and cmd catch job is not hot, got an
idea about changing spy job:

when get the area of spy job, add a 50% random chance to spy
the neighbourhood cities, might be more competitive.

btw: I think we need add a time limit of cmd spy info, as i was
player, when i planned to take over changan, i got a chance to do
spy there, then not report back to my taishou, then i kept the most
updated spy info until i do another or report after 2 weeks, got to
change it.....:PPP  hmm.......how about 30 mins....:)


---
����: Flee
��Ŀ: >> about help cgi
����: Wed Jul 21 00:47:41 1999
i have modified it, adding backgroup image
and replace all the ansi color code to html
color code, all use red 
too lazy to check all the correspoding color leh .. ^_^


---
����: Ice
��Ŀ: about marriage
����: Mon Jul 19 08:05:26 1999
I think some words need to be ��ɫ.:P, and try to make it fun for marriage
addoil tit


---
����: Fire
��Ŀ: about marriage
����: Mon Jul 19 08:02:53 1999
ice's marriage system sounds good
can tit finish it ?
we will all help you in some way
addoil tit


---
����: Ice
��Ŀ: �������£��������ʱ��������������ҹ������
����: Mon Jul 19 07:39:35 1999
���Ҫ��
һ�У�һŮ
���䳬��16�꣬δ��
�з���������10000

���ص㡢�����ˣ�
�⿤->��¶��->�ǹ���

���֤�
��ָ->subtype��hands
��all objs in this subtype is lv 0��

���׼����
�����ָ����ĳЩ�鱦���ڿ����򵽣������ṩorder����

�����̣�
����¶�£��ҵ��ǹ��ϣ�
ask qiao guolao about zhuhun
��check if both party meet requirement��gender, age, marital
status,ring in both body��

//if same gender
�ǹ��ϲ�Ȼ��ŭ���������������ֵ��ǰɣ������ģ�����ץ������
�ǹ��ϵ����һӵ���ϣ����һ�Ͱ��������������ͽ��˵��ش��Ρ�

//if age not qualify
�ǹ��ϡ��ٺ١�һЦ����������С�ģ����շ���������������
�ǹ��������������һ�Ͱ����ͷ��˵���������ǳ��������ɡ�

//if one party is married
�ǹ��϶��һ𡸺ߡ���һ�������ػ飿�Ŷ�û�У�ץ������
�ǹ��ϵ����һӵ���ϣ����һ������������ͽ��˵��ش��Ρ�
�ǹ��������ذ�ο���壺�𼱣��𼱣��Ժ����ҵ����õġ�����

//if no rings in both body
�ǹ��ϡ��š���һ����һ��������ֹ��ģ�������ǻ��е㶫��û׼���ðɣ�
�ǹ��������һ�Ͱ������ĵ�̾��һ����������ָ��û�о����飿

->all qualified
�ǹ��ϵ��ͷ���ţ��ã����������ǣ����ǿ��������మ��
fire��answer yes to qiao guolao
�һ�һ�����Ű��壬һ�������ǹ��ϵ�ͷ���ǣ��ǣ��ǡ�����
row��answer yes to qiao guolao
�����ߺ�����������ص��˵�ͷ��
//last chance to regret, if 30 secs no response
�ǹ���̾�˿���˵���������������ǻ��ǡ�����������
�һ�Ͱ��������һ�ۣ������ʼ磬�����߿��ˡ�

->marriage
�ǹ��Ϲ���һЦ���ã��ã��ã�
�ǹ�����ɫ���һ��ʵ����һ����ԸȢ����Ϊ�ޣ�
�һ�ʹ���ص�ͷ��Ը�⣬��Ը�⣡
�ǹ����������ʵ������壬���Ը�����һ�
����������������һ�һ�ۣ�˵������Ը�⣡
�ǹ���һ�Ĵ��ȣ��ã�����
�����ġ��ǹ��ϣ��һ��밢����ʽ��Ϊ���ޣ�blah blah, sb add it��
//underground actions
set ring on each body as ordered obj, rings cannot order or fix from makers��

->follow-ups
�㻻����һ�������ۣ���ϲ��������½���һ��ϲ�á�
��virtual room->xitang��
//look��hmm, sb can think of some better desc?��
    ������л���ר�õ�ϲ�ã������ŵƽ�ʣ�̨�ϸߵ����һЩ
��Ů���������ֶ��裬�����СѾ���������ϲ��;ơ���Χ������ǰ
��ף�صĿ��ˣ����ַǷ���

�㱻����Ѿ�������᷿�������˻����ķ��ϼ���������˸�ͷ������
���쵽��һ���������ӵ����
//look
���̲�ס���ƿ���ͷ������Χ���ָվ���������Ȼ��һֻ��ů������ס�ˡ�

->����
��һ�Ե�ϲ�������������һ����أ�
��bai tiandi��
�һ�Ͱ��峯���ذ���һ�ݡ�

//male id action only, if female id want to act, will be shown this
���ɻ�û�ж����أ��㼱ʲô��

��һ�Ե�ϲ����������������ݸ��ã�
��bai gaotang��
�һ�Ͱ������������һ�ݡ�

��һ�Ե�ϲ����������������޶԰ݣ�
��duibai��
�һ�Ͱ�����԰���һ�ݡ�

��һ�Ե�ϲ�����������������붴����

->����
�һ�Ͱ�����Ѿ�ߵ������½����˶�����
��virtual room->dongfang��
//look
    Ѿ���Ǻ�ϲ�ﶼ�Ѿ����˳�ȥ������˳�ִ������ţ�����ֻ��һ
�Դ���򷢳���΢����ž���������������м���һ��СԲ���������
��һ���ƺ�����С�Ʊ������ӵ���������һ������󴲣���������
�Ϲ��Ŵ��ġ�ϲϲ���֡�

�Ƹ�ͷ
�һ�ɵЦ�������ƿ��˰���ĸ�ͷ��������ڰ����������������һ�¡�

�ϻ��ƣ�
��drink hehuan��
//male id action only, if female id want to act, will be shown this
���ɻ�û�ж����أ��㼱ʲô��

�һ��������ƣ�������ڰ������˵�������ӣ�����һ������Ɑ�ưɡ�
���塸���̡�һ�����ߺ��������ӹ��Ʊ����������֣����һ�����ת�˸�����
�˴˵Ķ�ͷ������ţ�һ������˺ϻ��ơ�

Բ����
��yuan fang��
�һ�����ر����塣����������
һҹ�޻�����������������������
//30 secs busy time

���գ�
//force out of dongfang

��if disconnected or no response, process will be cancelled in 30 secs
  but marital status will be changed to married��
��in each step, will display a hint that how to do next��

how do u guys think about it?



---
����: Fire
��Ŀ: virtual room's two use macro
����: Mon Jul 19 07:39:20 1999
virtual rooms are more flexible, here has two use
macro used to design rooms
1 GETHERE(<what>)
  ���磺
  @GETHERE("b") �鵱�ص�brief
  @GETHERE("") �鵱�ط������������
  @GETHERE("o") �鵱�ط������Ʒ����
  @GETHERE("e") �鵱�ط���ĳ�������
2 SETHERE(<para>,<value>)
  ���磺 @SETHERE("b","%^YELLOW%^С·%^RESET%^")  �ѵ�ǰ�����short
���%^YELLOW%^С·%^RESET%^
 @SETHERE("o" , ([ "/sgdomain/modules/m_board.c" : ({ 1,
"%^H_GREEN%^����ָ��%^RESET%^","newbie"}), "/sgdomain/area/guan/huay
in/npc/shuijing.c" : 1 ,]) )
 ��ˮ�������԰�

addoil


---
����: Fire
��Ŀ: >re: tit
����: Mon Jul 19 06:41:15 1999
On Mon Jul 19 06:22:29 1999 Ice wrote post #647:
> hmm, about war movements, we have troops upgrade projects ahead,
> conditions will be changed after it's implemented
> 
> about emote, it's different from LPMUD, emotes r devided into 2 catagories:
> no targe, and with target
> 
> hmm, about the sentences of rumor, i think we can adjust it later
> now we need to debug and develop some urgent projects

in fact, we have designed the semote like other mud before
no target, to others and to self. but, stefan change it back
sigh 


---
����: Ice
��Ŀ: re: tit
����: Mon Jul 19 06:22:29 1999
hmm, about war movements, we have troops upgrade projects ahead,
conditions will be changed after it's implemented

about emote, it's different from LPMUD, emotes r devided into 2 catagories:
no targe, and with target

hmm, about the sentences of rumor, i think we can adjust it later
now we need to debug and develop some urgent projects


---
����: Tit
��Ŀ: can change this rumor?
����: Mon Jul 19 05:52:16 1999
�ҥ�ԡ�ĳ�ˣ��׿��ķ�׿���Ϊ��ɣ��̫�ء�
change to 
*** king take over *** taishou.
pls consider.


---
����: Fire
��Ŀ: about player's number
����: Mon Jul 19 01:49:35 1999
when the number of players more than 50
then if use update here
will have bugs
seem 50 is a key point


---
����: Row
��Ŀ: >about player's number
����: Mon Jul 19 01:56:35 1999
that is aweful, how to solve it?


---
����: Tit
��Ŀ: can change this rumor?
����: Mon Jul 19 04:29:16 1999
��ҥ�ԡ�ĳ�ˣ��׿��Ľ��׿����ɵ�������
This sounds not quite nice.
can change this to 
*** king "chu xun" or "xun shi" to somewhere?
pls consider.


---
����: Tit
��Ŀ: what emote!
����: Mon Jul 19 05:06:35 1999
chat* kick tit
����ġ��������һ���������Լ���ƨƨ�ϣ�ӡ��һ�������Ьӡ��
it seems not reasonable bah
kick �Լ���ƨƨ��һ�������Ьӡ?
may change to something else?
like ����ġ�����һ���������ȥ����С��Ť���Լ��Ľš�
just like kick nothing
pls consider.


---
����: Tit
��Ŀ: about move points
����: Mon Jul 19 05:17:52 1999
can we make that with the trainnig, the max movepoint of the troop can 
increase. some special area will cost a lot move points. maybe greater than 
the usually footman's max movepoints. so players have to train a lot 
increase movepoint or change to horseman to decrease movepoint cost.
just a suggestion.
pls consider.


---
����: Tit
��Ŀ: about base&job
����: Tue Jul 20 02:52:39 1999
�������� need some �˿� to do so.
so as a part of the �������� job, can let player to find people to do so 
at first?
just like sanguo caocao 's "tun tian"?
and can be divide as "jun tun" and "ming tun".
just a idea, pls consider.


---
����: Ice
��Ŀ: about ˰��������
����: Tue Jul 20 04:13:20 1999
���ڵĳ����ڿ�����˰��10 taxnation,70 taxlocal��֮����Ȼ�
��չ�����ڿ��Ź��һ��飬�ڹ�˰�ɵ�������£����������������
�����ҡ������������£�

1�� ��˰���˰֮�Ͳ�����100%����Ϊ����
2�� �ֵ�˰��������Ϊ10-70%�������˰Ϊ 5-50%����˰�ϵ�һ����
    ȫ�������½���㣬�µ�һ����ȫ����������һ�㡣
3�� ���һ��������˰��֮��Ϊ100���˿�ÿ���½�һ�룻
    ����80���˿�ÿ���½��ķ�֮һ��
    С��80����60���˿�ÿ���½�ʮ��֮һ��
    С��60����40���˿��ȶ���������С����������
    С��40����15���˿�����������




---
����: Row
��Ŀ: about cmd job stat
����: Sun Jul 18 22:05:36 1999
should we make cmd job stat the wiz-only cmd?
seems it provides too much info to player lah.


---
����: Row
��Ŀ: yu ji job is ok now
����: Sun Jul 18 22:11:08 1999
test ok


---
����: Ice
��Ŀ: suggestion about non-navy troops' loss in water
����: Sat Jul 24 16:21:34 1999
1. if step in water, each step will lose 1/50,
2. if stay in the same water room more than 5 secs, lose 1/20 every 5 secs.


---
����: Ice
��Ŀ: >about train
����: Sat Jul 24 16:07:48 1999
let me take an example:

now i am officer in longxi, there r 5 officers in the meeting(4 npc),
and i cmd train, only 1 npc cmd me. it means that i can lead at most
9k troops,
if player don't login dummies, they cannot even hold a 12-task
train, so they have
to login dummies to cmd me then quit them as npc, i dun think it's a good way
to encourage player to do train jobs, i have the following suggestion:

1. if we r not willing to make all the officer in the meeting
involve in the train,
   (though I think it's reasonable.:P at most 10 officers in a
meeting, not too much)
   we can make the NPC in wuguan position must cmd me if he attends
the meeting,
   it's their job...:P

2. since commando's train and morale r fixed, I dun think it's
necessary to let
   them train, however, they will attend if it's a bandit attack or
war, but seems
   no need appear in train.

a good example of large troops r impossible to train with is
luoyang, it has 80k,
but each traini can at most take 20k, after averaged, add only 1
traini and morale
each train, which discourage players.


---
����: Fire
��Ŀ: about maker and obj
����: Fri Jul 23 10:04:08 1999
for a certain obj, if we want to find who can make it
the right function is OBJ_D->get_obj_maker(<obj id>)
now i add a static mapping for that, so it is very quick
but for later dynamical obj system, may need a update function


---
����: Fire
��Ŀ: ��ɫϵͳ�ĸ���
����: Thu Jul 22 11:03:38 1999
1 ��ɫ��������ĸ�����move�е�hook��ɣ���ԭ����smartmove�м�code
  �ķ������ӿɿ���
2 ���е�npc��ɫ�����������/sgdomain/modules/char_server(CHAR_SERVER)
  ������������ʹ�ý�ɫ�������Ѱ���ӿ��ٿɿ���ȱ����û�а취ʹ��
  children(<body file>)�ķ����õ����ɫ�嵥������ϵͳ�Ŀɿ�����˵
  �����ĸĽ����ֵ�á��ɴ˸��¿��ܻ�����һϵ��BUG�����Ѿ��޸���boy,
  guy�е�һЩ���BUG���������ڲ�����children����ѯ��charheart_d ��
  �޷����������ڵ���Щ��ɫ���޷��Զ����(���BUG��ͷ����)������
  �϶�����������������BUG����ע��۲�㱨���Ա㼰ʱ����
 


---
����: Ice
��Ŀ: an idea about ring of marriage
����: Wed Jul 21 16:08:20 1999
we provide the name of rings, only brief long and wear/rm msg,
after ppl buy the rings, they can write their own desc and wear/rm msg
b4 going to marriage, and after the marriage is processed, it's set.

* smirk


---
����: Tit
��Ŀ: today many players war a each other to get anding for the starting cities
����: Thu Jul 22 03:15:57 1999
today many players war each other to get anding for the big cities and get
some other rewards.
e.g. changsha and chaisang war chibi many times.
e.g. changsha and chaisang war chibi many times.
war is not a easy thing, i beleive.
so i suggest that whoever start a war, attacker side and defence side should
both
drop anding. just like Civillization II.
of course if war win, get back some anding, but in total, should drop anding
for both side.
of course if war win, get back some anding, but in total, should drop anding
for both side.
e.g.
attacker win drop anding 20
attacker lose drop anding 50
defencer win anding donot change.
defencer lose anding drop to 30

this is just to avoid the "bug". just a suggestion. pls consider.


---
����: Row
��Ŀ: >today many players war a each other to get anding for the starting cities
����: Thu Jul 22 03:19:35 1999
agree tit.
and player only use 1 soldier to attack intend to add morale or train of
the target area, so we should set a lower limit of troop number of war.


---
����: Tit
��Ŀ: or give more punishment to loser side
����: Thu Jul 22 03:26:17 1999
continue with last post
when attacker lose one war, just like being pked in other mud.
everyone on line attend the war drop 1 lel skills.
and players in the same country donot attend the war, but one line drop half
lel skills.
defending side lose a war, attend war on line players drop 1 lel skills. not
attend the war drop half lel skills.
or for defending side punishment half of above, that is:
on line players and attend the war lose, drop half lel skills.
not attend the war drop 1/4 lel skills.
just let players be more careful when they want to war.
just a suggestion, pls consider.


---
����: Ice
��Ŀ: >>today many players war a each other to get anding for the starting cities
����: Thu Jul 22 04:15:07 1999
agree


---
����: Ice
��Ŀ: suggestion about recent changes of war
����: Thu Jul 22 18:26:04 1999
1�� ս������ʱ��

���ڵ�ս������ʱ����ԵĲ���������˫�������൱�����ط����
�����������ս������ɹ������������������齫���������������
ս����ʱ���ӳ�һ���ӣ�saying that ���������о�ǰ���г� or ��
�ڽ���ս��������ʵ�ֹ�ƽ��ԭ�򡣻�������һ�ַ������������һ
��δ�ܽ���ս������һ������ʾ�����ڽ���ս���������ط�����ٳ�
���ֱ���ϣ�ϵͳ���Զ�������������ϣ��Է�ֹ���ط������ӳ٣���
����Ϊ�Ժ��֧Ԯ��Э����һЩ�̵棬ֻ�������������Ĳ������Ƚ�
�������и�������ֻ���ڻ���ͨ��ͬ���ɱ�֧Ԯ֮��ſ�ʼ�Լ���ս��
����Ҫһ��ʱ�䣬˭�ĸ��������Ƚ����Ϳ��컯�ˡ�

2�� ���ӽ�����λ��

���ڲ��ӵĽ�������������ģ����˷��ز��ӻ��ڳ���Χ����֮�⣬
�������Ӹ��������ڶ�ʱ���ڼ���������˽��Լ����ӵķֲ�������
��ÿ��ս������һЩ�������ӳ��ֵ�������A1-T1��A1-A16�ȣ�Ҳ��
���ӽ�������ͬ��ı�Եһ�������ұ˴����ڣ��������ĸ��������
���������������ͬһ������ˡ���������ݳ��н����ķ��������
R5��R9�ĵط�һ���ӳ����ˣ��Ǻǣ������û��һ�㡣

3�� ���������޸�

���ڵĻ��������ֵ��30����������Ҳ��ӵĻ����ԣ������ڽ�����
���������󣬲�ͬ�����ڲ�ͬ���εĲ�����׷ֱ��������ʾ����
���������ó����ε����ơ����齫���������ֵ���ó�100���Ա���
���ӿ��ԡ����紦�ӣ��������á����Ժ������֮��Ĳ�������Ҳ
����������á�������btw�����쿴��������9������ܣ���֪������
��ϵͳ��Ӧ������busy time ȡ���ˣ���֮������һ������2����Ų
���������Ǻǣ�����busy time ���Է�ֹ����������������ܵ������

4�� ���ӽ����������ʱ����ʧ

���ڻ������в��Ӷ����Խ����������������û�д�ѽ������������
��ѽ������Ѽ����ˮ����ֱײ����ë��û����һ��������������
�ɡ�������ģ�����ˮ������֮�⣬�������в����ڽ����������һ
�Σ���ʧ1/n�ı�����n�Ĵ�С���Ը��ݱ�����ɫ����ͬ���ţ�����ȫ
�����1/10Ҳû��ʲô���⣬����û�д����͸�����һ�㡣������ʹ
�����ս�����õ�ʱ���Ǹ���ĵ������⣬�������ӵ����������
ֻ���ӹ���Ч����

5�� ս���밲���Ľ�һ������

��ԭ�л����ϣ���tit��˵�����������еľ������ս��������ֻţ�
���°����½��������ڵı�������ʧ�أ������İ���ҲӦ�û��½���
����ν���Ļ̻̣��ٺ١�

��tit�Ĺ�ʽ�ƺ�����һ�㣩�����鹫ʽ��

��������ĳ�ǣ�safety - 10 �����۳ɹ���񣬻�ֱ�ʧ�ܣ�

����ĳ�ǳɹ���no change

����ĳ��ʧ�ܣ�safety b4 loss / 2 
        ��ĳ�Ǿ�����һ������飬��ʧ���������ذ����½��ˣ�

���ڵı�������ʧ�أ�safety - 30
����ֹ��ˮ/���ʱ���ٴ����ݣ������Ժ�֧Ԯ���ܳ����ˣ����ڵ�
��������Ӧ���е��൱���Σ�

6�� ս����ѵ��ʿ��

�����Ľ��ͽ���ʧ�ܷ��İ��������ܸ����ؽ��ʹ�������������
���ڵ��ѹ�����ѵ��ʿ���ķ�������Ϊ�������׵ؿ�������������
���£�

����ʧ�ܷ����е�ѵ�� / 2��ʿ�� / 2
������ֻ�е�war_idea�����ѵ����ʿ����Ϊ��������ʱ����Ч��

7�� ����������߰����ֶεĵ���

�������ֶΣ������Ҫ�����������ͱ�������������ߣ������ǵ�
���ڻ������￪��Ϳ��Խ���ġ��������£�

����˰�ʣ���war_idea���������˰�ʵĵ��������ƣ���ÿ�ε���
          ���ܳ���20�������ļ��ҲӦ���У�Ʃ��ÿ���³���ֻ
          �ܵ���һ��˰�ʡ�

������������ʱ�ܿ��ֵ������ȿ�ս���ͣ�����ڰ���89ʱ���֣�
          ֻҪ���������˿ڵ��������ͱ�119�ˡ����齫���ֵ�
          ��׼��ߣ�ֻ�е���������60ʱ���������������ս��
          ������100����ô���ٻ�Ҫ��һЩ��������˳����ս��
��really dun think war is a easy stuff, so if want war, work hard��

8�� ս�������ĵ���

��������ȫ�������������ˣ�ս����ԭ�Ƚ�û��Ŀ�Ļ���ȷת��
��Ϊ������ս��Ŀ�ĵĹ����Եأ�����ĳЩ�������ĵ�ս��������
�������ھ���û������һ���������������Ҳ�����������������
Ϊ�˹�������̵�����Ҳ���Խ����Ļ�ˣ��������£�

������ʤ����
������          random skill + 1000
��������ң�    random skill + 500
��ͬ������������random skill + 600
��ͬ��������ң�random skill + 300

���ط�ʤ����
������          random skill + 800
���ص���ң�    random skill + 400
Э����������    random skill + 600
Э������ң�    random skill + 300

˳����һ�¹����츳���������������뷨���츳������������ߵ�
�������������������Բ��ܳ����츳���ޣ��˶�ʤ���ֻ�Ǻ���
���Ѻ��Ѷ��ѡ������������������£�

�������ﵽ�츳����ʱ��������ʽΪ��

%^GREEN%^exp = %^H_CYAN%^10 * %^GREEN%^lev * lev * 20 / (gift)%^RESET%^
���ٺ٣����Ѱɡ�������

pls raise ur doubts, and if i am here, talk to me bah ..:)


---
����: Fire
��Ŀ: the automatically act of npc chars are added
����: Thu Jul 22 20:37:21 1999
don't know if more bugs :(

I will begin to adjust war next step
addoil all :)


---
����: Ice
��Ŀ: basicjob: babysitter
����: Fri Jul 23 01:06:46 1999
ask zhang about job

��������Ա������������������顣
��Ա��˵��Ȯ���������˹̣ܽ�������/С������Ҵ�һ�����ɡ�

//this job is unique, if some one is doing, no one else can do

��Ա�������֣�һ����Ƥ��С�к�һ��һ�������˹�����

look

���������󸻺�����Ա��(zhang yuanwai)
�ż�С��ү��zhang shaoye��

�ż�С��ү������˵������ү��Ҫ����������η�ȥ�档
//all destination of this kid is inside huayin, so fire need remove
  the �ܵ� and �ϻ��� in huayin, i can remove it in map.:P

ask zhang shaoye about w
�ż�С��ү����ԥԥ����������ȥ��
//use same idea as xuzijiang, and can be a preparation of xu's job..:P

//���˵�ͷ
ask zhang shaoye about arrive
���������ż�С��ү˵������ү�����ˣ�����ʲô�Ը���

//if not right room
�ż�С��ү���´�У���ƭ˭�������������

//if more than 200 secs not arrive, job failed, cannot do it in 30 mins
�ż�С��ү���������ߡ���һ���������ܿ��ˡ�

//if arrive in the right room within 200 secs
�ż�С��ү��Ŷ����һ����ԭ����������ѽ������Ϊ��ʲô����ĵط��ء�
�ż�С��үһ���Դ��������һ���ȥ�����߿�����

//repeat the same process, same 200 secs limit
�ż�С��ү���š���һ����
�ż�С��ү������˵����������û���������������ң�Ҫ�������ҵ�ȥ��
�ż�С��үһ���̵��ܲ����ˡ�

//back to zhang
���������󸻺�����Ա��(zhang yuanwai)

ask zhang about pay
//if job failed
��Ա��һ�Ѿ�ס�����ڣ��㻹�������������ͣ�һ��ȥ��

//job succeeded��Ա��������ļ����������������������һ����ˣ��������ͣ�
//robot test and tiezi same random as chopping and digging
�㱻����ʮ�����ӡ�




---
����: Ice
��Ŀ: basicjob:buyfood
����: Fri Jul 23 01:31:33 1999
���� �

    ��������Ǻ����ˣ�����ܴ󣬵����õ÷ǳ��������־��£�Ҳ
������Ϊ��С��Ĺ뷿����¥�ϵ�Ե�ʡ�����ǽ����һ��ˮ��ľ�ķ�
�����������һ�ײ�ߣ����ӱ��������Ÿ߱�ľ�Ρ������԰���ֻС
�ɵ�ľ����������һֻϸ�ɻ�ƿ������Կ���һ����¥��ͨ���¥��

��Ա���Ԫ�� �ŷ��ˣ�zhang furen��

ask zhang furen about job
�������ŷ��˴�����������������
�ŷ���ЦЦ˵���ѵ�����ô�����⣬��ȥ������㶫�������ɡ�
�ŷ���˵�������ǧ��Ҫ�����ˣ��ҿ�ֻ˵һ�飬��Ҫ����
��ƽ����¥֮��С�����Ŀ�Ѽ �� ԥ��ˮ��̯֮С������ƻ����

//target obj will be food and drinks only
//cmd job will only show the target obj, the location won't be shown any more

//cannot finish or some other problem
ask zhang furen about cancel
������ɥ�������ŷ���˵����С�ĶԲ�����ˣ�С�ĶԲ�����ˡ�����
�ŷ��˰��������۽Ƕ���ɨ����һ�¡�

ask zhang furen about pay
//if no target obj in this body
�ŷ���һ�ֲ�����һ������ָ���������Ķ�ͷ�����ƾ�㣿��ˣ�ң��ߣ�

//if right obj
�ŷ��˰������������ ��Ѽ �� ƻ�� ������һ�£�����ص��˵�ͷ��

//same robot test, tiezi random as chopping and digsioil
�ã����ͣ�
����������������ʮ�����ӡ�

//since no more than 1/5 of the food and drink is over 40 silver, we can
  set the money reward of this job random from 30 to 60, it's a fair
  chance to get profit or loss, however, they can hold the food
  and drink, which are clean and ready to eat..:P


---
����: Ice
��Ŀ: about train
����: Sat Jul 24 12:48:06 1999
although fire said we'll add a midjob to increase local morale, i think
we need to change train a little bit.  now if a player cmd train, 
no more than 3 officers will auto join, which can at most bring 20k
each train,
so if a city has more troops, the train almost means nothing but
adding 1 each time.

i suggest to change the npc's auto cmd me, make it possible to train
with all possible
NPC in meeting will cmd me to train.


---
����: Yuyin
��Ŀ: bug ����
����: Sun Jul 25 02:00:13 1999
�������磬xixixi˵ chibi ���̵�ʱ���� bug
���� chibi �ġ�ʿ    ����
��  ����    �ڡ�
��ȫû��
���д����˵��������ڷֱ�ʱcmd over.
�ͻ����bug
���һ�û���Թ�,��fire ��һ��


---
����: Stefan
��Ŀ: driver udpated
����: Sun Jul 25 04:24:54 1999
We are now using a new driver 22.2a21.

If you check /log/log, there are just a lot of warnings, somebody
please fix it :)

I hope this time SanGuo should be more stable, but dunno... 

Because of the driver update, there may be some code broken, if any wiz
finds any broken code, please report.



---
����: Group
��Ŀ: faint
����: Wed Jul 28 06:27:07 1999
guwu is for permenant increase of morale? faint....
the function i used is the same which call all the troops decrease 1
morale for 1 heart beat during wars...is that one also pemenant?
if the answer is yes.... hmm... i will try to find a way to decrease temp one.
fire, please give a answer for this...thanks

group


---
����: Ice
��Ŀ: about boy
����: Wed Jul 28 06:32:06 1999
hmm, if boy ask for specific food or drink depending on target,
it sounds tough, bcoz if ppl need to find sb, he has to find out
that kind of food first, then need ask boy about xianren, then ask
baodating....
a too complex way, how about this?

make boy's request depending on area, that is, if i go luoyang, luoyang boy
will ask for one kind of food for all comers, which can make it easier and
more fun.  and we need to make the boy's request refresh in a certain time,
hmm, how about every one sg month, boy changes his taste month to month,
hmm, and on the other hand, we can make ask boy about xianren will cost only
mantou, bcoz xianren dun belong to any area, and highhands always no need to
do that job.

by the way, i think we need to increase or change the reward of findbody,
otherwise if find a ppl need 15 silver food, but get paying 5 silver, no one
will do it..:P


---
����: Ice
��Ŀ: about midjob
����: Wed Jul 28 06:45:33 1999
now most midjobs r targetless, like fanpeople, whisper.....
well, in KOEI's game, player can have freedom to choose which
target officer or city he would like to go, though we cannot
do the same here, i think we should change those nasty job's
method of getting area like spy job's, depending on the distance..:P


---
����: Fire
��Ŀ: >faint
����: Wed Jul 28 08:08:41 1999
On Wed Jul 28 06:27:07 1999 Group wrote post #688:
> guwu is for permenant increase of morale? faint....
> the function i used is the same which call all the troops decrease 1
> morale for 1 heart beat during wars...is that one also pemenant?
> if the answer is yes.... hmm... i will try to find a way to decrease temp
one.
> fire, please give a answer for this...thanks
> 
> group

now the morale just has one variable to hold it so all the act
on it is permenant. we may need introuce a temp morale later
but now just use it. I think it is ok.
make sure we use the same function, so if we need adjust later
just adjust that function but don't need adjust those code call
that function. 
about guwu, I think we need related skills to it
I will make a place for players to learn such skill

addoil ):


---
����: Fire
��Ŀ: >about midjob
����: Wed Jul 28 08:10:03 1999
On Wed Jul 28 06:45:33 1999 Ice wrote post #690:
> now most midjobs r targetless, like fanpeople, whisper.....
> well, in KOEI's game, player can have freedom to choose which
> target officer or city he would like to go, though we cannot
> do the same here, i think we should change those nasty job's
> method of getting area like spy job's, depending on the distance..:P

bugao has been designed related to the distance like spy
others will adjust later :)


---
����: Ice
��Ŀ: redo of local positions
����: Wed Jul 28 16:20:25 1999
���йٽף�

lv 1

������������ 
����ү������ 
���Ĺ٣����� ���� ���� 
���佫������ 
����٣����� ���� ���� 

lv 2

���峤������ 
����ү������ ���� 
���Ĺ٣����� ���� ���� 
���佫������ ����
����٣����� ���� ���� 

lv 3

����̫�أ����� 
�����ʦ������ 
����ү������ ���� ���� ���� 
���Ĺ٣����� ���� ���� ���� ���� ���� 
������������ 
���佫������ ���� ���� ���� 
����٣����� ���� ���� ���� ���� ���� 

lv 4

��̫�أ����� 
����ʦ������ 
����ү������ ���� ���� ���� ���� 
���Ĺ٣����� ���� ���� ���� ���� ���� ���� 
���󽫣����� 
������������ ���� ���� 
���佫������ ���� ���� ���� ���� 
����٣����� ���� ���� ���� ���� ���� ���� 

lv 5

��̫�أ����� 
����ʦ������ 
������ʦ������ ���� ���� 
����ү������ ���� ���� ���� ���� 
���Ĺ٣����� ���� ���� ���� ���� ���� ���� 
���󽫣����� ���� ���� 
������������ ���� ���� ���� 
���佫������ ���� ���� ���� ���� ���� 
����٣����� ���� ���� ���� ���� ���� ���� 

note��in the currently existing local positions, �佫 in lv 3 city is a kind
      of confusing with �佫 in lv 1 and lv 2 cities
on the other hand, no.
      of positions in city differs the cities levels, i changed some numbers
      of positions. I erased all ���� position and replaced it as ����, and
      put �佫 in lv 4 and lv 5 cities, to standardlize the positions.


�ط���ְҪ��

�Ĺ�

rep��                     200
local contri��            10
loyalty��                 50
skills��                  bfxy 30 zgxy 30
salary��                  1


���

rep��                     200
local contri��            10
loyalty��                 45
skills��                  bfxy 30 wxxy 30
score��                   att_abi 10
salary��                  1

��ү

rep��                     2000
local contri��            200
loyalty��                 55
skills��                  bfxy 35 zgxy 35
salary��                  2

�佫��

rep��                     2000
local contri��            200
loyalty��                 50
skills��                  bfxy 35 wxxy 35
score��                   att_abi 20
salary��                  2

���ʦ/����ʦ��

rep��                     10000
local contri��            500
loyalty��                 65
skills��                  bfxy 50 zgxy 50
salary��                  3

������

rep��                     10000
local contri��            500
loyalty��                 60
skills��                  bfxy 50 wxxy 50
score��                   att_abi 30
salary��                  3

��ʦ��

rep��                     20000
local contri��            1000
loyalty��                 75
skills��                  bfxy 70 zgxy 70
salary��                  5

��

rep��                     20000
local contri��            1000
loyalty��                 70
score��                   att_abi 40
skills��                  bfxy 70 wxxy 70
salary��                  5

��ְ��

rep��                      -
local contri��             -
loyalty��                  -
skills��                   -
salary��                   1

̫�أ�

level 1�� 
rep��                      -
local contri��             -
loyalty��                  50
skills��                   -
salary��                   2

level 2��
rep��                      -
local contri��             -
loyalty��                  60
skills��                   -
salary��                   3

level 3��
rep��                      -
local contri��             -
loyalty��                  70
skills��                   -
salary��                   4

level 4��
rep��                      -
local contri��             -
loyalty��                  80
skills��                   -
salary��                   6

level 5��
rep��                      -
local contri��             -
loyalty��                  90
skills��                   -
salary��                   10

note�� 

1��added local contri as a requirement, basicjob->findbody need to be
adjusted,
   thus player officer cannot change his city unless his king or ��ʦ
permited.

2��added loyalty of taishou position, when a taishou or a king wanna pos the
   taishou position to an existing officer, has to consider his loyalty first,

   otherwise the officer cannot be taishou, hope it can help to solve the
dummy
   taishou a little.

3��suggest to add a requirement of officers transfering, for example, if a
king
   named sb as taishou, or transfer an officer to a new city, this taishou or 
   officer cannot be transfered again within 1 mud year.  if a real taishou
pos
   his taishou position to an officer in his city, he is supposed that he
cannot
   get it back within 1 mud month.

4��added att_abi in score to restrict the ���'s position��hmm, since ���
need
   to war mainly, should consider his fight ability in his position
requirement.
   the requirement of officials should be higher than officers, since they dun
   need to fight.



---
����: Fire
��Ŀ: >redo of local positions
����: Wed Jul 28 19:48:57 1999
thank ice's post
I have check it and find most are very nice
the only problem is can anyone find some 
good chinese name (sound like sg time) to replace the current name ?
thanks


---
����: Ice
��Ŀ: names of local positions
����: Wed Jul 28 23:49:54 1999
���йٽף�

lv 1

������������ 
���ξ������� 
����������� ���� ���� 
����������� 
������������ ���� ���� 

lv 2

���峤������ 
����ү������ ���� 
��ͨ�£����� ���� ���� 
����������� ����
������������ ���� ���� 

lv 3

����̫�أ����� 
����ݣ����� 
�����£����� ���� ���� ���� 
����ܣ����� ���� ���� ���� ���� ���� 
���Խ������� 
������������ ���� ���� ���� 
����������� ���� ���� ���� ���� ���� 

lv 4

��̫�أ����� 
������������ 
�����У����� ���� ���� ���� ���� 
�����ܣ����� ���� ���� ���� ���� ���� ���� 
��ƫ�������� 
������������ ���� ���� 
���ཫ������ ���� ���� ���� ���� 
����ξ������ ���� ���� ���� ���� ���� ���� 

lv 5

��̫�أ����� 
����ʦ������ 
����ı������ ���� ���� 
�����ܣ����� ���� ���� ���� ���� 
�����ܣ����� ���� ���� ���� ���� ���� ���� 
������������ ���� ���� 
������������ ���� ���� ���� 
���佫������ ���� ���� ���� ���� ���� 
��Уξ������ ���� ���� ���� ���� ���� ���� 


---
����: Ice
��Ŀ: another heaven of idlers
����: Sun Jul 25 23:17:49 1999
Ŀǰ��������6��
��������������������������������������������������������������������������
����ͨ���֡���ҵ�������˿�������(dolly)                             
           
���±�ǧ�ԡ�ˮ�ι�����Ĺ����۲�(cool) [���� 5 Сʱ]                
           
�����������֮������ɽ��ְ�����ա��һ��ֺٺ�(fire) [���� 1 Сʱ] -������-
����ͨ���֡��۹������Ĺ١���Ѫ���������壬�����(row) [���� 36 ����]
���±�ǧ�ԡ���֮������̫��������������(meimei) [���� 18 ����]       
           
��С���Ĳɡ���֮����ƽ�峤�������У�z��Z�ڡ���������β��(ice)


---
����: Ice
��Ŀ: about ��Զ�̡�
����: Sun Jul 25 22:48:01 1999
when player use gini to do ��Զ�̡� emote, it's supposed to show
then gini id instead of the name, otherwise it can be unfriendly
bothering......



---
����: Stefan
��Ŀ: >another two bugs caused by the new mudos
����: Sun Jul 25 22:10:10 1999
On Sun Jul 25 08:29:12 1999 Fire wrote post #677:
> 1. in the verb parse
>    the parse of "STR" does't recognize Chinese strings
> 2. can't do semote to players in another room, 
> stefan, please have a look :)

I'll fix the verb in a few days.


---
����: Fire
��Ŀ: seem the new mudos is more stable
����: Sun Jul 25 19:57:51 1999
addoil :)


---
����: Fire
��Ŀ: another two bugs caused by the new mudos
����: Sun Jul 25 08:29:12 1999
1. in the verb parse
   the parse of "STR" does't recognize Chinese strings
2. can't do semote to players in another room, 
stefan, please have a look :)


---
����: Fire
��Ŀ: ����MUDOS����
����: Sun Jul 25 07:31:30 1999
�ǳ���лstefan��mudos ����
I hope this new mudos will solve our crash problem.
now i find two different between the new os and the old one
1, the compile are more strict, will give wrong to the
   unreference variable, (may be this is a swich in some place
    but i think this feature is good, can help us to find potental
    bugs)
2, the call_out is much faster than before
   in the code of thief, i usually use 
   call_out("escape",random(2)) then find it is too slow so
   i change to call_out("escape",random(1))
   in fact random(1)=0; so the call_out will be execute immeatately
   but in old os, it still has some delay, so it is just sutable for
   players to catch thieves, but in the new os, it is much faster
   so thief will disappear at no time, so have to change it back
   to call_out("escape",random(2))
   there may have more difference, but let hope this new os
   can help to solve the serious crash problem :)


---
����: Ice
��Ŀ: faint
����: Mon Jul 26 06:08:58 1999
Ŀǰ�� 22 λ��ҡ�0 λ��ʦ����Ϸ�У����� 1 λ�������ߡ�
Ŀǰ�� 12 λ�� 202.102.66.221 ���ߵ����:
wispy, gods, snowcc, ybing, bamboo, young, goda, snowqq, dummya, dummyb,
dummyc, dummyd.



---
����: Fire
��Ŀ: another differece between the two mudos
����: Mon Jul 26 08:51:08 1999
for old mudos
we use get_dir(<dir>) to retrieve all the file names
under that dir, now for the new mudos
have to sue get_dir(<dir>+"*.c") to get the result
this may cause some program don't work properly


---
����: Yuyin
��Ŀ: bug �㱨
����: Mon Jul 26 11:12:30 1999
na $nationtax qiao 20
������������磺��λ���䣬����ΪĿǰ������飬���ɽ��۳ǵĹ���˰����ʮ���ӵ���
ʮ
 ��ҥ�ԡ�ĳ�ˣ���������۳ǵĹ���˰����ʮ���ӵ���ʮ��
na #agree yuyin
*Bad argument 2 to member_array()
Trace written to /log/runtime


---
����: Ice
��Ŀ: about cast guwu
����: Mon Jul 26 16:46:05 1999
group, seems now cast guwu increase morale for permanent,
i casted guwu in war, then after war the rest morale + 20..:P
remember to change it to temp..:)

* escape


---
����: Row
��Ŀ: i hate exam
����: Tue Jul 27 21:17:31 1999
becoz of my academic work, i will be buzy and 
absent from here for around 2 weeks, sorry
for the delaying of my work, i'll pick it
up again when back.

                              row.


---
����: Fire
��Ŀ: >i hate exam
����: Tue Jul 27 21:18:16 1999
On Tue Jul 27 21:17:31 1999 Row wrote post #686:
> becoz of my academic work, i will be buzy and 
> absent from here for around 2 weeks, sorry
> for the delaying of my work, i'll pick it
> up again when back.
> 
>                               row.

addoil row, we are waiting the jiebai system :)


---
����: Ice
��Ŀ: suggest change the name of ranknation
����: Fri Jul 30 06:34:49 1999
ة�࣬���У���ʷ
�󽫾������ɽ������Ž�


---
����: Ice
��Ŀ: about obj level and officer level
����: Fri Jul 30 06:30:26 1999
now players said they r confused by the lv of obj and position,
and then dunno which they can order.

i think we can make this point clear, first in obj(maker)

����������������֣����������ò��񿴿����������Щʲô����
������������֪������ҪЩʲô��
��Ʒ����             �����          ������          �޸ļ�         ��Ʒ�ȼ�
------------------------------------------------------------------------------
С���(xiaotieji)    ��������        ʮ��������      ʮ������           ��
blah blah

second, i'll make a help level file to let player check their
level of position.

how do u guys think about it?

hmm, where can i check the position level yah?.:P * blush


---
����: Stefan
��Ŀ: ed fixed
����: Fri Jul 30 02:14:54 1999
as title :)


---
����: Fire
��Ŀ: ���ڼ�ı����ƹ淶��
����: Thu Jul 29 23:37:08 1999
����group�����һ����ıguwu������Ϊ����һ����ϵͳ
�ĺܺõĿ��ˡ�Ϊ�˱��ڽ��ķ�չ��������ϵͳͳһЭ��
�ҽ�����ڼ�ı����Ʋ������¹淶��
1   ���еļ�ı�� cast ������ִ������Ϊ��
    cast <jm_id> [target]
2   ���м�ı�Ķ���������ļ����ڣ�
    /sgdomain/jimou/ ·���¡��ļ��������ıIDһ��
3   ÿһ��ı��һ��Ӧ��(����skill�ҹ���
4   ���һ��module file�����ڴ洢���(����npc)��
    ��ıʲô��������磺ĳһ��ıʹ�õĴ�������һ��
    ʹ��ʱ��ȡ�
5   ͬһ��ɫ��ʹ��ͬһ��ıʱ��������̼����
6   �������ƣ�
    1. �������
    2. �������
    3. �������
7   һ��ıʹ�ú󣬸��ݸý�ɫ�����skill�ĸߵͣ��������
    (�粿��ʿ����������ѵ����ʿ�����з���ɫ�Ĳ�����)
    ���츳������
    1. ��ı�Ƿ�ɹ�
    2. ��ı��Ч����С
    3. ���ġ����а���
        1 ���ʷ��棺 ��gold,stuff��
        2 ʱ�䡣(busy time)
        3 ���ӵ�(busy time)
        4 blood and spirit
8   ��ıʹ�ú����
    �������࣬�ɹ���ʧ�ܡ�
    �ɹ����кô���ʧ��Ҫ��һЩ��������(��Ҫע��ƽ���
    Ǳ��bug)�������������ң���Ӧ���ܵľ���Ҫ���ӡ�
9   ��ı���ܵ�ѧϰ��
    1  �Ӻ��۵��鷿
    2  �ر��quest
    3  �ͻ�������һ����30��֮ǰû�о�������ƣ�����
       30��Ҫ��һ��������С�
10  һЩNPC�м��ܣ������Զ�ʹ�á�


---
����: Ice
��Ŀ: about guwu
����: Thu Jul 29 20:12:39 1999
����۸ߺ�����ͼ����ʿ���Ķ�־��
����۸ߺ�����ͼ����ʿ���Ķ�־��
����۸ߺ�����ͼ����ʿ���Ķ�־��
ʿ����Ⱥ�鼤�ܣ�ʿ�����ǡ�
ʿ����Ⱥ�鼤�ܣ�ʿ�����ǡ�
ʿ����Ⱥ�鼤�ܣ�ʿ�����ǡ�

busy time only work for other actions, if take the same
action, no restriction at present, group pls add it.

and the upcoming trickies should be designed in the same way.:P

addoil..:)


---
����: Fire
��Ŀ: ed has problem
����: Thu Jul 29 19:29:55 1999
now use ed can't display Chinese properly.
so, Stefan please fix this problm bah, xixi :)


---
����: Fire
��Ŀ: >sth wrong with ed(at least on ice's body)
����: Thu Jul 29 19:20:04 1999
On Thu Jul 29 15:41:18 1999 Ice wrote post #700:
> when i use more <file_name>, everything is normal and ok;
> but if i use ed <file_name>, i cannot read chinese at all,
> only show characters like the following
>    set_long("
> ^T^S^U^N^D^Z^I^O^O^B^U^F^[^P^[^T^[^M^C^L^P^K^C^[^J^L^N^@^V^D^W^S^K^F^U^X^U
^^^T
> ^Z^V^\^N^G^A^C^U^N^D^Z
> ^X^W^P^T
> 
> blah blah, dunno what's wrong with edit or i am not doing in
> the proper way, hmm, and there r lots of "^M" at the end of each line
> in most of the files..:(  pls check it.:(

i think this is because this file has been transferd by wrong
mode during ftp. 
so I strongly suggest when use ftp, turn on asicc mode


---
����: Ice
��Ŀ: sth wrong with ed(at least on ice's body)
����: Thu Jul 29 15:41:18 1999
when i use more <file_name>, everything is normal and ok;
but if i use ed <file_name>, i cannot read chinese at all,
only show characters like the following
   set_long("
^T^S^U^N^D^Z^I^O^O^B^U^F^[^P^[^T^[^M^C^L^P^K^C^[^J^L^N^@^V^D^W^S^K^F^U^X^U^^^T
^Z^V^\^N^G^A^C^U^N^D^Z
^X^W^P^T

blah blah, dunno what's wrong with edit or i am not doing in
the proper way, hmm, and there r lots of "^M" at the end of each line
in most of the files..:(  pls check it.:(


---
����: Stefan
��Ŀ: FTP and HTTP fixed
����: Thu Jul 29 12:57:47 1999
socket was much updated in the new driver, which caused them to fail.
Now FTP and HTTP should work.


---
����: Fire
��Ŀ: the name of local officer
����: Thu Jul 29 07:41:24 1999
now the local officer use the name as ice given
admire ice, how could get so much names
addoil :)


---
����: Fire
��Ŀ: >http server can not work
����: Thu Jul 29 07:39:39 1999
On Thu Jul 29 04:18:25 1999 Flee wrote post #696:
> is it because of the new MudOs ?

now the ftp and http either works properly, stefan, please have
a check.



---
����: Flee
��Ŀ: http server can not work
����: Thu Jul 29 04:18:25 1999
is it because of the new MudOs ?


---
����: Ice
��Ŀ: about trickies skill's learning methods
����: Sun Aug  1 14:29:08 1999
1�� study bing shu by han di's call
2�� while use that trick will add some exp, (succeed add 5, fail add 1)
    then can ask officer in the same nation about this skill, if this
    officer has higher skill, can learn, about the real NPCs, i think we
    can use bfxy ask the same level of his trick skills level, hmm, about
    the tricks used in war by NPC, need design carefully..:P
3�� some kind of skills can learn from doing some jobs, like jbsj, hmm,
   i think we should change the fire_officer provide ���֮�� instead of
   jbhj..:D, and we can add some more jobs like repair the city walls, 
    trapping, blah blah....


---
����: Ice
��Ŀ: additional note of trickies skills
����: Sun Aug  1 19:48:52 1999
�ܷ�֮��

ָ�Ӳ��������ܵĵ���ͬʱ�������ɹ��򰴹�����ʽ���㣬ʧ����������ҡ�

����֮��

��������ר�ã�����̷�Χ�ڵ����в�������������ǵо����Ѿ����ɹ���
����ʽ��ʧ������ҡ�

����������ı���Ժ�wxxy��ϵ�������Ӧ�ú�bfxy��ϵ��

���⼼�ܣ�
��䡢��䡢ռ�������Ŷݼ�ӦΪ���⼼�ܣ������з�Ӧ����ָ����ʱ�ľ��С�
�й��޸���ǽ�����ݾ����ѷŲ��Ȳ�ȷ������ʲô��������:(



---
����: Tit
��Ŀ: it seems that all the stuffs here are all too expensive 
����: Mon Aug  2 02:45:52 1999
the gold here seems to worth nothing.
1 spear cost 1000 gold!!!!
too terrible.
maybe can we check the price of all the stuffs and low down the price.
1 spear even not cost 1000 coin bah in that time.
pls consider.


---
����: Ice
��Ŀ: >it seems that all the stuffs here are all too expensive 
����: Mon Aug  2 06:49:35 1999
the max price for a weapon or cloth is 300 gold, pls recheck,
i think the price is ok, and later obj will have it's life of
recycle, ppl need to replace his weapon or cloth while it's
too old. however, so far as i know, only 3 objs exceeds 1000 gold,
hxbma, dwhorse, wuzhuima, that's it.


---
����: Fire
��Ŀ: a bug of socket
����: Tue Aug  3 11:01:40 1999
[errors] ((none)) Error logged to /log/runtime
[errors] *could not release: Descriptor out of range
[errors] /secure/obj/socket#1 at line 219
��ϵͳ�����������ˡ�
��ϵͳ��������뿪��������
��ϵͳ��ѩ�����ˡ�
��ϵͳ��ѩ�뿪��������
��ϵͳ���̾������ˡ�
��ϵͳ���̾��뿪��������
��ϵͳ������ɽ�����ˡ�
��ϵͳ������ɽ�뿪��������
��ϵͳ��С�������ˡ�
��ϵͳ��С���뿪��������
��ϵͳ��Ѱ�ɶ����ˡ�
��ϵͳ��Ѱ���뿪��������
��ϵͳ������ɽ����������
dbxwhere last
Tue Aug  3 11:00:09 1999
*could not release: Descriptor out of range
Object: /secure/obj/socket#1 at line 219
#0: 'listen_callback' at /secure/obj/socket#1 at line 219
dbxframe last 0
------secure/obj/socket.c:219 - listen_callback(-19)
locals: -5
----------------------------------------------------------------
    s = new(SOCKET, SKT_STYLE_INT_ACQUIRE, read_func, close_func);
SKTLOG("listen_callback: new sock",s);
    err = socket_release(fd, s, "release_callback");
SKTLOG("listen_callback: err",err);
    if ( err < 0 )
=>      error("could not release: " + socket_error(err) + "\n");
}
//### need a way to protect this from random writes
varargs nomask void send(mixed message, string address)
{


---
����: Fire
��Ŀ: about the types of troop.
����: Tue Aug  3 11:04:54 1999
now i have created a daemon "/daemons/troop_type_d.c". I think we
will use this daemon to handle most the information of the different
troops.
this daemon has scaned most information in groups troops file. so
it keeps most the information similar to that defined in groups 
file.
for some function, which involve to the weather and zhengxin of
the troop, we will try to introduce extra fields to handle this
problem. so we can realize functions that  certain troop is more
suitable to certan zhangxi under certain weather. for this daemon
"info t" will give most common information and wiz can  use
@TROOP_TYPE_D->get_troop_d([id],[what]) to retreve all the information
stored in this daemon. and we will develop more function to help
wiz manage and edit this troop type datebase. 
for the war system, I will gradually move most functions which
related to the troop types attached to this daemon.
addoil


---
����: Tit
��Ŀ: about the price
����: Wed Aug  4 03:44:12 1999
ask kong rong merchant about goods
��Կ��ڹ�����һ���ֵ��
 [0m���ڹ����˴𵽣����������´����
 [0m����      ��Ǯ              ����     
������������������������������������������������������������������
��ӧǹ    һǧ����������    ��ʮ��
��ǹ      һ����ʮ��������ʮ������  ��ʮ��
Ƥ��      һ����ʮ������    һ����ʮ��
 [0m�� ? ȡ�ð���>  [0m


---
����: Tit
��Ŀ: follow 355
����: Wed Aug  4 03:45:53 1999
i mean the price of the goods at merchant.
it seems too expensive lah.
that is all.


---
����: Fire
��Ŀ: about cast jimou
����: Wed Aug  4 07:22:07 1999
I moved cast.c from /wiz/group/ to /cmds/player
disable /cmds/verbs/cast.c
and group will put two jimou under /sgdomain/jimou/
let's see how these two jimou (used by cast) going.
addoil :)


---
����: Ice
��Ŀ: about the width in new driver
����: Fri Jul 30 18:03:35 1999
seems now all player's width is 79, stefan pls do sth to change
it bah, supposed to be even number bah..:P


---
����: Ice
��Ŀ: about wizlist
����: Fri Jul 30 17:29:18 1999
seems now wizlist won't have the list resort by time any more,
unless system reboot.  hmm, i remember b4 it can resort bah,
longer time no log in will be put upper.........


---
����: Flee
��Ŀ: >> about wizlist.c
����: Sat Jul 31 02:33:00 1999
wizlist will not resort the list unless u 
update /cmds/player/wizlist.c.
because it use LOGIN_D to obtain that list
which is very cpu time consuming.


---
����: Flee
��Ŀ: >> about ��ʱ�ض�ɽҡ���췭�ظ��������������һ����
����: Sat Jul 31 02:34:46 1999
it is a crash called by the /secure/master.c.
so evrey player is forced to quit b4 crash.


---
����: Flee
��Ŀ: About my curren works
����: Sat Jul 31 02:36:45 1999
i am very busy for these weeks, hope i can be
a little bit free next week .. 


---
����: Ice
��Ŀ: about jobs using the new driver
����: Sat Jul 31 14:38:52 1999
seems now most jobs' setting need to be adjusted, the new driver
works more efficiently, thus the delay in the past jobs r useless.

for example, visitpeople, it used to be 1-2 secs for each option,
but now, no delay in between at all, i think we should re-consider
the time of delay.

ps: about the multipatrol and thief, i think we need to do sth more,
if 3-5 ppl patrol in a city, and if thief appears, system start to
be lag bcoz all ppl cmd catch thief, and the thief is sneaky, thus
player keep pressing cmd catch thief and make the system lag.
how about this, make cmd catch has busy time, and delay the thief's
runaway trigger, make it more balance


---
����: Yuyin
��Ŀ: bug ����
����: Sat Jul 31 20:14:16 1999
�Ҹ� login ��
����Ȼ �
*call_other() couldn't find object
Trace written to /log/runtime


---
����: Ice
��Ŀ: about job after position changed
����: Sat Jul 31 22:51:49 1999
when a player changed his position from one city to another,
his job record should be consider done related to that city,
otherwise player can choose their whipser, spy obj or so,
like the following:

//it's the snoop log of xixixi
%> %%��Գ������Ӵ𵽣���whisper��
%�������Ӷ�����������˵���ƹ���¬ֲ�Ĵ治����
%> %%ask dead about position%
%���������Ц����С�������ϴ�ְ����ϲ���ɺ�ѽ��
��ҥ�ԡ�ĳ�ˣ�С�ٱ���Ϊ����������
%���������������<job>����Ϣ��
%> %%��Բ�����𵽣���whisper��
%�����������������˵��ƽѩ���ĺ����Ĵ治����
%����������Ӵ�������<position>����Ϣ��
��ҥ�ԡ�ĳ�ˣ�С�ٱ���Ϊ�ٶɻ�����
%> %%��Գ������Ӵ𵽣���whisper��
%�������Ӷ�����������˵���ƹ��������Ĵ治����
> %ask dead about position%
��ҥ�ԡ�ĳ�ˣ�С�ٱ���Ϊ����������
blah blah

thus i suggest to change to if the job related to the former city,
the job record should be consider this quote is done.

and later we can make player cannot change his city easily unless
his king permits.


---
����: Ice
��Ŀ: ���ڼ�ı
����: Sat Jul 31 23:20:33 1999
1�� ��ƣ�jbhj

    ���������򡢵��Ρ�����Ӱ��ɹ��ʺ���ʧ������ϵͳ�����ṩ
    ����һЩ���ֺ�ľ�ģ�ս��ʱЯ����ʹ�û�ƣ����Я��������
    ľ�ĺͻ��֣����յ���ʧ��Ϊ���ء�����Ū��������������:P
    �����Ƿ���Խ�warmap���ɿ��Կ�����һ���������л�ģ�����
    ���ƻ����ӻ�������Ż�ķ����޷����룬������ӱ�����Χ��
    ���޷��ƶ�������ʹ�á����֮�ơ�������

2�� ˮ�ƣ�jbsj

    ���ε�Ӱ����Ϊ��Ҫ������о������ڻ�����ķ��䣬���Կ�բ
    ��ˮ���������ı��ʹ�ú������Ƚ��ر���Ϊ�������ˮ�ƻ�
    ˮ�񶼱Ƚ����棬С�ĵ����ĺá�:D��

3�� ���裬guwu

    �������ʿ����ʧ�����½��������ܼ��𹻸ߵ�ʱ�򣬻����Թ�
    ���ڽ����ӵ�ʿ����������KOEI�ļ���֮�ƣ�

4�� ���ң�hunluan

    ʹ�������ڷ���ĵо�����������ң��޷��ƶ����������Լ���   
���ϵͳ���ƺ��޷�̽�У�ʧ���򱾲���������ң�������ʱ
    ������һ�룬�����ڼ��ƶ����޷��ָ���

5�� ��ڧ��neihong

    ʹ�о����ڵ���֧��������busy���һ��๥��������������֧��
    �ӵ��ƶ����ܷ��๥������֮��ʾ��֧���Ӷ����ٱ��������ˣ�
    ʧ���򲿶�������ң�ʱ��ͬ����ʧ�ܡ�

6�� ��ʰ��shoushi

    ʹ�����ӻ����ڷ���Ĳ����������״̬��ʧ�������ʱ������
    1/3��

7�� �����maifu

    �о��޷���쵽���ӵ�λ�á�״���ȣ��������Ӳ����ƶ���ʹ��
    ��ı�������һ��ʱ�ޣ�ʱ��һ����ᱻ�о�̽����쵽�����
    �ڼ�����о�ͣ�������ڵķ��䣬����Խ��й����������״̬
    ����һ��֮��ָ�����״̬������һ�εĹ������ӱ�������ʹ��
    �����ĵо�������ң�ʧ���򱾲���������ҡ�

8�� �����qibing

    �о��޷���쵽���ӵ�λ�á�״���ȣ������ӿ����ƶ�����һ��
    ʱ�ޣ�ʱ�޹���ָ�����״̬�������ǲ��ӵ��������ܳ���ĳһ
    �޶ȣ��� 500�����״̬�¿���ʹ�ü�ı�͹�����һ��ʹ�����
    �ָ�����״̬�����о����֣�ʧ����������ҡ�

9�� ��ʯ��luoshi

    ����Я��Բʯ�����ұ����Ӵ���ɽ�ĵ��Σ����Զ����ڷ���ĵ�
    ��ʵʩ��ʯ֮�ƣ��ɹ���о���ʧһ�������Ĳ����Լ��϶�ʱ��
    �Ļ��ң�ʧ�����˷�Բʯ������϶�ʱ��Ļ��ҡ�

10�����jiaoma

    �����ڻ��ڽ��ĵо�����ʹ�ý���֮�ƻή�͵о�ʿ����ʧ����
    �о�ʿ������������

11�����miehuo

    ���𱾲�����������Ļ��ƻ����ڷ���Ļ��ƣ�ʧ������Ʊ���
    �����ӣ�����������һ���ʧ���ٵ�һ��������

12���ѱ���huangbao

    ���ط�ר�ã������ڵĵо����ӻѱ����飬ʹ�ò�������Ϊ����
    �����յ��������ֻʳ��˻�ʿ���������ȫ�ɹ����ˣ�����ȫ
    ��ʿ������ʧ���򲿶�������ݻ��ҡ�
//thus i think we need to redo the task structure..:P

13���ٴ����fakeorder

    ֻ�ܶԷ�ָ�ӹ����ڲ���ʹ�ã��ٴ�ָ�ӹ���������е�ָ��
    ϵͳ�����о���ĳ������ĳ�������������һ��ʱ�ޣ������
    ��ҿ��ƵĲ��ӣ�����ʱɥʧ����Ȩ��ʧ���򲿶�������ҡ�

14�����ţ�chenzhuo

    ���ԶԱ��ٴ�����ı����ӻ����ڵĲ���ʹ�ã��ɹ���ָ�����
    Ȩ��ʧ����Ŀ�겿�ӵ�ʿ���µ���

15����䣬tianbian

    �������������ı仯���ɹ�����䣬ʧ��������������������
    ��ȫ��Ϊ 0���޷��Բ��ӷ������������ӻ��������������
    �����ۣ���

16����䣬fengbian

    �ı���򣬳ɹ������ı䣬ʧ����ͬ��䡣

������һЩ�����ļ�����ܷ�������Χ����ʿ��ͬʱ�����ڵĵ���
�����������䡢�޸���ǽ���ھ��ݾ����ѷŲ��ȿ��Թ�������⼼
�ܣ���������һ�����ӡ����й�����죨warinfo���ĸĶ�Ҳ������
������


---
����: Ice
��Ŀ: ���ڷ��ط�����
����: Sun Aug  1 00:47:40 1999
1�� ���ط���Ҫ�˵���ͼ�ı�Ե�ش���ĳһ�ض�������ܳ��ˣ�
2�� ���ط����˺������ʧһ������ϣ�
3�� ʿ������һ�룬���ڳ���Ŀ�ĵص�ʿ����ѵ���ȼ�Ȩƽ����
4�� ���ط����˵Ĺ�Ա��Ϊ����Ŀ�ĵص���ְ��
5�� ��ʧ������


---
����: Fire
��Ŀ: >���ڷ��ط�����
����: Sun Aug  1 01:47:17 1999
On Sun Aug  1 00:47:40 1999 Ice wrote post #717:
> 1�� ���ط���Ҫ�˵���ͼ�ı�Ե�ش���ĳһ�ض�������ܳ��ˣ�
> 2�� ���ط����˺������ʧһ������ϣ�
> 3�� ʿ������һ�룬���ڳ���Ŀ�ĵص�ʿ����ѵ���ȼ�Ȩƽ����
> 4�� ���ط����˵Ĺ�Ա��Ϊ����Ŀ�ĵص���ְ��
> 5�� ��ʧ������

ice's idea is right, will try to put it
in some where


---
����: Ice
��Ŀ: about jbsj&jbhj
����: Sun Aug  1 08:51:11 1999
jbsj: can learn from shuijing till level 20, can learn from bing shu
      from taijian till 30
jbhj: i think we can set fire_officer in each level 5 city thus won't
      make changan the only city can learn this, and limit can learn
      from officer till level 20, from taijian level 30


---
����: Ice
��Ŀ: >about the troop number
����: Tue Aug 10 04:40:18 1999
well, it's reasonable to keep a large amount of troops in the 
nation's border, and I think most guan are main warfields
if we have enough players to play later on. let's consider it
from the complete viewpoint(after the troops and stuffs transfer
completed), at first, i think guan's usage is mainly for defence,
but not for recruiting soldiers in the guan area, if the nation
need to defence at a guan or prepare attacking from, troops may
be transferred there, except only recruiting from the area, so
if a nation want to concentrate on some important cities, they should
transfer soldiers there, so i still think the limitation of recruiting
is reasonable for any cities.  anyway, i think we can make the following
adjustments:

1. implement the recruit limitation after transfer system completed;
2. extend the period of the people rebel if too many troops in the area,
   for example, extend from my planned 3 months to half year.
// i think half year is enough for a nation to make up its mind to
suppress the people or transfer them to a nearby larger area to stand by,
and i think if the assist_war/defence completed, those small areas dun
need to keep a very large amount all the time, however, they can keep
transferring the troops b4 that area's people rebel.

let me take a papaya example, zhuge liang sent ma su to defence jieting
while he heard that sima yi is on his way of attacking, so i think those 
small areas should keep a large amount of troops when it's necessary, but
not all the time.


---
����: Ice
��Ŀ: about black namelist
����: Tue Aug 10 02:24:56 1999
(1 )0           ������ɳ(lionking)    ����Ч

can block settled char? even not officer?

* doubt


---
����: Group
��Ŀ: about the troop number
����: Tue Aug 10 01:59:31 1999
i agree that for cities the the troop number should be limited for
recruiting. but i think that the number limited for a city is not
depended on the city population. this is because for some low level
cities, country need them store a number of troops to defend on
enemies since most of these cities are on the boundage between
countries. this can be done by transfer the soldiers and troops
between cities. the punish for store a huge number troops should be
rduced.


---
����: Ice
��Ŀ: about bandit system
����: Mon Aug  9 20:17:17 1999
���⻹��Ҫһ���������˵�ʱ�����ÿ�꿪ʼ��ʱ����趨��
��ʹ�����������£�

1�� ����ͷΪ���֮���ʱ�򣬺����ǻ������ĳ�����ң�ֱ��
    ����ȫ������µ�һ�꿪ʼ��ƽ����ʱ��ֻ��һ���������ң�
2�� �������˵ĳ��ֲ�����̫Ƶ����һ������ÿ���������20��
    ���У�����ÿ���¹������ڵ�1��2�����У�ֱ��������
3�� ÿ����һ���������˴�ѡ�������֮���ʱ��ѡȡ2��3��
    �ݳ��ֺ��ˡ�


һ��һ�����ˣ�

Ŀ�ģ���ռ˧�ʣ��Ӷ�ĳ���С�
�ص㣺û����ȷ���쵼���������١�
������Ϊ����������פ�������֮�͵� 1/4����಻���� 5000��
     ��������ǰ��ÿ������ͷ�Ӷ�ֻ��500���ƺ���̫����

�������ˣ�

Ŀ�ģ���ĳһ���������ܣ���ɱ���ӣ��޶�����
�ص㣺����ȷ���쵼�ߣ������϶࣬����֯��
      �����Žǵȣ�
������5000��20000��������ʱΪĳһ������������ÿ�γ�����
      ����ı䣬ֻ��ԽսԽ�٣�ֱ������ȫ����

I may start to collect the names and status of strong bandits
if all of us think it can be implemented.



---
����: Ice
��Ŀ: about disaster system
����: Mon Aug  9 20:15:59 1999
��ÿһ�꿪ʼ��ʱ������һ������ʱ������������Ӱ����ǡ�������
��ôֻ�ӡ��������г�ȡ����֮��Ȼ��ʹ��ʱ�����Ƶ�ʹ�ú��������£�

1�� ����ÿ���¼����Ƿ����ֻ���ֻҪ���ձ���ȵ�ʱ���Ϳ����ˣ�
2�� ����ͬһ�����л����ͬʱ���ܶೡ�ֻ���
3�� ������ͷ��ʱ��Ϊ��������ͷ��ʱ��Ϊ������Ӱ�����ͷ�򲻹���ʧ��
    �ֻ���Ӱ�첻��̫����Ƶ����
4�� �Ժ��ռ����������Ԥ���ֻ��ں�ʱ�εط�����ֻҪ��ʱ����ϳ�ȡ
    �Ϳ����ˣ�
5�� ���˷��պ�Ǹ�տ�����ÿ�궼����֮�⣬�����Ĳ������Ƶ����
6�� ÿ�꿪ʼ��ʱ��ֻҪ����Ӧ�����ֻ򽵸��г�ȡһ�����ַ�������
    �����ˮ�ͺ���ͬʱ������


���������˻����ǲ������ڵķ��õĶ�������ķ����Ϻã���ȽϿ�Ͳ�
��ͬʱflood̫�ࡣ

ʱ��->��ĳһ���ڿ��ܷ�����
Ԥ��->����Ԥ����ʩ���������ˮ�ȣ��Ż�ȡ�����
����->�п��ܷ���������

һ������

1�� ����

Ӱ�죺��ǽ�������½� 50%������ָ���½� 10%���˿ڣ�פ����ʧ 10%��
      ���лƽ���ʳ��������ʧ 10%�������½� 30��
      ���������й���ʱ������ȫ���ݻ٣�
ʱ�䣺���⡣
Ԥ�����ޡ�
������ȫ����
��������ҥ�ԡ�ĳ�ˣ�ĳ�ݷ���ǿ�ҵ������ڸ������⵽������١�
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 1 ����
      Ϊ��������ġ�

2�� ��ˮ
Ӱ�죺��ˮ���½� 30%������ָ���½� ((200 - ��ˮ��) / 2)%��
      ���лƽ���ʳ��������ʧ ((200 - ��ˮ��) / 2)%��
      �˿ڡ�פ����ʧ ((200 - ��ˮ��) / 4)%��������ʧ 20��
      ���������й���ʱ���������ݻٻ�һ����
ʱ�䣺�����ġ�
Ԥ������ˮ�ȸߣ���ʧ��С��
�������С������ϲ���
��������ҥ�ԡ�ĳ�ˣ�ĳ�ر���ˮ��û��������ʧ���ء�
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 5 ������
      Ϊ������ˮ�ġ�

3�� ��
Ӱ�죺ũҵָ���½� 10%����ʳ��ʧ 20%���˿���ʧ 5%��������ʧ 20��
      ���������й���ʱ����ũҵ�йصĹ������ݻٻ�һ����
ʱ�䣺�ġ��
Ԥ�����ޡ�
������ȫ����
��������ҥ�ԡ�ĳ�ˣ�ĳ�ؾú����꣬���ذ��սп����졣
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 5 ������
      Ϊ������ˮ�ġ�

4�� �ȳ�
Ӱ�죺ũҵָ���½� 10%����ʳ��ʧ 20%��������ʧ 10��
ʱ�䣺�ġ��
Ԥ�����ޡ�
������ȫ����
��������ҥ�ԡ�ĳ�ˣ�ĳ�غ�Ȼ���ִ����ȳ棬����ũҵ����������ʧ��
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 5 ������
      Ϊ�������ֵġ�

5�� ʧ��
Ӱ�죺������½� 30%������ָ���½� (200 - �����) / 2)%��
      ���лƽ���ʳ��������ʧ(200 - �����) / 2)%��
      �˿ڡ�פ����ʧ (200 - �����) / 4)%��
      ���������й���ʱ���������ݻٻ�һ����
ʱ�䣺����
Ԥ��������ȸߣ���ʧ��С��
������ȫ����
��������ҥ�ԡ�ĳ�ˣ�ĳ��������㣬���ط������ػ��֣���ʧ���ء�
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 5 ������
      Ϊ����ʧ��ġ�

6�� Ǹ��
Ӱ�죺ũҵָ���½� 20%����ʳ�ջ�ֻ�� 50%��������ʧ 30��
ʱ�䣺�
Ԥ�����ޡ�
������ȫ����
���������ջ��ջ�ļ��ڵ��ˡ�
      ��ҥ�ԡ�ĳ�ˣ�ĳ����ʳǸ�գ����ذ���Թ���ص���
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 10 ������
      ΪǸ�յġ�

7�� 쫷�
Ӱ�죺����ָ���½� 20%���˿ڡ�פ����ʧ 5%��������ʧ 30��
      ���������й���ʱ���������ݻٻ�һ����
ʱ�䣺�ġ�
Ԥ�����ޡ�
������ȫ����
��������ҥ�ԡ�ĳ�ˣ�ĳ����쫷���Ϯ�������⵽�����ƻ������ն������ˡ�
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 1 ����
      Ϊ����쫷�ġ�

8�� ����
Ӱ�죺����ָ���½� 10%���˿ڡ�פ����ʧ 20%��������ʧ 50��
ʱ�䣺���⡣
Ԥ�����ޡ�
������ȫ����
��������ҥ�ԡ�ĳ�ˣ�ĳ�ݱ������ߣ�һʱ���Ļ̻̣����շ׷�Ǩ�롣
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 1 ����
      Ϊ�������ߵġ�


�����˻�

1�� ����
Ӱ�죺����ָ���½� 10%���˿���ʧ 10%��פ����ʧ 10%��������ʧ 30��
ʱ�䣺ÿ������Ѯ����ʱ��
Ԥ������ѹ����cmd suppress in localmeeting��
      �����տ�ʼ���ۺ󣬿����ڵ��ػ�����������ѹ���գ���ѹ�󰲶���ʧ 30��
      �˿���ʧ random(5%)��פ����ʧ random (5%)��
      �ָ�����һ����ʱ��״̬������ó��м������������ľ��ӣ�������Ȼ��
      ������
      ��ҥ�ԡ�ĳ�ˣ������ʾ���ѹĳ�ذ��գ�ƽϢ�˵��ص����ԡ�
���������⡣
��������ĳ��������פ������������������ӵ�е�פ������ʱ��
      ��һ���£�
      ��ҥ�ԡ�ĳ�ˣ�ĳ�ذ��ղ������ؿ��������۷׷ף�һʱ���Ĵ��ҡ�//������
      �ڶ����£�
      ��ҥ�ԡ���ĳ�ذ��ղ������ؿ��������۷׷ף�һʱ���Ĵ��ҡ�//������
      �������£�
      ��ҥ�ԡ���ĳ�ذ��շ�Ȼ�ҸͶ��𣬷����˱��ҡ�

2�� �˻�
Ӱ�죺�������ռ��
      ����ָ���½� 5%���˿���ʧ 5%�����еĻƽ���ʳ��������ʧ 10%��
      ������ʧ 20��ʿ����ʧ 20��
      ����������й������򹤳����ݻٻ򽵼���
      ���սʤ��
      �������� 20��ʿ������ 20��
ʱ�䣺���⡣
Ԥ�����ޡ�
���������⡣
���������post about bandit��


��������

1�� ����
Ӱ�죺ũҵָ������ 10%����ʳ����Ϊ 200%���������� 20��
ʱ�䣺�
���������⡣
���������ջ��ջ�ļ��ڵ��ˡ�
      ��ҥ�ԡ�ĳ�ˣ�ĳ��ϲ����գ����ذ��ջ���ϲ�ء�
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 10 ������
      Ϊ���յġ�

2�� ��ѩ
Ӱ�죺ũҵָ������ 10%���������� 10��
ʱ�䣺����
�����������С�����
�����������ĵ�һ���µ���Ѯ��
     ��ҥ�ԡ�ĳ�ˣ�ĳ�ؽ�����ѩ�����ذ��ն��ֳ��졣
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 5 ������
      Ϊ����ѩ�ġ����ڱ����С��������ڣ���������򲻷�������

3�� ����
Ӱ�죺����ָ������ 10%���������� 30���˿����� 10%��
ʱ�䣺���⡣
���������⡣
��������ҥ�ԡ�ĳ�ˣ�ĳ�ذ��շ����ĳ��׷���Ϊ����
      ���������ɵ�֧��Ӱ���ǡ�������������Ӱ��ĵ����г�ȡ 2 ������
      Ϊ��������ġ�
      ĳ�ǰ����ͭ����ͭȸ��blah blah

really cannot find out more good deeds the god can do..:(



---
����: Ice
��Ŀ: about fate system
����: Mon Aug  9 20:15:21 1999
I think the implementation of fate system is complex, however, 
I think this system has a great potential for our future development,
it'll be easier to handle many events for us if we use it.

that's all of my promotion of the fate system, pls consider it
seriously bah..:P


---
����: Ice
��Ŀ: plan of implementation of fate system
����: Mon Aug  9 20:11:58 1999
һ����ɵ�֧��������
                                                            
��ɣ���10|"��","��","��","��","��","��","��","��","��","��","��
��֧����12|"��","��","��","î","��","��","��","δ","��","��","��","����

����������ϳ���ʮ����λ ��ͨ��"��ʮ����"��, 
ѭ��ʹ��. ����˳������:

����   �ҳ�   ����   ��î   �쳽   ����   ����   ��δ   ����   ����
����   �Һ�   ����   ����   ����   ��î   ����   ����   ����   ��δ    
����   ����   ����   ����   ����   ����   ����   ��î   �ɳ�   ����    
����   ��δ   ����   ����   ����   ����   ����   ����   ����   ��î    
�׳�   ����   ����   ��δ   ����   ����   ����   ����   ����   ���   
����   ��î   ����   ����   ����   ��δ   ����   ����   ����   �ﺥ

��Ԫ184�ꣽ������

�ͣգ�ʱ�䣺����־һ�ٰ�ʮ����һ����Ѯ�������ꡣ

��������֮�꣺

���ѭ�������½�����Ȼ֮�����������ʼ���գ������������������в��������
�������ѧ�У���ʮ��Ϊһ���ӣ�һ�����У���Щ����������ʢ֮�꣬��΢�Ƕ�
�ع������������Ϊ�ף������죬�����ɡ���֧Ϊ���������ݡ�

�����У�

���� ���� ���� ���� ���� ���� ���� ���� ���� ����

���ã�

1�� ����Щ���֮���ж�������ң����Ի�����ڳ��й�Ա����ְ�ı�����
2�� �����֮�꿪ʼʱ��һ��һ�գ���ӵ�������С�����˿ڡ�����Ա�ȵĹ�
    ���Ի�������������Ľ���������new rep = old rep * 1.5����
3�� ֻ�������֮����ܳƵۡ����׳ƻƵ����� * fool��
4�� �����ǻ�ٽ����ͷ�û����ң����post about bandit��
5�� �����������Լӣ�

������������

����Ե�����һ����Ӱ��������Ȼ���ﶼ�����У�������Ȼ����ÿһ����������
������ͬ�ĵ�����Ҳ����Щ�����ر��١�

���֮�������Ա�
------------------
ľ �� �ף��ң�������
�� �� ���������Ϸ���
�� �� �죬�������롣
�� �� ��������������
ˮ �� �ɣ��������

������λ�ֲ���

���������ݣ����ݣ����ݡ�
�Ϸ������ݣ�۫�ݣ����ݣ��Ͼ��ݡ�
���룺˾����ԥ�ݣ������ݡ�
���������ݣ����ݣ����ݣ�Ӻ�ݡ�
���������ݣ����ݣ����ݡ�

���ã�

1�� ��ͬһ����﹥�ݲ�ͬ��λ�ĳ��п��Ի�ò�ͬ�Ľ������ٸ����ӣ������Ϊ
    �ס���ʱ�������ڶ������ڵĳ��У�����ս������ҿ��Ի�üӱ��ľ��齱����
2�� ������ϵͳ���ƺ󣬿��������Ϊ�̶�ͣ�������ݣ������Ϊ�ס���ʱ���̶�
    ���ڶ������������ͣ������ԭ�����̶��������������ҵֵ�ߣ���̫�����
    һ���������������̶ӣ������һ������ĳ��о�Խ��������̶�����ѡ��
    �ƺ�Ϊ�ã�
3�� �����������Լӣ�


�ġ�����븣����

����Ե�����һ����Ӱ�����������ڽ��ֽ����ϡ����˺����ѵķ�����Ҳ����ݵ�
�ı�����׼�����ĳЩ�ش�������˵�����ߵķ����������е���������໯����
�ɵġ�Ӱ�����ߵ������������ݵĵ�֧����������ݵ����Ӱ�����һ��������
�����˵ķ����պ����෴�ġ����Ѻ����˵ķ����պ����෴�ġ�

������ڸ��������֣�ϵͳ��post��/wiz/ice/txt/fate_table.txt




---
����: Ice
��Ŀ: about the max amount of troops each city can recruit
����: Mon Aug  9 18:18:45 1999
I think each city should have a limitation about how many troops
can be recruited in that city, i think maybe we can use fomula like this:

max no. of troops can be recruited
= (current population / 10 * (safety / 200))

in this case, a 1M city with full safety can recruit 100k troops, 
which is supposed to be enough to defence any proper attack, and if
a city has more troops exceed this limitation for one month, ppl may
rebel, pls see my upcoming disaster post for detail about this point.


---
����: Fire
��Ŀ: today's work:
����: Mon Aug  9 10:21:14 1999
1 reduce the time for feedgoat to make it easier
2 fix several bugs in war
3 add the function for boy to destroy empty rooms


---
����: Ice
��Ŀ: changed a few names in ranknation
����: Sun Aug  8 14:20:25 1999
��ʦ -> �ܾ�ʦ
���� -> ��ʷ

to avoid confusion with ranklocal


---
����: Fire
��Ŀ: about the super lag in war
����: Sat Aug  7 08:31:56 1999
now the war seem super lag.
i have checked and find that there are two reason
1, the defence part use pursue the attack's leader
  if there are many defence troop the speed will be very slow
2 our system's memory seem run out, so have to use
  a lot virtual memory, this seem a reason
  when i reboot the system and try war
  even still lag but seem much faster than before


---
����: Ice
��Ŀ: about book in palace
����: Sat Aug  7 21:52:57 1999
hmm, sounds that if a ppl's skills is 31, still cannot learn
book volume 2 now, even enough literate....:(

when fire has time, pls check it bah.:D

addoil.:P


---
����: Ice
��Ŀ: about ordered objs
����: Sun Aug  8 01:35:23 1999
I think now it's the time to make cmd call's option 5 available.
bcoz nowadays money has weight, and player is trying to order better
obj, thus we can make the player can give his ordered obj to qb, means
only he dest that obj, nothing will be added in qb's status, since qb
no morale parameter.:P


---
����: Fire
��Ŀ: >about book in palace
����: Sun Aug  8 03:10:15 1999
On Sat Aug  7 21:52:57 1999 Ice wrote post #731:
> hmm, sounds that if a ppl's skills is 31, still cannot learn
> book volume 2 now, even enough literate....:(
> 
> when fire has time, pls check it bah.:D
> 
> addoil.:P

if over 30, need get some experence


---
����: Fire
��Ŀ: reduce the obj in system
����: Sun Aug  8 05:26:03 1999
In order to reduce the obj numbers in system, following
adjustments have been added.
1. when npc auto move, will check if the target room is
   already in system, if not will not move to that room
2. npc char will just add one cloth
3. add one timer m_char in m_charnpc to show how long this
   npc has lived, if too long will auto_disappear.
4. cpu command updated so wiz can check obj numbers more easily
5. further work will try to clean_up unused rooms


---
����: Fire
��Ŀ: a strange bug
����: Sun Aug  8 08:11:25 1999
some players such as flyee and xmzy can't
see the chat of them selves, this
happened before to some other players, is
it a very strange bug ?


---
����: Fire
��Ŀ: ���ڷ���ļ���ϵͳ���á�
����: Tue Aug 10 09:21:50 1999
1. ��ʾ�������ķ��䣬���ص��ڴ�ķ��䣬�����иõ������ص��ڴ�
   ����Ʒ(npc,player,obj)ͳ�ƣ�
@"/a/area_stat"->dis_all()
2. ��ʾ�����ڴ��е�ս�����䣺
@objects((:$1->is_gridroom():))
3. ���һ�����ڵ�����ս�����䡣
@MAP_D->destruct_area("chenliu")
  ע�⣺��û��BUG������£�һ������ս������Ӧ�ڸõ���
        ս����ѵ���������Զ�������������û��BUG����Ҫ
        �ֶ�ʹ�ô�ָ�
4. �Ľ���war���Զ����ս���Ĺ��ܣ�ͬʱ��ǿ��boy�������÷���
   �Ĺ��ܡ�ϵͳ�������Ͳ��١�:)


---
����: Ice
��Ŀ: made little change about ev_king/king.c
����: Tue Aug 10 16:33:40 1999
1. changed to if arrive within 2 mins, will get extra rewards;
2. changed to if money > 3000 will be robbed by han di;
3. changed if rep > 100k, will be rewarded little bit more;
4. changed if localcontri > 1000, will be rewarded skills.

* escape


---
����: Ice
��Ŀ: about lack of gold on hand
����: Tue Aug 10 18:13:03 1999
since now player cannot hold 3k gold on hand, thus player
king cannot order hxbma without wiz's help..:(
how about use the method of cmd donate:

while a player asks maker about order, he will be check if he
has enough gold on hand, if not, the make will say the following:

���ײ���ֵؿ�����һ�ۣ�����������Ǯ����û������
���ײ�������üͷ������˵������Ȼ������ô���У��ҵ��и��취������
���ײ����������ҿ��Խ��˵���������ȡǮ������Ҫ�Ӱٷ�֮ʮ�������ѣ������������
��
�ش𣺣�yes/no��
//yes
y
���ײ���������ϻ�������ǧ�������ƽ�
���ײ�������ͷ������������Ѿ����£�����Ѫ������ɺ󼴿�֪ͨ������ȡ��
//no
���ײ����ε������ʼ磺��Ȼ�����������ǻ��Ǹ��������ɡ�

gold will be deducted from either bank account or salary account.:D


---
����: Ice
��Ŀ: something about the char
����: Tue Aug 10 23:10:32 1999
1. today ztian ind in changsha, ���� has national rank, so he
   should be sent to be ��ְ in the remaining cities, but he wasn't.

2. xixixi war runan, runan lost, but all former officers in
   runan keep their position, their ranklocal, area, nation blah blah
   all not changed, thus those officers still occupying the positions,
   and even 2 leader.

is that bcoz fire changed sth? fire pls check.:P


---
����: Yuyin
��Ŀ: help
����: Sun Aug 15 08:02:19 1999
row and group
i use cuteftp
i can connect our MUD
but i can't see the file in our MUD
�ǲ��� setting ���� ?
�ǵĻ�Ӧ����ô��
�ҿ���һЩ��ҳҲ��֪����ʲôԭ��
�� mail ����
thanks


---
����: Fire
��Ŀ: about clean_up
����: Sat Aug 14 06:59:17 1999
in order to save memory, the boy call room's clean up
regularly, if you want an obj don't be destroied
by the clean_up, in the obj add one function as below

int query_clean_up() {
    return 1;
}

then this obj will not be clean up even in a box or in sth


so a very useful function, isn't it ?
:)


---
����: Ice
��Ŀ: about private buy
����: Fri Aug 13 21:00:32 1999
bcoz the salary can only be withdrawn but cannot be put back
any more, and actually the merchant should transfer gold from
player's bank account..:P so i think it'll be better change the
private buy consume bank account only, thus player can use
a more modern way for shopping, and they may deposit their money
in the bank, make the bank meaningful.

btw, i think we can just change the ask maker about order to
consume bank account only as well, thus player don't need to hold
that large amount of money on hand and we can enlarge the limit
of bank account from 1000 to 3000, no need to change much then.:P

actually i cannot find the bank is useful now..:P


---
����: Ice
��Ŀ: to stefan:a very strange bug
����: Fri Aug 13 14:53:43 1999
i think maybe sth wrong, but dunno what's wrong, let me post
the log here for reference:

> �����ġ�����(kings)���ҿ�������˵�Ļ�
snoop kings;�ɹ���
' say sth in chat;��˵����say sth in chat.;%����˵����say sth in chat.
> %chat �ҿ�������˵�Ļ�%
�����ġ�����(kings)���ҿ�������˵�Ļ�
%�����ġ�����(kings)���ҿ�������˵�Ļ�
' i saw u can yah;��˵����i saw u can yah.;%����˵����i saw u can yah.
%chat I can't%
�����ġ�����(kings)��I can't
%�����ġ�����(kings)��I can't

I think snoop is whatever he can see, i can see, but he insist he cannot,
same bug occured time to time, but sometimes after relog, it disappeared,
and he can see all else channels, except gossip, i think there was a post
by fire talking about the same problem, and seems not appeared while using
the old driver, stefan pls take some time to check bah..:P


---
����: Ice
��Ŀ: about absense of localmeeting
����: Fri Aug 13 01:40:15 1999
I tried to be absent for localmeeting, and i think the former
setting is 20 secs not in meeting room will be counted absent,
but the first time i stay outside, it costs 40 secs to say i am
absense, and the 2nd time, i give out a suggest of localbuy, then
it last 3 mins without announcing any absent msg.

who has time check check it bah.:P

* escape


---
����: Fire
��Ŀ: about the horse
����: Thu Aug 12 08:20:32 1999
now the formula is
time = 5 + (speed * distance) * 0.2
the speed for mache is 15


---
����: Fire
��Ŀ: about the horse system
����: Thu Aug 12 07:10:06 1999
����    �ȼ� ��Ǯ  ������ ���Ľ�/�� �ٶ� ����
��                                 15   --
����      0   1      0     0/20      20   4
������    1   10    +1     0/10      12   5
С����    1   15    +1     0/12      11   4
������    1   20    +1     0/10      11   4
������    1   30    +1     0/15      11   5
�Ʊ���    2   80    +2     1/20      10   6
������    2   100   +2     1/35      10   7
������    2   120   +2     1/40       9   7
������    3   200   +3     2/40       8   8
��֬��    3   250   +3     2/45       8   8
������    3   300   +3     2/50       7   8
������    4   400   +4     3/50       7   9
������    4   450   +4     3/55       7   9
��Ѫ����  5   1000  +5     4/55       6  10
��¬      7   -     +7     5/60       6  12
��Ӱ      8   -     +8     5/70       5  14
צ�Ʒɵ�  9   -     +9     5/75       5  15
������   10   -     +10    10/80      4  17
��ʽ��t=ʱ�䣬d=����, s=�ٶȡ�k����ϵ����Ŀǰȡ0.5
t=10+(d*s)*k


---
����: Fire
��Ŀ: >estimated horse list
����: Thu Aug 12 06:53:50 1999
about the horse
ice's data is right, but for the mache
still need a little consideration, it should be
slower than 12, because it can reach the target directly
so i suggest it is 15.
because for long distance journey, the time become more
and the journey has been broken several times
so need add some adventures in the way.
for example, when pass a froest and the player
hear some strange sound, then system ask if the player
want go and find out what is there, if input no, continue 
travel, if yes, enter the froest and may find something
interesting, of cause need overcome some difficult
and get special reward
for the speed, i think need adjust a little
the speed from level 1 to level 5 go
from 12 to 6, and for level 5 to level 9 go from
5 to 4, this may be mroe reasonable, or i will post
a new list :)


---
����: Ice
��Ŀ: estimated horse list
����: Thu Aug 12 05:07:23 1999
����    �ȼ� ��Ǯ  ������ ���Ľ�/�� �ٶ� ����
������    1   10    +1     0/10      12   5
С����    1   15    +1     0/12      11   4
������    1   20    +1     0/10      11   4
������    1   30    +1     0/15      11   5
�Ʊ���    2   80    +2     1/30      11   6
������    2   100   +2     1/35      11   7
������    2   120   +2     1/40      10   7
������    3   200   +3     2/50      10   8
��֬��    3   250   +3     2/45      10   8
������    3   300   +3     2/60      9    8
������    4   400   +4     3/80      8    9
������    4   450   +4     3/75      8    9
��Ѫ����  5   1000  +5     4/100     7    10
��¬      7   -     +7     5/150     6    12
��Ӱ      8   -     +8     5/180     5    14
צ�Ʒɵ�  9   -     +9     5/200     4    15
������   10   -     +10    10/400    3    17


mache's speed is 12 bah, slow enough, and maybe double the
transport fee, thus make buying horse more worthy.

*grin


---
����: Yuyin
��Ŀ: fire
����: Wed Aug 11 08:12:44 1999
�����飬�뾡��� marry system ����
addoil fire


---
����: Yuyin
��Ŀ: bug ����
����: Wed Aug 11 07:45:58 1999
�� clone /wiz/yuyin/obj/bed.c
 ------- /wiz/yuyin/obj/bed.c:26
 Warning: Function inherited from 'std/modules/m_mountable.c' does not match
current function in return type ( void vs int )
int mount_it_already()


---
����: Ice
��Ŀ: adjustment of localtax
����: Sun Aug 15 16:47:35 1999
1. if((p_safe<30)||((p_safe-(p_tax-p_oldtax)*2)<=30))
2. if(p_tax-p_oldtax>20||p_oldtax-p_tax>20)

cannot change tax.

hope it can restrict player use tax and sendfood only to raise
the safety a little bit.  however, i think we may add a time limit,
like an area cannot change tax more than once in the same day,
it's a kind of ����Ϧ�� bah.:P, or we can set if they insist to change
more than once in the same day, the increase of tax will be - 4* safety,
the decrease of tax will be + 0.5* safety.

* grin


---
����: Row
��Ŀ: >to stefan:a very strange bug
����: Sun Aug 15 21:55:07 1999
On Fri Aug 13 14:53:43 1999 Ice wrote post #758:
> i think maybe sth wrong, but dunno what's wrong, let me post
> the log here for reference:
> 
> > �����ġ�����(kings)���ҿ�������˵�Ļ�
> snoop kings;�ɹ���
> ' say sth in chat;��˵����say sth in chat.;%����˵����say sth in chat.
> > %chat �ҿ�������˵�Ļ�%
> �����ġ�����(kings)���ҿ�������˵�Ļ�
> %�����ġ�����(kings)���ҿ�������˵�Ļ�
> ' i saw u can yah;��˵����i saw u can yah.;%����˵����i saw u can yah.
> %chat I can't%
> �����ġ�����(kings)��I can't
> %�����ġ�����(kings)��I can't
> 
> I think snoop is whatever he can see, i can see, but he insist he cannot,
> same bug occured time to time, but sometimes after relog, it disappeared,
> and he can see all else channels, except gossip, i think there was a post
> by fire talking about the same problem, and seems not appeared while using
> the old driver, stefan pls take some time to check bah..:P

maybe its the problem of color setting...


---
����: Fire
��Ŀ: about the bug in job quote
����: Tue Aug 17 02:54:56 1999
that is a problem, but he can't get personal
reward for finish so many jobs
so i will fix this when we got enough types
of jobs for diffent level of jobs
thank ice
we all miss you, come back when possible :)
and we will keep your wiz position as you have
contribute so much to our mud.


---
����: Ice
��Ŀ: about job record
����: Tue Aug 17 01:51:51 1999
oops, just wanna post a message forget to tell b4 i leave, then
it crashed..:(
 
��������ʱ���Сʱ�����ӡ�
�㱻�����������ͻ���ͻص���ʦ������
> post
�������������⣬ . ��ʾ������
�������⣺��ʱ�ض�ɽҡ���췭�ظ��������������һ����
���뿪��������

kick, this time not me leh bah..:(

well, anyway, got say it here.

about the job record, I snooped xixixi when he keep transferring
himself very often, and i found there is a bug in the job record,
when a player ask for a job in A area, and then he finish that job
and doesn't report to the leader, he transfer to B area, and ask 
for the same job, the former job is not counted in the job record.
with this way, i found xixixi's id did around 40 visitpeople within
30 mins, totally ignored our job quote..:P

so I think when ask for job in an area, it should be recorded, even
the player changes his area, it should be counted.

well, it might be my last report anyway, won't have much time any
more..:P

nocry, nosigh, we have a tough and innovative wiz team, I expect
sanguo will be perfect and completed in no time.:)

thanks for everyone's support..:D

addoil all!


ps. I will try to be back whenever i can.:)


---
����: Fire
��Ŀ: about the message of fight
����: Thu Aug 19 05:34:24 1999
yuyin has written three fight message for ji, sword and unarmed
it seems that the unarmed has bug in it, so 
please fix the bug first
I have installed the ji.c and sword.c
they works well, addoil
another thing is that when you use ftp to upload and
download, please use ASCII mode.
thanks :)


---
����: Yuyin
��Ŀ: bug
����: Thu Aug 19 11:23:28 1999
mail fire
------- /secure/obj/mailers/mailer.c:291


---
����: Group
��Ŀ: about the channel
����: Fri Aug 20 03:47:44 1999
recently there are some bad players use gossip channel to say dirty
words and flood.

i think there should be a cmd to force close these players channel,
or even ban the ip.
is there got 1? if no, can do it at once? it is not possible to hope
all players come here are polite..sigh

group


---
����: Stefan
��Ŀ: >>to stefan:a very strange bug
����: Wed Aug 18 08:18:50 1999

I guess it could be caused by color, or mud client.
Tintin or zmud can sometime gag some information.
for example, zmud will gag the password. If the password matches some
color code or some string in the chat message,
it will be gagged. 

dunno if it helps. But one thing for sure is that the message did get
through, it is the player's client did not show it correctly.


---
����: Ice
��Ŀ: about transferring
����: Wed Aug 18 07:27:06 1999
I think now we r using simple transfer is fine at present, later
we will turn it to a task anyway, but .......

i haven't tested any transferring, so far as i saw, war became too
simple if no restriction of transferring.

1. national meeting can hold any time thus a 100k troops might be
   transferred from the northest to the southest city within 20 mins
   without any loss if train and morale both full, is it too fast?
2. transfer has some kind of loss, but as xixixi posted, if train and
   morale both 200, it's no loss anyway, is that too simple for transferring?
3. if a nation get an area, then transfer back all troops, then sendfood,
   till the safety can war again, it's kind of tricks can be used..:P

so for the simeple mode now, may be we can make the following adjustment:

1. each transfer will lose some morale, like 10 each time;
2. make national meeting or transferring has some limits, like
   at the same day can only hold one national meeting or, if A area
   transfer troops to B area, B area cannot transfer troops immediately,
   at least in the same day;
3. transferring stuff, gold, and food need rely on the troops in the startup
   area, if the proportion of food/troop, gold/troop blah blah is in some
   certain number, and/or safety in both area both high, the loss
will be less.

cannot help to post..:P

* escape


---
����: Yuyin
��Ŀ: i want make a wiz_cmds help for chinese
����: Fri Aug 20 15:43:41 1999
���������ҵ�Ӣ��ˮƽ����̫��
��������һЩ��ʦҲ������Һúܶ�
so ������һ�� wiz_cmds help for us
ϣ����λ��ʦ�ܸ��Ҷ�һ��İ���
chat* thank


---
����: Ice
��Ŀ: >about the channel
����: Sat Aug 21 01:54:51 1999
strongly agree, add a vote block channel bah..:)
and a block tell


---
����: Flee
��Ŀ: >> about the channel
����: Sat Aug 21 01:55:15 1999
agree ..
.'


---
����: Ice
��Ŀ: additional notes about transfer
����: Sat Aug 21 02:02:14 1999
1. when A area wants to transfer troops to B area, check B's
   safety, if lower than 100, can say:
   �������Ĳ��ȣ��ٽ�פ���ӿ���Ҫ������ѽ��
2. check B area's existing food, gold, stuff, if cannot support
   the troops for 3 months, it'll say:
   ���ػƽ�/����/��ʳ���㣬����ά�־��ӵĲ�����


---
����: Ice
��Ŀ: additional note about ��ʦ
����: Mon Aug 23 13:18:30 1999
1. ��ʦcannot pos on NPC king, that is cannot transfer king to
   another area, cannot get taishou from king, king is always
   the leader of capital;
2. ��ʦ cannot Ǩ����I think later capital is an important part,
   just like in SAN6, if a city doesn't have link with capital,
   it cannot hold localmeeting and nation meeting, what player
   can do there is only do normal job, thus the rest player will
   have to work hard to get back the link from capital to that
   blocked city.


---
����: Ice
��Ŀ: about the bug in chenghu_d
����: Mon Aug 23 13:10:18 1999
I think it's the emote with $n0a or $p0a sth got bug...:P
check check bah...:P
addoil


---
����: Ice
��Ŀ: about horse status
����: Sat Aug 21 11:40:42 1999
differentiate the ���ﰤ������� and û������ bah,
confused..:P


---
����: Ice
��Ŀ: about city walls
����: Sat Aug 21 18:18:47 1999
I think larger cities should have larger or boarder city walls,
like city size can be 4*4 for lv 5 cities, can be 3*4 or 4*3 for
lv 4 cities, and maybe some ���Ǻ� around it, grin.....

the point is larger cities r supposed to be harder to occupied,
actually in my memory, if the defence troops insist to defence
inside the city, the attack side have to use more troops than
defence side to get the city, and have to pay more if the wall
is strong enough.

well, maybe should implement all warmaps first then adjust them.:P

* pusha row
* escape


---
����: Ice
��Ŀ: add a board in qiao guolao's room bah
����: Sun Aug 22 09:27:14 1999
add a board or some displays in qiao guolao's room showing that

�һ���С�ٺ�������־ĳ��ĳ��ϲ������
�λü�������������־ĳ��ĳ��ϲ������

just for showing the marriage record, and displays the most recent
10 couples.:)


---
����: Ice
��Ŀ: �������
����: Sun Aug 22 18:20:53 1999
������ѩ�����������»ƽ���ǧ�İ���ʮ������

faint, I think if we don't change it, female id will be a trend
of making dummies..:P

suggest to make the following suggestion:

1. if the ��� over 300, ��� will say:
   ��ٴ��һ�����⣬�⣬�⡣��������̫���˰ɡ�������
2. after the wedding is over, the bride will receive 60% of the gold:
   �۳�������ú����������ѩ�����������»ƽ�xxx����
��bcoz there will be a NPC providing unlimited food in the wedding hall,
  and it charges the newly wedding couple, hmm, i made the NPC but cannot
   move obj from the NPC to the player, sb help to change it bah..:)
  it's /wiz/ice/npc/xiaosi.c, thanks..:) * pure ��


---
����: Ice
��Ŀ: ���ڽ��ͽ����emote�ĳƺ�
����: Sun Aug 22 20:10:45 1999
       ���          ����
$R  ���ޣ��๫��  �͵ܣ���硣
$r  �˻������ʡ�   ?  ��  ?

hmm, i think it should be added sooner or later, together with
the objs..:P it's not a good sample anyway, change it to a better
one bah.:D

* wink




---
����: Ice
��Ŀ: about business after unify
����: Mon Aug 23 02:49:30 1999
if we are planning to use NPC countries as initial setting, I
think we have to adjust the ��ʦ�ƶȣ�

just let system random pick sounds not so fair to every player,
I think maybe we can use work more will be selected, and can be
changed time to time. The npc king will select from the highest
3 national contribution officer, and choose from one of them
quarterly, semiannually or annually, i think it could be more
fair than just keep not falling to 0.

so the process of restart a game will be if player join a NPC 
nation, he have to keep work hard to gain enough contri to be
competitive, and the player king will have less pressure but also
less officers work for them.

some additional notes of transfering, i think now the simple mode
transfer is still too simple, it's hard to be a smooth transition
towards the pro mode, i think we can make it as the following:

1. make the max safely transfering is 80% or 75% sth, it's always
   not safe enough to transfering things and stuffs without player
   leader, so for troops with 200 200, it can be a possibility to
   be 80%, or less.  xixixi's unify is benefited from the safe
   transfering, i think we are not hoping to see a flash unify
   every real month anyway. with the observation of the recent
   2 weeks, war becomes the only important part of our game.
2. while pro mode of transfering is completed, we can offer 2
   choice, to use a simple mode to take risk of loss, or use
   manual control to transfer with less risk.
3. I think transferring should has some limitation, however, we can
   add some later, what i hope is not to make it as KOEI's game,
   what i saw recently was exactly the strategy used in KOEI's 
   series, only the frontier has large size troops, all cities in
   the back are empty, and troops can be transferred continuously.
   so i think for the simple mode at present, we can say our point
   is, if u just dun care about the loss, u can keep on transfering,
   if u cannot bear the loss, go make the frontier cities better,
   however, war is not the only business in our mud.

that's it, hope xixixi won't unify too soon, i need some time to
arrange the initial list..:(



---
����: Ice
��Ŀ: lost of chars
����: Mon Aug 23 04:16:36 1999
���鵽��420����ɫ��
faint, we lost around 20 chars, how come...:(


---
����: Fire
��Ŀ: about unarm.c
����: Mon Aug 23 10:44:04 1999
still has bug
sigh


---
����: Stefan
��Ŀ: description
����: Tue Aug 24 00:00:06 1999
�����ǲ����ø���̫������Ϊ���������н�������Σ�
���δ��ɵ� descrption. :)


---
����: Stefan
��Ŀ: �й� balance ������
����: Tue Aug 24 00:40:51 1999
Ŀǰ��ԳƵ۵����⣬���뻹��һ���й����ֺ����� balance �����⡣
�������»��������£�������ּ�����ͳһ�ܶ��Ļ������ֹ�������
mud ������־ͻ�Խ��Խǿ���½�������һ��ϣ���������С�

��������кü��֣�

1. ͳһ������ cut skill��cut exp, ���Ǹ����ֵ��������Ƚϴ�
�������ʧȥһЩ��ҡ�

2. ��Ȼ��������ʲôҲ��������������ƣ��������뿪������Ҳû��    
׼����ʹ�뿪�Ļ������ɫ��Ϊһ�� NPC Ҳ�Ǻ�ǿ�ģ�������
��һ��ȫ�ܵ� NPC��

3. ȫ�� reset�����һ�ɴ�ͷ��ʼ��������

4. �趨���ޣ����ÿ�����ֶ�һ������������̫�á�

�Ҿ�����Щ����û�н���������⣬�Ǿ������׳ɶ��ڳɾ͸�Ӧ�ó�
�������������и����飬����Ҳο�..

skill �� exp ����һ������� rate ���������������ޡ�����ȷ�˵����
��Ŀǰ����� skill ���Ƚϸߣ���ô���� skill �ɳ��͸��졣��Ϊ���� 
matter ������Ե� skill �� exp������ֻ����С����ֵ�ɳ����ٶȣ���
��ֵ�ɳ����䡣����ĿǰҪ�ﵽ 80 ������Ҫ���� 50 ��Сʱ�ɳ����� 80
����Ŀǰ�������������� mud ���ŵ����������������˵�ƽ��ˮƽ�����
�ˣ�Ҫ�ŵ�������Ҫ�� 160 ������ʱ��һ������Ҫ�ɳ��� 160 ��������
ֻ��Ҫ 50 ��Сʱ���������濴�����ƺ�����ռ�˱��ˣ���ʵ�ڸ����� 50
��Сʱ֮�󣬵õ����ˮƽ(������)��һ���ġ�

��Ȼһ������Ӱ���Ǿ���ֵ�����������᲻���Ϊ�������֣�����Ԥ��..
���и������������ rate ��ʱ���ǲ���Ӧ������һ������ˮƽ�ķֲ�ͼ��
�ǵ��ֶ໹�Ǹ��ֶ࣬��ͬ��λ��ʱ�� rate ��ͬ���ȵȡ�


---
����: Ice
��Ŀ: initial list of restart
����: Tue Aug 24 03:29:00 1999
10 player area:
qinchuan, yunnan, lingling, xinye, luling,
poyang, jinyang, qinghe, kuaiji, beihai.

NPC area:

1�����ڹ�
king: ma teng
xiliang: ma chao, pang de, ma tie
didao: ma dai, ma xiu

2 cities, 6 officers.

2�������
king: han sui
longxi: zhang heng, yang qiu
tianshui: liang xing, cheng yi
jieting: cheng yin
qishan: ma wan

4 cities, 7 officers.

3����׿��
king: dong zhuo
changan: li su, li ru, dong cheng, zhang liao
anding: zhu juan
chencang: song xian
xianyang: lv bu, chen gong
jingyang: wei xu
huayin: guo si
tongguan: hou cheng
wuzhangyuan: gao shun
wuguan: fan chou
hangu: zhang ji
hongnong: hua xiong, wang yun
mianchi: zhong you
luoyang: lu zhi, huangfu song, yang biao
huguan: zhang xiu
hulaoguan: xu rong

15 cities, 23 officers.

4���ν���
king: he jin
taiyuan: pan feng, han fu
shangdang: xin pi
yanmenguan: xin ping

3 cities, 4 officers

5����³��
king: zhang lu
hanzhong: yan pu, zhang song
xiabian: zhang wei
yangpingguan: zhang yin

3 cities, 4 officers.

6����谹�
king: liu zhang
chengdu: zhang song, deng xian, li hui, xu jing
dingjunshan: zhang ren
jiange: lei tong
zitong: wu lan, zou jing
fucheng: huang quan
mianzhuguan: fei shi
jianning: wu yi, dong he
jiangzhou: yang huai
yongan: yan yan, liu ba

9 cities, 16 officers.

7�������
king: liu biao
xiangyang: liu zong, kuai liang, zhang yun, huo jun
shangyong: cao mao, kuai yue
chanxi: wen pin, fu yi
changbanpo: gan ning, su fei
jiangxia: liu qi, huang zu

5 cities, 13 officers.

8��������
king: liu bei
jiangling: zhuge liang, wei yan, liu feng, yi ji
yiling: zhang fei, zhang bao
gongan: huang zhong, yin mo
huarong: guan yu, xu shu, wang fu
wuling: zhao yun, ma liang, jian yong

5 cities, 15 officers.

9�����ȹ�
king: liu du
changsha: xing daorong, liu xian
guiyang: pan rui
guilin: gong zhi
nanhai: bao long
chibi: zhao fan

5 cities, 7 officers.

10��Ԭ����
king: yuan shu
wan: ji ling, lei bo
runan: yuan yin
bowangpo: lv fan

3 cities, 5 officers

11������
king: sun jian
chaisang: zhou yu, zhu zhi, zhang zhao, lu ji
yuzhang: sun quan, huang gai
xisaishan: lv meng, han dang
danyang: sun jing, sun yu
lujiang: sun ce, li yi
ruxukou: lu xun, ling cao

6 cities, 15 officers.

12�������
king: liu you
shouchun: chen heng, chen wu
hefei: yan xing
huaiyin: ze rong
jianye: taishi ci
wujun: zhang ying

5 cities, 7 officers.

13���ܲٹ�
king: cao cao
xuchang: guo jia, xun you, xun yu, dian wei, cao ren, xiahou en, man chong
qiao: yu jin, liu ye
dingtao: cao ang, che zhou
puyang: xu huang, chan jiao
baima: cao hong, cao chun
ye: xiahou chun, cheng yu
chenliu: xiahou yuan, chen qun
guandu: li dian, yue jin

8 cities, 22 officers.

14��Ԭ�ܹ�
king: yuan shao
nanpi: yan liang, wen chou, zheng he, chunyu qiong, ju shou
daixian: guo tu
jicheng: yuan tan, tian feng
yijing: chen zhen
jieqiao: gao lan
pingyuan: yuan shang, feng ji
jinan: yuan xu, chen lin
bohai: shen pei

8 cities, 16 officers.

15����ǫ��
king: tao qian
xuzhou: chen gui, chen deng, sun gan
xiaopei: zang ba
xiapi: cao bao
guangling: mi fang
langya: mi zhu

5 cities, 8 officers.

16������趹�
king: gongsun zan
beiping: gongsun gong, yan gang
bailangshan: gongsun yue
xiangping: gongsun du

3 cities, 5 officers.

Total: 89 areas, 168 officers.

NOTE:
The first city is capital, king is always leader of capital.


---
����: Fire
��Ŀ: >description
����: Tue Aug 24 20:28:46 1999
On Tue Aug 24 00:00:06 1999 Stefan wrote post #785:
> �����ǲ����ø���̫������Ϊ���������н�������Σ�
> ���δ��ɵ� descrption. :)

that is a good idea :)


---
����: Ice
��Ŀ: about player data after unificationi
����: Tue Aug 24 07:25:01 1999
I think we can keep player's skills, and not change at all.
however, I think we do need change erase all the local
contributions..:P


---
����: Ice
��Ŀ: an idea of wounded soldiers
����: Tue Aug 24 07:08:03 1999
If sb remembers the SAN5, there was a �˱� para in troops,
I think we can also implement this idea.

change the attacked msg to ���� instead of ��ʧ

when a troop is attacked, part of them died, and part of them
wounded, thus added a new type in the current troops called
wounded soldiers, and their train and morale will be fixed at
50 50, just like commando.

and further more, we can set it as a permanent type, wounded
soldiers cannot involve in attacking, they can only involve in
defence, and they will recover after some time, the recover rate
can be fixed now and later maybe we can add a base of hospital
in large cities, with those hospitals, wounded soldiers can
recover faster.  after the wounded soldiers recovered, they will
be considered as footman.

then we can add a skill called healing, and a trick of healing.
while in war, the player can heal his wounded soldiers if he has
enough herbs and enough skills.:P

that's it.



---
����: Ice
��Ŀ: >description
����: Tue Aug 24 05:08:04 1999
I think it'll be better that the king or area leader take
charge of that.  I visited a mud named ���֮����it's a BIG5
version, and player can establish a nation, then design the map,
and room description and NPCs, after the wiz approved the setting,
it's his nation.

however, we cannot do exactly the same thing, bcoz our game is
more or less related to the history, so I think we should find out
a way to let player make descriptions by themselves and not just
giving out skills reward...:P

I think we have 80 areas without room description, it's a large large
work, how about giving out unique objs?


2 lv 1 or lv 2 cities with rooms total less than 30 will be reward a lv 6 obj
blah blah..:P or sth else, just find out a way to finish the descriptions.:D


---
����: Fire
��Ŀ: sorry about the wrong para
����: Wed Aug 25 19:10:19 1999
should be checkemote * /c


---
����: Fire
��Ŀ: how to set one room to be a bank
����: Wed Aug 25 22:26:56 1999
@SETHERE("t",3)


---
����: Row
��Ŀ: ����restart
����: Wed Aug 25 23:06:03 1999
������ǰ������������post���һ�����ͬ�⣬�ر��ǽ����׵۸�
��xixixi�Ľ��飬�ǳ���Ȥ������Ҳ�൱��������xixixi����
�ʵ��ˣ�����û��������Ҳ���ԣ���ʵ���ǰ����ָĵ���Ҳ����
ͳһ�Ľ����ɡ�
���ڼ���ݣ�Ҳ��һ�������壬�����ж������й��׵���Ҽ�
��ʦ�Ž�ȥ���п��ܵĻ�����ÿ����д��СС���Դ�����ʲô
�ģ����������Լ�д���Ѿ������ľ�ֻ������ʦ�����ˣ�������
��ݰ��ڻ������۵ĵط��������������������������Ҷ��л�
��ȥ��Ħ��Ħ��
���е�reset��ice����Ӧ��û��ʲô���⣬����ҵ�reset��Ҫ��
������ˣ�������Ҫ�˺�����ҵĸ��飬����ĳЩ��ʱ�ܴ����
����skills�Ͳ�Ҫ���ˣ�������书ʲô�ġ������Ĺ۵��ǣ�����
����ڵȼ��ϲ�ռ̫�����ƣ���Ϊ���Ƕ�ϵͳ����Ϥ�Ѿ��Ǹ���
��������ˡ�
���⣬���Կ��Ǹ�ͳһ�Ĺ���������һЩ�������ļ���Ʒ������
NBA�Ĺھ���ָ��hoho����ҿ���һ�¡�


---
����: Fire
��Ŀ: the bug about $n0p ?
����: Tue Aug 24 22:52:29 1999
when will this bug appear, i can't find it :(


---
����: Fire
��Ŀ: ��������������
����: Wed Aug 25 00:05:14 1999
1 ice ��NPC��list �ǳ��ã�׼������
2 ��Ҳ�����reputation, loyalty , localcontribution and nationcontribution
  ��ȫ��������������ͬ������MUD���ߵ�skillsû�о����Ե����á�
  һ�������������ֻ����Ĳ��룬��������Ҫ������ռһ���ı���(�����ĸ�MUD
  �ж����)�����һ�����ɣ��ܿ�ͱ���̭�����Ǳ�MUD��һ���ص㣬������ʼ��
  ���ֻ����������ܿ�Ͳ��ò����������ߵ�skills��reputationû��̫���
  �ˡ�������һ������һ���ż����͸��־�û��̫������𡣶�������Ƚϵ�����
  Ҫ������Ե��
3 ���鱾��ĩ����������
4 ����visitwise and searchwise �������ǵĳɹ��ʡ�
5 ���ڹ�ʦ��ֻ��nationcontribution > 500 (��ֵ���Ե���) ���ܵ�NPC���Ĺ�ʦ��
6 ��������
   1 ���ʳ�������ȫ������
   2 ����ѵ����ʿ��ȫ��Ϊ50
   3 ʿ�����������ȼ�   ����
                 5      500
                 4      400
                 3      200
                 2      100 
                 1      300
   4 ������������
7 ÿһ��ҹ���ϵͳ�Զ��㱸����NPC��
 


---
����: Ice
��Ŀ: >��������������
����: Wed Aug 25 00:45:05 1999
agree to restart this weekend.


---
����: Flee
��Ŀ: >��������������
����: Wed Aug 25 01:43:43 1999
agree


---
����: Fire
��Ŀ: about the semote_cgi
����: Wed Aug 25 19:08:32 1999
it is not bad, but if can display the rela massge such
�һ����Ƶغ��������˸��к��� 
rather than $N blah blah $t will be better
you can check "checkemote * /s" for similar method, thanks :)


---
����: Ice
��Ŀ: >about the semote_cgi
����: Wed Aug 25 19:09:34 1999
if can add the emoteapropos as well, will be much better..:)
emoteapropos is a player cmd

addoil flee..:D


---
����: Fire
��Ŀ: about recover
����: Thu Sep 23 22:24:16 1999
�ܲ�������������һ���ش��Ӳ���¹ʡ�����������µ�backup
��һ����ǰ�ġ�������Ƕ�ʧ��һ���µĿ����ɹ���һ���µ���
���������ݡ����˵����Һ�row�Ļ������������һ���µĲ�����
����ϣ������wiz�Ļ�����Ҳ�����Ƶ��ļ����������ǿ��Ժܿ�ָ���
�Һ�row�Ѿ��ָ��˲����ļ��������ǲ��ֻ���Ҫ�ָ��ļ���
1  ���� ���λ, flee's work
2  score.c ���� marriage and jieye situation. group's work
3  /sgdomain/home/pic/*.pic, fire's work
4  add and adjust home information in house_d ice's work
�������ֵĿ������ı�ȣ���Ҫ��flee and group�Ĺ�����ϣ����
���п������ܾ���ָ���


---
����: Stefan
��Ŀ: machine was hacked and all data lost
����: Thu Sep 23 00:18:33 1999
This is surely a sad news, I should not have used this machine because
it was not well maintain at all. Now I am thinking of moving the mud
to a new machine. Will update you guys after it is setup.

The backup I've got is the one just before reopen. It is about one
month old, that means no data in the month was kept. I hope this does
not mean too much lost to most of you. The webpage was also lost.

Any inconvenience caused is much regretted.


---
����: Stefan
��Ŀ: player login temporarily closed
����: Thu Sep 23 00:20:26 1999
players should not be able to login unless we got things fixed up.
*addoil fire
*addoil flee
*addoil row
*addoil ice

To reopen player login, edit /include/config.h, change #define NO_PLAYERS
to #undef NO_PLAYERS, then reboot the mud.


---
����: �һ�(fire)
��Ŀ: two new function for robot test
����: Thu Sep 30 03:33:56 1999
set_robot_time(int num) set the number of roboting
set_test_time(int num) set the number of testing


---
����: ĳĳ(group)
��Ŀ: the last city for war
����: Tue Oct  5 02:08:28 1999
i change the /sgdomain/cmd/war.c hence player can destroy NPC
country, hope that is ok.
group


---
����: �һ�(fire)
��Ŀ: how to check an obj's memory consume
����: Sun Oct  3 02:35:19 1999
help, help


---
����: ����(row)
��Ŀ: beware!
����: Thu Oct  7 22:48:20 1999
i dunno why, this site is becoming more and more lag, but its fine when
it was just restored. i remember that we experiencing the same situation
b4 the hacker attacked, so pls beware.....
maybe i think too much of it.


---
����: ����(row)
��Ŀ: area_d
����: Fri Oct  8 00:06:22 1999
i changed stat_me a bit, so an ordinary officer cannot see
the important info of a area, hope it can prevent some spy work.


---
����: �һ�(fire)
��Ŀ: about the lag
����: Fri Oct  8 05:41:52 1999
I will download a whole copy next week, sigh:(


---
����: ����(row)
��Ŀ: bug of bugao
����: Sat Oct  9 00:09:48 1999
liuxiong told me that bugao job got bug:
when someone drop the bugao, he will be busy for awhile,
and just at this moment, if another keep on typing "get bugao".
this guy will be rewarded 20 loyalty again and again, so
that is unreasonable, fire pls test on it.


---
����: ����(row)
��Ŀ: man tasklist
����: Sat Oct  9 04:53:40 1999
fire update the tasklist bah.
hoho.


---
����: �һ�(fire)
��Ŀ: about the bug in bugo
����: Mon Oct 11 07:49:22 1999
Hi row, thanks for your report
when you have time, can you help me to help
a check about that bug
the files is under /sgdomain/job/bugao/

thanks


---
����: �һ�(fire)
��Ŀ: welcome new wizard.
����: Wed Oct 13 07:32:08 1999
Now roro become a new wizard.
I think he can learn first, try to read
as many as helps under /help/wizard
and read some files under/sgdomain/job/
when he is familar to this system, I think
maybe he can try to design some new basic and mid
level jobs


---
����: Fire
��Ŀ: >about bugao job
����: Wed Oct 13 07:20:42 1999
On Tue Oct 12 23:05:50 1999 ����(row) wrote post #816:
> i changed the file :/sgdomain/obj/other/sdpk.c on the call_out("dissap")
> part, i think maybe becoz of the delay of 1 sec, player is allowed to input
> several get bugao within a short time which will cause bug. now i change
> it directly to remove(), so the bugao will be destruct as soon as someone
> get it, flee said it may cause some problem of get.c, but i tried and find
> its ok.  but please still keep an eye on it.

�һ����������ر��Ű���˵��������������г�Ϣ�ۣ������������ε�����һ����


---
����: ����(row)
��Ŀ: about bugao job
����: Tue Oct 12 23:05:50 1999
i changed the file :/sgdomain/obj/other/sdpk.c on the call_out("dissap")
part, i think maybe becoz of the delay of 1 sec, player is allowed to input
several get bugao within a short time which will cause bug. now i change
it directly to remove(), so the bugao will be destruct as soon as someone
get it, flee said it may cause some problem of get.c, but i tried and find
its ok.  but please still keep an eye on it.


---
����: ����(yuyin)
��Ŀ: about a new application for wiz
����: Tue Oct 12 05:26:37 1999
����֧�� fire �����,


---
����: �������(tit)
��Ŀ: i decide to quit from all mud
����: Thu Oct 14 21:39:19 1999
as title
sorry to all


---
����: ����(row)
��Ŀ: gj_menu has bug.
����: Sat Oct 16 22:18:48 1999
the ������ function has bug.
         *Expected: string or array or object Got: 0.
[errors] /sgdomain/home/npc/gj_menu#891953 at line 62


---
����: �һ�(fire)
��Ŀ: bugs in secure/simul_efun/string 
����: Sat Oct 16 20:12:12 1999
the iwrap function seem not work properly


---
����: Row
��Ŀ: >about new wizard
����: Wed Oct 20 18:54:20 1999
that is right, but i think the reputation should be 100000...hehe.


---
����: �һ�(fire)
��Ŀ: about new wizard
����: Wed Oct 20 03:19:01 1999
i think for new wizard, can we add some limit such as
reputation more than 10000, literate more than 2000 ?

if so, that means he is at least a good player and like
this mud and also know a lot about this from the view of
players, what you guys think ?


---
����: ����(row)
��Ŀ: bug report
����: Tue Oct 19 22:25:40 1999
rulin reparted some bugs:
1. e.g.: when a play ask for a searchwise job, when he finishes the
job, he doesnt go back and ask for pay, he may let taishou pos him to
another city, then he could ask for the same job again (he will not be
rewarded), if he is a nation officer, he doesnt need to let taishou pos
at all. this bug makes him do unlimited mid-job, the area and nation will
get the credit such as safety and npc, except the player himself receives no
credit, but it doesnt matter espcially in some rob-npc actions.
2. the result is nearly the same as the first bug, that is, ask for
job, finish
it, cmd resign the job after 10mins (the job record doesnt add),
then can ask for
job again.
3. that is about the house system's zhangfang.  normally player is allowed to 
have 5k gold in bank, 1k gold in salary, but the zhangfang fuction make this
limitation meaningless, ppl may transfer his money from his bank
accound to the
zhangfang, then he could get more than 6k gold. for the example, try
"money rulin".

for the first 2 bugs, i suggest ppl be set job record finished as soon as he 
finishes the job.
for the 3rd bug, fire pls check it further bah....xixi.

ps: rulin ask for some rewards for the reporting of these bugs: special horse,
better house, some equipments, i dont think that is much so i agreed, what r
ur guys opnions?


---
����: ����(row)
��Ŀ: about basic job
����: Tue Oct 19 19:45:44 1999
��ͻȻ�뵽���������idea��Щ�µĳ���������һ���������
һ����Ҳ���Ը�������wizһ����ϵ�Ļ��ᡣ��ҿ���Σ�


---
����: ����(row)
��Ŀ: suggestion about ����
����: Tue Oct 26 20:31:53 1999
i think in every area's info, u may find the ������id�� so
that is more clear.


---
����: ����(row)
��Ŀ: suggestion about house
����: Tue Oct 26 20:35:51 1999
fire, since those servants r all naked, and we have a �ʹ� option,
so why not when player give cloth or other things to servants, then he
or she can dress it up?  hehe...


---
����: Fire
��Ŀ: >suggestion about house
����: Wed Oct 27 04:05:08 1999
On Tue Oct 26 23:35:51 1999 ����(row) wrote post #827:
> fire, since those servants r all naked, and we have a �ʹ� option,
> so why not when player give cloth or other things to servants, then he
> or she can dress it up?  hehe...

I have though about it, need some time to implement




about the display of zhoumu, you can adjust it if you think
it is more clear :)


---
����: ����(ice)
��Ŀ: somewhat I did with this mud
����: Wed Oct 27 12:19:19 1999
all files associate with this mud I did with is in
/wiz/ice/sanguo
those are all copies I had, because most of the time
I used ED, so.....

I think most of them are rubbish, except the colored
house, update it bah, took me much effort..:P

addoil.:)


---
����: ����(row)
��Ŀ: suggestion
����: Wed Oct 27 21:15:11 1999
when someone tell ur or reply u, there should be his eng id follows
his chinese name,
it will be more clear.


---
����: �һ�(fire)
��Ŀ: about color house
����: Thu Oct 28 04:34:55 1999
that is good, ice. but i got some problem
1 in lima or unix system. how could we change a group of
file's extension. because in the house system we use *.pic
I got big trouble to change the name of groups so i download
them to localmachine and under dos use cp *.txt *.pic to change
them and upload back. is this method silly ?

2 still several house not color :)

3 I move all your *.txt to the *.pic but still need
install to the house system. when you have time
can you do it ? addoil :)



---
����: ����(row)
��Ŀ: ack
����: Mon Nov  1 17:25:31 1999
what the hell is going on?


---
����: ����(row)
��Ŀ: new basicjob: choppork
����: Mon Nov  8 23:24:02 1999
i just created a new basic job -- choppork, all relevant files including
help r under /sgdomain/job/choppork/.  so anyone please test it, if there
is no problem.  i hope fire could register it into the JOB_D.  thx.

any bugs, pls inform me.

row.


---
����: ����(yuyin)
��Ŀ: �ҵ�һЩ���
����: Sun Nov  7 03:34:13 1999
�Ҿ����б�Ҫ���й���һ��
mirror
����,�Ҿ��ÿ��Ժ� fire д�ŵ��Ǹ��˽���һ��
���ܻ�����ǵķ�չ�а���
��Ϊ�Ҿ����������ǵ� server ���ٶ����ʮ����
��Ӳ��Ҳ����������,
���������Ƿ�չ player ��һ��������
����������ܷ�չһ�� mirror �Ļ�
�� player ��������˵ҲӦ����һ������
�����ұȽ��޳ɿ���һ�� mirror

addoil fire
addoil all wiz


---
����: �һ�(fire)
��Ŀ: about the new job
����: Tue Nov  9 02:58:47 1999
seem has a little bug

I can't find zhang, so clone one at the river
���ڲ�������(yu fu)
�ӱߵ�һ��������(pound)
��������һ�쵶��������(zhang tuhu)
ask zhang about job
���������������λ������С��������Щ��ɡ�
��������������ţ���ô���ⰳһ�˻���æ��������������Ҫ��ʮ�������ţ�������
������㣬�е�Ҫ���룬���õİ��ɲ��ա�Ҫ�ǲ����������ˣ������ʰ��á�
(ask zhang about meat)
������������һ���޹ǵ���һƬ�����ߡ�
> i
�����ϴ���������Ʒ(���أ�44%)��
�����ݳ���(longblade)
�����(diamondring)
����쵹ٷ�(blguanfu)
  һ��ĥ��ѩ�����޹ǵ�(tigudao)
  һ��СԿ��(key)
  �İ���ʮһ������(gold)
can't find the meat ?
l
ľ�� [���ڣ�north]
    ����һ��խխ��ľ�ţ�����ȥ�ƺ����첻�ã�Ҫ��Ȼ����ȥ����
�е��ľ���ս�ء����������¿�����һ�������С�ӣ�ˮ����������
�ţ��峺�ޱȣ��㻹���Կ�������������ˮ����Ϸ�����ϻ�վ��һ
���ˣ�������Ǹ����
���ڲ�������(yu fu)
�ӱߵ�һ��������(pound)
��������һ�쵶��������(zhang tuhu)
ask zhang about meat
���������������ʦ���������ҵ��������ˣ������ܲ����ٸ�Щ��
*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/runtime
[errors] (fire) Error logged to /log/runtime
[errors] *Bad argument 1 to call_other()
         *Expected: string or array or object Got: 0.
[errors] /sgdomain/job/choppork/zth#166486 at line 196
dbxwhere
Tue Nov  9 05:54:44 1999
*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Object: /sgdomain/job/choppork/zth#166486 at line 196
#0: '<function>' at /secure/user#166205 (<function>) at :0
#1: 'dispatch_modal_input' at /secure/user#166205 (secure/user/input
sys.c) at line 305
#2: '<function>' at /trans/obj/wish#166212 (<function>) at :0
#3: 'shell_input' at /trans/obj/wish#166212 (secure/obj/shell.c) at line 130
#4: 'execute_command' at /trans/obj/wish#166212 at line 293
#5: 'do_game_command' at /std/race/human#166211 (std/body/cmd.c) at line 60
#6: 'do_ask_str_about_wrd' at /cmds/verbs/ask at line 74
#7: 'do_ask_liv_about_wrd' at /cmds/verbs/ask at line 66
#8: 'be_asked' at /sgdomain/job/choppork/zth#166486 (sgdomain/module
s/m_ask.c) at line 170
#9: 'special_answer' at /sgdomain/job/choppork/zth#166486 at line 47
#10: 'ask_meat' at /sgdomain/job/choppork/zth#166486 at line 196
dbxframe 10
------sgdomain/job/choppork/zth.c:196 - ask_meat()
locals: 0, 0, NULL
----------------------------------------------------------------
        {
           this_object()->targetted_action(
           "$N��һƲ����$T�����ղŸ�����⻹û���꣬��ô����Ҫ�ˣ�\n",usr);
           return;
        }
=>        if(pork->query_count()>20||pork->query_count()==20)
        {
            this_object()->targetted_action(
            "$N����$T��ͷ�������������Ѿ������ˣ���������Ҫ����(as
k zhang about pay)��\n",usr);
           return;
        }


addoil row


---
����: ����(row)
��Ŀ: choppork
����: Tue Nov  9 19:02:54 1999
i verified the code and correct the bugs, i hope there will be no problem...
xixi, pls test again.


---
����: ����(row)
��Ŀ: sth wrong with robot test
����: Wed Nov 10 00:40:42 1999
some player still get literate if they make wrong answer....fire pls check.


---
����: �һ�(fire)
��Ŀ: ����ս����Ϣ
����: Mon Nov 15 04:27:13 1999
�Ҽƻ����һ��С���򣬼�¼�¾����ܶ��ս����Ϣ��
Ȼ��ϵͳ�Զ�POST������
���ã�
  1 ������ʷ���ϡ�
  2 �����ڷ���ս���е�BUG����ƭ��Ϊ
  3 ���㹫�ڵĺ�����:)


---
����: ����(row)
��Ŀ: about tasklist
����: Mon Nov 15 05:11:39 1999
i have no problem about it, will finish them asap.


---
����: ˹̹��(stefan)
��Ŀ: mudlib public release
����: Thu Nov 11 07:46:34 1999
I am cleaning up a base mudlib release of chinese lima. I removed all San Guo 
related things from this base lib. But some more work has to be done.

I am also trying to clean up the library a little bit, I would be very
careful not to break existing things... but in case I do, please
pardon me :)


---
����: ˹̹��(stefan)
��Ŀ: release plan
����: Fri Nov 12 07:02:16 1999
�ҳ��������һ��ʱ������£�
( lima mudlib ָ�������к���������û��ֱ����ϵ�� code )

ʮһ�µף����������ҳ������ lima mudlib ������ release��
ʮ���µף������һ��������վ����ȡ������ʽ��
�������£���������־�Ļ����ܹ����Է������� SLG �� MUD ����

���� lima �� license ���ƣ����ܹ������κ���ҵ�棬�����Ҵ���
�� GPL �����к������ lima mudlib ������ mudlib���κλ�����
Щ mudlib �Ŀ��������빫�����е� source code��

֮������������ԭ���ǣ����۶�õļ����ܻᱻ�Ƶ������μ��Ǹ���
�õ����ӡ���Ȼ����һ�� code �ᱻ������������ӿ�ͷ�͹�������
�������԰ѻ��ڴ��ϵĿ�������������һ�������Ѹ�ٷ�����������
һ��������˿������̡�

���ͬʱ���һῪ��һ��ר������ lima mudlib ����ҳ��Э�����
���̡�

���������кܶ�Ǳ��û���ڳ����������Ұ������Ƴٵ��������£�
ϣ����ʱ���ܹ��ﵽһ���Ƚϳ���Ľ׶Ρ�

��֪����λ��ʦ��ʲô���飬���Թ�������һ�� :)

*addoil


---
����: Fire
��Ŀ: >release plan
����: Fri Nov 12 23:29:38 1999

stefan's suggestion is good

I think the best way to protect us is to open us
then anyone can get source code from us open page
and if they are interested can join our development team.

In this situation we can keep good development force

our ppl can download our code and if make some good
development we can ask them to feedback. perhaps we can
use CVS to manage the code version.

but the first important thing is to create a good
web page and clear our policy.

addoil


---
����: ����(yuyin)
��Ŀ: �Ҹ��˵�һЩ�뷨
����: Sat Nov 13 00:39:17 1999
�Ҿ��� stefan ��˵�ķǳ�����
�� fire ��˵����Ҳʮ���޳�
��Ϊ���ڱ���һֱ��Ķ��� lpc �����μǺ� ������
�� lama �������� mudlib ������ʮ���� 
���Ҫ��ʱ������߿� mudlib �Ļ�
����û��֧����ô��Ŀ���,������ֻ����������
����ܹ����Ļ�,���� download һ������ѧϰ
��Ϊ��һֱ��Ϊ�������һ��ʵ��һЩ�Ĺ���
������ӦΪ������˵��ԭ��δ������
�� fire �� stefan ����һ��
�� fire �� stefan ����һ��


addoil fire
addoil stefan
addoil all 


---
����: Row
��Ŀ: >release plan
����: Sat Nov 13 03:10:13 1999
i agree with stefan.
we still have lots of things to do b4 we can open the lib
to public for further development, so all of us have to
work hard to archive such target.  to open a mirror site
in china mainland as a first step is absolutly necessary,
especially for advertisement and test.  in addition, we may
recruit some new programmer from that site into our wizard
team to speed up our progress.  of coz, Sanguo's future is
free for all, i think its the way that all the chinese mud
have to go, especially for those develop based on public mudos.
anyway, sanguo is prosperous, lez do our best.


---
����: ����(flee)
��Ŀ: >> release plan
����: Sat Nov 13 05:49:47 1999
agreed.


---
����: ����(group)
��Ŀ: release plan
����: Sun Nov 14 01:17:24 1999
agreed..:)


---
����: ����(flee)
��Ŀ: tasklist
����: Sun Nov 14 19:56:09 1999
fire, post a new tasklist bah .. :)


---
����: �һ�(fire)
��Ŀ: the memory useage
����: Mon Nov 15 02:52:47 1999
> time
����ʱ��                ��ʮ����ʮһ��ʮ����������ʱ��ʮ�ķ�
����������              ��ʮ����ʮһ����������һʱ��ʮһ��
��������ʱ��Ϊ          ����ʮ��Сʱ����ʮ������


>cpu
CPU usage: 13.57%
Mud status is
Sentences:                            49      784
Objects:                            4912  1871320
Prog blocks:                         942  1193636
Arrays:                            30733 11576164
Mappings:                          66862  6522788
Mappings(nodes):                  150645
Interactives:                         22   139392
Obj table overhead:                 6004   284644
All strings:                    1345947 36436050 + 5516492 overhead
call out:                            200     5600 (current length 48)
                                         --------
Total:                                   %^H_RED%^63546870%^RESET%^
load average:
3.55 cmds/s, 8.79 comp lines/s
��Ʒ������3870
����������627
���ڷ���������331
���ⷿ��������456
daemon ��Ʒ������263

how come, our obj number just 3870, the cpu useage is 63K

*doubt


---
����: �һ�(fire)
��Ŀ: ����tasklist
����: Mon Nov 15 03:44:44 1999
������ǵ�Ŀ�ľ������һ��MUD��Ȼ�������ܹ�������ת������˵���ǵ�Ŀ
���Ѿ��ﵽ�ˡ�����������ǵ�Ŀ������һ����õ�����MUD�������ǵ�·��
���������������ǵ�MUD����Ϸ�����ϻ����Ѿ�������һ��Բ�����йؼ��Ե�
���ݻ��������ˡ���ȻBUG���ǲ��٣�����Ӱ����Ϸ�������е�����BUG�Ѿ���
���ˡ�ֻҪ�������������50(��ʱ�����ƺ����õ���)������ϵͳ����ת����
�첻�����⣬�ȶ����ƺ��Ѿ�������΢������в���ϵͳ:)��������һ���Ĺ�
������Ϊû��ʲô�ر�������£����д�ҿ��Ը�����Ȥ�����һЩ���ɷ��ӡ�
ͬʱ�Ѹ�����ͷ�ļ�������������ɡ�ʣ����Ϊ�ؼ��ľ��ǹ��ڹ�������ͷ�
վ�����⡣�������Ϊ���Ƕ�û�о��飬���Բ��ò�֮������
�����Ұ���ͷ�ļ����������ظ�һ�£�
1 fire: ����ϵͳ��NPC��Աϵͳ
        �����ϵͳ
2 flee,group: ��ı���󷨣�landlord��one on one
3 stefan: Web page, Open lib
4 row: ����һ�����ڹ����������м�������
5 yuyin: ����row��code����ȡ���һ���򵥵Ĺ�����
6 �������⼸���������ˣ����Կ�������simcity����������ϵͳ��
���϶���һЩ�ϵĻ��⣬��ҿ���ô����



---
����: Stefan
��Ŀ: >the memory useage
����: Mon Nov 15 23:27:18 1999
> All strings:                    1345947 36436050 + 5516492 overhead

Here is the problem... I am wondering why the strings have caused
42M memory... 
could there be some serious memory leak in MudOS?

> how come, our obj number just 3870, the cpu useage is 63K
> 
> *doubt


---
����: Ice
��Ŀ: >release plan
����: Tue Nov 16 15:41:09 1999
I agree the plan, all things seems alright except one point
if we open a mirror site in china, how will we manage the
development in 2 different sites? or we just let it go
to different direction?.:P


---
����: Ice
��Ŀ: >����tasklist
����: Tue Nov 16 15:47:25 1999
me ...... :(
mnn, if I can have time this week, I'll finish the house
level identification, but I have forgotten the cmd to
do it.:(

give me an example to do it like this:
@HOUSE_D->set_house("xxx","name","����")
para=name,level,room.....

��~~


---
����: �һ�(fire)
��Ŀ: kick ice
����: Wed Nov 17 02:02:54 1999
got ISP lah.
welcome back :)
the command is in /daemons/house_d.c
you check the code and try to find the cmd bah :)



---
����: �һ�(fire)
��Ŀ: ���ڱ��������
����: Wed Nov 17 02:26:09 1999
������������౦������û��������;���õ���
ice ��ʲô�õ��ӣ�


---
����: Row
��Ŀ: >���ڱ��������
����: Wed Nov 17 05:33:13 1999
On Wed Nov 17 05:26:09 1999 �һ�(fire) wrote post #854:
> ������������౦������û��������;���õ���
> ice ��ʲô�õ��ӣ�
��Ȼ��ͨ��quest������������job���������޵�����
����ice ���е��ɡ�grin....


---
����: Row
��Ŀ: >war info
����: Thu Nov 18 06:40:30 1999
On Thu Nov 18 08:26:43 1999 ˹̹��(stefan) wrote post #856:
> would it be better if we open another board for all those warinfo instead
> of caolu board?
i have the same suggestion as stefan, then players can read post
selectively. we may put a board named ս������¼ at each gate of
areas, and caolu is still the board for players opinion and suggestions, etc.

is that ok, fire?


---
����: ˹̹��(stefan)
��Ŀ: war info
����: Thu Nov 18 05:26:43 1999
would it be better if we open another board for all those warinfo instead
of caolu board?


---
����: ����(row)
��Ŀ: ������ô�ˣ�
����: Thu Nov 18 21:07:58 1999
������ٶ�ͻȻ�ָ���������ˮƽ���ǳ��ǳ��ÿ죬�þö�û����ôˬ�ˣ���
���½����Ҷ���ͬ���ĸо�����stefan�ڷ������϶����ֽ��ˣ��ٺ٣�����
�й�����ͻȻ�������ſ�������أ���֮�Ǻ��£�ϣ���ܱ��֡�


---
����: �һ�(fire)
��Ŀ: Ice is the best ppl to do the map
����: Sat Nov 20 19:06:23 1999
addoil :)


---
����: �һ�(fire)
��Ŀ: about the strings in the area_server
����: Sat Nov 20 19:08:44 1999
stefan is right, the server load all the desc in
the memory. I will change it so use different
files to hold the string information.
this is the same as warmap, home and semotes :)

and all other daemon datebase system. 
it is terrible :(


---
����: �һ�(fire)
��Ŀ: about the string
����: Sat Nov 20 19:24:46 1999
I think the area server and other daemons may be
not the real reason for so many string memory useage
because most daemons will be loaded when the system bootpu
and the rest daemon data will be loaded within the
first sevaral hours of the system's reboot. but
the memory usuage seem increase forever. so must
sth wrong with the OS. 


---
����: ����(flee)
��Ŀ: about catch bug(?)
����: Fri Nov 19 23:22:35 1999
here is the record of leeye
"recruit" : ([ /* sizeof() == 7 */
"beg_time" : 943080844,
"count" : 365,
"memo" : "��400��",
"left" : 400,
"finish_time" : 943080844,
"area" : "lujiang",
"lasttimes" : ({ /* sizeof() == 50 */
943054169,
943054195,


---
����: ˹̹��(stefan)
��Ŀ: cpu usage and area_server
����: Sat Nov 20 09:18:33 1999
The primary overhead comes from strings (as fire posted a CPU info).
I checked the area_server thingy, seems that all rooms
are loaded into memory, just imagine all the descriptions,
those are long strings, which surely add up to a lot of
memory space.

Is there a method to clean up unused rooms so that those memory
gets released? 


---
����: ����(ice)
��Ŀ: about whole_map.jpg
����: Sat Nov 20 09:43:08 1999
fire, I think you may still have the map files I sent to you,
pls send those to me to let me see if I can draw one for
stefan bah, my new email now is tom811@163.net, but seems it's
not work well time to time.:(, any way, if got time, i'll
try to do it, after all the whole_map is made by me.:P


---
����: ����(ice)
��Ŀ: ack
����: Sat Nov 20 10:22:40 1999
## Undefined variable 'HOUSE_D'
inn, just one sentence bah, fire, how to add...
* beg


---
����: ����(ice)
��Ŀ: about war_post
����: Sat Nov 20 11:29:48 1999
war_post is a nice try, but I have the following thoughts:

1. I think in acient time, people cannot get war result info
   and detail that much.
2. according to the first point and the post by tit b4,(about
   the spy ability), I think we can set some limitations to
   the war post.
3. set a para called sa(spy ability), and the sa has different
   levels regard to the nation's most recent 3 months' spy job
   number, if sa reach some certain level, the officers in that 
   nation can read some certain war_post.(here officers exclude
   ��ְ).
4. suggestion of sa level and war_post level:
   spy jobs done    sa level    war_post readable level
 in last 3 months
   150               30                all
   145               29     all except last half year
   140               28     all except last half year
   ...
   100               20     all except last half year
    95               19     only those concern to its nation
   ...
    50               10     only those concern to its nation
    45                9     none can be readable
   ...
     0               0      none can be readable

��������cannot read.:P

how do you guys think.:P


---
����: �һ�(fire)
��Ŀ: about the area_server
����: Sun Nov 21 01:42:20 1999
the total information (include the desc, short and obj list exit
list and so on) are stored under /data/area/
I find the total size of these data files is 336605
it is about 300K, so not very big. therefore
it may not the reason for that huge string memory
useage.



---
����: ����(flee)
��Ŀ: >> about hua tuo
����: Thu Nov 25 23:37:20 1999
the yao cao is quite heavy .. :)
if player carry too many stuff, the right one may not
move to him ..
i will reduce the weight of yao cao, anyway .. :)


---
����: ����(flee)
��Ŀ: >> whose char is this?
����: Thu Nov 25 23:35:44 1999
it is my char .. used to test jimou and zhenfu ..


---
����: ����(row)
��Ŀ: hua tuo job
����: Thu Nov 25 21:18:17 1999
hi flee, some players said that hua tuo job cannot be done properly, the tool
broke but hua tuo didnt accept none of the yao cao, would u please check?


---
����: �һ�(fire)
��Ŀ: about run out of file descriptor
����: Thu Nov 25 02:43:02 1999
I think that is the reason why i have changed the 
area room's from common file to virtual room
so for area, we just need open 2 files :)
but seem this doesn't help :(
anyway that is a strange bug. because as i know, there
is not a file close commond in this mud. so how could
close a file after open ?


---
����: ˹̹��(stefan)
��Ŀ: run out of file descriptors
����: Wed Nov 24 20:52:22 1999
Recently (yesterday and today), when the online players went up to around 50,
many system command fails to load because the mudos runs out of file
descriptors. I have increased the limit from 64 to 1024 now,
there should not be any problem for the moment. 

But the question is, how can we run out of file descriptors? there
must be some
thing wrong. Open a file but forgot to close? Should fix
things around.


---
����: ˹̹��(stefan)
��Ŀ: System Development
����: Mon Nov 22 05:25:12 1999
MudOS is already a dead project, nobody is really developing it. I am
afraid we have to shift our code base to the new LPC engine: Pike.
Pike is almost the same as LPC, but it is a complete and mature language.
It can be found at http://pike.idonex.se. Roxen is a great web server
written in Pike, and can be found at http://www.roxen.com. Both Pike
and Roxen are under GPL.
 
There are several reasons for doing this:
 
1. MudOS does not support access to database. 
 
   Our SanGuo mud has already shifted from traditional "one file one object"
   to a systematical daemon management system, such as the warmaps (442K),
   char daemon (700K), history daemon (174k), objects (151k). rooms (746k),
   news daemon (500k). MudOS is not designed for such kind of things, when
   it gets complicated, MudOS simple crashes. A database will boost the
   system performance by seperating out the data management part, Pike
   supports database connectivity to the database server MySQL.
 
2. MudOS does not intergrate well with Web.
 
   The HTTP daemon in Lima sucks because MudOS does not support
   multi-threading, and a simple query will greatly slow down the whole MUD. 
   Right now I am using Roxen to serve the San Guo's web page. It supports
   multithreading, and is the yet most flexible web server I've ever seen. 
   It performs very well, fast and stable. Have you seen the dynamic SanGuo
   newsgroup on the web page? I wrote it in Pike, which directly reads the
   "news_d.o" and "recent" under /data/news/ in our mud, without connecting
   to SanGuo mud.
 
3. MudOS prevents all MUDs based on MudOS from being commercialized.
 
   This is not a problem today, but will be a problem tomorrow, especially
   if we are moving towards a Graphical San Guo client, which is not a very
   hard job in my humble opinion. A Java Applet based client is quite easy
   to work out, and as you may have seen the Telnet Applet on SanGuo's web
   page, the display and input problem both have been solved. A simple idea
   to start with is to have a graphics+text combo. For example, the first
   graphical thing can be the map, and the war can be done graphically too
   (since it is already semi-graphical right now :), and the command and
   chat part we leave it as text based. Later this combo can be improved to
   a full graphical client.
 
However, with all the above said, it can not be done quickly in the near
future. We need some time to research all the possibilities. I think 
to open up Lima Lib and manage an open source project is the first step.
We will learn, and we will get the experience. If it goes well as expected,
we can move into the next era of San Guo development, i.e., to have a 
Pike based library running on a real database engine.
 
Though I mentioned graphical client and commercializing SanGuo, it would not
be an easy task, and that is also why I think open source is the model to
go. Unless there are enough solid developers of all sorts, ranging from
programmers and graphics designer to story writers, it will not be a
success. We are doing an Internet project, we need people to participant,
and by open source, we all benefit.
 
Hope we can meet the schedule and open up San Guo by April next year.


---
����: �һ�(fire)
��Ŀ: cpu useage
����: Tue Nov 23 05:35:35 1999

> CPU usage: 29.49%
Mud status is
Sentences:                            50      800
Objects:                            3664  1730048
Prog blocks:                         775   988784
Arrays:                            33447  1707748
Mappings:                          71738  6963740
Mappings(nodes):                  158947
Interactives:                         44   278784
Obj table overhead:                 6004   261964
All strings:                     108353  2530182 + 552748 overhead
call out:                            200     5600 (current length 128)
                                         --------
Total:                                   15020398
load average:
6.84 cmds/s, 32.44 comp lines/s
��Ʒ������3555
����������673
���ڷ���������506
���ⷿ��������778
daemon ��Ʒ������353
> time
����ʱ��                ��ʮ����ʮһ�¶�ʮ���������ʱ��ʮ����
����������              ��ʮ����ʮһ�¶�ʮ����������ʱʮ����
��������ʱ��Ϊ          һСʱ��ʮ��������


---
����: ˹̹��(stefan)
��Ŀ: cpu
����: Tue Nov 23 18:29:36 1999
CPU usage: 20.15%
Mud status is
Sentences:                            54      864
Objects:                            3697  1716280
Prog blocks:                         843  1079836
Arrays:                            32040  1735848
Mappings:                          70153  6827388
Mappings(nodes):                  156327
Interactives:                         46   291456
Obj table overhead:                 6004   255628
All strings:                     115211  2503762 + 584764 overhead
call out:                            200     5600 (current length 87)
                                         --------
Total:                                   15001426
load average:
6.01 cmds/s, 10.36 comp lines/s
��Ʒ������3467
����������678
���ڷ���������500
���ⷿ��������715
daemon ��Ʒ������320


---
����: ˹̹��(stefan)
��Ŀ: possibly the new server
����: Tue Nov 23 18:55:46 1999
please ping  63.194.210.134, and mail me the statistics you got.
Is it faster than the current one? 

It could be our new server, provided most wizs are happy with it :PP


---
����: ����(flee)
��Ŀ: >possibly the new server
����: Tue Nov 23 23:54:41 1999
ok for me, ... A_A


---
����: ����(row)
��Ŀ: about qb
����: Wed Nov 24 00:15:31 1999
now the qb is replaced by sc, but they r still taking salary, could fire
change it?


---
����: ����(row)
��Ŀ: about login numbers
����: Wed Nov 24 19:40:40 1999
today we met the same situation again, when ppl over 50, wiz cmds not working
anymore and bunchs of errors pop up, thats horrible.  so could stefan solve
this problem or just simply make the limit of login number, that is to say,
when there is 50 inside the game, no one is able to login any longer. is that
feasible, pls consider.
its urgent coz we r having more and more player everyday!!


---
����: ����(row)
��Ŀ: about login
����: Wed Nov 24 19:42:29 1999
its wierd that system counts someone in login process as a normal player
in the game, is that causing problem?


---
����: ˹̹��(stefan)
��Ŀ: re : file descriptor
����: Thu Nov 25 05:22:11 1999
I rechecked the driver.log, seems that the file descriptor problem
is related to socket fd, but not file fd. I made some change to
the driver, hopefully it shall not happen again.


---
����: ˹̹��(stefan)
��Ŀ: whose char is this?
����: Thu Nov 25 07:37:12 1999
info c fdummy
�����������ˡ���������������������ʡ���������Ѷ����������

��һ����Ѷ��
����ɫ���š�fdummy  ����    ��������    ��   ��   ������  
����    ��Ů      ����    �䡿14      ����    ò��26
�� ������ ����֮��(lsls)                ����    �ϡ�71
�� ���ڵ� �����(xuchang)
����͢��ְ������    ���ط���ְ��̫��    ��ٺ   »��20
����    ����100     ����    ı��100     ����   ����100
���������ס�0       �����ҹ��ס�0       ����   ������¶��â(345)
����    �͡����    ��״    ̬���    ����   ������    
����������ϵ��
�����Ƶ۹����� 31   ��  ���Ϲ����� 19   ��    ������� 59 
��  ���������� 28   ��  ��֮������ 39   ��  ���ȹ����� 59 
��  �һ������ 29   ��    ������� 15   ��ĩ�յ۹����� 57 
��˽����װ��
���ױ�������0                           ��ѵ   ����1
����    ƥ��0       ����    ����0       ����   ʳ��0       
����    �����
�����ﰤ��������¡�


---
����: ����(row)
��Ŀ: ������������
����: Fri Nov 26 23:30:58 1999
��Ҷ����������������˰ɣ�������������ԭ������������������
�Ǿ�������ϣ�������������Ρ������������ڻ�û������������ܣ�
��������������ѡ��
һ�������������ã�flee�Ѿ�����surrender�ˣ�����Ҳ����̫�鷳�ɣ�massage flee...
�����������е�Ͷ����������������ĳ�ض�����Ȼ����ʱ�ſ�Ͷ��Ҫ����
�����������ٹ�Ͷ����

�����Ա���Ϸ��Ӱ���ǱȽϴ�ģ������Ҹ���ϣ������������Ҫ������
������λ����Ҿ�����Σ�



---
����: ˹̹��(stefan)
��Ŀ: sanguo map
����: Sun Nov 28 03:57:51 1999
I've put up a simple map on the web page, please take a look.
Because it is too simple, it does not look very nice. It will
be better if somebody can use a real map from sanguo game or some
other places to be the background. Or draw borderlines to 
distinguish provinces.

Ice can take over from here? :-)


---
����: ����(ice)
��Ŀ: about the whole_map
����: Tue Nov 30 03:02:33 1999
I'll try to take it over, but don't expect I can finish it by next century..:P
Bcoz I cannot have much time to login, if u have some urgent msg to me, like
site moved, ice's been taken by hacker... blah blah.... mail me at
tom811@163.net
I may check mail at least every week...:P
God bless me that i can deal with photoshop ...:)
addoil all guys 
yours
ice


---
����: ����(flee)
��Ŀ: about chanrang
����: Mon Nov 29 23:01:16 1999
i have coded a chanrang program, which is a new function
of national meeting. check /wiz/flee/chanrang.c for details.
it is not finish yet, cos i dunno how the /secure/daemons/suicide_d
works .. 
please check it for any potential bugs.


---
����: ����(row)
��Ŀ: about old posts
����: Mon Nov 29 01:17:52 1999
today i downloaded the archive of caolu's old posts, a 652k txt
file...faint...
i checked half of it and now i am a little bit dizzy..:( i found
some posts r messed
up but i hope we didnt missed some good ones. i copied several lines
and saved for
record. after finishing the adjustment, i will email them to stefan
to help him to
implement the history affair part of sanguo's web page.

p.s. from those posts i can see a mud from a very beginning growing up to a
under-mature one, what a exciting experience!


---
����: ����(ice)
��Ŀ: I checked the current whole map in web
����: Tue Nov 30 22:21:53 1999
A graphical map will be much better but...
seems cannot perform the color difference by different country
as map main can do now into the graphical map..:P
forgive me..:P


---
����: Stefan
��Ŀ: >I checked the current whole map in web
����: Wed Dec  1 08:07:19 1999
On Wed Dec  1 01:21:53 1999 ����(ice) wrote post #889:
> A graphical map will be much better but...
> seems cannot perform the color difference by different country
> as map main can do now into the graphical map..:P
> forgive me..:P

oh? I thought that map on web is leady using color to differentiate
countries? 


---
����: �ֳ�(lch)
��Ŀ: kick ice
����: Thu Dec  2 03:10:46 1999
kick ice
nip ice
bite ice


---
����: ˹̹��(stefan)
��Ŀ: board bug
����: Thu Dec  2 08:51:13 1999
seems board does not check for the permission put on the newsgroup.
If you use news, groups "wiz.*" will only be read by wizards.
how come lch can read the board here? :)
*slogan lch


---
����: ����(flee)
��Ŀ: bug log
����: Wed Dec  8 20:24:24 1999
[errors] ((none)) Error logged to /log/runtime
[errors] *Array index out of bounds.
[errors] /daemons/warai_d (daemons/warai_d/automatch.c) at line 11


---
����: ����(flee)
��Ŀ: findfile -u
����: Tue Dec  7 23:03:15 1999
it semms that findfile's data is out of date
can any admin update it .. *hoho


---
����: �һ�(fire)
��Ŀ: to row
����: Sat Dec  4 15:38:04 1999
Hi, row
I copied m_pushable.c to /std/modules
you can test now :) addoil
in fact you can test even the m_modules under your directory
just in the inherit give the full directory.

anyway, if you need the privilege for /std/modules
just tell me.


---
����: ����(row)
��Ŀ: training has bugs?
����: Sun Dec  5 01:48:20 1999
several players reported that training got bugs, such as:
missed enemy troops, cannot order npc troops, pls look into it.


---
����: ����(ice)
��Ŀ: suggestion ofinfo h
����: Fri Dec 10 18:53:41 1999
1. should be viewed by the order of levels.
2. the price should be viewed together with unit of gold, otherwise player can
say that's silver.:P

I am interested to make some rules of real estate agency later, after I finish
the ma on web

using telnet now, maybe not so good posting.:P
excuse me.


---
����: ����(ice)
��Ŀ: who can give me a �й�����ͼ
����: Fri Dec 10 10:56:48 1999
I cannot find it by myself, if sb can find it, pls
send to me in jpeg format.:P
I think draw on real map will be better.:)


---
����: ����(yuyin)
��Ŀ: %^RED%^what is this %^RESET%^
����: Mon Dec 13 21:13:14 1999
���λ��   sg.sq.sh.cn ��һ��
���ǲ������ǵľ���
*wa
*oh


---
����: Fire
��Ŀ: >%^RED%^what is this %^RESET%^
����: Tue Dec 14 02:23:22 1999
On Tue Dec 14 00:13:14 1999 ����(yuyin) wrote post #901:
> ���λ��   sg.sq.sh.cn ��һ��
> ���ǲ������ǵľ���
> *wa
> *oh

I think that is the canada sanguo's page.



---
����: ����(yuyin)
��Ŀ: something
����: Tue Dec 21 02:53:52 1999
i think loveui  �������
����ֱ����̫������
��Ȼ post ��ô�ණ������ wizard
�Ҿ�����̫�������޿�����
���Ƕ��ǳ�ʱ���Ǯ��Ϊ��ҽ������ǵ� mud ����
������ʱ�����»����һ��
�����Ǿ��Կ��Ե�Ǹ
�� loveui ȴһֱ�������� wiz
�� fire ��һ��ʲô�ͷ����������ǵľͶ����û���
�Ҵ�������������Ϸ���κεĸĶ�
��Ϊ��������������������funtion �Ҷ����ǵ�
�� fire row flee group ice �ȸ��Ӳ��������κεĸ���
so i think ��Ӧ����һ�����
sigh
�� fire ��һ��


---
����: ����(row)
��Ŀ: ideas
����: Mon Dec 20 19:37:37 1999
�ǵ���ǰ�����и������оȻ���������ĳЩԭ����˴�Ȼ���
���������ˡ����ڲ����û������ԼӸĶ�������������һЩ����
������Ĺ�����������ԵķŻ�ȵȡ�
��Ҫ���뷨�������ģ����Ա�һ���С�Ǳ�С�(stealth) �ļ��ܣ�
һ��ʹ�óɹ��������ڸ�ԭ������֣���Ϊ����һ���ˣ��ͺ���
�������С�����ߵĹ���һ�㡣�������������( ������漰��
ȫ�ԵĻ�����Ϊ�޸�id���ܻ������bug)�������cast stealth
ʱ������һѡ�����г������װ��ɵ������ƤС�к�(boy)��
���߹�˫(oldman)��С������С��(girl)�ȵȣ�ѡ��󣬽�����
Ϊһ����������CHAR_D�У�
CHAR_D->set_char(id,"ste_tar","��ƤС�к�(boy)")
Ȼ������������ʹ��look��id����ʱ���������÷�������
��ʹ����stealth ���ܵĻ�����ʹ�øò�������ʹ���ߵ�title��
name��id���ü��ܵ��ô��ǿ������ε�ִ��һЩ��������񣬱�
���ƻ��й������������ӱ�cmd catch ����Ȼ����ԵĻ�����
��һ����̽�⡹(probe) �ļ��ܣ�һ��ʹ�óɹ����÷����ڵ���
����������ȫ������
���������������Ĺ����ͺܶ��ˣ���ʵ���ƻ��Ե��ڳ��ڷŻ�
��ˮԴ���¶��ȵȣ�����Ӧ�ľȻ𡢽ⶾ��
������ÿ��������һ����ͷ(�൱��Ѳ��)�����ƻ������У�����
����ʧ�֣�ʧ�ֵĻ��ͻᱻͨ��������ͷ������ץ�������ؾ�һ
Щ������ҹ���һСʱ��Ϳ��Ե�ĳ��ȥȡ��ͨ���ļ�¼��

��֪��������д���Ƿ���С�



---
����: ����(ice)
��Ŀ: one strange thing
����: Mon Dec 20 12:39:06 1999
so far in my mind, LULING is not a very large city, and
I remember in my orginal city setting and map drawing it
should be a lv 2 city sth, bcoz I am drawing the web-map,
I found it's different from the orginal setting.
I think lv 2 is reasonal able lv for LULING, so if sb 
has time, pls change it to lv 2 in @AREA_D and LULING.map bah

I'll draw it in web-map as lv 2 city at present, if sb can
persuade me that it should be a lv 4, I'll take my difficulty
to change it in my web-map then.:P

ps. I think there can be many relative things to be changed if
change LULING's lv, like officers' position para, take care bah.:P


---
����: �һ�(fire)
��Ŀ: disable and enable players channel privilige
����: Mon Dec 20 05:45:33 1999
@.xxx->disable_chan() to disable
@.xxx->enable_chan() to enable

addoil;)


---
����: Flee
��Ŀ: >about the whole map
����: Fri Dec 17 20:35:27 1999
On Fri Dec 17 11:42:05 1999 ����(ice) wrote post #904:
> Since seems no one can provide me a chinese ground map, I will
> have to do it by adjusting the Koei's game map now, pls don't
> scold me if it's ugly...:P
> 
> btw  I am now really very very interested in the real estate business,
> and I'll write a plan about it in detail.:)
> 
addoil ice, massage ice, hurry ice


---
����: ����(ice)
��Ŀ: about the whole map
����: Fri Dec 17 08:42:05 1999
Since seems no one can provide me a chinese ground map, I will
have to do it by adjusting the Koei's game map now, pls don't
scold me if it's ugly...:P

btw  I am now really very very interested in the real estate business,
and I'll write a plan about it in detail.:)



---
����: Ice
��Ŀ: >%^RED%^what is this %^RESET%^
����: Fri Dec 17 08:38:33 1999
It is mirror site of canada sanguo's homepage, and it's closed.:P


---
����: ����(ice)
��Ŀ: about mysterious
����: Sat Dec 25 13:05:12 1999
��ѷ�������û���⣬�ɵ�Ӧ�ò������������ܲ��ܸ��Ҷ������ӣ��ҳ�ȥ��Щԭ������
�俴��
bcoz now the cooker can copy food obj, the mysterious is unlimited
food, thus I removed this obj, but in the cooker's record, it's still
there but cannot be made.  fire, can u remove all the record
of mysterious from cookers who know how to copy it?


---
����: ����(ice)
��Ŀ: seems a bug in marriage
����: Sat Dec 25 12:44:15 1999
seems jiaofu tou cannot move northeast......
answer northeast to jiaofu tou, ������Խη�ͷ�����northeast
�η�ͷЦ�����ã��ã����Ǿ���northeast�����ߡ�
[errors] ((none)) Error logged to /log/runtime
[errors] */sgdomain/modules/char_server/jiaofu tou is not known by the parser.
 Call parse_init() first.
[errors] /sgdomain/modules/char_server/jiaofu tou (sgdomain/modules/m_char.c)
at line 39
answer northeast to jiaofu tou, ������Խη�ͷ�����northeast
�η�ͷЦ�����ã��ã����Ǿ���northeast�����ߡ�
[errors] ((none)) Error logged to /log/runtime
[errors] */sgdomain/modules/char_server/jiaofu tou is not known by the parser.
 
Call parse_init() first.
[errors] /sgdomain/modules/char_server/jiaofu tou (sgdomain/modules/m_char.c)
at line 39

fire pls chack it bah


---
����: ����(ice)
��Ŀ: about changing data
����: Sat Dec 25 11:45:56 1999
There is a player called ������(eat) asked me to change his age.
he said he was 18 but nothing married to him, and by accident his
passwd was pirated by others, and that char suicided, now he 
got a lover and wanna marry, but his new age is only 15, he asked me
to change, he said group recover his data except contribution and
age, after I got the reason, I changed the data.

Bcoz I am not familiar with cmds.:(  I used my dummy "Bingo" to test,
that's it.:P


---
����: ����(ice)
��Ŀ: to stefan
����: Sat Dec 25 10:14:30 1999
I have sent a package of pics to fire, pls check it if u
have got it.  There are some files in the zip file, one is 
main map, but it's without indication of different nations,
it's just a map..:P  and the 5 cities pics can be used to 
indicate different city levels, there is also a flag pic for
u if u need it to indicate different nations by using cgi,
I hope it can work for u.:)


---
����: Flee
��Ŀ: >how could there are two new npc countries ?
����: Sat Dec 25 06:56:22 1999
On Sat Dec 25 06:46:13 1999 �һ�(fire) wrote post #926:
> hi, everyon
> hi, everyone.
> today I find that there are two new npc countries
> ma wan and shen pei. How could npc create new nations
> anyone has any ideas ?
> 
> xixi:)
i guess player chan rang to npc .. hoho


---
����: Flee
��Ŀ: >����ս��
����: Sat Dec 25 06:54:59 1999
On Sat Dec 25 06:04:13 1999 �һ�(fire) wrote post #925:
> ��Ҳ֪����ı���Ͷ���ֻ��ս����ɫ��ࡣ
> ����Ϊս�����ֺܸ��ӣ�һ���޸Ķ����ܴ���
> ���BUG���������Ҫ��������������Ҫ�г��
> ��ʱ��;�����������û��ʱ�䡣flee��group
> һֱ������ı����ϸ�Ѿ������鲻���ˡ�����
> �����Ϊ���죬�Ϳ�����ʽ���š����flee��
> group���о���������������ж������ơ���
> ���԰�æ����һ��BUG�����پ������houseϵͳ
> ���������������غ���ҵ��
> row�����ʱ�䣬���Խ���fateϵͳ��
> regards
new semester starts next week, i and group will
be busy on our projects ... 
anyway, i will try stay online for at least one hour
per day.
about jimou, i agree with fire, there must be some unexcpetion
and may cause serious results ..
i plan to open jimou one by one, so we can reduce the damage ..
hehe

addoil all and will all of u a happy new mellinnium


---
����: �һ�(fire)
��Ŀ: how could there are two new npc countries ?
����: Sat Dec 25 03:46:13 1999
hi, everyon
hi, everyone.
today I find that there are two new npc countries
ma wan and shen pei. How could npc create new nations
anyone has any ideas ?

xixi:)


---
����: �һ�(fire)
��Ŀ: ����ս��
����: Sat Dec 25 03:04:13 1999
��Ҳ֪����ı���Ͷ���ֻ��ս����ɫ��ࡣ
����Ϊս�����ֺܸ��ӣ�һ���޸Ķ����ܴ���
���BUG���������Ҫ��������������Ҫ�г��
��ʱ��;�����������û��ʱ�䡣flee��group
һֱ������ı����ϸ�Ѿ������鲻���ˡ�����
�����Ϊ���죬�Ϳ�����ʽ���š����flee��
group���о���������������ж������ơ���
���԰�æ����һ��BUG�����پ������houseϵͳ
���������������غ���ҵ��
row�����ʱ�䣬���Խ���fateϵͳ��
regards


---
����: ˹̹��(stefan)
��Ŀ: sanguo's web page
����: Fri Dec 24 23:24:48 1999
sorry to row, the history part was not updated yet... 
Row has handed over to me quite a lot of material long time ago, I was
too papaya to make them on the web...*blush

Also, the map on the web currently got problem when countries
are more than 8.. I am debugging :PP


---
����: ˹̹��(stefan)
��Ŀ: I am back :)
����: Fri Dec 24 23:22:45 1999
Sorry for the long delay of pacakaging up mirror sites...
I am just back from a business trip, got sometime before year
end, so I guess I am now able to do something.

1. I've found a hosting place for San Guo, actually I've made my current
company to support San Guo hosting, so .. San Guo soon will be hosted
at one of the fastest internet datacenter : above net.

2. I was trying to get a website setup to host open source development,
but it was delayed quite significantly because I was too busy with work.
The web site should be up after new hosting site is confirmed.

3. Regarding mirror release, I will see if I can work out something 
before end of the year, initially we will only release encrypted mirrors.

4. Regarding our future development, the model will be what we've discussed
before, i.e., open up lima mudlib first, and see how it goes, also we
can accumulate some experience in managing open source development.
Later we will think of graphics java client or new server end based on pike.


---
����: Flee
��Ŀ: >to flee
����: Thu Dec 23 21:53:20 1999
On Thu Dec 23 11:45:55 1999 ����(row) wrote post #919:
> there is a bug in learning skills from xianren, if player doesnt
> have enuf money to learn the skills and still type "yes" when asked,
> system says "��û����ô��Ǯ" but player still get skills point...
> flee pls check it.
> btw: only works for under 30 levels study
fixed .. hoho


---
����: ����(row)
��Ŀ: ���ڱ���̫����
����: Thu Dec 23 21:48:27 1999
ǰ�����һЩ��������ģ����Ƿݷݱ�ʾ��������--ѵ��--ս��������
��̫������ʱ��һ���������ʧȥ��Ȥ�����룬��ıϵͳ�Ѿ�����
�ˣ����ŵĻ��ؽ��ḻս�����̣�ϣ���������ܿ������ǻ����Ը�����
�ҵĽ������Ƽ��������ķ�ʽ�����⣬����ϵͳ�ǲ���Ҫ�Ȼ���ϵͳ
��ɺ��ٿ��ţ��ܷ��ȿ�������͹����أ��Ͼ�������ǰ�й���ҲӦ
���ܷḻһ��ս��ϵͳ���һ��㿴��Σ�


---
����: ����(group)
��Ŀ: login
����: Thu Dec 23 21:06:06 1999
hmm.. it seems that some one try to login group from same place where i am at
Nov 18, it is quite strange... i have change the passwd.

group


---
����: ����(row)
��Ŀ: to flee
����: Thu Dec 23 08:45:55 1999
there is a bug in learning skills from xianren, if player doesnt
have enuf money to learn the skills and still type "yes" when asked,
system says "��û����ô��Ǯ" but player still get skills point...
flee pls check it.
btw: only works for under 30 levels study


---
����: Row
��Ŀ: >>about wan's reward
����: Thu Dec 23 08:04:26 1999
ok, no problem, so group set it bah.
btw, have to make a post to let players know, or they will...hehe
escape


---
����: Ice
��Ŀ: >about party
����: Thu Dec 23 04:19:55 1999
I think party in particular time is reasonable.:P
and if only regulate it by time from one to another, ppl can
gain food too much by changing his city.:P


---
����: Ice
��Ŀ: >ideas
����: Thu Dec 23 04:17:26 1999
I suggest if use "cast stealth", this id should have some kind of slowness
in action, bcoz if the officer in the city wanna catch him, he have to
"probe" first, and probe should cost some time, so it'll be more fair to both
sides.:P
*support row
:P


---
����: �һ�(fire)
��Ŀ: about wiz's passwd be hacked
����: Thu Dec 23 03:08:53 1999
I think it is better to check if you are hacked
or not
goto to the /log directory
use the following command
find -in "xxx ������Ϸ��" logins
xxx is the your id. 
then you will get a list of all login record and
check if there is some one login from other
site. 

if find that, please report and change the 
passwd immediately


---
����: Fire
��Ŀ: >about wan's reward
����: Thu Dec 23 03:02:52 1999
On Thu Dec 23 04:36:34 1999 ����(group) wrote post #913:
> i have agreed that give her a chinese garden house for her data of
> clothing, and i think 
> row also knows that. it is ok to give her the house? or cut the
> house to about 15 rooms?
> wait for answer. thanks
> 
> group

for person reward, that is ok lah :)


---
����: ����(group)
��Ŀ: about wan's reward
����: Thu Dec 23 01:36:34 1999
i have agreed that give her a chinese garden house for her data of
clothing, and i think 
row also knows that. it is ok to give her the house? or cut the
house to about 15 rooms?
wait for answer. thanks

group


---
����: ����(group)
��Ŀ: re party
����: Wed Dec 22 06:13:56 1999
can be sure... i put the limitation in the certain month it is because 
it is easy to control and give players a time feeling..:) if you
want, i can change it 
to time duration for sure..:)


---
����: �һ�(fire)
��Ŀ: about party
����: Wed Dec 22 05:02:55 1999
I think we may just limit the time span from one party to
another, unnessary must be in perticula month

how about this, group :)


---
����: �һ�(fire)
��Ŀ: new log file
����: Wed Dec 22 04:42:05 1999
the file /log/call record all the direct call
from wiz.


---
����: �һ�(fire)
��Ŀ: about the nation reward
����: Mon Dec 27 16:33:13 1999

that is right, when a player change to new country
his nation contribution will begin from zero but
the record of how much contribution has been award will
keep. this will couse that player lose some award after changing
nation. it is a way of penlty for betray. But maybe too much
later we will modify it so it is more fair.


---
����: ����(group)
��Ŀ: about login player
����: Sun Dec 26 22:43:02 1999
today when i finger, find a example
Login          player      56m  63.194.20.87
is that possible to idle 1 hour when login?....or something wrong?

group


---
����: ����(row)
��Ŀ: a bug in pos/i
����: Sun Dec 26 07:10:17 1999
there is a bug in king rewardind player function, i didnt check
the code, but i think fire might stored the old nationdistribution
in a para and match the new one each time, if bigger than 50, then reward.
the problem is, when a player changes his nation, his nationdistribution
will be re-count, so he have to wait for his record catching up the old
data to get the reward, that is surely a bug.  since we never deduce
nationdistribution, so i suggest, when the new nationdistribution is less
than the old record stored in the para, make the old record as zero.
dunno if its workable, fire pls check it.


---
����: ˹̹��(stefan)
��Ŀ: is it our code?
����: Sun Dec 26 06:00:10 1999
��  ��: ����Ҷ�����Ҳ��.  ��������Mud_Wizard[ ����������]  

����: onlymud (ֻ�����)  ����: 1999.12.25 20:18  
-------------------------------------------------------------------------
�����������Ѹ���lima �ܹ�������,�°��,���Խ���˵��,��£���������, 
ֵ��wizsѧϰ,�뻻sj��lib,��ӭ���Ž���/����lpc����.
chat* welcome all     
�� ��Դ:�������������� http://club.netease.com��[FROM: 202.102.254.80] 
--------------------------------------------------------------------------

xwin saw it and forwarded it to me. 

currently I do not think this is a big problem because we are going to open it
anyway.
But somehow it is still quite bad, at least hurt all wizs' feelings :P


---
����: ˹̹��(stefan)
��Ŀ: encrypted mirror
����: Sun Dec 26 05:44:24 1999
So far, I've successfully encrypted the *.c files and compiled a special
driver to run the encrypted mudlib. Those *.h files are not affected.

Also I need to get intermud protocol setup so that we will
know who are our mirrors. but that has got some problem :P lima bean
refuses to release their IMUD-3 server source code. I think I have
to work around it, maybe join current English IMUD-3, but filter out
English muds.

Thirdly, I am not sure how to clean up those daemon data files,
i.e., those *.o in /data, which should be reset, which should not?
need help later when I test the mirror site :)


---
����: �һ�(fire)
��Ŀ: a new command to check current tasks
����: Wed Dec 29 03:28:10 1999
task


---
����: ����(ice)
��Ŀ: bug in servant
����: Thu Dec 30 09:19:33 1999
when u call ur servant, only b&c works, all others say there
are bugs......:(
fire pls check it.:P


---
����: Row
��Ŀ: >bug in servant
����: Sat Jan  1 00:55:00 2000
sorry, its me who edited the file for servants, free_menu.c, gj_menu.c
and nwj_menu.c, i tried to let the married couple have the same
previlage to order the servant, but seems there is sth i cannot figure
out.  fire pls check it for me and tell me whats wrong. thanks.
sorry for bringing inconvenience.


---
����: Row
��Ŀ: >web page
����: Sun Jan  9 19:01:22 2000
where is my novel....:(
since the first edition of posts is ok, i'll put my hands on second one lah.

BTW: i think the dark background is good.  somehow remind ppl that sanguo
is a serious topic...hehe, how do u think?


---
����: �һ�(fire)
��Ŀ: good work, stefan
����: Sun Jan  9 14:34:57 2000
addoil


---
����: ˹̹��(stefan)
��Ŀ: web statistics for fun :)
����: Sun Jan  9 10:20:27 2000
page             view
------------    ------
history.html      253
enter.html        371
news.html         523
index.html       1308
map.html         3239
post.html        4638
help.html       17148

seems most people are only interested in help files :P


---
����: ˹̹��(stefan)
��Ŀ: web page
����: Sun Jan  9 10:12:18 2000
Just uploaded the history part of the web page.
Up to now, the web page has all parts, some improvement are still
needed. But roughly, the whole structure is like that.

I feel that the background is too dark, anybody share the same
feeling? Is it a good thing or bad thing? When I started, I followed
the old page to use dark background, but after browsing through
XKX and XYJ's pages, I feel ours is pretty dark :P

also the presentation needs more work, e.g., some graphics, nicer
layout and color arrangement, etc etc. I am not a web page specialist
and I need help!

anyway, let's leave it there until re-open. I am still bugging the
system admin to get server located and set up before 14th.
We shall see the outcome.

finally, thank row for the hard work in organizing all the
historical documents!


---
����: �һ�(fire)
��Ŀ: the restart part is ok
����: Wed Jan  5 03:43:22 2000
not test yet, and can't test now :(


---
����: ����(ice)
��Ŀ: about reallocation of nations in restart
����: Sun Jan  2 10:40:33 2000
Well, I do think only 3 nation in sanguo world can be a good
phase, maybe we can have multi-allocation restart plans later.
However, I don't think I can have enough time to design a 3 nation
allocation right now, bcoz I have got many tasks in my job and I
have to finish them as soon as I can.  So I am afraid that I
cannot finish that plan in time by 15th Jan, how about just let
those former player nation be taken by NPC randomly, or make them
to randomly assign to wiz.:P

Anyway, I will try, but it'll be better to prepare both hands by
restarts.

regards
Ice


---
����: ����(ice)
��Ŀ: about nationmeeting
����: Fri Jan  7 12:46:48 2000
I think players r familiar with nationmeeting now, and I found
one thing that can ignore the voting effects:
bcoz in the beginning of introducing nationmeeting, we didn't
set any limit on nationmeeting and no reward nor penalty for
suggestion approved or denied, so if a player insist to
do some transfers, he can just keep using nationmeeting
to achieve his goal, which can totally ignore the voting 
effects in meeting.

I suggest to add a time limit for nationmeeting,
like at most once per day or 2 days...:P
how do u guys think?


---
����: Row
��Ŀ: >house bug
����: Wed Jan 12 19:41:11 2000
On Wed Jan 12 21:12:56 2000 ����(row) wrote post #957:
> player reported house upgrade doesnt cost money, maybe a bug, pls check.

i tested, updating from palate to castle only cost me 10 gold...


---
����: ����(row)
��Ŀ: house bug
����: Wed Jan 12 18:12:56 2000
player reported house upgrade doesnt cost money, maybe a bug, pls check.


---
����: ����(ice)
��Ŀ: about document in web
����: Wed Jan 12 15:34:43 2000
the structure of document in web seems too flat,
when I open all sub-directory, the web page becomes too
long and seems it's hard to find exactly what i want.
I think maybe we can use the structure of yahoo,
like when u browse a subdir, u'll get into it, and
all subdir or documents under that dir will be shown,
and there is a return button in each page, thus when the
reader wanna back, press "return" then will goto the
upper dir.

I am not familiar with web developing, just advise.:P


---
����: ����(ice)
��Ŀ: bug? bug? bug?
����: Wed Jan 12 14:55:24 2000
> ��һ�ش��㣺�� bug �ɣ� �κ��˿��Զ������κ��˿��Ե��߼����ҹ�Ա
info c fyi
��һ�ش��㣺���� fire ����� �� ��)
*smirk
......


---
����: ˹̹��(stefan)
��Ŀ: server relocation
����: Wed Jan 12 03:18:07 2000
I am sorry that the server can not be changed this week.
Because there are some technical difficulties and lots of things
are happening, it is significantly delayed. 

I guess we have to stick to current server for the moment, the
reopen can be on 15th, but still with current machine.



---
����: Fire
��Ŀ: >a serious bug in job system
����: Tue Jan 11 04:44:32 2000
On Tue Jan 11 03:33:14 2000 ����(row) wrote post #950:
> today pangtong reported a serious bug in job system:
> when a player asks taishou for credit after finishing his job, the taishou
> disconnect(they use dummy as taishou, so they do it intently), but the
> player still get questions to answer and will be rewarded. thereafter,
> they login taishou again and ask for the same job, they will get another
> chance to be questioned and rewarded. so they keep doing it for adding about
> 100 literate and skills exp as much as they want.  i think this is aweful,
> fire pls test and correct it bah.

this bug is fixed, but haven't test yet. counld you please
ask pangtong to test if he want the 5 level stuff.
cheers :)


---
����: �һ�(fire)
��Ŀ: the bug for system can't clear house
����: Tue Jan 11 04:36:00 2000
has been fixed by adding some clean function in llb


---
����: Fire
��Ŀ: >re-open
����: Tue Jan 11 03:57:58 2000
On Mon Jan 10 21:32:19 2000 ˹̹��(stefan) wrote post #949:
> fire, would you please list down the steps for clearing accounts, reset
> deamons, etc?
> Because I am preparing mirrors, need to reset everything, but dont really
> know what are the things to be reset.
> 
> Thanks!

The process of clear up
1  use admtool to purge all the users
2  modify the function of clear_players() in 
   /daemons/restart_d.c to enable it.
3  run @"/daemons/restart_d"->clear_player(), maybe need
   several times if you meet too long evaulate error, when you
   receive the message done, then it will be ok
4  run @"/daemons/restart_d"->restart()
Bugs: 
1 some users may login before our system's crush and
  haven't login anymore, his record may can't be purged
  by admtool's purge according offline date
2 the record of house can't be cleard by purge the player
  or remove the char from char_d. we may need some clear code
  in ³ľ��
3 several functions in the restart_d haven't been test, they
  may have bugs
Suggestion:
1 first time we just open one mirror, and stefan and I will
  have admin account in the mirror for at least 1 month to 
  handle problems.
2 for the following mirrors, I think for each mirror, we need
  take care of it, if it run badly, it will hurt our reputation.
  so I think at least one of our wizs should have an admin account
  in there and deal with bugs and other problem.


---
����: ����(row)
��Ŀ: a serious bug in job system
����: Tue Jan 11 00:33:14 2000
today pangtong reported a serious bug in job system:
when a player asks taishou for credit after finishing his job, the taishou
disconnect(they use dummy as taishou, so they do it intently), but the
player still get questions to answer and will be rewarded. thereafter,
they login taishou again and ask for the same job, they will get another
chance to be questioned and rewarded. so they keep doing it for adding about
100 literate and skills exp as much as they want.  i think this is aweful,
fire pls test and correct it bah.


---
����: ˹̹��(stefan)
��Ŀ: re-open
����: Mon Jan 10 18:32:19 2000
fire, would you please list down the steps for clearing accounts, reset
deamons, etc?
Because I am preparing mirrors, need to reset everything, but dont really
know what are the things to be reset.

Thanks!


---
����: Stefan
��Ŀ: >about the rules for opening mirror
����: Fri Jan 21 11:07:58 2000
On Thu Jan 20 18:10:56 2000 �һ�(fire) wrote post #993:
> I agree with stefan's post
> but don't know how could control the mirror if it
> doesn't following our rules?
> do we have any way to terminate the mirror ?

the internal thing works this way:
1. driver hard codes the mudname and ip of the server;
2. mudlib requires frequent auto-update;
3. if a mudlib is not updated in 1 month, the mud will refuse to start;
4. if a mudlib is runing on a different ip, the mud will refuse to start;
5. if somebody runs a pirated copy, cases would be:
5.1. if he connects to internet, his ip will be different from the original;
5.2. if he does not connect to internet, he has to modify his machine time;
5.3. if he does not connect to internet, and he modifies his 
     machine time, just let him run the pirated copy :)
5.4. if a pirated copy every gets on the internet, it will leave a 
     record in the intermud data, we will be able to find out which
     copy he has got from, because we have the mudname.
6. the least and worst case would be somebody actually decrypted
   the whole thing, and start to distribute free copies :PP


---
����: ����(row)
��Ŀ: a potential bug in war system
����: Fri Jan 21 00:06:11 2000
when attacking general assigning troops, if he put 0 soldier in
his group, which will not terminate the assigning progress at all, there
will be a problem when he finishes all and enters the battle field.
becoz the system checks if the leader got 0 soldier left, he fails
the war.  that is not a error in code, but i think there should be
some way to prevent this from happening. so we need to set a lower limit
of soldier numbers, 50, or 100...since we need at least 2000 soldiers to
attack.


---
����: �һ�(fire)
��Ŀ: panttong's bug
����: Thu Jan 20 15:09:37 2000
I got pangtong's two bugs
first bug:
��Сͳ˵������һ��������ҷֱ���һ���ųɹ���ת�ɷֱ��ڶ����ŵ�ʱ��
��reconnect,�ٺ�
> ��Сͳ˵�������Կ����ҵĵ�һ���Ž���ս�������ҿ��Կ������˵����зֲ������
ʱ���һ����Լ����ֱ���
��Сͳ˵��������wiz����֪������ζ��ʲô��
��˵����don't know.
��Сͳ˵����������ǽ��������ҽ�����ս���������ҵı���û�з��ꡣϵͳ
������ʾ��"����xxxxx��ʿ��xxxɱ����"
��Сͳ˵�������ҿ��Կ����о��ı������䡣���ռ�˺ܴ���Ȼ���
��Сͳ˵�����ҿ�����Ե��˵�λ�ü����ֱ���
��Сͳ˵�����������������ս��������˵���������bug�����Ǹ�����ս��
��ʤ�����ҿ��Լ��ٲ��ٵ���ʧ��(��Ȼ��ʵ�����̫��ĳ��⡣)
��Сͳ˵����cmd warinfo.
second bug:
��Сͳ˵�����ؼ����ھ�Ӫ�ֱ���ʱ����NPc�ƶ������󣬱���ĳNPC�뿪�˾�
Ӫ������ķ����ƶ��ͻ����
I don't think these two bugs are so fatal as pangtong claimed,
anyway I will check them and fix them soon
and give him two level of skill is good enough lah :)


---
����: �һ�(fire)
��Ŀ: about the rules for opening mirror
����: Thu Jan 20 15:10:56 2000
I agree with stefan's post
but don't know how could control the mirror if it
doesn't following our rules?
do we have any way to terminate the mirror ?


---
����: ����(row)
��Ŀ: war bug plus
����: Thu Jan 20 17:45:40 2000
�������ڷֱ���ʱ����ط����Ƚ���ս����Ȼ���ˡ���������Ȼ�õ�
�ǳأ��������ѷ���ľ��Ӷ�ʧ��Ӧ���Ǹ�bug��


---
����: Fire
��Ŀ: >war bug plus
����: Thu Jan 20 18:18:51 2000
On Thu Jan 20 20:45:40 2000 ����(row) wrote post #994:
> �������ڷֱ���ʱ����ط����Ƚ���ս����Ȼ���ˡ���������Ȼ�õ�
> �ǳأ��������ѷ���ľ��Ӷ�ʧ��Ӧ���Ǹ�bug��

I can't find this bug
can anyone test to check if it always this case, or this bug caused by
some other reason


---
����: Fire
��Ŀ: >bug log
����: Wed Jan 19 15:49:12 2000
On Wed Jan 19 00:24:38 2000 ����(row) wrote post #985:
> ���Զ���ͬʱ̽�á�ο�ʡ�ɿ��ͬһ��NPC������̫�á�

I think can't, can it?



---
����: ����(row)
��Ŀ: to fire
����: Wed Jan 19 05:05:40 2000
pls read mail.


---
����: Stefan
��Ŀ: >about loveyou's hack event
����: Wed Jan 19 03:41:29 2000
On Tue Jan 18 17:50:13 2000 �һ�(fire) wrote post #984:
> I checked loveyou's login records
> and find before monday, all login from 202.100.41.*
> and on monday and tuesday the login from 61.128.*.* and the last
> login record goes back to 202.100.41.*;
> seem his account has been returned. 
> anyway this is a serious problem :(

I already asked him, his previous password was "12345". That is why
easily guessed by the hacker. Actually, not hacker at all,
they are schoolmates :)


---
����: ����(row)
��Ŀ: bug log
����: Tue Jan 18 21:24:38 2000
���Զ���ͬʱ̽�á�ο�ʡ�ɿ��ͬһ��NPC������̫�á�


---
����: ����(row)
��Ŀ: is info o's restriction working now?
����: Sun Jan 16 22:47:22 2000
as title.


---
����: Fire
��Ŀ: >is info o's restriction working now?
����: Mon Jan 17 02:05:51 2000
On Mon Jan 17 01:47:22 2000 ����(row) wrote post #976:
> as title.

it supposed to work now, if you find it doesn't work
in some case, there must be a bug there.
addoil


---
����: Row
��Ŀ: >>is info o's restriction working now?
����: Mon Jan 17 18:03:31 2000
On Mon Jan 17 05:05:51 2000 Fire wrote post #977:
> On Mon Jan 17 01:47:22 2000 ����(row) wrote post #976:
> > as title.
> 
> it supposed to work now, if you find it doesn't work
> in some case, there must be a bug there.
> addoil

there is a bug, i found that every player with skills at 30 can
be pos to national officer which means the info o is not working.


---
����: �һ�(fire)
��Ŀ: I got the bug for position requirement
����: Mon Jan 17 19:28:07 2000
please 
hope it is fixed :)


---
����: �һ�(fire)
��Ŀ: the task system and exception handling
����: Mon Jan 17 20:11:13 2000
the task system is the most tricky part in this mud.
because a task is not a simple event, it is a sequence
of events and usually last several mins to even one
hour. And it may envolve many chars many players. and
it may affect their behaviors. In this situation, if we
except a task go through the way as we excepted, we need
to write our code very carefully. And in our system, a
char can't be within two tasks at the same time. so we need
to handle the priority problem. For example, when a ppl is
in a meeting, and other area open a war to this area, the
new war task will temerinate the meeting task immediately.
and the real situation may be even more complex. 
Currently, we just have following tasks, they are:
localmeeting, train, war and party. 
Because of the complexity of task system, it is full of
bugs. most bugs are created by exceptions. and a most
serious bug is that a task may can't terminated. such as
players are traped in the warfield for several hours and
a party last several SG month. In order to solve those exceptions
I have following suggestions
1 when you use an object (for example a body) should always check
  if it is still a vilid object. write code like:
  Example:
     if(objectp(o_officer)&&objectp(me))
         o_officer->targetted_action("$N smiles to $T\n",me);
2 for mapping, don't forget to check if it is a map unless you are 
  100% sure.
  Example:
     mapping trps=AREA_D->get_area("changan","troop");
     if(mapp(trps)) // don't forget this line
        footnum=trps["footman"];
3 for arrays make sure it is not an empty array. the following code
  is risky:
     chars=TASK_D->get_task(t_id,"chars");
     foreach(string s in chars) {
	....
     }
   a more safe way is:
     chars=TASK_D->get_task(t_id,"chars");
     if(sizeof(chars)) // don't omit this line, it may save many bugs
       foreach(string s in chars) {
3 and 4 will come tomorrow, boss is coming,
fear


---
����: ˹̹��(stefan)
��Ŀ: a bug found by xfan
����: Tue Jan 18 06:14:03 2000
���¡ʷ�����㣺���ָ�bug
���¡ʷ�����㣺������һ��̫��(�峤)�����ٸĻ�����Ȼ
��������
then two chiefs appear.


---
����: Row
��Ŀ: >a bug found by xfan
����: Tue Jan 18 06:19:03 2000
do they have the same power, or the fake one will be erased
after system refresh?


---
����: ����(row)
��Ŀ: rob's bug report
����: Tue Jan 18 06:35:53 2000
rob said when he was assigning troops to attack wan, the defend party
retreated, then after rob took wan, he found all his attack troops
were lost, is that a hidden bug in war system? fire check? hehe.


---
����: �һ�(fire)
��Ŀ: about loveyou's hack event
����: Tue Jan 18 14:50:13 2000
I checked loveyou's login records
and find before monday, all login from 202.100.41.*
and on monday and tuesday the login from 61.128.*.* and the last
login record goes back to 202.100.41.*;
seem his account has been returned. 
anyway this is a serious problem :(


---
����: ˹̹��(stefan)
��Ŀ: reward demand from pangtong
����: Thu Jan 20 07:11:59 2000
��Сͳ�����㣺��һ���Ƚ����ص�bug��������ս���ġ�
��Сͳ�����㣺������Ҫ����gҲ�ܴ�
��Сͳ�����㣺��Ҫ�Ľ����Ǳ����������������Ե�����������ҵ������츳��
��ش���Сͳ������Ҫ����Ľ�����
��Сͳ�����㣺����Ҫ�����ڵ���ѧ������70����
��Сͳ�����㣺��Ȼθ�ڴ���һ�㣬��������Ϊ���ṩ��bug������ֵ�õġ�
��Сͳ�����㣺������������࣬�������bug���֣��ɼ�wiz�ڰ�ȫ�ķ�����
              �滹����ô���©����ȷʵӦ�����Ҽ��֡�
��Сͳ�����㣺ս�޲�ʤ����֪�����bug�ļ�ֵ����
��Сͳ�����㣺Ҳ����˵�������ǲ���������ֻҪ���������bug���ﵽ����Ҫ
              ��Ҳֻ��ʱ��������ѡ��������ࡣ

so how? fire, make a decision bah :)


---
����: ˹̹��(stefan)
��Ŀ: mirror regulation for review
����: Thu Jan 20 09:11:30 2000
                      �й���������־��վ�������Ѽ��淶


����־��վ��������

1. �����߱���ӵ��һ̨�� Internet ���ӵ� Unix ����վ (Solaris, Linux,
   FreeBSD) �ȡ��ٶ�Խ�죬����Խ��Խ�á������߱������Ȼ�ô˹���վ��
   ������������������־��Ϸ����ɣ��ſ���������롣

2. ����������������־��վ�����ķ�վ���й淶�����Ρ�

3. ���з�վ�������ڼ��ܺ�Ĵ��룬��վ�����������α�֤�����ص���Ϸ��
   ���������κ���ʽй¶��ȥ������־����Ϸ���ֻ�����ڸ���վ����Ϸ��
   ;����վ���ý���ת�����˻������á�

4. ����־��վ��������ȫȡ������վ��������˫������Ը�������κ�һ����
   ӵ����Է������ֹ��վ���е�Ȩ�������Է������θ���ȫ��֧�֡����
   ��ֹ��վ���е�һ�������н���Ȩ��


����־��վ���й淶

1. ��վ��������Ȩָ��������վ�������ʦ��ѡ���������������ڣ���಻
   �ó������ˡ�����֮�⣬��վ�����ṩ������ʦ���輼���ϵ�֧�֣�����
   ����վ�����Է�վ����ľ���Ȩ��

2. ��վ��ʦר�Ÿ����վ�ϵ��������������������̼�����־�����
   ��չ����

3. ��Ϊ MudOS �İ�Ȩ���⣬��վ����ֱ�Ӳ����κ���ʽ����ҵ���ıȡ��
   ҵ����

4. ��վ��ʦ������Э���������־��Ϸ��֪���ȣ���Ϊ�����վ��Ϸ�����
   �ṩ��õķ��񣬰�����ά�ַ�վ�������У�����������Ҿ��ף��ȵȡ�
5. ��վ֮�䲻�������κδ�����ҵ��������롣

6. ���Ҫ�Ļ���վ�����е� IP ��ַ����Ҫ����վ�����ʽ���롣

7. ��վĿǰ�����ṩ��������Ϸ���׵���ҳ֧�֣���վ��ʦ�������������
   ��վ��ص���ҳ���ݣ�����ҳ����վ֮��û��ֱ�ӵ����ι�ϵ��


����־��վ�������

1. ������Ӧ��дһ����ʽ�������ţ��������������������ҽ��ܣ�����ԭ��
   �������ڷ�վ��Ϸ�ķ����������ã�IP���Լ�����״���������϶Է�վ��
   ���͹淶��ʾ���ص�������Ȼ��ĸ���support@gime.com

2. ����վ��ʦ���й�����ѯ�ʾ���ϸ��ʱ��������Ӧ�ü�ʱ����𸴡�

3. �����뱻��׼֮�󣬽����յ���������־��վ���������

4. ����������е�˵������ȷ��װ����������־��Ϸ��������л��ṩ��Ҫ
   �Ĺ��߰�����Ϸ�����У������Լ�ά����


---
����: ˹̹��(stefan)
��Ŀ: any comments?
����: Thu Jan 20 09:13:03 2000
Sorry for the long delay of our server relocation, will be done in these few
days.


---
����: ����(row)
��Ŀ: ��Ϸ����
����: Thu Jan 13 18:51:20 2000
������mud��ȡ�����Ҷ�ice�����������޸ģ���ҿ�����Ρ�

    �ƶ�����Ϸ�����Ŀ���ǣ���֤���������ҵ����棬ά��һ��
��Թ�ƽ��������Ϸ�������жԱ���Ϸ����Ĳ�ͬ����߾���ʹ����
�����԰����̶�ʼ��ķ�ʽ�����������һ�����뱾��Ϸ����������
�ر����򣬷�����ܵ�������  

    �����Ǳ���ϷĿǰ�Ĺ���

��  �����ƻ���Ϸ���е���ң���������Ϊ���ܻ�ӭ�ߣ�����أɣ�
    ��ַ���ᱻ�ܾ����ߡ�
        
��  �������ʹ�ú���Ϸ������������ͬ�������֣��������ʹ��
    �����Ի��ԡ��ַ��Ի������Ե����֣���ʦ�����޸Ļ�ɾ�����
    ���ֵ�Ȩ����

��  �����ڹ��û�˽��Ƶ��̸����˽���⣻

��  �Ͻ��ڹ��û�˽��Ƶ������������Ϣ���ƣ̣ϣϣģ���

��  �Ͻ��ڹ��û�˽��Ƶ�������԰�����������ң�������������
����ɢ��Υ�����ۣ�
    
��  �Ͻ�һ�����ͬʱʹ�ó����������ϵĽ�ɫ���ͣգ̣ԣɣ��̣�
    �ǣɣΣ������������ɴ���ɵ���ʧ��ʦ�������⳥��

��  �Ͻ��������������ϵ����ʹ��ͬһ����Ϸ��ɫ���ӣȣ��ңţ�
�����ɣģ����ɴ���ɵ���ʧ��ʦ�������⳥��

��  �Ͻ����ã£գ�Ĳ����֪�£գǲ������ɴ���ɵ���ʧ��ʦ����
�������⳥��

��  �Ͻ�����ͶƱѡ��Ȩɧ��������ҵ�����������

��  Υ��������Ϸ������������ʦЭ������ͨ���󽫿����ܵ�����
    �ͷ�������Ϊ����һ�ֻ����ϣ���

����������ͷ���

���������û���ʱ�ر�����Ƶ����������ͶƱ�򿪣���

�������������ָ���۳��ٷ�֮ʮ��

�������۳����н�Ǯ��

�������ݻ�װ�������ݣ�

��������ʱ�����þܾ����վ�����ߵ�Ȩ�����£��Ρ��ӣɣԣţ���

�����������������е������Уգңǣţ���

�����Ա���Ϸ���������ߣ�����Ƶ�ͼ���������ȣ�����������
�������鱻�����߽���ý�����

��  �ٱ��£գ��ߣ������ܻ�ý�����

���������影����

������������ҵ�ʱӵ�н�Ǯ�ģ�����������������Ǯ�������ó���
���������������ƽ𣩣�

������������ҵ��κ����ֻ���������ָ���ģ�����������������Ϊ
����������������

���������������ӵ�е�һ�ֻ�һ������װ�����弶������Ч����

���������������ӵ�еķ��ݣ��弶������Ч����

����������װ�����ݣ�


ע��������ʦЭ��ӵ������������Ϸ���򼰽������������ս���Ȩ��



---
����: ˹̹��(stefan)
��Ŀ: mirror
����: Thu Jan 13 20:55:14 2000
����վ��������������������һ�£����Ƶ� server Ū���˾�
���Ͽ���


---
����: ˹̹��(stefan)
��Ŀ: document listing
����: Thu Jan 13 20:59:22 2000
I will take ice's suggestion and combine them toteogether and make
some changes. I think one good thing about current method is that I can
actually listed out whatever I want to see in
one page.


---
����: ˹̹��(stefan)
��Ŀ: agree with row on rob affair
����: Thu Jan 13 21:25:40 2000
rob is not a bad guy in the first place. Also the whole thing was not
really started by him according to those who witnessed. I am tired
of finding out who is right who is wrong. Both rob and rulin said something
disgraceful, so I agree with row to close their chat for 1 week.

I think this can be a warning before the rule comes out, later we just stick
to
the rules.


---
����: ����(ice)
��Ŀ: about the penalty
����: Thu Jan 13 21:46:25 2000
since our rules is not ready in public, I agree
it can be a warning, just deduct some gold bah.:P


---
����: ����(ice)
��Ŀ: about restart
����: Thu Jan 13 21:48:01 2000
�޻������㣺what time new open?
have we announced b4?
* doubt


---
����: ����(row)
��Ŀ: a bug
����: Thu Jan 13 21:59:43 2000
info c xiahou shang
this npc's skills suddenly drop to a unreasonable level, whats wrong?


---
����: Flee
��Ŀ: >about the penalty
����: Fri Jan 14 01:14:24 2000
On Fri Jan 14 00:46:25 2000 ����(ice) wrote post #966:
> since our rules is not ready in public, I agree
> it can be a warning, just deduct some gold bah.:P
agree with stefan and ice ..


---
����: �һ�(fire)
��Ŀ: about y2k
����: Fri Jan 14 02:32:36 2000
����ʱ��    һ����һ��ʮ����������ʱ��ʮ��
seem our system can't calculate current date
grin :)


---
����: �һ�(fire)
��Ŀ: ����MUD����
����: Fri Jan 14 04:27:34 2000
����MUD����
    ��ӭ�������ǵ������λ���̶����Ϊ�����������ͥ�е�һ����ң�����Ҫ
    �˽ⱾMUD�����¡�Ҫ���ʸ��ڴ���Ϸ��������������ؽ��ܱ����µ�ȫ��
    ���ݡ�
    �������Ϊ���޷����ܱ����µ����й涨�����������뿪����Ϸ��������
    ���ڴ���Ϸ����ʾ���Ѿ����ܱ����µ��������ݡ�
�����ܸ٣�
    ���������ƽ�ȵģ��������������ڴ�׷��ʤ�����ɹ����Ҹ� ��Ȩ����
�����Ȩ��
    1 ӵ���ڱ�MUD��������ʱ�������߽�����Ϸ����Ȩ��
    2 ӵ���ڱ�MUD�����ù�����˽��Ƶ�����ɽ�������Ȩ��
    3 ӵ����ָ�������԰����Ե���Ȩ��
    4 ӵ��ʹ��MUD mail����Ȩ��
    5 ӵ��������BUG��ǰ���£�����ָ���ʧ����Ȩ��
    6 ӵ�����ܵ��������(����ʦ)�ĳ�����Ϸ��Χ���������򲻹�������ʱ��
      ��ʦЭ�����ߵ���Ȩ��
���ְ��
    1 ���ý����κ�Ӱ�챾MUD��ȫ��ת�������������������Ϸ�Ļ��
      ���磺hack������Һ���ʦ�����룬flood�ȡ�
    2 ���������κν���Ƶ�������԰��MUD mail��������һ���г�����Ϸ��Χ
      ����в�͸�����������
    3 ����ʦ���б�̺Ͳ���ʱ��������ʦ�İ��ţ���ҪʱЭ����ʦ������
    4 ����BUG����ʱ�������԰��MUD mail����ʦ�㱨����������BUGĲ����
    5 ������ʦЭ���ƶ���������Ϸ����
����������
    1 ����ڹ���Ƶ�������ۺ����԰�ĸ��˴��������£����Ȩ�鴴�����Һ�
      ��ʦЭ�Ṳͬ���С���ʦЭ����Ȩ���κ�ý���Ϸ���ͳ�����Щ��Ʒ��
    2 ����Υ�����ְ�����ң���ʦЭ�����о��棬������Ҳ�����ȡ������
      ��ȫ�������Ȩ�Ĵ��������̱�׼���������������
    3 ���ڱ�MUD�����⹱�׵���ң���ʦЭ����Ը���һ������������ϸ�ڼ���
      ����������
    4 �����µ��ƶ�Ȩ���޸�Ȩ�ͽ���Ȩ������������ʦЭ�ᡣ


---
����: �һ�(fire)
��Ŀ: �������µĽ���
����: Fri Jan 14 04:46:41 2000
row��iceд����ҹ��򶼷ǳ��ã�����֮�����Ǻ�����MUD��
��ʽ����һ�£��������ǵ�MUD�Դ���Ϊ�ص㣬�ڴ������ǲ�
��Ҳ��������һ����������ʽ�ء�
�ҵ������Ǵ���һ�׸�Ϊ���ӵķ�����ʽ��Ŀǰ����һ������
Ȼ�󻹿����С��̷�������������������ս��������<�ز�����
�ȵȣ��������������ɵķ�ͥ��������ϵͳ������������
��������ӵ�кܴ�Ĵ����ռ䡣
����һ�㣬��Ҽ��ì����MUD����õ��˷ܼ���grin:)
��������row��ice�۵㲻ͬ���ǹ���multi-login�������Ͻ�ֹ
multi-login�ǲ�����еģ�����Ŀǰmulti-login��û�д���
�ر������ѣ���һ���̶��ϣ�multi-login������MUD������
���ģ������Ҳ�ϣ������ֱ�Ӽӵ�������ȥ��ֹ��Ҳ��������
����������ϵͳ�����ǿ��԰���һ���Ƽӽ�ȥ������һ����
��ֻ����һ��ID��Ϊ�����ų�Ա�����ǿ���ô����


---
����: ˹̹��(stefan)
��Ŀ: a suggestion from wzc
����: Fri Jan 14 19:46:44 2000
today С��(wzc) asked me to help him with the askjob. Because
he mis-typed an answer, he used up his job quota but still could not get 
any promotion. So he has to wait another day.

I turned down his request. But he is proposing
a suggestion:
С�������㣺��˵������ÿ��ֻ����һ��������ܼӵط����ף�ֻҪһ���û�취������
�ܲ�������������С�������㣺����Ӧ�øĸĵģ�����Ӧ��һ����Զ������Σ�������
����������Լӵģ�
С�������㣺������Ϸ�Ŀ����ԲŻ�ߵģ�


---
����: ˹̹��(stefan)
��Ŀ: changes
����: Sat Jan 15 05:35:18 2000
I was cleaning up some files, and made the following changes:
1. changed #include "/wiz/fire/fire.h" to #include <sanguo.h> in some files;
2. copied fire's diaochan.c to /sgdomain/npc/, so that
   ./cmds/player/checkemote.c will not use object in /wiz/;
3. copied /wiz/flee/menu/charmenu.c and /wiz/flee/menu/warmenu.c
   to /sgdomain/menu/ so that ./cmds/wiz/chareditor.c and
   ./sgdomain/cmd/warcmd.c will not use object in /wiz/;
4. removed #include "/wiz/ljty/ljty.h" from all horses under
   /sgdomain/obj/horse/. Those horses orignally inherited M_HORSE_1
   were changed to inherit M_HORSE instead. Some adjustment are also made.
   I am not sure I did a right thing here, can anyone confirm is there
   any use of ljty's M_HORSE implementation?
5. /wiz/fire/obj/wear/skirt.c and /wiz/nono/obj/changpao.c are copied
   to /sgdomain/obj/cloth/torso/ because they are used in NPCs involved
   in marriage.
6. removed #include "/wiz/ljty/ljty.h" from ./std/indoor_room.c
And the following are still in question:
1. there is a string path = "/wiz/group/troops/" in /daemons/troop_type_d.c
   is there any particular reason for that?
2. ./sgdomain/npc/fire_officer.c still uses flee's extinguisher.c and
   fire.c, but they can no longer be found under flee's directory. I believe
   this error has caused lots of lines in the runtime logfile. Flee,
   please make some adjustment bah :)


---
����: ����(row)
��Ŀ: bug info
����: Sat Jan 15 22:24:33 2000
pls check this player--rowcry's info, he has unreasonable high
reputation and literate, he told me he used a bug but didnt tell
me the detail when i asked. so pls check his data and try
to find out the bug...

ps: this guy's main char is grow, he suicided but asked for recover
then, no wiz agreed...hehe


---
����: ����(ice)
��Ŀ: draft of help rules
����: Thu Jan 13 07:35:13 2000
    �ƶ�����Ϸ�����Ŀ���ǣ���֤���������ҵ����棬ά��һ��
��Թ�ƽ��������Ϸ�������жԱ���Ϸ����Ĳ�ͬ����߾���ʹ����
�����԰����̶�ʼ��ķ�ʽ�����������һ�����뱾��Ϸ����������
�ر����򣬷�����ܵ�������  

    �����Ǳ���ϷĿǰ�Ĺ���:

��  �����ƻ�����Ϸ���е���ң���������Ϊ���ܻ�ӭ�ߣ������IP
    ���ᱻ�ܾ����ߡ�
        
��  �Ͻ��ڹ���Ƶ�������԰�����������ң�������������ɢ��Υ
    �����ۣ�
    
    �Ͻ�һ�����ͬʱʹ�ó����������ϵĽ�ɫ����������

    �Ͻ��������������ϵ����ʹ��һ�������Ľ�ɫ��

    �Ͻ����� BUG Ĳ����֪ BUG ������

    �Ͻ�����ͶƱѡ��Ȩɧ��������ҵ�����������

��  Υ��������Ϸ������������ʦЭ������ͨ���󽫿����ܵ�����
    �ͷ�������Ϊ����һ�ֻ����ϣ���

        ���û���ʱ�ر�����Ƶ����������ͶƱ�򿪣���

���������������ָ���۳��ٷ�֮ʮ��

���������۳����н�Ǯ��

���������ݻ�װ�������ݣ�

        �ܾ����վ�����߽���������Ȩ����

�������������������е�����PURGE����

��  �ٱ�bug�ߣ������ܻ�����µĽ�����

        ������ҵ�ʱӵ�н�Ǯ��10%��50%��

        ������ҵ��κ����ֻ���������ָ����5%��10%��

        ���������ӵ�е�һ�ֻ�һ������װ�����弶������Ч����

        ���������ӵ�еķ��ݣ�

        ����װ�����ݣ�


    ������ʦЭ��ӵ������������Ϸ���򼰽������������ս���Ȩ��


discuss discuss bah.:P


---
����: ˹̹��(stefan)
��Ŀ: to flee and group
����: Sun Jan 23 21:07:14 2000
this server seems to be very fast for Singapore players, come on guys,
do some advertisement in NUS and NTU lah! 

Addoil!


---
����: �һ�(fire)
��Ŀ: About task boards.
����: Sun Jan 23 19:41:30 2000
We will seperate the development into different tasks. for each tasks,
we will have seperate task news group. It will be easier to monitor
the process of that task. If the tasklist in the wizcommit got no 
objection. I will create several task news group for current tasks.


---
����: �һ�(fire)
��Ŀ: About wiz countries
����: Sun Jan 23 19:32:36 2000
For testing purpose, I suggest we put all the wiz countries together
Now we have 3 wiz countries, they are located in xiangping, dingjunshan
and yunnan. I think it will be better to transfer the wiz country from
yunnan to beiping. can anyone to negotiate with the players to give the
beiping to wizs?
escape


---
����: ˹̹��(stefan)
��Ŀ: Ҷ�������㣺huayin��33��������????
����: Sat Jan 22 01:28:13 2000
guess this is the most frequently asked question :)


---
����: ����(group)
��Ŀ: hunluan move
����: Fri Jan 21 21:06:38 2000
fixed. now in hunluan condition cant move.


---
����: ����ү(suicide)
��Ŀ: ��Һ�
����: Thu Feb 10 21:18:27 2000
�ոճ�Ϊ��ʦ����
��Ҷ����գ�
i will do my best here.
addoil
)


---
����: Fire
��Ŀ: >about guard
����: Mon Feb  7 17:52:07 2000
On Mon Feb  7 14:44:54 2000 ����(ice) wrote post #1039:
> according to a player's post b4, I do agree the guard should be
> called ����Уξ, so should we change the name of guard to it?
> it's just 2 characters in changing guard.c bah, i guess.:P
> if no one has objection, I may do it later.:P

just do it :)


---
����: �һ�(fire)
��Ŀ: new ideas
����: Fri Feb 11 10:30:29 2000
this is part from other mud
> �����´��š���ʴ�ۣ��Ͼ������Ƕ���û���α�����ҩ��
> �����´��š�̫���Ͼ����У��У��������������һ���ɵ�������ʹ�˱������
> �����´��š���ʴ�۴�ϲ�����ã���������š�
> �����´��š�̫���Ͼ��ɻ����Ī��......
�����´��š���ʴ�۳�̾һ�������ǲ��ǣ����Ǽ��ǿ�����Խ��Խ�����ˣ�
����԰�����ˣ������������¹��ء�
> �����´��š�̫���Ͼ��ͳ�һ��«�����������
> �����´��š���ʴ�ۣ���ѽ��
> �����´��š�̫���Ͼ������ã���ô���ˣ���������ȥ���ҡ�
> �����´��š���ʴ�ۣ��������ˣ�����һ�ɵ���ٸ���һ�ž����ˡ�
> �����´��š���˵��ͥ������һö�ɵ���


---
����: ����(ice)
��Ŀ: about guard
����: Mon Feb  7 14:44:54 2000
according to a player's post b4, I do agree the guard should be
called ����Уξ, so should we change the name of guard to it?
it's just 2 characters in changing guard.c bah, i guess.:P
if no one has objection, I may do it later.:P


---
����: ����(ice)
��Ŀ: about prohabiting hackers
����: Mon Feb  7 14:14:13 2000
I think the way used in FY is good to prevent from hackers to hack
player/wiz's passwd easily.
when a new player logon the server, he will be asked to enter a
passwd that contains with Capitalized characters, uncapitalized
characters and numbers all together, it must increase the difficulties
of hacking other ppl's passwd.  If a player missed some of the above
requirements, he cannot enter the game.

PS. sth that's not involved with hacker:
as i indicated before, the same names of player with different id
may make the ppl confused, since our mud is going to spreadout all
over the chinese mud area, I strongly suggest to add a same-name-check
while a new player is trying to logon our mud.(ofcoz it can be the
same in different mirror or the host server.


---
����: �һ�(fire)
��Ŀ: help,help
����: Fri Feb  4 05:25:55 2000
the mud just crush every several hours, and can't
auto reboot. what's wrong ?


---
����: �һ�(fire)
��Ŀ: small bug
����: Sat Jan 29 15:36:17 2000
���о����ҵĶ��������ˣ������һ��ͬʱ����������ask guan about
pay�������ҵ������ˡ����㲻����bug?


---
����: ����(row)
��Ŀ: ��վ
����: Sat Jan 29 08:35:41 2000
��������һ�����㽭վ���˱�����Ķ�һ�룬�Ǻǡ�
��վ���ٶȶԹ�����˵���������������������Ǳ�������վ����
������ҵĹ�湤�����ѹ��������������


---
����: �һ�(fire)
��Ŀ: tips about clean up
����: Sat Jan 29 03:51:15 2000
if we want some obj (npc) not be auto clean up by
system. we need add one function in that obj(npc)
  int query_clean_up() {
         return 1;
  }
be careful to use this function, don't use it unless
it is necessary. because it can't be auto clean up
by the system. it will keep there all the time until
you dest it :(. so for obj of this type, make sure
the number of it cna't be big and the code will finally
destroy it


---
����: �һ�(fire)
��Ŀ: about task goups
����: Sat Jan 29 02:01:24 2000
now we have 8 tasks
and we will make more soon. so wizs
please post your post on related task group
and when you enter news
just type "go task" will list all the task groups
addoil


---
����: �һ�(fire)
��Ŀ: about the job of findbody
����: Sat Jan 29 01:59:44 2000
I checked the code and find it has no silver reward
I changed it so it will reward 3 - 10 silvers now
ice, please update the help file bah :)


---
����: Fire
��Ŀ: >>sgdomain/event/ev_bwdh/ev_bwdh.o
����: Fri Jan 28 23:16:59 2000
On Fri Jan 28 22:02:20 2000 Flee wrote post #1023:
> On Fri Jan 28 01:10:27 2000 ˹̹��(stefan) wrote post #1018:
> > Seems that BWDH's data is stored there, I think it is
> > not a good place to hold data. Why not move it to somewhere in /data ?
> agree, since not a few of events have a data file, i suggest
> create a event dir under /date dir, and put all event data file
> there.

I creaed the dir, :) 
addoil flee:)


---
����: ˹̹��(stefan)
��Ŀ: serious crash fixed
����: Sun Jan 30 10:13:21 2000
ZJ site repeated crashed because of a MudOS bug, and now
it is fixed, both ZJ site and here are updated :)



---
����: Row
��Ŀ: >small bug
����: Sun Jan 30 10:45:11 2000
On Sat Jan 29 15:36:17 2000 �һ�(fire) wrote post #1029:
> ���о����ҵĶ��������ˣ������һ��ͬʱ����������ask guan about
> pay�������ҵ������ˡ����㲻����bug?

i will check it.


---
����: ����(ice)
��Ŀ: about some NPC.:P
����: Sun Jan 30 10:54:53 2000
��ҥ�ԡ�ĳ�ˣ��ŽǺ���Ͷ�����ȥ�ˡ�
hmm, seems he and his brothers should be bandit yah.:P
and other names in bandit should be reserved to be bandit that
lead the bandit war.:P


---
����: ����(row)
��Ŀ: update
����: Sun Jan 30 21:37:30 2000
i changed /sgdomain/job/makedoufu/gfz.c and /sgdomain/job/digsoil/sir.c;
please update in mirror.


---
����: ����(row)
��Ŀ: bug log
����: Mon Jan 31 01:51:22 2000
taishou will leave when player doing robot test, should prevent this
from happening..


---
����: ˹̹��(stefan)
��Ŀ: to fire
����: Mon Jan 31 02:28:33 2000
In case I am away, this server should always be up running... If not,
please drop me an email at paul@theV.net
1. backup is automatically run everyday, you may want to FTP to your
   own machine and keep a copy.
2. mirror update only happens every half an hour, which means every
   modification you made will appear in the mirror server every 30
   minutes. If you want ZJ site to update his local copy, ask xfan
   to run the "update.sh" in his directory. The relation is as
   follows:
   [our lib] ---------> [mirror server] ---------> [ZJ site]
           every 1/2 hour               update.sh
3. I also promised tiany to let him host our second mirror at Fu Zhou.
   But xfan is bugging me that he needs a leading time of at least
   one month. I think it is reasonable, so I am telling tiany that
   he will not be able to set up SanGuo mirror until late Feburary.
I may be able to check San Guo status when I am at home, and I
will come back to work on 17th Feb.


---
����: Fire
��Ŀ: >to fire
����: Mon Jan 31 17:10:41 2000
On Mon Jan 31 02:28:33 2000 ˹̹��(stefan) wrote post #1035:
> In case I am away, this server should always be up running... If not,
> please drop me an email at paul@theV.net
> 1. backup is automatically run everyday, you may want to FTP to your
>    own machine and keep a copy.
> 2. mirror update only happens every half an hour, which means every
>    modification you made will appear in the mirror server every 30
>    minutes. If you want ZJ site to update his local copy, ask xfan
>    to run the "update.sh" in his directory. The relation is as
>    follows:
>    [our lib] ---------> [mirror server] ---------> [ZJ site]
>            every 1/2 hour               update.sh
> 3. I also promised tiany to let him host our second mirror at Fu Zhou.
>    But xfan is bugging me that he needs a leading time of at least
>    one month. I think it is reasonable, so I am telling tiany that
>    he will not be able to set up SanGuo mirror until late Feburary.
> I may be able to check San Guo status when I am at home, and I
> will come back to work on 17th Feb.

no problem,
have a nice holiday :)
wave


---
����: Flee
��Ŀ: >sgdomain/event/ev_bwdh/ev_bwdh.o
����: Fri Jan 28 22:02:20 2000
On Fri Jan 28 01:10:27 2000 ˹̹��(stefan) wrote post #1018:
> Seems that BWDH's data is stored there, I think it is
> not a good place to hold data. Why not move it to somewhere in /data ?
agree, since not a few of events have a data file, i suggest
create a event dir under /date dir, and put all event data file
there.


---
����: ����(ice)
��Ŀ: about the waterflower bowl
����: Fri Jan 28 11:56:22 2000
it's supposed to disappear by watered by another player who
complete the waterflower job actually.  for example, if row get
that job, after some watering, he goes to sleep, then I step in
to continue water, the bowl will be finished by me.:P
however, it could be a reason that it's virtual room thus bowl
may disappear if long time no one visit there.:)

I remember the shui hu didn't have time limit to disappear, thus
player can water whenever he find there is a bowl there, it doesn't
sound so good.:P  maybe we can add a time limit in the obj->shui hu,
make it only can be kept for 30 mins sth, like the incense.:P


---
����: ˹̹��(stefan)
��Ŀ: sgdomain/event/ev_bwdh/ev_bwdh.o
����: Fri Jan 28 01:10:27 2000
Seems that BWDH's data is stored there, I think it is
not a good place to hold data. Why not move it to somewhere in /data ?


---
����: ����(row)
��Ŀ: to group
����: Fri Jan 28 00:51:11 2000
the waterflower's bug: bowl will disappear by no reason.
maybe it is becoz that the room is virtual, so if nobody be there for
certain time, the room will be cleared from system's memory, so
make the bowl always be there, and make it unaccessable for none-job
player bah...
that's my guess, dunno right or not...hehe.


---
����: Flee
��Ŀ: >huayin
����: Thu Jan 27 21:04:51 2000
On Thu Jan 27 18:37:54 2000 Է�(tset) wrote post #1014:
> foxer reported a bug about zuoci job:
> >cmd job foxer
>  24  �������  zuo ci          41    1  ִ�� �߷���ǰ     ����(Ӻ��)
> 
> more /sgdomain/job/zuoci/zuo_tool.c
> 57        here = env->get_area();
> 58        if( !here||here==""||!stringp(here)||here == "huayin" ) {
> 59                write("����Ȼ�����������\n");
> 60                return 1;
> 61        }
> 
> shouldn't huayin be not appearing in zuo's job totally? someone plz check.
it is not a bug, the huayin in memo just mean that 
the target city is near huayin, not necessorily is huayin.


---
����: ����(row)
��Ŀ: bug log
����: Thu Jan 27 20:44:25 2000
this always happens:
taishou left b4 player answer robot question, then player get nothing.


---
����: Է�(tset)
��Ŀ: huayin
����: Thu Jan 27 18:37:54 2000
foxer reported a bug about zuoci job:
>cmd job foxer
 24  �������  zuo ci          41    1  ִ�� �߷���ǰ     ����(Ӻ��)

more /sgdomain/job/zuoci/zuo_tool.c
57        here = env->get_area();
58        if( !here||here==""||!stringp(here)||here == "huayin" ) {
59                write("����Ȼ�����������\n");
60                return 1;
61        }

shouldn't huayin be not appearing in zuo's job totally? someone plz check.


---
����: ˹̹��(stefan)
��Ŀ: huayin.o changed
����: Wed Jan 26 13:09:25 2000
I changed everything starting with /wiz/fire to be under /sgdomain/.
those npcs and objects are moved to /sgdomain/npc and 
/sgdomain/obj/other/.

it was causing some problem with the mirror site because it does not
have /wiz/fire :)

hope I did not make any mistake to the current mud.


---
����: ����(row)
��Ŀ: a bug
����: Wed Jan 26 01:55:00 2000
sometimes, li guan (the guy who charge money for marriage) will
appear in some area, then he will cause problems...is this kind of
npc should be removed if there is no celebration?


---
����: ����(row)
��Ŀ: to fire
����: Tue Jan 25 21:33:01 2000
����Ŀǰ��λҪ������ˣ��Ƿ���Ӧ������ܲ��ԵĻ��ʣ�����
�ɴ�ȡ��������Ե�����������Ϊ��Σ�


---
����: Fire
��Ŀ: >to fire
����: Wed Jan 26 17:28:23 2000
On Tue Jan 25 21:33:01 2000 ����(row) wrote post #1008:
> ����Ŀǰ��λҪ������ˣ��Ƿ���Ӧ������ܲ��ԵĻ��ʣ�����
> �ɴ�ȡ��������Ե�����������Ϊ��Σ�

consider
I will calcualte and give a new formula


---
����: Fire
��Ŀ: >a bug
����: Wed Jan 26 17:28:51 2000
On Wed Jan 26 01:55:00 2000 ����(row) wrote post #1009:
> sometimes, li guan (the guy who charge money for marriage) will
> appear in some area, then he will cause problems...is this kind of
> npc should be removed if there is no celebration?

that's right, I will check it


---
����: �һ�(fire)
��Ŀ: ��ӥ�����㣺why ��ҳ�޷���ȥ��
����: Wed Jan 26 19:26:44 2000
web server down ?
how to start it?
xixi:)


---
����: �һ�(fire)
��Ŀ: About task news groups
����: Mon Jan 24 19:21:12 2000
Now I created 6 news groups
1   task.base
2   task.house
3   task.jimou
4   task.law
5   task.mirror
6   task.multitroop
They are current tasks, so for any post regard these
tasks, please post in related news group. Because some tasks
will go a long term, this will help to maintain the documents.
when we new tasks, we will create related news group too :)
addoil all


---
����: Row
��Ŀ: >About wiz countries
����: Mon Jan 24 02:04:15 2000
my nation is at bailangshan, it is the closest area to xiangping
and its a level 1 only area, not much affect to players.


---
����: ����(row)
��Ŀ: to stefan
����: Sun Feb 13 01:40:58 2000
pls add (id) right after the name while someone tell or reply u.


---
����: ����ү(suicide)
��Ŀ: Can give me the write right in help dir?
����: Sat Feb 12 23:11:40 2000
like topic.
)


---
����: ����ү(suicide)
��Ŀ: update help file about who
����: Sat Feb 12 22:37:00 2000
I have updated the help about about who.
It is in dir of "wiz/suicide",if it is ok please remove it to right dir.


---
����: ����ү(suicide)
��Ŀ: sth about unify
����: Sat Feb 12 22:35:35 2000
   After I had seen the archieve news yesterday i found
that the countries in our mud had been unified once by xixixi and
our mud had to be reopened. In my opinion frequent unify is not very
good,so i think if we can have a idea to avoid this or prolong this.

   In the discuss before someone had suggested to dec the efficiency
of transfer or prolong the time of transfer , i still  have  got 3
ideas,let's discuss bah...
   1) ���Դ���һ�����������˿��ƵĹ���(����:��ū���ձ�),
���ǲ��ӵı��ּ����ս������Ա���ҵ�ǿ.��Щ����ƽʱ��ҿ��Ժ�����
�ǵĴ���.����ĳ����ҹ��ҹ���ǿ��ʱ,���Ǿͻ�
����Ϯ�Ź�ռ����ҵ����������ǳ�,��ɴ���پ�֮��,��ʹ��Ҳ��ҹ�����
��һ������������С����ҹ���,ʹ��������ս.���������������ĳ���Ҳͳ
һ��������ҹ���,����Ҳ����ʹ��û�д󹦸�ɵĸо�,��Ϊ����һ�����ٵ�
�������Ŭ����չbaseϵͳ�����Լ����ӵı���,ʹ֮�ܺͻ����˿��ƵĹ���
����,������������.(�������ĳ����ܹ�ռ�ձ�,Ȼ������һ��������XX,��
��һ����ô�гɾ͸е���).
    2) ĳ��ҹ��ҵľ���������,�����Ĵ�����,���ҿɱ�������������һ
�������Ľ�������.��ĳ��̫�ر���Ȱ˵Ը�����ʱ���Ϳ���������ʽ�����
����λ̫��,��������������������һ�ټ��ɲ���ָ��,�ڰ�������ʱ����һ��
��ļ��һ�������ı���������߳ǳصķ�������,�����������Χ����������
��ĵط�,�������Զ�ʱ���ڹ�ռһЩ�ط�.��ʱ̫��Ҫ������������,����
�����ʸ�û�дﵽ������Ҫ��.������ʹһ�����������������һ����ɽ����
�Ļ���.
     


---
����: �һ�(fire)
��Ŀ: bug in who
����: Sat Feb 12 09:49:14 2000
who @����־�㽭վ
������־�㽭վ������ѶϢ�����Ժ�
[errors] ((none)) Error logged to /log/catch
[errors] *Bad type argument to +. Had array and string
[errors] /daemons/imud_d (daemons/imud/who.c) at line 55


---
����: Fire
��Ŀ: >To fire
����: Sat Feb 12 09:14:30 2000
On Sat Feb 12 01:35:26 2000 ����ү(suicide) wrote post #1046:
> Hi fire:
>   I have some confusion with writing help file job. My job is to write new
> help files about base system or those help files that up to date?
F
both :)


---
����: Stefan
��Ŀ: >who.c
����: Sat Feb 12 05:03:33 2000
On Fri Feb 11 21:25:55 2000 ����(flee) wrote post #1044:
> i have made some modification on command who.c
> 1) make -m work, to list all idlers;
> 2) -<country id> to list player in the given country;
> 3) @<mirrors> to list users in other sites, in order to do that
> i have make some change on /daemons/imud/who.c, since i am not
> fimilar with the inter mud suffs, can stefan or fire check these
> code, whether there any potential bugs or not.
> i have backuped the original files as /cmds/player/who.flee and
> /daemons/imud/who.c

finger @<mirror> already works for the mirror site. There should not be
any changes needed for /daemons/imud/who.c, please check again :)


---
����: ����ү(suicide)
��Ŀ: To fire
����: Sat Feb 12 01:35:26 2000
Hi fire:
  I have some confusion with writing help file job. My job is to write new
help files about base system or those help files that up to date?


---
����: ����ү(suicide)
��Ŀ: some declaration
����: Sat Feb 12 01:28:22 2000
Sadlife is my dummy,I use her to test.
So maybe i will call her data.
And for being familiar with this mud soon i will download some file
to see when i am offline.


---
����: ����(flee)
��Ŀ: who.c
����: Fri Feb 11 21:25:55 2000
i have made some modification on command who.c
1) make -m work, to list all idlers;
2) -<country id> to list player in the given country;
3) @<mirrors> to list users in other sites, in order to do that
i have make some change on /daemons/imud/who.c, since i am not
fimilar with the inter mud suffs, can stefan or fire check these
code, whether there any potential bugs or not.
i have backuped the original files as /cmds/player/who.flee and
/daemons/imud/who.c


---
����: �һ�(fire)
��Ŀ: set_notell([msg|1|0])
����: Mon Feb 14 23:02:00 2000
set_notell(1) will disable tell
set_notell(msg) will return the msg for not tell
set_notell(0) will enable tell


---
����: Fire
��Ŀ: >bug log
����: Thu Feb 24 04:36:53 2000
On Wed Feb 23 23:22:28 2000 ����(row) wrote post #1087:
> now player can "put" sth which cannot be given in someone, so maybe
> we have to modify the code of put.c
nod row


---
����: ˹̹��(stefan)
��Ŀ: call has no log
����: Thu Feb 24 09:02:33 2000
better add a log so that any call history can be checked.


---
����: ����(ice)
��Ŀ: typo of sb
����: Fri Feb 25 07:43:42 2000
> ��ҥ�ԡ�ĳ�ˣ����ݳ���ɿ���Բ��棬�������۷ݷݣ����ذ����½��ˡ�

it's  �׷� bah
sb change it bah.:P


---
����: �һ�(fire)
��Ŀ: the troop object
����: Wed Feb 23 07:20:00 2000
I change that to virtual object like virtual char
this way will be easier to find the right object
don't know if get in any bugs


---
����: ����ү(suicide)
��Ŀ: ����о�һ��
����: Wed Feb 23 02:31:43 2000
���������Һ�rowͻȻ���޷��ӹ������ߵ���վ.
����ʱstefan����վ����������������վ��������,��ֻʣ5�����.
ͬʱ��ping��վ��ͬ,����ʱ���ܵ���վstefan���Ե�sgzƵ����Ϣ.
��֪�ι�?
����log������־����վȡ��.
> mudlist
�� 5 �� MUD ���� 5 ����Ӧ�ģ����� 4 �����ڿ��š�
�� mudinfo <mudname> ����ȡ�������Ϣ��
Up  Mud              Address                 Lib           Open Status       
----------------------------------------------------------------------------
U   ����־����վ     130.91.8.120     5000   Lima 1.0a2    open              
U   ����־����վ     210.34.53.200    5000   Lima 1.0a2    open              
U   ����־�㽭վ     202.96.109.11    5000   Lima 1.0a2    open              
U   ����־��վ       208.184.73.226   5000   Lima 1.0a2    open              
> who @����־��վ  
������־��վ������ѶϢ�����Ժ�
> no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
����Ƶ�������㣺Hidden Names: There are currently
14 heroes wandering the lands.  Names are withheld to protect their
anonymity.
[another mud we don't know?]
no infomation availble!
no infomation availble!
����Ƶ�������㣺bad-pkt: Packet is of incorrect size.
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
�� ����־����վ ��  ������ʱ�䣺��ǧ����¶�ʮ��������ʮһʱ��ʮ���֣�
����ID�б���  Ŀǰ��������2��
��������������������������������������������������������������������������
˹̹��(stefan)     ����ү(suicide)
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
����Ƶ�������㣺bad-pkt: Packet is of incorrect size.
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
�� ����־�㽭վ ��  ������ʱ�䣺��ǧ����¶�ʮ��������ʮ��ʱ��ʮ���֣�
����ID�б���  Ŀǰ��������56��
��������������������������������������������������������������������������
С��(fanwf)        ��֪��(alter)      ����(cllin)        ��Ψ��(maodsa)
ɱ��(seaking)      ����(lvshui)       ����ˮ(zzzzzz)     ����(bawang)
����(sunson)       ����(yan)          ����(erzi)         ���(niba)
����(zxiaol)       �����(xixixi)     ����(eryuee)       ��Ů(seagirl)
��ʮ��(aniu)       ���(wujun)        �Ϲ���ӣ(slay)     ��������(wutian)
��Ҫ(buyao)        ����(sos)          ���(bbbbaaaa)     ǿǿ(chamcham)
��(aaaabbbb)       ����(hateyou)      �����(aha)        �Ϲ���ӣ(http)
����Ϧ��(drxy)     ����(row)          ���(kuangf)       �ƺ�(qwe)
����(storm)        ʱ��(age)          ��������(giving)   ���¿�(dgkai)
����(zrd)          ������ʹ(sixwing)  ����(ate)          ��ɫ����(fantasy)
��֮��(gone)       ����ү(suicide)    ���·�ѩ(feixue)   
����(hxx)          ����(zhangke)      ������(jianxu)     
��ƤƤ(pppp)       �·���(chili)      ����(rulin)        
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
no infomation availble!
�� ����־����վ ��  ������ʱ�䣺��ǧ����¶�ʮ��������ʮ��ʱ��ʮ��֣�
����ID�б���  Ŀǰ��������39��
��������������������������������������������������������������������������
���(rainbow)             ������(ufu)               ����(locust)
����(ahwoo)               ����(showlin)             Ц����(llf)
��һ����(other)           �ɼ�˼��(china)           ������(queen)
��è (zcr)                ����(shining)             ��ɱ(bsc)
����(pulldrag)            С��(lpr)                 �ϰ���(zzj)
����(ttk)                 ����(kindzcr)             ����ң(slamdunk)
�׷�(basten)              ʱ��(xzhao)               ����(aiai)
������(leishen)           ������(marco)             ����(szs)
С��(hujiang)           ����Ѫ(hrc)               ����(oic)
��צ��(octopus)           �������(sofronie)        Ϯа(xixie)
�ƾ�(story)               ����(liwang)              ��˫(wings)
����(xiha)                ������(wcb)               ����Ц(qcsjxrds)
��ѩ(roc)                 ��(linf)                  
l
��ʦ���� [���ڣ�northwest, south, east, north, up, down]
��ӭ���� LIMA����������ʦ�����ۺͷ����� LP MUD �� MudOS
����������̳����Ҳ����������ѯ��һЩ�й����� MUD �ļ��������⡣��
�ں�����������֣�LIMA �������ĵط��д����ƣ���ӭ��Ҷ��������
        ʹ������ϵͳ������ news ���
        ʹ�����ѡ�������� menu ���
        ʹ���ʼ�ϵͳ������ mail ���
����ǽ������һ��������ֻ�̨������ȥ���˼䡣�����Ǿ��ң������������š�
һ��ħ��ľ��(torch)���ڵ��ϣ�û����ע�⡣
Ц̸�����¡�����0�����ԡ�(board)
��������˹̹��(stefan) [���� 4 ����]
> ����ɫ���Ѿ�����ҹ�ˣ���Χ��һ�ж������ںڰ�֮�С�
who @����־�㽭վ
������־�㽭վ������ѶϢ�����Ժ�
> 
�� ����־�㽭վ ��  ������ʱ�䣺��ǧ����¶�ʮ��������ʮ��ʱ��ʮ�˷֣�
����ID�б���  Ŀǰ��������55��
��������������������������������������������������������������������������
С��(fanwf)        ��֪��(alter)      ����(zhangke)      ����(rulin)
ɱ��(seaking)      ����(lvshui)       ����(cllin)        ��Ψ��(maodsa)
����(sunson)       ����(yan)          ����ˮ(zzzzzz)     ���(niba)
����(zxiaol)       �����(xixixi)     ����(eryuee)       ����(tongz)
��ʮ��(aniu)       ���(wujun)        �Ϲ���ӣ(slay)     ��Ů(seagirl)
��Ҫ(buyao)        ����(sos)          ����(storm)        ��������(wutian)
��(aaaabbbb)       ����(hateyou)      ���(bbbbaaaa)     ǿǿ(chamcham)
����Ϧ��(drxy)     ����(row)          �����(aha)        �Ϲ���ӣ(http)
����(zrd)          ʱ��(age)          ���(kuangf)       �ƺ�(qwe)
��֮��(gone)       ������ʹ(sixwing)  ��������(giving)   ��ɫ����(fantasy)
����(hxx)          ����ү(suicide)    ���·�ѩ(feixue)   
��ƤƤ(pppp)       ����ˮ(xws)        ������(jianxu)     
who @����־����վ
������־����վ������ѶϢ�����Ժ�
> 
�� ����־����վ ��  ������ʱ�䣺��ǧ����¶�ʮ��������ʮ��ʱ��ʮ���֣�
����ID�б���  Ŀǰ��������40��
��������������������������������������������������������������������������
���(rainbow)             ������(ufu)               Ц����(llf)
����(ahwoo)               ����(showlin)             ������(queen)
��һ����(other)           �ɼ�˼��(china)           ��ɱ(bsc)
��è (zcr)                ����(shining)             �ϰ���(zzj)
����(pulldrag)            С��(lpr)                 ����ң(slamdunk)
����(ttk)                 ʱ��(xzhao)               ����(aiai)
�׷�(basten)              ������(marco)             ����(szs)
������(leishen)           ����Ѫ(hrc)               ����(oic)
С��(hujiang)           �������(sofronie)        Ϯа(xixie)
��צ��(octopus)           ����(liwang)              ���(qinga)
�ƾ�(story)               ������(wcb)               ��˫(wings)
����(xiha)                ��(linf)                  ����Ц(qcsjxrds)
��ѩ(roc)                 ����(locust)              ����(bawang)
who @����־��վ
������־��վ������ѶϢ�����Ժ�
> ��Fang@Myth and Lore�������㣺testing
[how this message come?]


---
����: �һ�(fire)
��Ŀ: about the /a/*.c
����: Tue Feb 22 19:18:41 2000
stefan's suggest is right. I will change the /a/*.c into one or few files.
another  thing is about the soldier lost due to reboot and crash.
I will write sth to record and auto recover in case soldiers lost. then
we can avoid the trouble to recover the lost soldiers. I truely believe
some ppl lie for their lost. but we have no proof :(



---
����: �һ�(fire)
��Ŀ: about the setting in char_d
����: Tue Feb 22 17:43:15 2000
  "nation" : "group", 
  "name" : "�һ�",
  "room" : "/a/xiangping/xp_yst", which room current in, this maybe
removed later
  "type" : 1,  // 1 player, 0 npc
  "hon" : 1246, // honour point
  "status" : 2, // online, sleep or active. obsolute
  "gold" : 2278, // salary money
  "nc" :  national contribution mapping
  "lo" :  relationships with all countries. mapping
  "zi" : "�ٺ�", zi
  "myarmy" : ([ ]), // players own army. need further develop. now nouse
  "gift" : gifts. mapping
  "h" : player's house information
  "literate" : 96008, //
  "catch_area" : "didao", where you can be catch, temp variable set
when you can be caught
                    // still other funcitons all begin with catch
  "wear" : what the player have, mapping
  "ju" : 1, jue wei.
  "lc" : localcontribution mapping
  "skills" : skills mapping 
  "ranklocal" : 180,  the rest are easy to understand
  "reputation" : 97850,
  "age" : 36,
  "gender" : 1, 
  "area" : "xiangping", settle area
   pre_mar is someone you are going to marry
   mar is your spouse
   re_mar is designed by row, maybe a flag to show that this is not
your first marriage


---
����: ˹̹��(stefan)
��Ŀ: >> virtual room
����: Tue Feb 22 08:06:43 2000
One class occupies more memory than data in the mapping :)

here is the theory:

1. a class file took more than 1k, depends on its program size;
2. a object of a class took more than 16bytes, depends on the variable
space used in the object;
3. a string only take whatever length it is;

So often you would see replace_program(..) in rooms of a MUD. because
each room is often programed as a file, it would be considered
as a different object from the /std/room.c, therefore it would
take up the space of the size of a class, and its first instance, that
is the object of that particular room, would still take the space of
a room object. replace_program() is used in such rooms to replace
the class with its parent, i.e., the /std/room, but still keeps
its own variable in the object itself. 

as a result of replace_program(), all the rooms would take up
object space of their own, but only share one class space of 
/std/room.c. Compared with one room with one class and one object,
it saves a lot.

so that is the theory behind rooms. I believe current virtual room
implementation already saved a whole lot, but I have not checked if
replace_program() is implemented in all the rooms or not. The other
way to save memory is to implement all rooms of San Guo under one class :P



---
����: Fire
��Ŀ: >regular restart
����: Tue Feb 22 00:59:28 2000
On Mon Feb 21 22:55:48 2000 ˹̹��(stefan) wrote post #1078:
> what about a regular restart every two days?
> actually, xfan mentioned this to me. I think it is not
> a bad idea. 
> ������Һͺ���ʦ�����ý��� crash �ˡ�

this is a good idea. better stop all the train, war before restart :)


---
����: Fire
��Ŀ: >virtual room
����: Tue Feb 22 00:58:28 2000
On Mon Feb 21 22:57:29 2000 ˹̹��(stefan) wrote post #1079:
> those rooms under /a are indeed virtual rooms for
> each city. 
> But look at them again, they are all similar. Why not
> integrate all the cities to be in one virtual room
> just like integrating all rooms into one city?
> 
> 
> any comments?

to use one virtual room server to create all the virtual
rooms is possible
but the file name each individual virtual room may be
several character longer. Because we are using char_d
to store all char's current room. so the daemon file for
char_d may be bigger. so it is quite hard to judge few files
bigger daemons and more files smaller daemons, which way is
better?


---
����: ˹̹��(stefan)
��Ŀ: virtual room
����: Mon Feb 21 22:57:29 2000
those rooms under /a are indeed virtual rooms for
each city. 
But look at them again, they are all similar. Why not
integrate all the cities to be in one virtual room
just like integrating all rooms into one city?


any comments?


---
����: ˹̹��(stefan)
��Ŀ: regular restart
����: Mon Feb 21 22:55:48 2000
what about a regular restart every two days?
actually, xfan mentioned this to me. I think it is not
a bad idea. 
������Һͺ���ʦ�����ý��� crash �ˡ�


---
����: Fire
��Ŀ: >cmd leave
����: Mon Feb 21 17:31:33 2000
On Mon Feb 21 08:13:57 2000 ����(group) wrote post #1076:
> (ת����reporter.bugs)
> mirror site got ppl use leave and rejoin to gain prize
> i add in the clear of nc for cmd leave.
> 
> please check it in ev_leave.c

that's right. and you can also set it to 0 :)


---
����: ����(group)
��Ŀ: cmd leave
����: Mon Feb 21 08:13:57 2000
(ת����reporter.bugs)
mirror site got ppl use leave and rejoin to gain prize
i add in the clear of nc for cmd leave.

please check it in ev_leave.c


---
����: Fire
��Ŀ: >add a new news group bah
����: Mon Feb 21 17:25:01 2000
On Mon Feb 21 06:46:18 2000 ����(ice) wrote post #1074:
> fire, add a new news group called "finance" bah..:P
done, addoil ice


---
����: ����(ice)
��Ŀ: add a new news group bah
����: Mon Feb 21 06:46:18 2000
fire, add a new news group called "finance" bah..:P


---
����: �Ƶ�(emperor)
��Ŀ: �Ҷ�fateҲ�ܸ���Ȥ��but suicide has programed fate system
����: Sat Feb 19 23:12:48 2000
fate system is very complex system,addoil suicide.


---
����: Ice
��Ŀ: >>>��һ�������ƻ�
����: Sat Feb 19 20:21:04 2000
no one interest of the fate system?.:(
cry
nip row


---
����: ����(row)
��Ŀ: bug log
����: Wed Feb 23 23:22:28 2000
now player can "put" sth which cannot be given in someone, so maybe
we have to modify the code of put.c


---
����: �Ƶ�(emperor)
��Ŀ: ��������ͥϵͳ
����: Fri Feb 18 11:49:43 2000
��ͥϵͳ�Ǹ��ܸ��ӵĹ�����������������Щ˼·��������������Ϣ
����ϸ���룬���ø���������������ҿ�����


---
����: ����ү(suicide)
��Ŀ: ���
����: Fri Feb 18 05:04:43 2000
���ǵ�λ��������������ˣ���һ���޷���������
�ظ�����գ�����׼��
:)


---
����: �һ�(fire)
��Ŀ: to suicide,
����: Fri Feb 18 04:28:21 2000
��Ļ�������ľ���ܺá�������ϵͳ��һ�������Ѿ����˽�һ��
ʱ�������ϵͳ�������ڲſ�����������ȫ����Ϊ����Ѷȴ󣬸�
��Ҫ��ԭ�����漰�ķ���ࡣ�ӻ��أ������ʣ�����ҵ��������֣�
��ս��ƽ�⵽JOBϵͳ����������ɫ������ƽ��������Ĺ�ϵ̫���ӡ�
�����ⲿ�ֲ�����һ���ſ�ʼ��Ӧ���ǻ��������֡�������Ŀǰ��
���������˼·����ʮ���˽⡣�����ҽ��飺�������Ҫ���ٶ�ȫ��
��һ���˽⡣��ô���HELP��������¹���������뾡���̣���
��ѡһ����Խ϶�����ϵͳ�����semote���ͥϵͳ(�ǲ��ֺͻ���
�ڳ������кܴ�����ƴ�)����������ϵͳҲ��һ��������ս��ϵͳ��
������ر�Ի���ϵͳ����Ȥ�������POSTһЩ��Ĺ��룬�����
�Ѻ�����ɺ�������һЩ�����ߣ�������һЩ���ϡ����ṩ��
ascii artͼ�κܺã��һ��������ṩ�ܶ�:)
addoil suicide


---
����: �һ�(fire)
��Ŀ: ���񲹳䡣
����: Fri Feb 18 04:13:51 2000
������������
  1 ������semote�Ĺ��ܡ�
    ����Ҫ�󣺺����ڵ�semoteϵͳ���ݡ�����ϵͳ���Լ�����
    ��Щ�������Ƶ�semote��������˭���Լ�ʹ��Ƶ�ʵȡ���
    ����Ƶ�semote��ֻ�и���ұ��˺�WIZ����ɾ�ġ���Ҳ�
    ��ɾ��Ŀǰ�Ѿ��е�semote�����ڣ�wizЭ�Ὣ��Щ��ƽ�
    �õ�semoteתΪ��ʽsemoteͬʱ�������һ��������
  2 ���Ӻ��ۺ͸����Ĺ�ϵ������
    ��ϵԽ�ߣ��Ըù���Ա�ټ��Ļ���ʹ�ͬʱ�ټ�������
    Щ�ô�����ϵԽ�����Խ�٣���ʹ�ټ����Ҳ��ѵ��һ�١�
    ��ù�ϵ�ķ������У������������Ȼ���ڿ����ǽ�Ǯ����
    ��������������磺���ƻ���ȡ����������ɺ��۵�����
    (���ڵ������ƺ�û������)��������������ʤ������Ա
    ����Լ������Ϲ����ֳ�ɫ�ȶ����Գ�Ϊ���ӹ�ϵ��������
    ������������ַ����������߹����������������Գ�Ϊ��
    ��ϵ�Ľ�ڡ�
  3 һ�����˶�ε�����ϵͳ��
����ܶ࣬��ӭĿǰ��û�о��������������롣


---
����: Fire
��Ŀ: >>��һ�������ƻ�
����: Fri Feb 18 01:40:58 2000
On Fri Feb 18 01:32:29 2000 Row wrote post #1061:
> objective clear :) and i apply for taking part in the design
> work for event of �Ƶ�.

so you have to major tasks:)
addoil
sweat row


---
����: Row
��Ŀ: >��һ�������ƻ�
����: Fri Feb 18 01:32:29 2000
objective clear :) and i apply for taking part in the design
work for event of �Ƶ�.


---
����: ����ү(suicide)
��Ŀ: ����������ϵͳ����.
����: Thu Feb 17 22:46:40 2000
�����������fire����Ļ���ϵͳ�Ŀ�������Ϊ�ҳ�Ϊ��ʦ��Ŀ�ͷ
������������׫д����ϵͳ��help�ĵ������ڶ���������ϵͳ�ļܹ�
�ͳ����������������һ�����˽⣮
����ֻҪfire��һ�ݻ���ϵͳ����һ��������Ҫ������ң��ҵõ���
���ϾͿ��Կ�ʼͶ���̿���������


---
����: �һ�(fire)
��Ŀ: ��һ�������ƻ�
����: Thu Feb 17 22:11:26 2000
��������������Ա�µĸɽ�(emperor �� suicide)������������������ʵ��
����µ����롣�ڴ��ҽ���һ���Ĺ����ƻ�����һ�¡�����֮������ӭ���ۡ�
1 flee&group�ļ�ıϵͳ�Ѿ�������ɣ���һ�����ѶȺܴ�(admire flee,
  grop)��������ҪһЩ���ԣ��ĵ����ƺ��������������뵽��������һЩ��
  A Ϊ������Ժ�ƽ�⣬����������һ�¹�ʽ��ͬʱ�趨һЩ��������ƽ��
    ����ı�������������Ѷȵȡ�
  B ���ڼ�ı��ѧϰ�������ڹ�͢���������������ѧ(������ѧ��ϸ���Ҳ�
    �˽⣬�����˵�ܹ�)��ϣ���ܰ�ѧϰ�ķ�������һ�¼ӵ�HELP��ȥ����
    ���ҽ�������һ���µĵȼ����Ӱ취������һ����ı��ʹ�������Ӿ��飬
    ������ﵽһ���̶ȿ������Լ�����(�������鷿)ͨ����ϰ��ߵȼ���
  C ��ɻ�ơ�flee˵�Ķԣ������������Ƶ�һ�ּ�ı����������õĺ�
    ҲӦ����ɱ�������ļ�ı��
  ��ıϵͳ�Ҳ�̫�˽⣬����ֻ���ҵ�һЩ���顣���������flee��group
  �Լ����ա�����ԭ����ʵ�ã�����
2 ���Ϲ�ϵͳ��
  ���Ǳ�MUD��һ�޶����¹��ܡ���һ������ROWȫ�渺���ҵĹ۵���Ҫ��
  �����Գ���������ɼ򵥵ģ����������ơ�ICE��POST�ǳ����壬Ҳ��ʵ
  �ʣ����Բο������⣬�Һ�flee�����ڱ���ϰ���һ�¡�����һ���ݵ���
  �����ڹ�˼�͹��̣�������ֹٻ�������Ҳ�ǳ���Ҫ����������ROW��ǿ��
  ���������ROWһ���������һ����ϲ��)
3 ����ϵͳ��
  �����������ݵĻ�������һ���������ʣ���ҵ�Ͷ���֡������ⲿ�ݣ���
  �ĺ���  ˼·�Ѿ����졣�伸��������к�ǿ�Ĺ����Ժ������ԡ��Ⱥ���
  ������ɺ������µĻ��أ�����Ʒ�֣����ֵ�ֻ��Ҫʹ��һЩ�˵��Ϳ�
  ���ˡ�����󲿷ֵĲ������ۺ�Ч�����Ժ����׵��б��ѯ�������ͷ���
  �˽���ƽ�⹤�������о���emperor��POST�ܺã����ط����ҵ�����
  ��ı���͡�Ҳ��һЩ��û���뵽�ģ�������ӡ��һᾡ������Щ��������
  �ս�������Ϊ���ܹ�����ʹ�ã�һЩ�õ��뷨Ҫ��һЩ����ʵ�֡�
4 �����Ƶۣ�
  �Ƶ۵�˼�����Ѿ�����һ��POST����������Ľ���ǿ���ӵ�и���Ĺ���
  ְλ�����ڻ����󲻳������ȡ�����۵Ĺ��ܡ������һ��Ҳ����Ҫ���ǡ�
  �Ӽ�������������һ�����ұ�ɵ۹�ֻ��Ҫcallһ������(COUNTRY_D->
  set_country(c_id,"level",1))�Ϳ����ˡ�����һ���ݵ��ص��ǹ���
  �ͳ��档һ������Ҫ��ͳһ�Ƿǳ����ѵģ������ܹ���Ϊ�۹�Ҳ��һ����
  ����ĳɾ͡��ͱ���û��̫�������������ϣ������һ��Ҫ��ʵ������
  һ��Ҫ�����ʹ�ù�����Ҷ��õ�һЩʵ�ݺ��൱�ĳɾ͸С�����һ��
  Ҫ���ñ����������һ�û�о���������һ���ݣ�������Ҫ��ྫ�ɵ����
  �ʹ��ֱʵĳ�������Ҳ�����ҵ�ǿ�����˭����Ȥ�ͱ����ɣ�)
5 ��ͥ���裺
  Ŀǰ���ǵļ�ͥϵͳ�Ѿ�����һ�����Ρ���������಻����Ͳ����Ƶĵ�
  �������磺
  A ���˳������ʷ��⣬��������Ĺ��ܻ�û������
  B ����ͬ�������ӡ�
  C ���ز���ҵ��û�и�������
  ��ϣ������һ��WIZ��������ͥϵͳ�Ľ��衣����һ���ǳ���Ҫ��ϵͳ��
  ����������������Թ�������Ϊ������Ϸ������һЩ����ζ����һ�����
  ���Դ�����ر���Ů����ҵ��ġ�ʹ����MUD���һ���ḻ����Ԫ����
  ����������硣ͬ����˭����Ȥ�ͱ����ɡ�
6 IMUD��WEB
  ����Ҫ��stefan�Ĺ����ˣ����ǵĵ�һ��MIRROR�ܳɹ�����Ҳ��Щ���⡣
  �����ٿ�������վ�����׺ܶࡣ�������ҹ����ⷽ�湤����һЩ���飬��
  ���ο���
  A ����һ���¸Ķ����԰塣WIZֻ��Ҫ�����¸Ķ�POST����վ�����з�վ
    ����Ӧ�����԰���Զ����¡�
  B ��DAEMON���ݷ��ࡣ
    1 ��ЩDAEMON��������վ��վͬ��һ���ģ���BASE_D��
    2 ��Щ����ȫû����ϵ���磺TASK_D��TROOP_D��
    3 ��Щ����Ҫ�ȿ�����ȥ�ڳ�ʼ�����磺CHAR_D��
    DAEMON���ݳ���ᵼ�����ص�ϵͳ��������崻���
  C IMUD��ʹ��SEMOTE��
  D ��WEB����ʾ��վ������������ͼ����ʾ��վһ���ڲ�ͬʱ����ƽ����
    ����������������ͼ����ʾһ��ʱ����(��һ����)ÿ���ƽ��������
    ������֪������һ�������ò�������    
7 HELP���������ǵ����HELP����Ҫ���£���Ҫ����һЩ��Ҳ��HELP��
  �ṹ��Ҫ�����������������. . . . point ....
Ŀǰ�Ļ�������������Щ����Ŀǰ��û�о�������WIZ��ѡ�Լ�ϲ������ʤ
�εĹ���Ȼ��POST����PLAN��



---
����: Fire
��Ŀ: >help system
����: Thu Feb 17 21:29:19 2000
On Thu Feb 17 19:48:50 2000 ˹̹��(stefan) wrote post #1056:
> I think the help system has to be clean up, many players are complaining
> that the levels and relations in current help system are not 
> that clear to follow...
> 
> any idea?

the helpediter can easily to manage the
change of the help structure. the only problem
is we need a wiz to rearrange the who helps
anyone interested in this job ?


---
����: ˹̹��(stefan)
��Ŀ: help system
����: Thu Feb 17 19:48:50 2000
I think the help system has to be clean up, many players are complaining
that the levels and relations in current help system are not 
that clear to follow...

any idea?


---
����: ˹̹��(stefan)
��Ŀ: sgz server
����: Sat Feb 19 00:08:19 2000
The reason that current server connection seems slow is
because the server is not officially in above.net yet :P
Right now it connects to above.net backbone through a DSL
connection, which limits the bandwith and performance.

Soon it will be placed into above.net and connects to the internet
backbone, then it would be faster.


---
����: �һ�(fire)
��Ŀ: the help for jimou
����: Thu Feb 17 04:51:13 2000
I have installed group's help for jimou
help jimou


---
����: Fire
��Ŀ: >����ϵͳ
����: Sat Feb 26 02:10:32 2000
On Sat Feb 26 01:08:18 2000 ˹̹��(stefan) wrote post #1098:
> �Ҿ���Ŀǰ�İ���ϵͳ��Ҫ����һ�£����鰴���·��ࣺ
> 
> �������  ������·  ��ɫ�ɳ�  ���ҽ���  
> 
> ս��ϵͳ  ���ĵ���  ��������  ��Ϸ����
> 
> ���л�����ϸ�֣���������ϵͳ����һĿ��Ȼ��á�˭������ݹ����أ�
> ���߿��������й������Ұ�æ������ rulin �� :)     

that's great, point . . . .
escape


---
����: ˹̹��(stefan)
��Ŀ: for reference :)
����: Sat Feb 26 10:30:35 2000
http://akiratsai.hypermart.net/disappoint-san-internet.html


---
����: ����(flee)
��Ŀ: findfile
����: Wed Mar  1 08:18:20 2000
>findfile test.c
Badline ... 

fire or stefan, please upgrade it ..


---
����: �һ�(fire)
��Ŀ: about the hook of object_meet.
����: Wed Mar  1 06:25:49 2000
I checked your code, it's great. But I have some concern. With
the hook of object_meet, whenever an object move to another 
environment it will check the hook of every object in this
environment. I don't know how much cpu power it will used. And
in fact, most the checks will be no result. I think perhaps we
can just add one hook of object_arrived in the rooms, and to check
if the arriving is a player and if the room has some one want to
welcome and so on. I think this way will be much saving. 
Another thing is about the function of init. I don't know much thing
about es2, so don't know what the useage of init() in es2. but in
this mud, we have used a lot of init and samilar function for the
initialization. And to use it as an welcome trigger may cause some
conflicts. So perhaps we can choise another name for this function.
anyway, this is just a small issue. for the system part, I am not
quite familar, maybe stefan and flee can give some better suggestions :)


---
����: �һ�(fire)
��Ŀ: about recover soldiers
����: Wed Mar  1 05:42:48 2000
now i modified the ev_war ,train and area_d
so before each war and train, the number of soldier in the
area will be saved in area_d with type of ssoldiers
the ssoldiers will store two records one is old
one is new, when new record come, the old new become old
and the new comer will become new, so this will help
us to recover. sigh


---
����: ����ү(suicide)
��Ŀ: no title
����: Wed Mar  1 01:57:50 2000
fire :
  have u seen the program i had pasted about init().
please reply me ur opinion soon.
admire fire
massage fire


---
����: �һ�(fire)
��Ŀ: ����MUD��һ�����
����: Wed Mar  1 00:02:06 2000
�ܸ����ܿ�������MUD����ĳɾ͡���Ȼ���ǻ�Զ������POPULAR
������MUD��������������������MUD����õġ�
��˵����MUD����õ�����MUD��������Ϊ���ǵ�����ϵͳ������
��MUDҪ�ã�Ҳ����˵���ǵ�ս��ϵͳ�Ƕ�һ�޶��ģ�����������
����Ϊ����ʵ���˶�̬MUD�Ĺ��롣��˵����MUD����õ�ԭ����
���ǵ�MUD�ǽ�����һ�������ϣ������ǵ�MUDʵ������һ���롣
����˵������������������棺
1 ���ǵ�MUD�ᳫ�Ž�����ľ��񡣡�
2 ���ǵ�MUD��������˳�ޡ������������кڰ���һ��������
  ��Ϸ�Ŀ���ȡ�
���������ʼ��˼MUD�Ļ������롣�����������ͺ��������
Ϊʲô���ǵ�MUD��һ��ʼ�ͱ���û��PK������SKILL����ƣ���
ͨ��MUD��SKILL���ٵ����޼��ٵ�һ�١�ȡ����Ǳ�ܵĸ����
��������Ǵ��з����ԡ��ܶ�MUD����ʶ��PK��һ�����õ����أ�
�ںܶ�����¿��ܻ������˺���ҵĹ�ϵ����������ҵ������
���ƶ�������PKER���Ƶ���Ϸ���򣬵���������ȫ�õ�PK������
��������������Ժڰ���Ϊ��Ϸ����̼��Ϳ����ԵĻ��ᡣ������
MUD��ȫ��������һ�㣬���ҷ����ķǳ�Ư����
������MUD�У���ҵ����׷���Ѿ������Ǹ��˼��ܵĵ�ʧ����Ҽ�
��ì��Ҳ�����Ǹ���֮��Ķ���ԹԹ������������һ�����������
�߶ȡ�ͬʱ(��֪����������û�У����Ǿ�����˵)������Ϊ�й���
ȱ�ٺ������񣬾��Ǹ���������ǿ������һ��Ҳ��һ��ɢɳ������
�����̨������������������Ǽ٣����MUD���Ƕ�������ŵ�һ��
��ս����һ��HEI����LEEYE����POST���й�����ȫ���Ժ���������
�Žᣬ����Ϊһ����ͬ��Ŀ��ܶ���ͬʱ����������Щ���ԭ��ȱ
����������Ļ�����Ҳϣ�����MUD������ǿ�������ⷽ������ʡ�
ֻ�ǲ�֪�������ܲ�����ᵽ��һ�㣬�������ᵽ��һ�㣬�Ҿ���
������Ҳ�е�������ֵ�ˡ�
����̸һ̸WIZ������������Ȼ���ǵ�MUD����ǿ���Ž����Ϊ���⣬
���ǵ�WIZ�����Ӧ����ˡ�����һ����ֱ�ڿ�û�гǸ����ˡ�������
����ִ���ںܶ�����²�����Ϊ��һ�����׺������ˡ��������MUD��
�������е��˶������ĺܺã��ڴ��ҷǳ��м���Ҷ��ҵ��½��֧�֡�
�ر���STEFAN��������������������кܴ�ķ��磬���������ƽ���
��ʱ�������������ܵ��������ͳһ��ͬʱ�һ�Ҫ��лROW������
����Զ���ŵ����ѡ�����flee,ice,group,tset���Ƿǳ��ѵõĺ���
ⷰ顣������suicide,emperor�����ദʱ�仹�̣���������˽⣬
��������Ҳ���ǿ��Ժ�����ⷰ顣����֮�����ܹ���������ô�ɹ���һ
���������ǵ�WIZ�����кܸߵĸ�����������������Ҫ�Ǻ����ǵĹ�ƽ
���ɵĿ��������йء���������ʲô���Ļ����£�����ʲô�����ˣ�
�����벻�����Ǵ��ڵġ���δ�����Щ�������ʹ���˺����ǵĺ�����
�������½��飺
1 ��Ҫ������ѹ�Ʋ�������ô�����ô˵������������Щ����������
  ����������йء����Ƕ����ˣ��˴˶��˽����Ե����㡣
2 �����˵�����������ء�����ĳЩ�£���һ���Ƕ�ô�������������
  �����������ߵĽǶȳ�������Щ�������������һ�档
3 �������ƹ����ƶȣ�������WIZ COMMITTEE������ʱ����һЩ����
  ���ڴ󶼱�������ͬʱ��ЩҲ���Ѿ������ʺ�Ŀǰ��״̬��������
  �����ܴ�������һ�£����ۺ��ٹ���ִ�С�
������һ��ƪ����������۾���û�п��۵Ļ��������Ѿ���������:)




---
����: ����ү(suicide)
��Ŀ: can move na.c from /cmds/verbs/ to /cmds/player
����: Tue Feb 29 23:33:42 2000
for ppl can't use na when riding horse.


---
����: ����ү(suicide)
��Ŀ: A example from my own lima(no modify to fit this system)
����: Tue Feb 29 22:25:34 2000
//filename: /domains/yangzhou/npc/xiaoer.c
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit LIVING;
inherit M_CONVERSATION;
inherit M_VENDOR;
#define OBJS "/domains/yangzhou/obj/"
void init(object ob)
{ if (environment(ob)==environment())
     do_game_command("mpolite "+ob->query_primary_id());
}
void buy_thing()
{
  write("�͹ٿ�����<list>����쿴�ҿ������Ķ���!\n");
}
void setup() {
    set_id("xiaoer");   //��ͷ��ĸ����ΪСд�������޷�Look
"/domains/yangzhou/npc/xiaoer.c" (1-20 23%) [h]:
    set_name("��С��");
    set_gender(1);
    set_long("��С�����ڵ�վ�ڵ����ʱ�Ⱥ�Ϊ���˷���.");
/* Determines what type of currency we'll use */
    set_currency_type("gold");
/* Tells vendor we will sell things */
    set_for_sale(1);
/* Tells vendor we will buy things */
//    set_will_buy(1);
/* itemization of what we sell initially filename : #
   if # is set to -1, it will sell an infinite # of that item
*/
    set_sell(([
     OBJS "mantou" : -1,
     OBJS "doujiang" : -1,
     ]));
"/domains/yangzhou/npc/xiaoer.c" (21-40 46%) [h]:
/*   We would set this so that the vendor stores weaps/armor in a storage
   room.  See help on set_unique_inventory.  storage.c in the rooms subdir has
   been set up to work.
    set_unique_inventory(__DIR__ "rooms/storage");
*/
  /* We would set this if we wanted EVERYTHING to be stored in a storage
   room.
   set_all_unique(1);
*/
    
    set_options( ([
        "hello" : "Hello!",
        "greeter" : "What do you do?",
        "where" : "Where do I get LIMA?",
        "problems" : "I'm having problems setting up LIMA.",
        "compilation" : "Where should I report MudOS compilation problems?",
"/domains/yangzhou/npc/xiaoer.c" (41-60 69%) [h]:
        "intermud" : "How do I get on intermud (I3)?"
    ]) );
    set_responses( ([
        "hello" : "Hello, and welcome to the LIMA mudlib!  I'm
designed to answer some
basic questions you might have about it.",
        "greeter" : "I help people with basic questions and problems
with the LIMA
mudlib.  I also demonstrate LIMA's M_CONVERSATION module, which makes building
NPCs who can hold intelligent conversations a snap!  Feel free to
read my code,
its in " + __FILE__ + ".",
        "where" : "LIMA, like almost all MudOS libs, is available at
ftp.imaginary.com,
and its mirror aragorn.uio.no.  Look in the /pub/LPC/lib/LIMA directory.",
        "problems" : "I can help you with compilation problems, and
getting your MUD on
the intermud network.@@intermud,compilation",
        "compilation" : "Problems compiling MudOS should be reported to
mudos-bugs@imaginary.com.",
        "intermud" : "First, edit config.h and make sure ADMIN_EMAIL
is set correctly. 
If it isn't, you will not be permitted to connect.  Then do 'update
/daemons/imud_d'.  You should be on the net.  You can check with
'mudinfo <your
mud name>' from here.  Use 'igossip /on' and 'icode /on' to turn on
the standard
channels."
    ]) );
    set_start( ({ "hello", "greeter", "where", "problems" }) );
    set("inquiry", ([
     "name":"�����㶼����ʶ�����������ĵ�С�������ҡ�", 
     "here" : "��֪������ʲô�ط�����ֻ�������㶫����ڷ��ԡ�",
     "buy" : (: buy_thing :),
   ]) );
 
    add_hook("object_meet",(:init:));
   // unguarded( 1, (: restore_object , file_name()[0..<3] :) );
}


---
����: ����ү(suicide)
��Ŀ: way of init()
����: Tue Feb 29 22:22:37 2000
��/std/object/move.c���޸�:
1 ��function varargs mixed move(mixed dest, string where) 
  �� return MOVE_OK;  ǰ׷������code:
    //:HOOK object_meet
    //Called by the obs in the new envirionment where an object move to 
    //The return value is ignored.
     obs = all_inventory(dest)-({this_object()});
     call_out((:do_meet,obs,this_object():),1);
 
2 ���Ӻ���do_meet()
  void do_meet(object *obs,object ob)
{
  obs->call_hooks("object_meet",HOOK_IGNORE,0,ob);
  for (int i=0;i<sizeof(obs);i++)
      ob->call_hooks("object_meet",HOOK_IGNORE,0,obs[i]); 
}


---
����: Fire
��Ŀ: >>hook is the way to go
����: Tue Feb 29 21:51:14 2000
On Tue Feb 29 20:31:22 2000 Suicide wrote post #1123:
> i agree with stefan .
> i have added the init() func in my lima bean by using hook.
> for all obj's move use modules m_move's func move()
> i add a hook called "obj_meet" in it.
> when some obj need to  do sth when interacted  it just only need 
> to write a func link to hook obj_meet()
> i think this hook is useful in writing RPG game program.
> i think it is better to add some RPG thing in our mud later.

that's good,
can you put the code under your directory and let use
have a look, if it compible with our current mudlib and
don't consume too much cpu power, we can use it :)


---
����: Suicide
��Ŀ: >re: emperor
����: Tue Feb 29 20:45:12 2000
disagree "text mud got no future"
I think if we can code a friendly client that ppl needn't input sth
All cmd and suggest can be chosen by the mouse then the text mud
will live forever.
For graphic game the art design is the most important thing .
We ,as a programmer, can do nothing without the pic to code a graphic game.
I had tried to code a pc graphic game ,but soon i gived up for i
have no pic to use.
And can't find sb who is familair art and computer to help me.
So i disagree " text mud got no future"
I had thought the life of the text mud for a long time.
I think if we can code �ѺŵĿͻ���
����ҷ�������������,���е�������ɲ˵��������ѡ��,��ô
LONG LIV TEXT MUD.

xixi:)


---
����: Suicide
��Ŀ: >hook is the way to go
����: Tue Feb 29 20:31:22 2000
i agree with stefan .
i have added the init() func in my lima bean by using hook.
for all obj's move use modules m_move's func move()
i add a hook called "obj_meet" in it.
when some obj need to  do sth when interacted  it just only need 
to write a func link to hook obj_meet()
i think this hook is useful in writing RPG game program.
i think it is better to add some RPG thing in our mud later.


---
����: ˹̹��(stefan)
��Ŀ: re: emperor
����: Tue Feb 29 12:00:50 2000
thanks for posting related stuff :) Lima has gone dead
for a few years, I really hope they can come back :P 

I never tried DGD, but I would guess its license is not that
"great" at all, still no good for commercial mud.

I am writing a new engine, and I have already informed each
individual in this sanguo wiz group. That is also why I
dont really have time to put effort on the web pages.


I will release it as GPL, soon everyone can take a look,
see wheather the design is better or not :)

text mud got no future.


---
����: �Ƶ�(emperor)
��Ŀ:  Mudlib for DGD
����: Tue Feb 29 09:38:31 2000
 Mudlib for DGD
The latest version of the Melville mudlib is stored in this directory.

Melville is a mudlib written by Stephen Schmidt (Mobydick) for the DGD
driver. It is a small starter mudlib which you can use to organize a
group of wizards for your own coding projects. It has a working mail
system, bulletin board, channel daemon, and room system so that you can
communicate as a group, a player/wizard/admin hierarchy of wizards to
organize code access, and support for most traditional LP features like
object inventories, command paths, object-defined commands, emotes and
soul commands, and so forth. It does not have any game features such as
combat, magic, races, or levels. This makes the mudlib more suitable
for non-game applications as well as leaving you free to implement any
game features you want in your own fashion. It has 49 commands,
23 for players and the rest for wizards or admins.

The current version of the lib, 0.9, takes up 89k compressed and will
uncompress to 399k; it contains 141 files. It unpacks to a single directory
calld melville which contains all of the code and supporting documentation.
To use it, you need to download and compile the DGD driver, which is probably
available on the same site as this. Version 0.9 of Melville should work
with version 1.1 of DGD.

Questions and feedback on Melville can be directed to Mobydick at
schmidsj@union.edu.




---
����: �Ƶ�(emperor)
��Ŀ: lima1.0a9 is release now
����: Tue Feb 29 09:17:25 2000
as title.


---
����: �Ƶ�(emperor)
��Ŀ: LPMUD FAQ֮һ
����: Tue Feb 29 09:16:39 2000

    Can I charge players to play my mud?
    
   If you write the server from scratch AND you wrote your mudlib from
   scratch and you have agreements with the coders who wrote areas on
   your mud, the answer, of course, is yes. The above will take roughly
   3-5 years of full-time work to accomplish as well.
   
   If you do not wish to go through all of that time to write your own
   server and object library, then you may only user DGD. Of course, you
   will have to get express permission from Dworkin. The only object
   library you may use for such purposes is LPMoo.
     


---
����: ˹̹��(stefan)
��Ŀ: about mirrors and admins
����: Tue Feb 29 08:11:15 2000
Just some explanation behind the mirror and admin arrangement..

I am controlling mirror application, but if somebody can help to
give any advice, I would really appreciate it. I am not very familar
with China's network situation, and ZJ site is open because it is
on 169 net, FZ site is open because it is on eduation net, TW site
is open because there is no other TW applicant, and I think it is
better to have some exposure in TW than none. Row and Emperor
have given me some advice on it, thanks.

The admin in mirrors. I feel terribly sorry after reading Fire's
email. I have to say it was not my intention to put myself as the
only Admin in the mirrors. The reason is PASSWORD. I chose not to
put any main site wizs' data files in the mirror package because
I am afraid when any of us types password, it would be snooped by
the mirror's root user, and would end up with main site being
hacked through wiz account. And I specially chose another password
for myself in the mirror package and change it immediately after
the mirror first booted up so that I have different password at
every single mirror site.

It has been suggested that every wiz here can take care of some  
of the mirrors by being Admin there, and I fully agree. But it is
dangerous for me to choose a password on your behalf, and I thought
it would be easier after I go in and promote the mirror-admin-to-be.
If this has offended any of our wizs, I would sincerely apologize.

I always feel quite delighted when seeing our wizs group can work
together in a happy and seamless fashion, and it is my fault that
I did not notice my action could have cause such a mis-understanding.
I never took it for granted that this mud is owned by me or by anybody.
All the wizs, as a group, are the owner. If you have ever contributed
some effort, even a single line of code, you are deserved to have
the joy of the success of this mud. It is also why earlier on I
dismissed the opinion of charging mirror sites for money in return.
Think about it, if we have $100 income, who gets $10 who gets $50?
Without any legal bound between us or a legal person to represent
the right, I would rather choose to have no income.

And also my thanks to fire, who pointed out my fault up and straight.
which is the way I always like when he deals with things.

I will post out mirror arrangement in a later post.

stefan


---
����: ˹̹��(stefan)
��Ŀ: hook is the way to go
����: Tue Feb 29 07:23:52 2000
If we had designed things more clearly :)


---
����: �һ�(fire)
��Ŀ: about trigger
����: Tue Feb 29 05:20:51 2000

flee is right, you can use /std/modules/m_trigers.c
but i don't think m_triggers.c is very good
if want better performance, perhaps just directly override
the receive_outside_msg and receive_private_msg.
however all this kind of things may make misjudge, because if 
you say something which matchs the patten, it will also react, 
but for common npc, that is ok. in order to make the parse of 
incomeing object more correctly better to use hook, but that 
may need adjust the environment so perhaps don't worth for 
this simple case


---
����: Fire
��Ŀ: >>>> ���
����: Tue Feb 29 05:17:58 2000
On Tue Feb 29 02:42:43 2000 ����(flee) wrote post #1114:
> i think the init() is disabled in lima lib
> for the functionality of it, such as suicide refered 
> ������, m_trigger servers the same purpose ..
> it should be located at /std/modules/m_trigers.c //not sure .. 

flee is right, you use /std/modulesm_trigers.c
but i don't think m_triggers.c is very good
if want better performance, better directly override
the receive_outside_msg and receive_private_msg
but all this kind of may make misjudge, because if you say something
match the patten, it will also react, but for common npc, that is
ok. in order to make the parse of incomeing object more correctly
better to use hook, but that may need adjust the environment
so perhaps don't worth for this simple case


---
����: ����(flee)
��Ŀ: >>> ���
����: Tue Feb 29 02:42:43 2000
i think the init() is disabled in lima lib
for the functionality of it, such as suicide refered 
������, m_trigger servers the same purpose ..
it should be located at /std/modules/m_trigers.c //not sure .. 


---
����: Suicide
��Ŀ: >>���
����: Tue Feb 29 02:39:18 2000
create() can only be called when obj first created.
but init() can be called when interacted by other things.
For example :
  when i enter a ��ջ the С�� object that had beed created before
can just say sth instead of using a random time to say .

inti() just like a ������.
if our mud haven't open this func i'd like to do it.
i have finished it in my own chinese lima bean.
xixi.


---
����: ����(flee)
��Ŀ: about ��������
����: Tue Feb 29 02:11:54 2000
i suggest use XKX's style, top 100 players will be
announced each week, however, only top 10 will be
recodered as history .. 


---
����: Flee
��Ŀ: >���
����: Tue Feb 29 02:10:19 2000
On Mon Feb 28 23:12:23 2000 ����ү(suicide) wrote post #1110:
> women 
> ���ǵ�mud��������es2�е�init()������?
try create()


---
����: ����ү(suicide)
��Ŀ: ���
����: Mon Feb 28 23:12:23 2000
women 
���ǵ�mud��������es2�е�init()������?


---
����: Group
��Ŀ: >to group
����: Mon Feb 28 01:51:33 2000
On Sat Feb 26 06:07:18 2000 ����(ice) wrote post #1102:
> > ����(kdkk)�����㣺qing feng cant searchwise
> > ����(kdkk)�ش��㣺�����ǻ��쵽�����
> > ����(kdkk)�ش��㣺�����ǻ��쵽�����
> ����(kdkk)�ش��㣺�˷�������� :(
> consider to do sth bah.:P
before i create them, i have set that whisper can not performed to
group's country.
seems i need adjust some code to make sure leave dont happen to my
npcs as well..

thank you for the bug..^^


---
����: ����(group)
��Ŀ: about the leave
����: Mon Feb 28 02:22:06 2000
is that reasonable to make those high loyalty and high skilled npcs
have very low 
leave rate? in sanguo time, this kind of npcs almost never move around..^^

group


---
����: Fire
��Ŀ: >����ϵͳ
����: Sat Feb 26 02:10:32 2000
On Sat Feb 26 01:08:18 2000 ˹̹��(stefan) wrote post #1098:
> �Ҿ���Ŀǰ�İ���ϵͳ��Ҫ����һ�£����鰴���·��ࣺ
> 
> �������  ������·  ��ɫ�ɳ�  ���ҽ���  
> 
> ս��ϵͳ  ���ĵ���  ��������  ��Ϸ����
> 
> ���л�����ϸ�֣���������ϵͳ����һĿ��Ȼ��á�˭������ݹ����أ�
> ���߿��������й������Ұ�æ������ rulin �� :)     

that's great, point . . . .
escape


---
����: ˹̹��(stefan)
��Ŀ: ����ϵͳ
����: Sat Feb 26 01:08:18 2000
�Ҿ���Ŀǰ�İ���ϵͳ��Ҫ����һ�£����鰴���·��ࣺ

�������  ������·  ��ɫ�ɳ�  ���ҽ���  

ս��ϵͳ  ���ĵ���  ��������  ��Ϸ����

���л�����ϸ�֣���������ϵͳ����һĿ��Ȼ��á�˭������ݹ����أ�
���߿��������й������Ұ�æ������ rulin �� :)     


---
����: Fire
��Ŀ: >strange thing
����: Sat Feb 26 00:18:32 2000
On Fri Feb 25 15:36:18 2000 ����(ice) wrote post #1092:
> I tried put gold in another body, then it got lost, it's reasonable.
> however, i dest myself then relog, the system says illegal copy 
> and then i found my gold back to my body.
> is that strange?.:P

the reason is you dest yourself, if quit will not have this problem


---
����: Ice
��Ŀ: >��������ѵ���ı��������������������
����: Fri Feb 25 22:50:34 2000
right, i think it's reasonable though it might be not our original
propose.  just like ������¼�, enemy cannot spy if the troops r out
to train.:P


---
����: ����ү(suicide)
��Ŀ: ��������ѵ���ı��������������������
����: Fri Feb 25 21:43:01 2000
as title


---
����: ����(ice)
��Ŀ: war bug bah
����: Fri Feb 25 21:11:50 2000
> ��ɽ(san)�����㣺we attack changan from xianyang
��ɽ(san)�����㣺we spyed a few minutes before war
��ɽ(san)�����㣺the troop in changan is 10k
��ɽ(san)�����㣺they have 20k mingbing and 20k+ troopin war

seems nowadays wiz not war at all? sb start a war to see see bah.:P


---
����: ����(ice)
��Ŀ: about info
����: Fri Feb 25 20:47:27 2000
nowadays the info become longer and longer, I think info a and info c
can be devided by using sub-order like the following:
info here/a will show basic info like weather,name,neighbours..
info here/a t will show troops info in detail
info here/a s will show stuffs here in detail
info me/c will show basic detail
info me/c r will show the relations....
blah blah
maybe later i can give a sample view of it.:P
how do u guys think about it?


---
����: ����(ice)
��Ŀ: strange thing
����: Fri Feb 25 15:36:18 2000
I tried put gold in another body, then it got lost, it's reasonable.
however, i dest myself then relog, the system says illegal copy 
and then i found my gold back to my body.
is that strange?.:P


---
����: ˹̹��(stefan)
��Ŀ: bug report from yesh
����: Fri Feb 25 11:36:04 2000
�߻�(yesh)�����㣺I guess there is some bug
�߻�(yesh)�����㣺we spy shouchun yesterday, they had only 20k+
�߻�(yesh)�����㣺but today they has 40k+
�߻�(yesh)�����㣺�᲻����bug
�߻�(yesh)�����㣺���� �����ϴ�͵Ϯ changan
�߻�(yesh)�����㣺սǰ 30 ���Ӳ�����spy ���ǲ� 10K+
�߻�(yesh)�����㣺��ʱȷ�� 20K+
�߻�(yesh)�����㣺����ֵ�
�߻�(yesh)�����㣺�Ҳ�����wiz������Ǽӱ�
�߻�(yesh)�����㣺����������bug
�߻�(yesh)�����㣺�Ұ���ǰ��longxi ��Ī������Ķ������
�߻�(yesh)�����㣺һ��֮��Ҫ��һ��������������������ܵ�
�߻�(yesh)�����㣺��ʱ������Ҫquit��
�߻�(yesh)�����㣺��ʱÿ��������æ�ñ�
�߻�(yesh)�����㣺longxi ԭ����ֻ�� 10k
�߻�(yesh)�����㣺һҹ֮�� ����� 20k
�߻�(yesh)�����㣺�����ʳ �� ��������
�߻�(yesh)�����㣺�ü���֮���ֹͣ��Ȼ����


---
����: �һ�(fire)
��Ŀ: about call
����: Sat Feb 26 05:49:20 2000
now the use of call is also loged as @
in /log/call
addoil


---
����: Ice
��Ŀ: >>����ϵͳ
����: Sat Feb 26 05:51:41 2000
point
blink


---
����: ����(ice)
��Ŀ: to group
����: Sat Feb 26 06:07:18 2000
> ����(kdkk)�����㣺qing feng cant searchwise
> ����(kdkk)�ش��㣺�����ǻ��쵽�����
> ����(kdkk)�ش��㣺�����ǻ��쵽�����
����(kdkk)�ش��㣺�˷�������� :(
consider to do sth bah.:P


---
����: ˹̹��(stefan)
��Ŀ: for reference :)
����: Sat Feb 26 10:30:35 2000
http://akiratsai.hypermart.net/disappoint-san-internet.html


---
����: ����(ice)
��Ŀ: about txt mud
����: Thu Mar  2 11:20:57 2000
I think txt mud won't die for the near future, at least i like
the txt mud.:P  suicide is right, we dun have graphical designer
in our team bah.:P  if need to develop a graphical version, we
need at least half dozen wiz to work for the graphic
on the other side, i apperiate graphical version bcoz it's more
visible, and more attractive .:P
however, in my experience, I have seen a mud died bcoz the wiz team
r emphasize to develop the graphical version, then both project died...
* fear
if we r intending to develop a graphical version, we need to state
clearly the task allocation, otherwise we'll get in the same way of
the dead canada sanguo mud.:P
regards.:)


---
����: ����(ice)
��Ŀ: about development
����: Thu Mar  2 11:27:03 2000
today i logged in then queried by player.:(
they query that why qibing is changed to less useful now, it wasted
me a lot of time to explain it.  and a player said that why we put
some not mature projects in the game......
it reminds me a little, we r socalled "officially opened" now bah,
thus we cannot announce it's a developing mud, it's a test version...
so i think maybe we can work in this way, we can establish a test
site for test only, player are welcome to login that site, but will
be warned that all the data in that site is just for test, however, 
they have rights to test the latest developing project there, it can
be called our lab there.:P
just a thought in mind, how do u guys think about that?


---
����: ˹̹��(stefan)
��Ŀ: graphics and text
����: Thu Mar  2 13:16:08 2000
A good MUD does not die because it is text based, but
its future is definitely limited due to the text contraint,
due to the underlining engine, be it a LPmud or DGD.

A good point that ice mentioned is about the team and the 
focus. I totally agree with that. So far I have seen
XYJ, XKX and FY being successful, but all of them have stopped
development more or less. Why? There isn't much space left :)
Also, wizs come and wizs go, people get lazy when a MUD
gets to a certain stage. 

Graphics sure takes a lot of effort to develop, and not every
mud got that resource, especially human resource. I would not
think it is a easy task to accomplish. But again, compared to a
graphics mud, the text based mud is much limited. I appreciate
the beauty of literature, but how many people actually pay 
attention to the room description after playing for a month? :)

Being a compromise to both sides, I would envision
a mud that supports both text and graphics, independantly. 
It is pointless to talk about graphics mud without a good engine
to support it, and that is just the engine alone, for the 
 graphics mud to be successful, the client is very crucial.

If any mud ever gets from a text based to that stage, it
is either converted to a real company with finacial support, 
or a complete open source project where everybody works for
free, but definitely not the current style where only wizards
hold the code and players never get them. The current style
suffers from the license problem. All of XKX, XYJ, FY and SGZ 
have this problem, but ES2 and Lima do not because their
source code is released to everyone.

An example is Graphics King of Kings. GKK can be found
at http://www.lager.com.tw/gkk/ and its ancestor KK
can be found at http://www.lager.com.tw/muds/kk/, which
was originally based on ES2. They run into license
problem.


---
����: �һ�(fire)
��Ŀ: about findfile
����: Thu Mar  2 19:19:57 2000
The reason for findfile can't build up a search database
properly is under the /data/M, there are about 15356 files.
so the mud's file system can't hold too many files under
one directory.
The files under this directory are all the mudmails. one
mail will create one file. And i don't know if a ppl suicide
or purged, still his mails keep here or not. Now I let the 
findfile skip this directory. so findfile is ok. But later
we may need improve lima's mudmail system.



---
����: Row
��Ŀ: >about development
����: Thu Mar  2 20:49:33 2000
as the matter of fact, our sanguo is officially open though we
didnt exclaim that. players play this mud for real and really enjoy
their moments here, which is a great honor of all of our wizs. however,
this doesnt mean a stop to development but more like a push, we need to
keep our mud a fresh and wonderful world so that it may attract more ppl.
as the problem pointed out by ice, it is true and was surfaced b4, but,
as far as i can see, players r busy here (as we hoped :P) and wont have
enuf time to spend in another test site although it wont be troublesome
for us to open such one. so, the current situation demands our wiz team
to consider very carefully b4 releasing any new projects, besides, we need
to set the changes to the minimum in order not to cause big loss in case there
r bugs. anyway, the current situation is satisfying, players r cooperative
and know how to raise their suggestions at proper way and time.

God bless us.


---
����: ����(row)
��Ŀ: about national officer positions
����: Thu Mar  2 21:23:56 2000
��������ұ�Թ���ҹ�Ա��λ��̫�٣�����Ҫ����˶ࡣ
����Ϊ��Ȼ���ǲ�����ÿ���˶��ܵ��Ϲ��ҹ�Ա����Ҳ
�����ʵ��������������ְλ�������Ϊ��Σ�


---
����: Suicide
��Ŀ: >>about development
����: Thu Mar  2 21:39:41 2000
I agree with row.
If we add a new development site how to attract ppl to just help us test?
So the right way is still develop at this site. 
But we could post a title at the caolu to tell ppl that what condition 
we met. When we add some new function here we have to need there test.
For we can't test the new function anywhere else.
Get their understanding i think thry will support us.


---
����: ����(row)
��Ŀ: ��վ��ҵ����
����: Thu Mar  2 22:06:23 2000
zjվ��ұ�Թ�ҳ�Ϊ100��npc ��Ұ����̫���Ƿ�Ӧ��
��Ϊ�������ҳϲ���100��npc��Ұ��Ȼ�����ֵ�100�ġ�


---
����: Fire
��Ŀ: >about national officer positions
����: Thu Mar  2 22:27:41 2000
On Thu Mar  2 21:23:56 2000 ����(row) wrote post #1141:
> ��������ұ�Թ���ҹ�Ա��λ��̫�٣�����Ҫ����˶ࡣ
> ����Ϊ��Ȼ���ǲ�����ÿ���˶��ܵ��Ϲ��ҹ�Ա����Ҳ
> �����ʵ��������������ְλ�������Ϊ��Σ�

it is you who is undertaking the development of emperor country
hehe row
addoil row
when they got empire, they should have enough position lah
hoho row
massage row


---
����: Fire
��Ŀ: >��վ��ҵ����
����: Thu Mar  2 22:28:05 2000
On Thu Mar  2 22:06:23 2000 ����(row) wrote post #1143:
> zjվ��ұ�Թ�ҳ�Ϊ100��npc ��Ұ����̫���Ƿ�Ӧ��
> ��Ϊ�������ҳϲ���100��npc��Ұ��Ȼ�����ֵ�100�ġ�

now it is the way mah
xixi


---
����: Row
��Ŀ: >>about national officer positions
����: Thu Mar  2 23:58:18 2000
On Thu Mar  2 22:27:41 2000 Fire wrote post #1144:
> On Thu Mar  2 21:23:56 2000 ����(row) wrote post #1141:
> > ��������ұ�Թ���ҹ�Ա��λ��̫�٣�����Ҫ����˶ࡣ
> > ����Ϊ��Ȼ���ǲ�����ÿ���˶��ܵ��Ϲ��ҹ�Ա����Ҳ
> > �����ʵ��������������ְλ�������Ϊ��Σ�
> 
> it is you who is undertaking the development of emperor country
> hehe row
> addoil row
> when they got empire, they should have enough position lah
> hoho row
> massage row

faint, i didnt finished union yet....sigh


---
����: �һ�(fire)
��Ŀ: the meet event
����: Thu Mar  2 04:31:53 2000
suicide has introduced the idea about when you enter 
a room the npc should greet the players. that's good
But I think suicide's method may use more cpu power
than necessary. I have created three modules can handle
this problem. The three modules are
1 M_MEETPLACE /sgdomain/modules/m_meetplace.c
2 M_GREETER /sgdomain/modules/m_greeter.c
3 M_GUEST /sgdomain/modules/m_guest.
for example, if you enter a store and the keeper will
auto welcome you. then, the room should inherit the
m_meetplace, the keeper inherit the m_greeter and you
inherit m_guest. then in order to make the hook work
the m_meetlace should be started by using set_can_meet(1)
Now i make the base_room inherit the m_meetplace and
body inherit the m_guest and all the makers inherit
the m_greeter so you will be welcomed when you enter a
store:) and there is still another event called do_send
that will happened when you leave the store. this kind
of functions can also be used to other objects.
addoil:)


---
����: ����(row)
��Ŀ: about post
����: Tue Mar  7 00:48:10 2000
��ͬ������ʦ��������post�������Ϲ���Ա�������
������˼�ǣ���ʦ�����ж����ĺ�����ת�ص��ض���board����
jury member�Ķ���Ȼ����Խ���ͶƱ��������ɹ�����ͶƱ
����ã���������dummy�����ⲻ���׽�����͸ĳ������Ϲ���
Ա����ɣ�����Ӧ���ܹ���������ҵ������wizӦ��Ҳ��
��ͶƱ�����ڶ����һ�Σ�һ�ܵĻ����ܺ����²��࣬һ��
�Ļ�����ʱ����̫����������Σ������ܽ��󻹿��Խ���
�½�����ѡ(������һ��)�����ڵ���̨���Ǿ�������һ����
�����������ο���


---
����: ����ү(suicide)
��Ŀ: i met the same thing as tking and zeda
����: Mon Mar  6 08:52:08 2000
who -w
*Bad argument 1 to call_other()
Expected: string or array or object Got: 0.
Trace written to /log/runtime
�� ����־��վ ��  ������ʱ�䣺��ǧ���������������ʱ��ʮ�߷֣�
������ʦ�б���Ŀǰ��������5��
��������������������������������������������������������������������������
���������ں���������ܡ�����������ү���ֺǺ�(suicide)
��   ����   �������������ˡ�t���Ƶ�(emperor)
��  ��֮��  ����֮����������(group) [���� 2 ����]
����ƽ���ں��֮������������ɫ��ûɫ�����һ��ֺٺ�(fire)
��������������������������������������������������������������������������
>l
Can't use verb with no body.
when i reconected half a min later.
i am in /domains/std/void.c


---
����: ����ү(suicide)
��Ŀ: ����
����: Mon Mar  6 08:53:55 2000
������ΪͻȻ�����һ���޷�����Ҳ����Ļˢ�µ������,reconect ��.
����ͬʱ�ҵ�����������������.


---
����: ˹̹��(stefan)
��Ŀ: web page development
����: Mon Mar  6 10:13:13 2000
I will make all the webpages accessible through CVS.
So anybody who wants to make contributions
please feel free :)

also agree with Group's opinion on post system.

BTW, I am on a trip, dont expect me to get 
anything done soon :PP sorry ..


---
����: ����(row)
��Ŀ: about post
����: Tue Mar  7 00:48:10 2000
��ͬ������ʦ��������post�������Ϲ���Ա�������
������˼�ǣ���ʦ�����ж����ĺ�����ת�ص��ض���board����
jury member�Ķ���Ȼ����Խ���ͶƱ��������ɹ�����ͶƱ
����ã���������dummy�����ⲻ���׽�����͸ĳ������Ϲ���
Ա����ɣ�����Ӧ���ܹ���������ҵ������wizӦ��Ҳ��
��ͶƱ�����ڶ����һ�Σ�һ�ܵĻ����ܺ����²��࣬һ��
�Ļ�����ʱ����̫����������Σ������ܽ��󻹿��Խ���
�½�����ѡ(������һ��)�����ڵ���̨���Ǿ�������һ����
�����������ο���


---
����: ˹̹��(stefan)
��Ŀ: web page development
����: Mon Mar  6 10:13:13 2000
I will make all the webpages accessible through CVS.
So anybody who wants to make contributions
please feel free :)

also agree with Group's opinion on post system.

BTW, I am on a trip, dont expect me to get 
anything done soon :PP sorry ..


---
����: ����(row)
��Ŀ: about post
����: Tue Mar  7 00:48:10 2000
��ͬ������ʦ��������post�������Ϲ���Ա�������
������˼�ǣ���ʦ�����ж����ĺ�����ת�ص��ض���board����
jury member�Ķ���Ȼ����Խ���ͶƱ��������ɹ�����ͶƱ
����ã���������dummy�����ⲻ���׽�����͸ĳ������Ϲ���
Ա����ɣ�����Ӧ���ܹ���������ҵ������wizӦ��Ҳ��
��ͶƱ�����ڶ����һ�Σ�һ�ܵĻ����ܺ����²��࣬һ��
�Ļ�����ʱ����̫����������Σ������ܽ��󻹿��Խ���
�½�����ѡ(������һ��)�����ڵ���̨���Ǿ�������һ����
�����������ο���


---
����: ����ү(suicide)
��Ŀ: CVS will be supported in which OS?
����: Mon Mar  6 10:26:33 2000
as title.


---
����: ˹̹��(stefan)
��Ŀ: web page development
����: Mon Mar  6 10:13:13 2000
I will make all the webpages accessible through CVS.
So anybody who wants to make contributions
please feel free :)

also agree with Group's opinion on post system.

BTW, I am on a trip, dont expect me to get 
anything done soon :PP sorry ..


---
����: �һ�(fire)
��Ŀ: hp rob
����: Mon Mar  6 06:06:52 2000
��������״��������̬��������
����Ѫ��   318 / 318 ( 318 )  
�Ѿ����  -87287 /-198 (-198 )  
��ʳ���   114 / 200  
����ˮ��   114 / 200  
������������������������־��

flee, please check the formula for spirit


---
����: ����ү(suicide)
��Ŀ: ��������.
����: Mon Mar  6 05:46:55 2000
Ϊ�������Ҳ�ܼ��뵽���mud�Ĵ�����
��������һ�����͹����,����ʦ��������ռ��й�������.
����ṩ�����ϱ����ɺ����һ���Ľ���.
��������������ǰ��ȷ��,����͸����.
�������Լ�����ʦһЩ�ռ�����,����asc image ��ѹ��


---
����: ����(group)
��Ŀ: firework
����: Mon Mar  6 05:35:41 2000
firework done. /wiz/group/firework.c
add it in marriage ba


---
����: Row
��Ŀ: >���㽨��,��Ҷ෢��
����: Sun Mar  5 22:50:46 2000
its a really good suggestion.


---
����: ����ү(suicide)
��Ŀ: kick fire
����: Sun Mar  5 20:49:22 2000
reply�������.


---
����: Fire
��Ŀ: >���㽨��,��Ҷ෢��
����: Sun Mar  5 20:45:35 2000
aggree suicide, 


---
����: �һ�(fire)
��Ŀ: ����°�ĭ���赹�ڵء�
����: Sun Mar  5 18:59:56 2000

who -n
�� ����־��վ ��  ������ʱ�䣺��ǧ����������������ʱ��ʮ�߷֣�
�������������򣽩�Ŀǰ��������27��
������������������������������������������������������������������������
��
��   ����   ��������������˼����(zeda) [���� 11 ����]
��   ����   ��������������˼����(zeda) [���� 11 ����]
��   ����   ��������������˼����(zeda) [���� 11 ����]
��   ����   ��������������˼����(zeda) [���� 11 ����]
��   ����   ��������������˼����(zeda) [���� 11 ����]
��   ����   ��������������˼����(zeda) [���� 11 ����]
��   ����   ��������������˼����(zeda) [���� 11 ����]
������������������������������������������������������������������������
��

˼�������˹�����
˼���Ƴ������뿪�ˡ�
˼�������˹�����
˼���������������<job>����Ϣ��
���˼����Ц����С�ֵ����ҵ��¸ɣ������ְ��������������ȥ�ʱ��ش峤��
faint
����°�ĭ���赹�ڵء�
˼����˵����hi.
say how could you login so many copy ?
��˵����how could you login so many copy ?
whoip zeda
Ŀǰ�� 9 λ�� 216.154.8.66 ���ߵ����:
(login), zeda, zeda, (login), zeda, zeda, zeda, zeda, zeda.
> ˼����˵����is a problem on net.
˼����˵����sometime when i log in it didnt show chinese.
��˵����what problem ?
��˵����then ?
> ˼����˵����some i have to keep try.
˼����˵����it happen again.
��˵����can you order other copies of your self ?
˼����˵����i m reading ����
��˵����oh.
��˵����do you select gb ?
> ˼����˵����so i can see what u writting.
��˵����do you select gb or big5 ?
snoop zeda
�ɹ���
> %s%ay wait here ill try agian and we will see
%��˵����wait here ill try agian and we will see.
˼����˵����wait here ill try agian and we will see.
����˵�ͷ��
%�һ���˵�ͷ��
> snoop
�ɹ���
> l
��ϵͳ����������������־��վ��
������������˼����(zeda) [���� 15 ����]
������������˼����(zeda)
˼�����뿪������־��վ��
��ϵͳ��˼�����뿪������־��վ��
˼����һ��ȭ��Ҫ�����ˡ�
��ϵͳ��˼���ƽ�������־��վ��
˼����һ��ȭ��Ҫ�����ˡ�
˼���ƽ�������־��վ��
l
��Ӫ [���ڣ�west, south]

    �������������פ��Ӫ�أ�һ������ɫ�������е��������룬��
���߲ʵ����ӭ��Ʈ�ɷ��׳�ۡ�Ӫ����ʿ�����е��ڿյش��ж�
�������е�����Ѳ�ߣ��е�æ��������������������������������
�������ֵĵط��ˡ���Ӫ��������һ�����ӣ��ǽ��������µĵط���

�������ġ�����219�����ԡ�(board)
�Թ�������������(yang zuo)
�Թ�ƫ�������࣬�֟o��(chenqing)
�Թ��������ʯ����������(shi bao)
�Թ�������ܷѹۣ�������(fei guan)

������������˼����(zeda) [���� 16 ����]
������������˼����(zeda)
����ͷ������ġ�Ŷ����һ�����ƺ�������ʲô���ֺ���û����
��˵����can you read chinese this time ?
> ˼�����뿪������־��վ��
��ϵͳ��˼�����뿪������־��վ��
˼����һ��ȭ��Ҫ�����ˡ�
��ϵͳ��˼���ƽ�������־��վ��
˼����һ��ȭ��Ҫ�����ˡ�
˼���ƽ�������־��վ��
l
��Ӫ [���ڣ�west, south]

    �������������פ��Ӫ�أ�һ������ɫ�������е��������룬��
���߲ʵ����ӭ��Ʈ�ɷ��׳�ۡ�Ӫ����ʿ�����е��ڿյش��ж�
�������е�����Ѳ�ߣ��е�æ��������������������������������
�������ֵĵط��ˡ���Ӫ��������һ�����ӣ��ǽ��������µĵط���

�������ġ�����219�����ԡ�(board)
�Թ�������������(yang zuo)
�Թ�ƫ�������࣬�֟o��(chenqing)
�Թ��������ʯ����������(shi bao)
�Թ�������ܷѹۣ�������(fei guan)

������������˼����(zeda) [���� 16 ����]
������������˼����(zeda)
> ˼����˵����k.
say ok ?
��˵����ok ?
˼����˵����what u think is prblem.
whoip zeda
Ŀǰ�� 9 λ�� 216.154.8.66 ���ߵ����:
zeda, zeda, (login), zeda, zeda, zeda, (login), zeda, zeda.
��˵����dunno.
��˵����can you order all the zedas or just one zeda ?
˼����˵����will i hop all but one.
��Ц���������������ˣ����ڵ���ֱ�����
��˵����ok, please logout and let me dest all the zeda.
��˵����then you login again after 5 mins ok ?
> ˼����˵����what is prper way to log out.
��˵����quit.
> ˼����˵����just close?
����˵�ͷ��
> ˼�����뿪������־��վ��
��ϵͳ��˼�����뿪������־��վ��
˼����һ��ȭ��Ҫ�����ˡ�
��˵����then wait 5 min then login again.
> l
��ϵͳ��˼���ƶ����ˡ�
��ϵͳ��˼�����뿪������־��վ��
˼���ƶ����ˡ�
��ϵͳ��˼���ƶ����ˡ�
˼�����뿪������־��վ��
��ϵͳ��˼�����뿪������־��վ��
˼����һ��ȭ��Ҫ�����ˡ�
��ϵͳ��˼���ƶ����ˡ�
��ϵͳ��˼�����뿪������־��վ��
��ϵͳ��˼���ƶ����ˡ�
��ϵͳ��˼�����뿪������־��վ��
��ϵͳ��˼���ƶ����ˡ�
��ϵͳ��˼�����뿪������־��վ��
��ϵͳ��˼���ƶ����ˡ�
��ϵͳ��˼�����뿪������־��վ��
whoip zeda
û���˴��Ǹ���ַ���ߡ�
����°�ĭ���赹�ڵء�
��˵����all leave at one moment.



---
����: ����(ice)
��Ŀ: 2 bugs setback after hacked
����: Sat Mar  4 00:31:27 2000
1. yuzhang south gate is not accessable by player( cannot s from
   south street)
2. luling is a lv 1 area, but it's now lv 4!.:(
pls fix it


---
����: �һ�(fire)
��Ŀ: marriage bug in mirror
����: Fri Mar  3 23:00:21 2000
��վ��鲿�ֵ�BUG��Ҫ����Ϊ
��վ�Ľ�ɫ��û��li guan,si ye��NPC��
�ҵ����˳��򣬲�����Ҫ�����ǽ�ɫ�ˡ�
��վӦ�ÿ�����������ˡ�


---
����: ����(row)
��Ŀ: change chinese id
����: Thu Mar 23 08:16:48 2000
����޸�һ��id���������֣��������id�����Ļ���


---
����: �һ�(fire)
��Ŀ: about rumor
����: Thu Mar 23 06:50:45 2000
now wiz can view the sender's id as well as the name :)


---
����: Row
��Ŀ: >train bug
����: Thu Mar 23 06:34:30 2000
On Thu Mar 23 05:50:19 2000 �һ�(fire) wrote post #1275:
> ͬ����id����ѵ����ʹ�����ӱ���
> ż��һ�λ��Ǵδ���ˣ����Թ�û�У�
> doubt

we can test...:)


---
����: �һ�(fire)
��Ŀ: train bug
����: Thu Mar 23 05:50:19 2000
ͬ����id����ѵ����ʹ�����ӱ���
ż��һ�λ��Ǵδ���ˣ����Թ�û�У�
doubt


---
����: Suicide
��Ŀ: >npc
����: Thu Mar 23 03:32:37 2000
agree row;


---
����: ����(row)
��Ŀ: npc
����: Wed Mar 22 23:10:38 2000
�ţ��һ�����ΪNPC�����ļ���̫����Щ������letter�Ĺ���̫ǿ��
�Ƿ����ҳ�95���ϵ�NPC����Ұ���ʣ���ÿ����������NPC�Զ���1-2��
�ҳϣ�letter�ɹ����Դ���Ƚ�NPC�ҳϣ���ֻ�ж��ҳ�С��70��NPC
������١��һ���Ϊ��Σ�


---
����: ����(ice)
��Ŀ: ?
����: Wed Mar 22 00:27:03 2000
��ϵͳ��������������־��վ��;��ϵͳ���ٺٽ�������־��վ��
i used whoip and idfind, get only 1 body get in, so ...
what's wrong?


---
����: �һ�(fire)
��Ŀ: about nanhua
����: Tue Mar 21 21:56:22 2000
because for a new xianren, need update the data
in char_d, but char_d can't auto update because it 
includes so many player related data, so in each mirror
the wiz need to do the following things to update the
nanhua

call /daemons/char_d,add_char,nanhua laoxian
call /daemons/char_d,set_char,nanhua laoxian,name,�ϻ�����
call /daemons/char_d,set_char,nanhua laoxian,body,xianren/nanhua
call /daemons/char_d,set_char,nanhua laoxian,is_xianren,1
call /daemons/char_d,set_char,nanhua laoxian,is_tmp,1

addoil :)


---
����: Fire
��Ŀ: >move new discard.c
����: Tue Mar 21 21:48:24 2000
On Tue Mar 21 19:23:00 2000 ����ү(suicide) wrote post #1268:
> I have made a little mistake with "||" in if sentence.xixi
> It should be "&&".I have modified it in /wiz/suicide/discard.c.
> pls move it to /cmds/verbs.
> by the way can give me the write right of "/cmds/verbs"?
> So i can do it as soon as i finished it.

i will move the discrad.c and give you the write priviliage later :)
addoil suicide


---
����: ����ү(suicide)
��Ŀ: move new discard.c
����: Tue Mar 21 19:23:00 2000
I have made a little mistake with "||" in if sentence.xixi
It should be "&&".I have modified it in /wiz/suicide/discard.c.
pls move it to /cmds/verbs.
by the way can give me the write right of "/cmds/verbs"?
So i can do it as soon as i finished it.


---
����: Row
��Ŀ: >about the rumor
����: Tue Mar 21 09:17:27 2000
On Tue Mar 21 05:04:04 2000 �һ�(fire) wrote post #1266:
> now wiz can see who is sending rumors
> sigh

better add id after chinese name...
sweat fire


---
����: �һ�(fire)
��Ŀ: about the rumor
����: Tue Mar 21 05:04:04 2000
now wiz can see who is sending rumors
sigh


---
����: �һ�(fire)
��Ŀ: about discard
����: Tue Mar 21 04:41:45 2000
I have modified the new_d
so a king has right to remove his nation's post

so suicide just focus on the discard.c bah xixi


---
����: ����ү(suicide)
��Ŀ: about discard.c
����: Tue Mar 21 04:19:40 2000
Can i add a new func called "force_remove_post" in news_d
for emperor using to discard the title posted by others?
Then it will affect nothing about any other code using func of news_d.


---
����: Fire
��Ŀ: >about info
����: Tue Mar 21 02:02:54 2000
On Tue Mar 21 00:57:11 2000 ����(ice) wrote post #1259:
> ����ʦ������(ice)��info s;û���������ʡ�;> info s all;û���������ʡ�
> ����ʦ������(ice)��so do info n...
> ����ʦ������(ice)��so add a info x all?
> ����ʦ������(ice)��or info xa ...
> just like the info n, info a b4, can show all the brief?
info s list
xixi


---
����: ����(ice)
��Ŀ: a typo.:(
����: Tue Mar 21 01:08:00 2000
info j
the lv 10 need 2000000 repu, seems it was my typo.:(
how about change it to 1m rep?
* fool
i have forgotten the cmd to change it, fire tell me again?
* escape


---
����: ����(ice)
��Ŀ: runan warmap
����: Tue Mar 21 01:01:33 2000
cmd warmap runan
is it that default warmap b4?
seems it's not updated.:P
sb just draw one bah
and if have time, pls check if there is some left is using default
warmap bah.:)
* addoil



---
����: ����(ice)
��Ŀ: about info
����: Tue Mar 21 00:57:11 2000
����ʦ������(ice)��info s;û���������ʡ�;> info s all;û���������ʡ�
����ʦ������(ice)��so do info n...
����ʦ������(ice)��so add a info x all?
����ʦ������(ice)��or info xa ...
just like the info n, info a b4, can show all the brief?


---
����: Row
��Ŀ: >a discovery
����: Tue Mar 21 00:38:03 2000
On Tue Mar 21 00:36:31 2000 ����(ice) wrote post #1257:
> if I do xu zijiang's job, then I don't need to take any transportation
> tool to my destination anyway, bcoz the xian ren trans me to the
> destination at that time, so he is my horse? it takes no time from
> yunnan to bailangshan .:P
> * snicker

yeah, this trick may be found by players already, they just dont report
as they always did...hehe.


---
����: ����(ice)
��Ŀ: a discovery
����: Tue Mar 21 00:36:31 2000
if I do xu zijiang's job, then I don't need to take any transportation
tool to my destination anyway, bcoz the xian ren trans me to the
destination at that time, so he is my horse? it takes no time from
yunnan to bailangshan .:P
* snicker


---
����: Fire
��Ŀ: >info a
����: Mon Mar 20 17:29:01 2000
On Mon Mar 20 07:08:46 2000 ����(row) wrote post #1255:
> the info aa got problem, may be caused by disable ev_merchant.
> pls check.

yes, it is, i will fix it asap :)
sorry for that


---
����: ����(row)
��Ŀ: info a
����: Mon Mar 20 07:08:46 2000
the info aa got problem, may be caused by disable ev_merchant.
pls check.


---
����: ����ү(suicide)
��Ŀ: �����ϻ�����Ԥ��fate
����: Mon Mar 20 03:27:33 2000
file have move to /sgdomian/modules/m_charnp/xianren/nanhua.c
pls check and open it.


---
����: Fire
��Ŀ: >a bit triuble with discard
����: Mon Mar 20 02:32:28 2000
On Sun Mar 19 23:40:53 2000 ����ү(suicide) wrote post #1251:
> Fire:
>     For in news_s it still has a limit to delete the others title 
> i can't finish the new discard.c unless rem some judgement code in the
news_d.
>    To modified the news_d i think it should get ur agree for maybe my doing 
> will bring some bug about news.
>    Do u have some idea to avoid this?
let me check your code first :)
addoil


---
����: ˹̹��(stefan)
��Ŀ: discard
����: Sun Mar 19 23:47:23 2000
maybe the right way is not to "discard" it, just "hide" it.
Still needs to modify news_d, but can avoid accedental mistakes.


---
����: ����ү(suicide)
��Ŀ: a bit triuble with discard
����: Sun Mar 19 23:40:53 2000
Fire:
    For in news_s it still has a limit to delete the others title 
i can't finish the new discard.c unless rem some judgement code in the news_d.
   To modified the news_d i think it should get ur agree for maybe my doing 
will bring some bug about news.
   Do u have some idea to avoid this?


---
����: Stefan
��Ŀ: >������Ƶ�����crash���ַ����ĳ��Ȳ��ܳ������512�ֽ�
����: Sun Mar 19 10:20:07 2000
On Sun Mar 19 07:55:41 2000 �Ƶ�(emperor) wrote post #1246:
> ������Ƶ�����crash���ַ����ĳ��Ȳ��ܳ������512�ֽ�
> �����������޹�

I fixed it the other day to make maxum input line to be 240 characters.
But seems fire found that "to" command also causes this
bug, better fix it some time later.

but anyway, "to" is only used by wizs, we just be cautious :)


---
����: ˹̹��(stefan)
��Ŀ: player recovery
����: Sun Mar 19 10:13:59 2000
We have backups since January. The backup works this way..
Every month there is a backup.
Every week there is a backup, the last week's backup
will replace that month's monthly backup.
Every day there is a backup, the last daily
backup becomes a weekly backup.

All together, only 7 daily backups from Sunday to Saturday.
For past months, only monthly backup exists;
for past weeks, only weekly backup exists.

So, I can get both rical and leeye's data back,
but may not be the most recent one.


---
����: �Ƶ�(emperor)
��Ŀ: ������Ƶ�����crash���ַ����ĳ��Ȳ��ܳ������512�ֽ�
����: Sun Mar 19 07:55:41 2000
������Ƶ�����crash���ַ����ĳ��Ȳ��ܳ������512�ֽ�
�����������޹�


---
����: �һ�(fire)
��Ŀ: a crash
����: Sun Mar 19 05:37:47 2000


use to chat or to sgz can cause crash
so if we have to use to chat or to sgz
please make sure the input no more than 5 lines
if it is more than 5 lines, it's better seperate it
into several parts. hoho :)


---
����: ����ү(suicide)
��Ŀ: modify discard.c
����: Sat Mar 18 21:32:12 2000
Today hei told me if the emperor can delete the useless title in
their own country.
So i modify the discard.c .
But i have no right to write /cmds/verbs to replace the old file.
Please help me remove /wiz/suicide/discard.c /cmds/verbs if can .


---
����: Flee
��Ŀ: >>bug log
����: Fri Mar 17 19:58:30 2000
On Fri Mar 17 06:30:16 2000 Fire wrote post #1242:
> On Fri Mar 17 06:28:58 2000 ����(row) wrote post #1241:
> > �����ϵͳ���ü�����ʳ���ĵ�ʱ�򣬰ѱ�����ȥѵ������ô
> > ��ʳ�Ͳ����ˡ�
> 
> this is a bug, maybe we can fix it in the future
> that troop will consume food and gold in train and war
that's right, troop will consume more food and gold in
train and war than in rest ... *hehe


---
����: Fire
��Ŀ: >bug log
����: Fri Mar 17 06:30:16 2000
On Fri Mar 17 06:28:58 2000 ����(row) wrote post #1241:
> �����ϵͳ���ü�����ʳ���ĵ�ʱ�򣬰ѱ�����ȥѵ������ô
> ��ʳ�Ͳ����ˡ�

this is a bug, maybe we can fix it in the future
that troop will consume food and gold in train and war


---
����: ����(row)
��Ŀ: bug log
����: Fri Mar 17 06:28:58 2000
�����ϵͳ���ü�����ʳ���ĵ�ʱ�򣬰ѱ�����ȥѵ������ô
��ʳ�Ͳ����ˡ�


---
����: Group
��Ŀ: >the warmap bug
����: Fri Mar 17 01:26:18 2000
On Thu Mar 16 08:02:48 2000 �һ�(fire) wrote post #1239:
> group fixed it ?
> oh, great, addoil :)
yap..forgot to post..:P

group


---
����: �һ�(fire)
��Ŀ: the warmap bug
����: Thu Mar 16 08:02:48 2000
group fixed it ?
oh, great, addoil :)


---
����: Fire
��Ŀ: >a small bug
����: Thu Mar 16 02:27:19 2000
On Thu Mar 16 01:49:31 2000 ����(row) wrote post #1236:
> a bug of digsoil, when the field is ok, a player can turn mutong, and then
> he will have busy time, but if he try to dig the soil once more and get
> the msg that its no necessary to dig the soil anymore, he is able to
> dig the soil rightaway, seems its the bug of busy time.

yes it is :P
I will try to fix it
addoil


---
����: ����(row)
��Ŀ: the shutdown bug
����: Thu Mar 16 01:59:49 2000
urgent!!! i think this should be solved the first, someone just wanna
destroy sanguo by keep on rebooting...sigh


---
����: ����(row)
��Ŀ: a small bug
����: Thu Mar 16 01:49:31 2000
a bug of digsoil, when the field is ok, a player can turn mutong, and then
he will have busy time, but if he try to dig the soil once more and get
the msg that its no necessary to dig the soil anymore, he is able to
dig the soil rightaway, seems its the bug of busy time.


---
����: ����(row)
��Ŀ: to fire
����: Wed Mar 15 23:59:33 2000
how to change a player's password, i mean as an admin.


---
����: �һ�(fire)
��Ŀ: I know a way to crash the mud
����: Wed Mar 15 18:23:54 2000
to chat a long article (100 lines or so)
especially there are about 50 ppl onlines
tset also got some way to crash our mud, I forget the
detail, seem find sth from the core dump



---
����: ˹̹��(stefan)
��Ŀ: mudos
����: Wed Mar 15 11:35:27 2000
the mudos used here is fairly unstable, I already fixed
quite a few, but since row has found more, there
could be many others :PP 

Simply by dropping objects in a room won't cause ES2
MudoS (an old version) to hang, Iremembered that
I tested in lima too, no such bug. but I am not sure :P

if a player post a too long article, it would usually cause a buffer
overflow, MudOS should discard the buffer to avoid overflow..
dunno why it will kill the mudos, this could be a really serious
bug.

Bombing ports, well, no way to protect MudOS against this,
simple cure maybe to restrict concurrent connection from
the same IP. It would not work if they guy is issuing millions
of open TCP connection from his own machine :P

anyway, current mudos is just too hard to fix, anybody got any idea
when new mudos is going to be released?


---
����: ����(row)
��Ŀ: hmm...
����: Wed Mar 15 00:57:57 2000
today, i talked with a player in zj site, he is the guy who reported those
two reboot bugs. he said there r many potential OS bugs in sanguo, and gave
example that keep on logining new id will hang on the system too. in addition,
he said he found there is a guy used to attack sanguo by bombing the port,
so i am worried about the security of the system.

stefan has any better solutions?


---
����: �һ�(fire)
��Ŀ: admire row
����: Tue Mar 14 23:47:28 2000
i will check these bugs


---
����: ����(row)
��Ŀ: a bug which can add soldier after reboot
����: Tue Mar 14 23:41:50 2000
use two ids with same chinese name, then announce a war. put 1 id
as general and assign certain number of troops, then cause shutdown,
when system is restarted, that 2 ids can both take the same number of
troops back to the city.


---
����: ����(row)
��Ŀ: the bugs cause shutdown
����: Tue Mar 14 23:37:18 2000
1, if a player intends to post a very long article, the system
cannot handle and will shutdown immediately.
2, in the kitchen of huayin, if a player keep on ask chu niang
about food and drop the food, soon that room will get too many objects
and also cause the system to shutdown.


---
����: ����ү(suicide)
��Ŀ: ����
����: Tue Mar 14 23:05:30 2000
�Ҳ���˵catch������,��ץ����Ӧ��ץ.
�ҵ���˼���Ƿ�����޸�catch��Ч��,��΢����һ��.


---
����: Row
��Ŀ: >�޸Ľ���
����: Tue Mar 14 22:57:07 2000
����Ϊcatch����û��ʲô���⣬��catch���������ƻ�������
���Ҳ�����������������һ��mud ��Ϸ�ﲻ����һ�ź�����
��Ϊ������ʧȥ�˾��������壬��Ȼ����Ҫ��ֹ���ǳ��ֹ���
�ľ��棬�������໰��ʹ�÷Ƿ��ֶθ��ƻ��ȵȡ�


---
����: ����ү(suicide)
��Ŀ: �޸Ľ���
����: Tue Mar 14 22:52:54 2000
����������ֲ�����Ϊ��ұ�catch���������¼�����.
�Ƿ���Կ��Ǽ��ٱ�ץ����ʧ��ץ��Ľ���.
��������catch���Ѷ�,������fight�������ױ�����.


---
����: ����(row)
��Ŀ: �����ʺ�
����: Tue Mar 14 20:52:55 2000
zjվ�ֳ����˵����ʺŵ��£����˵������������ʺŲñ���������ҡ�
������findָ���ѯĳid��login״�������ǣ�
*(s)printf(): BUFF_SIZE overflowed... (arg: 1);

please advise.


---
����: ����(row)
��Ŀ: ���ٳ�Ʒ�ġ�����־�ߡ�
����: Tue Mar 14 20:50:02 2000
���������������С�����־�ߡ���ȫ���ԣ����Բο����е�
��Ʒ����ĳ���ã����ɲ�����
http://games.sina.com.cn/handbook/0003/03091514.shtml

�������ַ��
http://games.sina.com.cn/


---
����: ����(ice)
��Ŀ: add a busy time for add and rm blacklist
����: Tue Mar 14 10:57:47 2000
it floods in rumor all the time, everyone can check it out
any time.
* slogan


---
����: ����(row)
��Ŀ: hmm...serious bug
����: Tue Mar 14 08:42:57 2000
in zj, when its night, the system will reboot by no reason.
some players report there is someone intended to shutdown it
by certain bug to gain some benefits, for instance, when
the sanguo restarts, han di will call a player immediately.
is there a way to track the inproper shutdown and check the cause?
please advise.


---
����: ����(group)
��Ŀ: faint
����: Tue Mar 14 01:20:11 2000
forgot to take the disk...tomorrow i will upload in...

escape...



---
����: �һ�(fire)
��Ŀ: improvement of fight
����: Mon Mar 13 07:18:55 2000
1 for a room if set("no_fight",1) then it is a no fighting room
  if set("no_fight",<msg>) when a player try to fight will show
  him the msg, which usually means the reason why can't fight here
2 if fight a player, need both side fight the other then can fight
3 if two ppl fighting and move to a no fight room the fight will
  auto stop


---
����: ����(row)
��Ŀ: to fire
����: Mon Mar 13 01:13:08 2000
i rmed put.c in zj site, but when the site is rebooted, put.c returns and
is loaded by system, which means its useless by only removing.
what else can i do?


---
����: ����(row)
��Ŀ: bug log
����: Sun Mar 12 23:54:01 2000
������ ��tking
����   ��Mon Mar 13 12:59:26 2000
��Ŀ���й�������ͬʱ��һ��ID��BUG 
---------------------------------------
�ղ�����yesl����bl,״̬����POS�У������ʱyesl�Լ�Ҳ����
Ȼ����Ҳ������bl
��������ȴû��quit,���Լ�������.
��û�����ظ����ԣ���֪�����Ǹ�żȻ���󣬻���BUG



---
����: ����(row)
��Ŀ: bug of xuzijiang
����: Sun Mar 12 22:02:14 2000
i changed the file of /sgdomain/job/xuzijiang/xianren.c, hope it will
fix the bug.


---
����: �һ�(fire)
��Ŀ: a little suggestion for row
����: Sun Mar 12 19:41:29 2000
comfort row,
In a Mud, I think the most difficult thing is to deal problems with players :(
Because they are so different, sometime is pretty hard to be
justify. So in this
special situation. I may suggest you don't cut a players' skill until 3 chars 
from different ips and different countries prove that he has used
bug to increase
his skill and also give the number how many levels he has got from the bug.
When you got this proof, you cut down his skill. So either side got
complains, 
it is not your mistake :). 
This is only my personal suggestion, you may find some better solutions. 
addoil row
sweat row


---
����: Suicide
��Ŀ: >> ����. 
����: Sun Mar 12 19:24:44 2000
When the player's data gets saved periodically, the online time
can be saved together. If crash, all data should revert
to the last saved data. 

So now we should discuss how to saved the online time periodically.

It still need a period call to update all ppl's online time.
What should we use and how to do it?
Let's discuss Bah...


---
����: ����(row)
��Ŀ: whats wrong
����: Sun Mar 12 11:13:03 2000
��ʱ�ض�ɽҡ���췭�ظ��������������һ����

zj site shutdown several times in a few minutes without any
reasons, whats wrong???


---
����: ����(row)
��Ŀ: bug...
����: Sun Mar 12 11:09:02 2000
i am really depressed now...players just intend to use bug to 
get benefit instead of reporting...i posted in zj site for the
purpose that i want them to report how much they got from the bug
but, seems its useless...no one is really consider from the game
developing aspect, they just want their own good....

that makes me angry.  pls advise where and how can i track those
bug user, and i will CUT or PURGE!
i am not a harsh person but they really disappointed me.


---
����: ����(row)
��Ŀ: bug log
����: Sun Mar 12 10:54:59 2000
another bug same as cmd leave. in pos, king dismisses a player, then
the player ask about position again, the nationcontribution will
not decrease.


---
����: ˹̹��(stefan)
��Ŀ: > ����. 
����: Sun Mar 12 01:30:56 2000
The adversary object is only in recent Lima Lib, but not here..

Also age computation does not need "log" files :) If you take a look
at old ES2 files, each player's .o data has a field indicates how long
the player has spent in the mud. So this data
is actually with each player, not in the log file. Also 
the computation could be "smarter" to avoid crash problem...
for example:

When the player's data gets saved periodically, the online time
can be saved together. If crash, all data should revert
to the last saved data. 

I would agree with fire, because some other things are also done in the
age_beat()
besides the age calculation, need to take care of those things as well.


---
����: Flee
��Ŀ: >>suggestion
����: Sun Mar 12 00:05:16 2000
On Sat Mar 11 15:09:23 2000 Ice wrote post #1201:
> since row talked about fight, can we think of give back the weapons
> to the NPC's? 
> just for not easy to fight with lv bu sth.:P
> 
> btw, if use set_no_fight(1), and if I am following row to fight with
> him, when he move in no_fight room, will the fight stop?
env->set("no_fight", 1)
then players can not start fight in the room .. 
but i am not sure about the case ice metioned .. 
*fool


---
����: �һ�(fire)
��Ŀ: the bug about leave and rejoin and get reward
����: Sat Mar 11 23:18:22 2000
is due to when i edit ev_leave.c, I was using a old
copy. Now i change it back, sorry for this bug


---
����: �һ�(fire)
��Ŀ: about age_beat
����: Sat Mar 11 23:01:49 2000
1 now it is using call_out for each ppl, this may use more
  memory resource than necessary.
2 use heart_beat, because heart_beat calls every 2 second,
  but our age_beat takes about 240 second. so heart_beat 
  may use more cpu power.
3 use calculation on call method. just like the hp system, 
  system will calculate the hp, mp, food and drink when it 
  is called. This method is very skillful. However our age_beat
  also triggles some other actions such as the use's home events.
  Therefore to use this way may miss some trigger if no other
  request ask for the system to calculate players age. 
4 Triggered by other periodical daemons like day_d. By using this
  method, each period system needs do the following things:
  a get a list of all online players
  b run the age_beat method on each player by using for loop
  This method may cause a peak cpu useage in a short time every
  perodical time. And all the events triggered by the age_beat
  may happen at the same time. So it still hard to say this is
  the best method.
Compared the 4 different method, my personal feeling is method
3 is the best. But we need to find a good and realiable trigger
for the calculation.
  
  


---
����: Fire
��Ŀ: >a doubt
����: Sat Mar 11 22:32:44 2000
On Sat Mar 11 15:27:41 2000 ����(ice) wrote post #1202:
> can ���ܾ�ʦ��Ʈѩ act as king?
> ��ҥ�ԡ�ĳ�ˣ�Ʈѩ��ƮѩΪ��ɽ��������
> ...
> * fool

he is a ����


---
����: ����ү(suicide)
��Ŀ: ��վ�������leave bug.
����: Sat Mar 11 22:07:56 2000
�������cmd leave then reposition.
all nationcontribution remains and can get reward for ���� time and time.
All player in zj site r using this bug to get reward and reward now.
Fire maybe we should recover the data of zj site of yesterday.
Have we?


---
����: ����ү(suicide)
��Ŀ: ����.
����: Sat Mar 11 21:48:03 2000
���ǵ�mud�е�pplƽʱ��û��������?
�ǲ���ֻ��fightʱ��������.?
���������֪lima bean����adversary��һ�������heart_beat��
���������е�������̳�heart_beat().
�Ҿ�����log����age��Ȼ����,����ʵ��������������.
��һ:����down��.
�ڶ�:log�ļ�����ɾ��,���뱣��,���һ�Խ��Խ��.
����:log�ļ�û������,�ǳ���,Ҫ����һ�����age����Ҫɨ������log�ļ�.
    ��ʱҲ��С.
�������ҵ�һЩ�뷨,Ҳ�����,����ָ��.


---
����: Suicide
��Ŀ: >>>����age_beat()
����: Sat Mar 11 21:39:42 2000
we can just turn on the heart_beat of ppl.
��֪����lima bean������adversary���в���heart_beat��
���������е�obj��������,�������ǿ���ֻ����ҵ�����.


---
����: ����(ice)
��Ŀ: a doubt
����: Sat Mar 11 15:27:41 2000
can ���ܾ�ʦ��Ʈѩ act as king?
��ҥ�ԡ�ĳ�ˣ�Ʈѩ��ƮѩΪ��ɽ��������
...
* fool


---
����: Ice
��Ŀ: >suggestion
����: Sat Mar 11 15:09:23 2000
since row talked about fight, can we think of give back the weapons
to the NPC's? 
just for not easy to fight with lv bu sth.:P

btw, if use set_no_fight(1), and if I am following row to fight with
him, when he move in no_fight room, will the fight stop?


---
����: ����(row)
��Ŀ: suggestion
����: Sat Mar 11 12:21:19 2000
we used to have a set_no_fight(1), dunno if i get it right
i suggest to set all meeting room cannot fight, coz player will
flood there to interrupt others. and fly_room, etc


---
����: Stefan
��Ŀ: >>����age_beat()
����: Sat Mar 11 00:29:46 2000
On Fri Mar 10 03:51:15 2000 Fire wrote post #1198:
> On Fri Mar 10 03:05:15 2000 ����ү(suicide) wrote post #1197:
> > �����Ҳ���fate_d.cʱ���ⷢ��ϵͳ��Ȼÿ��ppl����һ��age_beat��call
> > ������ǲ��ǻ�Ӱ��ϵͳ����?
> > �������Լ���lima beanʵ��age������ʱ����ܿ������.
> > ����ϵͳ���Զ���ʱ���õ�heart_beat������ʵ��, �����ͱ��������������.
> > ����ϵͳ���Զ���ʱ���õ�heart_beat������ʵ��, �����ͱ��������������.
> > ����Ȥ
> > �Ļ���������.
> 
> that is a good point, we may change the design style later
> hoho

I am not sure what is done within age_beat, but the best
way to increase age is to calculate it whenever the age number
is needed.

for example, if "score" shows age, age should only be
calculated when the "score" command is typed by the player.
If in some program, the age of a player has to be obtained, 
it can also be calculated by calling compute age function.
The age itself can be computed from the sum of a player's 
online time. Online time can be obtained by recording
linkdead/logoff/login time. Unless there are other things
that must be done with a call_out in age_beat, otherwise, to
compute age itself does not need call_out.

Most things that seem to require periodical call_out can
also be avoided in similar ways.

The worst case is heart_beat() function, it is called every
second for every interactive object, that surely wastes quite
a lot of CPU. That is why Lima eliminate heart_beat() in the
first place.


---
����: Fire
��Ŀ: >����age_beat()
����: Fri Mar 10 03:51:15 2000
On Fri Mar 10 03:05:15 2000 ����ү(suicide) wrote post #1197:
> �����Ҳ���fate_d.cʱ���ⷢ��ϵͳ��Ȼÿ��ppl����һ��age_beat��call
> ������ǲ��ǻ�Ӱ��ϵͳ����?
> �������Լ���lima beanʵ��age������ʱ����ܿ������.
> ����ϵͳ���Զ���ʱ���õ�heart_beat������ʵ��, �����ͱ��������������.
> ����ϵͳ���Զ���ʱ���õ�heart_beat������ʵ��, �����ͱ��������������.
> ����Ȥ
> �Ļ���������.

that is a good point, we may change the design style later
hoho


---
����: ����ү(suicide)
��Ŀ: ����age_beat()
����: Fri Mar 10 03:05:15 2000
�����Ҳ���fate_d.cʱ���ⷢ��ϵͳ��Ȼÿ��ppl����һ��age_beat��call
������ǲ��ǻ�Ӱ��ϵͳ����?
�������Լ���lima beanʵ��age������ʱ����ܿ������.
����ϵͳ���Զ���ʱ���õ�heart_beat������ʵ��, �����ͱ��������������.
����ϵͳ���Զ���ʱ���õ�heart_beat������ʵ��, �����ͱ��������������.
����Ȥ
�Ļ���������.


---
����: Row
��Ŀ: >suggestion about info a
����: Fri Mar 10 02:18:42 2000
agree...i'll do the modification.


---
����: �һ�(fire)
��Ŀ: suggestion about info a
����: Fri Mar 10 02:17:26 2000
Now the info aX is good, the only problem is not easy to remember them
and will hard to read the help info page (that help include too much
informations). So I suggest:

1 add a info aa to display all the information like the old info a.

2 info a will display the useage of all the info aX.

3 add info aX here to display current area's information. 

PS X could be one of m, g, f, a . . .


---
����: �һ�(fire)
��Ŀ: %^H_RED%^A very stange bug
����: Thu Mar  9 18:18:58 2000
today, when I login and find the system just reboot and then it
crash. So I relogin and it crash again, I try to restart the server
It still the same. After some observation, I find the crash is 
caused when ���(wji) login. Please check the log.Usually when
the system reboot, it can last about 1 min and when wji login
it will crash immediately. So I suspect wji's data got some problem.
I goto the server and copy all the wji.o to wji.o.back and then
plan to purge him when login, then miracle happens, the system not
crash anymore. faint. Is it because I have copy some of his data file
solved the strange crashes or sth else. Anyone has any ideas
PS: the log about the crash
��ϵͳ�������������־��վ��
��ʱ�ض�ɽҡ���췭�ظ��������������һ����
��ϵͳ�������������־��վ��
��ʱ�ض�ɽҡ���췭�ظ��������������һ����
> ��ϵͳ�������������־��վ��
��ϵͳ���¸ҽ�������־��վ��
��ʱ�ض�ɽҡ���췭�ظ��������������һ����
��ϵͳ�������������־��վ��
�� ����־��վ ��  ������ʱ�䣺��ǧ�����¾���������ʱ��ʮ�߷֣�
����ID�б���  Ŀǰ��������8��
��������������������������������������������������������������������������
�һ�(fire)   ���(wji)    צ��(java)
> ��ʱ�ض�ɽҡ���췭�ظ��������������һ����
��ϵͳ�������������־��վ��
��ʱ�ض�ɽҡ���췭�ظ��������������һ����
> ��ϵͳ�������������־��վ��
��ʱ�ض�ɽҡ���췭�ظ��������������һ����



---
����: �һ�(fire)
��Ŀ: Hi suicide
����: Wed Mar  8 22:13:01 2000
���POST��ȫ���濴�ˣ���Ľ��鲢��û�е�����Щʵ���ϻ���
�����������ġ���ֻ���ڿ��ǵ�ĳЩ��ƿ�������ı׶����Բŷ���
�ġ�����һ����Ƶĺ��뻵Ҫ�����ʵ���м������˵������������
ԭ����Ƶ�gini������Ϊ������˼ͬʱҲ���˺ܴ����ȥCODE������
���ܲ����룬��Ȼ������������ȡ���ˡ����Թ���POST�������
�ݣ��㻹��ȥ����������Ȼ��©������δ���ǲ������޲��ģ�ͬʱҲ��
���������������ȷ�ġ����ҵ�������ȫ�Ƕ��ࡣ
���������������Ĺ�����ʽ����Ȼ��Ҷ���ƽ�����ɵġ������ǻ���
Ҫ��һ�����ĵĹ������֯�ſ��������ϵͳ��������ת�����������
������wiz committee����Ҫ�ľ���Ҫ��������С�����WIZ�ľ��幤��
���š���Ҫ���������tasklist��������WIZ�������в�������ۡ�������
��һ��WIZ������һ�����ӣ��Ϳ�����������һ��WIZȥ���ġ�������ƺ�
�������Ƕ���ӭ�����������ԭ�򣬲��������Ͼ�ȥ�����ر�����Щ��
�����������ϵͳ����ƣ��ڲ��ɵ���ʱ��Ҫ���������ڳ�������������
�͵۹���ơ�ʵ����Щ�ڼ����϶������ѡ�һ��ָ��Ϳ�����һ������
��Ϊ�۹�������һ�����������������ˣ�ֻҪ��һ������commentȥ����
���ϾͿ��Ի�Ծ����������Ϊ����Ƶ�ƽ���ϣ���Щ���⻹û����ȫ��˳��
������ص���ƻ�û����ɣ�������Щ�õĶ������ò��˳�һ�¡���Ϊ��
������û��ã���ණ��������Ϥ���������Ҳ�����㡣
ʵ���ϣ��Һ�����������Ĺ���̬�ȺͿ�ݵĹ����ٶȡ�����һ��������
���ǻ�Ҫע���������ϡ����һ����������Ǿ���Ŀǰû��ʲô���
�����øɡ���ʵ����һ����ᣬ�������FATEϵͳ��Զû����ɣ�������
�г�һЩ���ԸĽ��ĵط���
1  һ�����ڵ����ѣ���Ӧ��ͬʱһ˲��ͻȻ���֡�
2 ���ѵ��������ڼ򵥣�Ӧ����Ԥ��(�����Ƕ��)�������м���̣�������
3 ����Ҫ�о�������ݣ�����˵���֣����Ӧ�ÿ��Կ������ھ���ķ����
  Ҳ������һЩ��ʽ���������FLEE����һ��������JOB�������ȥ�ο�һ��
4 ��Щ��������𣬺�ˮ�ͻȳ档��Ӧ��ֻ��һ�����С����ڳ���ҲҪ�ܵ�������

5 ��������һ�����˹��磬��ҿ����������ʱ���ļ��ס�Ҳ������һ���ƽ�֮����

   �ƽ�֮���������Ʋƣ�����������ü�ʿ���ȵȡ����廹���Ը��࣬��Щ��Ҫ��

   ������ɣ�����ЩҲ�������ھ�����
����ֻ��һЩ�ҵ���㽨�飬������ô���������и�������ݡ���֮������������

ֻ���ٶȡ���������Ҫ���Һ�����ROW������ϸ�ڿ̻���һֱ��һ˿������ͬʱ
emperor��CODE����Ҳ�ǳ��ߡ����֮���ҵ�CODE�ʹֲ�һЩ�����Ծ���Ҫ
���޲�������ǰ���һЩPOST������Ҳ��̫�ã��ڴ���Ҳ��ʾ��Ǹ����֮����
��һ�������������Ŀ�Ķ���һ�µģ����Ǵ�������õ���Ϸ��Ը���ǵ�����
���ճ��档


---
����: �һ�(fire)
��Ŀ: about post
����: Wed Mar  8 18:40:23 2000
����SUICIDE��POST����ƣ���Щϸ���ҵ�����Ƿ��Եġ�����
�Ѿ�˵���ˡ������ҵ������һ������ȷ�ġ�һЩ�漰����ϵͳ
����ƣ�������з����ʱ������Ҫ��ίԱ�������۾����ġ�
����POST����һ��������ϵͳ��ϵ�����ر����е���ƣ�������
WIZ��һ���Ĵ������ɡ�����SUICIDE����ȥ���ԣ�������Ľ�
���Ƚ����룬�Ǿ���������


---
����: ����(ice)
��Ŀ: to suicide
����: Wed Mar  8 10:08:23 2000
I can suggest and suggest, u need code and code, so should we make
a team?.:P
however, our plan will be discussed.:P
well, I am going to make some plan in mind for long for u to code,
I have no idea of coding.:(
so, i'll just provide without being afraid that no one will be free
to code it.:)
* sing
* massage suicide


---
����: ����ү(suicide)
��Ŀ: To row 
����: Wed Mar  8 08:26:00 2000
��˵�ĳ�������ϵͳ�������Ҷ�����.
��˵�ĳ�������ϵͳ�������Ҷ�����.
Ҫ��һ������Ĺ�ʽ̫���ˣ�������̽��ϸ�����ܶ��֣�
���ٿ��ǿ��ǣ�
лл��Ľ��飮:)
admire row.


---
����: ����ү(suicide)
��Ŀ: :)
����: Wed Mar  8 07:40:19 2000
This afternoon row ask me about that hwo about bandit.
So i think if i can add the old bandit event into fate system.
if it is not a good idea i give up.
:)
i am just free. i need code and code.


---
����: Ice
��Ŀ: >>����bandit
����: Wed Mar  8 05:04:23 2000
On Wed Mar  8 04:35:33 2000 Fire wrote post #1186:
> On Wed Mar  8 01:43:11 2000 ����ү(suicide) wrote post #1185:
> > fire:
> >   ���ҿ���������ǰϵͳ�����Զ���banditϮ����ֻ�Ǻ��������ˣ�
> > �����ҿɲ����԰�������fateϵͳ����fateϵͳ�е�����ȡ����ǰ��
> > ai_d�еĵ��ã�
> 
> fateϵͳĿǰֻ��һ����ܡ��ں������ϻ�û�С�
> bandit�漰��ս������ս��Ŀǰ�Ѿ��������ˡ��ȶ������ɺ�Ҫ��
> ����ȵ�����(���Ĳ���Ҫ��д)������banditĿǰ���Ȳ�Ҫ���ˡ�

faint, suicide, so if u want, let's discuss but not execute it bah.
* fool


---
����: Ice
��Ŀ: >����bandit
����: Wed Mar  8 05:03:23 2000
bandit had bugs b4, it's better recheck it b4 implement it
and i had a plan about bandit, so pls read it in fate.com bah
if u r not clear enough, post ur doubts.:)
I'll be pleasure to discuss it any time.:P


---
����: Fire
��Ŀ: >����bandit
����: Wed Mar  8 04:35:33 2000
On Wed Mar  8 01:43:11 2000 ����ү(suicide) wrote post #1185:
> fire:
>   ���ҿ���������ǰϵͳ�����Զ���banditϮ����ֻ�Ǻ��������ˣ�
> �����ҿɲ����԰�������fateϵͳ����fateϵͳ�е�����ȡ����ǰ��
> ai_d�еĵ��ã�

fateϵͳĿǰֻ��һ����ܡ��ں������ϻ�û�С�
bandit�漰��ս������ս��Ŀǰ�Ѿ��������ˡ��ȶ������ɺ�Ҫ��
����ȵ�����(���Ĳ���Ҫ��д)������banditĿǰ���Ȳ�Ҫ���ˡ�


---
����: ����ү(suicide)
��Ŀ: ����bandit
����: Wed Mar  8 01:43:11 2000
fire:
  ���ҿ���������ǰϵͳ�����Զ���banditϮ����ֻ�Ǻ��������ˣ�
�����ҿɲ����԰�������fateϵͳ����fateϵͳ�е�����ȡ����ǰ��
ai_d�еĵ��ã�


---
����: Fire
��Ŀ: >bug report from zj
����: Wed Mar  8 00:12:33 2000
On Tue Mar  7 23:56:59 2000 ����(row) wrote post #1182:
> �����˵��������������bug���鷿����ıһ��ѧ���ܸ߼���
> ������put�����⣬�����ų�����bug�������顣
I will disable put
hehe


---
����: Fire
��Ŀ: >to fire
����: Wed Mar  8 00:12:17 2000
On Tue Mar  7 23:46:39 2000 ����(row) wrote post #1181:
> ����NPC������Ұ�������������ʧ���������ֲ���������
> �������������������������������˹٣���fire������Ұ����
> Ӱ��NPC�����������ֲ��Ѿ���ɵ���ʧ��
NPC�������ǻ��Զ����ġ�
���ò��ģ�)


---
����: ����(row)
��Ŀ: bug report from zj
����: Tue Mar  7 23:56:59 2000
�����˵��������������bug���鷿����ıһ��ѧ���ܸ߼���
������put�����⣬�����ų�����bug�������顣


---
����: ����(row)
��Ŀ: to fire
����: Tue Mar  7 23:46:39 2000
����NPC������Ұ�������������ʧ���������ֲ���������
�������������������������������˹٣���fire������Ұ����
Ӱ��NPC�����������ֲ��Ѿ���ɵ���ʧ��


---
����: Fire
��Ŀ: >change chinese id
����: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 ����(row) wrote post #1278:
> ����޸�һ��id���������֣��������id�����Ļ���
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
����: Fire
��Ŀ: >change chinese id
����: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 ����(row) wrote post #1278:
> ����޸�һ��id���������֣��������id�����Ļ���
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
����: ����ү(suicide)
��Ŀ: close war time of zj site.
����: Thu Mar 23 19:31:07 2000
Row:
  Have u promised ppl in zj site that u will close the war time?
This morning a ppl coming from zj site told me about it.
:)


---
����: Fire
��Ŀ: >change chinese id
����: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 ����(row) wrote post #1278:
> ����޸�һ��id���������֣��������id�����Ļ���
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
����: Fire
��Ŀ: >change chinese id
����: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 ����(row) wrote post #1278:
> ����޸�һ��id���������֣��������id�����Ļ���
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
����: Fire
��Ŀ: >change chinese id
����: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 ����(row) wrote post #1278:
> ����޸�һ��id���������֣��������id�����Ļ���
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
����: ����ү(suicide)
��Ŀ: apply for mirrow
����: Sat Apr  1 07:36:22 2000
A guy coming from tsinghua ask me about their apply for mirroe.
he tell me that stefan promise that he will reply him before april.
He is eager to know the result.
Stefan if u have time Can u mail him?


---
����: ˹̹��(stefan)
��Ŀ: imud problem
����: Fri Mar 31 23:07:28 2000
it is because the router is down. We are using the 
international router, have to find out why...


---
����: �һ�(fire)
��Ŀ: it seems our intermud stuff got bugs
����: Thu Mar 30 23:40:17 2000
news

news
who -w



---
����: ����ү(suicide)
��Ŀ: addoil all
����: Thu Mar 30 03:49:08 2000
������ߺ����������,���񶼺�æ��.
�ڴ˶Դ�ҵ�һ������ѧϰ˳��


---
����: Ice
��Ŀ: >where is the modules about fight?
����: Wed Mar 29 21:02:34 2000
is it in daemons/fight_d/ and fight_d.c?
* addoil suicide


---
����: �һ�(fire)
��Ŀ: busy
����: Wed Mar 29 06:50:44 2000
these days our company is pretty busy,
the market stuff need delay several days
sorry, addoil all :)


---
����: ����ү(suicide)
��Ŀ: where is the modules about fight?
����: Tue Mar 28 19:13:28 2000
for my lima bean version is a little different from here.
So i can't find it quickly.pls help me.


---
����: Suicide
��Ŀ: >>about anti-robot
����: Tue Mar 28 19:12:35 2000
can we add anti-robot question before job instead of finishing job.
then the ppl still nedd finish only one question according to finishing
one job.


---
����: Ice
��Ŀ: >about anti-robot
����: Tue Mar 28 06:04:45 2000
I think it's a not bad idea, however, if the player's net is lag, he
will have to suffer
from each time he cannot get the job bcoz they dun have enough time
to answer the
anti-robot questions.


---
����: ����ү(suicide)
��Ŀ: about anti-robot
����: Mon Mar 27 20:32:48 2000
BSW: we can also add question before recruit and other important job for 
   ppl.
xixi .


---
����: ����ү(suicide)
��Ŀ: about anti-robot
����: Mon Mar 27 20:29:07 2000
In caolu runner say that if we could add a anti-robot question 
before whisper or letter.I think it is a good idea.
What do u sthink so?


---
����: Suicide
��Ŀ: >about my absence
����: Sun Mar 26 22:40:37 2000
poor fire
addoil fire


---
����: �һ�(fire)
��Ŀ: about my absence
����: Sun Mar 26 21:00:52 2000
Because my University's network got some problem. So
I could't login last weekends. Sorry for my absence,
I have to find another free ISP :(


---
����: Ice
��Ŀ: >about buy
����: Sun Mar 26 01:18:58 2000
I tried to make maker use bank account to complete the deal, but..
my programming skill is too weak to ...
so just change it, it's simple for u guys.:P
* esacpe


---
����: ����(flee)
��Ŀ: about buy
����: Sun Mar 26 00:01:39 2000
today noise want to a hxbma, but he is too weak to
carry 3k gold .. so i just dest 3k gold from him and
add a hxbma for him.
can we withdraw money from bank account directly, 
instead of carrying so many gold .. 


---
����: �Ƶ�(emperor)
��Ŀ: to stefan
����: Sat Mar 25 19:19:15 2000
���������зǳ����free email����ҿ�����free email��
�õ�ע�����룬�Ҿ�ע�����ϰٸ�free email������˭��
��Ҫemail address�������������С��������õ���
������ʲô�鷳��������email����ը���һ���email����
�ˡ�


---
����: ˹̹��(stefan)
��Ŀ: email registration
����: Sat Mar 25 10:53:20 2000
I think a better way is to force email registration after a 
player settle. This way will be better for fresh newbies.

For myself, I am always scared when asked for email address :)

Should we post a privacy statement?? 


---
����: �Ƶ�(emperor)
��Ŀ: �����Ƶ�ע������ϵͳ
����: Sat Mar 25 06:02:26 2000
1.�������������ʱ����Ҫע��email��Ȼ�����ø�email�õ�
�µ�������ܽ�����Ϸ��
2.�������ע��IDʱ����Ҫע����ʵ��email���õ��µ�����
���ܽ���������
3.��������붪ʧ����hack������WIZ��������smtp����
������ҷ����µ������ʼ����������ҵľ�ע�����䲻��
ʹ��ʱ������WIZȷ�ϣ����Ը�������µ�ע�����䷢��
�����ʼ���
4.smtp�����÷���
������ң��Ƶ�(emperor)
�����ԭ��ע������sufeng@990.net������ʹ��ʱ
����WIZ����ʹ�ã�smtp emperor�����䷢�������ʼ���
��ԭ��ע������sufeng@990.net����ʹ��ʱ������Ƶ�
Ҫ�µ����䣬�磺sufeng@ynmail.com��������WIZ
����ʹ�����smtp emperor sufeng@ynmail.com
�����Ƶ۷����µ�ע�������ʼ���
5.���Ϲ��ܾ���ʵ�֣���������ߣ���ҿɵ��ҵ�
����MUD����ԡ�
;��������Ҫʲô������


---
����: Ice
��Ŀ: >����ע������
����: Sat Mar 25 02:50:14 2000
so nice
* great emperor


---
����: �Ƶ�(emperor)
��Ŀ: ����ע������
����: Sat Mar 25 01:34:54 2000
�����Լ��Ļ����ϳɹ��Ĳ�������ұ���ͨ����ʵ��������ע��
���õ�ID������������Ҫ����������ʹ�÷��͸���������
���õ�ID������������Ҫ������������ʹ�÷��͸���������
�����Ժ���Ҷ�ʧ������󣬿���������WIZ���룬����WIZ����
ͨ��ʹ��һ����������������Զ��ٷ�һ����������ż�
����ԭ����ע�����䣬����������Ч�ؽ����Ҷ�ʧ�����
���⡣
������Ϊ�������


---
����: ����(group)
��Ŀ: bug
����: Fri Mar 24 09:28:00 2000
��   ����   ���������˷���(groupone)
��   ����   ���������˷���(groupone)
if create together, you can have 2 totally same id in the mud 
this is maybe the reason for the train bug
fire please check


---
����: ����(ice)
��Ŀ: ...
����: Fri Mar 24 09:17:28 2000
read leeye's post 509...


---
����: ����(ice)
��Ŀ: suggest to add a cmd of set_notell for player
����: Fri Mar 24 09:15:43 2000
for avoiding player disturb another to earn benefits, I think add
the cmd of set_notell
for player to handle it themself will be fine.

here is the log of discussion by some player...
�������������Ŷ������ɫ�ĸ�����������
���������������¶��а���Ц�ݣ���֪�����������ˡ�
���������ʯ���ƻ����ǵ�trigger
�����������������������ɫ���飬grin

...


---
����: �Ƶ�(emperor)
��Ŀ: ��������
����: Fri Mar 24 09:01:07 2000
��@ USER_D->set_variable("emperor","chinese_id","�˵�")
�����޸���ҵ���������������û�Թ���
xixi:)


---
����: ����(ice)
��Ŀ: an old old problem
����: Fri Mar 24 05:16:56 2000
duplicated chinese name and dummy problems were old problems,
for some reasons, we didn't fix it at that time, but for now, seems
it's becoming barriers for our growth, think a way to deal with it?

dummies and robots r problems of all mud...:(
duplicated chinese name is hard to fix bcoz there r many duplicated
names already existing...

think about it

* addoil


---
����: Fire
��Ŀ: >change chinese id
����: Thu Mar 23 18:00:02 2000
On Thu Mar 23 08:16:48 2000 ����(row) wrote post #1278:
> ����޸�һ��id���������֣��������id�����Ļ���
edit /data/players/x/xxxx.o
there are two place in that file to modify
one is chinese_id another is chinese_name
hoho


---
����: Stefan
��Ŀ: >apply for mirrow
����: Sat Apr  1 21:49:17 2000
On Sat Apr  1 07:36:22 2000 ����ү(suicide) wrote post #1305:
> A guy coming from tsinghua ask me about their apply for mirroe.
> he tell me that stefan promise that he will reply him before april.
> He is eager to know the result.
> Stefan if u have time Can u mail him?

there are four applications from tsinghua, I am always confused :P
I will settle it, but all of them are not officially permitted, 
hard to decide which one to choose.


---
����: Suicide
��Ŀ: >about block_tell
����: Sat Apr  1 21:12:17 2000
fire have add a function to block tell lah...
.id->set_notell(xxx)
All thing we have to do is add the function to a verb file.
But i don't know if fire want to open this.
So i will not do this by myself.
:)


---
����: ����(ice)
��Ŀ: about block_tell
����: Sat Apr  1 08:53:03 2000
I think set the block tell as a player function is necessary, today
I found a post in
shanghai mirror, a player flood another player with tell for 1 hr.:P
so fire pls make it possible for player to block tell


---
����: Fire
��Ŀ: >bug log
����: Mon Apr  3 23:46:52 2000
On Mon Apr  3 22:49:56 2000 ����(row) wrote post #1313:
> if a player ask xxx idler/guy/resident about getppl when he doesnt got
> a getppl job, the ppl will be set busy and wont leave as long as that
> player stay in the same room, nobody can ask that ppl about visit or fan.
> until someone come and recruit them.
i will check it
hoho :)


---
����: ����(row)
��Ŀ: bug log
����: Mon Apr  3 22:49:56 2000
if a player ask xxx idler/guy/resident about getppl when he doesnt got
a getppl job, the ppl will be set busy and wont leave as long as that
player stay in the same room, nobody can ask that ppl about visit or fan.
until someone come and recruit them.


---
����: Suicide
��Ŀ: >>apply for mirrow
����: Mon Apr  3 20:15:18 2000
sweat stefan
addoil stefan.


---
����: ����(ice)
��Ŀ: about yuyin's suggestion
����: Sun Apr  2 15:57:35 2000
I think maybe we can add a position in our mud like "immortal"?
then the wizs and admins in mirror can login for the discussion
and meeting time to time.

here is the desc of immortal in a mud webpage:
immortal)---�����ǽ�����Һ���ʦ֮��ĵȼ���һ��Ϊ�۲�Ա����æ��;Щbug��

I think it can be assigned in this way:
every wizs and admins in mirror will have a id as immortal automatically
in main, the id and passwd will be mailed to their own mudmail account
or email account;
the rights they can have r: auto having the announce,wiz,bug channels,
can used a cmd "immo" to go to a special discussion room called
discussion room sth, then they can post in the "discussion" board
about their idea, the difference of immortal and player is they
will be able to have direct discussion/private discussion with main
site's wizs about development or bugs.
they cannot view the codes and read the wiz.com and tasks...


in the current condition, I think there will be too less communication
among the mirror's wizs and also main->mirrors' wizs.

consider?
/


---
����: ����(ice)
��Ŀ: yuyin's suggestion
����: Sun Apr  2 15:41:27 2000
ʱ��:  Sun Mar 26 20:17:52 2000                Post-id: 28 (39 Last)
����:  ����(yuyin)
��Ŀ:  �йع����ϵ�һЩ����
----------------------------------------------------------------------
�йع����ϵ�һЩ����

���� sg �����������Ѿ���һ���ˣ��ӿ�ʼ��ֻ�м��� area һֱ��
���ڵĴ��ͼ����20-30��npc�����ڵ�200���npc�����ǵ� sg ����
�˶��ٵķ�����꣬���ڵĵ������ڵĳɾͣ���Ҳ�Ƿǳ�ֵ������ȥ
���˵ġ����Ǵ�ҿ����뵽���ڸտ�ʼ��ʱ������վ��ֻ��һ����
���Թ���������Ƚϼ򵥣�����������ȴ�� 5 ����վ�ˣ���������վ
�Ĺ���Ϳ���Ҳ�������� fire �� row , stefan һ���а����Ƿ��
�����������Ļ�������� �� �ڴˣ��������һ��С�����
    �����Ƿ���Լ���һ��ͳ�������и�վ֮���֪ͨ������

�йع�����
    1   ����վ�������е���ϵ����վ�����и��±��뼰ʱ������վ��
        �� admin �㱨�������Ÿ��º�����ʱ�䡣������ sg ���ص�����
        ÿһ����С�ĸĶ�����Ӱ�쵽 player ��������Ϸ�������� lpc
        ���ԣ������˹�ͨ�Ժ�Ϳ��Զ���һ����õ� update ʱ���
        ������
        
    2   �ѱ�վ��һЩ���������һЩ���ܣ���Э�� admin ���� player
        ֮��ľ��׺ͽ⣬��վ���һЩ�ش���ߵİ��š�����Ϊÿһ��
        ��վ�������Լ����Ļ�����������վ��� wizard ����֪���ģ�
        ���������� sg ���ص����£��кܶ���������������վ��������
        ��������վȴû��������������һ���ڴ����ϾͿ��Է����������
        վ��� wizard ȡ����ϵ�����ƶ�һ�����õĴ�������
    
    3   ÿ��������������վ��ͳ����г��̣����������ƻ���������
        ������վ��� wizard �� admin �Ŀ������������ź�ÿһλ
        admin �� wizard �Ŀ�������������Ϊÿһ��վ���ʵ�����
        �����в�ͬ���� player ����Ҫ��wizard �������ȵ����⣬
        ����һ�����Ժ���İ��ſ�����ʹ fire �� row ,stefan ��
        ����ȫ���Ľ��п�����������һ���棬Ҳ���Թ˼�����վ player
        ����Ҫ����


���ϼ�������ֻ���ҵ�һЩС����������Ҳֵ�ÿ���һ�¡�




---
����: ����(ice)
��Ŀ: about yuyin's data
����: Sun Apr  2 07:34:13 2000
since yuyin now is a player, I suggest to cut his skill and reputation down to
a
normal stage.
if no one has objection, I'll mail yuyin to deal with this case.


---
����: Ice
��Ŀ: >about no tell
����: Tue Apr  4 06:06:25 2000
let's try with it first, if it still happens that player got flood,
release the no_tell function bah.:P


---
����: Suicide
��Ŀ: >about no tell
����: Tue Apr  4 02:26:02 2000
I think "  set can't tell a player the same thing within 10sec"
is a good idea .
To have a short busy time is a bothering thing.
:)


---
����: �һ�(fire)
��Ŀ: about no tell
����: Mon Apr  3 23:56:15 2000
Yes, we have a function find_body(id)->set_notell(xxx) to disable tell.
But at first I just want this used by wizs who can avoid repeatly disturbed
by players. But for players, I think our mud encourage them to communation
so don't want to release this feature to players. But we meet some problems
that some players use tell to flood. so what do you guys think, to open
no_tell for players or set can't tell a player the same thing within 10sec
and each tell has a short busy time to avoid flooding(just like
chat). So which 
way do you guys think it's better?



---
����: �һ�(fire)
��Ŀ: recover wujun
����: Tue Apr  4 19:32:53 2000
the function to recover an areas soldier is:
@AREA_D->set_area("wujun","troop",AREA_D->get_area("wujun","ssoldier
s")["new"]["troop"])

but some time need to check if got commando there :)


---
����: Fire
��Ŀ: >>about no tell
����: Tue Apr  4 19:31:58 2000
On Tue Apr  4 02:26:02 2000 Suicide wrote post #1316:
> I think "  set can't tell a player the same thing within 10sec"
> is a good idea .
> To have a short busy time is a bothering thing.
> :)
it is not a real busy time
just you can't tell twice within 1 second
because if we tell, need spend some time to input
so unless a ppl use robot or trigger, it is impossible to
tell twice within 1 sec, hoho


---
����: Fire
��Ŀ: >bite's home file is corrupted.
����: Wed Apr  5 22:27:28 2000
On Tue Apr  4 20:31:36 2000 ����ү(suicide) wrote post #1320:
> Today when i online bite tell me she can't home and can't cmd call.
> I checked her home file /data/home/b/bite.o i found i even can't more it.
> The error is just like we try to more file in mirror.
> So i delete the bite.o file and let her rebuild a home.
> She tell me she will lose 750 gold for this and ask me for money.
> So i add her golds to build new house.
> I asked her if she know what's wrong she had do her house.
> She tell me when crash she is in her own home when relogin she can't 
> home any more.
> 
> Am I wrong to add her golds to rebuild home?

I think what you done is right :)


---
����: Fire
��Ŀ: >cut of yuyin's skill
����: Wed Apr  5 22:08:37 2000
On Wed Apr  5 00:35:17 2000 ����(ice) wrote post #1324:
> i cannot find anyone interested to reply my post, so i go ahead with
> cut yuyin's skill for the reason that his skills was set when he was
> wiz, now he is an ordinary player, so should not be special.

right, just do it :)


---
����: ˹̹��(stefan)
��Ŀ: re: qinghua mirror
����: Wed Apr  5 08:17:02 2000
Actually I replied all of them that no confirmative answer will
be given until mid of April. But they just kept sending emails, often
same email repeated 4 times, which made me too lazy to answer :PPP

I will follow up with this guy later, but which application is his? I
am still confused :PP


---
����: ����(ice)
��Ŀ: cut of yuyin's skill
����: Wed Apr  5 00:35:17 2000
i cannot find anyone interested to reply my post, so i go ahead with
cut yuyin's skill for the reason that his skills was set when he was
wiz, now he is an ordinary player, so should not be special.


---
����: ����ү(suicide)
��Ŀ: To Stefan
����: Wed Apr  5 00:28:19 2000
��Ϳ˵�������ǹ��ڷ�վ����
��Ϳ˵������ôһֱû��stefan�Ļ���ѽ
��Ϳ˵�����Ҷ��켱����
��Ϳ˵����suicide? ������
����˵�ͷ��
��Ϳ(yuera)�����㣺��ô��û��stefan�Ļ���ѽ
��Ϳ˵�������׳�ʲô�����ˣ�
��˵����stefan said there r 4 ppl in tsinghua applying for mirror.
��Ϳ˵������ͬ�����ǵ����룿
��˵����He is confused and don't know how to use.
��Ϳ˵������֪��������������ô����
��Ϳ˵�������ˣ�Ҫ˵��һ��
��Ϳ˵����������һ��Ҫ�����Ǻ���
��˵����We can only choose 1 .
��˵����and none of it is official site.
��Ϳ˵��������˵4��������һ��Ҫ������һ������
��Ϳ˵�����ٷ���
��Ϳ˵����ʲô��ٷ���
��Ϳ˵�������Ƕ���xyj2000��ô����
��˵�����廪�Ĺٷ�վ��
��Ϳ˵�����������ԣ�
��Ϳ˵������������xyj������վ��
��˵����i don't know how stefan will choose.
��Ϳ˵������Ҫ��ô���ſ����أ�
��Ϳ˵��������stefan��Ҳ��������
��Ϳ˵������Ҳ������
��˵����u can mail him and tell hime sth in detail .
��Ϳ˵�����ҷ���3������
��Ϳ˵����һ�ⶼ��û��
��Ϳ˵���������Һ��ż�
��˵����ok. i will tell him about this again.
>��Ϳ˵��������Ҫ��4���е�����һ������������
����˵�ͷ��
>��Ϳ˵��������֮������Э�̾�������
��Ϳ˵����ϣ�����Ǻ�����֮���ܹ���ȡ����
��Ϳ˵�������⣬�Ҳ���������˵�Ĺٷ���ʲô��˼
��Ϳ˵��������xyj2000�ܿ����ǵõ���׼��
��Ϳ˵�������ǣ�����˵һ�£���ΪѧУ�����������׵�֧��
����˵�ͷ��
��˵����i will post him right now.
��˵����' bye.
��Ϳ˵�������ǿ�xyj��ʱ�򣬺�����˵����


---
����: ����ү(suicide)
��Ŀ: bite's home file is corrupted.
����: Tue Apr  4 20:31:36 2000
Today when i online bite tell me she can't home and can't cmd call.
I checked her home file /data/home/b/bite.o i found i even can't more it.
The error is just like we try to more file in mirror.
So i delete the bite.o file and let her rebuild a home.
She tell me she will lose 750 gold for this and ask me for money.
So i add her golds to build new house.
I asked her if she know what's wrong she had do her house.
She tell me when crash she is in her own home when relogin she can't 
home any more.

Am I wrong to add her golds to rebuild home?


---
����: Row
��Ŀ: >cut of yuyin's skill
����: Wed Apr  5 23:14:03 2000
sorry ice, these days got some personal problem...
anyway, i support you just as b4.


---
����: Ice
��Ŀ: >war time
����: Thu Apr  6 16:23:30 2000
could be a way for now.:)


---
����: ˹̹��(stefan)
��Ŀ: war time
����: Thu Apr  6 09:44:16 2000
how about make it rotate every 20 hours, so eventually it will come to
morning, afternoon, evening, midnight, etc.

Or similar concept :)


---
����: ����(ice)
��Ŀ: seems sth got to be changed
����: Thu Apr  6 08:56:55 2000
ʱ��:  Thu Apr  6 07:48:41 2000                Post-id: 625 (632 Last)
����:  ����(lonestar)
��Ŀ:  ����sg
----------------------------------------------------------------------
�����������
ֻ�������������˺ö�newbie
���Բ��ò����
�����ҹ���������û�����߶�ʧ��xiapi lujiang
��ͬ���������ǵ�һ�η���lujiang�ɹ���������xixixi 30k
��������ĸе�����
�����Һ�yesl����ԭ��
����ʱ��������
����û�������ܳ��ں�xixixi����ҹ�Կ�
��sg mud�������Ƹе���������
�����Ҹ��˾�������sg@zj
Ҳ��sg��Ϸ�ȵ���˭��24 hour���߰�


from this post, I think we should stop to consider this matter,
i dun think make a player 24 hrs on line will be our purpose, but
actually, it is.:(
however, every mud has the same problem, more time, a higher highhand,
but I think we can have an advantage against other wuxia muds, our
war system can be rewrite to make this kind of problems better.:)
so ...  * addoil fire
* escape


---
����: Ice
��Ŀ: >yuyin'skill
����: Thu Apr  6 08:51:17 2000
On Thu Apr  6 02:49:43 2000 ����(group) wrote post #1330:
> ice, it seems that what you did does not get the effect^^
> you must ensure that yuyin is online, then you can reduce his skills
> by the way you use^^
> 
> best regards

faint, i'll try to do it when he is online.:(
* fool


---
����: ����(group)
��Ŀ: yuyin'skill
����: Thu Apr  6 02:49:43 2000
ice, it seems that what you did does not get the effect^^
you must ensure that yuyin is online, then you can reduce his skills
by the way you use^^

best regards


---
����: Suicide
��Ŀ: >re: qinghua mirror
����: Wed Apr  5 23:50:29 2000
I also don't know which id he use to apply for mirror.
But when i met home again i will ask hime about it.


---
����: Suicide
��Ŀ: >war time
����: Thu Apr  6 20:16:14 2000
agree .


---
����: ����ү(suicide)
��Ŀ: add a mail list.
����: Thu Apr  6 20:21:46 2000
Can we use the smtp daemons that had been finished by emperor to
be a mailist server?
Then if we met some good articles we could use a cmd to let smtp daemons
to mail these articles to all the ppl who have registered here.
So every ppl registered here can get the new things happened here even
without login here when they r busy.


---
����: ����ү(suicide)
��Ŀ: war time
����: Thu Apr  6 20:18:33 2000
But the best way i think is that we should open war everytime.
So we have to addoil to strong the war system.
addoil .


---
����: ����ү(suicide)
��Ŀ: To fire :
����: Tue Jul 25 19:42:31 2000
  ̫���ƶȵ�����code�Ҷ�д�õ��Ի���������,���ڹ�Ա��Ǩ��ְ����һ�����ҹ�Ա
����ֵ����(NPC����),���ʲ��ú��ַ�ʽ?һ:��Ҵﵽ�ʸ�;������Ҫ
��:ϵͳ�Զ���ѡ,�򺺵��ټ����,fire�����һ�ַ�ʽ��.


---
����: �һ�(fire)
��Ŀ: Re suicide
����: Tue Jul 25 16:11:26 2000
�ڷܶȵĽ��鲻������������NPC������һ����
���ˡ�����NPC��֧�ֶ��һ���̫�˽����ʵ�֡�
�ҽ������NPC����̫�أ����Բ���suicide���ڷ�
�ȿ��˷���ϵͳ�Զ����������Ƕ��ڹ�ʦ���ҽ���
����ѡ�ٵķ�����ÿһ����Ա����������ҹ��׺�
�ڷܶȼ���һ��Ȩֵ�������ڽ�Ŀǰ��voteϵͳ����
һ��ר������ѡ�ٹ�ʦ����ʦ�����н����������
����ѡһ�졣���Ҫ����ʦ������һ����֧�ֶȺ�
֧�ֱ�����������������ͷ�����ܣ���Ϊ��ҵ��ڷ�
���͹��������ߣ������ܲ�����ʦ����һ�����׵�
��ʦ���Բ����ܡ�����������������Զ�̫��ͬʱ
�ù������������ȼ��ﵽһ���̶�ʱ���ù�����������չ
����
1�� ����ѡ�ٹ�ʦ����Ϊ����Ҫǿ�󣬱����к��ĵ�
      �쵼�����ѡ������ʦ����һ����չ��Ȼ�����ơ�
2�� �������̫�ض�����Ҳ����� �޸Ķ�����Ҫ�󣬼���
    �ڱ�����һ�����������������(�ڷܶȺ͵�������Ҫ
    ��Ҫ��)��֧�֣��ſ��Զ�����
�����ֱ��ǣ���ҹ��ǵ����ƣ�NPC��������ƣ�����
Ҳ�п�����ϲ���ܲٵ�������������������ܲ�һͳ����
������
���ԣ�suicide�����Ȱ�NPC�Զ�̫�ز��ݸ�ã���һ��
�ٿ��ǹ�ʦ���⡣addoil suicide



---
����: ����ү(suicide)
��Ŀ: To fire
����: Tue Jul 25 06:41:38 2000
Did u rm the file of npcai_d.c in /daemons dir?
I have upgraded it and put it in the dir /wiz/suicide,check it bah...
The 2nd copy add the function of ��Ա���Զ���ְ.


---
����: ����ү(suicide)
��Ŀ: ��������
����: Tue Jul 25 04:36:23 2000
/sgdomain/event/ev_position.c�ĵ��Ĵ��޸�
1)  ���н�ɫ��һ�γ�Ϊ��ְʱ,�趨��ʼ�ڷܶ�tsxΪ200
/daemons/npcai_d.c�ĵڶ����޸�
1)  ��ѲNPC���Ƶ���(����ΪNPC��û����ҹ�ʦ)�Ĺ�Աְλ����,û��Ѳһ
�ι�Ա���ڷܶ�
    ��15,���ڷܶ�С��0ʱ,����ְ,���������ط����ҹ�Ա,�Ƚ�ְ����
��Ա,��һ������
    �ܶ���Ϊ��,��Ž�ְ��ط���Աְλ,��Ա����ְʱ,�����͹�������1/5
(��֪�Ƿ�̫��,
    �뽨��),����ְ���ʼ�ڷܶȻָ���100,��ֹ������ڷܶ�Ϊ��ʱ�ڴ���
ְ�ֱ���ְ,���
    ������ʧ.
2)  ̫�ر���ְҲ�������͹�������1/5.
3)  NPC����(��û��ʦ)�����Ϊ̫��ʱ,ֻ������ҹ�Ա,������ط���Ա.


---
����: �һ�(fire)
��Ŀ: about suicide's code
����: Tue Jul 25 00:52:00 2000
I haven't check your idea clearly.
seem not bad, I will check them tomorrow and 
give comment asap.

admire suicide

addoil sucide.
bow


---
����: �Ƶ�(emperor)
��Ŀ: һЩ����
����: Mon Jul 24 08:18:18 2000

һЩ����

1�� ����������ֻҪһ��������������һ���������JOB��
�Ǿ���ζ�����ܵ�һ���������ڵĵ������������������
JOB ��һ����ȫ�׻����˵������˵��������׾ٵġ�
    ��ʹ��SUICIDE ������̫�غ͹�ʦ�����ƶȣ����ǲ���
����������⡣
    �����ҽ�������һЩJOB�� ��ЩJOB �Ǹ������������
����Ŀǰ���ڹ�ʦ��̫�صĹ��ҹ��ף���ΪSUICIDE ������
������̫�غ͹�ʦ�����CODE�����뻹�ǲ��ðɣ����ȼٶ�
ÿ����Щ��Թ�ʦ��̫�ص�JOB���ཱུ��500���ҹ��ס�����
JOB �൱����ʷ�ϵĽ����ԣ������ɶ����εĹ��ҹ����ٴ�
��Ҳ���ػ⼸����Զ�ԩ���ڷ粨ͤ�����������𩼸���
��һ�����ͱ�������ǰ���ٻأ�����������ɽ����һ��ʧ�ܡ�
��ʷ�������������ܶࡣ
    ��������һ��������JOB��
        ��ҿɳֱ� 500���ƽ�ȥ��¸�ѵж�������ڹ���ĳ
��NPC �������NPC ��������ж���ҵĲ��ԣ�ÿ��һ�β��ԣ�
����ж���ҵĹ��ҹ��׽��� 50�����߿��Ǹ��ݻƽ�������
������Ӧ�����Ĺ��ҹ��ס�����Ҳ������Ҷڻ��Ļƽ�������
����ȥ����������˹ܼҺ󣬻ƽ���û�ط��á�
    ������̣�
    A�� ������������ڹ�����Ҫ��ʵʩ���Թ�����
    B�� ���ڹ�������ʾͬ�⣬���������ڮ���ĸ���ң�NPC
���ܱ�ʵʩ����
    C�� ���ڹ������ж��Ƿ�������һ�����ҵ���ҡ�����ǣ�
�����������ȥ��¸ĳ��NPC �����NPC ��Ȼ�ǵж��������
���Ĺ�Ա�����뱻ڮ�ٵ������һ�����У�Ҳ���Բ���һ����
�С�����һ����ڮ�������BLOCK�����С�
    D�� ����ҵ����NPC ��ask ĳĳ about dihui�����
NPC �ٺ�Ц�˼������ʵ�����Ը������ٻƽ�100-1000����
�����������ڻƽ�����ȡ����������ϵĻƽ���������������
��100 GOLD�������ڻƽ�û�ã�������Ļƽ���������100 ��
������Ļƽ���������100����random��2��==0 ���ߴ�������
�Ļƽ������Ļ��������ұ�NPC �ؽ��η�����
    E�� ���û���ؽ��η������������Ļƽ�������Ӧ�ۼ�
��ڮ����ҵĹ��ҹ��ף�����ҥ��Ƶ������ʾ��ĳĳNPC �ڹ�
����ǰ����һЩ���ԣ�ĳĳ��ҵĹ��ҹ��ױ������ˡ�ͬʱ��
���JOB ����ҵĹ��ҹ�����Ӧ���һЩ��ֵ��
    F�� ��ڮ�����ÿ���죨12Сʱ��֮�ڵĹ��ҹ������౻
����500�����Ǽ���ֵ��

    �����������JOB ����Ҽ�����ù��Ķ��ǣ�����Ҳ��
�������ʦ�����⡣ͬʱҲ���ڹ�ʦ������Ҫѧ��ˣ��ı��Ҳ
��һЩ����ڽ�����ĳ��ID�Ĺ��ҹ��׺�ȴ���������һ��
ID������ȥ���ٵڶ���IDʱ��ȴ���ֻƽ��Ѿ������ˡ���ι�
�����˶��ֲ����Լ���ID�ڶ���ǰ�������˽������������⹻
����������ͷ�۵ġ�������Ϊ�Լ���������ҳ�����������
�������ܷ�չ�Լ����������������ͷ���ˡ�
    ���JOB ���ö������κ��ѳ�Ϊ��Ա����ң��������ǹ�
ʦ��̫�ء�
    

2��suicide��npcai_d��Ѳ��ʱӦ�ö�ÿ����ҹ�Ա�����жϣ�
�����Ƿ�߱�������ְ���������������Ļ��� Ӧ�ñ��Զ���
Ϊ��ְ�����������ˡ�
    ����ҹ�Ҳ��һ����

3������ս������ʱ�����ѡһЩNPC ����ұ�ץ����ץ��NPC
��һ��ʱ�����������ˡ�����֮ǰ�ڵ�����Ϣ������һ�
ս����ĳĳ��ĳĳ������ұ�ץ����һ�ɱ���ͷ����Ӧ����
������������һ�������м���һ����ͬʱ������ط����׵�ָ
�ꡣ����������������ȫ����ΪNPC��
    

ͬʱ��Ҳ�ܷ�ֹ������������м�war��warȥ��������߾��顣
���������war��warȥ�����ܻ�ò���ʧ�ˡ�ֻ������ͳһȫ��
����Ҳ��ܻ�ø��߾���Ľ�������ź���
����Ҳ���ͨ��war��ø��߾���Ľ�������ź���


---
����: ����ү(suicide)
��Ŀ: /daemons/npcai_d.c���޸ı���¼��
����: Mon Jul 24 00:12:55 2000
����˵����
    �Գ���Ϊ��λ��ÿMUDʱ���һ��(16����)����˳���99������������Ѳ��
���е�����Ѳһ��������ʱ����16*99=1584���ӣ���һ���144����)��������
���̫�ػ���ҹ�����ʦ�ĵ�������ʲôҲ����������NPC���Ƶĵ���ִ������
�����жϣ�
    1��û�����̫�أ���ѡ���̫�أ������ǹ��ҹ���>��500*����level����
    �õ���������ҵ�ǰ�������ݸ��˹��ҹ��׸ߵͰ�һ��������ѡ��
    2�������̫�أ��������ڷܶȣ�����ұ���ѡΪ̫��ʱ����ʼֵΪ200����
    ��ÿ��Ѳһ�ν�20����ֵ�������ۣ������ڷܶȽ�Ϊ0��ͻᱻ��ְ���ڷܶ�
    ������ͨ����ĳЩ�Գ��з�չ��Ҫ��job�����ۣ���ʵ�֣�ÿ��һ��job��һ
    ��Ҳ����˵������̫�ر���ÿ�죨ʵ��ʱ�䣩��20����Ҫjob�ڷܶȾͻ᲻
    �������������Ϊ̫�غ�ʲô��ҪJobδ����10����ѲҲ����11���ͻ��Զ�
    ����ְ������ͨ������ÿ����Ѳ����ֵ��������ʱ��20)�Ϳ��Կ���һ���ڷ�
    �����̫��һ���������job.
    3)�����Ƿ���ٽ����ٵĳ��п�ս������ʱû�����Ժ�������䣩��
    4)���Ǳ������Ƿ���ʲô���ʱ�䷢��������䣬��䣬����Ϯ�ŵȵȡ�(δʵ��)
����: (���ѳ�������ͨ��ϣ����Ҳ���)
      1  ����add_country("dong zhuo","xiangping")����ƽ�Ƚ���һNPC��������
      2  Ͷ����NPC���������Լ��Ĺ��ҹ��ס�
      3  @ "/daemons/npcai_d"->test_npc_taishou("xiangping")�Ϳ��Խ��в����ˡ�
      4  �ڷܶȵĲ���Ϊ"tsx".
      5  update�ó�������һ��ʱcall,������ɺ����������
         @ "/daemons/npcai_d"->remove()����ɾ��.
      
���ܻᵼ��BUG���������:
      1  ���̫������̫�غ�ĳ�ְ�����ѿ��ǲ���ͨ����
          
��ϵͳ���������Ӱ�죺
  ��Ҫ����JOBϵͳ�����ӽ����ڷܶ���һҪ�ء�(�޸�/daemons/char_d/loca
lcontribution.c
�жϵ�̫�����ӹ��ҹ���ʱ��ͬʱ��һ���ڷܶ�).
  
  �����һ����ɣ�ʵ�������Ǿ��Ѿ�����ʵ�п���̫���ƶ��ˡ�Ȼ����̫��
�ƶȵĻ���������
�������������̫�غ��������ʦ��������������2/3��NPC��ɫ֧�֣�û����
�Ĺ�ʦ��̫�����
�õ�����2/3NPC��Ա��֧�֣������޷�����ʦ��ְ�����������ò����ͻᱻ��
ʦ�������������
�����ǾͰѹ�ʦ��̫���ƶ��ںϵ�һ���ˡ�
  ���fireͬ���������ĸ��ģ��Ҿ������޸�localcontribution.c,��������
�Ϳ�������һ����
ʽ����̫���ƶ��ˡ�
      
���������������ķ������в���������֮����ϣ������ܼ�ʱ����ָ������


---
����: ����ү(suicide)
��Ŀ: /sgdomain/event/ev_position.c�ĵ����δ��޸�
����: Mon Jul 24 00:12:37 2000
1)  Ϊ�˱��ֺ�ԭ����ʦcode�ļ����ԣ���̫��ΪNPC��ɫʱ,�ж˹���
    ��û�й�ʦ����������̫���ƶȵĻ���������һ���µ��뷨������
    ����̫�غ��������ʦ��������������2/3��NPC��ɫ֧�֣�û����
    �Ĺ�ʦ��̫������õ�����2/3NPC��Ա��֧�֣������޷�����ʦ��
    ְ���������������������������µ�code�ﱣ���˶Թ�ʦcode�ļ�
    ���ԣ������Ժ��޸ĵĹ�������


---
����: �Ƶ�(emperor)
��Ŀ: king of kings
����: Fri Jul 21 21:14:08 2000
����֮����GBվ�㣺 www.kok.com.cn


---
����: ����ү(suicide)
��Ŀ: To fire
����: Thu Jul 20 21:34:28 2000
Open a new newsgroup bah,call it task.guoshi and move all about it
in wiz.com there
massage fire
hoho fire
:)


---
����: Suicide
��Ŀ: >>To fire:
����: Thu Jul 20 21:33:14 2000
I will modify the code of ev_ncpcountry to random select taishou,but i will
add a limit that the play that can be taishou must should fit the
qualification of the taishou.


---
����: ����ү(suicide)
��Ŀ: Finish Ev_position.c
����: Thu Jul 20 21:28:10 2000
I have finished the code of ev_position and had install in /sgdomain/event.
I had test all the situation what i can think out and u guys had
mentioned to me , 
to avoid big bugs.welcome to check it.
If there are still sth i can't think ,pls tell me.


---
����: ����ү(suicide)
��Ŀ: /sgdomain/event/ev_position.c�ĵڶ����޸�
����: Thu Jul 20 21:19:26 2000
1)  ��̫��ΪNPC��ɫʱ,�ж��ǲ������̫�����õĻ�����ǲ������.


---
����: Fire
��Ŀ: >To fire:
����: Thu Jul 20 16:48:16 2000
On Wed Jul 19 22:36:13 2000 ����ү(suicide) wrote post #1601:
> ��ϣ������ϵͳ�����ѡ����>500�������̫��,�ɲ����Ըĳ�,��
> ��Ҵﵽ̫�ر�׼����NPC����������̫��
> ,������С�����׿�һ����̫�ض���ǵ�̫�ؾ�Ҫ������һ��,�Ƚ�ƽ��,
> �����ͬ������,�������ó����������̫�ص�code.
>  .
> 
> 
> 
> 

TI think random is a little better.
If player ask the position, once he got thatrequirement, he can
become localleader immediately.
so it maybe easy for dummies to get all the local's leader position
after several days of restart.
If we choice the random, The dummy may not so easy to
get the position. and we can make the assign of new local leader
last for about 2 weeks or even longer
it may give more chance for real players.

However, your suggestion about different requirement
for different level of city is very good.
You can give a list of the different requirement and then modify 
the ev_npccountry.c

about the ev_position.cI am not sure about the bug you metioned.
If it has that bug, please fix it bah, hoho :)

addoil suicide.


---
����: ����ү(suicide)
��Ŀ: To fire:
����: Wed Jul 19 22:36:13 2000
��ϣ������ϵͳ�����ѡ����>500�������̫��,�ɲ����Ըĳ�,��
��Ҵﵽ̫�ر�׼����NPC����������̫��
,������С�����׿�һ����̫�ض���ǵ�̫�ؾ�Ҫ������һ��,�Ƚ�ƽ��,
�����ͬ������,�������ó����������̫�ص�code.
 .






---
����: Suicide
��Ŀ: >Re suicide about ev_position.
����: Wed Jul 19 22:30:33 2000
I know that the old code in ev_position will display a menu
and ask the user to choice which position he wants to apply.
But it has a big big bug ,when player input the officer id,system will 
not check if it is valid,even the officer id isn't in that area or is a nation
officer,so i had modified the code to fix this bug.
I had modified that only the localleader is a npc ,then player can ask
higher local postion,but forgot to judge if the king is player or Npc
localleader is granted by player,so i will fix it.:)

Fire, Have u check my code of ev_position.c that i have installed 
in system and now only can be tested by wiz for asking postion.
Check it bah,hoho,give me ur suggestion.

In ur post u said that will we disable guoshi when next restart,
Will we use the new ev_position ,if it is ,pls tell me,
I will delete the limited code (which only open new function to wiz)
before restart.:)


---
����: Row
��Ŀ: >The san7
����: Wed Jul 19 19:48:14 2000
On Wed Jul 19 18:58:44 2000 �һ�(fire) wrote post #1597:
> I just can't believe what ice send to me is only a copy of the
> files under his computer's san7. How can I just run them without
> the installation. I believe every big software as san7 can work
> only when you install it properly in your computer and during 
> this processit may copy some dll under windows directory or 
> register some environment constants. Kick ice, 
> 
> It took me so much time in vain
> 
> Sigh
> 
laugh, comfort fire, just let ice EMS the CD to you.
or re-ftp up the installation file.


---
����: �һ�(fire)
��Ŀ: The san7
����: Wed Jul 19 18:58:44 2000

I just can't believe what ice send to me is only a copy of the
files under his computer's san7. How can I just run them without
the installation. I believe every big software as san7 can work
only when you install it properly in your computer and during 
this processit may copy some dll under windows directory or 
register some environment constants. Kick ice, 

It took me so much time in vain

Sigh



---
����: Ice
��Ŀ: >something strange in news system
����: Wed Jul 19 18:45:56 2000
I think we may have a dual way system anyway, both rules have
its own adv, also disadv, then we can choose sth in between.:P
later I'll try to make it together and post it up.


---
����: �һ�(fire)
��Ŀ: something strange in news system
����: Wed Jul 19 16:44:54 2000
I find I can't read the post in progress from
news command but can read it from board. It is strange,
some the msg id got some error so it cause the confused
problem. The post in progress can't be viewd by news
is 
1����ʦ�ƶȵĵ�����                    ���һ�(fire) Jul 17��
��������������������������������������������������������������������
�������������ܿ��Ҫͳһ���ֶԹ�ʦ�ƶ���������ʱ������������ֻ��
������������
1 NPC���ҽ������Զ�������ʦ��
2 ϵͳ������ذ�һЩNPC������ҽ���Ϊ̫�أ������ǣ�
  a ���ҹ��״���500��
  b ����û�����̫��(Ҳû�����ί�ε�NPC̫��)��
��ֻ��һ����ʱ�޸ķ��������ų��ٴε����Ŀ����ԡ�


---
����: �һ�(fire)
��Ŀ: Re suicide about ev_position.
����: Wed Jul 19 16:17:22 2000

In fact, the old code in ev_position will display a menu
and ask the user to choice which position he wants to apply.
but that one caused the dummy spy problem. So all the new
position has limited to R_SG. Now I think suicide can modify
the code and when the king and localleader are both npc
then the system will display a menu for the player to choice
position. Otherwise only grant R_SG position. However, please
also check if the localleader is assigned by a player localleader.
you can find some example code in the sgdomain/menu/pos.c
cheers, :)



---
����: �һ�(fire)
��Ŀ: about about san7.zip
����: Wed Jul 19 16:10:26 2000
I finally got that file. It took me about 24,300 seconds to download
in my office's computer. I have delete it from ice's directory.
The next task for me is try to burn a CD in my office so I can
install it on my home's computer. 
hoho :)
thanks ice


---
����: ����(ice)
��Ŀ: grrr....
����: Wed Jul 19 05:33:21 2000
I am exhausted involved in unlimited arguement...:(
I am going to pay a visit to my friend and drink sth today,
after that I'll resoncisder the whole topic, and provide some
other detailed plan.
suddenly remember some other reasons of we changed the former
rules to guoshi rules, and I think our former rules works as
suicide's anyway.  btw, do suicide know our former rules of
local rank? if u dun know, errr, I dunno where to chekc it.:(
if u meet me or fire, ask to explain then.
addoil all.


---
����: Suicide
��Ŀ: >>To stefan
����: Wed Jul 19 04:52:51 2000
�ÿ���Ŷ����Ҫ�Ķ����б���
�ÿ���Ŷ����Ҫ�Ķ����б�����
��û�з���sina.com��
�ҵ��ʼ���ַ��suicide75@wx88.net,����һ�»��ǲ��У�stefan���ٰ�æ���һ�°ѣ�
��


---
����: Stefan
��Ŀ: >To stefan
����: Wed Jul 19 03:27:25 2000
On Wed Jul 19 02:07:51 2000 ����ү(suicide) wrote post #1589:
>    Pls help me debug the smtp_d.c bah,i still can't use it.It is very
poerful
> for me. For i want that i can read those good posts after i offline.
>   To keep a mass log is a mass thing.
> 
> Beg stefan
> Massage Stefan
> Sweat stefan

ǰ�첻С�İ��Լ��� laptop ���¸�ʽ���ˣ�����Ķ���˲�仯Ϊ����...
�������ǲ���� :( 
SMTP ���ϴθ��������ԣ���Ϊ�»����� domain name ûŪ�ã��㷢��
sina.com �ͻᱻ�ܣ�����Ӧ�ú��ˣ��������Կ� :)


---
����: ����ү(suicide)
��Ŀ: To stefan
����: Wed Jul 19 02:07:51 2000
   Pls help me debug the smtp_d.c bah,i still can't use it.It is very poerful
for me. For i want that i can read those good posts after i offline.
  To keep a mass log is a mass thing.

Beg stefan
Massage Stefan
Sweat stefan


---
����: ����ү(suicide)
��Ŀ: ev_position.c���޸ı���¼�� 
����: Wed Jul 19 00:31:49 2000
���ܸ���˵����O--�ɹ��ܡ�N--�¹���
�ϣ���ask taishou about postion,���ֻ�ܳ�Ϊ��ְ��Ա�����ߵĵط���Աְλ
������Ҫֱ����̫����ָ����
�Σ����̫��Ϊ��ҽ�ɫ��ͬ�ɹ��ܣ�������û����ҳ�Ϊ̫�أ�ֻ����NPC ��ɫ
��������̫��ʱ�������������������㣬��ͨ��ask taishou about position��
�������õ��п�ȱ�ĵط���Աְλ��
����ģ�����ӣ�check_area_vacancy(p_area,officer_id)
���ܣ����ڼ�����������ְ��ְλ�ڱ������Ƿ���ں��п�ȱ��ԭ����ֻ������
�������������Ŀ�ȱְλ�������ѡ������������벻�ڴ��еĹ�ְ�󣬲����Ϸ�
�������Լ�飬�������ܵ�����ҵõ�������Ҫ�����й�Աְλ�����Ӹ�ģ���
����������������
����: (���ѳ�������ͨ��ϣ����Ҳ���)
      ���ڳ���������������code,������δ����ǰֻ����ʦ���Բ���,����Ӱ����
      ��ϵͳ.
      if (!wizardp(who)) //��δ����ǰֻ����ʦ���Բ���
  
��ϵͳ���������Ӱ�죺
1 �����ڸ���ְ��Ҫ��Ե������׶Ⱥ�������Ҫ��̫�ͻ�Э��������̫��ְ֮��
�����ع�ֻ��700���ɣ��峤�ĵع�ֻ��100������ֻ��1000������ϣ��fire��ice 
    ��ϸ���һ�£�����һ�¹�ְ����Ҫ��
2   ���ǵ����һ�����ӳ�Ϊ��ɫ�󣬼���һ�ڷܶȵ���ֵ������ɲ�ͬ�Ĺ���ʱ��
������������Ĳ�ͬ��������������ĵ�ʱ��Ĳ�ͬ������һ�����ڷܶȣ����ǹ�
������һ�̶�ʱ�����������������Ӧ���е��ڷܶ�������ֵ��ÿ����һ�̶�ʱ
������ϵͳ�Զ���ѯĳ������������ҹ�Ա���ڷܶ�����ֵ����[���ʵ������ֵ]
������[������������ֵ]���Ĳ�ֵΪ��ֵ��ϵͳ���뾯�棬����ﵽһ���������
�����Զ���ϵͳ���ְ��.��������������������飬����һ���Ϳ�ʼ���ڷܶ��ж�
������ϵͳ��
���������������ķ������в���������֮����ϣ������ܼ�ʱ����ָ������
����
 


---
����: ����(ice)
��Ŀ: dission between suicide and me
����: Tue Jul 18 19:02:28 2000
as suicide wish, I post the dission of guoshi here, grrr, not a good job
for me anyway.:P

����ʦ������ү(suicide)��ice,u mean when should write a vote system first?
����ʦ������ү(suicide)��But I think vote taishou is not a good thing.
> ����ʦ������ү(suicide)����̫�ػ���Ҫ��ʵ��,���ȴﵽ̫��
����ʦ������ү(suicide)����̫�ػ���Ҫ��ʵ��,���ȴﵽ̫��Ҫ�������̫��!
> ����ʦ������ү(suicide)���㿴�����в���?
����ʦ������ү(suicide)��������ʦһ��
> ����ʦ������ү(suicide)��Ҫ�ڷܵĹ�������һ���ﵽ̫�ص�����
����ʦ������(ice)��if I log 2 days after restart, I have no chance?
����ʦ������ү(suicide)��But too many cities
����ʦ������(ice)��taishou position is not permenant
����ʦ������ү(suicide)���������ͨ��һ��ʱ����̫����ɵ����������ж����Ƿ�
�ᱻ��ְ
����ʦ������(ice)��then we need to design some taishou job then
����ʦ������ү(suicide)��Just let taishou can also do job ,then ok?
����ʦ������(ice)��if taishou is so important, he is supposed to do some
higher lv of jobs
����ʦ������(ice)��but we didn't have any high lv jobs yet
> ����ʦ������ү(suicide)��If he is out to do job,can left his Ļ�� in meeting
room.
����ʦ������ү(suicide)���͹�����ù�ϵ
����ʦ������ү(suicide)��JOB1 �Ĺ�����ƥ!
����ʦ������ү(suicide)�������ҵ���˼������������
����ʦ������ү(suicide)�����fire������Ὠ��,�һ᲻�ϻ㱨����.
����ʦ������ү(suicide)�������������ط���Ա�����ƶ�
> ����ʦ������ү(suicide)���һ�㱨�Ҹ���ʲô����,ע����ʲô����
����ʦ������ү(suicide)�����ǾͿ���һ�߰��Ҳ���,һ�������һ���Ҫע��ķ���

* sweat


---
����: ����ү(suicide)
��Ŀ: Re :ice
����: Tue Jul 18 08:45:15 2000
From Ice:
>��������ڲ���̫��Ķ�������£������������ģ�
>1������ʦ��ѡ���ƶȸĳɴӸù����ҹ��׳���500���������ѡ3�����
>   ���ҹ��׵��ù���������ѡ��ÿ�˵Ļ���Ϊ���Ĺ��ҹ���ռ��ѡ�ߵ�
>   ���ҹ��׵ı��ʡ����û���˳���500���򲻴��ڹ�ʦ���������500
>   ����Ҳ���3�ˣ����㷽��һ������ѡ�����ˣ��ɹ��Ļ�����ˣ�ʧ��
>   �Ļ���Ҳ��Դ��ˡ�
   
Re: Ice����˵�ķ�������������ʵ�еķ�����ȫһ��,�����������ڹ���
    �������Ѵﵽ1000,�������й�ʦ�ƶȵı׶�.
   
>2����ʦ��ѡ���޸�Ϊ2���ɹ�������ɸѡһ�Σ�����ͬѡ���ƶȡ�Ӧ�ò�
>   ���ڲ���ʦ�������λ�һֱ���ε����⣬˭�Ĺ����ڷܻ���ʹ�����
>   ���ߵ��������⣬�Ǿ�Ҫ�ɹ�Ա֮����Э���ˣ��Ͼ�������Ϸ����һ��
>   ��˵�˾������Ϸ��������ɸѡ����ѡ�Ĺ�ʦ����ɥʧ�κζ�����
>3��������������ڹ�ʦ�����ζȽ���0��һ���ᱻ���������ʦְλ������
>   ��1���º����½���ɸѡ���������ʦְ�����ҹ��ҹ��׼��루�����
>   ��Υfire�趨���ҹ���Ϊ���Ժ����ĳ��ԣ���
Re: ʵ���ϵ�һ���õ���ʦ��������ӵ�����´�Ȩ,��������ȫ�����ų��켺
    ���������ѡ,��Щ���ܻ������λ�����Ҳ�������ι�ʦ��ѹ�����޷�
    �õ�����,�������ڵ���Һ����е���˼��,��һ���Ұ���,��һ����
    ����,��������ʦ����һ��Ⱥ����Ϊ.ֻҪ��һ��������ҹ�ʦҲ�ǻ�����
    ��ҩ,����һ��ľ�������Ȩ���д��,ʹ�������ʦ�Ŀ�����Ϊ0,���Ҽ�
    ʹ�жԷ��Ĺ�ʦ��ѡ,��Ҳ����õ�ԭ��ʦ���µ�֧��,����������Ҳ����
    ������Ȩ�Ӵ��ԭ��ʦ�������,�����Լ��������,�����Բ�ͣ�ܶ���ԭ
    ��ʦ�����Ҳ�ܲ���.�����ɹ�ʦ����Ҳ����,�ϱ�����õľ���.
    
>4����pos����жԹ�ʦȨ����һЩ���ƣ�
>   1 ÿ���һ����Ա��ְ�����ζȽ�50��
>   2 ÿ����һ����Ա�����ζȽ�20��ÿ����һ�ι��������ζȽ�50��
>   3 ÿ����һ����Ա�Ĺ���ְλ�����ζȽ�10��
>   4 ÿ����һ��̫�أ����ζȽ�20�������Լ���̫�أ����ζȽ�50��
>   5 ����̫�ز��ܵ�����ֻ��������������Ա��̫�ز��ܵ�������ֹÿ��
>      �ѵ������գ�Ȼ�����˷��ء�
>5�����������Ĺ��׶ȣ�ʹһЩ�Թ��������Ĺ�����һЩ��ʹ�����Ĺ�����
>   �ϴ�Ĳ��졣���������ˡ��������˵ȳɹ���Ĺ��׶ȼӱ���
Re : ������ʦ��Ȩ����ȷ�Ǹ��÷���,���Ǳ�����ʦ�ĳ�ʼ���öȾͲ���,��
     ����Ȩ�ǹ�ʦ���Ч����,����Թ�ʦ������Ȩ���������ϸ������,
     ʹ������������µ���Ҳ����Ӱ��Ͳ��粻Ҫ��ʦ.
     
�������ҵ�һ�����,Ҳ��֪�Ƿ�ƫ��,����ָ��,����ллice��ô���д�����
����,���Ұ����ܴ�.�ڿ���ice���ӵ�ʱ�����ֲ����˼����뷨,����ҷ������:
1 ȡ����ʦ,ʵ����ǰ�Ĺ��������ƶ�,��Ҳ�ͣ�ĳɳ�һֱ����Ϊ̫��,̫�����
  ֱ�Ӷ�������.�����ͻᵼ�ºܶ��Ե�������Ϊ�����Ĺ��ĳ���,ͳһ���¾ͻ��
  �ĺ���,��������������������´�־Ͷ���.�����ɹ��������ƶȵĻָ�,��
  �������ϲ��������������Ҵ����������Ȥ,��һ�����з�չ��ͳһȫ����ʹ
  ��Ҹ��гɾ͸�.
2 ȡ����ʦ�迼�ǵķ���:(�ҿ��Ǻܲ���,����Ҷ�����)
   2.1�ط���ְ�ķ���:
     a ��û�����̫��ǰ,���ʸ�ﵽ�����п�ȱʱ��NPC̫����������.����ҳ�
       Ϊ̫�غ�����ҷ���.
     b ���ڵط���Աְλ����,������Щ�õ�ְλ���ֳ�ʱ�䲻���ߵ���ҵĴ���
       ��������͹�ʦ���ζ�һ��������ڷܶȸ���,�ڷܶ�Ϊ0����ְ.
   2.2���ҹ�Ա�����úͷ���
     a ����ͽ�ְͬ�ط���Ա,ֻ�������������.
     b ����ȡ����ʦ��Ĳ���̫���ƶ�,һ���ǿ��Ե�ͬ��һ������,ԭ�еĹ��ҹ�
       Ա�����þͲ�����,�������ǿ��Կ���һЩ�µĹ���.(�õ������нˮ,��ǰ
       �߳��а�����ս,ĳһ�ǵĹ��ҹ�Ա������������������Ǯ�Ļ����ϵõ���
       �ߵĳɹ���,��������һЩ��������ֻ�й��ҹ�Ա�������ȵ�)
   2.3���ڹ����ѳ�Ϊ��λ,����Ҫ����ȼ�С�ĳ��п���������5����(��Ȼ�кܴ�
      �Ѷ�),��ȻС���е�̫�ؾ�һ������Ҳû����.
   2.4news�Ƿ�ҪΪ�����ǽ���һ���µ���,���ǹ��ù������԰�,������һ����־ֻ
      ��ͬ�ǵĲ��ܿ���.
   
   
       
       
   
   


---
����: ����ү(suicide)
��Ŀ: To stefan
����: Tue Jul 18 07:25:21 2000
  Stefan :
   The function of transfering news to email is still not
working,can u check it?
I need this function very much.thx.
                              suicide


---
����: ����(ice)
��Ŀ: about guoshi
����: Tue Jul 18 03:54:03 2000
guoshi should not be able to change the name of country as well.


---
����: ����(ice)
��Ŀ: mudlist
����: Tue Jul 18 01:37:57 2000
> mudlist
�� 9 �� MUD ���� 9 ����Ӧ�ģ����� 6 �����ڿ��š�
�� mudinfo <mudname> ����ȡ�������Ϣ��
Up  Mud              Address                 Lib           Open Status       
----------------------------------------------------------------------------
U   �^���@��         203.133.98.184   7878   Lima 1.0a9    mudlib translat   
U   ����־�Ϻ�վ     61.129.64.138    5000   Lima 1.0a2    open              
U   ����־̨��վ     211.72.114.51    5000   Lima 1.0a2    open              
U   ����־�㽭վ     202.96.109.11    5000   Lima 1.0a2    open              
U   ����־����վ     61.128.193.35    6666   Lima 1.0a2    open              
U   ����־��վ       209.249.156.100  5000   Lima 1.0a2    open              


errr, what's that


---
����: ����(ice)
��Ŀ: a funny program about sg
����: Tue Jul 18 01:36:11 2000
I found a funny question program, it has about 600 questions,
every time randomly choose 25 questions, the answering way is
similiar to our robot test, but those questions r just too tough,
how ever, take a look.
it's in /wiz/ice/sgyy.exe.
ps I used ftp/auto to upload and download, if works, dunno should
use binary or acsii.:P


---
����: ����(ice)
��Ŀ: about guoshi
����: Tue Jul 18 01:16:53 2000
��ʦ�ƶȳ�¯��Ŀ��������ǿNPC��������ҹ��Ŀ��⣬���ڵ�ʱ����
һ������ʷ���ã������������ƺ����еĹ�ʦ�ƶ��Ѿ�����������Ҫ�ˡ�
�ҹ۲쵽�Ĺ�ʦ�ƶ���Ҫ�׶����£�
1����һ����ҵ��Ϲ�ʦ�Ժ��Ҳ����Ƿ���ף�����������ȫ�����ɻ
   �������ζ��ǲ��ή��0�ģ����仰˵���������������ȫû�л���
   ȡ����֮�����ο����ڴ��Ļ�������ʦ���ˣ���������multilog����
   �ܻ����˵ģ����Ӳ����ܱ�ȡ������������������˭���Ĺ�ʦ��˭
   �������ʹ��ر�������һЩ�維׿��Ԭ�ܵȵĹ�ʦ��ͳһֻ��ʱ��
   ���⡣
2����ʦ��Ȩ���������ǵ�ͬ�ڹ����ģ����˲������á�����֮�⣬��
   ���������ܣ������ڹ�ʦ���ǹ����������������鲢��һ����Ϊ������
   ���Һõģ����Թ�ʦ��һЩ�к��ڹ��ҵ������ʱ��û��ʲô�ͷ���
3����һ����ʦҪ������ʱ�������԰ѹ������䣬Ȼ���Լ��ڹ������
   �ĵط����������Ҷ������Ժ���INFO N�鿴��ǰ���ҵ����ʱ����
   ��Ȼ�ڹ�ʦ��ְλ�ϣ���Ȼ��������ʹ�ù���ʦ��ְ�ܣ���һ��Ҫ�ȵ�
   ���ζȽ�Ϊ0�����Ҳ��л��ᵱ�Ϲ�ʦ��

��������ڲ���̫��Ķ�������£������������ģ�
1������ʦ��ѡ���ƶȸĳɴӸù����ҹ��׳���500���������ѡ3�����
   ���ҹ��׵��ù���������ѡ��ÿ�˵Ļ���Ϊ���Ĺ��ҹ���ռ��ѡ�ߵ�
   ���ҹ��׵ı��ʡ����û���˳���500���򲻴��ڹ�ʦ���������500
   ����Ҳ���3�ˣ����㷽��һ������ѡ�����ˣ��ɹ��Ļ�����ˣ�ʧ��
   �Ļ���Ҳ��Դ��ˡ�
2����ʦ��ѡ���޸�Ϊ2���ɹ�������ɸѡһ�Σ�����ͬѡ���ƶȡ�Ӧ�ò�
   ���ڲ���ʦ�������λ�һֱ���ε����⣬˭�Ĺ����ڷܻ���ʹ�����
   ���ߵ��������⣬�Ǿ�Ҫ�ɹ�Ա֮����Э���ˣ��Ͼ�������Ϸ����һ��
   ��˵�˾������Ϸ��������ɸѡ����ѡ�Ĺ�ʦ����ɥʧ�κζ�����
3��������������ڹ�ʦ�����ζȽ���0��һ���ᱻ���������ʦְλ������
   ��1���º����½���ɸѡ���������ʦְ�����ҹ��ҹ��׼��루�����
   ��Υfire�趨���ҹ���Ϊ���Ժ����ĳ��ԣ���
4����pos����жԹ�ʦȨ����һЩ���ƣ�
   1 ÿ���һ����Ա��ְ�����ζȽ�50��
   2 ÿ����һ����Ա�����ζȽ�20��ÿ����һ�ι��������ζȽ�50��
   3 ÿ����һ����Ա�Ĺ���ְλ�����ζȽ�10��
   4 ÿ����һ��̫�أ����ζȽ�20�������Լ���̫�أ����ζȽ�50��
   5 ����̫�ز��ܵ�����ֻ��������������Ա��̫�ز��ܵ�������ֹÿ��
     �ѵ������գ�Ȼ�����˷��ء�
5�����������Ĺ��׶ȣ�ʹһЩ�Թ��������Ĺ�����һЩ��ʹ�����Ĺ�����
   �ϴ�Ĳ��졣���������ˡ��������˵ȳɹ���Ĺ��׶ȼӱ���


---
����: Row
��Ŀ: >���ֳԲ�����?
����: Mon Jul 17 02:50:56 2000
On Sun Jul 16 22:02:49 2000 ����ү(suicide) wrote post #1579:
> ��ҥ�ԡ�ĳ�ˣ���Сͳ���������㹻��������Ѫ��������ˡ�

Ӧ���Ǵ�������˰ɡ�


---
����: ����ү(suicide)
��Ŀ: ���ֳԲ�����?
����: Sun Jul 16 22:02:49 2000
��ҥ�ԡ�ĳ�ˣ���Сͳ���������㹻��������Ѫ��������ˡ�


---
����: ����ү(suicide)
��Ŀ: To stefan
����: Sun Jul 16 20:53:35 2000
   The function of transfering news to email isn't work,can u check
the smtp log?


---
����: Fire
��Ŀ: >tai yuan base
����: Sun Jul 16 16:33:28 2000
On Sun Jul 16 08:49:46 2000 ˹̹��(stefan) wrote post #1576:
> noise reported that ganjin of taiyuan's base always drops
> from 100 to 29 suddenly, I am not sure what is the reason.

I think that may caused the data of taiyuan happenly connected
with other base. But don't know which one and how they connected
each other. escape


---
����: ˹̹��(stefan)
��Ŀ: tai yuan base
����: Sun Jul 16 08:49:46 2000
noise reported that ganjin of taiyuan's base always drops
from 100 to 29 suddenly, I am not sure what is the reason.


---
����: Emperor
��Ŀ: >about san7
����: Fri Jul 14 05:54:14 2000
On Thu Jul 13 23:45:26 2000 �һ�(fire) wrote post #1571:
> hi ice, I don't have san7, can you ftp it back
> to the lima ?
����־�ߴ��Ҹо������棬���Ĵ�Ҫ��ߴ��Ĳ������÷ǳ��򵥣���ѡ�ˡ����ա�
�����ɫ����ģ�����Ҫ���೤ʱ�䣬����ͳһȫ�����ߴ��и���BUG���Ҿ���̫û��˼
��Զ�����Ĵ����档���ٵ�����������һ������һ����poor koei��


---
����: ����(ice)
��Ŀ: >about san7
����: Fri Jul 14 05:40:30 2000
ack, the full size of the game is 240MB, I think if I zip it it'll still
be 100MB sth, anyway, I think ICQ will be better to trans big files point to
point, so next time I meet u, fire, we can try.
errrr, this weekend I won't show up, hope next week the server work well then.
addoil


---
����: Stefan
��Ŀ: >about san7
����: Fri Jul 14 00:08:44 2000
On Thu Jul 13 23:45:26 2000 �һ�(fire) wrote post #1571:
> hi ice, I don't have san7, can you ftp it back
> to the lima ?

oh NO! It will add too much space to the backup :PPP We are having
a backup size of 15M zipped ....


---
����: �һ�(fire)
��Ŀ: about san7
����: Thu Jul 13 23:45:26 2000
hi ice, I don't have san7, can you ftp it back
to the lima ?


---
����: ����(ice)
��Ŀ: I can connect to internet leh
����: Thu Jul 13 22:34:58 2000
well, I finally got an internet connection in my room.:)
couple of days ago I just cannot log to the main even the main's status
in other mirror is open, but now the speed for me is like flying in the air
compared to PRC..:(
and I'll start to show up after this weekend, i can be reached
by the email "finger ice"(free) and mobile phone +31615351046 (costly):P
or the ICQ number stated in the former post.


---
����: Ice
��Ŀ: >about the guo shi
����: Thu Jul 13 22:22:20 2000
On Thu Jul 13 20:59:20 2000 �һ�(fire) wrote post #1565:
> the reason to have guo shi is to give the npc country a chance
> to survive if it got a very good guoshi. hoho :)
> But seems this feature is misused. I will modify the system to make
> it more fair. thank your suggestion, suicide. :)

fire have san7? take it as a reference bah.:)
if u dun, I have a HD version in my laptop, I can use ICQ to transfer to u
if u wish, my ICQ number is 13104091, needs authorization, state u r then.:)
ps it's a JP version, but can still play with since there still some
chinese chars within, no difficulties at all.:)

about guoshi, I think it's not suitable for the current situation, I think
we need to do sth to deal with the NPC's kings AI in managing a country,
like changing cities, changing positions etc. the king should have his
own mind as well, sometimes player asks for change, sometimes he changes it
by his own willing, if not agree to obey, decrease loyalty or be fired.:P
sth like that.


---
����: Ice
��Ŀ: >re: emperor
����: Thu Jul 13 22:15:20 2000
On Mon Jul 10 17:38:24 2000 ˹̹��(stefan) wrote post #1555:
> ʵ���ϣ���Щ��Ϣ���ˮ������ģ����ڽ�����ȷ�������ֲ�����ʽ�� server
matrix��
> ��������������ڽ�������Ϸ���������ǵ���һ����Ŀ�����Ҳ��ǽ���������Ŀ��
> ����֮���Ǻ� 263 �����ģ����������ļ��� MUD �������ǿ���ɱɱ
> �� RPG �࣬û�д�ǰ;���������Լ�֮�侺���ͺܼ����ˡ��������ĺõ����ڿ���
> ֻ���ձ���ʯ��ʱ���� Sony �� Ever Quest��ʯ�Ѿ��� 20 ̨������ͬʱ���ˣ���
����
> ��
> ���������ص�ƿ�����⣬Ŀǰ�Ѿ���̨�������ת����û�е���½����
> 
> �����ϣ�������ϷȦ����ô����΢�Ӵ�һ�¾Ͷ���ʶ�� :)

��������֮ǰ����һЩ��־���������ǹڵ�������������Ϣ�������Ժ�Ҳȥ��
���ǵ���վ���Ѿ������˵����Ĳ����ڣ�����վ������cn.yahoo.com�����ҵ���
��������Ϊֹ�ҵĸо������ǵ���Ϸ���ݲ����ḻ��Ҳ������Ϊû�нӴ���
��Ϸ��������ֻ���ܲ⡣
����������ͼ����������Ϸ����󻮣������������򲿷�.:P������˼��̫�࣬
��Ҫ�ú��������.:)�����Ҳ�ȷ���Ƿ����в��ֶ�Ҫ��һ����ϸ���󻮣�
���ǵȴ�Ұѿ�����۶������˲�����ϸ�µķ������ۡ�


---
����: Suicide
��Ŀ: >>���쵱����ʱ�ĳ�����Ϣ
����: Thu Jul 13 21:09:59 2000
agree with stefan .I also saw the disk wrong err last time.
pls change server quickly bah.
And i want to be the admin here for my seldom meeting fire here.
And i want to code to solve the guoshi question.


---
����: ����ү(suicide)
��Ŀ: To stefan
����: Thu Jul 13 21:06:30 2000
Pls change the smtp address to this machine in /secure/daemons/smtp_d.c
I can't transfer news now lah..


---
����: �һ�(fire)
��Ŀ: about the guo shi
����: Thu Jul 13 20:59:20 2000
the reason to have guo shi is to give the npc country a chance
to survive if it got a very good guoshi. hoho :)
But seems this feature is misused. I will modify the system to make
it more fair. thank your suggestion, suicide. :)


---
����: Fire
��Ŀ: >>post all lost?
����: Thu Jul 13 20:56:49 2000
On Tue Jul 11 20:03:51 2000 Suicide wrote post #1558:
> Maybe still caused by the new_d .
> Fire change it back bah.It always lost new post when posts up to 200.
I will check the new_d, but I think the reason of lost news may be
caused by other reason.
because I have chnage the new_d a long time ago. and it doesn't
cause much trouble
the trouble only happened when other system error happened. so
anyway, I will double check my code :)


---
����: Stefan
��Ŀ: >���쵱����ʱ�ĳ�����Ϣ
����: Thu Jul 13 20:29:45 2000
On Tue Jul 11 20:05:50 2000 �Ƶ�(emperor) wrote post #1560:
> ��������post����"."�����༭ʱ��˵û��Ȩ��appand����
> ��/data/daemons/news.o�ļ��ͬʱ�������Ҳ������
> Ƶ��������ͬ����Ϣ������������Ƶ�/data/Ŀ¼�µı���
> �����ִ���Ȼ���������û�κ���Ϣ���͹����ˡ�����
> ������վ��ֻ�����ӣ����ܳ���WELCOME��Ϣ���Ժ�һֱ
> ���������ǲ���/data/Ŀ¼�ڰ�ȫϵͳ�е�Ȩ�����������⣿

The crash is due to a disk lost. I saw the message last
time , and when it appeared, the second disk of the machine
is lost. This error is not specifically related to news or 
our mud.

We are going to shift to another machine, and hope it
will solve the problem.


---
����: ����ү(suicide)
��Ŀ: TO emperor
����: Tue Jul 11 21:00:09 2000
Emperor:
   Sorry!!!!!!!When i disconnect to phone i lost ur phone number which pasted 
in the notebook without save by mistakes. So i can't phone u that time.
When i connect here again try to find u ,but i failed.Sorry!!!!!!!!!!!!!!
                       suicide


---
����: ����ү(suicide)
��Ŀ: To fire:
����: Tue Jul 11 20:12:30 2000
Fire :
  R u very busy these days?if u r free can u change the ��ʦ�ƶ� to ̫���ƶ�,
When restart all player ��̫�ض���������ʦ,�����ǲ��Ǻ�һ��,�ܹ�����
��ʦ�ƶȵı׶�?
�뷨:
  1)������Ҷ��Ӻ󵱱����ְ��������������ط���Ա.
 2)�������ع��ﵽһ��ʱ,�������������̫��.
 3)�ٵ�һ��ʱ�ɶ���.
 4)������Ҿ�����7,8����Ҳ����̫����,���Ҳ��ܱ�֤ÿ��������.

�Ҳ�֪������ǲ���æ�Ÿ��¼ƻ�,������ϣ���������mud��������������,
�����ʦ�ƶȰ�.


---
����: �Ƶ�(emperor)
��Ŀ: ���쵱����ʱ�ĳ�����Ϣ
����: Tue Jul 11 20:05:50 2000
��������post����"."�����༭ʱ��˵û��Ȩ��appand����
��/data/daemons/news.o�ļ��ͬʱ�������Ҳ������
Ƶ��������ͬ����Ϣ������������Ƶ�/data/Ŀ¼�µı���
�����ִ���Ȼ���������û�κ���Ϣ���͹����ˡ�����
������վ��ֻ�����ӣ����ܳ���WELCOME��Ϣ���Ժ�һֱ
���������ǲ���/data/Ŀ¼�ڰ�ȫϵͳ�е�Ȩ�����������⣿


---
����: �Ƶ�(emperor)
��Ŀ: ���쵱����ʱ�ĳ�����Ϣ
����: Tue Jul 11 20:04:19 2000



---
����: Suicide
��Ŀ: >post all lost?
����: Tue Jul 11 20:03:51 2000
Maybe still caused by the new_d .
Fire change it back bah.It always lost new post when posts up to 200.


---
����: ˹̹��(stefan)
��Ŀ: post all lost?
����: Tue Jul 11 19:45:56 2000
What has happend to the old posts? 


---
����: �һ�(fire)
��Ŀ: the server becomes more frigle
����: Tue Jul 11 14:57:50 2000
Today, when I get to office, I find our MUD is down.
Then I login the Unix server and start the MUD and quit.
then I try to connect the game, I find it is still down.
so I log in the UNix again and start the mud and try to
connect. It seems ok. 
However, after about 5 mins, when I think everything is stable
I quit the Unix. However, at the same time the game is down without
any warning message. 
is it very strange. Should I keep connected to the Unix server
all the day. I don't know if the Unix will kick me out if I idle
for a whole day :)


---
����: ˹̹��(stefan)
��Ŀ: re: emperor
����: Mon Jul 10 17:38:24 2000
ʵ���ϣ���Щ��Ϣ���ˮ������ģ����ڽ�����ȷ�������ֲ�����ʽ�� server matrix��
��������������ڽ�������Ϸ���������ǵ���һ����Ŀ�����Ҳ��ǽ���������Ŀ��
����֮���Ǻ� 263 �����ģ����������ļ��� MUD �������ǿ���ɱɱ
�� RPG �࣬û�д�ǰ;���������Լ�֮�侺���ͺܼ����ˡ��������ĺõ����ڿ���
ֻ���ձ���ʯ��ʱ���� Sony �� Ever Quest��ʯ�Ѿ��� 20 ̨������ͬʱ���ˣ�������
��
���������ص�ƿ�����⣬Ŀǰ�Ѿ���̨�������ת����û�е���½����

�����ϣ�������ϷȦ����ô����΢�Ӵ�һ�¾Ͷ���ʶ�� :)


---
����: ˹̹��(stefan)
��Ŀ: server problem
����: Mon Jul 10 17:31:24 2000
It seems that FreeBSD can not take heavy load on its Dual CPU
configuration. So it goes down very often :PP

Now one of the CPU is disabled, we will see how it works out.


---
����: �һ�(fire)
��Ŀ: hi stefan
����: Mon Jul 10 15:03:33 2000
some players complain this new server.
I am not sure what are the problems.
sigh.


---
����: �һ�(fire)
��Ŀ: hi emperor
����: Mon Jul 10 15:01:56 2000
where did you get all your news,
could you please post the URL of those news ?
thanks

fire


---
����: �Ƶ�(emperor)
��Ŀ: ���ǵ��ٶ����
����: Mon Jul 10 07:40:15 2000
           ����ͼ��MUD������֮����������ͱ�����ʼ

����������֮����Ϊ̨��֪��ȫ����3Dͼ��RPG����������Ϸ����ͬʱ����
������������̨���кܺõ���ϷȺ�壬Ϊ���ƹ���һ��������������Ϸ��
��������������ش�½�г���Ϊ�ᰮ������Ϸ������ṩ���������й�����
�Ļ���3D�����������Ʒ�����ڣ�����й���½�����û������Ϸ��������
�ȫ�濪ʼ��ǰ500�������߶��ɻ������ʼĵ���Ϸ���̡� 

����������ַ�� http://210.78.145.16/temp/ 




---
����: �Ƶ�(emperor)
��Ŀ: ��һ���ڴ�½���е�ͼ��MUD
����: Mon Jul 10 07:37:45 2000
            ����֮����King of Kings��¡�صǳ���2000.6.28)

����ҵ���һ��ȫ����ͼ��MUD---����֮����King of Kings��¡�صǳ��ˡ�
�������Ϸ�������׾���Ѷ(Lager)����̨����������������--�������
���Ƶ�ͼ��MUD��27���ڳ��Ƿ��������¡�ص��׷���ʽ�������Ϸ���й�
�����п���������ͳ����MUDת�ɶ�̬������ͼ��ʵ�����������һ��ȫ��
��3Dͼ��RPG����������Ϸ����ͬʱ�������������������ÿᰮ������Ϸ��
��һ�±����Ե���������֮��ǿ�����Ϸ���ܣ�����֧����Ŀ�Ӵ�������
����Ϸ������Ѥ�������3Dħ��Ч���������������һ�ͳRPG��Ϸ����
��������Ϸ��ͻ��������й�ŷ�޵�ħ��������ɴ˿��Կ��������Ϸ��
Ŀ�겻�����й��г�����Ŀ����������й�������������������� 

������Ϸ����ʵ����60����ʱ�����У���ҹ������������ɡ������Ľ�ɫ
���ţ���������������ð��ݽ�ɫ�����ͣ����Ա𡢷�װ�����͡����롭��
�������ǰ�������һ��һľ����ȫ�����й滮���������š�������ľ������
���硢�趨�����з������������������µȣ����������ҵ��˸����
��Ϸ�ж��صĳǰ�ϵͳ���������һ�������ཨ���������������롣������
�����ϵ�����ָ�����ʵ����������ϲŭ���ܣ��Ӵ���ԵĲ����Ǳ���
�ļ���������Ǹ��ӡ��������򸾡��ֵܡ����ѣ���ͬ��ʵ������˼ʻ�����
ÿһ��������ÿһ�����붼������У�����������ҵĶ����������ڵ�һ��
ȫ��������������King of Kings����֮����������Ϸ����ʷ�����ºۼ�����
�������ʵ���ḻ�Ļ����������������ÿһʱ�̵�δ���� 

������һ���ǲ��Ǻ����㼤�����ǻ������������֮�����������磡7����
��ƽװ�����19Ԫ�������ۼ۳�����������Ϸ�Ŀ��� 




---
����: �Ƶ�(emperor)
��Ŀ: ��Ϣ
����: Mon Jul 10 07:17:21 2000
           ��������˾�н�����ͼ��MUD��Ϸ�߻��� 

�������Խ�������˾����Ϣ����������˾����ȫ������ͼ��MUD��Ϸ
���ǳ���Ů���Ĳ߻����������ƻ���ϷΪһ������ʵ������Ϊ������ 
ͨ���������������гɳ�������������ȵ�������ʵ��ͼ��MUD 
��Ϸ�� 
һ����Ʒ�趨
��һ��������5000Ԫ ����������н�������˾��Ϸ��Ʒ����
�ڶ���������3000Ԫ ����������н�������˾��Ϸ��Ʒ����
������������1000Ԫ ����������н�������˾��Ϸ��Ʒ����

��������Ҫ��
1.������������ص㣬��˼��ӱ����ķḻ��
2.�߻�������������˼����ȷ����Ϸ�Ժá�
3.ͻ����Ϸ����ּ������˼��ͻ����Ҫ�л������ϵ����塣


        ���ǳ���Ů���߻��������Բ������ 


������������˾��7�³�����վ�Ϸ�����������ͼ��MUD���ǳ���Ů��
�߻�������Ϣ�������ڹ��ý����������ڶ����ѵ�֧���£�����
�˺ܴ����ᷴ�졣��ֹ��10��31�գ���������˾�Ѿ�½���յ���
��200ƪӦ���߻��壬���а���Ϊ�����ٵ����Ը۰�̨�Լ���������
�ĸ������������˾ר��Ϊ���������������ѡС�飬������
���ǳ���Ů���߻�������Ļظ��͸���ĳ���ɸѡ������ 

���������������ѡС��ĳ���ɸѡ����������˾����ѡ����20ƪ
�Ƚ������ͼ��MUD���ǳ���Ů���Ĳ߻��壬���������칫��������
ѡ��Ʒ��������ͬʱ��������˾������վ�Ļ�������Ŀ��ÿ�칫��
һƪ��ѡ��Ʒ��������������������ǵ���ѡ���������̳Ҳ��
��Ӧ����ר�ŵİ�鹩���������Щ��Ʒ�������۷��ԡ���������˾
��������20ƪ��ѡ��Ʒȫ������֮������վ�Ͽ���ר�ŵ�ͶƱ��ѡ
�����������������������Щ��Ʒ������ѡ�����վ�������3����Χ
��Ʒ�� 

������������˾�����������֪��ý���ר�Ҳ���˴���ѡ�����
����λ�Ĺ����ԡ������Խ��мල��ͬʱ��������˾Ҳ���Ӵ˴�
������ѡ���������������10��������ң�����������н�����
��˾��Ϸ��Ʒ�����͡�ϣ��������ӻԾ�μ����ǡ��ǳ���Ů���߻�
������ѡ�� 



---
����: �Ƶ�(emperor)
��Ŀ: ��������˾�ķ�����ģʽ��ֵ�òο���
����: Mon Jul 10 07:13:00 2000



---
����: �Ƶ�(emperor)
��Ŀ: ��һ��ͼ��MUD
����: Mon Jul 10 07:11:28 2000
        ͼ�ģ������׿�3Dͼ��MUD��Ϸ�����ڽ�����������̨

����2000��4�£����ڽ�������˾����ʽ������������֮�õĹ��ڿ�3Dͼ��
MUD��Ϸ�����ڽ���������Ϸ�Ĺ��½ű��ᴩ���й��Ĵ�ͳ����˼�룬���
�������а���һ���������ˣ�������һϵ�еĽ����� ������ν����������
ǻ��Ѫ���Ĵ���壬һ���������겻�ѵ�������һ�οɸ�����Ĺ��£� Ҫ
���ǡ� ��Ӣ���ᣬ���ᵯ��������������ء��˼����ģ����ǿ�ɽ���ɡ�
����������һ�е�һ�ж������Լ� ѡ������Щ���棬�����ڽ�������˵
��ʵ����ȫ���š������ɵ���Ϸ��ڣ����еľ��鶼������� �������
����MUD��Ϸ���������ڡ� 

�����ٶ������������������ĵ����⣬�������ڽ��������������µ�����
���������ǽ����е�ͼ�������ļ���װ�ڿͻ��ˣ��ڿͻ��ˣ�����ָ�����
������룬������������й��˴��䣬��Լ�ͻ�����ָ���ʱ�䡣����ʱ��
���÷������ģʽ�����ͻ���ת��Ϊ������������ɴ˼�����������������
�����������������������ͨѶ�ٶȡ������ڽ������������˷ֲ�����ʽ��
�����ϵͳ������������ ���Ͽ�����������������������������ƣ� ����
����ҵ����ݱ��������������ϣ��������ʱ����ͨ�������������䣬����
ͬʱ���������������ӣ����ͬʱ��¼���ɳ��������ˣ� 



---
����: �Ƶ�(emperor)
��Ŀ: ��һ��ͼ��MUD
����: Mon Jul 10 06:51:09 2000
        ͼ�ģ��̹ſ��������--���й�����MUD�� 


�������й�����MUD�������̹Ź�˾��ʱ���ؿ�����һ���ͨ��INTERNET
��������ǧ��ͬʱ���е�����ͼ��MUD��Ϸ�� 

������Ϸѡȡ���ǹŴ����й�Ϊ��������Ϸ�е����������������Ʒȫ
Ϊ3D�����������ƻֺ��Ͻ��ǣ�С�����ϵĲ�����Ʊ��޲�һһ������
ԭ������ò����������ṩһ����õ���Ϸ��������Ϸ�ṩ����ʮ�ֲ�ͬ
�����빦�ܵĽ�����磺�����̵ꡢ�ٸ������̡���Ժ����ݡ����ݵ�
�ȣ���ҿ���ͨ���ۺ�������Щ�̵꣬ʵ�ָ��ָ��ӵ��淨�����ķḻ
��Ϸ�����ݣ���ҽ������еõ�����µ���Ȥ�� 

��������Ϸ����ҿ��Դӽ�20��ְҵ����ѡһ���Լ�ϲ���ģ��������ö�
��սʿ��������С͵��������Ҳ�������Ľ�ʦ�����ˡ���������ؤ�ȣ���
һ����������Ҳ�У�����������һ�����޵ĺ��С����ְҵ���ṩ��40��
����ؼ��ܣ���Ȼ���ܵ������Ǻ����ְҵ�йصġ���Ϸ�еĸ��ֵ�����
������ǧ�֣����м������������Ҳ����֥�ɵ������и���������Ʒ����
������Ϸ�л᲻�ϵ����·��֡� 

������Ϸ�������Ҫ�Զ�����������������ҿɴ��¸���ְҵ����ý�Ǯ��
���ڷ�չ��ҵ���������񣬻������Һ��ڡ�Ȣ�����ӡ� 

��������Ϸ������һ���ص㣬������Ϸ���ṩ�Ľ�4�����ĵ�ͼ�� �����й�
��ʮ���У�һ�ٶ����ׯ�����졢ɽ����Ϊ����ṩ��һ���޴����Ϸ�ռ䡣
���µ�ȫ��ά�����Ͷ��󣬻�����������侳����Ϸ�л����� 400������
���͵����������ȥ��ɣ��������񶼿����ö������ϵķ�����ɣ���ȫ
����������ܣ��磺��ҩ��Ѱ��ҩ�������˼ɵ���ҿ�͵����ƭ��������
�뵱���ӵĿ����Ե·��ˣ���ҩ��Ȼ�ᵽ�֡� 



---
����: ����ү(suicide)
��Ŀ: about nationmeeting
����: Sun Aug  6 02:27:27 2000
����̫���ƺ͹�ʦ�Ʋ����,һ�����ܴ��ڶ��ɲ�����������,��������ڵĹ�
�һ��鲻������,
��ô��ʦ�ɻ���Ϊ���ҹ�Ա�Ӷ����ù��һ����nationtax��tran���׸���
�Եĵط�̫��
���Ƕ�����ô���������ڶ�û�뵽�����еķ���,ϣ����Ұ�������,���Ὠ��:
1) ����nationtax�����趨��ֻ�б���̫�ؿ�������,��ʦ����ҹ�Ա����Ȩ,
��Ҳ�ȽϷ���
   ʵ�����.
2) ����tran,��ֻ��ô��,��Ұ��æ��!!!!!!


---
����: ����ү(suicide)
��Ŀ: /sgdomain/modules/m_board.c�ĵ�һ���޸ģ�
����: Sat Aug  5 23:52:45 2000
1) Ϊ���̫���ƣ����ӱ��ǻ��ܡ����ܵ�post��ʽ��
2) @--��ʾ���ǻ��ܣ�ֻ�б�����ҿ����Ķ���
   @@-��ʾ���Ǿ��ܣ�ֻ�б��ǹ�Ա�����Ķ���
3) @(���ǻ���)��*(��������)�ķ��Ų�ͬʱ���ͣ�
   post�ĵ�һ���ַ�Ϊ@�����Ϊ���ǻ��ܣ������ֵ�*��Ϊ��post���ݣ�
   ��֮��Ȼ��
4) �������������δ����ǰ���Ŷ�ϵͳ���κ�Ӱ�죬�Ҳ��Գɹ����Ѿ����ţ�
   ���Ҽ����ԡ�codeҪ��Ч����Ҫupdate board���ڷ��䡣


---
����: ˹̹��(stefan)
��Ŀ: complains about jimou
����: Fri Jul 28 23:56:47 2000
�����ġ�����(magi)��stefan���Լ���ɣ�һ��2�˵Ĳ��ӱ�ɱ��2M��ʲô���ĳ�����д
�����ġ���
�����ġ�˹̹��(stefan)��������������?
�����ġ����۲ݶ�˹̹�����˵�ͷ��
�����ġ����۲�(cool)������ˮ��
�����ġ�����(magi)������
�����ġ�����(magi)��jbsj neihong
�����ġ�����(magi)������
�����ġ�����(magi)��jbsj�Ǽ�¼������
�����ġ����۲�(cool)������ԽС��ɱ����Խ��
�����ġ�����(magi)����������ǰ����ʮ���Ϻ�վ�ļ�¼
�����ġ�����(magi)��������ļ�¼���Ҵ���ģ��ҿ��Ա�֤
�����ġ�����(magi)������һ��࣬��ǧ��ǧ�Ķ����ڻ���


---
����: ˹̹��(stefan)
��Ŀ: to group (player's complain)
����: Fri Jul 28 23:34:38 2000
to group (player's complain)
�����ġ�����(magi)���ϴ���Ͷ��˵��ʦ�Ʋ�����
�����ġ�����(magi)��ɱ����̫��
�����ġ�����(magi)�����佫�Ƶ�fenfa����һ���Ƚ�
�����ġ�����(magi)���������ȥ����������Ķ���
�����ġ�����(magi)����ֱ�Ӱ�fenfa����һ��3
�����ġ�����(magi)��������4
�����ġ�����(magi)�����Ǹ����أ�
�����ġ�����(magi)���ǲ������������˵���㲻��˵������������ҾͶ����㲻����
������
�����ġ�����(foxer)��������Ķ�ʲô����֪ͨһ��
�����ġ�����(magi)����ı�ĳɹ���Ҳ���Ե���
�����ġ�����(foxer)��һ�仰��˵��Ϲ��
�����ġ�����(magi)����������Ҳû֤��
�����ġ�����(magi)������������Ҳû�취

hoho, so please take care of it :)


---
����: Suicide
��Ŀ: >about guoshi
����: Thu Jul 27 21:01:52 2000
�ð�.������ѡ�ٹ�ʦ�� code,���⽵skill��idea fire��ͬ��Ļ�,��Ҳ����취.
������restart_d������һ��������ʾ�������ĵڼ���,ͬʱ�ڽ�ɫ����������
Ҳ���Ӷ�Ӧ��.
������������,���һ��½,login.c���ж�ϵͳ������ֵ����ҵ��Ƿ�һ��,�����һ��
�ͽ�����ҵļ���,Ȼ����Ҷ�Ӧ�����Ĳ������óƺ� restart_d��һ�¼���.


---
����: �һ�(fire)
��Ŀ: about guoshi
����: Thu Jul 27 19:09:29 2000
û�й�ʦ�����������ݵĹ���ȫ��û���ã�ͬʱȺ�����ף�
����������ڲ�����λ��
����ƶ���һ��������룬�������Ŀǰ�������϶�����
��ǰ��ֵ��һ�ԡ�


---
����: Fire
��Ŀ: >how about lower players' lv
����: Thu Jul 27 19:02:41 2000
On Wed Jul 26 22:35:13 2000 ����(group) wrote post #1620:
> when re open, is that ok to lower the skills lv of the players. then
> we can say it is a begining.
> and i think this is a way to reduce the guoshi's problem

it has a little technique difficult.
because if a player don't on line, can't cut his
skills because it is stored in the body.


---
����: Emperor
��Ŀ: >>���ڹ��ҹ�Ա��
����: Thu Jul 27 04:21:24 2000
agree suicide,���ǲ�������Ƶ�Ϊ�á�


---
����: Suicide
��Ŀ: >���ڹ��ҹ�Ա��
����: Thu Jul 27 00:33:15 2000
����ϸ˼��������,����NPC������û�й�ʦ,��������̫��ֻҪͬ��Э��,Ҳ����
���Ҿͻ�˥����,�Ҿ���һ�������Ƿ��ǿ��,��һ����Ҫ�й�ʦ��.
��֪�������ĶԲ���.������ô˵,ʵ��̫,����һ�����Ҳ���ѡ����ʦ,ֻҪ����
̫��һ�������Ϳ����������ҹ�Ա����.������һ�����ҵ�̫�صĸ������˵
����Ҳ����һ��ս����,��ô��Ҫ��������ѡ����ʦ��?


---
����: ����(group)
��Ŀ: how about lower players' lv
����: Wed Jul 26 22:35:13 2000
when re open, is that ok to lower the skills lv of the players. then
we can say it is a begining.
and i think this is a way to reduce the guoshi's problem


---
����: �һ�(fire)
��Ŀ: ���ڽ���
����: Wed Jul 26 22:04:24 2000
�ʵ۵����벻��������Ϊ��ֻ��һ���������JOB����ȫ����
���������ʦ�����ǲ����ܵġ������Էḻ���ǵ�JOBϵͳͬʱ
Ҳ���һЩƽ�����⡣����ʵ���ʱ��Ļ������԰����JOB��
һ����
addoil emperor


---
����: �һ�(fire)
��Ŀ: ���ڹ��ҹ�Ա��
����: Wed Jul 26 21:47:19 2000
��Ϊ���ҹ�Ա�������ɵ��ڱ����ڸ������������뻹�ǵ�
���˹�ʦ���ɹ�ʦ�����⡣���һ��NPC��û�й�ʦ����
�͸�����������Ϊ����������Ȼ���һ�˥����Ҫ��ǿ��
��������ѡ����ʦ���������Ҳ��Ὠ��һ������ѭ����
�ڷܶȵ�����Ǻܲ���ġ����ں�NPC�����ܶȣ��������
��Ȼ�ܺã���ʵ��ʱҪ����ϸ����ơ�������600����NPC
500������ҽ�ɫ�����ÿһ֮�䶼������ϵ�Ļ���������
��300��000������ʵ���ϲ�̫��ʵ������Ҫ��ƹ�ϵ�ȣ�һ
��Ҫ������������������ǣ����������


---
����: �Ƶ�(emperor)
��Ŀ: �ڷܶȵĸ���
����: Tue Jul 25 22:16:41 2000
�������Ϻ�suicide�ڵ绰������������Сʱ���һ�����ͬ
suicide��˼·��
    suicide���ڷܶȵĸ������������й��ҵ���ҹ�Ա��
�ڷܶȳ�������̫�ء���ʦ��ѡ���⣬�����ڶ�����������
�͹�������Ŀ��죨������Գ����������Ϲ�Ա�͹��ҹ�Ա�ģ���
�������������Ź�ռ�ŵط���Ա�����ҹ�Ա�͵۹���Ա��λ�ö��Ȳ�
�������ֲ����ߵ�ȴ����ٺ»�ڻ��ƽ�Ĳ������󡣶������ڷܶ����
ָ�꣬������Ч�ط�ֹ��������ķ��������һ����Ҿ��ڸ�λ����ı��ְ
�Ļ��������ڷܶ���Ȼ�ή�������Ӷ�ͨ��npcai_d��������ְλ��Ҳ��
�������һ�������λ�Ļ��ᡣ
    ����suicide����������־�С����ܶȡ�������ͨ�������NPC֮��
���ܶȵĹ�ϵ��ʹ�Լ��õ��󲿷ֹ�Ա��ӵ������Ϊ̫�ػ��ʦ�������ܶ�
������ͨ����һЩ�������ܶȵ�JOB��ʵ�֡�����д�š��ݷõȣ���Щ��������
�����ﶼ���ֳɵģ���΢�޸�һ�¾����������ܶ����ӵ���Ҫ��


---
����: �һ�(fire)
��Ŀ: stranges in post
����: Mon Aug  7 16:03:46 2000
I find some strange bugs in post yesterday.
When I login i find i have 1 post not read in the wiz.com
but after I type news. it said no new post
I think it is this bug remove the news group of task.guosi

about npcai_d.c, I have a little suggestion.

I think itself should not have a call_out. It better
to use ai_d.c to trigger the npcai_d.c so our system
have a certer heart that is day_d and a single
thinking circle that is ai_d.c, 

I have copy the npcai_d.c to /daemons, so
suicide please change it trigger by ai_d.c
and I don't think that it need to be added in the preload
it can be started by ai_d as well. 

addoil suicide :0


---
����: ����(ice)
��Ŀ: �����趨������ĳͷ��Ľ���
����: Mon Aug  7 05:54:41 2000
������Ƶ��Ժ����������������ĺ��Ӧ���ǲ�ͬ�ģ��������£�

1����������������Ĺ�����
   ��������30%��
   ��Ǯ����30%
   ��ù���ϵ��Ϊ1��
   �����Ժ�չ��ս������ץ��²�Ժ󣬼�ֵ����Ͷ���ľ������ܻᱻ
     ץ��ͷ������ͷ������ܵ������ڻ��ڣ�Ͷ����û��ʲô�����ˣ�ֻ
     ��˵��Ϊ�˱�����������������½�����

2���Ƶۺ���������Ĺ�����
   ��������50%��
   ��Ǯ����50%
   ��ù���ϵ��Ϊ1��

3�����������õĹ�����
   ��������50%��
   ��Ǯ����50%��
   ��Ϊ�ù���ְ��Ա��
   ����ͨ���ұ����õ���ұ��������ﵽ20000���۹��������ﵽ50000����

4��������Ͷ���Ĺ�����
   ��������50%��
   ��ù���ϵ���룬����Ϊ�ù���ְ��Ա��
   ��Ǯ����50%��

5���Ƶۺ�Ͷ���Ĺ�����
   ��������80%��
   ��ù���ϵ���룬����Ϊ�ù���ְ��Ա��
   ��Ǯ����80%��

���ڷ��Ӻ�װ��������ΪӦ�ò��ý��а��ᣬ�����ƺ������װ��ᣬ��װ����
ץ��²�����Ժ���սʤ��������ЩӦ�ò���ϵ���������������⡣

�����������ԭ����zeda������ˣ�������ָ�����ˣ��ֲ��ܶ���������
������˫���Ľ���֮������ӻ�ȥ�ˣ������Ҿ��������ƺ���̫�������Ծ�
��������Ͻ��顣


---
����: ����(ice)
��Ŀ: �����趨����Ҫ�����ʽ�Ľ���
����: Mon Aug  7 05:18:07 2000
�����������ӿ��Գ�������һֱû�н����޸ģ������������á�Ͷ��֮��
�ĳͷ��ƺ�Ҳû��ʲô��ͬ��ͬʱ��������ʽҲ������ô���룬һ�統�꣬
������Ҫ������һ�Ѵ��ף�����֮��Ҫ������Щ���Լ���ϵ�ߵĲ�����
Ͷ��������Ȼ����ܿ�ʼ������������޸Ľ������ܼ��ٴ��ף�ֻ�ǿ���
���ر���ʹ�ô�����Э���������ٸ�������˵�������ڵ����������Һ�
row�ǱȽ���ģ�������ͬһ�����е��ι�Ա���������ڵĶ�����ʽ����
����֮��rowδ�ؾͿ���Э���ҽ��й�����ֻ���Һ��ʵĴ�����Ͷ���˹�
�����ܿ�ʼ��

��suicide�ѽ�����ʦϵͳ��Ч�ҹ��ܵ�ǰ���£������������޸ģ�

1��������Ҫ�󣺣�������������������
   a.�����ǵ�������̫�أ�
   b.��������Ϊ500*�����ȼ���
   c.����Ϊ10000*�����ȼ���
   d.������3�������ϵ�����ҹ�ԱЧ�ң�
   e.�õ�������Ϊһ��������
   f.�õ����������볬��150��
   g.�õ������ӱ���Ϊ1000*�����ȼ���
   h.�õ�������ѵ��ʿ�����볬��100��
   i.�õ�����Ǯ���볬��10000��
   ��û�м���Ҫ��

2����������ʽ��

��һ��������Ч�ҵĵ��ط���ְ��Ա�򵱵�̫��ask xxx about independent��
ĳ������ĳ̫�����С��˵����������´��ң����ϲ���ʹ˽Ҹͣ���������ɡ�

����ʵ��˲��ǵ��ع�Ա����̫�ػش��ⲻ�Ǹ���Ҫ���ĵ��°ɡ����򷵻ء�
����ʵ����ǵ�����ְ��Ա����ش𣺸�������ͼ�췴�𣿴������򲻿ɡ�
������ʵĲ���̫�ػ򵱵�����̫�أ���ش𣺱�ְ/С����Ȩ���ƣ����Գ���ѽ��
������ʵ�̫�ص������ײ��㣬��ش������д��⣬ֻ���´˵����Ĳ�����
������ʵ�̫���������㣬��ش������д��⣬��ϧ�������㣬���Է���ѽ��
������ʵ�̫��û���㹻�ĵ��ع�ԱЧ�ң���ش������д��⣬��ϧ���ֲ���ѽ��
������ʵ�̫������Ϊһ����������ش𣺴˵����Է�չ������֮����Ҫ���ᡣ
������ʵ�̫�ذ������㣬��ش𣺴˵����Ļ�ɢ���������Գ��¡�
������ʵ�̫�ؾ��Ӳ��㣬��ش������µľ��Ӷ����������Զ�Ȩѽ��
������ʵ�̫��ѵ��ʿ�����㣬��ش𣺴�ʱ���Ĳ��ȣ��ٱ����ڣ��������Գ��¡�
������ʵ�̫�ص�����Ǯ���㣬��ش�û���㹻�Ľ�Ǯ�����»����²��㡣
������ʵ�̫�����Ѷ�������ң���ش���׳�ѽ�������Ѿ���������ˣ�
�����ġ�����

������ʵ�̫������������������̫�ػ�Խ�����ʹ��emote "ok" �����ش�
ĳ̫���İ����𣬳���˵�����ã���ʱ������������ʱ��
�������������е�gossip�����Ϣ��

3�������Ժ�ı仯��

a.�����Ĺ��������ӱ���
b.����Ч�ҵĵ��ع�Ա��Ϊ������ְ��
c.����Ч�ҵĵ��ع�Ա�ҳϼӱ�����ϵͳ������������¹��ҵĹ�ϵ�ȵĻ����ϣ�
d.����Ч�ҵĵ��ع�Ա��������20%��
e.���ؾ���ʿ������50��
f.����NPC��Ա�ص�ԭ���������������ְ��
g.���صĽ�Ǯ����10000��������ʱ�����õģ�
h.�ù�������Ч�ҵĹ�Ա��ԭ���ҵĹ�ϵ��Ϊ1��



---
����: ����ү(suicide)
��Ŀ: about nationmeeting
����: Mon Aug  7 03:09:33 2000
/daemons/nation_channel_d/nationtax.c�ĵ�һ���޸�:
1) ֻ�б���̫�ز��������������˰��
/daemons/nation_channel_d/tran.c�ĵ�һ���޸�:
1) �����������������е�һ������������ſ����ۣ�
   a)�����˺ͱ���������̫��Ϊͬһ�ˡ�
   b)����������̫��Ч�ҽ����ˡ�
   c)����������̫�غͽ�����Ч��ͬһ�ˡ�


---
����: ����ү(suicide)
��Ŀ: To fire
����: Mon Aug  7 02:14:39 2000
fire :
   ��������magi�Ѿ�ͳһ��,�ҿɲ�����install���еĳ�������ϵͳ������,
������ǰ��ʱ���ڹ���Ҳ������?�뾡����Ҵ�.
                                 suicide


---
����: ����ү(suicide)
��Ŀ: ������޸�
����: Mon Aug  7 02:12:35 2000
/daemons/char_d.c�ĵ�һ���޸�:
1) �޸�get_char�ĺ���������ɫû��Ч����Ϣʱ���ز���0�����ǽ�ɫ�Լ���id��
   Ŀ����Ϊ�˷�ֹ���ֵ�������ɫ��û������Ч����Ϣʱ������Ƚ����ߵ�Ч��
   ��Ϣ����Ϊget_char�ķ���ֵ����0�� �����������һ�µ������
/sgdomain/cmd/fealty.c�ĵڶ����޸ģ�
1) cmd fealty ���ڲ쿴�Լ�Ч�����
   cmd fealty none���ڳ���Ч��
   cmd fealty <id>��������Ч�ң�Ч�ҵĶ�������Ǳ����Ĺ�ʦ���������ֹ���
   ��ʱ����Ч�ҷ�����̫�����ﵽ�����Է����ʾ��ӵ�Ŀ��


---
����: ����(ice)
��Ŀ: about history
����: Mon Aug  7 02:07:42 2000
stefan found out that the new id login makes the system lag may
be caused by the too long history for a new player, I think it's not
so necessary to set all history while a player login, bcoz if he
didn't login for a period of time, there may be a long history flooding
the screen thus he might omit some important msg in the beginning like
"u have been failed to login x times" or "u have got mail" sth.

I suggest to make the normal history to another board.:P
(sg is coming to have more and more boards), the only thing left is
then progress board has news, remind a player to go read progress board.
so that player can concentrate on important msgs after login, and if he
is interested to see the history, check the board out.
it'll also ignore the cause of new id login make system lag.:)


---
����: ����ү(suicide)
��Ŀ: about progress
����: Sun Aug  6 20:15:42 2000
�������nationmeeting�Ĳ���Ӧ�þͿ���������,
����fire���/wiz/suicide/npcai_d.cת����/daemons���Ҽ��뵽preload��(
׼������ǰ)
�ҽ������������nationmeeting��code.


---
����: ����ү(suicide)
��Ŀ: ����/daemons/restart_d.c���޸�
����: Sun Aug  6 20:10:40 2000
���ӳ�ʼ������ʱ,ϵͳ�Զ���ѡNPC����̫��


---
����: ����(ice)
��Ŀ: national meeting
����: Sun Aug  6 19:42:14 2000
well, task.guoshi is gone, i have to post here.:P
suicide asked me about the comment of national meeting after
the new guoshi system is done.  I think to enhance the leader
's power who didn't cmd fealty to the guoshi, we can make national
meeting that if transferring sth from the area which is not fealty
to the guoshi, the leader will have 3 votes in natinoal meeting,
or can make a 1 vote objection of the leader, if he dun agree,
nothing can be transferred from his area.  but so there need to make
sth in pos.c, to let the taishou make his vote always positive to the
nation's decision or negative. that's my idea.

btw, players r eagerly willing to have a restart these days, will suicide
announce ur progress so that admin can all a restart.:)
addoil


---
����: ����(ice)
��Ŀ: call log
����: Sun Aug  6 18:33:12 2000
with fire's expectation, i added 2 wxxy lv for jianran for his bug report.


---
����: ����ү(suicide)
��Ŀ: /daemons/ai_d.c�ĵ�һ���޸�
����: Sun Aug  6 18:02:55 2000
1) ע�͵�ԭ����ϵͳ�Զ���ѡ��ʦ��code.�����ٵ���/ev_npccountry.c


---
����: ����ү(suicide)
��Ŀ: TO fire 
����: Sun Aug  6 18:01:41 2000
Fire :
   It is so strange that the newsgroup of task.guoshi is disappear,why?
Is it a bug?


---
����: ����ү(suicide)
��Ŀ: To ice
����: Mon Aug  7 18:00:35 2000
Ur post about ind , i will do it as quickly as i can.
Thx for ur post.


---
����: Suicide
��Ŀ: >stranges in post
����: Mon Aug  7 17:48:29 2000
Why i add call_out in npcai_d directly is because I am afraid of
error of "evaluation too long" caused by call Ƕ�׵� function in
diffrent files.


---
����: �һ�(fire)
��Ŀ: to suicide
����: Mon Aug  7 16:05:14 2000
when will you finish your nation meeting ?
How about we restart at this weekend ?


---
����: Ice
��Ŀ: >>>RE : ice's post about ���������  
����: Thu Aug 10 03:30:46 2000
well, that's fine, i m not asking to do it now, but just starting
to ignore some option of lv 1 area, so that later we dun have to adjust
many codes if we make up our mind to change lv 1 area to just-war area.


---
����: ����ү(suicide)
��Ŀ: To stefan
����: Thu Aug 10 01:44:14 2000
stefan :
    fhxy�ᵽ������shutdown����һЩbug ���֣���������վrebootʱҲ�����ˣ���ʱ��
�޷�pos ��ask postion ��������������վupdate�⼸����Ӧ���ļ�pos.c ��ev_postion
�����޷�update�ɹ������������ļ�corrupt �ˣ��Һ�������reboot���³���ü��ζ�
û�гɹ�������Ǵ�zj mirror ftp ���⼸���ļ����У����ܰ��Ҽ��һ����ʲôԭ��
������Ǵ�������������Ҳ������ÿ��reboot���¶��޷��ָ��������������ҷ�������
��code ��.c �ļ��ż��ܣ�����������վ��.c�ļ��ı����ļ�������վ�����ֱ�ӿ���Դ
�룬�ǲ��������ǵļ����趨�о�����������ģ���ֹ�����ļ��ڷ�վ���ܺ��޷�ʹ�ã�
    ����رռ�ı���������޳�ice ������������������ֹͣ����Ȼ���������ˣ���
����������Բ߰ɡ�


---
����: ����ү(suicide)
��Ŀ: Who can adjust war map
����: Wed Aug  9 22:27:18 2000
1  ÿ���ؿڶ�������,�����ѹ�,�����ؿڵ�����������ڵ�����.
2 ���ǹؿڵĵ���Ӧ�þ���û������,����ǽ��һ��,��һ����.


---
����: ����ү(suicide)
��Ŀ: To fire
����: Wed Aug  9 21:18:44 2000
Fire :
   ��������һ��ͬѧ���������ǵ���ʦС��,�μӳ��򿪷�,�㿴������?
�������,�ҾͿ�ʼ��ϵ,�������ԼӴ����ǵĿ�������.
  ���ҿ�������,��������Щ����й��,�㿴��?


---
����: Suicide
��Ŀ: >>RE : ice's post about ���������  
����: Wed Aug  9 21:16:30 2000
Ice :
  ����lvl 1����������,����ʱ���õ�ԭ������Ϊ�������Ҫ�漰��code�ܶ�ܸ���,
��ʵ���Ǻ�ͬ������뷨.
  �����һ��ڿ����ڹؿ���̫�ص������ô�����ʳ��������,�Ѱ�.
 �������������ʱ���úò���?


---
����: Suicide
��Ŀ: >about vote xxx close/open
����: Wed Aug  9 20:54:50 2000
����������,�Ұ�ϵͳ�趨��һ��IPֻ�ܵ�½4����ɫ.
(�����������ɻ����ͬʱ���ߵ����Ӧ�ò�����4����


---
����: ����(ice)
��Ŀ: about vote xxx close/open
����: Wed Aug  9 16:43:17 2000
can we add a same IP limitation of vote, if sb choose to vote sth,
check if this ip has voted about the same thing or not, if this IP
has voted, then any other id from the same IP cannot vote for the
same thing any more.  I dun like to watching those guys playing jokes
in this way anyway.  how do u guys think about it?


---
����: Ice
��Ŀ: >RE : ice's post about ���������  
����: Wed Aug  9 14:43:45 2000
1��������Ҫ�󣺣�������������������
   a.�����ǵ�������̫�أ�                
     ͬ�⣬������������ݴ�̫��Ҳ���Զ����Ļ����ǲ��Ǹ���Ȥ����˵������
     ��̫�����˲���������á�
well, i dun have objection of that.:P up to u.

   e.�õ�������Ϊһ��������
     ��ʱ��ͬ�⣬��Ϊ��������̫�ز��ܶ����������ֲ�Ը������ʦ��������
     �޳�ͷ֮�գ������Ǹ�����Ƹ���·ǰ������Ҳ���Զ����ɣ�ֻ����������
     ����ʧ�����Ͳ����������ˡ�
no, in my mind, the lv 1 area is not a city at all. lv 1 area should NOT
have population, bcoz it's only somewhere for war/defence only, holding
it is to protect the major cities beside or, some important geographic
location. that's y i also suggest to remove lv 1 area from the fate table.
lv 1 area is mostly working for war, not for manage. lv 1 area should not
have production, it should be just a dead area, must need somewhere else
like big cities beside to support it's troops there. so i still insist it
should not be included in the ind-able list.:P
     
   i.�õ�����Ǯ���볬��10000��
     ͬ�⣬���ǲ���Ҳ�ĳ�3000*�����ȼ�����?
that's fine, money is not a big deal, up to u.
     
3�������Ժ�ı仯��
   a.�����Ĺ��������ӱ���
     ͬ�⣬���Ǳ�������ǲ���Ӧ���������ٽ�60%����Ȼ��������������������
     ��Ȼ�ȶ���ǰ�ߡ�
so change to after ind, add 50%, if ruined, decrease 50%, it must be lower.:P
     
   c.����Ч�ҵĵ��ع�Ա�ҳϼӱ�����ϵͳ������������¹��ҵĹ�ϵ�ȵĻ����ϣ�
     ͬ�⣬������ϵͳ������������¹��ҵĹ�ϵ�ȵĻ���������漰�Ķ���̫�࣬
     ��֪�Ƿ���Ըĳ�60+random(40)?
no objection.
     
   f.����NPC��Ա�ص�ԭ���������������ְ��
     ͬ�⣬���Ǻõø��¹����������ɣ��ǲ��ǿ��Ժ�����һ�������ҹ�Ա��ȥ��
     ������random(2)�������������ˡ�
i have no idea about the current mode, just think that there may be some
technique difficulties for making it random stay in the new nation. but if
u think it's possible, just make it by ur mind.
   
   g.���صĽ�Ǯ����10000��������ʱ�����õģ�
     ͬ�⣬��3000*��������
no objection.
     
������Ƶ��Ժ����������������ĺ��Ӧ���ǲ�ͬ�ģ��������£�
(�������������Ͷ�����𣬶��е��Ϸ������Ϊ������Ĺ���Ӧ�ô��ϴ���������
 �������̫��)
 
1����������������Ĺ�����
   ��������30%��       ����ΪӦ��>50%,������70%
   ��Ǯ����30%         ����ΪӦ��>50%,������70%
   ��ù���ϵ��Ϊ1��
   
2���Ƶۺ���������Ĺ�����
   ��������50%��       ����ΪӦ��>50%,����Ϊ�ܳɵ�˵�������ܶ࣬���Ա���50%
   ��Ǯ����50%         �ָ�������ǰ����֪���ɵۻ᲻�������ӱ�����ȻӦ�ö࿳��
   ��ù���ϵ��Ϊ1��

3�����������õĹ�����
   ��������50%��       ͬ��
   ��Ǯ����50%��       ͬ��
   ��Ϊ�ù���ְ��Ա��
   ����ͨ���ұ����õ���ұ��������ﵽ20000���۹��������ﵽ50000����

4��������Ͷ���Ĺ�����
   ��������50%��       ����ΪӦ��>50%,������70%
   ��Ǯ����50%��       ����ΪӦ��>50%,������70%

5���Ƶۺ�Ͷ���Ĺ�����
   ��������80%��       ͬ��
   ��Ǯ����80%��       ͬ��

about the penalties, it's up to u.:) that's it.


---
����: ����ү(suicide)
��Ŀ: apply for a test.
����: Wed Aug  9 01:48:53 2000
So busy these days, and my brain is always in a confusion condition.
So i will have a rest and finished the �����ͷ�.


---
����: Stefan
��Ŀ: >Still about heart beat
����: Tue Aug  8 21:23:27 2000
On Tue Aug  8 20:00:51 2000 ����ү(suicide) wrote post #1666:
> ��Ȼheart_beatÿ tick������һ��,����Ϊ������mudosֱ�ӵ�����������Ϊ
> ʹ����������ʹ�õ�age_beatҪ��,��Ϊʵ���Ϲ����call out��ϵͳ���ȶ�
> ϵͳ���ܵ���ĸ���,��֪stefan,fire�������?��ES2 mudlib�����µ�
> mud����ֱ���õ�hear_beat,kk��ϵͳͬʱ�м����˶�û������.
call_out is also invoked by mudos directly, it is not an issue.
I believe heart_beat is disabled for good reasons, mostly because
wizs tend to produce 'lazy' code when heart_beat is around :)

KK is a different thing, nobody looked at their code, not sure
if any hack was there to make MUDOS stable.

To support a few hundred people is not a problem for lima
either, just that time_consuming things should be carefully
avoided, or arranged to happen pbit by bit.


---
����: ����ү(suicide)
��Ŀ: Still about heart beat
����: Tue Aug  8 20:00:51 2000
��Ȼheart_beatÿ tick������һ��,����Ϊ������mudosֱ�ӵ�����������Ϊ
ʹ����������ʹ�õ�age_beatҪ��,��Ϊʵ���Ϲ����call out��ϵͳ���ȶ�
ϵͳ���ܵ���ĸ���,��֪stefan,fire�������?��ES2 mudlib�����µ�
mud����ֱ���õ�hear_beat,kk��ϵͳͬʱ�м����˶�û������.


---
����: ����ү(suicide)
��Ŀ: npcai_d's callout has been modified
����: Tue Aug  8 19:55:53 2000
I have used ai_d to call npcai_d->act() at hour 3 per day 


---
����: �һ�(fire)
��Ŀ: modification in history_d
����: Tue Aug  8 16:55:02 2000
I move all the histroy data older than 4 weeks
into another mapping oldhistory, so when a player
come in he will auto read the history no more than
4 weeks. This will solve the problem of lag
when a new player register. But for the old
his data, we haven't have an interface to read them.
Anyway, they are kept. when we find a good solution
to display them, it is on the way.
addoil :)



---
����: �һ�(fire)
��Ŀ: ��Ŀ:  RE : ice's post about ���������  
����: Tue Aug  8 16:24:08 2000
The design is not bad. The problem in old system
is all of these are seperated in many files
so quite hard to balance. So if we apply the
new system. put them all in one file and disable
some of the old code. If we need adjustment, we know
where to find it out.


---
����: �һ�(fire)
��Ŀ: about call_out
����: Tue Aug  8 16:22:04 2000

call_out will not be handle separately by the system.
so will not cause too long parse problem even called from
another program. ai_d has been carefully designed, should
not have this kind of problem.


---
����: ����(ice)
��Ŀ: system unusual lag
����: Tue Aug  8 14:49:40 2000
����ʱ��                ��ǧ����°��������ʱ��ʮ�߷�
I checked cpu usage, it's pretty low as 2.33%, and there is not unusual
msg appeared in system channel or bug, it's just lag for all players
as well. stefan pls check what's happened? or there is sb trying to attack
or hack sg again...

ps. to suicide, i'll give u a response of ind post later.


---
����: ����ү(suicide)
��Ŀ: RE : ice's post about ���������  
����: Tue Aug  8 07:15:47 2000
Ice :
    ������Ķ����������post����ϸ��˼����������һЩ�뷨����,fire�������ۣ�
1��������Ҫ�󣺣�������������������
   a.�����ǵ�������̫�أ�                
     ͬ�⣬������������ݴ�̫��Ҳ���Զ����Ļ����ǲ��Ǹ���Ȥ����˵������
     ��̫�����˲���������á�
     
   b.��������Ϊ500*�����ȼ���
     ͬ��
     
   c.����Ϊ10000*�����ȼ���
     ͬ��
     
   d.������3�������ϵ�����ҹ�ԱЧ�ң�
     ͬ��
     
   e.�õ�������Ϊһ��������
     ��ʱ��ͬ�⣬��Ϊ��������̫�ز��ܶ����������ֲ�Ը������ʦ��������
     �޳�ͷ֮�գ������Ǹ�����Ƹ���·ǰ������Ҳ���Զ����ɣ�ֻ����������
     ����ʧ�����Ͳ����������ˡ�
     
   f.�õ����������볬��150��
     ͬ��
     
   g.�õ������ӱ���Ϊ1000*�����ȼ���
     ͬ��
     
   h.�õ�������ѵ��ʿ�����볬��100��
     ͬ��
     
   i.�õ�����Ǯ���볬��10000��
     ͬ�⣬���ǲ���Ҳ�ĳ�3000*�����ȼ�����?
     
3�������Ժ�ı仯��
   a.�����Ĺ��������ӱ���
     ͬ�⣬���Ǳ�������ǲ���Ӧ���������ٽ�60%����Ȼ��������������������
     ��Ȼ�ȶ���ǰ�ߡ�
   
   b.����Ч�ҵĵ��ع�Ա��Ϊ������ְ��
     ͬ��
     
   c.����Ч�ҵĵ��ع�Ա�ҳϼӱ�����ϵͳ������������¹��ҵĹ�ϵ�ȵĻ����ϣ�
     ͬ�⣬������ϵͳ������������¹��ҵĹ�ϵ�ȵĻ���������漰�Ķ���̫�࣬
     ��֪�Ƿ���Ըĳ�60+random(40)?
     ͬ��
     
   d.����Ч�ҵĵ��ع�Ա��������20%��
     ͬ��
     
   e.���ؾ���ʿ������50��
     ͬ��
     
   f.����NPC��Ա�ص�ԭ���������������ְ��
     ͬ�⣬���Ǻõø��¹����������ɣ��ǲ��ǿ��Ժ�����һ�������ҹ�Ա��ȥ��
     ������random(2)�������������ˡ�
   
   g.���صĽ�Ǯ����10000��������ʱ�����õģ�
     ͬ�⣬��3000*��������
     
   h.�ù�������Ч�ҵĹ�Ա��ԭ���ҵĹ�ϵ��Ϊ1��
     ͬ��
     
������Ƶ��Ժ����������������ĺ��Ӧ���ǲ�ͬ�ģ��������£�
(�������������Ͷ�����𣬶��е��Ϸ������Ϊ������Ĺ���Ӧ�ô��ϴ���������
 �������̫��)
 
1����������������Ĺ�����
   ��������30%��       ����ΪӦ��>50%,������70%
   ��Ǯ����30%         ����ΪӦ��>50%,������70%
   ��ù���ϵ��Ϊ1��
   
2���Ƶۺ���������Ĺ�����
   ��������50%��       ����ΪӦ��>50%,����Ϊ�ܳɵ�˵�������ܶ࣬���Ա���50%
   ��Ǯ����50%         �ָ�������ǰ����֪���ɵۻ᲻�������ӱ�����ȻӦ�ö࿳��
   ��ù���ϵ��Ϊ1��
3�����������õĹ�����
   ��������50%��       ͬ��
   ��Ǯ����50%��       ͬ��
   ��Ϊ�ù���ְ��Ա��
   ����ͨ���ұ����õ���ұ��������ﵽ20000���۹��������ﵽ50000����
4��������Ͷ���Ĺ�����
   ��������50%��       ����ΪӦ��>50%,������70%
   ��Ǯ����50%��       ����ΪӦ��>50%,������70%
5���Ƶۺ�Ͷ���Ĺ�����
   ��������80%��       ͬ��
   ��Ǯ����80%��       ͬ��
���ڷ��Ӻ�װ��������ΪӦ�ò��ý��а��ᣬ�����ƺ������װ��ᣬ��װ����
ץ��²�����Ժ���սʤ��������ЩӦ�ò���ϵ���������������⡣
ͬ��.
Fire and ice ,consider about my opinion bah, if u all agree i will do this.
   


---
����: Suicide
��Ŀ: >>>a little bug
����: Tue Aug  8 07:15:09 2000
Have fixed lah but set loyalty to 80 when auto select taishou by system


---
����: Ice
��Ŀ: >>a little bug
����: Tue Aug  8 06:37:33 2000
hmm, i think if he is leader, he cannot cmd leave any time, so maybe
need a restriction to let system know when a NPC leader's loyalty
is lower than some certain level, NPC king will get another new taishou
and also if there is guoshi and player king, he'll receive a msg that
leader is having low loyalty. however, I think leader should be forced
not able to cmd leave, i remember the cmd leave for player has limited
this way, dunno if it's changed or not.


---
����: Ice
��Ŀ: >>about ranks
����: Tue Aug  8 06:33:31 2000
must be officer in order to be listed in rank? hmm, in my mind,
the target of playing this game is not only being a good officer
or a king, being xianren can still have many things or objective to 
achieve.:P so maybe change it to not necessary to be officer?


---
����: Suicide
��Ŀ: >a little bug
����: Tue Aug  8 06:11:58 2000
It is caused by the NPC taishou's low loyalty,So i modified /daemons/area_d.c
/head.c . When system auto head to select NPC atishou  ,the NPC
taishou's loyalty
will inc to 80.
Then Npc taishou who is auto selected will not be cmd leave frequently.


---
����: ����ү(suicide)
��Ŀ: To fire
����: Tue Aug  8 06:03:48 2000
How many ticks = 16min(1 day in mud) ah???
Is is 240?


---
����: Suicide
��Ŀ: >about ranks
����: Tue Aug  8 05:57:14 2000
rob was not an officer when the rank was generated.
This is the result that he wasn't in rank.
hoho


---
����: ����(ice)
��Ŀ: about ranks
����: Tue Aug  8 03:48:52 2000
i read the most recent ranks, but surprised to find that rob
was not in any rank list, though he is 88 yrs old, he's not in the
oldest players' list.:P and none of other lists included him.
suicide pls spare some find to find out why?
rob was not an officer when the rank was generated.


---
����: ����(ice)
��Ŀ: a little bug
����: Tue Aug  8 03:39:54 2000
NPC taishou of bailangshan cmd leave by himself.:P  i think it's
supposed not to happen, bcoz if a taishou cmd leave, and the system
doesn't come to that area to check, players in that area cannot do
any job.
btw, i added another NPC taishou for bailangshan.


---
����: ����ү(suicide)
��Ŀ: To fire
����: Tue Aug  8 01:33:12 2000
Fire:
   For flee and group all devote in project of GIME,can we hire some new wiz?
How about starrock's apply?


---
����: ����ү(suicide)
��Ŀ: about �ڷܶ�
����: Tue Aug  8 01:28:30 2000
����train,��һЩmeeting�Ĺ���������ev_job�е�job,����������ǰ�޸�ev_job.c
��reward����ǰ�����ڷܶ�,��ô��ͣtrain����Ҿ��޷����ڷܶ�,���������ڸĳ�
��/char_d/localcontribution.c�е�������ӵ�������,�ҵ������״��ڵ���3ʱ,��һ��
�ڷܶ�.����visitpeople���job����reward�������е㲻��,�������ҵ�guy,ʲô��
��ѡ,ֻѡ10�˳�,��ȥ������ܵõ�6��ع�,��һ������һЩjobȫ�����ȴ
ֻ��3��ع�,
�����е㲻ƽ���,�ɲ����Ե�������?


---
����: Suicide
��Ŀ: >small bug...
����: Tue Aug  8 01:15:30 2000
I will adjuest when i am free.
Thx row.
:)


---
����: ����(row)
��Ŀ: small bug...
����: Mon Aug  7 22:52:56 2000
when i ask gongsun zan about position, gongsun zan answers:
����趶���˵�������ȿ��ǿ��ǡ�
  ����      ��ְ
����趶�������㿼���׵���������˾������� answer <����> to gongsun zan

i guess i dont meet the requirement of the next position, so the code and the
name of the position wont be shown. well, for such situation, a sentence
as: ������δ�ﵽ��һ��ְҪ�������Ŭ���� will not cause confusion.
am i right?


---
����: Ice
��Ŀ: >stranges in post
����: Mon Aug  7 22:19:51 2000
i met that bug often, is it fixed?


---
����: ����ү(suicide)
��Ŀ: To fire
����: Mon Aug  7 18:02:05 2000
I have install all code into system,u can check and debug lah...
I haven't modify the call_out of npcai_d.c for those error maybe caused.
But if u confirm that will not happen i will modified it.


---
����: Ice
��Ŀ: >>about vote xxx close/open
����: Thu Aug 10 03:33:32 2000
hmm, b4 I didn't agree to this idea much... but, now i think it's
fine to deal in this way.  since i dun want to see sb login 12 ids
to run robot while there r 20 players online including me.:P


---
����: �һ�(fire)
��Ŀ: limitation of login number from 1 ip
����: Thu Aug 10 22:13:26 2000
the way to avoid multi login by ip is not a
realiable way. so should avoid this kind of limitation
until it is ergent


---
����: ����ү(suicide)
��Ŀ: guoshi info 
����: Thu Aug 10 21:14:20 2000
I have fixed guoshi info when he cmd leave or inf.
or ind.pls check bah...


---
����: Suicide
��Ŀ: >how about restart tomorrow
����: Thu Aug 10 19:34:47 2000
Ok,restart tomorrow.
I will try my best to be online tomorrow,and when u will restart?


---
����: Suicide
��Ŀ: >re suicide
����: Thu Aug 10 19:34:01 2000
1  limit only 4 char can login from 1 IP is to void run too many
robot by one people.
2 ABout new wiz i will contact with him.


---
����: �һ�(fire)
��Ŀ: how about restart tomorrow
����: Thu Aug 10 16:49:17 2000
suicide, is that ok ?


---
����: �һ�(fire)
��Ŀ: re suicide
����: Thu Aug 10 16:48:39 2000
>����������,�Ұ�ϵͳ�趨��һ��IPֻ�ܵ�½4����ɫ.
>(�����������ɻ����ͬʱ���ߵ����Ӧ�ò�����4����
I think this is a big issue. I think maybe
limit the vote right for each ip is better.

>   ��������һ��ͬѧ���������ǵ���ʦС��,�μӳ��򿪷�,�㿴������?
>�������,�ҾͿ�ʼ��ϵ,�������ԼӴ����ǵĿ�������.
That's good, so you can ask him to login and try to contact me
or other wiz members when we are online, so we can have a chance
to know each first :). If he can get 1 other wiz's recommandation,
then we can discuss his application.



---
����: Ice
��Ŀ: >>about guoshi's requirement
����: Thu Aug 10 14:21:31 2000
������趴�������<guoshi>����Ϣ��;����趶���ŭ������ô��Ҫ�Ĺ��Ҵ�
�£�ƾ�����ݻ��岻���죬������̫���������ɡ�
liyu is xianzhi, so cannot ask for guoshi? faint...


---
����: Ice
��Ŀ: >>about cmd fealty
����: Thu Aug 10 14:20:19 2000
no, just add it. u may not see it when u r online, unless u r 24 hrs
online.:P so just add it, or make it like the chat rules, cannot repeat
in 10 secs.


---
����: ����ү(suicide)
��Ŀ: To ice
����: Thu Aug 10 07:19:43 2000
If u want liyu to be guoshi u must let him to be taishou first
and ask gongsun zan about guoshi to open vote.


---
����: Suicide
��Ŀ: >about guoshi's requirement
����: Thu Aug 10 07:17:49 2000
Now is 4k now ,not 10k lah....
Have u use liyu to ask king about guoshi????


---
����: Suicide
��Ŀ: >about cmd fealty
����: Thu Aug 10 07:16:57 2000
Let's check it if it just appear i will add time limit.
:)


---
����: ����(ice)
��Ŀ: about cmd fealty
����: Thu Aug 10 05:27:49 2000
there should be a busy time or cannot cmd fealty in a certain time,
otherwise will make flood in rumor.


---
����: ����(ice)
��Ŀ: about guoshi's requirement
����: Thu Aug 10 05:05:53 2000
maybe the nc requirement is too high, it's hard for a player to work
till 10k nc to gain guoshi, maybe u should lower it to 2k or so will be
more suitable. btw, i called liyu's nc and rep, so that it might be possible
to make him the guoshi when system check xiangping, then let's see if there is
still some other bug, if there isn't obvious bug, let's restart
these 2 days bah.


---
����: Suicide
��Ŀ: >Help,
����: Fri Aug 11 00:41:24 2000
In our mud ,We can convert BIG5<-->GB code ah...
Can u check it ,ʵ����ֻ�Ǹ��ַ����ձ������


---
����: �һ�(fire)
��Ŀ: Help,
����: Thu Aug 10 23:47:40 2000

Anyone know how to thans big5 code to unicode and gb code?
Please Help.

Regards,




---
����: �һ�(fire)
��Ŀ: Welcome dreamfly.
����: Thu Aug 10 23:44:44 2000

We have a very strict process for promoting a new wizard.
But because both Stefan and I are pretty busy this moment,
and this new member is a close friend of suicide, I promote
him without asking his application and voting in our wiz
committee. However, I think we still need dreamfly to give
some introduction of himself and give a plan for what he
like to do and may contribute to this mud within two weeks.

Addoil :)


---
����: Row
��Ŀ: >welcome new wiz dreamfly
����: Thu Aug 10 22:29:48 2000
welcome


---
����: ����ү(suicide)
��Ŀ: welcome new wiz dreamfly
����: Thu Aug 10 22:22:22 2000
He is my best friend and classmate.
��Ҷ���չ�!


---
����: ����(ice)
��Ŀ: about my post 4650 in caolu
����: Sat Aug 12 19:12:06 2000
@CHAR_D->set_char("taishou id","grant",0)

this cmd will fix that. it's bcoz the current NPC leader r exactly
the same as b4 restart, and restart didn't remove the grant data.


---
����: Suicide
��Ŀ: >about lower the speed of unify
����: Sat Aug 12 18:41:24 2000
Is that "about fhxy's mail"?
I have transfered it to my email ,but i haven't read it for less time.
I will read and consider it tomorrow,then reply ur post,hoho
I will read and consider it tomorrow,then reply ur post,hoho


---
����: ����(ice)
��Ŀ: about lower the speed of unify
����: Sat Aug 12 18:11:02 2000
any one read my post in task.war? do some change or not? or
any comment? or just simply cannot find that post? if so, i'll
post it here. and pls fix the bug in task group first bah.:P


---
����: ����(ice)
��Ŀ: about restart
����: Sat Aug 12 18:10:04 2000
after restart, all bn in all area is not cleaned, so that the
blacklist in all cities remain the same as last generation.
better fix it now, hoho.


---
����: ����(group)
��Ŀ: chinese name
����: Fri Aug 11 12:07:50 2000
today there is a player login with a extremly long name
hmm... is there a limit for the length of chinese name?
if dont have, better add a limit ba


---
����: ����(ice)
��Ŀ: about task group
����: Fri Aug 11 07:45:39 2000
faint, i wrote a post on task.war, but seems no one have read
it, after i finish that post, i cannot found there is any news
as well, fire check the task group again? addoil


---
����: ����(ice)
��Ŀ: about multilog
����: Fri Aug 11 07:38:31 2000
since not many of us wanna limit the login of same IP, so sb make
vote for the same thing every IP has only 1 vote bah, it's not a big
issue leh bah.:P
addoil


---
����: ����(ice)
��Ŀ: help of new system
����: Fri Aug 11 06:37:23 2000
though there is a post in progress, I think we still need a help
to let others check when necessary, suicide make it bah


---
����: Ice
��Ŀ: >welcome dreamfly
����: Fri Aug 11 06:31:25 2000
welcome dreamfly, i think u need some time to know this game first,
i suggest u to read some of the players' help, to have a brief idea of
this game, then if u still have some questions, try ask me if i m online,
i'll show u what i know.:P


---
����: Ice
��Ŀ: >about ��ʦ����
����: Fri Aug 11 06:28:49 2000
1. this idea is interested.
2. can give the taishou a choice, like when he is login after that guoshi
beep
is ind, he will be informed to make a choice, then after the system check
the city, if the taishou didn't login for a long long time, thus he won't
choose y/n to follow guoshi's ind or not, make it nothing happen, he'll still
belong to the old king.
3. answers of 2.

another question, no one can ind in NPC's capital, that's for sure,
that's y i need u to make guoshi cannot transfer king to anyother area,
and also change capital is not possible unless there is a comparable status
of the old city and the new city. but for now, just make it not able to change
capital and trans king for guoshi, so that no one can ind in capital.


---
����: ����(group)
��Ŀ: welcome dreamfly
����: Fri Aug 11 03:59:29 2000
welcome ^^ 
welcome ^^ 

recently quite busy in reading code...*_^
if no special things happen, i should be able to finish the code for 
npc auto cast

regards
group


---
����: Stefan
��Ŀ: >Help,
����: Fri Aug 11 01:03:26 2000
On Thu Aug 10 23:47:40 2000 �һ�(fire) wrote post #1697:
> Anyone know how to thans big5 code to unicode and gb code?
> Please Help.
> 
> Regards,
> 
> 
ftp.cuhk.hk
in ifcss/software directory you can find quite a lot of
chinese software. A unix package called "utf7" actually
does translation between unicode, utf7, utf8 and gb, big5.


---
����: Stefan
��Ŀ: >limitation of login number from 1 ip
����: Fri Aug 11 01:01:40 2000
On Thu Aug 10 22:13:26 2000 �һ�(fire) wrote post #1693:
> the way to avoid multi login by ip is not a
> realiable way. so should avoid this kind of limitation
> until it is ergent

agree. from NUS all have same IP , and probably > 10 :P


---
����: ����ү(suicide)
��Ŀ: about ��ʦ����
����: Fri Aug 11 00:41:46 2000
��ʦ�����ļ��ַ�ʽ:
   1 һ����ʦ����,��ô����fealty����̫�صĵ���������ԭNPC����תΪ���ĵ���.
   2 ֻ�й�ʦ�Լ����յĵ�������,����̫�صĳǶ�������NPC����.
   3 ��ʼֻ�й�ʦ�Լ����յĵ�������,����fealty����̫�ؿ���ѡ������Ӧ����
     ����Ч��ԭ���Ĺ���?
   
   ����һ������,���ǹ������ڵ��Ǹ�����ô����,��Ϊ����������޷�����.
   
   �����������,ok?


---
����: ����(group)
��Ŀ: about auto cast
����: Mon Aug 14 01:30:19 2000
i just finished auto cast code, it seems working well on my 
computer, but not sure whether it is good enough or not.

in every 7 minutes, system will random choose a NPC troop,
can then random choose a jimou for cast.

mainly there are 3 types, base on wuli, base on zhimou, base on meili.

if wuli is chosen, fenfa will be checked first. if can fenfa, the troop
will fenfa, otherwise it will check whether can jiaoma, and last
it will choose one from qibing and sugong.

if zhimou is chosen, the system will check whether hunluan and
shidu can be used.

if meili is chosen, system will try jiedu and shoushi first. then will
be guwu and zhanbu.

other jimou like neihong, huangbao, luoshi, jbsj will be added in later
however, i need do a mess change for the jimous.

fire, please check check the ftp server, it is not working for me 
and flee....:~(

regards


---
����: Row
��Ŀ: >>about NPC leave
����: Mon Aug 14 00:40:30 2000
/sgdomain/event/ev_donate.c is responsible for npc's donate, which will
add loyalty and reputation randomly. the new npcai_d can call it.


---
����: Row
��Ŀ: >about NPC leave
����: Mon Aug 14 00:27:04 2000
On Mon Aug 14 00:11:04 2000 ����ү(suicide) wrote post #1727:
> I have done nothing with NPC leave.
> NPC just leave for its low loyalty,And many NPC now has low loyalty.
> I don't know why ? 
NPC's loyalty is decreased for assorted reasons, been lettered, been
whispered, been posed to a lower position (maybe), havent received salary...
its hard for NPC to maintain higher loyalty becoz there are so many dummies
doing so many jobs...hoho, anyway, i think we may add more job to add
NPC's loyalty, since we only have visitofficer have such function.


---
����: ����ү(suicide)
��Ŀ: about NPC leave
����: Mon Aug 14 00:11:04 2000
I have done nothing with NPC leave.
NPC just leave for its low loyalty,And many NPC now has low loyalty.
I don't know why ? 


---
����: Fire
��Ŀ: >>>>>about war
����: Sun Aug 13 20:36:40 2000
On Sun Aug 13 20:03:24 2000 Ice wrote post #1725:
> there is a time limit for defence arrange troops bah, i remember,
> if so, that's fine, otherwise it'll be a trick of the defender.:P
> and b4 defence party enter the warfield, the morale of attacker
> should not decrease anyway.

yes it is, if the defence leader idle then the system will
auto arrage the troop. so don't worry about that :)


---
����: Ice
��Ŀ: >>>>about war
����: Sun Aug 13 20:03:24 2000
there is a time limit for defence arrange troops bah, i remember,
if so, that's fine, otherwise it'll be a trick of the defender.:P
and b4 defence party enter the warfield, the morale of attacker
should not decrease anyway.


---
����: �һ�(fire)
��Ŀ: thank stefan and suicide
����: Sun Aug 13 19:59:52 2000
for your help and information.
regards,


---
����: Fire
��Ŀ: >>>about war
����: Sun Aug 13 19:52:52 2000
On Sun Aug 13 19:43:20 2000 Suicide wrote post #1722:
> I think if we can set a flag which used to judge if defense side had
> entered the warfield.
> When defense side haven't entered warfield it will suggest attack side
> "�������������ӱ���XXɱȥ...".

yes, now i use this method.
we can use TASK_D->get_task(id,"start_war") to check, if return
value is "yes", then the energy will auto recover. if not can't recover
energy so the attack side need to wait until the defence finish their
arrangement :)


---
����: Suicide
��Ŀ: >>about war
����: Sun Aug 13 19:43:20 2000
I think if we can set a flag which used to judge if defense side had
entered the warfield.
When defense side haven't entered warfield it will suggest attack side
"�������������ӱ���XXɱȥ...".


---
����: Stefan
��Ŀ: >the name
����: Sun Aug 13 14:17:57 2000
On Sun Aug 13 02:18:15 2000 ����(group) wrote post #1717:
> the name is iiiiiiii
This problem is now fixed.


---
����: ����(ice)
��Ŀ: about npc leave
����: Sun Aug 13 10:09:54 2000
players complain that npc will leave even he is in 100, and now
no one "tanqin", also they said they observed that when more npc r
not officer, the leaving rate is higher.


---
����: ����(ice)
��Ŀ: hmm
����: Sun Aug 13 10:00:06 2000
fix task group now bah, otherwise wiz.com will be full of all
posts.

and i have a suggestion about cmd honour, if sb cmd leave the nation,
or ind, or be fired, or system restart, the honour should be cleaned
to 0, i think. bcoz the honour is mostly related to the nation, if sb
lose the nation, honour will be meaningless.:P

ps. a thought in mind long ago, i think honour is just like pots in other
wuxia mud anyway.


---
����: Ice
��Ŀ: >about war
����: Sun Aug 13 08:04:57 2000
i agree group's opinion.
but also try change the defence part's delay as well, it's really
unfair to the defence party.


---
����: ����(group)
��Ŀ: the name
����: Sun Aug 13 02:18:15 2000
the name is iiiiiiii


---
����: Stefan
��Ŀ: >chinese name
����: Sun Aug 13 00:30:59 2000
On Fri Aug 11 12:07:50 2000 ����(group) wrote post #1708:
> today there is a player login with a extremly long name
> hmm... is there a limit for the length of chinese name?
> if dont have, better add a limit ba

I think we do have a limit, let me know who has got long name.


---
����: ����(group)
��Ŀ: about war
����: Sat Aug 12 23:25:33 2000
please change the war part.
if it is the npc country, only taishou can lead war.

i think the war record is a good verify for that.


---
����: ����ү(suicide)
��Ŀ: call log
����: Sat Aug 12 22:05:54 2000
For Jianran's bug report,I reward him of dec 5 year older.


---
����: Ice
��Ŀ: >to group
����: Thu Aug 17 21:12:09 2000
i support to increase the time between using 2 same jimou.:)


---
����: ����ү(suicide)
��Ŀ: to group
����: Thu Aug 17 21:06:05 2000
�Ƿ���ԼӴ�ʹ�����μƲ�֮��ļ��ʱ��,���������ʹ�õĴ���?
�������ʹ�ü�ı�Ĵ����ɸü�ı�Ķ�Ӧ�Ļ�������ֵȷ��?
25 һ�� 50 ���� 75 ...100...  ��������������Ļ�,���ڴ��̾��Ǳȼ�ı
������Ϳ���
���һ��,what do u think?


---
����: ����ү(suicide)
��Ŀ: about ����
����: Thu Aug 17 20:13:47 2000
A good idea ,we can use it to make ����
if a guy's ���� is different from npc who can teach special skill
,then that guy can't learn from it,or can lah...
I will think about it and make it as quick as i can.


---
����: Suicide
��Ŀ: >report type
����: Thu Aug 17 20:12:03 2000
On Thu Aug 17 09:00:44 2000 ����(ice) wrote post #1764:
> cmd report
> 
> �����ʽ��
> cmd report local      ̫��ר�õı����������
> cmd report nation     ���ҹ�Ա�Ĺ����������
> 
> ע�ͣ�
> ֻ����Ӧְλ����Ҳ���ʹ�ø�������ڹ��ҹ�Ա��ְ����δ��ϸ�ֹ���
> ��ʱ��ͳһ����ĸ�ʽ���С�
> 
> ��ز�����
> cmd report local/nation last <num_mon> �鿴��ȥ�����µı��漯�ϡ�
> ����ȱʡ��Ĭ��Ϊ�鿴�ϸ��µı��档<num_mon> ��Χ��1��12��
> 
> ������أ�
> ̫�ز鿴���ر��棬ÿ��ÿ�±��������ı��ػƽ�100����������鿴��ȥһ��
> �ı��������ı��ؽ�Ǯ1200��
> ���ҹ�Ա�����������鿴���ұ��棬ÿ��ÿ�������Ĺ���ƽ�200��������鿴
> ��ȥһ��ı��������Ĺ����Ǯ2400��
> 
> �����ʽ��
> cmd report local
> �������������ء����������������������������������������������
> ����    �ơ�<��������>    �� ������ ��<��������>
> ��������ʿ����<ʿ����Ŀ>
> �ӱ������͵���ص�ʿ����Ŀ��<ʿ����Ŀ>*
> ��������͵����ص�ʿ����Ŀ��<ʿ����Ŀ>*
> �������лƽ�<�ƽ���Ŀ>
> �ӱ������͵���صĻƽ���Ŀ��<�ƽ���Ŀ>*
> ��������͵����صĻƽ���Ŀ��<�ƽ���Ŀ>*
> �����������ݣ�<������Ŀ>
> �ӱ������͵���ص�������Ŀ��<������Ŀ>*
> ��������͵����ص�������Ŀ��<������Ŀ>*
> ��������ľ�ģ�<ľ����Ŀ>#
> �ӱ������͵���ص�ľ����Ŀ��<ľ����Ŀ>*
> ��������͵����ص�ľ����Ŀ��<ľ����Ŀ>*
> ���������ʱ���ͬľ�ģ�
> ��������ũ����<ũ����Ŀ>#
> �½���ũ����Ŀ��<ũ����Ŀ>*
> �²��ũ����Ŀ��<ũ����Ŀ>*
> ���������ر���ͬũ����
> ���ؽ�������������<��������>*
> ���ؽ���ñ�������<��������>*
> ������������������������������������������������������־������
> * ��û�з�������仯������ʾ�ڱ����ϡ�
> 
> cmd report nation
> �����������������������ҡ����������ʡ���������Ѷ����������
> �������б�����<ʿ����Ŀ>
> �����������лƽ�<�ƽ���Ŀ>
> ��������������ʳ��<��ʳ��Ŀ>
> �������������µ�����
> ��������������
> ����ɥʧ�����µ�����
> ��������������
> ���һ���ı�������
> <��><��>��<��ɫ����>���飬**
> ʵ�ʴ�<����һ>����<����/��/��/ʿ��>��<������>��**
> ����������������������������������������������������־����
> ** �����˸�����������ʾ�ڱ����ϣ�û������ʾ��
It is a very good idea,but maybe very complex for we should keep a track 
of everything what happened before,and if we do this we should consider
the different of the nation officer ,and do all in a whole big project,
or later we still need to do more about it.
So who can give a suggestion which officer can see what?
BTW: fire,how about to absorb starrock to be a wiz who give plan ?
     For now i get to know that the plan is the headest work than 
     code,we need more more wiz to make plan.


---
����: Ice
��Ŀ: >about base
����: Thu Aug 17 19:24:25 2000
our mines r not function now yet, so still time to adjust that.:P
we dun even have a good way to allocate mines resource yet, so need to
consider it, maybe later.:P


---
����: ����ү(suicide)
��Ŀ: about base
����: Thu Aug 17 19:00:51 2000
Today i read the comments of ����������,and found that
���ڸ��ֿ�����ڸ�������
ÿ�µ��������ǲ�ͬ�ģ���Ϊ�����ط����ֿ�����Դ��ƶ���ǲ����ȵģ�������
����Ҳ�������������


---
����: Suicide
��Ŀ: >addoil suicide's relation_d
����: Thu Aug 17 18:56:21 2000
wx88.net��������������server��mail�����⣬����ǰ��wx88.netҲ�����⣬���˸�
elong.com���ٶȺܿ죬����һ��.


---
����: ����(ice)
��Ŀ: report type
����: Thu Aug 17 09:00:44 2000
cmd report

�����ʽ��
cmd report local      ̫��ר�õı����������
cmd report nation     ���ҹ�Ա�Ĺ����������

ע�ͣ�
ֻ����Ӧְλ����Ҳ���ʹ�ø�������ڹ��ҹ�Ա��ְ����δ��ϸ�ֹ���
��ʱ��ͳһ����ĸ�ʽ���С�

��ز�����
cmd report local/nation last <num_mon> �鿴��ȥ�����µı��漯�ϡ�
����ȱʡ��Ĭ��Ϊ�鿴�ϸ��µı��档<num_mon> ��Χ��1��12��

������أ�
̫�ز鿴���ر��棬ÿ��ÿ�±��������ı��ػƽ�100����������鿴��ȥһ��
�ı��������ı��ؽ�Ǯ1200��
���ҹ�Ա�����������鿴���ұ��棬ÿ��ÿ�������Ĺ���ƽ�200��������鿴
��ȥһ��ı��������Ĺ����Ǯ2400��

�����ʽ��
cmd report local
�������������ء����������������������������������������������
����    �ơ�<��������>    �� ������ ��<��������>
��������ʿ����<ʿ����Ŀ>
�ӱ������͵���ص�ʿ����Ŀ��<ʿ����Ŀ>*
��������͵����ص�ʿ����Ŀ��<ʿ����Ŀ>*
�������лƽ�<�ƽ���Ŀ>
�ӱ������͵���صĻƽ���Ŀ��<�ƽ���Ŀ>*
��������͵����صĻƽ���Ŀ��<�ƽ���Ŀ>*
�����������ݣ�<������Ŀ>
�ӱ������͵���ص�������Ŀ��<������Ŀ>*
��������͵����ص�������Ŀ��<������Ŀ>*
��������ľ�ģ�<ľ����Ŀ>#
�ӱ������͵���ص�ľ����Ŀ��<ľ����Ŀ>*
��������͵����ص�ľ����Ŀ��<ľ����Ŀ>*
���������ʱ���ͬľ�ģ�
��������ũ����<ũ����Ŀ>#
�½���ũ����Ŀ��<ũ����Ŀ>*
�²��ũ����Ŀ��<ũ����Ŀ>*
���������ر���ͬũ����
���ؽ�������������<��������>*
���ؽ���ñ�������<��������>*
������������������������������������������������������־������
* ��û�з�������仯������ʾ�ڱ����ϡ�

cmd report nation
�����������������������ҡ����������ʡ���������Ѷ����������
�������б�����<ʿ����Ŀ>
�����������лƽ�<�ƽ���Ŀ>
��������������ʳ��<��ʳ��Ŀ>
�������������µ�����
��������������
����ɥʧ�����µ�����
��������������
���һ���ı�������
<��><��>��<��ɫ����>���飬**
ʵ�ʴ�<����һ>����<����/��/��/ʿ��>��<������>��**
����������������������������������������������������־����
** �����˸�����������ʾ�ڱ����ϣ�û������ʾ��


---
����: Ice
��Ŀ: >>ת��
����: Thu Aug 17 07:51:51 2000
yap, i think gini is the same function of guan pig.:P although gini
is a little bit annoying sometimes, it's purpose is nice.:) suicide can take
a look of the gini's code.


---
����: Ice
��Ŀ: >��ɫ֮���ϵ�ȵĳ���/daemons/relation_d.c���:
����: Thu Aug 17 07:48:21 2000
Well, i think suicide did a good job.:) b4 he announced this, i have
another idea to implement simple relationship, that's koei's ���� or can be
called Ե��, that's a hidden para. the range can be from 0-999, and it can
be randomly allocated to different char. the relationship about it is, if a
char's xiangxing is 123, another one is 124, they 2 may have very
good relation
with each other, if the third one have 789, then he will have bad relationship
with those 2. anyhow, i think this idea from koei is interested, it explained
һЩ�����޷����͵�Ե��.:P maybe after the relation system is done,
we can think
about it.

about suicide's relationship code, i dun have many ideas yet, but I think if
system restarts, all relationship can be cleaned 0, then the system load won't
be too heavy. and every char's relation among others is starting
from 0, except,
those family relationship and jiebai, marry relationship, i think we need to
set a fix para for them, both NPC and player, if in those cases, the
relationship
won't be changed.


---
����: Row
��Ŀ: >ת��
����: Thu Aug 17 07:38:33 2000
we have gini...point fire...hoho


---
����: �Ƶ�(emperor)
��Ŀ: addoil suicide's relation_d
����: Thu Aug 17 07:26:59 2000
Ϊ��news���Ҳ��ܷ���post���ҵ������У�ÿ����ʾ���ͳɹ���ÿ�ζ��ղ���
wx88.net������Ӧ��û����


---
����: ����ү(suicide)
��Ŀ: ת��
����: Thu Aug 17 00:51:17 2000
1��������·
��ʵ�Ҿ�������־�����ⲿ���������Լ���ɫ������Ҳ����������ֵĲ��֡�
ÿ����һ�����������ˣ���Ҫ���ܶ�ʱ���������������������ⲿ�ֱ�ú�
��Ȥ���ǲ����������˵ġ������������ʣ�����Ӧ��������mud������õ�֮һ
�������ϵ��˲��࣬���кܶ���ÿ��վ����id�ĳ������ٵĹ�ϵ����ʵ�ܶ��˶�
������������˳�ȥ���Եÿ�������ࡣҪ������������ʵ��һ��npc��æ�Ϳ���
�ˣ�������һ������Ӧ����һ����·��guan pig�������ң�Ȼ��������һЩ����
���ҡ������Իش�һЩ���⣬�൱��help.�������׺�����ࡣȻ�󻹿���������
ʲô������Ӧ�óԷ��ˣ�����ȥ�������ʳ������ԡ�������ǿ��Դ�·����ȥ����
ask guan pig about �����������Զ�����ȥ�������Ǹö�á������Ժ�������֡�
����ѵ����ʲô�ģ�������뿪�˻�������ֻnpc���뿪���ˣ�������ʲô�ġ�
�����Ҿ��ó�����Щ�����ڴ������ѶȲ��󣬹ؼ�����ʦ�ز��������������˵ĸ��ܡ�
2. ����
���Ǵ����˵ĽǶȳ���˵˵���Ҿ��������ⷽ��Ҫ�����紴����ѧϰһ����˵������
��Ŀ�ľͷ��Ŀ�ľ�Ȼ�����ż�������ô���ģ�uo����Ҳ�п�ľͷ���������������
��ľͷ�᳤��ľ���ܣ���˵�ô�����ֻ��������߷�ľ�ɹ��ʣ����Ƕ���Ҳ�����
һ��ɾ͸С��Ҿ��û�Ӧ�������ڿ󡢴������в˵ȵȹ����������Ҳ���Դ������
����ʦ����
�ḻ��������û�õļ��ܣ������е���ѵ������������ȥ͵���е���ҽ���ÿ�������
����
���ڵ�����������̫�����ˡ�
���Ҵ�ı���ʲô�Ŀ��Ի�Ǯ����ã�
3������
���Ҳ�漰����������⣬������ʦ����ϣ�������Ŭ��ͳһ������ÿ������ÿ����
����������������е��˵������Ǹ�ݣ��е��˵������ǳưԣ��е��˵�����������
��һ�������е��˵����������µ�һ�׸����е��˾��뵱��������ٺ»�����ӣ��е�
�˿�����ƽ����
Ϊʲôһ��Ҫͳһ�أ���������ȱ����Ϸ�������ԡ�
��ʵ�Һ���������������һ�����µ�һ�����������һ��������˫�ı����������ã�
����û��������ְҵѽ����Ϸ��������ÿ��visitofficer��fanpeople������ʵ���ǲ�
ϲ���Ĺ���ְҵ���Էḻһ�㣬��Ҫ���ǵ��ٵģ������źõ�������ҽ����ѵ��ʦ����
�������ء�����������Ҳ�ܺã�����֮��û���������ǿ�����
4�� ����Ҫ�ǻ������ⷿ���������ͺ��ˣ����� ��������Ʒ(cmd addselllist xxx)��
�������ҵ�list�ͻῴ����Ҫ���Ķ����������ͼ�Ǯ��Ȼ����Խ��ס���Ȼ�����޶�һ
������ֻ׼�޶�һ�������͵���Ʒ�����������������ҡ����˳��󣬾���̫��һ������
������������ʧ�ٽ��н��ס������ḻ�г����ֿ���׬Ǯ������ѽ��
ֻ��������������е�����ˡ�����̫��̫�࣬û�кܶ�Ŀռ䣬Υ����һ��
mud��ԭ��
������uo����������й��Ļ�������������һ�ֽ�ϵ��뷨����ʦ�Ƕ��Ŭ���������Ǿ�
�ø��Ӻ����


�Ӹ���·����뷨������˼����?˵������һ��ܶ�����������.
����lima mudlib�����и�С����,���Ըĸ�Ŷ


---
����: ����ү(suicide)
��Ŀ: ��ɫ֮���ϵ�ȵĳ���/daemons/relation_d.c���:
����: Thu Aug 17 00:17:21 2000
��ɫ֮���ϵ�ȵĳ���/daemons/relation_d
����: ���ڱ����ɫ֮��Ĺ�ϵ�ȣ�Ϊ�Ժ����չ�˼ʹ�ϵ�ĺ��ĳ���
����: ���ڽ�ɫ�ڶ࣬������Ӧ�Ĺ�ϵֵ�����ݺܶ࣬����Ǽ򵥵�ȫ��
�������������ڴ��б�Ȼ�����ĺܶ���ڴ棬���ȫ�������ڴ�����ֻ��
��    ��Ҫʱ�����ڴ棬ʹ������ڴ���ж������ô���̾ͻ�Ƶ���ı���
������д�����ش��̵ĸ������������ߣ������ǲ����˴������ڴ�cache 
���������ϵķ�ʽ��ʹ��������ܴﵽһ�������Ч����
      �����Ҿͽ���һ���ҵķ�����
      �������ݵı��棬��û�в���һ��dameons �ļ��б���������һ��
      �ļ��еķ�ʽ��������body��link�İ���ɫID�ֿ�����ķ�ʽ����
      �����ڴ����趨һ���ڴ���cache ������Ҫ��ѯ������ɫ֮��Ĺ�
      ϵ��ʱ�����������ͼ��cache ��Ѱ���Ƿ���ڣ����û�о͸���
      ��ɫ��ID�������ļ��������ɫ�Ķ�Ӧ����װ��cache �����Ҽ�¼
      װ��Ķ�Ӧʱ��Ϊ��ʼ����ʱ�䣮���ڼ���cache �е����ݾ�ֱ��
      ��cache �л�ã�ͬʱҲ�������ķ���ʱ�䣮����cache �Ĺ�����
      �趨��һ����Ŀ�����ֵ��һ����Ŀ���ڲ������ʵ����ʧЧʱ��
      ����ÿ��һ��ʱ�䣨������Ϊ��Сʱ��ʮ�֣����Զ����cache ��
      ��Щ��ʧЧ�Ľ�ɫ���ݣ����⵱������ͼװ���µĽ�ɫ���ݶ�����
      cache �е���Ŀ��������Ŀ�����ֵ������Ҳ��ǿ��������ֽ�ɫ
      ���ݣ���������Ч�ķ�ֹ�˳�ʱ�䲻�����ʵ���Ч����ռ�ù����
      ϵͳ�ڴ棬����ϵͳ�����½�������Ҳ��Ϊcache �Ĵ��ڼ����˴�
      �̵�Ƶ����дװ��ж�����ݣ�
      
����: �ҵĳ����б���һ��������ɫ֮��Ĺ�ϵֵƽ����Ҫʮ���ֽڣ�����
������ƽ��һ����ɫ��ͣ�������������ɫ������ϵֵ����ô����һ����ɫ
��������������ռ���ڴ�������Ϊ10*300=3000 ԼΪ3k������cache �����
��������ֵ���Ϊ150 ,��ô�������ϵͳ����ռ�õ�150*3=450k ���ڴ�
�������ռ䣬�����������ܴ��һ��ϵͳ�������ֵ���뻹�ǿ��Խ��ܣ���
������Ȼ���ǻ�����ͨ��������ֵ�������������ռ�õ��ڴ�ռ䣮
��ʽ: һ����ɫ�������ļ���ʽ��:
      (["data":(["suciide":10,"fire",15]),"time":xxxxxxx])
      cache�����ݸ�ʽ��:
      "<��ɫid>":[��ɫ����]
      
����: get_relation(<��id>,<��id2>) ���ڻ��������ɫ��Ĺ�ϵֵ��
������add_relation(<��id>,<��id2>,int) �����趨������ɫ��Ĺ�ϵֵ��
������stat_me(0)  ���ڻ��cache�е���Ŀ��
������stat_me(1)  ���ڻ�õ�ǰ�����ʵĽ�ɫ����
      stat_me(2)  ���ڻ��cache����������
����: ���ҵĻ������Ѿ�ȫ�����Գɹ������ϴ��ļ���/dameonsĿ¼�£�����
���������Ҫ�ǲ��Ի�ʹ�ã���Ҫfire��/dataĿ¼�½���һ����Ŀ¼relation
      ����/data/relation�½���a.b.c.d.e.....z����Ŀ¼��
      
����������Ҫ�ģ�������Ȼ������ĳ�������ˣ���ôΧ��������һЩ��Ȥ��
�����˼ʹ�ϵ��ϵͳ������Ҫ��Ҷ��߻���ཨ������
���������ò��ã�:)      
.c���:


---
����: Ice
��Ŀ: >ת��
����: Wed Aug 16 21:43:04 2000
hmm, i dun really get it... but it's sounds like the situation to
enable chengdi in san7.:P
anyhow, i think it's not bad to implement an idea that increase some
importance of some certain areas, as some special bases do.
dun have clear idea of it now yet.


---
����: ����ү(suicide)
��Ŀ: ת��
����: Wed Aug 16 21:34:00 2000
ʱ��:  Thu Aug 17 07:02:50 2000                Post-id: 591 (591 Last)
����:  ��װ��(ghb)
��Ŀ:  ����һ���õĽ���
----------------------------------------------------------------------
�������ǲ��ǰ�Ю�����������ӽ�ȥ��
�Ѵ����ƹ��ӽ��Ƶ���ȥ
����ױ���Ŀ����500�ˣ��ٰ�ة�࣬���ǿ�����changan�����
�ҽ�������Ķ�������90,�Ϳ��Դ����ƹ���Ҫ��Ƶ�
�����Ю�����������
ս���ϳ���������λ�������ƺ�������˼��
�����Ƶ۵���������
han di������Ӧ����һ���


---
����: ����ү(suicide)
��Ŀ: To group
����: Wed Aug 16 06:52:24 2000
�ϵͳ��������أ�no NPC troops in the war. ���ԣ�/sgdomain/event/ev_cast
��ϵͳ��������أ�no NPC troops in the war. ���ԣ�/sgdomain/event/ev_cast
�����ġ����(ptwo)��war system should be the core of this game, not doing jobs
��ϵͳ��С��(chun)�뿪������־��վ��
cmd war time
���´�ս������ʱ�䣺ʮ��Сʱ��ʮ�����ʮ�����ӡ�

Group:
   �ڷ�war timeҲ���NPC troop��?


---
����: �Ƶ�(emperor)
��Ŀ: �й�����������
����: Wed Aug 16 05:27:40 2000
���R��վ08/10��������ͻ�ư�ǧ�˴Σ����x��ҟ���֧�֣� 
�� �R�W·������һ����؛ʮ���f��ȫ�����գ��ڶ����o�������ӏ��漴���Ƴ��� 
   

stefan,��������100��������ͼƬ�ߴＸʮM



---
����: �Ƶ�(emperor)
��Ŀ: �й�����������
����: Wed Aug 16 05:25:00 2000
������Ӎ��������߈�������춽��չ��棬ȫ�����������꼴������؜�������� 
�b������һ�ٷN�����������D�n���_��ʮMB��춸��Q�����b��r���ψD�ӿ��� 
�o��ͬ�����D���@ʾ�����cՈ���ҊՏ���������Լ�������Ч�� 

������Ӎ��������߈����������^�B�Ձ��^�죬�l�F���S����Ҟ�Dһ��˽��ʹ����� 
��ʽ�����e���Ɖ��[��ƽ���⣬��������r��ӍϢ�O����������Y���e�y������Ŀǰ 
�l�F֮������ 1 ֮����Ⱥ��������ʧ�����ֵ��ʧ�������e�y�ȣ���߈������������n 
��Ҳ�Ҫ����Լ���˽�j��Ӱ���������⣬����̎�P�k�����£� 
��1. �����߽���@��ֱ�ӿ��n��ȫ����ҡ� 
��2. ����@�ɴ����i ID�����Гpʧ�������ؓ�� 

 

 
 



---
����: ����ү(suicide)
��Ŀ: about war field map
����: Wed Aug 16 01:56:41 2000
Any one can make a change at war field map.
At least make those �ؿ� as the real area which is hard to attack
and easy to defend
.����Щ�ؿڵ�����Щ���հ� ...


---
����: Suicide
��Ŀ: >>about fight
����: Wed Aug 16 01:54:41 2000
I will just do as urs ah..
hoho


---
����: ����(ice)
��Ŀ: about localleader
����: Wed Aug 16 01:28:09 2000
�����ġ��ܵ��ع�Ա�ƾ٣��Ż���Ϊ�����̫��
�����ġ�����(ice)��maggy was xuchang taishou?
> �����ġ�С�����ԹԵ������������ԣ����������¡�
�����ġ�����(ice)��by b or by c?
> �����ġ�С����(may)��pos e to huguan
�����ġ��������°�ĭ���赹�ڵء�

faint, we omited this point, qiandu auto switch the capital localleader
to the new capital, then the former one is no leader actually, so maybe
make moving capital won't move localleaders/king to the new capital
automatically, let them do it themselves bah.


---
����: ����(ice)
��Ŀ: about war again
����: Tue Aug 15 22:15:40 2000
I think the situation now is exactly like long b4, cdd got changan
from taiyuan war with dummy, now ppl can ask for position if NPC
nation dun have guoshi and area dun have player taishou, then he
can cmd war an area, also his dummy may cmd me in defence war and arrange
troops for the defence party. I saw u guys posted an idea some
days ago, it's about if there is no local player leader chosen yet,
and the nation has no guoshi, make the NPC leader defaultly the defence
leader, I think we must do it now, bocz my last post in caolu must remind
them to use this way.:P pls do it as soon as possible.
otherwise it'll ruin suicide's work.


---
����: Ice
��Ŀ: >about fight
����: Tue Aug 15 22:07:38 2000
faint, suicide, would u pls try use my plan? i think it'll be
not hard to expand to urs, or wait for others discuss a little bit
more first? I think if u started it now, it's not too easy to
change later anyway, the later the harder.:P


---
����: ����ү(suicide)
��Ŀ: about fight
����: Tue Aug 15 21:49:36 2000
��˵��������,������һ����,�������,�����ٸ���


---
����: ����(ice)
��Ŀ: about dantiao
����: Tue Aug 15 21:33:28 2000
˵������ϵͳ�����ڲ�®Ҳ�ᵽ������ǰ����������һ���뷨��Ҳ����
���������ˣ������ڻ��������ƺ��е���ˣһ��ȭ��˭��������˭�ģ�
�����ֲ�̫�׵���ǰ����castor����˵��һ�£���˵������mud�ĵ���
Ҫ�����Ƿǳ��ѵģ���koei�ĵ������������õ�ģʽ֮�󣬻����൱��
����Ч���ں���֧�֣�������˵�����ǲ��粻ҪŪ�������ϵͳ������
���ֺá����룬���Ļ���һ������������������������˸����ӵĵ���
ϵͳ����֮��������Ա���ҽ��ܻ������˸���Ȥ����ô�������ܰ�
���ˣ�������Ϊ������������Ҫһ������ϵͳ��ֻ�ǣ�����Ҫ��ô���ӡ�

��˵SUICIDE�����⻰������ͬ���Ĺ۵㣬����������Ŀ��Ӧ���ǳ�Ϊ
һ�������������ᣬһ������HELP NEWBIE����д���ģ����Ӧ����
����ϣ���ɳ���Ŀ��ܶ������յ�Ŀ��δ���ǳ�Ϊͳһ�Ĺ������߼���
�Ľ��죬���ǿ��Գ�Ϊ����һ�������ˡ�������ҽʦ�ȡ�������ʱ����
�޷������ϣ����ǵ�ս�Ժ�ս���������ò�����������Ӧ�����ȸ��ĵ�
Ӧ����ս��ϵͳ������������NPC AIϵͳ�����ڵ�NPC��Ҫ���Ǳ����ģ�
û�������Ե�NPC�������Ϸɥʧ�˲�����Ȥ������ʹ������Ϊһ������
����Ŀ�꣬��Ӧ��������ʵ�������ϵͳ�Ļ�����ʵ�ֵġ�

����ϵͳ���ҵ���֪��Ӧ�ò���ͬ�����еĴ򶷣�fight��ϵͳ����
��������ƽʱ�������Ӽ��ܵģ���������������ΪӦ�ò���Ҫ���й���
���޸ģ������������Ÿ������˺ú������ˣ�����û��ʲô�����ǻ���
���������ġ������֮��Ϊ��Ҫ���ֶ��Ե�������������û��ʲô����
������Ϊ��������û������������Ҳû�еط����Իָ���Ҫ�ǷǱ�����
�����ӵ���������ҿ���û��ʲô��Ȥ����ȥ��ϵͳ�⣬�Ҿ����µ�
����ϵͳ������׶ο��Է��ڱ������ϣ����Ч�������ˣ��ٽ�����
�ϵ�ս����ȥ������Ҳֻ��ս���ֶ��е�һ�֣���Ҫ��ս������ս����
���ú�ʿ����ս����

�Ҿ��õ���ϵͳ��ʱ���ʺ�������ô�����Ӵ�����һ�������������
�����Ƶĵ���ϵͳ�͹��ˡ���������ϵͳ֮ǰ��Ӧ�ÿ��ǵ��������ٵ�
��ͬ�����Ҫ�������ÿ����һ��ָ�����һ�������ǲ�̫���еģ���
�������SAN7һ��ÿ����һ��Ҫ�ٿ�����һ����ʲô������˫��������
30�룬�Ǵ�����һ���˵��´���춼���ˡ����ԣ�����ˣȭ�Ƚ��ʺ�
���ڵ����������������Ϊ��·�Ļ�����Ż����Խ��ܰɡ�

����SUICIDE��������ͬ��;�����֣����е������������Ϊֹ��ʹ��
ʲô���������˿���֮�⣩�Ǹ��ݸ��˵İ��ã���Ϸ������ģ������Լ�
ϲ����ʲô��������ʲô���������Ӧ�ò�����������Ϸһ�����Ϲ�����
ɫ�ʡ����ڻ����Ȳ����ż����˰ɡ�

ÿ������Ҫ�в�ͬ����ʽ������ģ�ֻ��Ҫ����಻ͬ���������е�ͷ�ۣ�
�������Ҫ���е���ϵͳ�Ļ��Ǳ���Ҫ�ġ�������ʽ��ѧϰӦ��ͨ������
�����У���Ҫ���н�������Ҫ���õ����������ķ������Ҿ���ÿ��������
�м���������ʽ��Ȼ������������ʹ�����ˡ�

������ǰ���뷨�����뻹�ǿ��Բ��õġ�

����ʹ�õ���ʽ��
���ϡ����С����¡����ϡ����С����¡���Ϣ��������ʽ��
�������ϡ��С��£�������ʱ������ֿ����½�20%��
���أ��ϡ��С��£�������Է������������Լ����ص�λ�ã��ֿ�������
50%������Է������Ĳ����Լ����ص�λ�ã���ֿ������䣻
��Ϣ����Ϣ�ָ�ʣ����Ѫ��30%������Ϣʱ�ֿ����½�30%��

����ʹ�õ���·�����ܹ�5����
���б��ƣ�����һ�����ڣ�����ϵͳ����ѡ��ѡ��ķ�Χ����������Ϣ
��������ʽ������Ϣ��������ʽֻ����ÿ����·��ѡȡ���ܳ���һ�Ρ�

ս�����ˣ�
����ҵ�ʱ��ɱ����Ϊ����ֵ����϶Է�����·���Լ��Է��ĵֿ���������
���Է�������ֵ��

ս���ָ���
�ڵ�����ʼʱӦ��ֹ�����Զ��ָ���ֻ�е����ѡ����Ϣʱ���ָܻ�������

������ʽ��Ӧ�ã�
����������ʽÿ�ֱ������м��֣����⼸��������ʽ�����ࣺ
1��ȫ��һ������ʵʩȫ��һ��ʱ����ĵֿ����½�80%��������Է�Ҳ��
�����Ļ�������Ĺ�ʽ�еֿ���������80%���������ɱ�����ӱ���
2��ǿ����������ʵʩǿ������ʱ����ĵֿ����½�60%������ɱ��������
30%��
3��ȡ�ɹ�������ʵʩȡ�ɹ���ʱ����ĵֿ����½�20%������ɱ������
RANDOM��150%�����ɹ��ﵽ150�Ļ���ȫ��һ���൱�������˵Ļ�����٣�
ͬʱ������ɹ��Ļ���Ҳ�����˲��˶Է�һ����ë��
ֻ��������ʽ����ʹ�Է����ˣ���ͨ�Ĺ���ֻ�������Ѫ��

�����غ�����
�����ܹ���3���غϣ�3���غ�֮�����û�зֳ�ʤ������ʣ����Ѫռ����
Ӧ����Ѫ�ı������Ϊʤ�����ұ���400���Է�����300����ս����ʣ��
100����Ҳʣ��100����ô�ǶԷ�ʤ����

���ͣ�
1���ṩ�ֶ��ĵ���ģʽ����ң����ṩ����ʤǿ�Ļ��ᡣ
2�����԰���NPC�μӱ����ᣬ�����������սNPC�Ļ��ᣬspig��lv bu
��˭Ӯ����֪����
3����Բ����ӵ���ƣ�Ӧ�ò���Ͷ�����ľ���������Ŀǰ������������ģ�
���ǿ����������ϵͳ�ṩһ�����֮�䡢��ϵͳ֮�䶷�Ƕ����Ļ��ᡣ
4���������ڱ����᲻�����������������
5��������Ϊ�Ժ��һ������ϵͳ��չ�Ļ�����

hope u guys can consider it smoothly.:) * support


---
����: Ice
��Ŀ: >>My idea about jimou
����: Tue Aug 15 19:19:29 2000
Ҫ���һ��������AI�ǲ����ܵģ���Ϊ�˵���Ϊ��Զ�в���Ԥ֪�ԣ���
���Ե��ж��ǻ��ڳ�ʽ�趨��if...then...��������Զֻ����ӵ�
if...then...���ܳ�Ϊ�Ƚϳ����AI������Ϊ��

NPC�ļ�ıʹ��Ӧ�÷�Ϊ�����������һ������Ҳ�����ʱ��NPC�����
NPC�ļ�ıʹ��Ӧ�ý���������ѧ��ļ�ı���ڶ���������NPC��������
��Ҫ��NPC���м�ı���ܵ������൱���ѣ��������ı������ʱӦ��ֻ��
���ȡ�ã���������Ŷ������������KOEIһ����ÿ��NPC��ļ��ܵ�����
�ã������ڻ���������ɣ�����ʱ��NPC��ıӦ�ò�����ֱ�ӹ��������
��ǿ�ļ�ı����һЩ��ռ�������ȵľ��Ȳ��ÿ����˰ɣ��Ͼ�������Щ
��û�����������á�

Ӧ��ֻ�о����������ʹ�ü�ı������ʱ����£����������һ���ҡ�
���һ�����������������NPC�ģ�ֻ�о����������ʹ�ü�ı��������
��ֹ�˳��ּ�������ͬʱʹ�ü�ı��ɻ��ҵ�������������趨ֻ�д�NPC
���Ų���ʹ�ü�ı�ˡ�����ҪͬʱҪ��cmd cast�ĸ��ģ�ʹ����Ҳ���
��������ʱ�޷�ʹ�ü�ı��

��Ȼ������GROUPҲӦ���Ѿ����˵ģ����ǵ�NPC�������ڲ����⵽һЩ
�����ԵĹ���ʱ������Ӧ��ʹ��һЩ��ı��������ơ��������Եļ�ı��
��Ҫ�൱���if...then...�������ȸ���GROUP���᰸��Щ�޸�

if wuli is chosen, fenfa will be checked first. if can fenfa, 
the troop will fenfa, otherwise it will check whether can jiaoma, 
and last it will choose one from qibing and sugong.
����ܷ���������TRIGGER�������յ���Ϣ��Χ����ʱ�����ѡ��ܷ���
�������ڵ�NPC��Χ����Ҳ����ѡ�����ܡ���������ı��˳���ſ���
�ĳ��ٹ�������ܷ���TRIGGER��������������ս��һ��ʼʱ����
��鲿���Ƿ���������Ҫ�󣬷��Ͼ������Ȼ��������ڵ�NPC AI��
����Ż���ö����ֱ���Է��������ٹ���ս���бȽ���Ҫ��һ��������
˳��Ӧ����ǰ��

if zhimou is chosen, the system will check whether hunluan and
shidu can be used.

���û��������Ȼ��ң���ʩ����

if meili is chosen, system will try jiedu and shoushi first. 
then will be guwu and zhanbu.

����ʰ����ⶾ�ɣ�Ȼ����裬ռ�������Ǻǣ��ȽϿ��¡�

������û���趨NPC���Եļ�ı����ǰ���ǲ����ڿ�ս��ʱ����ϵͳ��
��������鼸�����ˣ���Ȼ����û�����뵽�������л�ʹ�ü�ı�ķ�����
�����GROUP�ķ�����ÿ7���������ȡһ��������ʵʩ��ı���ⲻ̫
�������ڵ�ս��״����7���ӵ�ʱ�������㹻һ����Ҿ��Ű��Լ��ľ���
ȫ�������ˡ�

����SUICIDE�Ŀ�������Ӧ���Ƚ�����ʵ�֣���ʵʩ�ɹ����м��ϱ�ʩ��
��������أ�����Ӧ�ø��ӽ���ʵ�����

Ŷ���벻��̫���ˡ�


---
����: ����(ice)
��Ŀ: �������еȼ���
����: Tue Aug 15 17:53:17 2000
�����������Ѿ����������ȼ��㣬�������������һ�����еȼ���Ļ���
���������֮�以���ʱȳɾͣ�������ΪǨ���Ƿ�����������׼��

�������еȼ���=
���еȼ�*200 + �����˿� /�����еȼ�*1000�� + ���׶�(300)
����ҵ + ũҵ + ��ҵ + ������*���еȼ�/2 + ������Ŀ*10

���������������100���˿ڣ�����ָ��ȫ�����Ļ�������10������
�������׶� =1000 + 200 + 300 + 800*5/2 + 100 = 3600

�����ũ��20���˿ڣ�����ָ��ȫ��������10������,�������׶�
=600 + 667 + 800*3/2 + 100 = 2567

���ָ���Ŀ����������ģ����ȳ��еȼ�����Ҫ��,Խ��ĳ���Խռ���ƣ�
Ȼ����Ϊÿ���ȼ��ĳ��ж����൱���˿����ޣ������Ҫ���ݳ��еȼ�
�������˿ڵļ�Ȩ���أ�����������׶���Ӧ�ñȽ�ռ���ƣ���Ȼ����Ϊ
Խ��ĳ��У��ڹ����������Ҫ����Ĺ�Ա���ε�����ְ������Ҳ������
���ݵ�����ͬ����Ȩ�Ĳ���������ǻ��أ���Ϊ��ҵϵͳû��������ȷ��
������ʱ�ȸ��ݻ�����Ŀ������ɣ�����û�м�Ȩ��

���һ������ҪǨ����������Ҫ�����õĳ���Ǩ�ɣ���ô�������ҹ���
����Ǩ������Ӧ�ó���һ����ʾ���ó��е�״�������еȼ��㣩�����й���
Ҫ�������ҪǨ���Ļ���ȫ���İ����½�����Ա�ҳ��½������Ŀ��
���е�״�������ڵĺõĻ�����Ǩ��˳���������NPC���ҵĹ�ʦҪ�����
Ǩ�������Ŀ����е�״���ã���Ǩ���ɹ��������Ļ�����ʦ�����ζ�
��������½���

���⣬����Ҫ��info������ϳ��еȼ������ʾ�������ѯ��

��������Ҫ�Խ����Ժ���ʵ�֣���ˣ�Ǩ�������Ϊ�������صľ�����
��������׼��������.:P


---
����: ����(ice)
��Ŀ: about taishou in na meeting
����: Tue Aug 15 16:28:19 2000
I think maybe piaox's report is right, bcoz only taishou can
suggest the transition between 2 areas, so I think when a 
transit-destination taishou ask for the meeting to transfer sth
to his area, it's possible now.  so maybe change to taishou can only
suggest to transfers out of his area, otherwise must be national
officer.:)


---
����: ����ү(suicide)
��Ŀ: still about fight
����: Mon Aug 14 23:04:18 2000
 ��row ����ս��ϵͳ������һ������,��Ȼ�з���,����Ҳ�ﵽ��һ����
��ʶ���򵥵Ľ���һ�£�
���������Һ�row ����Ϊ���ǵ�ս��ϵͳӦ�������ȥ������Ϸ��ϵͳȫ�Զ�
�����������Ƶ�ģʽ���ĳ��������Ϊ���ƣ�������Ϊ���ٵ�ԭ�����������
��������ȫ�˹����ƣ���Ϊ������Ȼ������������Ҳ���ƽ����������ɹ�
��������ʶ���ǰ��Զ����˹������������˹�����ָ�ϵͳҲ�ܰ�Ĭ�ϵ�
���������򵥹������У������Ҳ���Ը���ʵ�������ʱ����ָ������Լ���
������������ģʽ��
    
    �Һ�row ��һЩ����Ҳ�򵥽���һ�£�
    ����Ĭ��ս��ģʽ��
    ROW:����������趨���Լ���Ĭ�Ϲ�����·��
    ME :���ҵ�����У���һ���Щ������·�����������ļ��ܼ�����Ƶģ�
    ��������������ѧ����ʱ������NPC ��ʿ���ݻ�Ե�ɺ����ѧ���ˣ�Ҳ
    ��������˵���ܴ������ҿ���ʲô���⹥����·�����ᣬ��ֻ�л���
    �������ܵȼ�����������ΪĬ�ϵĹ�����·��������ϵͳ���е�ս��ϵͳ��
    �����������κθı䣬�����Ҳ�����趨��
    
    ROW:���ڹ�����·����Ҫ��������������Ϸ��perform ��ʽ�������ýְ�
        �ȴ���Ϸ��������·�Ĺ���ģʽ��
    ME :����Ϊ�õĶ�����Ҫ���գ�������Ϊ������ս����Ϸ��Ҫ��������Ϸ
    ������ȫ��ͬ�����ܾ�ʹ���������perform ���ʵ����ս��ϵͳ����
    ��������ľ������ڣ�����Ӧ�ð����õ�һ�����չ������ԸĽ�����ɸ�
    ��������ɫ��ϵͳ�������������У������Ҹ��У��������������������
    �����ң����ҵ��뷨��ֻ������perform �ĸ���������������ʽ����
    �����ҵ���ƪ��˵���������ÿ�����⹥����ʽ�������������Ĳ�λ
    �����ͽ�����ǿ�Ĳ�λ��ʵ����Ҳ�����Ϊ���ǹ��������¡���·����Ȼ
    ������λ�п��ܻ��ֵĸ�ϸ��ÿ������������·���ǿ�Լ��Ĺ�������ͬ
    ����ʱҲ����Լ�����ĳ����λ���صı�����������Է�ǡ���й������
    ����������λ��ǿ����·�������Ļ����Լ��ͻᷴ���ܵ��ش���ʧ������
    ����˫�������Ƿ��˽�Է��������·���Լ��Ƿ��п��Ƶ������������
    ����ս���Ľ������żȻ�ԣ��˽�Է�����·Ҳ����˸���Ҫ�����飮
    
    ˵���������һЩ���⻰��Ҳһ����һ�ᣬ�Ҷ��������MUD �ķ�չ��
�����������Ƴ�һ�����ȫ����������������������һ��ս��MUD ��Ϸ��
������Ϊ�˱�������ս����Ϸ����ɫ����������ϵͳ�Ľ��裬��ϣ����������
���������Ҷ����ҵ���ϲ���Ľ�ɫ(������ıʿ����ʿ�����˵ȵȣ���������
������ǰд����Ϸ��������)��������ֻ����һ�������ӵصĽ�������ɫ������
����ʹ���ǵ���Ϸ�����������;���������֪����Ҷ��������ô��ģ�
    
    


---
����: Row
��Ŀ: >about fight
����: Mon Aug 14 19:52:53 2000
�书����Ӧ�����������ս�������Ϸ��ռ�ݺܴ����������
��˼���أ��������Ĵ�ϵͳ���϶�Ϊ����Ϸ��ɫ���١���
�������Ѿ����˺�����������Ϸ���Ƶ��򵥵ö��ս��ϵͳ��
�ɲ�����ǣ�������ɫ֮һ----���������������޷�������
��˵����������������Ӧ����һ���佫�ƣ���ս����ʹ��������
���Է�Ӧս����ʼ������ʤ�߾���ʿ�����������߾���ʿ��
����������������Զ����ˡ�����Ӧ�ý�������Ƶþ��в���
Ԥ���ԣ�������ʮ��Ҳ�л������Ӯ��ʮ�ģ�����Ȼ��ʮ�Ծ�
ʮ�Ǻ��޻���ġ������������Ƶ�ʹ�ý�����ð���ԣ���Ϊһ
���ɹ�����Ч���󣬵�Ҳ���ᱻ���ã���Ϊʧ�ܵĻ���ͬ����
�����⣬ƽʱ��Ҫ�������ģ����Եȵ������ᣬ���ڵ�
�����ƺ����޴̼��ԣ��������µĵ���ϵͳ�������ܻ������
�Ҳ������Ȥ��

����ϵͳ����ƣ�����ǰ����и����룬����Ҳ����һ����
�ĳ��򣬵���֪�����������ˣ������ó����ο�һ�¡�����ү
����ҲӦ�����Ǹ���������ӣ���������������޸ġ���Ҫ��
Ŀ���ǣ���ȫ�������еĴ�ϵͳ�������µ�ģʽ���������
��ս���ǵĲ���ȣ�������������Ļǰ��ˢ��������ƴ����ʩ
��perform ��

ֻҪ����Ĺ�˼���ˣ���������Ҳ�ͺð��ˡ������ʲô
�������ӭ�����


---
����: ����ү(suicide)
��Ŀ: about fight
����: Mon Aug 14 18:13:49 2000
���������˺ü����ս��ϵͳ��������Ҳû�еõ�һ������ķ�����Ψһ
���ջ����Դ������ˣ�����ʵ���벻Сȥ�����Ȱ����Ժ��е�ֻ�۰�ϵ�
�뷨��д��������ש����һ�£�˵���������֮������һ���ܺõķ�����
    
    1)��������ϵͳ�п��֡���������ǹ��ꪡ�����������������ս��ϵ
    ͳ�ĵ�һ����Ҫ�ò�ͬ�������в�ͬ��Ч�����ҵĳ��������ǣ�
    ���֡�����������ʹ��ʱ�����ܲ���Ǵﵽһ���������ҿ���
    �������������ﵽ����һ�ĵز����������κ�����ʹ���κ�������
    ������������������ʽ��
    ����������������ǿ����������ʹ�ù������ľ������٣��ھ�����ͬ
    �������������Ҳ��ָ����������ʹ�õĹ��д�����࣬����������
    �������������˺�����ͣ����µı����Դ�����Ϊ������ǹ����ꪣ���
    ����������������������
    ����
    2)ÿ�������������������ʽ�����Ը��ݸ��˸��������ܵȼ���ϸ�ֳ�
    ���������𣬵�Ȼ��ʽ������Ҳ��ͬ��������ʽ�ɷ�Ϊ���к����У���
    ���߿�������ˣ�������ֳ����ɲ�λ��ÿ�����о��ж�ĳ����λ����
    ��Ч����ѣ���ĳ����λ����Ч����͵����ԣ�ͬʱ����Ҳ���ж�ĳ��
    ����λ������Ѻ���͵����ԣ��������������Ϳ�������������˵�Ч
    ������ʹ�ù��п��Լ�ǿ�Լ��Ĺ�����ͬʱһ��ʱ��������ķ��ؽ���
    �����Է��ķ�����ɿɳ�֮������ʹ�����п��Լ�ǿ�Լ��ķ�����ͬʱ
    ��һ��ʱ��������Ĺ������ͣ������ڴ�ʱ���ڿ��Իָ��Լ�ʹ�ù���
    �������ĵľ���ﵽ�ڴ�ʹ�ù��еĵز�������Խ�������ĵľ���Խ��
    ���ҽ��ͷ���Խ�࣬����Խ����������Խ�͵�����Ļָ��ٶ�Խ�죮
    
    3)������ʽ��ѧϰ���佫������̫�ظ��Ҫһ����ѧ���е������ڴ�
    ���ڼ��ڿ����Ĵ�Ѳ�Σ�Ѱ��������ֵ���ʿ���䣬��ĳ����������ʿ
    �����԰��Լ����������ʽ������ң�����ѧ���е�ʱ�����佫�޷���
    ����ս������������������͹����йص�������ɸ��˺͹�������֮
    �����һ��ССì�ܣ����������Ժ��ϵͳӦ�ö��������ƣ������
    ���˺͹��������ĳ�ͻ��������Լ�ȥȡ�ᣬ�����ǲ��Ǹ�����˼��
    ��
    
    
    ���Ͼ����ҵ�һЩ�뷨���ǳ��ǳ������죬��ӭ��Ҷ�������:)


---
����: Suicide
��Ŀ: >>about auto cast
����: Mon Aug 14 18:13:05 2000
But i can use ftp server ah,why?


---
����: Ice
��Ŀ: >>about auto cast
����: Mon Aug 14 16:39:38 2000
faint, fire didn't use ultraedit bah, seems i m not the last guy.
fire wanna try that? edit on ftp server, without using the ed here.:P


---
����: Fire
��Ŀ: >about auto cast
����: Mon Aug 14 16:34:54 2000
On Mon Aug 14 01:30:19 2000 ����(group) wrote post #1731:
> i just finished auto cast code, it seems working well on my 
> computer, but not sure whether it is good enough or not.
> 
> in every 7 minutes, system will random choose a NPC troop,
> can then random choose a jimou for cast.
> 
> mainly there are 3 types, base on wuli, base on zhimou, base on meili.
> 
> if wuli is chosen, fenfa will be checked first. if can fenfa, the troop
> will fenfa, otherwise it will check whether can jiaoma, and last
> it will choose one from qibing and sugong.
> 
> if zhimou is chosen, the system will check whether hunluan and
> shidu can be used.
> 
> if meili is chosen, system will try jiedu and shoushi first. then will
> be guwu and zhanbu.
> 
> other jimou like neihong, huangbao, luoshi, jbsj will be added in later
> however, i need do a mess change for the jimous.
> 
> fire, please check check the ftp server, it is not working for me 
> and flee....:~(
> 
> regards

great group, for the ftp server, it can't go through fire wall.
So I can't use ftp either. I always use ed, cut and paste. sign


---
����: Fire
��Ŀ: >about NPC leave
����: Mon Aug 14 16:33:00 2000
On Mon Aug 14 00:11:04 2000 ����ү(suicide) wrote post #1727:
> I have done nothing with NPC leave.
> NPC just leave for its low loyalty,And many NPC now has low loyalty.
> I don't know why ? 

I think because of restart all the loyalty are random assigned. hoh


---
����: Group
��Ŀ: >My idea about jimou
����: Mon Aug 14 04:18:58 2000
1. this skills comparison is there already, the thing need to
consider is the formula.

2 now the limitation comes from the jing sheng. since only 
sleep can recover it, a player can only use limit number of 
jimou within a war time.

about the times limitation... hmm... maybe can appears from the jing sheng
formula.

3. yap, that is the same thought as me, so when i can update the jimou
system, all this comparison will be added in.

xixi
regards


---
����: ����ү(suicide)
��Ŀ: My idea about jimou
����: Mon Aug 14 03:02:58 2000
     Group�Ѿ���ʼ�޸ļ�ıϵͳ��,�ڴ���˵˵�ҵĿ���������
     ��ı��code��ûʲôϸ�������뵽��˵���ǣ�Ҳ����Щ�뷨
     ����ϵͳ�Ѿ�ʵ���ˣ�
     .
     1 ��ı��Ҫ������ƣ��Ҵ�ſ���һ�¼�ı��code�������
     ���ԵеļƲߣ��ڼ���ɹ��Ժ�ɱ����ʱ������û�п��Ƿ�
     ���ط���������(������ط��佫�����ı�ĵȼ������ط���
     ��������ı����������������ܿ����Ϸ��ط��佫����Щ����
     ���ǲ��ǻ������˼�����磬������(A��)�Է��ط�(B��)ʩĳ
     �����ı(C�ƣ������B�����佫��C�Ƶȼ���A���Ļ��ߣ���ô
     ���üƾͲ�Ӧ�óɹ�������͵Ļ����ݵȼ����������Ӧ����
     ��ɱ������Ч���������Ϳ��Լ򵥵Ľ���һ���໥���Ƶķ�ʽ��
     
     2 ��ı����ս����˵��ԶӦ��ֻ��һ�ָ����ֶΣ����������壬
     ���������������ü���Ȼ���е�ƫ���˷����ǲ��ǿ��Ը���
     ����ҵ���ıֵȷ��һ��ս�����������ʹ�õĴ���������
     ����಻Ӧ�����ĴΣ�
     
     3 �佫��  --���ض����������ɱ�����ļ�ı����˫���ľ�������
     �������������Աȱ����йأ�
     ���ǽ���  --���ض������ʹ�з�������ʱɥʧ�������ж�������
     ��������������˫���佫����ı�Աȱ����йأ�
     ���Ƚ��ơ�--���ض�����¶��Լ�ʹ��������Լ�����ĳЩ��ֵ����
     �������������������Լ�������ֵ�й�.����


---
����: �һ�(fire)
��Ŀ: ����relation_d
����: Tue Aug 22 17:08:14 2000
I have readed suicide's relation_d.c, it is a very good programming.
I think for 
those who want to learn some program skills, it is a very good sample:)

Here is some of my suggestions:
1 One thing is not clear, is the relation only one way realtion, which
  is from npc to a player. or a two way relation between any chars.
2 If it is a two way relation. does the relation A->B equals B->A, if it
  is this case, when we add relation, we need adjust both files. but it
  is good for quiring. For example, if I want to check my relation to
  several npcs, I don't need to load all those npc's relationship files
  I only need to load my relationship file and get the whole result.
  I think this can save lot's spaces.
3 I suggest once the relation drop to zero, that record should be removed
  from the relations, this can save space.
4 Maybe we can add a auto clean function. all the relations keep dropping
  if the player doesn't play. once his relationship with one npc drop to zero
  we can clean a record from both his relation file and that npc's
relationship
  file. the method can prevent the whole relationship growing without control.
5 The last is only a small one, There is a function called implode which can
  concatenate strings from an array, it is oppersit to explode. 
Anyway, relation_d is an excellent work, addoil suicide :)



---
����: �һ�(fire)
��Ŀ: ����relation_d
����: Tue Aug 22 17:08:14 2000
I have readed suicide's relation_d.c, it is a very good programming.
I think for 
those who want to learn some program skills, it is a very good sample:)

Here is some of my suggestions:
1 One thing is not clear, is the relation only one way realtion, which
  is from npc to a player. or a two way relation between any chars.
2 If it is a two way relation. does the relation A->B equals B->A, if it
  is this case, when we add relation, we need adjust both files. but it
  is good for quiring. For example, if I want to check my relation to
  several npcs, I don't need to load all those npc's relationship files
  I only need to load my relationship file and get the whole result.
  I think this can save lot's spaces.
3 I suggest once the relation drop to zero, that record should be removed
  from the relations, this can save space.
4 Maybe we can add a auto clean function. all the relations keep dropping
  if the player doesn't play. once his relationship with one npc drop to zero
  we can clean a record from both his relation file and that npc's
relationship
  file. the method can prevent the whole relationship growing without control.
5 The last is only a small one, There is a function called implode which can
  concatenate strings from an array, it is oppersit to explode. 
Anyway, relation_d is an excellent work, addoil suicide :)



---
����: �һ�(fire)
��Ŀ: suicide����Ʋ��������޷���
����: Tue Aug 22 16:44:42 2000
���һ�����ְ����ְ�ɫ�����⡣
�����Ը��е�ע�������ͷ����޳�Ҳ
�޷����ֳ��������Կ�����Ҫһ
������ӵ���ơ�



---
����: Fire
��Ŀ: >>�������Ը��ɫ��ϵϵͳ������:
����: Tue Aug 22 16:16:18 2000
On Mon Aug 21 19:14:54 2000 Row wrote post #1793:
> ����һ���൱����˼����ơ���ҵ��Ը��ص����ȷ���أ�����ȫ�����
> ��

the design is interesting, but lack the flexible to expand.
hmm.


---
����: ����(ice)
��Ŀ: about boy
����: Tue Aug 22 11:05:41 2000
I think most of us knew this b4, that's if sb keep asking a boy
about somebody or xianren, then the boy will be busy, and then
all others cannot do job related to the city's NPC.

i tried to read the code, and i didn't find any time limit if
not answering boy's question.
I think we can make 2 changes if there is not time limit at present:
1. add time limit, like 20 secs sth.
2. if the time limit reached, then the boy will kick the player
and move to the next room.

though it's not the best way, but i think can be little bit
better bah.:)


---
����: �Ƶ�(emperor)
��Ŀ: �����ҵ������suicide�Ķ��и��ô�������Ҫר�ű���CHAR��Ĺ�ϵ��
����: Tue Aug 22 07:30:04 2000
��Լ�ڴ����������ֻ����ҪCPU����һ�²����ϵ�ȵĺ������ø�ֵ��


---
����: �Ƶ�(emperor)
��Ŀ: �Ը���
����: Tue Aug 22 07:17:52 2000
suicide������ܺã���������
�����뻹�Ǳ仯һ��Ϊ�ã��򵥵Ľ������£�
����һ����9��Ƨ��--��Ǯ���������������ġ����䡢�þơ���ʳ����ɫ��
�ô���
��restartʱ�����������һ��NPC�м��ְ��ã���һ�ֵ����֡�
��Ҹ�ע��ʱҲ������ɺ��м��ְ��á�
�����֮�����Һ�NPC��û���κ�һ�ְ�������ͬ�ģ�
�������Ը���ȫ��ͬ��
��һ����ͬ�ģ�����Щ���ݣ�
�ж�����ͬ�ģ���Щ���죻
��������ͬ�ģ��Ը���
ȫ����ͬ�ģ��Ը���ȫ��ͬ��


��Ȼ�����Ϸ��䷽��Ҫ������Ը���ȫ��ͬ�ĸ����Ǽ��͵ġ�
��Ȼ�����Ϸ��䷽��Ҫ������Ը���ȫ��ͬ�ĸ����Ǽ��͵ġ�

����һ�ַ����ǣ�
�ٶ���15�ְ��ã���ÿ����Һ�NPC������10�ְ��ã�
Ȼ���������ϵ��Ը�ƥ�䷽������������֮���Ը��ϵ��
��Ϊ��ʵ���Ը��ϵĸ���룬��Ҫ����������CHAR�İ��������������С�
���������Ը���ȫ��ͬ�ĸ����Ƿǳ��͵ģ�������ҵ���Ϸ��

���������ж����ְ�������������Ҫ�ø���������һ�£����������
�Ը����̶ȵ����仮�֣�������ͷǳ���ѧ�ˡ�

���ֻ������Һ�NPC��ֻ��һ�ְ��ã���̫�����ˡ�

����ֻ��һЩż�У���Ҳο����ӡ�



---
����: Ice
��Ŀ: >���ڴ�ϵͳ�ĸĶ�������code���԰�װ�ɹ���
����: Tue Aug 22 04:07:28 2000
fight also should not be available in fly_room.:) otherwise
can flood while sb is trying to arrange troops b4 war.
and I think attack can be only possible in the attacker's own
area, so that it can be said defence his own area if sb trying to
do some hurting job to his area.
hmm, or we should make it only when sb is jailed, only can attack in
the attacker's jail and the attackee must be a prisoner.


---
����: Ice
��Ŀ: >vote close fix lah
����: Tue Aug 22 04:03:22 2000
great.:)
massage suicide


---
����: ����ү(suicide)
��Ŀ: ���ڴ�ϵͳ�ĸĶ�������code���԰�װ�ɹ���
����: Tue Aug 22 02:18:43 2000
1  ԭfightָ�����ǰһ����ֻ������������Ҫ�Է���Ӧ�ſɣ�
2  ��������һ��attack ��ָ��������κ�ʱ���κεط���
�� �����������������ж������������������attack���򶷣�
�� �Ҳ���Ҫ�Է���Ӧ��
3  fire��/std/monster/heart_beat.c �е�start_fight ����
�� �ж�������ʱ��û�д�����������Ҫע�͵�����жϵĴ�
 ���룬����Կ������Ŀ¼��Ȩ�������𣿻��߰��ҷ���/wiz
   /suicideĿ¼�µ�heart_beat.c���ƹ�ȥ��Դ��û�иĶ���
   ֻ��ע�͵����Ƕ��ж���䣮��Ϊ����ж����ظ��ģ���
   fight.c��attack.c�ж��Ѿ������ж��ˣ���


---
����: ����ү(suicide)
��Ŀ: vote close fix lah
����: Mon Aug 21 21:10:51 2000
ice
   I have fixed the vote close channel ,now 1 IP only can vote once.


---
����: Suicide
��Ŀ: >>�������Ը��ɫ��ϵϵͳ������:
����: Mon Aug 21 21:04:45 2000
nod row.
all random.


---
����: Row
��Ŀ: >�������Ը��ɫ��ϵϵͳ������:
����: Mon Aug 21 19:14:54 2000
����һ���൱����˼����ơ���ҵ��Ը��ص����ȷ���أ�����ȫ�����
��


---
����: ����ү(suicide)
��Ŀ: �������Ը��ɫ��ϵϵͳ������:
����: Mon Aug 21 18:31:46 2000
ȡֵ��Χ:1-100  ��100��
������Ʒϵͳ������,���԰���Щ�Ը�ֳ�ʮ������,��ͬ�Ը�Ľ�ɫ
���ò�ͬ����Ʒ,�Ժ���£�佫�Ϳ��Լ�����������ϲ������Ʒ,��̫
����־��һ��.
01-10     ��Ǯ   ϲ����Ǯ
11-20     ����   ϲ������
21-30     ����   ϲ����ƥ
31-40     ����   ϲ���鼮
41-50     ����   ���,�Ƚ����׽���
51-60     ����   ���,�Ƚ����׽���
61-70     ����   ϲ������
71-80     �þ�   ϲ���Ⱦ�
81-90     ��ʳ   ϲ��Ʒ��������ζ
91-100    �ô�   ϲ������
�����ж�������ɫ���Ը�����Ƴ̶�ʱ,��Ϊһ�¼���:
�����ɫA���Ը�Ϊa,��ɫB���Ը�Ϊb
level0 if  a=b       �Ը���ȫ��Ͷ  
level1 if |a-b|<10   �Ը�������
level2 if |a-b|<20   �Ը���ϸС�Ĳ���
level3 if |a-b|<30   �Ը�һЩ����
level4 if |a-b|<40   �Ը��ٲ��� 
level5 if |a-b|<40   �Ը�ܶ����,���ǻ�������
level6 if |a-b|>=50  �����  
�����������жϽ�ɫA��ͼ��£B��ʱ��,Ч�����жϾͿ���������ĵȼ�lvl���ж�,
if lvl=6  ʧ��,�޷��ɹ�
if lvl<6  then
   if random(lvl+1) ==0  �ɹ�
   else                ��ʧ��  
�����ǵĽ�ɫ��ϵϵͳ��,����һ����Ҫ�ĸ�����:
A��B�Ĺ�ϵ��(�����Ϊ��Ϥ�̶�,��Ȼ���ֵ������������a��b����)
��ô�ѹ�ϵ�Ⱥ��Ը�����ڳ����ж���,�����������ǵ�:
����ǰ���Ը����Ƴ̶ȵȼ����жϹ�ʽ��Ϊ:
�ȼ� = bmin(|a-b|,(100-��ϵֵ)),Ҳ����ȡ���ߵľ���ֵ.
�ٸ�����:
���|a-b|=60ʵ������ζ�������Ը�ܲ���,���������ɫA�ͽ�ɫB�Ĺ�ϵ��Ϊ80,
��ô100-80=20,bmin(60,20)=20,Ҳ����˵���Ľ���ǵȼ�Ϊ3,�����ǵȼ�6,��
ô��ɫA��ͼ�Խ�ɫB������£ʱ,�Ͳ�����ȫʧ�ܶ���һ�����random(3+1)
����������ͼʱ:
    ��ʵ������Ҳ�����Ը�ͬ���˾��޷���Ϊ����, ���������ǵĲ߻��н�ɫ��
�Ը���ÿ�����ǹ̶���, ����ϵ���ǿɱ��, ��ν�����Ϊ���Ը����ϴ��ʹ��
����ɫ�޷��ߵ�һ��, ʵ���е�ƫ��, ������뿼�ǹ�ϵ�ȵĻ�, ���ǿ���ͨ����
��һЩ������¼��������Ը����̫��Ľ�ɫ֮��Ĺ�ϵ�ȵõ��������ֲ�������
����������޷����ݵı׶�.
    �ٸ���򵥵�Ӧ�����ӣ������н�ɫA��Ů��ɫB��ͼ��飬���ǿ������ж���
�ߵ��Ը�����Ƿ�̫����̫�����޷���ϣ�������ʱ���԰���һЩ�¼������н�
ɫAȥ������ж�Ů��ɫB���Ӷ��������ߵĹ�ϵ�ȣ������Գ����Ը���谭����
����ϵ�Ŀ�꣮
�������ҵ�һЩ�뷨����ӭ����Ὠ�飮��:)
������û������Ļ�����׼�����������ϵͳӦ����whisper��visitofficer����
JOB��.


---
����: Suicide
��Ŀ: >re suicde
����: Mon Aug 21 18:30:54 2000
I have put it in /daemons lah,It isn't working now.
U can check it lah.


---
����: �һ�(fire)
��Ŀ: re  about officer_d
����: Mon Aug 21 16:23:50 2000
----------------------------------------------------------------------
>�Ҿ������ڵĹ�ְҪ��̫������������Щ���ֻ���һЩ���ף�
>���ڹ�ְ��Ҫ�󾭳��Ƕ���һζ���������Կ���������75 30 30
>�Ľ�ɫ���Ҽǵ������й�ְҪ��ļƻ����ǰ����������츳������

ͬ��Թ�ְҪ�����һ���ĵ�������Ȼ��Ϊ��������������
Ҫ���⣬Ҳ�����ʵ����ӵ�������������Ҫ�󡣵�Ҫ������
��������Ϊ���ؿ����츳����Ϊ�����ɳ����ٶ�ֱ�Ӻ��츳�йص�



---
����: �һ�(fire)
��Ŀ: about starrock
����: Mon Aug 21 16:18:32 2000
If anyone meet him, can ask if he is still interested
in becoming a wiz here.


---
����: �һ�(fire)
��Ŀ: re suicde
����: Mon Aug 21 16:17:58 2000
about the relationships' design,
please put your code under your directory first and
let us have a brief check. then we can implement
in a suitable time. 
addoil suicide :)


---
����: Ice
��Ŀ: >���Ļ����˲��Ե�ʱ��
����: Mon Aug 21 02:21:34 2000
hoho, but if i just want to get literate, i just need to answer
about 10 wrong, then just keep asking for job and resign, will get
literate yah.:) better consider it in more details.:P


---
����: ����ү(suicide)
��Ŀ: ���Ļ����˲��Ե�ʱ��
����: Mon Aug 21 02:20:14 2000
�����ġ�̩ɽ(tazan)��change to all robot test at ask job mah
�����ġ�̩ɽ(tazan)��all same as waterflower
�����ġ�����ү���˵�ͷ��
�����ġ�����ү(suicide)��It is a good idea.
�����ġ�̩ɽ(tazan)��but a lazy idea:)
�����ġ�����ү(suicide)��No answer true No get job
�����ġ�̩ɽ(tazan)��easy to change yah:)
�����ġ�̩ɽ(tazan)��no job and add job counter

And change all robot-test style to sentence-style,which style i had explained 
that can not make robot to overcome,then we can control multilog.
How do u guys think about?


---
����: ����(ice)
��Ŀ: about officer_d
����: Mon Aug 21 01:01:34 2000
�Ҿ������ڵĹ�ְҪ��̫������������Щ���ֻ���һЩ���ף�
���ڹ�ְ��Ҫ�󾭳��Ƕ���һζ���������Կ���������75 30 30
�Ľ�ɫ���Ҽǵ������й�ְҪ��ļƻ����ǰ����������츳������

�������¶����ְҪ��ļ��ܺ��츳Ҫ�󣬵�����Ҫ�ڳ��������޸ģ�
��Ҫ�����츳��Ӻͼ�����ӵĺ����������Ҷ�����ɺ󣬿���ȡ��
ԭ���ļ��ܺ�����

����Ҫ���ӵĺ��������������
@OFFCER_D->set_officer(61,"gift",(["wuli"+"zhimou":30]))
��֪�������ʽ���ԣ��������˼���������

���¼ƻ��������ģ�
�ط���Ա�������츳�����츳�����Ҫ����ӵĺ�������ȱʡΪ0��
�ط��佫Ϊwxxy+bfxy
�ط��Ĺ�Ϊzgxy+bfxy
���ҹ�Ա���˺���������ӵ�Ҫ��֮�⣬��Ҫ�����츳��Ҫ��
�����佫Ϊwxxy+bfxy��wuli+zhimou
�����Ĺ�Ϊzgxy+bfxy��meili+zhimou
�ط����죨������ʼʱ��̫��ѡ��Ҫ����������������ܺ͡�
���ط�����Ҳδ��Ҫ�������Ҳ���ԣ�

������������������޸���ɵĻ����һ�ͨ��
@OFFICER_D->set_officer �����¶����ְ��Ҫ����

ͬʱinfo o xxx �ĸ�ʽҲ��Ҫ���޸�


---
����: Ice
��Ŀ: >Re fire
����: Sun Aug 20 23:31:36 2000
errr, sth about starrock's apply, i think we should firstly ask
his willing of joining wiz team now, then our admin have to do sth
b4 promote him, that's we must move all the posts about commercial
move into an achieve. well, maybe i take it too serious, but i think
if a fresh wiz knows this, especially he's promoted from a player, i
think it's a must do.
btw, pls move this post to achieve as well, or i should discard it.:P
regards


---
����: ����ү(suicide)
��Ŀ: Re fire
����: Sun Aug 20 22:39:51 2000
1 ����fight�����԰�Ҫ��Է�ͬ��ſ���fight������ȡ����
  ��Ҫ�����ڷֱ���������fight�����ơ�
RE: Agree . I will modify the code later.
  
7 ����suicide�Ĺ�ϵ�ȵ���ơ�����ڼ����Ϻ��м����ԡ�
  ����ϣ���ܺ�Ŀǰ�Ľ�ɫ�ڹ��ҵĹ�ϵ����һ�¡�ͬʱҲ
  ���Կ��Ǽ����ɫ�Ը�Ĳ�������������һ������Ŀ��
  
RE: ��Ϊ����idʵ���Ͼ��ǹ�����id,���Ա���һ�º����ף�
�������ǿ��ǵ���ǰ����ļ����ԣ���Ȼ����Ҫ�޸Ĳ���
����code�����ҿ���һЩ���ǻ���©��ɲ���Ҫ���鷳����
�������ҵ��뷨�ǣ�����ԭ����ɫ����ҹ�ϵ�Ľṹ����Ϊ
�������ǽ�ɫ�͹��ҵ�һ��Ч�Ҷȣ�������ڽ�ɫ�͹�����
����������ƵĹ�ϵ�Ⱦ��ǽ�ɫ�Թ���˽�˶��ԵĹ�ϵ�ȣ�
��������һ����ɫ�Թ��ҺͶԹ��ҵ������в�ͬ���ҳ϶Ȼ�
�����Ƿ���ʵ������ģ���Ȼ��ɫ�͹���˽�˹�ϵ�ȵ�ֵ��
����С����Ӱ���ɫ�Թ����ҳ϶ȵ���������֪fire����Ϊ
����������������ڽ�ɫ�Ը���������Ѿ���ice ���۹���
�������ˣ�ice ��������һ��koei��Ϊ����Ҳ�����Ը�Ĳ�
����������Χ��1-(xxx) ֮�䣬����ɫ��ֵ�����Ҳ����ζ
    Ȥζ��Ͷ�����̫�����ζ���Ը����롣
    
    �����ͬ�������ϵĹ۵㣬���������е�code�������Ѿ�
    ׼�����ˣ���������Ҫ�ľ������Χ������Ƴ���Ȥ�Ķ�
    �������ҵĳ����뷨������������ǰ�NPC�����ĳ�ʼ��
    ��һ���������趨����ҵ��Ը����³�ʼ��ֻ��Ͷ��
    �Ը�����Ĺ���Ϊ�٣���ô�Ϳ��Ա����ڳ��ھ��γɵ�һЩ
    ���Ż������Ϸ�ľ����ԡ������Ը�������������Ե�ͬ��
    һ�����˲����ܶ�����˼�Ķ�����������Ұ��ֲ��Ͼ��޷�
    ��顣����grin��
4 ����starrock����ʦ���룬��û�з�����������û����
  ����ͬʱ����ϣ��������ô�����������ˡ�
RE: ���ǿ��Ը���һ��������Ŀ�����Ǹ������ǵĹ�ϵ���Ը�ϵͳ
�������һ�������Ȥ��plan�����ͨ�����ǾͿ�������������ʦ
���������������ô��?


---
����: ����(ice)
��Ŀ: jimou table
����: Sun Aug 20 17:36:41 2000
�ɣ�          �ȼ�  ʹ�ü��        ʹ��Ҫ��    ��������
jiedu         ��    100            ʮ����      �ι�����
chenzhuo      ��    һ��            һ��        �ι�����
zhanbu        ��    �İ���          ��ʮ����    �ι�����
shidu         ��    300            ��ʮ��      ��������
fakeorder     ��    400            ��ʮ�弶    ��������
fengbian      ��    ������ʮ��      ��ʮ�˼�    ��������
shoushi       ��    60             ��ʮ��      �ι�����
scout         ��    ��ʮ��          ��ʮ�弶    �ι�����
tianbian      ��    �İ���          ��ʮ��      ��������
hunluan       ��    200            ��ʮ��      ��������
guwu          һ    150            һ��        �ι�����
qibing        ��    400            ��ʮ��      ��ѧ����
neihong       ��    300            ��ʮ��      ��������
sugong        ��    300            ��ʮ����    ��ѧ����
luanshe       ��    300            ��ʮ��      ��ѧ����
fenfa         ��    300            ��ʮ�弶    ��ѧ����
huangbao      ��    ������          ��ʮ�弶    ��������
luoshi        ��    250            ʮ�弶      ��ѧ����
jiaoma        һ    100            һ��        ��ѧ����
maifu         ��    ������          ��ʮ��      ��������
jbsj          ��    300            ʮ��        ��������

1. I cannot find the mp consumption formula, so do group.
so I think we may use the level of the jimou to indicate the
comsumption. there r 4 levels, and group expect that the
average mp of players r around 300, so we can make a basic
unit of consumping mp25, multiply by the level of jimou, so
that the jimou can be used in war should be around 6-8 times
per war, hope this can be more balanced. or adjust it later.
2. I changed some of the internal time, it's shown in the above
table.


---
����: �һ�(fire)
��Ŀ: Re: 
����: Sun Aug 20 16:48:00 2000
1 ����fight�����԰�Ҫ��Է�ͬ��ſ���fight������ȡ����
  ��Ҫ�����ڷֱ���������fight�����ơ�
2 ���ڼ�ı�����Ӽ�ıʹ�ô�����һ���ð취�������
  ����Ϊ����ս��һ���ļ�ı��ʹ�ô���������һԱ��
  �ļ�ıʹ�ô�������������ǿ����ͳ��ָ�ӡ�
3 ����anti-robot�����¼����������Ӳ�����⡣��ʵ����
  �µľ������ܼ򵥡�ֻҪ��/sgdomain/robot/sentence/
  ���¼�һ��*.txt�ļ���ÿ���ļ�������ʮ�С�ÿ���ɼ���
  ������ɡ�ÿ������֮�������Ķ��ŷֿ�������������
  ��һ���µ���⡣ע��һ�㣬���е��ַ���Ҫ��ȫ�ǵġ�
4 ����starrock����ʦ���룬��û�з�����������û����
  ����ͬʱ����ϣ��������ô�����������ˡ�
5 ���ڹ�ʦ����ƣ���Ϊ�µĹ�ʦ�����ѡ�ġ���������
  ��DUMMY�Ŀ����Բ��󣬿��Կ����ʵ��Ӵ��ʦ��Ȩ����
6 �ֱ����⡣���ط��������ٷֱ�ʱĿǰ��ϵͳ�ǿ����Զ�
  �л����Զ��ֱ������Բ������̫�����ʧ���������
  �ȴ�ʱ�䣬����������ʿ�������⣬�һᾡ������
7 ����suicide�Ĺ�ϵ�ȵ���ơ�����ڼ����Ϻ��м����ԡ�
  ����ϣ���ܺ�Ŀǰ�Ľ�ɫ�ڹ��ҵĹ�ϵ����һ�¡�ͬʱҲ
  ���Կ��Ǽ����ɫ�Ը�Ĳ�������������һ������Ŀ��
  addoil suicide :)



---
����: Ice
��Ŀ: >about war
����: Sun Aug 20 00:53:01 2000
On Sun Aug 20 00:14:17 2000 ����(group) wrote post #1779:
> when the war begins, there should be a time limit for
> defender finish his fenbing, otherwise there will be no end 
> for the war. and when attacker waiting for the defender enter,
> there should no drop for shiqi.

support group... players complained about this, hmm, but i remember
fire said there is time limit for defence party arrange troops and during
that period, morale won't drop...

well, if it's really the same as players said, i think we need to do
the following:
1. defence party have to finish arrange troops in 8 mins, that means half day
in mud, meeting the due system will take over the arrange job and arrange as
soon as it can.
2. b4 denfence party enter warfield, attacking side's morale won't drop.


---
����: ����(group)
��Ŀ: about war
����: Sun Aug 20 00:14:17 2000
when the war begins, there should be a time limit for
defender finish his fenbing, otherwise there will be no end 
for the war. and when attacker waiting for the defender enter,
there should no drop for shiqi.


---
����: Suicide
��Ŀ: >>about anti-robot
����: Sat Aug 19 19:46:16 2000
��.������һ��ʵ�ʵ�����Ͽ��е���.
admire


---
����: Emperor
��Ŀ: >about anti-robot
����: Fri Aug 18 06:39:48 2000
������robot,��һ����
�벻������������˵ķ���̫���ˣ�xixi



---
����: Ice
��Ŀ: >about anti-robot
����: Fri Aug 18 05:29:15 2000
hoho, if i know how to make a totally auto robot, i won't always try to
do repeating jobs by hands. i think change robot question is one of the
ways, another way is making more fun jobs, though it's a hardly achieved
goal...


---
����: ����ү(suicide)
��Ŀ: about anti-robot
����: Fri Aug 18 01:11:22 2000
�����zmud��robot����̸��һ����,�����ҵ���anti-robot�ķ���.
�����������еĻ����˻ش����ⶼ������ٷ�������,��ô�Ը����ķ�������
���ǵ�����ÿ��һ��,��Ҫѭ��,�Ǿ�ok��.�ҿ���һ�����ڵ�robot���Գ���,����
��sentence�в��Ե��ֵĳ���Ϳ����ֳ�����,����ֻҪÿ��ʹ�ò�ͬ�����
��Դ�ļ��Ϳ�����.
������ҿ���������һ���򵥵ĳ���,���һ����Ӵ��С˵�������ѡȡƬ�ϲ���������
�ϴ��Ϳ�����,�����������Զ�����ظ���.

��Ȼ,�Ҳ���˵��ֹһ��robot,��ֻ�������robot��ʹ�÷���,���������Щ
��Ҫde 
job���ò�Ӧ�������ʹ��robot���ǾͿ���ʹ������Ĳ��Գ�������һش�,
�������Ϳ��Կ�������,����������Ϊ��ҿ���ʹ���ҿ��Լ�����Ҹ�����job
robot ���ǾͿ��Բ�ʹ�����ֲ��Գ���.
robot ���ǾͿ��Բ�ʹ�����ֲ��Գ���.

��֪����Ҷ������ʲô����,��෢��,���ͬ���Ҿ�д�Ǹ��������Ƭ�ϵĳ���,
����ϣ�����������Щ��������Ӧ�ÿ������ʹ��robot,�Һ���һ���ĸ���.


---
����: ����(group)
��Ŀ: about the jimou
����: Fri Aug 18 01:05:34 2000
beside longer the duration, there is another way,
which is to increase the use of jingsheng for cast.
now the lv 1,2,3,4 jimou cost jingsheng is
15,20,25,30. 
ice, please summarize it and give me a plan for the cut, the duration
are list in info jimou. 
commonly player have around 200-250 jingsheng, highest condition 
is around 390-400


---
����: Suicide
��Ŀ: >>>to group
����: Thu Aug 17 22:24:23 2000
�������ǵ�Ŀ����:
��Ҫ���ͼ�ı��Ч��,������һ��кܴ����,�������ǿ��Դ���������Ŀ�ʹ�ô���.
������������һ��ս���������4��,��Ȼ����Ҫ��ҵ�ĳ��ֵΪ100.grin


---
����: Row
��Ŀ: >>to group
����: Thu Aug 17 21:27:19 2000
there should be time interval for 2 cast of different jimou.


---
����: Suicide
��Ŀ: >about relation
����: Wed Aug 23 18:32:40 2000
I am considering about it.


---
����: ����(group)
��Ŀ: about relation
����: Wed Aug 23 04:33:52 2000
suicide �Ĺ�ϵϵͳ�൱��Ȥ�����˾����Ǻ��б�Ҫ�����ġ���
�ض�Ԫ���õ����⣬�ƺ�������һ�����㹫ʽ�������
�ͺñ�����������ԣ������Բ����������ϵ��
�������������ϲ������������ÿ������ڽ������ϵ�
ʱ��Ӿ��ֻ���ϲ����ѡ�����֣�Ȼ�����������ϲ��
�������ֵ--��ϵͳԤ���趨��Χ�趨���ٽ��м���
��ȷ���ۺϵ���ֵ��NPC��������ѡȡ���֣���ȻҲҪ
ע��NPC�������ʷ������ù���Ǯ�������ƺ�˵��
��ȥ����һ������ֵ��������仯���ڼ��㽻���ɹ���
��ʱ���ټ����ϵ�Ⱥ��ˡ�



---
����: ����ү(suicide)
��Ŀ: bug of whisper
����: Tue Aug 22 22:43:51 2000
������˼ԭ��û�кʹ�ҽ������,����whisper������,
��Ϊ����whisperֻҪѡ1 2 3 4�Ϳ��Խ��ܶ��ҳ�, ���Դ��
����whisper job��ʱ��Ҫ����һ��,����ǽ�����macro����
�����whisper job,�벻Ҫѡ1 2 3 4 , ֱ��ѡ10�Ϳ�����,
������õ�robot��ÿ�θ�������. лл.

<����ת��maggy���� board>
�Ҽ����һ��code,��һ��Сbug,���ڽ����


---
����: ����ү(suicide)
��Ŀ: To stefan about cq site
����: Tue Aug 22 21:25:41 2000
����:  ����(rainm)
��Ŀ:  to suicide
----------------------------------------------------------------------
���Ѿ���������ϵ�ˣ��������ṩserver,����ܹ��ɹ�
��֪��suicide �Ƿ�ͬ��open new site? �������е�cq id ת����վ��
               ------------ rainm


---
����: ����ү(suicide)
��Ŀ: Re fire about relation_d
����: Tue Aug 22 21:10:33 2000
1 One thing is not clear, is the relation only one way realtion, which
  is from npc to a player. or a two way relation between any chars.
RE:It is a two way relation between any chars.
  
  
2 If it is a two way relation. does the relation A->B equals B->A, if it
  is this case, when we add relation, we need adjust both files. but it
  is good for quiring. For example, if I want to check my relation to
  several npcs, I don't need to load all those npc's relationship files
  I only need to load my relationship file and get the whole result.
  I think this can save lot's spaces.
RE: I have modified the code by add a new function called:
    add_both_relation(id1,id2,add)
    now it runs like this lah.
  
3 I suggest once the relation drop to zero, that record should be removed
  from the relations, this can save space.
RE:I have modified the code ,now it runs like this lah.
  
  
4 Maybe we can add a auto clean function. all the relations keep dropping
  if the player doesn't play. once his relationship with one npc drop to zero
  we can clean a record from both his relation file and that npc's
relationship
  file. the method can prevent the whole relationship growing without control.
RE: Can we consider about this later for coding such a functon will be so
    technical ,we should consider deeply about it. I think the most important
    thing now is to plan how make this relationship into apllication.:)
    
  
  
5 The last is only a small one, There is a function called implode which can
  concatenate strings from an array, it is oppersit to explode. 
RE:I have used exploade function in my code lah,but implode is not used.


---
����: Suicide
��Ŀ: >����relation_d
����: Tue Aug 22 19:20:09 2000
I will consider about this.

BTW: ice, i have added no attack in fly room. Now both fly room and
meeting room
     can't attack lah..


---
����: Stefan
��Ŀ: >to stefan
����: Tue Aug 22 18:36:37 2000
On Tue Aug 22 18:09:32 2000 ����ү(suicide) wrote post #1807:
> Cq mirror's local admin want to close my mud for system resource lack.
> Can u communicate with xyx to get a idea how to settle those guys
> playing in cq mirror
> All put them to zj site?

actually chengdu guys are contacting me to set up 
mirror. I think I will negotiate a mirror transfer.
But not sure yet.


---
����: ����ү(suicide)
��Ŀ: to stefan
����: Tue Aug 22 18:09:32 2000
Cq mirror's local admin want to close my mud for system resource lack.
Can u communicate with xyx to get a idea how to settle those guys
playing in cq mirror
All put them to zj site?


---
����: ����ү(suicide)
��Ŀ: cq site will close
����: Tue Aug 22 17:49:46 2000
suicide��ã�
    �����Ǹ��ܺõ�mud����˼��ӱ����ƶ�������������MUD���¼�Ԫ��
    ϣ��������������ߵĴ������������ĵ�Ӳ�̿ռ���ڴ�ռ��Ѿ�
Σ������WLZB������WLZB����Ҳ������ӣ�SGZҲ�ڲ��ϵ����͡����ڷ�
����������Դ��ʣ�޼���
    ���Ҹ��˶���ϣ��SGZ��һֱ����ȥ��������������ԭ���Ҳ��ò�
����ʹ��ľ������ر����������վ���봦���ƺ����ˣ���֪ͨ�Ҿ���
��վʱ�䡣
    ��Щʱ�����Ǻ����ǳ���죬ϣ���л����ٴκ�����


---
����: �һ�(fire)
��Ŀ: about heart_beat
����: Tue Aug 22 17:16:18 2000
I commented that code according to suicide's suggestion.
so to check if can fight will start from the cmd
not from the fight itself, this maybe a good idea. but becareful :)


---
����: Fire
��Ŀ: >to fire
����: Sun Aug 27 16:23:20 2000
On Thu Aug 24 19:19:56 2000 ����ү(suicide) wrote post #1821:
> fire:
>   add a time limit bah when defence side arrange troop,or when war
> defence side
> will ����ʱ��.

Now there is a time out for each input, seem we still need a time
for the whole process. I will modify it. addoil :)


---
����: ����(ice)
��Ŀ: about wiz.committee
����: Sun Aug 27 07:42:07 2000
no one go wiz.committee to give opinion of promoting chun?


---
����: ����ү(suicide)
��Ŀ: about whisper job
����: Sun Aug 27 06:52:33 2000
�����whisper����һ���޸�,�뷨����:
1,2,3 de 
1,2,3�Ĺ�ά�츳��ѡ��ֻ��npc���츳�ҹ�,�������ҳ��޹�.
6,7,8���ж���������һ����,�����ظ�,��׼���޸�����һ��������в
Ϊ��ϥ̸��,�ж�������˫�����Ը����ֵ.

��֪����к����?
�������Ѿ��������Ը��������,�Ұ���ice����˼���˸�"����(bazi)"������id.
@ CHAR_D->get_char("suicide","bazi") ��Χ��ʱ��1-100,�����ɫ��û�и�
ֵϵͳ���Զ���ʼһ������.


---
����: Stefan
��Ŀ: >To stefan
����: Sun Aug 27 05:03:46 2000
On Sat Aug 26 07:24:01 2000 ����ү(suicide) wrote post #1825:
> It is so strange that when mirror reboot ,always some files
> corrupt,thus they can't be used
> Cause a lot of bug,can u check why?This condition has appear for some times.
> Now even i am afraid of rebooting at mirror.

But I think I've fixed this bug? For unknown reasons, some
files on our main server concerning mirror setup always
get corrupted :PPP I've added some fix to it, not sure ihow well it works
now...


---
����: ����ү(suicide)
��Ŀ: To stefan
����: Sat Aug 26 07:24:01 2000
It is so strange that when mirror reboot ,always some files
corrupt,thus they can't be used
Cause a lot of bug,can u check why?This condition has appear for some times.
Now even i am afraid of rebooting at mirror.


---
����: Stefan
��Ŀ: >to stefan
����: Fri Aug 25 21:53:48 2000
On Wed Aug 23 23:27:27 2000 ����ү(suicide) wrote post #1816:
> One guy in cq mirror want to apply a server to transfer all data
> there,if cq mirror will close
> ,stefan,would agree this sute?
> ��Ŀ��about apply mirror 
> ---------------------------------------
> ����������Ĺ���վ��SUN U1
> �Ҹտ����й�������mirror site apply ,������Solarisѽ
> sun ����վװ����linux ,������solaris û����ɣ�
> ��suicide ���ǣ�����Ҳ����ߣ���ȥcq վ��zhenzhue ����guoyi������
> ��л�ˡ�thank suicide
>  ----- rainm

We can not support Solaris currently, because the old
machine was removed :PP


---
����: Ice
��Ŀ: >sth about suggestion
����: Fri Aug 25 04:22:02 2000
On Fri Aug 25 00:14:05 2000 ����ү(suicide) wrote post #1822:
> �����ҷ�����Щ��ң��ڶ�ʱ����ͨ��localmeeting��localtax ��sendfood
> �����honour,�������Ƕ�suggestion��������һ��һ�������21�����飬
> ��ô�������ں̵ܶ�ʱ���ڻ��4k honour,���Բ�֪����Ҿ������費��Ҫ
> ����һ�£��Ѷ��˵����ƸĳɶԵ��������ƣ�Ʃ��ĳ��һ��ֻ����21������
> �����ô����

i think 10 per person, and 20 per area will be fine.:)
however, the actual limit of 10 will be 11, also 20 will be 21.:P


---
����: ����ү(suicide)
��Ŀ: sth about suggestion
����: Fri Aug 25 00:14:05 2000
�����ҷ�����Щ��ң��ڶ�ʱ����ͨ��localmeeting��localtax ��sendfood
�����honour,�������Ƕ�suggestion��������һ��һ�������21�����飬
��ô�������ں̵ܶ�ʱ���ڻ��4k honour,���Բ�֪����Ҿ������費��Ҫ
����һ�£��Ѷ��˵����ƸĳɶԵ��������ƣ�Ʃ��ĳ��һ��ֻ����21������
�����ô����


---
����: ����ү(suicide)
��Ŀ: to fire
����: Thu Aug 24 19:19:56 2000
fire:
  add a time limit bah when defence side arrange troop,or when war
defence side
will ����ʱ��.


---
����: ����ү(suicide)
��Ŀ: what's wrong?
����: Thu Aug 24 19:18:44 2000
 61                               *** �ʼ���ʧ�� ***
 62                               *** �ʼ���ʧ�� ***


---
����: �һ�(fire)
��Ŀ: please read post in
����: Thu Aug 24 16:15:36 2000
wiz.committee
it seem you can't auto read it if use news
hoho :)


---
����: Suicide
��Ŀ: >about attack
����: Wed Aug 23 23:39:13 2000
If changing code like u said ,it will be a large work,so trouble.
So can we just let it be? If some guy abuse using this then i try to 
limit it ,ok?


---
����: ����ү(suicide)
��Ŀ: my idea
����: Wed Aug 23 23:35:41 2000
���������job��Ч������ҵ�ĳ��ܹҹ�,���ǳɹ��ʵĹ�ʽ����.
����newbie����dummy��job����Ч�ͻ᲻��,���ǻ��ܳɳ�,�������ٹ���dummy��Σ��
��֪�����ʲô���?


---
����: ����ү(suicide)
��Ŀ: to stefan
����: Wed Aug 23 23:27:27 2000
One guy in cq mirror want to apply a server to transfer all data
there,if cq mirror will close
,stefan,would agree this sute?
��Ŀ��about apply mirror 
---------------------------------------
����������Ĺ���վ��SUN U1
�Ҹտ����й�������mirror site apply ,������Solarisѽ
sun ����վװ����linux ,������solaris û����ɣ�
��suicide ���ǣ�����Ҳ����ߣ���ȥcq վ��zhenzhue ����guoyi������
��л�ˡ�thank suicide
 ----- rainm


---
����: ����(ice)
��Ŀ: about attack
����: Wed Aug 23 19:24:40 2000
I think attack now is just like fight b4, can fight inside and
outside, and can also attack npc to gain exp. I think it's just
erasing the effort of fight.
the effort of fight is:
1. fight npc to gain exp.
2. cannot fight in indoor room.
3. fight online player will need opponent's agreement.
I think attack should not be the same as fight, so i have
2 alternative suggestions:
1. attack is only can be used in jail room, and the attackee must
be caught by sb, so the meaning of attack is like ���̿���.

2. make attack cannot gain exp anyway, and also it'll be better
can only attack others in the attacker's own area. socall his
��ͷ�����Ժ����޼ɡ�


---
����: Fire
��Ŀ: >�������ݰ��������NetXray.
����: Thu Oct  5 18:03:22 2000
On Thu Oct  5 06:46:37 2000 �Ƶ�(emperor) wrote post #10008:
> �����¡���ͼ�β���������ping���ٶȲ�������£������ٶ�Ҫ��KK����ˡ�
> ֻ�������ͼƬframe����̫�٣�����û����KK����������ħ��Ч����������о�
> �ȡ����ڽ���������ǿ��ࡣ�����¡���KKҪ������ֻ������ûKK�ĺã����ݲ߻�
> �Ե��������¡�ͼ��MUD�Ŀͻ��˻��������ȡ֮���ġ�
> �ø�HEX�ļ��༭������tx.exe���ܿ����ͻ�����Ƶ�������ݡ�

thanks ;P


---
����: �Ƶ�(emperor)
��Ŀ: DirectX7.0a�Ǹ��ö�����
����: Thu Oct  5 06:56:03 2000
DirectX7.0a֧��Visual Basic�����ظ�����SDK�������溬��
��ϸ��VC��VB�İ����ļ���
��VB���ͼ��MUD��client������Ҫ��VC�ļ򵥡�������������ϸ
�Ķ�directX��VB�����help��
����Ȥ�Ŀɿ�����


---
����: �Ƶ�(emperor)
��Ŀ: �������ݰ��������NetXray.
����: Thu Oct  5 06:46:37 2000
�����¡���ͼ�β���������ping���ٶȲ�������£������ٶ�Ҫ��KK����ˡ�
ֻ�������ͼƬframe����̫�٣�����û����KK����������ħ��Ч����������о�
�ȡ����ڽ���������ǿ��ࡣ�����¡���KKҪ������ֻ������ûKK�ĺã����ݲ߻�
�Ե��������¡�ͼ��MUD�Ŀͻ��˻��������ȡ֮���ġ�
�ø�HEX�ļ��༭������tx.exe���ܿ����ͻ�����Ƶ�������ݡ�


---
����: �һ�(fire)
��Ŀ: help suicide.
����: Wed Oct  4 23:09:02 2000
hi suicide,
I find a piece interesting vc code on the internet
the url is http://tech.sina.com.cn/soft/2000-09-28/778.html
but when i test it, I find it miss some part and I don't
know how to fix it. When you have time, could you please
try this and if you can fix the problem, please email me
a copy. hoho :)

Regards,



---
����: Fire
��Ŀ: >>һ������ͼ��MUD
����: Wed Oct  4 21:02:02 2000
I played it. 
It's not too bad, only the movement is a little bit slow
compared to diablo, the play is not so fluent.


---
����: Stefan
��Ŀ: >һ������ͼ��MUD
����: Wed Oct  4 19:16:45 2000
On Wed Oct  4 08:07:01 2000 �Ƶ�(emperor) wrote post #10003:
> �����컨��7��Сʱ��http://www.21cntx.com������
> ����ͼ��MUD�Ŀͻ��ˡ�����������7��8��Сʱ��ͬʱ����
> �����MUD��ͨѶЭ�顣���MUD�ӽ��������ʼ��ƣ�����
> 9���µ�ʱ�����ɵ�Ч��������֮����࣬������һЩ���
> �������MUD�����Ǵ�������ʾ�ܴ�ֵ��ȥ��������������
> ����������MUD������ͨѶЭ�顣�������ǻ��ü���ѽ��

I played it about two weeks ago, but the site was directing me to
netease.com :PPPP

Anyway, it is not an very interesting mud, graphics is the
worst compared to KK and SanGuo.


---
����: Fire
��Ŀ: >һ������ͼ��MUD
����: Wed Oct  4 15:52:47 2000
On Wed Oct  4 08:07:01 2000 �Ƶ�(emperor) wrote post #10003:
> �����컨��7��Сʱ��http://www.21cntx.com������
> ����ͼ��MUD�Ŀͻ��ˡ�����������7��8��Сʱ��ͬʱ����
> �����MUD��ͨѶЭ�顣���MUD�ӽ��������ʼ��ƣ�����
> 9���µ�ʱ�����ɵ�Ч��������֮����࣬������һЩ���
> �������MUD�����Ǵ�������ʾ�ܴ�ֵ��ȥ��������������
> ����������MUD������ͨѶЭ�顣�������ǻ��ü���ѽ��
����ͨ��Э����ʲô���ģ��ܲ��ܼ򵥽���һ�¡�
���⣬��ʲô���߿��Խٻ�һ�����ͨ�ŵ�����
�������
��������:)


---
����: �Ƶ�(emperor)
��Ŀ: һ������ͼ��MUD
����: Wed Oct  4 08:07:01 2000
�����컨��7��Сʱ��http://www.21cntx.com������
����ͼ��MUD�Ŀͻ��ˡ�����������7��8��Сʱ��ͬʱ����
�����MUD��ͨѶЭ�顣���MUD�ӽ��������ʼ��ƣ�����
9���µ�ʱ�����ɵ�Ч��������֮����࣬������һЩ���
�������MUD�����Ǵ�������ʾ�ܴ�ֵ��ȥ��������������
����������MUD������ͨѶЭ�顣�������ǻ��ü���ѽ��


---
����: Group
��Ŀ: >>about news_d
����: Wed Sep 27 01:17:22 2000
that is not bug lah, rRfFis only for the post you read, so
not necessary to appear before you read any post.


---
����: Ice
��Ŀ: >about news_d
����: Wed Sep 27 01:06:14 2000
(wiz.com:1851) 201 ������ 1 ��δ�� [q?lLmgpnc] > 
//it's b4 I read this post...
(wiz.com:10000) 0 ��ʣ�� [q?lLmgprRfFncMD] > 
//it's after... still some bugs mah
addoil


---
����: �һ�(fire)
��Ŀ: about news_d
����: Wed Sep 27 00:42:06 2000
I make some modification in news_d
the two big part is
1 use a new mapping to hold the last id, it is better to use the group
  to host last id
2 i find the time to save the whole post is not too much so 
remove the function of save recent. it make the program too difficult
to read.



---
����: Suicide
��Ŀ: >about farm news
����: Thu Sep 21 19:45:55 2000
agree with fire.
every updateing area_d.c will cause the areas turn changed maybe.
In my npcai_d.c , i keep a log of all areas in data file,
so its turn will never changed.


---
����: �һ�(fire)
��Ŀ: about farm news
����: Thu Sep 21 19:09:31 2000
I think that bug may come from area d
in area_d it has a function to retrieve an area id.
this list may be affected by some other program so some times an
area can't be retrieved
or some area has been retireve more than one times during one rand.
in order to solve that problem. we can update area_d.
but why that list is affected is still mysterious.
hmm


---
����: ����(group)
��Ŀ: bug in farm
����: Thu Sep 21 00:55:55 2000
as templar reqest, i can be vitness that changan farm's ganjing drops
extremely fast. as i saw at 2:40 this afternoon, it is 100, when i saw it
at 3:40, it becauses 28.

please check check bah... i looked the code and cant find where is
the place...:P

addoil

group


---
����: ˹̹��(stefan)
��Ŀ: bug
����: Wed Sep 20 23:37:13 2000
��Ŀ�������Ƿ��˰�ش󺰣����ˣ�ȫ���ˣ� 
---------------------------------------
changan farm has bug again, like the previous one in noise's taiyuan last
generation
�ĸɾ�has no use
now we get back hanzhong, otherwise changan xiangyang 100K footman will starve
to death
i have told group, ice but still no response
pls check and help to solve this bug
beg
bow
                                      templar


---
����: ����ү(suicide)
��Ŀ: about ʤ������
����: Wed Sep 20 17:09:52 2000
��˵��������������Ҫɱ���з�ȫ������̫������.
��˵����Ӧ�ù����ǽ����ʤ��
��Ǻǵ�Ц�˼�����
����˵���������������
>����˵����ɱ2/3������ռ���о���ʤ��


---
����: ����ү(suicide)
��Ŀ: about tune gold incoming
����: Wed Sep 20 16:30:18 2000
����˵����4������,���˿�������������15000
����˵��������Ϊ5000,�ͺܳԽ���
����˵������Աũ��ռ1000
����˵�ͷ��
����˵����ʣ��4000��40000��,����ֻ�÷�չ��ҵ


---
����: �Ƶ�(emperor)
��Ŀ: ?
����: Sun Sep 17 08:30:57 2000
��lima���������ݿ���ô���������Լ������ϳɹ�������MUDOS+mSQL.


---
����: �һ�(fire)
��Ŀ: sorry about the post
����: Fri Sep 15 00:45:32 2000
this week really no time.
I will do it next week.
sorry to all


---
����: Stefan
��Ŀ: >the web server
����: Thu Sep 14 21:01:49 2000
oops, that was a mistake, I've put it back :PPP


---
����: �һ�(fire)
��Ŀ: the web server
����: Thu Sep 14 17:57:55 2000
now i find the www.gime.org and sgz.gime.org direct to the same place
so where is the sgz's main site ?


---
����: �Ƶ�(emperor)
��Ŀ: graphical mud
����: Wed Sep 13 03:15:55 2000
ʯ��ʱ���� www.waei.com.tw
���������� www.chinesegamer.net
���ڽ����� www.gameking.net.cn/rzjh-new/
����֮���� www.kok.com.cn
����    �� www.lineage.com.tw
�������� www.station.sony.com/everquest/
Asheron's Call ��www.microsoft.com/games

��www.waei.com.tw�����ҵ�����ͼ��MUD������

����һЩ����


---
����: ˹̹��(stefan)
��Ŀ: to emperor
����: Tue Sep 12 21:58:18 2000
please post those graphical mud address again, thanks!!


---
����: �һ�(fire)
��Ŀ: about posts
����: Tue Sep 12 17:11:28 2000
hi all,
I find that our news sysem is really sucked
I will rewrite the news_d and make it clear in this week
cheers


---
����: Ice
��Ŀ: >addoil suicide and chun
����: Wed Aug 30 17:13:55 2000
On Wed Aug 30 15:58:29 2000 �һ�(fire) wrote post #1836:
> make the gini more fun and useful. hoho :)

addoil addoil.:) 


---
����: �һ�(fire)
��Ŀ: addoil suicide and chun
����: Wed Aug 30 15:58:29 2000
make the gini more fun and useful. hoho :)


---
����: ����ү(suicide)
��Ŀ: to ice
����: Tue Aug 29 23:54:23 2000
I check the file of /log/help_miss,then i know u had faq ���� ....
So i have added a hint of ����, u can check again.
From this u can know how the gini helper works.
:)


---
����: ����ү(suicide)
��Ŀ: about ���ְ�������
����: Tue Aug 29 23:33:37 2000
���ְ�����������޸����.
Ϊ�˷����������ţ��ر�����ЩӢ�Ĳ�����֣�chun������fire�ľ���ϵͳ
������һЩ�Ķ�����������ڵ����ְ������飮
����: ÿ��һ��ʱ�䣬�����Զ��������������˵��ʾ��Ϊ�˷�ֹflood����
����  �Ѿ�����������������ڻ�������������һ�Σ����ҳ��˾���Ķ�����
�������������е���ʾֻ�о���������ܿ�����������Ϊ�˰���Ӣ�Ĳ��õ���
�������Ҳ���help���ص�������һ��gini faq�Ĺ��ܣ����ǰ�һЩ����̸֮��
���������ľ䱣����gini_d��hints �У�������������ͼ��������ʱ�ͻ��ȴ�
������sghelpϵͳ�в��ң����û���ٴ�hints�в������޶�Ӧ�ĵ��ʣ������
��������Ѷ�Ӧ��hint������ʾ������������߶�û�в鵽��������ͼ���ҵ�
����������ᱣ����/log/help_miss�У�����������ʦÿ�����߿��Բ������
������log �ļ����������Ӷ�Ӧ��hint��gini_d�У���������hints �Ĳ�����
�����������ǵľ���͵������˰��Զ�ѧϰ���ܣ������ܹ�Խ��Խ��Ч��������
������������������������Ӧ��help��
Ϊ�˰����hintѧϰ������˵��������ھٸ����ӣ�
    ���������и�Ӣ�ĺܲ����������������mud �������ȿ�����֪��Ǯ����Դ��
����������֪��Ǯ��Ӣ����money ����ô���϶����޷���help money���������
Ҫ�õ�����Ϣ���������������þ��� gini faq Ǯ  ����ѯ�������ǵ�hints ��
���Ѿ�����������һ�
���������mud�ϵĽ�Ǯ�����֮�䲻�ܻ�����룬ֻ�ܿ��Լ������������Ժ���
����нˮ����ϸ�������Բμ���help money   help job  help basicjob��
    ��ô��������Ǯ�����������仰�п��Եõ�ƥ�䣬�������hint�ͻ���ʾ
����ң���ͬʱҲ��֪��������help money help job help basicjobȥ��ø���ϸ
����Ϣ�ˣ�
    ����������������� gini faq ʳ������ǵ�hints ��û���й�ʳ������
����sghelp��Ҳ��Ϊ����������϶��޷���ã����Ǿ���ͻ���ʾ��
    "���ˣ������ҵĶ�����Ҳ��̫��Ŷ�������ҿ��԰�������ʦ��
    "�������´����ߵ�ʱ��Ϳ���֪����."
    
����ͬʱ��¼һ��ʧ�ܲ��Ҽ�¼��/log/help_miss �ļ��в���ͬʱ������announceƵ
���У�����������ʦ�Ϳ�������һ���µ�hint:
    "ʳ����Ҫ�ǿ�Ǯ��ģ�����û��Ǯ��ʱ������һ�����ĳ���Ҫ(ask chu niang 
     about food )�����⵱���Ժ�����ٷ��˲ƻ����Թͳ�ʦ����������ϸ�������
     �μ���help 
    
������������hints �Ĳ������������ǵľ���Ϳ��Ի����ϻش����ִ�������⣮
˵�������ھ���ϵͳԭ������ҿ��ŵ�һЩ�����󣺸����������͡���������µȵ�
�������Ҷ���ʱ��ֹ�ˣ���Ϊ��Щ�������ְ������鶼�ò��ϣ���׼���ڳ���ϵͳ�Ķ�
����������չ��Ŀʱ��½��������Щ���ܸ���ң�����������һЩ��Ȥ�Ĺ��ܡ�������
���������ڻ���ֹ��Ұ����ְ������������������ô�Ҹ�Ķ��Ǿ��顣���Ժ����
������ϵͳ����չ�п��Գ���������ƣ�����Ұѳ�����ؼң�û�¿��������������
����������Ϸ��;)
�������ͣ���chun��ƣ����ڸոռ��˸�С�����Ժ�ϣ��chun��½������һЩ��Ȥ�Ķ���
������è�����ġ���ӥ������ʨ�ӡ��ϻ����ߵȵȵȵȡ�
��֪��Ҷ�����ʲô�������ӭ������ţ��Һü�ʱ���ġ����û��ʲô������Ҿ�׼��
������µ�½����ҿ����ˡ�
������


---
����: ����ү(suicide)
��Ŀ: re chun about how to set multilines describe of gini 
����: Mon Aug 28 23:12:41 2000
if u want to set the setting of birth use like this :
"to gini addact birth" ,then just input multilines,it should be ok.


---
����: ����ү(suicide)
��Ŀ: about whisper
����: Sun Aug 27 21:37:05 2000
��"�߹��ջ�"�ĳ���"��ϥ̸��",�ж�������ɫ���Ը�������жϳɹ���.


---
����: ����ү(suicide)
��Ŀ: about whisper
����: Sun Aug 27 21:33:49 2000
��"�߹��ջ�"�ĳ���"��ϥ̸��",�ж�������ɫ���Ը�������жϳɹ���.


---
����: Row
��Ŀ: >>about create discussing group.
����: Sat Oct  7 08:50:54 2000
On Fri Oct  6 23:08:35 2000 Ice wrote post #10013:
> ice_sgz@elong.com
> 
> addoil suicide.:)
> 
> btw, I bought a �������� today, didn't try it yet, but I heard it
> need 2G HD space.^_*, anyone wanna try it, i can mail it away...
raise row
what's the basic configration of that game?


---
����: Row
��Ŀ: >about create discussing group.
����: Sat Oct  7 08:49:32 2000
my e-address: lau_roger@hotmail.com


---
����: Stefan
��Ŀ: >about create discussing group.
����: Fri Oct  6 23:08:55 2000
On Fri Oct  6 22:22:16 2000 ����ү(suicide) wrote post #10012:
> Hi! all guys:
>    I will create a discussing group for our wiz group in egroups.com.
> I need ur email address to make u be the member of this group.
>   Can u guys post ur own email address here ,so i will add it,
> then we can discuss problems just using email,even no need  
> login here to post .
>    I think it can improve the efficiency of our groups.

I created a group a long long time ago, was never used
by anyone. we can use that :P


---
����: Ice
��Ŀ: >about create discussing group.
����: Fri Oct  6 23:08:35 2000
ice_sgz@elong.com

addoil suicide.:)

btw, I bought a �������� today, didn't try it yet, but I heard it
need 2G HD space.^_*, anyone wanna try it, i can mail it away...


---
����: ����ү(suicide)
��Ŀ: about create discussing group.
����: Fri Oct  6 22:22:16 2000
Hi! all guys:
   I will create a discussing group for our wiz group in egroups.com.
I need ur email address to make u be the member of this group.
  Can u guys post ur own email address here ,so i will add it,
then we can discuss problems just using email,even no need  
login here to post .
   I think it can improve the efficiency of our groups.


---
����: Suicide
��Ŀ: >help suicide.
����: Fri Oct  6 03:14:00 2000
I will try to do this after the nation's holidays.


---
����: ����ү(suicide)
��Ŀ: To emperor
����: Thu Oct 19 18:38:50 2000
How about ur newbie system?
Andwhy not i can't hear ur voice in egroups?
I need ur help!!!!!!!!!!!!


---
����: Emperor
��Ŀ: >trainϵͳ����
����: Thu Oct 19 06:16:57 2000
agree suicide.
Ԥ�ȷֱ��кô�����Ӧ�ñ���һЩ�ɴ˴����������⡣


---
����: ����ү(suicide)
��Ŀ: trainϵͳ����
����: Wed Oct 18 18:46:48 2000
train�Ĺ���:
Ϊ��������,DIR��������:
   WAR    Ŀ¼=/sgdomain/event/war
   WARAI  Ŀ¼=/daemons/warai_d
   EVENT  Ŀ¼=/sgdomain/event
   DAEMONSĿ¼=/daemons
   LOCALMTĿ¼=/sgdomain/event/ev_localmeeting
   SGCMD  Ŀ¼=/sgdomain/cmd  
1 SGCMD/train.c start()����
2 LOCALMT/suggestion.c get_suggestion()����
3 EVENT/ev_localmeeting.c  meet_over()����
4 WAR/train.c train()����
  train()��������:
  a)  ����TT_TRAIN��task
  b)  ��ʼ��ս��log(WARAI_D->create_inf(t_num) ��WARAI/display.c)
  c)  ����ս����ͼ(MAP_D->add_city(p_area))
  d)  ����task�ĳ�ʼ����ΪTRAIN_BEG
  e)  ����train_arrange����(��WAR/train_beg.c),���ܼ��:
      e.1)������task�ĳ�ʼ����def_general_left����
      e.2)����def_pre_arrange����(��WAR/def_arrange.c),���ܼ��:
          e.2.1)�����趨task�еĳ�ʼ���Ӳ���,���ʱTT_WAR��task���������
5 ��TASK_D����train.c�е�train_process��������train��������:
  a)��һ��TRAIN_BEG:
    a.1)����train_collect����(��WAR/train_beg.c),���ܼ��:
        a.1.1)����task��def_general_left����,�����вμ�ѵ���Ľ����Ƶ���Ӫ
    a.2)����task�ĵڶ�������ΪTRAIN_PROCESS.
  b)�ڶ���TRAIN_PROCESS:
    b.1)�ۼ�task�е�curtimeֵ,�ò������ڼ��ѵ�������Ƿ�ʱ.
    b.2)����check_question����(��WAR/train_check.c),���ܼ��:
        b.2.1)���ѵ���и���������������ִ�����,�õ�����ֵ:
        b.2.2)���ݷ���ֵ,����ͬ�Ĵ���
              QUESTION_PROCESS:   ѵ����������ִ����,������ѵ.
              QUESTION_OVER_DUE:  ѵ��������ɳ�ʱ,�����µ�ѵ������
              QUESTION_FAIL:      �������δ����ս��,����TRAIN_END����
              QUESTION_SUCCESS:   ѵ��������ɳɹ�,�����µ�ѵ������
              NO_QUESTION:        ����û������,�����µ�ѵ������
        b.2.3)��ͼ�����µ�ѵ������,�ɹ�������TRAIN_PROCESS�׶�,��Ϊ����
              ѵ�������Ѿ���ɶ�����޷�������ѵ������,�����TRAIN_END
              �׶�
    b.3)question_new�����������(��WAR/train_new.c)���ܼ��:
        b.3.1)����ѵ�������������ø����������޶�ʱ��������йز���.
        b.3.2)��һЩ�ض����������͵���һЩ�ض������.
              ��һ��ѵ������ֱ�arrange����,����man_input(p_leader,t
ask_id,"d")
              ����(��/sgdomain/menu/warinput)
  c)������TRAIN_END�׶�:
    c.1)����train_over����(��WAR/train_over.c),���ܼ��:
        c.1.1)����release_army����(��WAR/abort.c),ɾ������troop object,
              ���Ҽ�¼�½����ͷ���˫����������.ɾ��ս����ͼMAP_D->
destruct_area(area);
        c.1.2)����task����AFTER_TRAIN����.
        c.1.3)���ѵ���������ɳɹ���ʧ�ܴ���,���ǰ���Ų�ֵ<=0,��
              �򵥵�ɾ����task��������ش�robot_test����,����big_reward
              ����(��WAR/train_over)����ѵ�������Ͳ���ѵ���Ľ���,Ȼ��ɾ
              ����task.
              
  d)���Ĳ�AFTER_TRAIN�׶�:
    d.1)����release_army����(��WAR/abort.c),ɾ������troop object,����
        ��¼�½����ͷ���˫����������.ɾ��ս����ͼMAP_D->destruct_area(area);
    d.2)ɾ����ѵ������.
  (ʵ���ϵ��Ĳ��ǲ��ɴ��,��Ϊ������TRAIN_END�����10���Ӳű�ִ��,��
   ��������ʹ��Ϊ�ش�ʱ���ɾ��task��Ҫ��ʱ��ԶԶ����10����,task��
   10���Ӳ�����ʱ���ڱ�ɾ��,���Ե��Ĳ������ɴ�,��������ɴ�Ļ�������
   ��Ϊ�������Ĳ�����ͼɾ��task�����³������bug)
fire,��֪������ķ�������ʲô��©�����ĵط�,������.
ice, ���԰����ռ��ռ�ƽ����ѵ�������Ļ�û�����bug��,������ϣ�����ڵ�
     һ����train������Ŀ�н����.
����trainϵͳ�������Ҳ���ʲô�Ķ�,����������������ڳ����еķֲ�λ��,
�ﵽ�׶�������Ŀ��,warϵͳ�����bug��������ֱ�ϵͳ,������������
--Ԥ�ֱ�ϵͳ,Ҳ����˵���ӵķ��䲻��սʱ��ʱ����,������ƽʱ�ͽ����ӽ�
�ڽ���ͳ��,���ȥ������������һ��,������ս��ʱֻҪָ������Ľ�������
��,��֪����������?


---
����: Stefan
��Ŀ: >>wiz site is created
����: Sat Oct 14 04:53:26 2000
On Thu Oct 12 19:25:26 2000 Suicide wrote post #10028:
> I can't login with id "suicide" ah,can u cp our data file their stefan?

problem solved, please try again :)


---
����: Suicide
��Ŀ: >wiz site is created
����: Thu Oct 12 19:25:26 2000
I can't login with id "suicide" ah,can u cp our data file their stefan?


---
����: ˹̹��(stefan)
��Ŀ: wiz site is created
����: Thu Oct 12 05:46:20 2000
on port 5454.

No player login, no new player registration. 

All please try, if you have problems, please let me know.


---
����: Suicide
��Ŀ: >>>>To fire
����: Tue Oct 10 17:44:08 2000
nothing.hoho.addoil.
BTW:Have u recieved my mail from egroups?


---
����: Fire
��Ŀ: >>>To fire
����: Tue Oct 10 16:53:54 2000
On Tue Oct 10 02:57:41 2000 Suicide wrote post #10024:
> I have put it in /wiz/suicide,named src.zip
I got it, thank you.
hoho:)
the problem i meet is I don't know splashwnd is inserted
by a predefined conmponent.
I think I should create a class of that. blash.

Thank you very much. xixi :)


---
����: Suicide
��Ŀ: >>To fire
����: Tue Oct 10 02:57:41 2000
I have put it in /wiz/suicide,named src.zip


---
����: Fire
��Ŀ: >To fire
����: Mon Oct  9 15:52:44 2000
On Sat Oct  7 21:31:52 2000 ����ү(suicide) wrote post #10017:
> Fire:
>     I have modified that code u told me to check,it runs ok now.
> I just modified serveral sentence.
>   There is a ���� in sentence :
>     strcpy(lf.lfFaceName,sFaceName.GetBuffer(sFontName.GetLength()));
>  *** sFaceName should be sFontName
>  *** And u should declare the function "DrawText() and WindowProc" 
>  *** in head file Splash.h,then everything will ok.
> 
> BTW: fire,just try bah,if u still have problem,just tell me,
>     I will mail u the source code.

Hi suicide
, the typo you metioned I know already but it still not working.
please send me your source code bah :)
xixi
thank
bow


---
����: ����(group)
��Ŀ: email
����: Sun Oct  8 22:51:54 2000
snow_zf@hotmail.com
sorry, a little busy recently


---
����: Row
��Ŀ: >>>>about create discussing group.
����: Sun Oct  8 22:07:42 2000
escape ice


---
����: Ice
��Ŀ: >>>about create discussing group.
����: Sun Oct  8 17:10:04 2000
kick row, u can buy it in ���� just for RMB 29 mah. I was talking to those
guys overseas...
nip
ps. I was meaning ordinary mail delivery, but not email...


---
����: ����ү(suicide)
��Ŀ: to all
����: Sat Oct  7 21:45:18 2000
���ʴ����û���յ��Ҹ���ҷ��ĵ�һ��egroups��mail?
���õ���finger���ǵõ���email��ַ��groupû�У����Բ����յ�


---
����: ����ү(suicide)
��Ŀ: To fire
����: Sat Oct  7 21:31:52 2000
Fire:
    I have modified that code u told me to check,it runs ok now.
I just modified serveral sentence.
  There is a ���� in sentence :
    strcpy(lf.lfFaceName,sFaceName.GetBuffer(sFontName.GetLength()));
 *** sFaceName should be sFontName
 *** And u should declare the function "DrawText() and WindowProc" 
 *** in head file Splash.h,then everything will ok.

BTW: fire,just try bah,if u still have problem,just tell me,
    I will mail u the source code.


---
����: ����(group)
��Ŀ: careful
����: Tue Nov 21 22:34:47 2000
today the guy who steal xiaobai and others passwd come and ask my passwd.
he pretend to be ˹̹��(ste)�ش��㣺С��
.... dont want to waste time on him, however please be careful 
sigh
oh, his ip is 61.136.141.81


---
����: ����ү(suicide)
��Ŀ: to stefan
����: Tue Nov 21 19:42:36 2000
Pls reboot bah when u login, it is a long time that it haven't reboot .


---
����: ����ү(suicide)
��Ŀ: about install auto arrangement
����: Fri Nov 10 20:49:33 2000
I have added a switch in new arrangement system to decide if a
area uses new arrangement system.

if @AREA_D->set_area(p_area,"arrange_type",1) then will use new system
else @AREA_D->set_area(p_area,"arrange_type",0) then will use old system


---
����: ����ү(suicide)
��Ŀ: auto arrangement system modified ok
����: Fri Nov 10 20:47:55 2000
�޸ı���:
def_arrange.c,//�޸��Զ��ֱ����㷨,ʹ��ﵽ���Ч��
train.c,        //��train_beg.c�е�void train_arrange(int task_id)
                //��������train.c��,���Ұ�����sort�μ�ѵ���Ľ���
def_meeting.c , //������sort�μ�ս���Ľ���
def_meeting.c , //������sort�μ�ս���Ľ���
train_beg.c ,   //ע�͵�void train_arrange(int task_id)����
def_input.c     //sort����,��֤�ֱ��Ĵ��򰴱���ID˳������.


---
����: Suicide
��Ŀ: >to chun
����: Sun Nov  5 17:11:06 2000
My english is not very well , if u don't get my meanings, pls tell me


---
����: ����ү(suicide)
��Ŀ: to chun
����: Sun Nov  5 17:10:08 2000
There r two function related things what we want to keep it when relogin.
One is set_is_keeping(1),this allow u will not auto drop this when u quit.
Another important one is no_give_npc(),this allow u will not auto give this 
thing to ur alternative npc when u quit, then this thing will be kept
in ur body object.
Thus when u relogin this thing will be kept. You can check these 2 functions
in /sgdomain/home/homekey.c

chat haven't finish yest.
You maybe think i haven't used these 2 funnctions ,why it works well ah?
Actually ur code doesn't work wellm let me explain it.
When u quit,u will auto give lamp to ur alternative npc,then u relogin,
for ur alternative npc object is still in, u will auto swap 
from npc to body,then lamp will transfer from ur npc object to ur body.
But if before u relogin, i dest ur npc object,then u relogin
u will find ur lamp will disappear, u can try it.

Your another question about "����ʾ���Ӷ���ʾ���" is that u should 
added some judge before set_id , for example :
private gini_type
if gini_type == "dog"  set_id("shao zi","����");
else set_id("gini lamp","���")

add_save("gini_type");
add_save("gini_type");

void set_type()
{
gini_type = xxxx
}


---
����: �һ�(fire)
��Ŀ: busy and busy
����: Thu Nov  2 23:48:42 2000
I will be very busy next month
a demo for December
so I may not come frequently
sorry all


---
����: С��(chun)
��Ŀ: I got it, suicide :)
����: Wed Nov  1 20:36:23 2000
Thanks very much to suicide :).
I have cleaned gini.o to remove a accidentally added void type.
I will use the test site for add more types, this really
make things easier to be done :).

chun


---
����: ����ү(suicide)
��Ŀ: to stefan
����: Wed Nov  1 19:19:49 2000
Hi stefan:
    Can u add a link dir here to connect the test site dir, then we
could easy 
move what we have modified from test site to main site.
   How do u think about it?


---
����: ����ү(suicide)
��Ŀ: to chun
����: Wed Nov  1 19:18:27 2000
I have added the writing right of /daemons and /sgdomain to u
Just check ,but more careful, if u meet some problem ,pls tell me.


---
����: Suicide
��Ŀ: >The gini ...
����: Tue Oct 31 22:34:44 2000
ok, i will open right for u in test site.
when u meet me online.


---
����: С��(chun)
��Ŀ: The gini ...
����: Tue Oct 31 22:08:40 2000
Bow :),
I wonder if I could get some write privilege on the gini files, which are
gini.o, gini_d.c, gini.c, it will be great if I can do some test on
it on the wiz mud ...
Maybe ... can I?....
Well, just asking ...
papaya chun
escape
thank
bow
mobai all


---
����: Suicide
��Ŀ: >I forget the ftp port No.
����: Tue Oct 31 17:54:40 2000
4999


---
����: С��(chun)
��Ŀ: I forget the ftp port No.
����: Tue Oct 31 06:51:48 2000
bow :),
Sorry, I already forget the ftp port no lah... anyone can
help tell me? 

Thanks :)


---
����: ˹̹��(stefan)
��Ŀ: Ban IP
����: Mon Oct 30 22:58:35 2000
All IP starting with 166.127 is now banned because of
fhj and asf's annoying behavior.

If you are so unlucky and from the same IP range, please email
me.


---
����: Suicide
��Ŀ: >Really sorry :( I am not reponsible
����: Mon Oct 30 17:53:51 2000
Actually,Warmly welcome u back first.:)
I miss u very very much.


---
����: С��(chun)
��Ŀ: Really sorry :( I am not reponsible
����: Mon Oct 30 13:53:27 2000
Hi,

	Sorry I haven't been here for quite a long time,
I am really not an responsible wiz. I guess I might not fit ...


---
����: Stefan
��Ŀ: >the I3 router got problems?
����: Tue Oct 24 04:38:46 2000
On Tue Oct 24 00:37:48 2000 �һ�(fire) wrote post #10035:
> can't communicate with mirrors. shrug.
I've updated main site's I3 server IP to 
point to the latest server. But seems all other mirrors are
still using old ones. They have not updated their lib :PPP


---
����: �һ�(fire)
��Ŀ: the I3 router got problems?
����: Tue Oct 24 00:37:48 2000
can't communicate with mirrors. shrug.


---
����: ����ү(suicide)
��Ŀ: to emperor
����: Sun Oct 22 17:48:13 2000
You said u would post ur plan about newbie system here,but i still
can't see ah...
addoil emperor!!!!!!!!!!1


---
����: ����ү(suicide)
��Ŀ: a little modification
����: Thu Jan 11 21:45:58 2001
modify the welcome login display.
give some comment to mirror players num.


---
����: ����ү(suicide)
��Ŀ: to stefan
����: Thu Jan 11 21:41:22 2001
Ϊʲô����cq mirror���Կ�����վ�ǿ��ŵ�,����վȴ������cq��վ?
����һ���ĸ�������Ҫ�޸İ�?


---
����: ����ү(suicide)
��Ŀ: to stefan
����: Thu Jan 11 21:16:10 2001
������־������ү(suicide)��i>����Ƶ�������㣺bad-channel: not
listening to imud_sgz


---
����: Suicide
��Ŀ: >row's article is pirated!
����: Tue Jan  9 18:30:16 2001
Maybe we can communicate with that publisher by this,
then we maybe can get help of advertisement for our new Graphic mud
with even no money need.
Isn't it a good idea?


---
����: ˹̹��(stefan)
��Ŀ: row's article is pirated!
����: Tue Jan  9 17:27:52 2001
A very new magzine called ������Ϸ featured our MUD and
row's article ���֮ս��

But seems the magzine never informed anyone of us.


---
����: ˹̹��(stefan)
��Ŀ: piger to be NPC
����: Wed Jan  3 02:42:45 2001
bite is asking for this, but I don't know how to do.
So if fire sees this, please help :)


---
����: Ice
��Ŀ: >>Season's Greeting!
����: Mon Dec 25 05:02:13 2000
On Sun Dec 24 21:09:59 2000 Suicide wrote post #10091:
> It is so long a time that we haven't recieved ur message ,what r u doing
now?
> Fire had come to sh ,but dunno how to contact u, it is so pity.
> )

ppy row was caught by ET from Mars in the past a few weeks leh bah..:P
Well, still in X'mas now, Merry X'mas and Happy another New century.:)
addoil all


---
����: Suicide
��Ŀ: >Season's Greeting!
����: Sun Dec 24 21:09:59 2000
It is so long a time that we haven't recieved ur message ,what r u doing now?
Fire had come to sh ,but dunno how to contact u, it is so pity.
)


---
����: ����(row)
��Ŀ: Season's Greeting!
����: Sun Dec 24 18:37:21 2000
Merry X'mas & Happy New Yeah to all u guys!


row


---
����: ����(ice)
��Ŀ: sorry for disturbing...:P
����: Sun Dec 17 16:33:56 2000
It's so nice to see u guys finally, and I felt guilty when I saw ur tired
faces...
Pardon me ......
Waiting for u guys' good news.
addoil


---
����: �Ƶ�(emperor)
��Ŀ: name
����: Fri Dec 15 05:23:56 2000
                    %^B_RED%^        %^RESET%^
                    %^H_WHITE%^��������%^RESET%^
                    %^ORANGE%^��¹��ԭ%^RESET%^
                    %^B_RED%^        %^RESET%^


---
����: �Ƶ�(emperor)
��Ŀ: name
����: Fri Dec 15 05:18:12 2000
                    %^RED%^        %^NOR%^
                    %^HIG%^��������%^NOR%^
                    %^YEL%^��¹��ԭ%^NOR%^
                    %^RED%^        %^NOR%^


---
����: Emperor
��Ŀ: >our mud's name
����: Fri Dec 15 05:13:42 2000
On Thu Dec 14 23:50:45 2000 ����ү(suicide) wrote post #10082:
> How about :
> ��������
> ��¹����
������
����־--��¹��ԭ


---
����: ����ү(suicide)
��Ŀ: our mud's name
����: Thu Dec 14 23:50:45 2000
How about :
��������
��¹����


---
����: �Ƶ�(emperor)
��Ŀ: gime̫�˷��ڴ棡
����: Thu Dec 14 21:06:29 2000
gime̫�˷��ڴ棡


---
����: Suicide
��Ŀ: >>>I will go to shanghai
����: Wed Dec 13 17:01:54 2000
U'd better contact me earlier as possible as u can,


---
����: Ice
��Ŀ: >>>I will go to shanghai
����: Wed Dec 13 07:34:11 2000
On Wed Dec 13 02:29:21 2000 Fire wrote post #10078:
> On Mon Dec 11 00:24:22 2000 Suicide wrote post #10076:
> > My mobile phone is 13901583882
> > office phone: (025) 5404463 �� (025) 5407271-260
> > Pls contact me if u reach shanghai .
> 
> I will stay in Shanghai for 1 day and Guangzhou for 1 day
> but the schedule may change in the last minuite
> anyway, I will contact you and stefan when I get there.

GZ for 1 day? hmm, I planned to go to SZ this weekend, if u
and stefan group flee r coming to gz, I dun have to take that trip.:P
my MP number is 13922231112, contact me when u fix the day.
ps. didn't I tell anyone here I lived in GZ?  ...:(


---
����: Fire
��Ŀ: >>I will go to shanghai
����: Wed Dec 13 02:29:21 2000
On Mon Dec 11 00:24:22 2000 Suicide wrote post #10076:
> My mobile phone is 13901583882
> office phone: (025) 5404463 �� (025) 5407271-260
> Pls contact me if u reach shanghai .

I will stay in Shanghai for 1 day and Guangzhou for 1 day
but the schedule may change in the last minuite
anyway, I will contact you and stefan when I get there.


---
����: ˹̹��(stefan)
��Ŀ: to emperor
����: Mon Dec 11 18:27:01 2000
The gime version you have is not up-to-date, please
check out the most recent version from sourceforge CVS.


---
����: Suicide
��Ŀ: >I will go to shanghai
����: Mon Dec 11 00:24:22 2000
My mobile phone is 13901583882
office phone: (025) 5404463 �� (025) 5407271-260
Pls contact me if u reach shanghai .


---
����: �һ�(fire)
��Ŀ: I will go to shanghai
����: Sun Dec 10 23:55:49 2000
hi row, how can I contact you.
and also suicide, maybe we three
can have a dinner together.
I think row is the landlord
so he may like to treat us. hoho :)


---
����: �Ƶ�(emperor)
��Ŀ: to stefan
����: Sun Dec 10 06:42:08 2000
���ڵ�BUG��:
creating table ... schema mismatch for zone daemon.emote, ([ /* 2 elements */
  "id":"varchar(32)",
  "rules":"blob"
]) vs ([ /* 2 elements */
  "id":"char(32)",
  "rules":"blob"
])
c:\gime\engine/module/drink.pike:26:Couldn't include file.
c:\gime\engine/module/food.pike:26:Couldn't include file.
c:\gime\engine/user/module/login.pike:54:Couldn't include file.
error execution query UPDATE object_room SET exits='?ke0a eastobject.room.l
iv
ing_room' WHERE id='wiz_room';
error execution query UPDATE object_room SET exits='?ke0a westobject.room.w
iz
_room' WHERE id='living_room';
done.
You may now run ./start.pike again to start GIME.

��room��object_room����update exits��ʱ����������quote_value(
([object.room.living_room]), z->schema["exits"] )���������⣬��֪��
��ʲôԭ��


---
����: �Ƶ�(emperor)
��Ŀ: to stefan
����: Sun Dec 10 00:29:47 2000
������95�����������gime�ˣ�����init_zoneʱ��daemon.emote��id������
���Ͳ�ƥ�䡣
��/engine/module/food.pike and /engine/moudel/drink.pike�е�include
<sgz/sgzdaemon.h>
��Ϊsgz/sgzdaemon.h�ļ������ڶ�����
�ͷ�����ЩBUG��


---
����: ����ү(suicide)
��Ŀ: about quarreling in caolu
����: Sat Dec  9 18:47:14 2000
For it is so silence these days,so i add some ����.
Now and so much posts in caolu,hoho.
I reached my aim,and i will keep silence le.
:)


---
����: �Ƶ�(emperor)
��Ŀ: to stefan
����: Sat Dec  9 04:02:17 2000
���ڿ�������mysql�ˣ����ڴ����������ݿ��ʱ����
error execution query SELECT * FROM class;
error execution query SELECT * FROM daemon_news__group;
error accessing daemon.news._group
Starting GIME done.
no matched zone table to store data for msg.user.module.login.welcome
no matched zone table to store data for msg.user.module.login.welcome
no matched zone table to store data for msg.user.module.welcome
no matched zone table to store data for msg.user.module.welcome
no matched zone table to store data for msg.user.welcome
no matched zone table to store data for msg.user.welcome

��֪���ǲ���windows operation system��Ե�ʣ����ڲ顣
��Ҳ���Ҳ�飬ok?


---
����: ����(group)
��Ŀ: name
����: Thu Dec  7 22:32:21 2000
��������Ϸ����.


---
����: Suicide
��Ŀ: >name
����: Thu Dec  7 01:10:50 2000
����������?


---
����: ����(group)
��Ŀ: name
����: Thu Dec  7 00:57:26 2000
hihihi, please consider a name for our new designed game..:P

push ice
push fire
push suicide
push emperor
push row
push push push

giggle


---
����: ����ү(suicide)
��Ŀ: to stefan
����: Tue Dec  5 16:49:46 2000
Need reboot lah,Can u promote me ?
For fire will not come here in a long time.


---
����: ����ү(suicide)
��Ŀ: replace new robot sentence txt files
����: Tue Dec  5 16:47:22 2000
This is all produced by the little program i have written.
Just random select sentence from my big txt download Dir.
:)


---
����: Emperor
��Ŀ: >to empoeror
����: Tue Dec  5 03:44:12 2000
On Mon Dec  4 02:47:51 2000 ˹̹��(stefan) wrote post #10064:
> I have to try it myself in order to debug :PPP
> My guess is, did you have test DB in your MySQL?
> You can try Pike command line, just type in:
> Sql.sql("mysql://localhost/test")
> and see what happens. It should return you an object.
> 
����������Թ��ˣ�����û��


---
����: ˹̹��(stefan)
��Ŀ: to empoeror
����: Mon Dec  4 02:47:51 2000
I have to try it myself in order to debug :PPP
My guess is, did you have test DB in your MySQL?
You can try Pike command line, just type in:
Sql.sql("mysql://localhost/test")
and see what happens. It should return you an object.



---
����: Emperor
��Ŀ: >to stefan
����: Sun Dec  3 03:48:09 2000
�Ұ�gime��start.pike��object db;��ΪSql.sql dbҲû�á�


---
����: �Ƶ�(emperor)
��Ŀ: to stefan
����: Sun Dec  3 03:45:43 2000
�Ұ�װ��Roxen 2.1.158�����кܳɹ���
�ҳɹ���add Sql module in Roxen,����ʾ
����mysql�ɹ���ͬʱ��ʾ�һ����ϵ�mysql�汾��
��������gimeʱ����mysql://localhost/testȴ����
����db object�����ܰ����ҵ��ؼ�������

������win95�ϰ�װroxen2.1�ģ�roxenû�κ����⡣

�ҿ���roxen�� server/modules/database/sqldb.pike
�ļ���ûʲô������롣

sqldb.pike�Ĳ��ִ������£�
  mapping sql_urls = parse_table(QUERY(table));

  string res = "";

  if (sizeof(sql_urls)) {
    res += "<table border=\"0\">\n";
    foreach(sort(indices(sql_urls)), string s) {
      Sql.sql o;

      mixed err = catch {
        o = Sql.sql(sql_urls[s]);
      };

      if (o) {
        res += sprintf("<tr><td>Connection OK</td>"
                       "<td><tt>%s</tt></td>"
                       "<td>%s server on %s</td></tr>\n",
                       Roxen.html_encode_string (s),
                       Roxen.html_encode_string (o->server_info()),
                       Roxen.html_encode_string (o->host_info()));
      } else if (err) {
        res += sprintf("<tr><td><font color=red>Connection
failed</font>: %s</td>"
                       "<td><tt>%s</tt></td><td>&nbsp;</td></tr>\n",
                       Roxen.html_encode_string (describe_error (err)),
                       Roxen.html_encode_string (s));
      }

����roxen��add modules�󣬳ɹ�������"Connection ok"



---
����: Emperor
��Ŀ: >to emperor
����: Sat Dec  2 03:23:27 2000
On Fri Dec  1 20:48:31 2000 ˹̹��(stefan) wrote post #10060:
> I've put it at http://www.gime.org/roxen-2.1.185-nt4sp6.exe
> 
> Not sure if it supports MySQL.
> I've not tried it myself.
thank stefan.


---
����: ˹̹��(stefan)
��Ŀ: to emperor
����: Fri Dec  1 20:48:31 2000
I've put it at http://www.gime.org/roxen-2.1.185-nt4sp6.exe

Not sure if it supports MySQL.
I've not tried it myself.


---
����: ����ү(suicide)
��Ŀ: ���ڹ�Ա��Ǩ
����: Thu Nov 30 21:07:19 2000
����ϵͳ������ҹ��Ĺ�Ա,�������ʸ��Ƿ���ʵļ��,
�Դ�,����׼����������ʸ��鹦��,�γ��ʸ񲻺�
���Զ���ְ��,�Դ˴����ʲô���,�뽨��?


---
����: �Ƶ�(emperor)
��Ŀ: to stefan
����: Mon Nov 27 04:33:05 2000
Roxen WebServer 2.1.185, 128 bit crypto, Windows NT 4.0 Service Pack 6 Binary
stefan,����汾֧��Mysql���ܲ��ܷ���www.gime.org��������
download.roxen.com���ٶ�̫���ˡ�
thx stefan.


---
����: �һ�(fire)
��Ŀ: hello all
����: Sun Nov 26 18:45:54 2000
havn't login for serveral weeks. really busy this moment
but it's lucky that my project progressed better even
than expected. 

I will goto Macro next month and may goto China as well
but not sure.

I think we may need a new admin here to manage this site
I am too busy to do that job.

anyway, I am very happy to find we are still running. 
addoil all.



---
����: ˹̹��(stefan)
��Ŀ: good website - for game designers
����: Thu Nov 23 22:30:45 2000
www.costik.com

This guy is a game designers, there are many interesting writings
concerning multiuser games and games in general.

A very good one is "I Have No Words & I Must Design" under his 
writing page.  It talked about what makes it a game, and the important
aspects of a good game. One point very relavant to us is that
in our MUD, after the great tension period where there are three equally 
strong countries, there isn't much tension when one country has
the obvious advantage to beat all others. This is why everyone
is asking to restart even when no one unifies the whole country.


---
����: ����(group)
��Ŀ: oh
����: Tue Nov 21 22:35:21 2000
last num is 108, not 81... :P


