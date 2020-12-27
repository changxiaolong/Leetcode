class Solution {
public:
    string multiply(string num1, string num2) {
        		vector<int> result(num1.size() + num2.size() - 1, 0);
		string lon = num1;
		string sort = num2;
		if (num1.size() < num2.size())
		{
			sort = num1;
			lon = num2;
		}
		int sortnum = 0;
		for (string::reverse_iterator it =  sort.rbegin(); it != sort.rend(); it++)
		{
			int snum = *it - '0';
			int lonnum = 0;
			for (string::reverse_iterator itlon = lon.rbegin(); itlon != lon.rend(); itlon++)
			{
				int lnum = *itlon - '0';
				result[sortnum + lonnum] += snum*lnum;
				lonnum++;
			}
			sortnum++;
		}

		for (size_t i = 0; i < result.size() -1; i++)
		{
			result[i + 1] += result[i] / 10;
			result[i] = result[i] % 10;
			if (i == result.size() - 1 && result[i + 1] >= 10)
			{
				result[i + 1] = result[i + 1] % 10;
				result.push_back(result[i + 1] / 10);
			}
		}

		string res = "";
		for (vector<int>::reverse_iterator it = result.rbegin(); it < result.rend(); it++)
		{
			res += to_string(*it);
		}
		for (size_t i = 0; i < res.size(); i++)
		{
			if (res[i] != '0')
			{
				return res.substr(i);
			}
		}
		return "0";
    }
};
