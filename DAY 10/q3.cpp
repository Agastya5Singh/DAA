#include <bits/stdc++.h>
using namespace std;

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;
void bfs(int v)
{
  for (i = 1; i <= n; i++)
    if (a[v][i] && !visited[i])
      q[++r] = i;
  if (f <= r)
  {
    visited[q[f]] = 1;
    bfs(q[f++]);
  }
}
int main()
{
  int v=1 , count = 0;
  cout << "\n Enter the number of vertices:";
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    q[i] = 0;
    visited[i] = 0;
  }
  cout << "\n Enter graph data in matrix form:\n";
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      cin >> a[i][j];
  bfs(v);

  cout <<"\n rechable vertices:";
    for (i = 1; i <= n; i++)
        if (visited[i])
        cout << i << " ";
  for (i = 1; i <= n; i++)
    if (visited[i])
      count++;
  if (count == n)
    cout << "\n Graph is connected";
  else
    cout << "\n Graph is not connected";
  return 0;
}