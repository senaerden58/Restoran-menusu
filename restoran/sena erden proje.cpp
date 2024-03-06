#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>
#include <iomanip> 
#include <cstring>

using namespace std;

class Urun
{
public:
	string urunAdi[32] = { "Lahmacun", "Manti", "MuzluKek", "Simit", "Omlet", "SucukluYumurta", "Tost", "Pizza", "BiberDolmasi", "KoftePatates", "Makarna", "Pide(karisik)",
		"Borek", "BezelyeYemegi", "Pilav", "EzogelinCorba", "KuruFasulyeYemegi", "Karniyarik", "Sarma", "Sutlac", "Muhallebi", "Kurabiye", "Baklava", "Waffle", "Browni",
		"Ayran", "Limonata", "Kola", "MeyveSuyu", "SogukCay", "TurkKahvesi", "FiltreKahve" };  //urun adi dizisi 
	string eklenenUrun[10]; //elemanlarý sonradan girilen kullanýcý tarafýndan olusturulabilecek dizi
	int uretimTarihi = 01 / 01 / 2023;       //sbt
	int sonKullanmaTarihi = 01 / 01 / 2024;    //sbt
	float kaloriGram[32] = { 148,322,392,250.2,153.7,242,313.3,266,273,388.5,131,800,
	285,185,359.2,91,227,97,127,111.1,122.4,501.9,335,291,466,60,40.2,37.5,54.5,35.1,7,5 };
	float eklenenKalori[10];
	float fiyat[32] = { 16,70,30,5,30,50,25,110,30,90,55,45,
	33,30,25,20,22.5,27,35,47,35,17,70,65,30,
	10,15,15,13,14,39,29.5 };
	float eklenenFiyat[10];

	int eklenen = 0;
	int urunSayisi = 32;

	void Menu()
	{
		ifstream DosyaOku("yemekcesit.txt");
		ofstream DosyaYaz("yemekcesittmp.txt", ios::out);
		if (DosyaYaz.is_open())
		{
			cout << "DOSYA ACILMISTIR.";

			cout << endl;
		}
		DosyaYaz << "----------------RESTORAN MENUSU-------------" << endl;
		DosyaYaz << setw(20) << left << "URUN ADI" << setw(15) << left << "Urun kalori gram:" << setw(20) << left << "Urun fiyat:" << setw(20) << left << endl;
		for (int i = 0;i < urunSayisi;i++) //urun adý dizisini döndürür.
		{
			DosyaYaz << setw(30) << left << urunAdi[i] << setw(10) << left << kaloriGram[i] << setw(70) << left << fiyat[i] << endl;
		}
		for (int i = 0;i < eklenen;i++)
		{ //eklenen varsa dosyaya yazýlýr
			DosyaYaz << setw(30) << left << eklenenUrun[i] << setw(10) << left << eklenenKalori[i] << setw(70) << left << eklenenFiyat[i] << endl;
		}
		int islemNu;
		char chr = 'a';
		char chr11 = 'c';
		do
		{
			do
			{

				cout << "-----------------------MENU------------------------------" << endl;
				cout << "1-Kayit ekleme" << endl;
				cout << "2-Kayit silme" << endl;
				cout << "3-Kayit guncelleme" << endl;
				cout << "4-Rapor alma" << endl;
				cout << "5-Malzemeleri gorme" << endl;
				cout << "6-Depoyu gorme" << endl;
				cout << "Yapmak istediginiz islem numarasi giriniz." << endl;
				cin >> islemNu;
			} while (islemNu < 1 && islemNu>4);
			switch (islemNu)
			{
			case 1:
			{
				system("cls");
				ofstream DosyaYaz("yemekcesit.txt", ios::app); //dosya acýldý.
				char ch = 'a';
				cout << "Urun eklemek istiyor musunuz?(e/h)" << endl;
				cin >> ch;
				if (ch == 'e')
				{
					cout << "Kac urun eklemek istersiniz?(Maximum 10 urun eklenebilir.)" << endl;
					cin >> eklenen;

					for (int i = 0; i < eklenen; i++)
					{
						cout << "Urunun adini giriniz.";
						cin >> eklenenUrun[i];
						cout << "Urunun kalorisini giriniz.";
						cin >> eklenenKalori[i];
						cout << "Urunun fiyatini giriniz. ";
						cin >> eklenenFiyat[i];
					}
					cout << "Urunler eklendi." << endl;

					DosyaYaz << "----------------RESTORAN MENUSU-------------" << endl;
					DosyaYaz << setw(20) << left << "URUN ADI" << setw(15) << left << "Urun kalori gram:" << setw(20) << left << "Urun fiyat:" << setw(20) << left << endl;
					for (int i = 0;i < urunSayisi;i++)
					{//urun adý dizisini döndürür.
						DosyaYaz << setw(30) << left << urunAdi[i] << setw(10) << left << kaloriGram[i] << setw(70) << left << fiyat[i] << endl;

					}
					for (int i = 0;i < eklenen;i++)
					{//eklenen lemaný yazdýrýr.
						DosyaYaz << setw(30) << left << eklenenUrun[i] << setw(10) << left << eklenenKalori[i] << setw(70) << left << eklenenFiyat[i] << endl;
					}
					eklenen += eklenen;
				}
				break;
			}
			case 2:
			{
				system("cls");
				char ch = 'a';
				int urunSayisi = 32;
				int aranan;
				int aranan1;
				string sil1;
				int boyut = sizeof(urunAdi) / sizeof(urunAdi[32]);          //dizi boyutu bulma
				int boyut1 = sizeof(eklenenUrun) / sizeof(eklenenUrun[eklenen]);
				int boyut2 = sizeof(eklenenKalori) / sizeof(eklenenKalori[eklenen]);
				int boyut3 = sizeof(eklenenFiyat) / sizeof(eklenenFiyat[eklenen]);
				int boyut4 = sizeof(kaloriGram) / sizeof(kaloriGram[32]);
				int boyut5 = sizeof(fiyat) / sizeof(fiyat[32]);
				string sil;
				int silindi = 0;
				cout << "Silinecek urun:";
				cout << "-------YEMEK LISTESI--------" << endl;
				for (int i = 0;i < urunSayisi;i++)
				{
					cout << i + 1 << setw(30) << left << urunAdi[i] << setw(10) << left << kaloriGram[i] << setw(70) << left << fiyat[i] << endl;
				}
				cout << "Yeni eklenen elemani silmek icin 99'a basin." << endl;
				cout << "Silinecek urunun numarasini yaziniz." << endl;
				cin >> aranan;
				cout << endl;
				ifstream DosyaOku("yemekcesittmp.txt", ios::in);
				ofstream DosyaYaz("yemekcesit.txt", ios::out);
				while (!DosyaOku.eof())
				{
					if (aranan - 1 <= urunSayisi)
					{
						for (int i = 0;i < urunSayisi;i++)
						{
							if ((aranan - 1) == i)
							{
								system("cls");
								if (aranan - 1 < 32)
								{
									cout << "\n ------Menudeki Kayit-------- \n ";
									cout << "Urun adi:" << urunAdi[i] << endl;
									cout << "Kalori gram:" << kaloriGram[i] << endl;
									cout << "Fiyat:" << fiyat[i] << endl;
									cout << "Urunun ismini dogru bir sekilde yaziniz." << endl;
									cin >> sil;
									//silme iþlemi
									for (int i = 0; i < urunSayisi; i++)
									{
										if (urunAdi[i] == sil)
										{
											for (int j = i; j < boyut; j++)
											{//secilen elelmaný bir sonrakine aktarma
												urunAdi[j] = urunAdi[j + 1];
											}
											silindi = 1;
											i--;
											boyut--;
										}
									}
									system("Pause");
									DosyaYaz << "----------------RESTORAN MENUSU-------------" << endl;
									DosyaYaz << setw(20) << left << "URUN ADI" << setw(15) << left << "Urun kalori gram:" << setw(20) << left << "Urun fiyat:" << setw(20) << left << endl;
									for (int i = 0; i < boyut; i++)
									{
										DosyaYaz << urunAdi[i] << setw(15) << left << kaloriGram[i] << setw(20) << fiyat[i] << setw(20) << left << endl;
									}
									for (int i = 0; i < eklenen - 1; i++)
									{
										DosyaYaz << eklenenUrun[i] << setw(15) << left << eklenenKalori[i] << setw(20) << eklenenFiyat[i] << setw(20) << left << endl;
									}
								}
							}
						}
					}
					else if (aranan == 99)
					{
						cout << "-------YEMEK LISTESI--------" << endl;
						for (int i = 0;i < eklenen;i++)
						{//eklenen urunu silme
							cout << i + 33 << setw(30) << left << eklenenUrun[i] << setw(10) << left << eklenenKalori[i] << setw(70) << left << eklenenFiyat[i] << endl;
						}
						cout << "Lutfen silinecek yemegin numarasini yaziniz." << endl;
						cin >> aranan1;
						cout << endl;
						if (eklenen == 0)
						{
							cout << "Urun eklenmemistir." << endl;
						}
						else
						{
							for (int i = 0;i < eklenen;i++)
							{
								if ((aranan1 - 1) == i + 32)
								{
									system("cls");
									if (aranan - 1 >= 32)
									{
										cout << "\n ------Menudeki Kayit-------- \n ";
										cout << "Urun adi:" << eklenenUrun[i] << endl;
										cout << "Kalori gram:" << eklenenKalori[i] << endl;
										cout << "Fiyat:" << eklenenFiyat[i] << endl;

										cout << ("\n Eger urun bu ise silinecek urun adini yukarda yazildigi gibi giriniz: ");
										cin >> sil1;
		
										for (int i = 0; i < eklenen; i++)
										{//silme 
											if (eklenenUrun[i] == sil1)
											{
												for (int j = i; j < eklenen; j++)
												{
													eklenenUrun[j] = eklenenUrun[j + 1];
													silindi = 1;
													i--;
													boyut1--;

												}
												for (int j = i;j < eklenen;j++)
												{
													eklenenKalori[j] = eklenenKalori[j + 1];
													sil1 = 1;
													i--;
													boyut2--;
												}
												for (int j = i;j < eklenen;j++)
												{
													eklenenFiyat[j] = eklenenFiyat[j + 1];
													sil1 = 1;
													i--;
													boyut3--;
												}
											}
										}
										cout << "Baska bir islem yapmak ister misiniz?(e/h)" << endl;
										cin >> ch;
										DosyaYaz << "----------------RESTORAN MENUSU-------------" << endl;
										DosyaYaz << setw(20) << left << "URUN ADI" << setw(15) << left << "Urun kalori gram:" << setw(20) << left << "Urun fiyat:" << setw(20) << left << endl;

										for (int i = 0; i < boyut; i++)
										{
											DosyaYaz << urunAdi[i] << setw(15) << left << kaloriGram[i] << setw(20) << fiyat[i] << setw(20) << left << endl;
										}
										for (int i = 0; i < boyut1; i++)
										{
											if (eklenenUrun[i] == " ")
											{
												continue;
											}
											if (eklenenKalori[i] == 0)
											{
												continue;
											}
											if (eklenenFiyat[i] == 0)
											{
												continue;
											}
											DosyaYaz << eklenenUrun[i] << setw(15) << left << eklenenKalori[i] << setw(20) << eklenenFiyat[i] << setw(20) << left << endl;
										}//dosyaya da yadýrýldý.
									}
								}
							}
						}
					}
					else
					{
						cout << "Urun bulunamadi." << endl;
					}

					DosyaOku.close();
					DosyaYaz.close();
					remove("yemekcesittmp.txt");
					rename("yemekcesit.txt", "yemekcesittmp.txt");
				}
			}
			case 3:
			{
				system("cls");
				char ch = 'a';
				int urunSayisi = 32;
				string sil1;
				int boyut = sizeof(urunAdi) / sizeof(urunAdi[32]);
				int boyut1 = sizeof(eklenenUrun) / sizeof(eklenenUrun[10]);
				int boyut2 = sizeof(eklenenKalori) / sizeof(eklenenKalori[10]);
				int boyut3 = sizeof(eklenenFiyat) / sizeof(eklenenFiyat[10]);
				string degistir;
				int degisti = 0;
				ifstream DosyaOku;
				ofstream DosyaYaz;
				DosyaOku.open("yemekcesit_duzenle.txt");
				DosyaYaz.open("yemekcesit.txt", ios::app);
				cout << "----------------RESTORAN MENUSU-------------" << endl;
				cout << setw(20) << left << "URUN ADI" << setw(15) << left << "Urun kalori gram:" << setw(20) << left << "Urun fiyat:" << setw(20) << left << endl;
				for (int i = 0;i < urunSayisi;i++)
				{
					cout << setw(30) << left << urunAdi[i] << setw(10) << left << kaloriGram[i] << setw(70) << left << fiyat[i] << endl;
				}
				for (int i = 0;i < eklenen;i++)
				{
					cout << setw(30) << left << eklenenUrun[i] << setw(10) << eklenenKalori[i] << setw(70) << left << eklenenFiyat[i] << endl;
				}
				cout << "Urunun adini giriniz." << endl;
				cin >> degistir;
				while (!(DosyaOku.eof()))
				{

					for (int i = 0;i < urunSayisi;i++)
					{
						DosyaOku >> urunAdi[i] >> kaloriGram[i] >> fiyat[i];

						if (degistir == urunAdi[i])
						{
							system("cls");
							cout << "\n ------Menudeki Kayit-------- \n ";
							cout << "Urun adi:" << urunAdi[i] << endl;
							cout << "Kalori gram:" << kaloriGram[i] << endl;
							cout << "Fiyat:" << fiyat[i] << endl;
							//silme iþlemi
							for (int i = 0; i < boyut; i++)
							{
								if (degistir == urunAdi[i])
								{
									for (int j = i; j < boyut; j++)
									{
										urunAdi[j] = urunAdi[j + 1];
										degisti = 1;
										i--;
									}
								}
							}
							DosyaYaz << "----------------RESTORAN MENUSU-------------" << endl;
							DosyaYaz << setw(20) << left << "URUN ADI" << setw(15) << left << "Urun kalori gram:" << setw(20) << left << "Urun fiyat:" << setw(20) << left << endl;
							for (int i = 0;i < 1;i++)
							{
								cout << "Urunun adini giriniz." << endl;
								cin >> eklenenUrun[i];
								cout << "Urunun kalorisini giriniz." << endl;
								cin >> eklenenKalori[i];
								cout << "Urunun fiyatini giriniz. " << endl;
								cin >> eklenenFiyat[i];
								cout << "Degistirildi!" << endl;

								DosyaYaz << setw(30) << left << eklenenUrun[i] << setw(10) << left << eklenenKalori[i] << setw(70) << left << eklenenFiyat[i] << endl;

							}
							for (int i = 0;i < boyut;i++)
							{
								DosyaYaz << setw(30) << left << urunAdi[i] << setw(10) << left << kaloriGram[i] << setw(70) << left << fiyat[i] << endl;
							}

							DosyaOku.close();
							DosyaYaz.close();
							if (degistir == urunAdi[i]) // Programda kayýt varsa yapýlan deðiþikliklerin dosya üzerine yazýlmasý saðlandý.
							{
								remove("yemek_duzenle.txt");
								rename("yemekcesit.txt", "yemek_duzenle.txt");
								cout << "Yemek bilgileri yenilendi." << endl;
							}
							else
							{
								remove("yemek_duzenle.txt");
							}
						}
					}
				}
				break;
			}
			case 4:
			{
				system("cls");
				ifstream DosyaOku("rapor.txt");
				ofstream DosyaYaz("rapor.txt", ios::out);
				cout << "RAPOR DOSYASINA YAZILDI!" << endl;
				DosyaOku.close();
				while (!DosyaOku.eof())
				{
					DosyaYaz << "----------------RESTORAN MENUSU-------------" << endl;
					DosyaYaz << setw(20) << left << "URUN ADI" << setw(15) << left << "Urun kalori gram:" << setw(20) << left << "Urun fiyat:" << setw(20) << left << endl;
					for (int i = 0;i < urunSayisi;i++)
					{
						DosyaYaz << setw(30) << left << urunAdi[i] << setw(10) << left << kaloriGram[i] << setw(70) << left << fiyat[i] << endl;
					}
					for (int i = 0;i < eklenen;i++)
					{
						DosyaYaz << setw(30) << left << eklenenUrun[i] << setw(10) << left << eklenenKalori[i] << setw(70) << left << eklenenFiyat[i] << endl;
					}
					DosyaYaz.close();
				}
				break;
			}
			case 5:
			{
				system("cls");
				char ch;
				string ad;
				ifstream DosyaOku("Malzeme.txt");
				ofstream DosyaYaz("Malzemeler.txt", ios::app);
				int sayi99;
				while (!DosyaOku.eof())
				{
					do
					{
						cout << "----------------RESTORAN MENUSU-------------" << endl;
						cout << setw(20) << left << "URUN ADI" << setw(15) << left << "Urun kalori gram:" << setw(20) << left << "Urun fiyat:" << setw(20) << left << endl;
						for (int i = 0;i < urunSayisi;i++)
						{
							cout << i + 1 << setw(30) << left << urunAdi[i] << setw(10) << left << kaloriGram[i] << setw(70) << left << fiyat[i] << endl;
						}
						cout << "Yemek malzemelerini gormek icin sayiyi giriniz." << endl;

						cin >> sayi99;
						system("cls");
						if (sayi99 > 0 && sayi99 <= 32)
						{
							for (int i = 0;i < urunSayisi;i++)
							{
								if (sayi99 - 1 == i)
								{
									DosyaYaz << urunAdi[i] << "\n";
									if (i == 0)//lahmacun //10 adet
									{
										DosyaYaz << "un=2 su bardagý" << endl << "1 çay kaþýðý maya" << "2 çay kaþýðý tuz" << endl << "1 su bardagi ilik su" <<
											"1 yemek kaþýðý sývýyað" << endl << "350  gr yaðlý kýyma" << endl << "1 adet kuru soðan" << endl <<
											"2 adet domates" << endl << "1 yemek kaþýðý domates salçasý	" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 1)//manti  //6 kisilik
									{
										DosyaYaz << "3su bardaðý un " << endl << "1 su bardaðý ýlýk su" << endl << "1 çay kaþýðý tuz" << endl << "1 adet yumurta" << endl <<
											"250 g az yaðlý kýyma" << endl << "1 adet orta boy soðan" << endl << "1 çay kaþýðý tuz" << endl << "2 yemek kaþýðý tereyaðý" << endl << "2 yemek kaþýðý salça" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 2)//muzlu kek //10 kisi
									{
										DosyaYaz << "3 yumurta" << endl << "1 su bardaðý toz seker" << endl << "1 su bardaðý sut " << endl << "1 su bardaðý sývý yag " << endl <<
											"2 olgunlaþmýþ muz" << endl << "3 su bardaðý un	" << endl << "1 paket kabartma tozu" << endl << "1 paket vanilya" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 3)//simit  14 kisilik
									{
										DosyaYaz << "1 su bardaðý ýlýk süt" << endl << "1 su bardaðý ýlýk su " << endl << "1 su sivi yag" << endl << "1 yemek kasigi seker" << endl <<
											"1 tatlý kaþýðý tuz	 " << endl << "1 küçük paket kuru maya" << endl << "Aldýðý kadar un" << endl << "Yarým çay bardaðý üzüm pekmezi	" << endl <<
											"Yarým çay bardaðý su" << endl << "Bol susam " << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 4)
									{//omlet tek kisilik
										DosyaYaz << "2 adet yumurta" << endl << "Tuz" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 5)
									{//sucuk 2kisilik 
										DosyaYaz << "125 gr sucuk " << endl << "2 yumurta" << endl << "1, 5 yemek kaþýðý sývýyað" << endl << "1 cay kasýgý Tuz" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 6)
									{//tost 4 kisilik
										DosyaYaz << "4 dilim tost ekmeði " << endl << "4 dilim kaþar peyniri " << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 7)//pizza  10 kisi
									{
										DosyaYaz << "5 su bardaðý un" << endl << "1 paket instant maya" << endl << "1 yemek kaþýðý toz þeker" << endl << "1 yemek kaþýðý tuz" << endl <<
											"2 su bardaðý ýlýk su" << endl << " 2 su bardaðý domates salcasý" << endl <<
											"Kaþar peyniri" << endl << "Sucuk" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 8)//biber dolmasi 6kisilik 
									{
										DosyaYaz << "Yarým kg dolmalýk biber" << endl << "Her biber için 1 yemek kaþýðý pirinç" << endl << "1 adet soðan" << endl << "1 yemek kaþýðý salça" << endl <<
											"2 - 3 adet domates" << endl << "Tuz " << endl << "Sývý yað" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 9)//kofte patates  //4kisilik
									{
										DosyaYaz << "2 - 3 adet patates " << endl << "2 adet domates " << endl << "Sývý yað " << endl <<
											"1 adet yumurta" << endl << "Yarým su bardaðý un" << endl << "Tuz" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 10)//makarna  4kisilik
									{
										DosyaYaz << "1 paket makarna" << endl << "Tuz" << endl << "Tereyaðý" << endl << "Sývý yað" << endl <<
											"1 adet tavuk suyu bulyon" << endl << "Su" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 11)//pide 6kisilik
									{
										DosyaYaz << "5 su bardaðý un  " << endl << "2 su bardaðý su " << endl << "1 tatlý kaþýðý tuz" << endl << "1 yemek kaþýðý þeker" << endl << "Yarým paket instant maya " << endl <<
											"Sucuklu - kaþarlý - biberli harç " << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 12)//borek  6 kisilik
									{
										DosyaYaz << "3 yufka" << endl << "250 g kasar peynir " << endl << "1.5 su bardaðý süt	" << endl << "4 çay bardaðý siviyag" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 13)//bezelye yemegi 4 kisilik
									{
										DosyaYaz << "2 adet büyük boy patates" << endl << "1 kilogram ayýklanmýþ bezelye " << endl << "2 adet küçük boy soðan	 " << endl <<
											"1 yemek kaþýðý domates salçasý" << endl << "2, 5 çay kaþýðý tuz " << endl << "2, 5 su bardaðý sýcak su" << endl << "Az sývý yað " << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 14)//pilav  6kisi
									{
										DosyaYaz << "2 su bardaðý pirinç" << endl << "2, 5 su bardaðý sýcak su" << endl << "3 yemek kaþýðý tereyaðý " << endl << "1 yemek kaþýðý sývý yað " << endl << "Tuz" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 15)//ezogelin corba 6 kiþilik
									{
										DosyaYaz << "1 su bardaðý kýrmýzý mercimek" << endl << "1 tatlý kaþýðý pirinç " << endl << "1 tatlý kaþýðý bulgur" << endl << "2 diþ sarýmsak" << endl <<
											"1 orta boy soðan" << endl << "1 yemek kaþýðý tereyaðý" << endl << "2 litreye yakýn sýcak su" << endl << "Tuz" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 16)//kuru fasulye 8 kisilik
									{
										DosyaYaz << "2 su bardaðý kuru fasulye" << endl << "1 adet kuru soðan" << endl << "1 yemek kaþýðý domates salçasý" << endl <<
											"4 yemek kaþýðý sývý yað" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 17)//karnýyarýk 6 kisilik
									{
										DosyaYaz << "2 adet orta boy soðan" << endl << "2 adet domates" << endl << "Sývý yað, tuz " << endl << "200 gr kýyma" << endl <<
											"1 çay bardaðý sýcak su " << endl << "1 yemek kaþýðý salça" << endl << "1 su bardaðý sýcak su" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 18)//sarma 12 kisilik
									{
										DosyaYaz << "asma yapragi" << endl << "1 çay bardaðý zeytinyaðý(125 ml) " << endl << " 3 adet kuru soðan " << endl << " 1 tatlý kaþýðý tuz" << endl <<
											" 2 su bardaðý pirinç" << endl << " 1 tatlý kaþýðý toz þeker" << endl <<
											" 1, 5 su bardaðý sýcak su(300 ml)" << endl << " 1 tatlý kaþýðý toz þeker" << endl << " 2, 5 su bardaðý sýcak su(500 ml)" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 19)//sutlac 6 kiþilik
									{
										DosyaYaz << "1 lt süt " << endl << "2 çay bardaðý pirinç " << endl << "1 litre su" << endl << "3 yemek kaþýðý un" << endl <<
											"2 su bardaðý toz þeker" << endl << "1 su bardaðý süt " << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 20)//muhallebi 4 kisilik
									{
										DosyaYaz << "Yarým su bardaðý þeker  " << endl << "1 yemek kaþýðý niþasta" << endl << "3 yemek kaþýðý un" << endl <<
											"4 su bardaðý süt" << endl << "1 tatlý kaþýðý tereyaðý" << endl << "1 paket vanilya" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 21)//kurabiye   12kisiliik
									{
										DosyaYaz << "250 gram tereyaðý " << endl << "1 yumurta  " << endl <<
											"1 paket kabartma tozu" << endl << "4 su bardaðý un " << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 22)//baklava  16kiþilik
									{
										DosyaYaz << "3 yumurta " << endl << "1 su bardaðý süt" << endl << "1 su bardaðý sývý yað" << endl << "1 adet kabartma tozu" << endl <<
											"Yarým çay kaþýðý tuz" << endl << "6 su bardaðý un" << endl << "Kýrýlmýþ ceviz ya da fýndýk" << endl <<
											"4 bardak þeker" << endl << "5 bardak su" << endl << "300 g tereyaðý ya da margarin" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 23)//waffle 4 kisilik
									{
										DosyaYaz << "1 yumurta" << endl << "1 çorba kaþýðý þeker Yarým su bardaðý süt" << endl << " 2 çorba kaþýðý sývý yað   " << endl << " 1 paket vanilin" << endl <<
											" 1 paket kabartma tozu" << endl << " 1 su bardagý un" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 24)//browni 8 kisilik
									{
										DosyaYaz << "300 gram bitter çikolata " << endl << "3 adet yumurta " << endl << "1 su bardaðý toz þeker" << endl << "150 gram tereyaðý " << endl <<
											"1 su bardaðý un" << endl << "1 paket vanilya" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 25)
									{
										DosyaYaz << "Kutu ayran" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 26)
									{
										DosyaYaz << " Þiþe Limonata " << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 27)
									{
										DosyaYaz << "Kola" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 28)
									{
										DosyaYaz << "MeyveSuyu" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 29)
									{
										DosyaYaz << "SogukCay" << endl;
										DosyaYaz << "**********************************************************************************" << endl;
									}
									else if (i == 30)
									{
										DosyaYaz << "2 çay kaþýðý kahve" << endl << "1 çay kaþýðý þeker " << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
									else if (i == 31)
									{
										DosyaYaz << "1 tatlý kaþýgý kahve" << endl << "1 su bardaðý su" << endl;
										DosyaYaz << "*********************************************************************" << endl;
									}
								}
							}
						}
						cout << "Urun malzemeleri dosyaya yazildi.\n";
						cout << "Devam etmek ister misiniz?(e/h)" << endl;
						cin >> ch;
					} while (!(ch == 'h'));
					DosyaYaz.close();
					DosyaOku.close();
					if (ch == 'h')
					{
						break;
					}
				}
			}
			case 6:
			{
				float un = 50; //kg
				float su = 100; //L
				float maya = 30;//paket
				float tuz = 10; //kg
				float kiyma = 5; //kg
				float sogan = 100; //adet             
				float domates = 100; //adet
				float salca = 15; //kg
				float yumurta = 10000; //adet
				float tereyag = 100;//kg
				float seker = 100; //kg
				float sut = 100;//L
				float muz = 100; //adet
				float pekmez = 100; //l
				float sucuk = 100; //adet
				float tostEkmegi = 1000; //tane
				float kasarPeynir = 10000; //kg
				float siviYag = 1000; //l
				float kabartmaTozu = 1000; //paket
				float vanilya = 1000; //paket
				float dolmalýkBiber = 10000; //tane
				float pirinc = 1000;//kg
				float patates = 10000;//adet
				float makarna = 100000; //paket
				float tavukSuyu_bulyon = 100000; //adet
				float yufka = 100; //adet
				float kirmiziMercimek = 1000; //kg
				float bezelye = 1000; //kg
				float bulgur = 100; //kg
				float kuruFasulye = 100; //kg
				float asmaYapragý = 1000; //kg
				float zeytinYagý = 10000; //litre
				float nisasta = 1000; //kg
				float ceviz = 100000; //kg
				float cikolata = 10000; //kg
				float ayran = 50; //kutu
				float limonata = 50; //kutu
				float kola = 50; //kutu
				float meyveSuyu = 50; //kutu
				float sogukCay = 50;//kutu
				float kahve = 100; //kg
				float turkKahvesi = 1000; //kg
				int sec;
				int siparisSayisi;
				int bitir;
				float ucret = 0;
				ifstream DosyaOku("depo.txt");
				ofstream DosyaYaz("depo1.txt", ios::app);
				while (!(DosyaOku.eof()))
				{

					for (int i = 0;i < urunSayisi;i++)
					{
						cout << i + 1 << setw(30) << left << urunAdi[i] << setw(10) << left << kaloriGram[i] << setw(70) << left << fiyat[i] << endl;
					}
					for (int i = 0;i < eklenen;i++)
					{

						cout << i + 32 << setw(30) << left << eklenenUrun[i] << setw(10) << left << eklenenKalori[i] << setw(70) << left << eklenenFiyat[i] << endl;
					}
					cout << "Siparis edilecek urunun numarasini yaziniz." << endl;
					cin >> sec;
					cout << "Kac tane siparis edilecek?" << endl;
					cin >> siparisSayisi;
					siparisSayisi += siparisSayisi;
					DosyaYaz << "-----------------Kalan urunler:----------------" << "------------------Fiyat------------------" << endl;
					for (int i = 0; i < urunSayisi;i++)
					{
						if (i == sec - 1)
						{
							ucret += siparisSayisi * fiyat[i];
							DosyaYaz << urunAdi[i] << setw(40) << "TOPLAM TUTAR:" << ucret << "TL" << endl;
							if (i == 0)//lahmacun //10 adet
							{
								for (int i = 0;i < siparisSayisi;i += 10)
								{
									un -= 0.4;
									maya -= 0.5;
									tuz -= 0.001;
									su -= 0.2;
									siviYag -= 0.012;
									kiyma -= 0.35;
									sogan -= 1;
									domates -= 2;
									salca -= 0.012;
								}
								DosyaYaz << "Un:" << un << "kg" << endl << "Maya:" << maya << "paket" << endl << "Tuz:" << tuz << "kg" << endl << "Su:" << su << "L" << endl << "Siviyag:" << siviYag << "L" << endl << "Kiyma:" << kiyma << "kg" << endl <<
									"Sogan:" << sogan << "adet" << endl << "Domates:" << domates << "adet" << endl << "Salca:" << salca << "kg" << endl;
							}
							else if (i == 1)//manti  
							{
								for (int i = 0;i < siparisSayisi;i += 6)
								{
									un -= 0.6;
									su -= 0.2;
									tuz -= 0.005;
									yumurta -= 1;
									kiyma -= 0.250;
									sogan -= 1;
									tereyag -= 0.12;
									salca -= 0.024;
								}
								DosyaYaz << "Un:" << un << "kg" << endl << "Su:" << su << "L" << endl << "Tuz:" << tuz << "kg" << endl << "Yumurta:" << yumurta << "adet" << endl << "Kiyma:" << kiyma << "kg" << endl << "Sogan:" << sogan << "adet" << endl << "Tereyag:" << tereyag <<
									"kg" << endl << "Salca:" << salca << "kg" << endl;
							}
							else if (i == 2)//muzlu kek //10 kisi
							{
								for (int i = 0;i < siparisSayisi;i += 10)
								{
									yumurta -= 3;
									seker -= 0.2;
									sut -= 0.2;
									siviYag -= 0.2;
									muz -= 2;
									un -= 0.6;
									kabartmaTozu -= 1;
									vanilya -= 1;
								}
								DosyaYaz << "Yumurta:" << yumurta << "Adet" << endl << "Seker:" << seker << "kg" << endl << "Sut:" << sut << "L" << endl << "Siviyag:" << siviYag << "L" << endl << "Muz" << muz << "adet" << endl << "Un" << un << "kg" << endl <<
									"Kabartma Tozu:" << kabartmaTozu << "paket" << endl << "Vanilya:" << vanilya << "Paket" << endl;
							}
							else if (i == 3)//simit  14 kisilik
							{
								for (int i = 0;i < siparisSayisi;i += 14)
								{
									sut -= 0.2;
									su -= 0.2;
									siviYag -= 0.2;
									seker -= 0.012;
									tuz -= 0.006;
									maya -= 0.5;
									un -= 1;
									pekmez -= 0.2;
								}
								DosyaYaz << "Sut" << sut << "L" << endl << "Su" << su << "L" << endl << "SiviYag:" << siviYag << "L" << endl << "Seker:" << seker << "Kg" << endl << "Tuz:" << tuz << "kg" << endl << "Maya" << maya << "paket" << endl
									<< "Un" << un << "Kg" << endl << "Pekmez:" << pekmez << "L" << endl;
							}
							else if (i == 4)//omlet tek kisilik
							{
								for (int i = 0;i < siparisSayisi;i += 2)
								{
									yumurta -= 2;
									tuz -= 0.012;
								}
								DosyaYaz << "Yumurta:" << yumurta << "Adet" << endl << "Tuz:" << tuz << "kg" << endl;
							}
							else if (i == 5)//sucuk 2kisilik 
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									sucuk -= 0.125;
									yumurta -= 2;
									siviYag -= 0.018;
									tuz -= 0.006;
								}
								DosyaYaz << "Sucuk:" << sucuk << "adet" << "Yumurta:" << yumurta << "Adet" << endl << "Siviyag:" << siviYag << endl << "Tuz:" << tuz << "kg" << endl;
							}
							else if (i == 6)//tost 4 kisilik
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									tostEkmegi -= 4;
									kasarPeynir -= 0.125;
								}
								DosyaYaz << "Tost ekmegi:" << tostEkmegi << "Adet" << "Kasar peynir:" << kasarPeynir << "kg" << endl;
							}
							else if (i == 7)
							{
								for (int i = 0;i < siparisSayisi;i += 10)
								{
									un -= 1;
									maya -= 1;
									seker -= 0.012;
									tuz -= 0.006;
									kasarPeynir = 0.125;
									sucuk -= 0.125;
								}
								DosyaYaz << "Un:" << un << "kg" << endl << "Maya:" << maya << "Paket" << endl << "Seker:" << seker << "kg" << endl << "Tuz:" << tuz << "kg" << endl << "Kasar peynri:" << kasarPeynir << "kg" << endl << "Sucuk:" << sucuk << "adet" << endl;
							}
							else if (i == 8)//biber dolmasi 6kisilik 
							{
								for (int i = 0;i < siparisSayisi;i += 6)
								{
									dolmalýkBiber -= 0.5;
									pirinc -= 0.12;
									sogan -= 1;
									salca -= 0.012;
									domates -= 4;
									tuz -= 0.02;
									siviYag -= 0.024;
								}
								DosyaYaz << "DolmalikBiber:" << dolmalýkBiber << "kg" << endl << "Pirinc:" << pirinc << "kg" << endl << "Sogan:" << sogan << "kg" << endl << "Salca:" << salca << "kg" << endl << "Domates:" << domates << "kg" << endl << "Tuz:" << tuz << "kg" << endl
									<< "Sývý yag:" << siviYag << "L" << endl;
							}
							else if (i == 9)//kofte patates  //4kisilik
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									patates -= 3;
									domates -= 2;
									siviYag -= 0.2;
									yumurta -= 1;
									un -= 0.1;
									tuz -= 0.06;
								}
								DosyaYaz << "Patates:" << patates << "adet" << endl << "Domates:" << domates << "adet" << endl << "Sývý yag:" << siviYag << "L" << endl << "Yumurta:" << yumurta << "adet" << endl << "Un:" << un << "kg" << endl
									<< "Tuz:" << tuz << "kg" << endl;
							}
							else if (i == 10)//makarna  4kisilik
							{
								for (int i = 0;i < siparisSayisi;i += 4)
								{
									makarna -= 1;
									tuz -= 0.012;
									tereyag -= 0.5;
									siviYag -= 0.012;
									tavukSuyu_bulyon -= 1;
									su -= 0.5;
								}
								DosyaYaz << "Makarna:" << makarna << "paket" << endl << "Tuz:" << tuz << "kg" << endl << "Tereyag:" << tereyag << "kg" << endl << "Siviyag:" << siviYag << "L" << endl << "Tavuk suyu bulyon:" << tavukSuyu_bulyon << "adet" << endl <<
									"Su:" << su << "L" << endl;
							}
							else if (i == 11)//pide 6kisilik
							{
								for (int i = 0;i < siparisSayisi;i += 6)
								{
									un -= 1;
									su -= 0.4;
									tuz -= 0.006;
									seker -= 0.012;
									maya -= 1;
									sucuk -= 0.125;
									kasarPeynir -= 0.5;
								}
								DosyaYaz << "Un:" << un << "kg" << endl << "Su :" << su << "L" << endl << "Tuz:" << tuz << "kg" << endl << "Seker:" << seker << "kg" << endl << "Maya: " << maya << "paket" << endl <<
									"Sucuk:" << sucuk << "adet" << endl << "Kasar peynir:" << kasarPeynir << "kg" << endl;
							}
							else if (i == 12)//borek  6 kisilik
							{
								for (int i = 0;i < siparisSayisi;i += 6)
								{
									yufka -= 3;
									kasarPeynir -= 0.25;
									sut -= 0.3;
									siviYag -= 0.2;
								}
								DosyaYaz << "Yufka:" << yufka << "adet" << endl << "Kasar peynir:" << kasarPeynir << "kg" << endl << "Sut:" << sut << "L" << endl << "Sivi yag:" << siviYag << "L" << endl;
							}
							else if (i == 13)//bezelye yemegi 4 kisilik
							{
								for (int i = 0;i < siparisSayisi;i += 4)
								{
									patates -= 2;
									bezelye -= 1;
									sogan = 2;
									salca -= 0.012;
									tuz -= 0.009;
									su -= 0.3;
								}
								DosyaYaz << "Patates:" << patates << "adet" << endl << "Bezelye:" << bezelye << "kg" << endl << "Soðan:" << sogan << "adet" << endl <<
									"Salça:" << salca << "kg" << endl << "Tuz:" << tuz << "kg" << endl << "Su:" << su << "L" << endl;
							}
							else if (i == 14)//pilav  6kisi
							{
								for (int i00;i < siparisSayisi;i += 6)
								{
									pirinc -= 0.4;
									su -= 0.3;
									tereyag -= 0.036;
									siviYag -= 0.012;
									tuz -= 0.012;
								}
								DosyaYaz << "Pirinç:" << pirinc << "kg" << endl << "Su:" << su << "L" << endl << "Tereyað:" << tereyag << "kg" << endl << "Sývý yað :" << siviYag << "L" << endl << "Tuz:" << tuz << "kg" << endl;
							}
							else if (i == 15)//ezogelin corba 6 kiþilik
							{
								for (int i = 0;i < siparisSayisi;i += 6)
								{
									kirmiziMercimek -= 0.2;
									pirinc -= 0.06;
									bulgur -= 0.06;
									sogan -= 1;
									tereyag -= 0.012;
									su -= 2;
								}
								DosyaYaz << "Kýrmýzý mercimek:" << kirmiziMercimek << "kg" << endl << "Pirinç: " << pirinc << "kg" << endl << "Bulgur:" << bulgur << "kg" << endl << "Soðan:" << sogan << "adet" << endl << "Tereyaðý:" << tereyag << "kg" << endl <<
									"Su:" << su << "L" << endl << "Tuz:" << tuz << "kg" << endl;
							}
							else if (i == 16)//kuru fasulye 8 kisilik
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									kuruFasulye -= 0.4;
									sogan -= 1;
									salca -= 0.012;
									siviYag -= 0.048;
								}
								DosyaYaz << "Kuru fasulye:" << kuruFasulye << "kg" << endl << "Soðan:" << sogan << "adet" << endl << "Domates salçasý:" << salca << "kg" << endl <<
									"Sývý yað:" << siviYag << "L" << endl;
							}
							else if (i == 17)//karnýyarýk 6 kisilik
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									sogan -= 2;
									domates -= 2;
									siviYag -= 0.012;
									tuz -= 0.006;
									kiyma -= 0.2;
									salca -= 0.012;
									su -= 0.2;
								}
								DosyaYaz << "Soðan:" << sogan << "adet" << endl << "Domates:" << domates << "adet" << endl << "Sývý yað:" << siviYag << "L" << endl << "Kýyma:" << kiyma << "kg" << endl << "Salça:" << salca << "kg" << endl << "Su:" << su << "L" << endl;
							}
							else if (i == 18)//sarma 12 kisilik
							{
								for (int i = 0;i < siparisSayisi;i += 12)
								{
									asmaYapragý -= 1;
									zeytinYagý -= 0.125;
									sogan -= 3;
								}
								DosyaYaz << "Asma yapragi : " << asmaYapragý << "kg" << endl << "Zeytinyaðý:" << zeytinYagý << "L" << endl << " Soðan:" << sogan << "adet" << endl << "Tuz:" << tuz << "kg" << endl <<
									" Pirinç:" << pirinc << "kg" << endl << " Seker:" << seker << "kg" << endl << " Su:" << su << "L" << endl << "Seker:" << seker << "kg" << endl << "Su:" << su << "L" << endl;
							}
							else if (i == 19)//sutlac 6 kiþilik
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									sut -= 1;
									pirinc -= 0.5;
									su -= 1;
									un -= 0.012;
									seker -= 0.5;
								}
								DosyaYaz << "Süt :" << sut << "L" << endl << "Pirinç:" << pirinc << "kg" << endl << "Su:" << su << "L" << endl << "Un:" << un << "kg" << endl <<
									"Seker:" << seker << "kg" << endl;
							}
							else if (i == 20)//muhallebi 4 kisilik
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									seker -= 0.1;
									nisasta -= 0.012;
									un -= 0.036;
									sut -= 0.8;
									tereyag -= 0.006;
								}
								DosyaYaz << "Seker: " << seker << "kg" << endl << "Niþasta:" << nisasta << "kg" << endl << "Un:" << un << "kg" << endl << "Süt:" << sut << "L" << endl << "Tereyaðý:" << tereyag << "kg" << endl << "Vanilya:" << vanilya << "paket" << endl;
							}
							else if (i == 21)//kurabiye   12kisiliik
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									tereyag -= 0.25;
									yumurta -= 1;
									kabartmaTozu -= 1;
									un -= 1;
								}
								DosyaYaz << "Tereyaðý :" << tereyag << "kg" << endl << "Yumurta:" << yumurta << "adet" << endl << "Kabartma tozu:" << kabartmaTozu << "paket" << endl << "Un:" << un << "kg" << endl;
							}
							else if (i == 22)//baklava  16kiþilik
							{
								for (int i = 16;i < siparisSayisi;i += 16)
								{
									yumurta -= 3;
									sut -= 0.25;
									siviYag -= 0.25;
									kabartmaTozu -= 1;
									tuz -= 0.06;
									un -= 1.2;
									ceviz -= 3;
									seker -= 1;
									su -= 1.2;
									tereyag -= 0.3;
								}
								DosyaYaz << "Yumurta:" << yumurta << "adet" << endl << "Süt:" << sut << "L" << endl << "Sývý yað:" << siviYag << "L" << endl << "Kabartma tozu:" << kabartmaTozu << "paket" << endl <<
									"Tuz:" << tuz << "kg" << endl << "Un:" << un << "kg" << endl << "Kýrýlmýþ ceviz ya da fýndýk:" << ceviz << "kg" << endl <<
									"Seker:" << seker << "kg" << endl << "Su:" << su << "L" << endl << "Tereyaðý ya da margarin:" << tereyag << "kg" << endl;
							}
							else if (i == 23)//waffle 4 kisilik
							{
								for (int i = 0;i < siparisSayisi;i += 4)
								{
									yumurta -= 1;
									seker -= 0.012;
									sut -= 0.1;
									siviYag -= 0.024;
									vanilya -= 1;
									kabartmaTozu -= 1;
									un -= 0.2;
								}
								DosyaYaz << "Yumurta:" << yumurta << "adet" << endl << "Seker:" << seker << "kg" << endl << "Süt:" << sut << "L" << endl << "Sývý yað:" << siviYag << "L" << endl << " Vanilin:" << vanilya << "paket" << endl <<
									" Kabartma tozu:" << kabartmaTozu << "paket" << endl << "Un:" << un << "kg" << endl;
							}
							else if (i == 24)//browni 8 kisilik
							{
								for (int i = 0;i < siparisSayisi;i += 8)
								{
									cikolata -= 0.3;
									yumurta -= 3;
									seker -= 0.2;
									tereyag -= 0.150;
									un -= 0.2;
									vanilya -= 1;
								}
								DosyaYaz << "Cikolata:" << cikolata << "kg" << endl << "Yumurta :" << yumurta << "adet" << endl << "Seker:" << seker << "kg" << endl << "Tereyaðý :" << tereyag << "kg" << endl <<
									"Un:" << un << "kg" << endl << "Vanilya:" << vanilya << "paket" << endl;
							}
							else if (i == 25)
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									limonata -= 1;
								}
								DosyaYaz << " Þiþe Limonata:" << limonata << "kutu" << endl;
							}
							else if (i == 26)
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									ayran -= 1;
								}
								DosyaYaz << "Kutu ayran:" << ayran << "kutu" << endl;
							}
							else if (i == 27)
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									kola -= 1;
								}
								DosyaYaz << "Kola:" << kola << "kutu" << endl;
							}
							else if (i == 28)
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									meyveSuyu -= 1;
								}
								DosyaYaz << "MeyveSuyu:" << meyveSuyu << "kutu" << endl;
							}
							else if (i == 29)
							{//soguk cay
								for (int i = 0;i < siparisSayisi;i++)
								{
									sogukCay -= 1;
								}
								DosyaYaz << "Soguk cay:" << sogukCay << "kutu" << endl;
							}
							else if (i == 30)
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									turkKahvesi -= 0.012;
									seker -= 0.006;
								}
								DosyaYaz << "Turk kahvesi:" << turkKahvesi << "kg" << endl << "Seker:" << seker << "kg" << endl;
							}
							else if (i == 31)
							{
								for (int i = 0;i < siparisSayisi;i++)
								{
									kahve -= 0.003;
									su -= 0.2;
								}
								DosyaYaz << "Kahve:" << kahve << "kg" << endl << "Su:" << su << "L" << endl;
							}
							ifstream DosyaOku1("siparis.txt");
							ofstream DosyaYaz1("siparis1.txt", ios::app);
							int a;
							cout << "Siparis listesi icin 1'e basin" << endl;
							cin >> a;
							cout << "Eger biten urun varsa siparis listesine yazildi." << endl;
							if (a == 1)
							{
								DosyaYaz1 << "----------------Siparis Listesi-----------------" << endl;
								if (un < 0)
								{
									DosyaYaz1 << "Un" << endl;
								}
								if (yumurta < 0)
								{
									DosyaYaz1 << "Yumurta" << endl;
								}
								if (su < 0)
								{
									DosyaYaz1 << "Su" << endl;
								}
								if (maya < 0)
								{
									DosyaYaz1 << "Maya" << endl;
								}
								if (tuz < 0)
								{
									DosyaYaz1 << "Tuz" << endl;
								}
								if (kiyma < 0)
								{
									DosyaYaz1 << "Kiyma" << endl;
								}
								if (sogan < 0)
								{
									DosyaYaz1 << "Sogan" << endl;
								}
								if (domates < 0)
								{
									DosyaYaz1 << "Domates" << endl;
								}
								if (salca < 0)
								{
									DosyaYaz1 << "Salca" << endl;
								}
								if (tereyag < 0)
								{
									DosyaYaz1 << "Tereyag" << endl;
								}
								if (seker < 0)
								{
									DosyaYaz1 << "Seker" << endl;
								}
								if (sut < 0)
								{
									DosyaYaz1 << "Sut" << endl;
								}
								if (muz < 0)
								{
									DosyaYaz1 << "Muz" << endl;
								}
								if (pekmez < 0)
								{
									DosyaYaz1 << "Pekmez" << endl;
								}
								if (sucuk < 0)
								{
									DosyaYaz1 << "Sucuk" << endl;
								}
								if (tostEkmegi < 0)
								{
									DosyaYaz1 << "Tost ekmegi" << endl;
								}
								if (kasarPeynir < 0)
								{
									DosyaYaz1 << "Kasar peynir" << endl;
								}
								if (siviYag < 0)
								{
									DosyaYaz1 << "Siviyag" << endl;
								}
								if (kabartmaTozu < 0)
								{
									DosyaYaz1 << "Kabartma tozu" << endl;
								}
								if (vanilya < 0)
								{
									DosyaYaz1 << "Vanilya" << endl;
								}
								if (dolmalýkBiber < 0)
								{
									DosyaYaz1 << "Dolmalik biber" << endl;
								}
								if (pirinc < 0)
								{
									DosyaYaz1 << "Pirinc" << endl;
								}
								if (patates < 0)
								{
									DosyaYaz1 << "Patates" << endl;
								}
								if (makarna < 0)
								{
									DosyaYaz1 << "Makarna" << endl;
								}
								if (tavukSuyu_bulyon < 0)
								{
									DosyaYaz1 << "Tavuksuyu bulyon" << endl;
								}
								if (yufka < 0)
								{
									DosyaYaz1 << "Yufka" << endl;
								}
								if (kirmiziMercimek < 0)
								{
									DosyaYaz1 << "Kirmizi mercimek" << endl;
								}
								if (bezelye < 0)
								{
									DosyaYaz1 << "Bezelye" << endl;
								}
								if (bulgur < 0)
								{
									DosyaYaz1 << "Bulgur" << endl;
								}
								if (kuruFasulye < 0)
								{
									DosyaYaz1 << "Kuru fasulye" << endl;
								}
								if (asmaYapragý < 0)
								{
									DosyaYaz1 << "Asma yapragi" << endl;
								}
								if (zeytinYagý < 0)
								{
									DosyaYaz1 << "Zeytinyagi" << endl;
								}
								if (ceviz < 0)
								{
									DosyaYaz1 << "cikolata" << endl;
								}
								if (cikolata < 0)
								{
									DosyaYaz1 << "Cikolata" << endl;
								}
								if (ayran < 0)
								{
									DosyaYaz1 << "Ayraan" << endl;
								}
								if (limonata < 0)
								{
									DosyaYaz1 << "Limonata" << endl;
								}
								if (kola < 0)
								{
									DosyaYaz1 << "Kola" << endl;
								}
								if (meyveSuyu < 0)
								{
									DosyaYaz1 << "MeyveSuyu" << endl;
								}
								if (sogukCay < 0)
								{
									DosyaYaz1 << "Soguk Cay" << endl;
								}
								if (kahve < 0)
								{
									DosyaYaz1 << "Kahve" << endl;
								}
								if (turkKahvesi < 0)
								{
									DosyaYaz1 << "Turk kahvesi" << endl;
								}
							}
							DosyaYaz1.close();
							DosyaOku1.close();
						}
						cout << "Kalan urun ve tutar depo1 dosyasýna yazildi." << endl;
						cout << "Baska urun siparis etmek ister misiniz?" << endl;
						cout << "1-evet" << endl;
						cout << "2-hayir" << endl;
						cin >> bitir;
						if (bitir == 2)
						{
							break;
						}
						else
						{
							cout << "Devam etmek istiyor musunuz?(e/h)" << endl;
							cin >> chr;
						}
					}
				}
			}
			case 7:
			{
				ifstream("rapor.txt");
				ofstream("rapor.txt");
				float uretilen[32];
				float satilan[32];
				float toplamMaliyet = 0;
				float gelir = 0;
				srand(time(NULL));
				for (int i = 0;i < urunSayisi;i++)
				{
					uretilen[i] = rand() % 11 + 20;
				}
				for (int i = 0;i < urunSayisi;i++)
				{
					satilan[i] = rand() % 19 + 1;
				}
				for (int i = 0;i < urunSayisi;i++)
				{
					toplamMaliyet += uretilen[i] * fiyat[i] - satilan[i] * (fiyat[i] / 3);
				}
				cout << "Toplam Maliyet:" << toplamMaliyet << endl;

				for (int i = 0;i < urunSayisi;i++)
				{
					gelir += satilan[i] * fiyat[i];
				}
				cout << "Gelir:" << gelir << endl;
				float kar = ((gelir - toplamMaliyet) / toplamMaliyet) / 100;
				if (kar > 0)
				{
					cout << "Kar:" << kar << endl;
				}
				else if (kar < 0)
				{
					cout << "Zarar:" << -kar << endl;
				}
			}
			}
			DosyaOku.close();
			DosyaYaz.close();
			cout << "Devam etmek istiyor musunuz?(e/h)" << endl;
			cin >> chr11;
		}while (chr11 == 'e');
	}
};

int main()
{
	Urun urunler;
	urunler.Menu();
	return 0;
}