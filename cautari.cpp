#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include <cstdlib>

using namespace std;

			//-------------------------INCEPUT AFISAREA ORASELOR VECINE ALE UNUI ORAS SI AFISAREA TABLEI---------------------
void AfisareaOraselorVecineSiAfisareaTablei() {
	char* nume[20] = { "Arad ->0","Bucuresti ->1","Craiova ->2","Drobeta ->3","Eforie  ->4","Fagarasi ->5","Giurgiu ->6",
				     	//   0         1            2              3            4              5          6
		              "Harsova ->7","Iasi ->8","Lugoj ->9","Mehadia ->10","Neamt ->11","Oradea ->12","Pitesti ->13","Ramnicu-Valcea ->14","Sibiu ->15","Timisoara ->16","Urziceni ->17","Vaslui ->18","Zerind ->19" };
		               // 7           8           9            10           11             12            13                 14               15             16               17            18            19
	int n = 20;
	int i, j, k;
	int a[20][20];




	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;


	a[0][15] = 1;
	a[0][16] = 1;
	a[0][19] = 1;
	a[1][13] = 1;
	a[1][5] = 1;
	a[1][17] = 1;
	a[1][6] = 1;
	a[2][14] = 1;
	a[2][3] = 1;
	a[2][14] = 1;
	a[2][13] = 1;
	a[3][10] = 1;
	a[4][7] = 1;
	a[5][15] = 1;
	a[7][17] = 1;
	a[8][11] = 1;
	a[8][18] = 1;
	a[9][16] = 1;
	a[9][10] = 1;
	a[12][19] = 1;
	a[12][15] = 1;
	a[13][14] = 1;
	a[14][15] = 1;
	a[17][18] = 1;


	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j])
				a[j][i] = 1;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << a[i][j] << " ";

			cout << " " << nume[i] << endl;
	}
	int alegeOras;
	cout <<endl<< "Introduceti numarul unui oras: "; cin >> alegeOras;
	cout << "Orasele care fac legatura cu " << nume[alegeOras] << " sunt:" << endl;

		for (i = 0; i < n; i++)
			if (a[alegeOras][i])
				cout << nume[i] << endl;
}

			//-------------------------SFARSIT AFISAREA ORASELOR VECINE ALE UNUI ORAS SI AFISAREA TABLEI---------------------


			//-------------------------INCEPUT CAUTAREA IN LATIME-----------------------------------------------------------
void CautareInLatime() {

		char* nume[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagarasi","Giurgiu",
			             //   0       1            2         3        4         5          6
			"Harsova","Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","RV","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
		    // 7         8      9       10       11       12       13      14    15        16           17       18        19
		int n = 20;
		int i, j;
		int a[20][20];




		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				a[i][j] = 0;


		a[0][15] = 1;
		a[0][16] = 1;
		a[0][19] = 1;
		a[1][13] = 1;
		a[1][5] = 1;
		a[1][17] = 1;
		a[1][6] = 1;
		a[2][14] = 1;
		a[2][3] = 1;
		a[2][14] = 1;
		a[2][13] = 1;
		a[3][10] = 1;
		a[4][7] = 1;
		a[5][15] = 1;
		a[7][17] = 1;
		a[8][11] = 1;
		a[8][18] = 1;
		a[9][16] = 1;
		a[9][10] = 1;
		a[12][19] = 1;
		a[12][15] = 1;
		a[13][14] = 1;
		a[14][15] = 1;
		a[17][18] = 1;


		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (a[i][j])
					a[j][i] = 1;

		int oras_destinatie=6;
		int oras_start = 11;
		int noduri[20];								//	lista de nodurii!!
		int nr_noduri=0;							//numarul de noduri din lista de nodurii
		int vizitat[20];							//vector care retine daca un oras este vizitat sau nu!!!
		int parinte[20];							//vector care retin vecotrul unui oras
		int gasit = 0;								//gasit =1 cand s-a gasit solutia
		int nod;									//nodul curent
		int solutie[20];							 //vectorul care retine solutia (drumul)
		int nr_solutie = 0;							//numarul de orase din vectorul solutie


		cout << "Drumul de la orasul " << nume[oras_start] << " la orasul " << nume[oras_destinatie] << " este:\n";


		for (i = 0; i < n; i++)
			vizitat[i] = 0;
		noduri[0] = oras_start;						//adaugam orasul de start pe prima pozitie in lista de nodurii!!
		nr_noduri++;								// sa modificat numarul de nodurii
		vizitat[oras_start] = 1;  //

		while ((gasit == 0) && (nr_noduri != 0)) {
			nod = noduri[0];								//am scos primul element din lista de noduri
			for (i = 0; i < nr_noduri - 1; i++)
				noduri[i] = noduri[i + 1];					//eliminam primul element din lista de nodurii
			nr_noduri--;									//scandem numarul de nodurii
			if (nod == oras_destinatie)
				gasit = 1;
			else {
				for (i = 0; i < n; i++)
					if ((a[nod][i] == 1) && (vizitat[i] == 0))		//caut orasele conectate de nodul nod si nevizitate
					{
						noduri[nr_noduri] = i;						//adaugam la sfarsit in lista de noduri orasul i
																	//este singura diferenta intre cautarea in adancime si cea in latime
						nr_noduri++;
						vizitat[i] = 1;
						parinte[i] = nod;
					}
			}




		}

		//Afisarea solutie
		do {
			solutie[nr_solutie] = oras_destinatie;
			nr_solutie++;
			oras_destinatie = parinte[oras_destinatie];
		} while (oras_destinatie != oras_start);

		solutie[nr_solutie] = oras_start;
		for (i = nr_solutie; i >= 0; i--)
			cout << nume[solutie[i]] << " " << endl;
}
			//-------------------------SFARSIT CAUTAREA IN LATIME-----------------------------------------------------------


			//-------------------------INCEPUT CAUTAREA IN ADANCIME---------------------------------------------------------
void CautareaInAdancime() {
	char* nume[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagarasi","Giurgiu",
		            //   0       1            2         3        4         5          6
		"Harsova","Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","RV","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
	     // 7         8      9       10       11       12       13      14    15        16           17       18        19
	int n = 20;
	int i, j, k;
	int a[20][20];




	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;


	a[0][15] = 1;
	a[0][16] = 1;
	a[0][19] = 1;
	a[1][13] = 1;
	a[1][5] = 1;
	a[1][17] = 1;
	a[1][6] = 1;
	a[2][14] = 1;
	a[2][3] = 1;
	a[2][14] = 1;
	a[2][13] = 1;
	a[3][10] = 1;
	a[4][7] = 1;
	a[5][15] = 1;
	a[7][17] = 1;
	a[8][11] = 1;
	a[8][18] = 1;
	a[9][16] = 1;
	a[9][10] = 1;
	a[12][19] = 1;
	a[12][15] = 1;
	a[13][14] = 1;
	a[14][15] = 1;
	a[17][18] = 1;


	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j])
				a[j][i] = 1;

	int oras_destinatie = 6;
	int oras_start = 12;
	int noduri[20];								//	lista de nodurii!!
	int nr_noduri = 0;							//numarul de noduri din lista de nodurii
	int vizitat[20];							//vector care retine daca un oras este vizitat sau nu!!!
	int parinte[20];							//vector care retin vecotrul unui oras
	int gasit = 0;								//gasit =1 cand s-a gasit solutia
	int nod;									//nodul curent
	int solutie[20];							 //vectorul care retine solutia (drumul)
	int nr_solutie = 0;							//numarul de orase din vectorul solutie

	cout << "Drumul de la orasul " << nume[oras_start] << " la orasul " << nume[oras_destinatie] << " este:\n";

												//Algoritmul de cautare in adnacime!!!!!!!!!!!!!!

	for (i = 0; i < n; i++)
		vizitat[i] = 0;
	noduri[0] = oras_start;						//adaugam orasul de start pe prima pozitie in lista de nodurii!!
	nr_noduri++;								// sa modificat numarul de nodurii
	vizitat[oras_start] = 1;  //

	while ((gasit == 0) && (nr_noduri != 0)) {
		nod = noduri[0];								//am scos primul element din lista de noduri
		for (i = 0; i < nr_noduri - 1; i++)
			noduri[i] = noduri[i + 1];					//eliminam primul element din lista de nodurii
		nr_noduri--;									//scandem numarul de nodurii
		if (nod == oras_destinatie)
			gasit = 1;
		else {
			for (i = 0; i < n; i++)
				if ((a[nod][i] == 1) && (vizitat[i] == 0))		//caut orasele conectate de nodul nod si nevizitate
				{
					for (int j = nr_noduri; j > 0; j--)					//am deplasat nodurile din lista de noduri o pozitie spre dreapta
						noduri[j] = noduri[j - 1];
					noduri[0] = i;											//adaugam orasul i pe prima pozitie (la inceput) in lista de noduri
					nr_noduri++;
					vizitat[i] = 1;
					parinte[i] = nod;
				}
		}




	}

	//Afisarea solutie
	do {
		solutie[nr_solutie] = oras_destinatie;
		nr_solutie++;
		oras_destinatie = parinte[oras_destinatie];
	} while (oras_destinatie != oras_start);

	solutie[nr_solutie] = oras_start;

	for (i = nr_solutie; i >= 0; i--)
		cout << nume[solutie[i]] << " "<<endl;
}
			//-------------------------SFARSIT CAUTAREA IN ADANCIME---------------------------------------------------------


			//-------------------------INCEPUT CAUTAREA IN ADANCIME LIMITATA------------------------------------------------
void CautareaInAdancimeLimitata() {
	char* nume[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagarasi","Giurgiu",
		//   0       1            2         3        4         5          6
		"Harsova","Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","RV","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
	// 7         8      9       10       11       12       13      14    15        16           17       18        19
	int n = 20;
	int i, j, k;
	int a[20][20];




	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;


	a[0][15] = 1;
	a[0][16] = 1;
	a[0][19] = 1;
	a[1][13] = 1;
	a[1][5] = 1;
	a[1][17] = 1;
	a[1][6] = 1;
	a[2][14] = 1;
	a[2][3] = 1;
	a[2][14] = 1;
	a[2][13] = 1;
	a[3][10] = 1;
	a[4][7] = 1;
	a[5][15] = 1;
	a[7][17] = 1;
	a[8][11] = 1;
	a[8][18] = 1;
	a[9][16] = 1;
	a[9][10] = 1;
	a[12][19] = 1;
	a[12][15] = 1;
	a[13][14] = 1;
	a[14][15] = 1;
	a[17][18] = 1;


	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j])
				a[j][i] = 1;

			int oras_destinatie=6;
			int oras_start = 12;
			int noduri[20];								//	lista de nodurii!!
			int nr_noduri=0;							//numarul de noduri din lista de nodurii
			int vizitat[20];							//vector care retine daca un oras este vizitat sau nu!!!
			int parinte[20];							//vector care retin vecotrul unui oras
			int gasit = 0;							//gasit =1 cand s-a gasit solutia
			int adancime[20];
			int limita = 4;
			int nod;									//nodul curent
			int solutie[20];							 //vectorul care retine solutia (drumul)
			int nr_solutie = 0;							//numarul de orase din vectorul solutie

			cout << "Drumul de la orasul " << nume[oras_start] << " la orasul " << nume[oras_destinatie] << " este:\n";
	for (i = 0; i < n; i++)
		vizitat[i] = 0;

	noduri[0] = oras_start; //adaugam orasul de start pe prima pozitie din lista de noduri
	nr_noduri++;
	vizitat[oras_start] = 1;
	adancime[oras_start] = 0;


	while ((gasit == 0) && (nr_noduri != 0)) {
		nod = noduri[0]; //am scos primul element din lista de noduri
		for (i = 0; i < nr_noduri - 1; i++)
			noduri[i] = noduri[i + 1];//eliminam primul element din lista de noduri
		nr_noduri--;
		if (adancime[nod] <= limita) {
			if (nod == oras_destinatie)
				gasit = 1;
			else
			{
				for (i = 0; i < n; i++)
					if ((a[nod][i] == 1) && ((vizitat[i] == 0) || ((vizitat[i] == 1) && (adancime[i]>adancime[nod] + 1))))//caut orasele conectate de nodul nod si fie sunt nevizitate, fie sunt vizitate dar la o adancime mai mare decat adancimea la care le gasesc acum
					{												       //adancime veche i	>adancime noua i
						for (j = nr_noduri; j > 0; j--)//am deplasat nodurile din lista de noduri cu o pozitie spre dreapta
							noduri[j] = noduri[j - 1];
						noduri[0] = i; //adauam orasul i pe prima pozitie in lista de noduri
						nr_noduri++;
						vizitat[i] = 1;
						parinte[i] = nod;
						adancime[i] = adancime[nod] + 1;
					}
			}
		}
	}



	//Afisarea solutiei

	do {
		solutie[nr_solutie] = oras_destinatie;
		nr_solutie++;
		oras_destinatie = parinte[oras_destinatie];
	} while (oras_destinatie != oras_start);
	solutie[nr_solutie] = oras_start;

	for (i = nr_solutie; i >= 0; i--)
	cout << nume[solutie[i]]<<" "<<endl;
}
			//-------------------------SFARSIT CAUTAREA IN ADANCIME LIMITATA-----------------------------------------------


			//-------------------------INCEPUT CAUTARE IN ADANCIME INTERATIVA-----------------------------------------------
void CautareaInAdancimeIterativa() {
	char* nume[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagarasi","Giurgiu",
	              	//   0       1            2         3        4         5          6
		"Harsova","Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","RV","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
	    // 7         8      9       10       11       12       13      14    15        16           17       18        19
	int n = 20;
	int i, j, k;
	int a[20][20];




	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;


	a[0][15] = 1;
	a[0][16] = 1;
	a[0][19] = 1;
	a[1][13] = 1;
	a[1][5] = 1;
	a[1][17] = 1;
	a[1][6] = 1;
	a[2][14] = 1;
	a[2][3] = 1;
	a[2][14] = 1;
	a[2][13] = 1;
	a[3][10] = 1;
	a[4][7] = 1;
	a[5][15] = 1;
	a[7][17] = 1;
	a[8][11] = 1;
	a[8][18] = 1;
	a[9][16] = 1;
	a[9][10] = 1;
	a[12][19] = 1;
	a[12][15] = 1;
	a[13][14] = 1;
	a[14][15] = 1;
	a[17][18] = 1;


	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j])
				a[j][i] = 1;

	int oras_destinatie = 6;
	int oras_start = 12;
	int noduri[20];								//	lista de nodurii!!
	int nr_noduri = 0;							//numarul de noduri din lista de nodurii
	int vizitat[20];							//vector care retine daca un oras este vizitat sau nu!!!
	int parinte[20];							//vector care retin vecotrul unui oras
	int gasit = 0;							//gasit =1 cand s-a gasit solutia
	int adancime[20];
	int limita = 0;
	int nod;									//nodul curent
	int solutie[20];							 //vectorul care retine solutia (drumul)
	int nr_solutie = 0;							//numarul de orase din vectorul solutie

	cout << "Drumul de la orasul " << nume[oras_start] << " la orasul " << nume[oras_destinatie] << " este:\n";

	while ((gasit == 0) && (limita < n)) {
		limita++;
		for (i = 0; i < n; i++)
			vizitat[i] = 0;

		noduri[0] = oras_start; //adaugam orasul de start pe prima pozitie din lista de noduri
		nr_noduri++;
		vizitat[oras_start] = 1;
		adancime[oras_start] = 0;


		while ((gasit == 0) && (nr_noduri != 0)) {
			nod = noduri[0]; //am scos primul element din lista de noduri
			for (i = 0; i < nr_noduri - 1; i++)
				noduri[i] = noduri[i + 1];//eliminam primul element din lista de noduri
			nr_noduri--;
			if (adancime[nod] <= limita) {
				if (nod == oras_destinatie)
					gasit = 1;
				else
				{
					for (i = 0; i < n; i++)
						if ((a[nod][i] == 1) && ((vizitat[i] == 0) || ((vizitat[i] == 1) && (adancime[i] > adancime[nod] + 1))))//caut orasele conectate de nodul nod si fie sunt nevizitate, fie sunt vizitate dar la o adancime mai mare decat adancimea la care le gasesc acum
						{												       //adancime veche i	>adancime noua i
							for (j = nr_noduri; j > 0; j--)//am deplasat nodurile din lista de noduri cu o pozitie spre dreapta
								noduri[j] = noduri[j - 1];
							noduri[0] = i; //adauam orasul i pe prima pozitie in lista de noduri
							nr_noduri++;
							vizitat[i] = 1;
							parinte[i] = nod;
							adancime[i] = adancime[nod] + 1;
						}
				}
			}
		}
	}


	//Afisarea solutiei

	do {
		solutie[nr_solutie] = oras_destinatie;
		nr_solutie++;
		oras_destinatie = parinte[oras_destinatie];
	} while (oras_destinatie != oras_start);
	solutie[nr_solutie] = oras_start;

	for (i = nr_solutie; i >= 0; i--)
		cout << nume[solutie[i]] << endl;
	cout << "Solutia s-a gasit la limita " << limita;
}
			//-------------------------SFARSIT CAUTARE IN ADANCIME INTERATIVA-----------------------------------------------

			//------------------------INCEPUT CAUTARE CU COST UNIFORM-------------------------------------------------------

void CautareaCuCostUniform() {
	char* nume[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagarasi","Giurgiu",
		            //   0       1            2         3        4         5          6
		"Harsova","Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","RV","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
	    // 7         8      9       10       11       12       13      14    15        16           17       18        19
		int solutie[20];//vectorul care retine solutia, drumul
		int nr_sol = 0; //numarul de orase din vectorul solutie
		int nod; //retine nodul curent
		int gasit = 0; //gasit=1 cand s-a gasit solutia
		int oras_dest = 6;
		int oras_start = 12;
		int noduri[20]; //lista de noduri
		int nr_noduri = 0; //numarul de noduri din lista de noduri
		int vizitat[20];//vector care retine daca un oras e vizitat sau nu
		int parinte[20];//vector in care retin parintele unui oras
		int n = 20;
		int cost[20];
		int i, j, k;
		int a[20][20];

		for (i = 0; i < n; i++) {
		   for (j = 0; j < n; j++) {
			   a[i][j] = 0;
					}
				}

				a[0][15] = 140;
				a[0][16] = 118;
				a[0][19] = 75;
				a[1][6] = 90;
				a[1][13] = 101;
				a[1][17] = 85;
				a[2][3] = 120;
				a[2][13] = 138;
				a[2][14] = 148;
				a[3][10] = 75;
				a[4][7] = 86;
				a[5][1] = 211;
				a[5][15] = 99;
				a[7][17] = 98;
				a[8][11] = 87;
				a[8][18] = 92;
				a[9][10] = 70;
				a[9][16] = 111;
				a[12][19] = 71;
				a[12][15] = 151;
				a[13][14] = 97;
				a[14][15] = 80;
				a[17][18] = 142;

				cout << "Drumul de la orasul " << nume[oras_start] << " la orasul " << nume[oras_dest] << " este:\n";

				for (i = 0; i < n; i++) {
					for (j = 0; j < n; j++) {
						if (a[i][j] != 0)
							a[j][i] = a[i][j];
					}
				}
	for (i = 0; i < n; i++)
			vizitat[i] = 0;

	//cautarea cu cost uniform
		noduri[0] = oras_start; //adaugam orasul de start pe prima pozitie din lista de noduri
		nr_noduri++;
		vizitat[oras_start] = 1;
		cost[oras_start] = 0;


		while ((gasit == 0) && (nr_noduri != 0)) {
			nod = noduri[0]; //am scos primul element din lista de noduri
			for (i = 0; i < nr_noduri - 1; i++)
				noduri[i] = noduri[i + 1];//eliminam primul element din lista de noduri
			nr_noduri--;

			if (nod == oras_dest)
				gasit = 1;
			else
			{
				for (i = 0; i < n; i++)
					if ((a[nod][i] != 0) && ((vizitat[i] == 0) || ((vizitat[i] == 1) && (cost[i] > cost[nod] + a[nod][i]))))//caut orasele conectate de nodul nod si fie sunt nevizitate, fie sunt vizitate dar la o adancime mai mare decat adancimea la care le gasesc acum
					{												                    //costul vechi i	>  costul noua i
						cost[i] = cost[nod] + a[nod][i];
						k = 0;//pozitia pe care vom insera elementul i in lista de noduri ordonata crescator astfel incat lista sa ramana ordonata
						while ((k < nr_noduri) && (cost[noduri[k]] < cost[i]))
							k++;
						for (j = nr_noduri; j > k; j--)//am deplasat nodurile din lista de noduri cu o pozitie spre dreapta
							noduri[j] = noduri[j - 1];
						noduri[k] = i; //adauam orasul i pe prima pozitie k in lista de noduri ordonata crescator
						nr_noduri++;
						vizitat[i] = 1;
						parinte[i] = nod;

					}
			}
		}
		int c = cost[oras_dest];
		//Afisarea solutiei

		do {
			solutie[nr_sol] = oras_dest;
			nr_sol++;
			oras_dest = parinte[oras_dest];
		} while (oras_dest != oras_start);
		solutie[nr_sol] = oras_start;

		for (i = nr_sol; i >= 0; i--)
			cout << nume[solutie[i]] << endl;
		cout << "Drumul are in total " << c << " km." << endl;
	_getch();
}
			//------------------------SFARSIT CAUTARE CU COST UNIFORM-------------------------------------------------------

			//------------------------INCEPUT CAUTAREA GREEDY---------------------------------------------------------------
void CautareaGreedy() {
	char* nume[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagarasi","Giurgiu",
					//   0       1            2         3        4         5          6
					"Harsova","Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","RV","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
			     	// 7         8      9       10       11       12       13      14    15        16           17       18        19
	int solutie[20];//vectorul care retine solutia, drumul
	int nr_sol = 0; //numarul de orase din vectorul solutie
	int nod; //retine nodul curent
	int gasit = 0; //gasit=1 cand s-a gasit solutia
	int oras_dest = 1;
	int oras_start = 12;
	int noduri[20]; //lista de noduri
	int nr_noduri = 0; //numarul de noduri din lista de noduri
	int vizitat[20];//vector care retine daca un oras e vizitat sau nu
	int parinte[20];//vector in care retin parintele unui oras
	int n = 20;
	int cost[20];//costul uni nod este distanta pana la oras start

	int i, j, k;
	int a[20][20];

	int h[20] = { 366,0,160,242,161,176,77,151,226,224,241,234,380,10,193,253,329,80,199,374 }; //heuristica ====vector care retine distantele in linie dreapta de la fiecare oras la bucuresti


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}

	a[0][15] = 140;
	a[0][16] = 118;
	a[0][19] = 75;
	a[1][6] = 90;
	a[1][13] = 101;
	a[1][17] = 85;
	a[2][3] = 120;
	a[2][13] = 138;
	a[2][14] = 148;
	a[3][10] = 75;
	a[4][7] = 86;
	a[5][1] = 211;
	a[5][15] = 99;
	a[7][17] = 98;
	a[8][11] = 87;
	a[8][18] = 92;
	a[9][10] = 70;
	a[9][16] = 111;
	a[12][19] = 71;
	a[12][15] = 151;
	a[13][14] = 97;
	a[14][15] = 80;
	a[17][18] = 142;

	cout << "Drumul de la orasul " << nume[oras_start] << " la orasul " << nume[oras_dest] << " este:\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] != 0)
				a[j][i] = a[i][j];
		}
	}
	for (i = 0; i < n; i++)
		vizitat[i] = 0;


	//cautarea GREEDY-Lacom
	noduri[0] = oras_start; //adaugam orasul de start pe prima pozitie din lista de noduri
	nr_noduri++;
	vizitat[oras_start] = 1;
	cost[oras_start] = 0;


	while ((gasit == 0) && (nr_noduri != 0)) {
		nod = noduri[0]; //am scos primul element din lista de noduri
		for (i = 0; i < nr_noduri - 1; i++)
			noduri[i] = noduri[i + 1];//eliminam primul element din lista de noduri
		nr_noduri--;

		if (nod == oras_dest)
			gasit = 1;
		else
		{
			for (i = 0; i < n; i++)
				if ((a[nod][i] != 0) && ((vizitat[i] == 0) || ((vizitat[i] == 1) && (cost[i] > cost[nod] + a[nod][i]))))//caut orasele conectate de nodul nod si fie sunt nevizitate, fie sunt vizitate dar la o adancime mai mare decat adancimea la care le gasesc acum
				{												                    //costul vechi i	>costul noua i
					cost[i] = cost[nod] + a[nod][i];
					k = 0;//pozitia pe care vom insera elementul i in lista de noduri ordonata crescator astfel incat lista sa ramana ordonata
					while ((k < nr_noduri) && (h[noduri[k]] < h[i]))
						k++;
					for (j = nr_noduri; j > k; j--)//am deplasat nodurile din lista de noduri cu o pozitie spre dreapta
						noduri[j] = noduri[j - 1];
					noduri[k] = i; //adauam orasul i pe prima pozitie k in lista de noduri ordonata crescator
					nr_noduri++;
					vizitat[i] = 1;
					parinte[i] = nod;

				}
		}
	}
		int c = cost[oras_dest];
		//Afisarea solutiei

		do {
			solutie[nr_sol] = oras_dest;
			nr_sol++;
			oras_dest = parinte[oras_dest];
		} while (oras_dest != oras_start);
		solutie[nr_sol] = oras_start;

		for (i = nr_sol; i >= 0; i--)
			cout << nume[solutie[i]] << endl;
		cout << "Drumul are in total " << c << " km." << endl;
		_getch();
	}

			//------------------------SFARSIT CAUTAREA GREEDY---------------------------------------------------------------

			//------------------------INCEPUT CAUTAREA A*---------------------------------------------------------------
void CautareaA() {
		char* nume[20] = { "Arad","Bucuresti","Craiova","Drobeta","Eforie","Fagarasi","Giurgiu",
		             	//   0       1            2         3        4         5          6
			"Harsova","Iasi","Lugoj","Mehadia","Neamt","Oradea","Pitesti","RV","Sibiu","Timisoara","Urziceni","Vaslui","Zerind" };
		     // 7         8      9       10       11       12       13      14    15        16           17       18        19
		int solutie[20];//vectorul care retine solutia, drumul
		int nr_sol = 0; //numarul de orase din vectorul solutie
		int nod; //retine nodul curent
		int gasit = 0; //gasit=1 cand s-a gasit solutia
		int oras_dest = 1;
		int oras_start = 12;
		int noduri[20]; //lista de noduri
		int nr_noduri = 0; //numarul de noduri din lista de noduri
		int vizitat[20];//vector care retine daca un oras e vizitat sau nu
		int parinte[20];//vector in care retin parintele unui oras
		int n = 20;
		int cost[20];//costul uni nod este distanta pana la oras start

		int i, j, k;
		int a[20][20];

		int h[20] = { 366,0,160,242,161,176,77,151,226,224,241,234,380,10,193,253,329,80,199,374 }; //heuristica ====vector care retine distantele in linie dreapta de la fiecare oras la bucuresti
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				a[i][j] = 0;
			}
		}

		a[0][15] = 140;
		a[0][16] = 118;
		a[0][19] = 75;
		a[1][6] = 90;
		a[1][13] = 101;
		a[1][17] = 85;
		a[2][3] = 120;
		a[2][13] = 138;
		a[2][14] = 148;
		a[3][10] = 75;
		a[4][7] = 86;
		a[5][1] = 211;
		a[5][15] = 99;
		a[7][17] = 98;
		a[8][11] = 87;
		a[8][18] = 92;
		a[9][10] = 70;
		a[9][16] = 111;
		a[12][19] = 71;
		a[12][15] = 151;
		a[13][14] = 97;
		a[14][15] = 80;
		a[17][18] = 142;

		cout << "Drumul de la orasul " << nume[oras_start] << " la orasul " << nume[oras_dest] << " este:\n";

		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (a[i][j] != 0)
					a[j][i] = a[i][j];
			}
		}
		for (i = 0; i < n; i++)
			vizitat[i] = 0;


		//CAutarea A*
		noduri[0] = oras_start; //adaugam orasul de start pe prima pozitie din lista de noduri
		nr_noduri++;
		vizitat[oras_start] = 1;
		cost[oras_start] = 0;


		while ((gasit == 0) && (nr_noduri != 0)) {
			nod = noduri[0]; //am scos primul element din lista de noduri
			for (i = 0; i < nr_noduri - 1; i++)
				noduri[i] = noduri[i + 1];//eliminam primul element din lista de noduri
			nr_noduri--;

			if (nod == oras_dest)
				gasit = 1;
			else
			{
				for (i = 0; i < n; i++)
					if ((a[nod][i] != 0) && ((vizitat[i] == 0) || ((vizitat[i] == 1) && (cost[i] > cost[nod] + a[nod][i]))))//caut orasele conectate de nodul nod si fie sunt nevizitate, fie sunt vizitate dar la o adancime mai mare decat adancimea la care le gasesc acum
					{												                    //costul vechi i	>costul noua i
						cost[i] = cost[nod] + a[nod][i];
						k = 0;//pozitia pe care vom insera elementul i in lista de noduri ordonata crescator astfel incat lista sa ramana ordonata
						while ((k < nr_noduri) && (cost[noduri[k]] + h[noduri[k]] <cost[i] + h[i]))
							k++;
						for (j = nr_noduri; j > k; j--)//am deplasat nodurile din lista de noduri cu o pozitie spre dreapta
							noduri[j] = noduri[j - 1];
						noduri[k] = i; //adauam orasul i pe prima pozitie k in lista de noduri ordonata crescator
						nr_noduri++;
						vizitat[i] = 1;
						parinte[i] = nod;

					}
			}
		}
		int c = cost[oras_dest];
		//Afisarea solutiei

		do {
			solutie[nr_sol] = oras_dest;
			nr_sol++;
			oras_dest = parinte[oras_dest];
		} while (oras_dest != oras_start);
		solutie[nr_sol] = oras_start;

		for (i = nr_sol; i >= 0; i--)
			cout << nume[solutie[i]] << endl;
		cout << "Drumul are in total " << c << " km." << endl;
		_getch();
}


			//------------------------SFARSIT CAUTAREA A*---------------------------------------------------------------
void meniul_principal() {
	int op, i;
	char c;

	do {
		//system("cls");
		cout << endl << endl << endl;
		cout << "			MENIUL PRINCIPAL" << endl << endl << endl;
		for (i = 1; i <= 80; i++)
			cout << "=";
		cout << endl << endl << endl;
		cout << " 1. Afisarea Vecinilor Unui Oras Si Afisarea Tablei" << endl << endl;
		cout << " 2. Cautarea In Latime" << endl << endl;
		cout << " 3. Cautarea In Adancime" << endl << endl;
		cout << " 4. Cautarea In Adancime Limitata" << endl << endl;
		cout << " 5. Cautarea In Adancime Iterativa" << endl << endl;
		cout << " 6. Cautarea Cu Cost Uniform" << endl << endl;
		cout << " 7. Cautarea Greedy" << endl << endl;
		cout << " 8. Cautarea A*" << endl << endl;
		for (i = 1; i <= 80; i++)
			cout << "-";
		cout << endl << endl;
		cout << " 9. Exit" << endl << endl;
		for (i = 1; i <= 80; i++)
			cout << "=";
		cout << endl << endl;
		cout << " Operatia dorita [1...9] ->"; cin >> op;
		switch (op) {
		case 1:
			system("cls");
			AfisareaOraselorVecineSiAfisareaTablei();
			_getch();
			break;

		case 2:
			system("cls");
			CautareInLatime();
			_getch();
			break;
		case 3:
			system("cls");
			CautareaInAdancime();
			_getch();
			break;
		case 4:
			system("cls");
			CautareaInAdancimeLimitata();
			_getch();
			break;
		case 5:
			system("cls");
			CautareaInAdancimeIterativa();
			_getch();
			break;
		case 6:
			system("cls");
			CautareaCuCostUniform();
			_getch();
			break;
		case 7:
			system("cls");
			CautareaGreedy();
			_getch();
			break;
		case 8:
			system("cls");
			CautareaA();
			_getch();
			break;
		}
	} while (op != 9);
}


int main() {
	meniul_principal();
	return 0;
}
