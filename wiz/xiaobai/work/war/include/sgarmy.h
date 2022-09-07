// /include/sgarmy.h
// data type for the unit of sg army, a army for each city
// by xiaobai, August 2001

class SGarmy
{
    int m_nTaskId;  // task id in which this army is
    
	int m_nArmyId;  // ����� id
	string m_strArmyName;  // ���������

	string m_strNationId;  // �������Ҵ���
	string m_strCityId;  // �������д���

	string m_strLeaderId;  // ��˧

	string m_strSide;  // a Ϊ��������d Ϊ���ط�

	string m_strColor;  // ��ʾ����ɫ

	int m_nFood;  // ����
	int m_nGold;  // ��
	string m_strCaptive  // ��²���� 

	int m_nCntTroop;  // troop ��Ŀ�ļ�����
	
	mapping m_mTrpIds;  // array of the troop id
}
