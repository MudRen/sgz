// lcm : experimental
// tr_buyer.c
// start 20/10/98
#include <mudlib.h>
#include <sanguo.h>
#include "trade.h"

// what to inherit?


int isUser(object obj)
{
    return 1;
}

// check?
void wantGood(object seller, object buyer, string good)
{
    string buyerid;
    string sellerid;
    int tid;
    string dbg;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    dbg = buyerid + "," + sellerid;
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    printf(dbg + " : " + tid + "\n");
    if (tid == -1)
    {
      seller->targetted_action
      ("$N��$T�Ի��˵�������и�����������\n", buyer);
      return;
    }
    seller->clear_answer();
    (DATA_TRADE)->setTrade(tid, "good", good);
    (TR_SELLER)->hasGood(tid);
}

void requestGood(int tid)
{
    object buyer;
    object seller;
    string buyerid;
    string sellerid;
    buyer = (DATA_TRADE)->getTrade(tid, "buyer");
    seller = (DATA_TRADE)->getTrade(tid, "seller");
    if (!objectp(buyer) || !objectp(seller))
        return;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    seller->targetted_action
      ("$N��$TЦ��˵�������뽻��ʲô��
����˾������� answer <��Ʒ> to "+sellerid+"\n", buyer);
    seller->set_answer(buyerid, (:wantGood:) );
}

void negotiate(object seller, object buyer, string good)
{
    string buyerid;
    string sellerid;
    int tid;
    string dbg;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    if (tid == -1)
    {
      seller->targetted_action
      ("$N��$T�Ի��˵�������и�����������\n", buyer);
      return;
    }
    seller->clear_answer();
    (DATA_TRADE)->setTrade(tid, "buynegotiate", good);
    (GEN_TRADE)->replyResponse(tid, good);
}

void response(int tid)
{
    object buyer;
    object seller;
    string buyerid;
    string sellerid;
    string egood;
    buyer = (DATA_TRADE)->getTrade(tid, "buyer");
    seller = (DATA_TRADE)->getTrade(tid, "seller");
    if (!objectp(buyer) || !objectp(seller))
        return;
    egood = (DATA_TRADE)->getTrade(tid, "exchange");
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    seller->targetted_action
      ("$N��$TЦ��˵������"+egood+"��������������\n
���Ծ������� answer accept to "+sellerid+"\n
��Ҫ��ֹ���׵Ļ������� answer abort to "+sellerid+"\n
��Ȼ�������������Խ�������Ʒ\n
����˾������� answer <��Ʒ> to "+sellerid+"\n", buyer);
    seller->set_answer(buyerid, (:negotiate:) );
}
