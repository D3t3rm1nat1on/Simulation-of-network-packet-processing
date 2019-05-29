#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

struct Pocket
{
	int indx;
	int arrival;
	int duration;
};

int main()
{
	queue <Pocket> pocket;
	queue <Pocket> buff;
	int size, n;
	cin >> size >> n;
	vector <int> result(n);
	for (int i = 0; i < n; i++)
		result[i] = -2;
	if (size == 0)
	{
		for (int i = 0; i < n; i++)
			cout << -1 << endl;
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		Pocket temp;
		temp.indx = i;
		cin >> temp.arrival >> temp.duration;
		pocket.push(temp);
	}
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		if (buff.empty())
		{
			time = pocket.front().arrival;
			result[i] = time;
			buff.push(pocket.front());
			pocket.pop();
			continue;
		}
		while (!buff.empty() && pocket.front().arrival - time >= buff.front().duration)
		{
			time += buff.front().duration;
			buff.pop();
			if (!buff.empty())
			result[buff.front().indx] = time;
		}
		if (!buff.empty())
			buff.front().duration -= pocket.front().arrival - time;
		time = pocket.front().arrival;
		if (buff.size() == size)
		{
			result[i] = -1;
			pocket.pop();
			continue;
		}
		buff.push(pocket.front());
		result[i] = time;
		pocket.pop();
	}
	while (buff.size() > 1)
	{
		int temp = buff.front().duration;
		buff.pop();
		result[buff.front().indx] = time + temp;
		time += temp;
	}
	for (auto now : result)
	{
		cout << now << endl;
	}
	return 0;
}