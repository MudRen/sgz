// /include/sgtroop.h
// data type for the unit of sg troop
// by xiaobai, August 2001

///////// status of the troops //////////////

#define SGTRP_QIBING        "qibing"
#define SGTRP_MAIFU         "maifu"
#define SGTRP_APPEAR        "appear"
#define SGTRP_COMMANDO      "commando"



class SGtroop
{
	int m_nArmyId;  // ���������
	int m_nTrpId;  // ���ӱ��

	string m_strLeaders;  // ��������

// ����λ��
    string m_strLanding;
    string m_strRoom;
	int m_nPosX;
	int m_nPosY;
	string m_strTerrain;  // ����

// ״̬
	string m_strWarOrder;

	int m_nSoldierNum;
	int m_nTrain;
	int m_nMorale;
	int m_nEnergy;
	
	string m_strStatus;

// װ��
	string m_strRighthandItem;  // ˫�����������֣�
	string m_strLefthandItem;
	string m_strArmor;
	string m_strHorse;
	string m_strCraft;
}
