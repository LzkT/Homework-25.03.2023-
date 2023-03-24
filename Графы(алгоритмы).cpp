#include <iostream>
#include <vector>
#define inf 100000
using namespace std;

struct Edges {
	int u, v, w;
};

const int Vmax = 1000;
const int Emax = Vmax * (Vmax - 1) / 2;
int i, j, n, e, e2, start, anothere = 0;
Edges edge[Emax];
Edges edge2[Emax];
Edges edge3[Emax];
Edges edge4[Emax];
Edges edge5[Emax];
int h[Vmax];
int d[Vmax];
int d1[Vmax];

//алгоритм Беллмана-Форда
void bellman_ford(int n, int s)
{
	int i, j;

	for (i = 0; i < n; i++) d[i] = inf;
	d[s] = 0;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < e; j++)
			if (d[edge[j].v] + edge[j].w < d[edge[j].u])
				d[edge[j].u] = d[edge[j].v] + edge[j].w;

	for (i = 0; i < n + 1; i++) d1[i] = inf;
	d1[n] = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < e + n; j++)
			if (d1[edge4[j].v] + edge4[j].w < d1[edge4[j].u])
				d1[edge4[j].u] = d1[edge4[j].v] + edge4[j].w;

	cout << endl;
	cout << "Aлгоритм Беллмана-Форда: ";

	for (i = 0; i < n; i++) if (d[i] == inf)
		cout << endl << start << "->" << i + 1 << "=" << "Not";
	else cout << endl << start << "->" << i + 1 << "=" << d[i];

	for (i = 0; i < n + 1; i++)
		if (d1[i] == inf)
		{
			h[i] = 0;
		}
		else h[i] = d1[i];
}

//алгоритм Дейкстры
void Dijkstra(int st, int V)
{
	int** GR = new int* [V];
	for (i = 0; i < V; i++)
	{
		GR[i] = new int[V];
	};

	int s = 0;

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			GR[i][j] = edge2[s].w;
			s++;
		};
	};

	int count, index, p, r, m = st + 1;
	int* distance = new int[V];
	bool* visited = new bool[V];

	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	};

	distance[st] = 0;

	for (count = 0; count < V - 1; count++)
	{
		int min = INT_MAX;

		for (i = 0; i < V; i++)
			if (!visited[i] && (distance[i] <= min))
			{
				min = distance[i];
				index = i;
			};

		r = index;
		visited[r] = true;

		for (i = 0; i < V; i++)
			if (!visited[i] && (GR[r][i] != 0) && (distance[r] != INT_MAX) &&
				(distance[r] + GR[r][i] < distance[i]))
				distance[i] = distance[r] + GR[r][i];
	}
	cout << endl;
	cout << "Алгоритм Дейкстры:\t\n";
	cout << "Стоимость пути из начальной вершины до остальных:\t\n";
	for (p = 0; p < V; p++) if (distance[p] != INT_MAX)
		cout << m << " > " << p + 1 << " = " << distance[p] << endl;
	else cout << m << " > " << p + 1 << " = " << "маршрут недоступен" << endl;


	for (i = 0; i < V; i++)
	{

		delete[] GR[i];

	};

	delete[] distance;
	delete[] visited;
};

//алгоритм Флойда-Уоршелла
void Flo(int V)
{
	int k;

	int** D = new int* [V];
	for (i = 0; i < V; i++)
	{
		D[i] = new int[V];
	};

	int s = 0;

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			D[i][j] = edge3[s].w;
			s++;
		};
	};

	for (i = 0; i < V; i++) D[i][i] = 0;

	for (k = 0; k < V; k++)
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				if (D[i][k] && D[k][j] && i != j)
					if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0)
						D[i][j] = D[i][k] + D[k][j];

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++) cout << D[i][j] << "\t";
		cout << endl;
	};

	for (i = 0; i < V; i++)
	{

		delete[] D[i];

	};
};


void Dijkstra_for_dj(int st, int V)
{
	int** G = new int* [V];
	for (i = 0; i < V; i++)
	{
		G[i] = new int[V];
	};

	int s = 0;

	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			G[i][j] = edge5[s].w;
			s++;
		};
	};

	int count, index, p, r, m = st + 1;
	int* distance = new int[V];
	bool* visited = new bool[V];

	for (i = 0; i < V; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	};

	distance[st] = 0;

	for (count = 0; count < V - 1; count++)
	{
		int min = INT_MAX;

		for (i = 0; i < V; i++)
			if (!visited[i] && (distance[i] <= min))
			{
				min = distance[i];
				index = i;
			};

		r = index;
		visited[r] = true;

		for (i = 0; i < V; i++)
			if (!visited[i] && (G[r][i] != 0) && (distance[r] != INT_MAX) &&
				(distance[r] + G[r][i] < distance[i]))
				distance[i] = distance[r] + G[r][i];


	}
	cout << endl;
	cout << "Алгоритм Джонсона:\t\n";
	cout << "Стоимость пути из начальной вершины до остальных:\t\n";
	for (p = 0; p < V; p++) if (distance[p] != INT_MAX)
		cout << m << " > " << p + 1 << " = " << distance[p] << endl;
	else cout << m << " > " << p + 1 << " = " << "маршрут недоступен" << endl;


	for (i = 0; i < V; i++)
	{

		delete[] G[i];

	};

	delete[] distance;
	delete[] visited;
};

//главная функция
int main()
{
	setlocale(LC_ALL, "Rus");
	int w;

	cout << "Количество вершин > "; cin >> n;
	e = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << "Вес " << i + 1 << "->" << j + 1 << " > "; cin >> w;
			if (w != 0)
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = w;

				edge4[e].v = i;
				edge4[e].u = j;
				edge4[e].w = w;

				e++;
			};

			edge2[anothere].v = i;
			edge2[anothere].u = j;
			edge2[anothere].w = w;

			edge3[anothere].v = i;
			edge3[anothere].u = j;
			edge3[anothere].w = w;

			edge5[anothere].v = i;
			edge5[anothere].u = j;
			edge5[anothere].w = w;

			anothere++;
		};

	int pp = 0;
	e2 = e;
	int y = e;
	for (j = e; j < (e + n); j++)
	{

		edge4[j].v = n;
		edge4[j].u = pp;
		edge4[j].w = 0;

		pp++;
	};

	cout << "Стартовая вершина > ";
	cin >> start;

	cout << "Список кратчайших путей:";
	bellman_ford(n, start - 1);
	Dijkstra(start - 1, n);

	cout << endl;
	cout << "алгоритм Флойда - Уоршелла" << endl;
	cout << "Матрица кратчайших путей:" << endl;
	Flo(n);

	for (i = 0; i < n * n; i++)
	{
		if (edge5[i].w != 0)
		{
			edge5[i].w = edge5[i].w + h[edge5[i].v] - h[edge5[i].u];

		};
	};

	Dijkstra_for_dj(start - 1, n);

	system("pause>>void");
};