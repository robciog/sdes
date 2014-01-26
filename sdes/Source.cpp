#include <stdio.h>
#include <stdlib.h>

//klucz	10111 01110
//wiadomosc 0111 1011
// wynik 1000 1000

void pw(int tab[], int tab2[])
{
	//int tab2[8];
	tab2[0] = tab[1];
	tab2[1] = tab[5];
	tab2[2] = tab[2];
	tab2[3] = tab[0];
	tab2[4] = tab[3];
	tab2[5] = tab[7];
	tab2[6] = tab[4];
	tab2[7] = tab[6];
}
void po(int tab[], int tab2[])
{
	tab2[0] = tab[3];
	tab2[1] = tab[0];
	tab2[2] = tab[2];
	tab2[3] = tab[4];
	tab2[4] = tab[6];
	tab2[5] = tab[1];
	tab2[6] = tab[7];
	tab2[7] = tab[5];
}
void p4w8(int tab[], int tab2[])
{
	tab2[0] = tab[3];
	tab2[1] = tab[0];
	tab2[2] = tab[1];
	tab2[3] = tab[2];
	tab2[4] = tab[1];
	tab2[5] = tab[2];
	tab2[6] = tab[3];
	tab2[7] = tab[0];
}
void p10(int tab[], int tab2[])
{
	tab2[0] = tab[2];
	tab2[1] = tab[4];
	tab2[2] = tab[1];
	tab2[3] = tab[6];
	tab2[4] = tab[3];
	tab2[5] = tab[9];
	tab2[6] = tab[0];
	tab2[7] = tab[8];
	tab2[8] = tab[7];
	tab2[9] = tab[5];
}
void p10w8(int tab[], int tab2[])
{
	tab2[0] = tab[5];
	tab2[1] = tab[2];
	tab2[2] = tab[6];
	tab2[3] = tab[3];
	tab2[4] = tab[7];
	tab2[5] = tab[4];
	tab2[6] = tab[9];
	tab2[7] = tab[8];
}
void sl1(int tab[], int tab2[])
{
	tab2[0] = tab[1];
	tab2[1] = tab[2];
	tab2[2] = tab[3];
	tab2[3] = tab[4];
	tab2[4] = tab[0];
}
void sl2(int tab[], int tab2[])
{
	tab2[0] = tab[2];
	tab2[1] = tab[3];
	tab2[2] = tab[4];
	tab2[3] = tab[0];
	tab2[4] = tab[1];
}
void sbox0(int tab[], int tab2[])
{
	int i;
	if (tab[0] == 0)
	{
		if (tab[1] == 0)
		{
			if (tab[2] == 0)
			{
				if (tab[3] == 0)
				{
					tab2[0] = 0;
					tab2[1] = 1;
				}
				else
				{
					tab2[0] = 1;
					tab2[1] = 1;
				}
			}
			else
			{
				if (tab[3] == 0)
				{
					tab2[0] = 0;
					tab2[1] = 0;
				}
				else
				{
					tab2[0] = 1;
					tab2[1] = 0;
				}
			}
		}
		else
		{
			if (tab[2] == 0)
			{
				if (tab[3] == 0)
				{
					tab2[0] = 1;
					tab2[1] = 1;
				}
				else
				{
					tab2[0] = 0;
					tab2[1] = 1;
				}
			}
			else
			{
				if (tab[3] == 0)
				{
					tab2[0] = 1;
					tab2[1] = 0;
				}
				else
				{
					tab2[0] = 0;
					tab2[1] = 0;
				}
			}
		}
	}
	else
	{
		if (tab[1] == 0)
		{
			if (tab[2] == 0)
			{
				if (tab[3] == 0)
				{
					tab2[0] = 0;
					tab2[1] = 0;
				}
				else
				{
					tab2[0] = 1;
					tab2[1] = 1;
				}
			}
			else
			{
				if (tab[3] == 0)
				{
					tab2[0] = 0;
					tab2[1] = 1;
				}
				else
				{
					tab2[0] = 0;
					tab2[1] = 1;
				}
			}
		}
		else
		{
			if (tab[2] == 0)
			{
				if (tab[3] == 0)
				{
					tab2[0] = 0;
					tab2[1] = 1;
				}
				else
				{
					tab2[0] = 1;
					tab2[1] = 1;
				}
			}
			else
			{
				if (tab[3] == 0)
				{
					tab2[0] = 1;
					tab2[1] = 1;
				}
				else
				{
					tab2[0] = 1;
					tab2[1] = 0;
				}
			}
		}
	}
}
void xor(int tab[], int tab2[], int tab3[])
{
	int i;
	for (i = 0; i < 8;i++)
	tab3[i] = tab[i] ^ tab2[i];
}
int main()
{
	int kp[10] = { 1, 0, 1, 1, 1, 0, 1, 1, 1, 0 };
	int kpr[8];
	int wiadomosc[8] = { 0, 1, 1, 1, 1, 0, 1, 1 };
	int wiad_pw[8], wiad_pw2[8], after_xor[8];
	int tab2[8];
	int temp[10];
	int tempa[5], tempb[5],temp2a[5],temp2b[5];
	int i;
	p10(kp, temp);
	for (i = 0; i < 5; i++)
		tempa[i] = temp[i];
	for (i = 5; i < 10; i++)
		tempb[i-5] = temp[i];
	sl1(tempa, temp2a);
	sl1(tempb, temp2b);
	for (i = 0; i < 10; i++)
	{
		if (i < 5)
		{
			temp[i] = temp2a[i];
		}
		else
		{
			temp[i] = temp2b[i - 5];
		}
	}
	p10w8(temp, kpr);
	for (i = 0; i < 8; i++)
	{
		printf_s("%d ", kpr[i]);
	}
	pw(wiadomosc, wiad_pw);
	p4w8(wiad_pw, wiad_pw2);
	xor(wiad_pw2, kpr, after_xor);
	printf_s("\n");
	system("pause");
	return 0;
}