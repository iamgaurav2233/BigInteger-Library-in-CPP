class BigInteger{
public:
string add(string a, string b)
{
    string sum = "";
    long long i = (long long)a.size() - 1, j = (long long)b.size() - 1;
    long long carry = 0;
    while (i >= 0 or j >= 0)
    {
        carry += (a[i] - '0') * (i >= 0) + (b[j] - '0') * (j >= 0);
        sum += '0' + (carry % 10);
        carry /= 10;
        i--;
        j--;
    }
    while (carry)
    {
        sum += '0' + (carry % 10);
        carry /= 10;
    }
    reverse(all(sum));
    return sum;
}

   string mul(string num1, string num2)
{
   string s = "";
   if((num1.at(0) == '-' || num2.at(0) == '-') &&
      (num1.at(0) != '-' || num2.at(0) != '-' ))
      s='-'+s;

   if(num1.at(0) == '-')
      num1 = num1.substr(1);

   if(num2.at(0) == '-')
      num2 = num2.substr(1);
   int len1 = num1.size();
   int len2 = num2.size();
   if (len1 == 0 || len2 == 0)
   return "0";
   vector<int> result(len1 + len2, 0);
   int i_n1 = 0;
   int i_n2 = 0;
      for (int i=len1-1; i>=0; i--)
   {
      int carry = 0;
      int n1 = num1[i] - '0';
      i_n2 = 0;
            for (int j=len2-1; j>=0; j--)
      {
         int n2 = num2[j] - '0';
         int sum = n1*n2 + result[i_n1 + i_n2] + carry;

         carry = sum/10;

         result[i_n1 + i_n2] = sum % 10;

         i_n2++;
      }

      if (carry > 0)
         result[i_n1 + i_n2] += carry;

      i_n1++;
   }

   int i = result.size() - 1;
   while (i>=0 && result[i] == 0)
   i--;

   if (i == -1)
   return "0";     
   while (i >= 0)
      s += std::to_string(result[i--]);
   return s;
}
};
