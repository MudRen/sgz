// lcm : experimental
// tr_seller.c
// start 20/10/98
#include <mudlib.h>
#include <sanguo.h>
#include "trade.h"

// what to inherit?


int isUser(object obj)
{
    return 1;
}

void exchangeGood(object buyer, object seller, string reply)
{
    string buyerid;
    string sellerid;
    int tid;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    if (tid == -1)
    {
      buyer->targetted_action
      ("$N��$T�Ի��˵�������и�����������\n", seller);
      return;
    }
    buyer->clear_answer();
    (DATA_TRADE)->setTrade(tid, "exchange", reply);
    (GEN_TRADE)->start(tid);
}

// check?
void canSellGood(object buyer, object seller, string reply)
{
    string buyerid;
    string sellerid;
    int tid;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    if (tid == -1)
    {
      buyer->targetted_action
      ("$N��$T�Ի��˵�������и�����������\n", seller);
      return;
    }
    buyer->clear_answer();
    if ((reply == "y") || (reply == "yes"))
    {
        (DATA_TRADE)->setTrade(tid, "status", TRADE_START);
        buyer->targetted_action
      ("$N��$TЦ��˵������Ҫ����ʲô��������\n", seller);
        buyer->set_answer(sellerid, (:exchangeGood:) );
    }
    else
    {
      seller->targetted_action
      ("$N��$T˵�����Բ�����û��������Ҫ�Ķ�����\n", buyer);
      (DATA_TRADE)->removeTrade(tid);
    }
}

void hasGood(int tid)
{
    object buyer;
    object seller;
    string sellerid;
    string buyerid;
    string good;
    buyer = (DATA_TRADE)->getTrade(tid, "buyer");
    seller = (DATA_TRADE)->getTrade(tid, "seller");
    good = (DATA_TRADE)->getTrade(tid, "good");
    if (!objectp(buyer) || !objectp(seller))
        return;
    if (!(stringp(good)))
        return;
    sellerid = (seller->query_id())[0];
    buyerid = (buyer->query_id())[0];
    buyer->targetted_action
      ("$N��$T˵������ɷ���"+good+"���ң�
�������������� answer <y|yes> to "+buyerid+"\n", seller);
    buyer->set_answer(sellerid, (:canSellGood:) );
}

void negotiate(object buyer, object seller, string good)
{
    string buyerid;
    string sellerid;
    int tid;
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    tid = (DATA_TRADE)->getTradeId(buyerid + "," + sellerid);
    if (tid == -1)
    {
      buyer->targetted_action
      ("$N��$T�Ի��˵�������и�����������\n", seller);
      return;
    }
    buyer->clear_answer();
    (DATA_TRADE)->setTrade(tid, "exchange", good);
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
    egood = (DATA_TRADE)->getTrade(tid, "buynegotiate");
    buyerid = (buyer->query_id())[0];
    sellerid = (seller->query_id())[0];
    buyer->targetted_action
      ("$N��$TЦ��˵������"+egood+"��������������\n
���Ծ������� answer accept to "+buyerid+"\n
��Ҫ��ֹ���׵Ļ������� answer abort to "+buyerid+"\n
��Ȼ�������������Խ�������Ʒ\n
����˾������� answer <��Ʒ> to "+buyerid+"\n", seller);
    buyer->set_answer(sellerid, (:negotiate:) );
}
