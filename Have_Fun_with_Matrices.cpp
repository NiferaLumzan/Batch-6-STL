#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<sstream>
#include<set>
#include<queue>
//#define fin freopen("test.TXT","r",stdin)

using namespace std;
typedef long long ll;

/* Have fun with matrices */

int option(string s)
{
//    cout << s << endl;
    istringstream ss(s);
    string s1;
    bool first = true;
    do
    {
        ss >> s;
        break;
    }
    while(ss);

    if(s == "row")
    {
        return 1;
    }
    else if(s == "col")
    {
        return 2;
    }
    else if(s == "inc")
    {
        return 3;
    }
    else if(s == "dec")
    {
        return 4;
    }
    else if(s == "transpose")
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

int main()
{
//    fin;
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << endl;
        int rowCol;
        cin >> rowCol;
        int mat[rowCol][rowCol];

        //-----------input
        int rows;
        vector<int> v;
        for(int i = 0; i < rowCol; i++)
        {
            cin >> rows;
            v.push_back(rows);
        }
        for(int i = 0; i< rowCol; i++)
        {
            for(int j = rowCol-1; j >= 0; j--)
            {
                int last = v.at(i) % 10;
                v[i] = (int)v.at(i)/10;
                mat[i][j] = last;
            }
        }

//        for(int i = 0; i< rowCol; i++)
//        {
//            for(int j = 0; j<rowCol; j++)
//                cout << mat[i][j];
//        }


        int op;
        cin >> op;
        cin.ignore(); // for getline() to work perfectly
        vector<string> choise;
        while(op--)
        {
            string s;
            std::getline(cin, s);
//            cout << s << endl;
            choise.push_back(s);
        }
//        cout << choise.size();
        for(int i = 0; i< choise.size(); i++)
        {
//            cout << choise.at(i) << endl;
        }

        for(int i = 0; i< choise.size(); i++)
        {
//            cout <<"choise.at(i): " << choise.at(i) << endl;
            int op = option(choise.at(i));
//            cout << op << endl;
            int newMat[rowCol][rowCol];

            if(op == 1) //row a b
            {
                string s = choise.at(i);
                istringstream ss(s);
                int co = 0, r1,r2;
                do
                {
                    if(co == 1)
                    {
                        ss >> r1;
//                        cout << r1;
                        co++;
                    }
                    else if (co == 2)
                    {
                        ss >> r2;
//                        cout << r2;
                        co++;
                    }
                    else
                    {
                        ss >> s;
                        co++;
                    }
                }
                while(ss);

                for(int j = 0; j<rowCol; j++)
                {
                    int temp = mat[r1-1][j];
                    mat[r1-1][j] = mat[r2-1][j];
                    mat[r2-1][j] = temp;
                }
            }
            else if(op == 2) // col a b
            {
                string s = choise.at(i);
                istringstream ss(s);
                int co = 0, r1,r2;
                do
                {
                    if(co == 1)
                    {
                        ss >> r1;
//                        cout << r1;
                        co++;
                    }
                    else if (co == 2)
                    {
                        ss >> r2;
//                        cout << r2;
                        co++;
                    }
                    else
                    {
                        ss >> s;
                        co++;
                    }
                }
                while(ss);

                for(int j = 0; j<rowCol; j++)
                {
                    int temp = mat[j][r1-1];
                    mat[j][r1-1] = mat[j][r2-1];
                    mat[j][r2-1] = temp;
                }
            }
            else if(op == 3) // inc
            {
                for(int i = 0; i<rowCol; i++)
                {
                    for(int j = 0; j<rowCol; j++)
                    {
                        mat[i][j]++;
                        if(mat[i][j] == 10)
                            mat[i][j] = 0;
                    }
                }
            }
            else if(op == 4) //dec
            {
                for(int i = 0; i<rowCol; i++)
                {
                    for(int j = 0; j<rowCol; j++)
                    {
                        mat[i][j]--;
                        if(mat[i][j] == -1)
                            mat[i][j] = 9;
                    }
                }
            }
            else if(op == 5) //transpose
            {
                int newMat[rowCol][rowCol];
                for(int i = 0; i<rowCol; i++)
                {
                    for(int j = 0; j<rowCol; j++)
                    {
                        newMat[i][j] = mat[j][i];
                        newMat[j][i] = mat[i][j];
                    }
                }
                for(int i = 0; i<rowCol; i++)
                {
                    for(int j = 0; j<rowCol; j++)
                    {
                        mat[i][j] = newMat[i][j];
                    }
                }
            }
            else
            {
                break;
            }
        }

        //print
        for(int i = 0; i< rowCol; i++)
        {
            for(int j = 0; j<rowCol; j++)
            {
                cout << mat[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
