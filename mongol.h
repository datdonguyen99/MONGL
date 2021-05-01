//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any
// other libraries.

#include <string>
string readyForBattle(const string ID[], const int NID, const string input1[],
                      const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str,
                             const string input7Matrix[], const int k);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////

/*char decodeToChar(string ip1) {
  string s0 = "EFGHIJK";
  string s1 = "LMNOPQR";
  string s2 = "#TUVWXY";
  string s3 = "@ASZBCD";
  if (ip1[0] == '0') {
    return s0[ip1.size() % 7 - 1];
  } else if (ip1[0] == '1') {
    return s1[ip1.size() % 7 - 1];
  } else if (ip1[0] == '2') {
    return s2[ip1.size() % 7 - 1];
  } else if (ip1[0] == '3') {
    return s3[ip1.size() % 7 - 1];
  }
}

int bcdToDecimal(string ip1) {
  int len = ip1.length(), check = 0, check0 = 0;
  int num = 0, sum = 0, mul = 1, rev = 0;

  for (int i = len - 1; i >= 0; i--) {
    sum += (ip1[i] - '0') * mul;
    mul *= 2;
    check++;
    if (check == 4 || i == 0) {
      if (sum == 0 && check0 == 0) {
        num = 1;
        check0 = 1;
      } else {
        // update the answer
        num = num * 10 + sum;
      }
      check = 0;
      sum = 0;
      mul = 1;
    }
  }
  // Reverse the number formed.
  while (num > 0) {
    rev = rev * 10 + (num % 10);
    num /= 10;
  }

  if (check0 == 1) {
    return rev - 1;
  }
  return rev;
}

string decodeStr(string ip1) {
  string rong = " ";
  string temps;
  int current;
  int next = -1;
  int temp;
  do {
    current = next + 1;
    next = ip1.find_first_of(rong, current);
    temp = bcdToDecimal(ip1.substr(current, next - current));
    temps = temps + decodeToChar(to_string(temp));

  } while (next != string::npos);
  return temps;
}

int checkVua(string ID) {
  int found1 = ID.find("VUA");
  string t2 = ID.substr(1, ID.size() - 2);
  int found2 = t2.find("THD");
  if (found1 == 0) {
    return 1;
  } else if (found2 != std::string::npos) {
    return 2;
  } else {
    return 0;
  }
}

string bubbleSrt(string str2) {
  string str = str2;
  size_t n = str.size();
  size_t i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (str[j] > str[j + 1]) {
        char temp = str[j + 1];
        str[j + 1] = str[j];
        str[j] = temp;
      }
  return str;
}

string vuaDecode(string ip1, int id) {
  if (id == 1) {
    if (ip1.size() <= 2) {
      return ip1;
    } else {
      string rev = string(ip1.rbegin(), ip1.rend()); // reverse string
      string res;
      for (int i = 0; i < rev.size(); i++) {
        if (rev[i] > ip1[i])
          res = res + rev[i];
        else
          res = res + ip1[i];
      }
      return res;
    }
  } else if (id == 2) {
    for (size_t i = 0; i < ip1.length(); i++) {
      if (i % 3 == 0) {
        ip1 += ip1[i];
      }
    }
    return bubbleSrt(ip1);
  } else {
    return ip1;
  }
}

string decodeStr1(string s, int id) {
  if (s[0] == '#') {
    char temp = s[s.size() - 1];
    s.erase(0, 1);

    if (temp == 'Z') {
      string tt = s + 'A';
      return vuaDecode(tt, id);
    } else
      return vuaDecode(s + (++temp), id);
  } else if (s[0] == '@') {
    s.erase(0, 1);
    string rev = string(s.rbegin(), s.rend()); // reverse string
    return vuaDecode(rev, id);
  } else {
    return vuaDecode(s, id);
  }
  /// e-learning.hcmut.edu.vn/mod/forum/discuss.php?d=134037
}
// const string ip2[] = {"EFGHIJK", "LMNOPQR", "#TUVWXY", "@ASZBCD"};
// string retu = "";*/
string readyForBattle(const string ID[], const int NID, const string input1[],
                      const int N1) {
  // return "You can remove this return";
  // vector<int> decodeStep1;
  // vector<char> decodeStep2;
  /*string ip1;
  string temp = "";
  string temp1 = "";
  int id = 0;
  for (int i = 0; i < NID; i++) {
    if (checkVua(ID[i]) > id) {
      id = checkVua(ID[i]);
    }
  }
  for (int i = 0; i < N1; i++) {
    ip1 = input1[i];
    temp = decodeStr(ip1);
    temp1 = temp1 + " " + decodeStr1(temp, id);
  }
  temp1.erase(0, 1);
  return temp1;*/

  /*////// BEGIN DECODE TO DECIMAL ///////*/
  string ip1 = "";
  bool check = false;
  for (int i = 0; i < N1; i++) {
    for (int j = 0; j < input1[i].length(); check ? (j += 1) : (j += 2)) {
      if (input1[i][j] == ' ') {
        check = true;
        ip1 += ' ';
      } else {
        check = false;
        if (input1[i][j] == 48 && input1[i][j + 1] == 48) {
          ip1 += '0';
          // cout << "k";
        } else if (input1[i][j] == 48 && input1[i][j + 1] == 49) {
          ip1 += '1';
          // cout << "m";
        } else if (input1[i][j] == 49 && input1[i][j + 1] == 48) {
          ip1 += '2';
          // cout << "h";
        } else if (input1[i][j] == 49 && input1[i][j + 1] == 49) {
          ip1 += '3';
          // cout << "b";
        }
      }
    }
    ip1 += ' ';
    if (i + 1 != N1) {
      ip1 += '!';
    }
  }
  /*////// END DECODE TO DECIMAL ///////*/

  cout << ip1 << "dat" << endl;
  /*////// BEGIN DECODE TO ALPHABET ///////*/
  int pos = 0;
  int posTem = 0;
  string space = " ";
  string row;
  char temp;
  string decode2 = "";

  pos = ip1.find(space, pos);
  while (pos < ip1.length()) {
    row = ip1.substr(posTem, pos - posTem);
    string strDecode2 = "";
    int cntStep = 0;
    for (int i = 0; i < row.length(); i += cntStep) {
      temp = row[i];
      int cnt = 0;

      for (int j = i; j < row.length(); j++) {
        if (temp != row[j]) {
          break;
        }
        cnt++;
      }
      cntStep = cnt;
      if (cnt > 7) {
        cnt = cnt % 7;
      }
      cout << cntStep << " ";
      if (cnt == 1) {
        if (row[i] == '0') {
          strDecode2 += 'E';
        } else if (row[i] == '1') {
          strDecode2 += 'L';
        } else if (row[i] == '2') {
          strDecode2 += '#';
        } else if (row[i] == '3') {
          strDecode2 += '@';
        }
      } else if (cnt == 2) {
        if (row[i] == '0') {
          strDecode2 += 'F';
        } else if (row[i] == '1') {
          strDecode2 += 'M';
        } else if (row[i] == '2') {
          strDecode2 += 'T';
        } else if (row[i] == '3') {
          strDecode2 += 'A';
        }
      } else if (cnt == 3) {
        if (row[i] == '0') {
          strDecode2 += 'G';
        } else if (row[i] == '1') {
          strDecode2 += 'N';
        } else if (row[i] == '2') {
          strDecode2 += 'U';
        } else if (row[i] == '3') {
          strDecode2 += 'S';
        }
      } else if (cnt == 4) {
        if (row[i] == '0') {
          strDecode2 += 'H';
        } else if (row[i] == '1') {
          strDecode2 += 'O';
        } else if (row[i] == '2') {
          strDecode2 += 'V';
        } else if (row[i] == '3') {
          strDecode2 += 'Z';
        }
      } else if (cnt == 5) {
        if (row[i] == '0') {
          strDecode2 += 'I';
        } else if (row[i] == '1') {
          strDecode2 += 'P';
        } else if (row[i] == '2') {
          strDecode2 += 'W';
        } else if (row[i] == '3') {
          strDecode2 += 'B';
        }
      } else if (cnt == 6) {
        if (row[i] == '0') {
          strDecode2 += 'J';
        } else if (row[i] == '1') {
          strDecode2 += 'Q';
        } else if (row[i] == '2') {
          strDecode2 += 'X';
        } else if (row[i] == '3') {
          strDecode2 += 'C';
        }
      } else if (cnt == 7) {
        if (row[i] == '0') {
          strDecode2 += 'K';
        } else if (row[i] == '1') {
          strDecode2 += 'R';
        } else if (row[i] == '2') {
          strDecode2 += 'Y';
        } else if (row[i] == '3') {
          strDecode2 += 'D';
        }
      }
      // cout << temp << " ";
    }
    decode2 += strDecode2;
    // decode2 += " ";
    // cout << cnt << endl;
    // cout << temp << " ";
    // cout << pos << " ";
    if (ip1[pos + 1] == '!') {
      decode2 += ' ';
    }
    pos += space.length();
    posTem = pos;
    pos = ip1.find(space, pos);
  }
  /*////// END DECODE TO ALPHABET ///////*/

  cout << '\n' << decode2 << "|" << endl;

  for (int i = 0; i < decode2.length(); i++) {
    if (decode2[i] == '#') {
      for (int j = i + 1; j < decode2.length(); j++) {
        if (decode2[j] == '#' || decode2[j] == '@' || decode2[j] == ' ' ||
            j == decode2.length() - 1) {
          if (j == decode2.length() - 1) {
            j += 1;
          }
          char prior = (int)decode2[j - 1];
          // cout << "prior: " << (int)prior << endl;
          if ((int)prior > 64 && (int)prior < 91) {
            if ((int)prior == 90) {
              prior = 65;
            } else {

              prior += 1;
            }
            string tempt = decode2.substr(j, decode2.length() - j);
            decode2.erase(j, decode2.length() - j);
            decode2 += prior + tempt;
          }
          break;
        }
      }
    } else if (decode2[i] == '@') {
      string temptReverse = "";
      int j = 0;
      for (j = i + 1; j < decode2.length(); j++) {
        if (decode2[j] == '#' || decode2[j] == '@' || decode2[j] == ' ') {
          break;
        }
        temptReverse += decode2[j];
      }
      string temptPostReverse = decode2.substr(j, decode2.length() - j);
      decode2.erase(i + 1, decode2.length());
      for (int k = temptReverse.length() - 1; k >= 0; k--) {
        decode2 += temptReverse[k];
      }
      decode2 += temptPostReverse;
    }
  }
  cout << decode2 << "|";
  /*while (!ip1.empty()) {
    string temp = ip1.substr(0, ip1.find(" "));
    cout << temp;
    if (ip1.find(" ") > ip1.size()) {
      break;
    } else {
      ip1.erase(0, ip1.find(" ") + 1);
    }
  }*/

  /*
    string retu = "";
    for (int i = 0; i < N1; i++) {
      string temp = input1[i];
      for (int j = 0; j < 7; j++) {
      }
    }

    for (int i = 0; i < decodeStep1.length(); i++) {
      int row = (int)decodeStep1[0];
      for (int j = 0; j < decodeStep1.length(); j++) {
        if (decodeStep1[i] != ' ') {
          counter++;
        }
      }
      char temp = ip1[row][(counter - 1) % 7];
    }*/

  /*string *ip1 = new string[N1];
  for(int i = 0; i < decodeStep1.size();i++){
    ip[i] = decodeStep1[i];
    if(decodeStep1[i] == 4){
      ip1[i] = ' ';
    }
    if(decodeStep1[i] == 5){

    }
  }*/
  /*
  ** AFTER DECODE STEP1, 0,1,2,3 was stored in decodeStep1
  ** and 4 is space between string
  ** and 5 is signal end 1 line
  */
  cout << endl;
  return "You can remove this return";
}

int decode(const string A, const string B) {
  // return -1;
  char *str = new char[A.size() + 1];
  copy(A.begin(), A.end(), str);
  char *substr = new char[B.size() + 1];
  copy(B.begin(), B.end(), substr);

  bool check = false;
  int count = 0;

  for (int i = 0; i < A.length(); i++) {
    if (str[i] == substr[0]) {
      check = true;
      for (int j = 0; j < B.length(); j++) {
        if (substr[j] != substr[i + j]) {
          check = false;
          break;
        }
      }
      if (check == true) {
        count++;
      }
    }
  }
  delete[] str;
  delete[] substr;
  return count;
}

void shiftLeft(string &A, int &numShift) {
  string temp = A.substr(0, numShift);
  A.erase(0, numShift);
  A = A + temp;
}
void shiftRight(string &A, int &numShift) {
  int numNoShift = A.length() - numShift;
  string temp = A.substr(numNoShift, numShift);
  A.erase(numNoShift, numShift);
  A = temp + A;
}

string findRoute(const string input3) {
  // return "You can remove this return";
  vector<string> vecStr;
  string Str = input3;
  while (!Str.empty()) {
    vecStr.push_back(Str.substr(0, Str.find(" ")));
    if (Str.find(" ") > Str.size()) {
      break;
    } else {
      Str.erase(0, Str.find(" ") + 1);
    }
  }

  // vector<string> vec;
  string NN = vecStr[0];
  string BB = vecStr[1];
  string SS = vecStr[2];

  char *pN = new char[NN.size() + 1];
  std::copy(NN.begin(), NN.end(), pN);
  char *pB = new char[BB.size() + 1];
  std::copy(BB.begin(), BB.end(), pB);

  if (atoi(pB) < 0) {
    int numB = atoi(pB) - atoi(pB) * 2;
    int lenS = SS.length();
    if (numB >= lenS) {
      numB = numB % lenS;
    }

    if (numB != 0) {
      shiftLeft(SS, numB);
    }
  } else if (atoi(pB) > 0) { //////////////////////////
    int numB = atoi(pB);
    int lenS = SS.length();
    if (numB >= lenS) {
      numB = numB % lenS;
    }
    if (numB != 0) {
      shiftRight(SS, numB);
    }
  }

  for (int m = 0; m < SS.length(); m++) {
    int t = 0;
    int shift = atoi(pN) - 2 * m;
    if (shift < 0) {
      shift = shift - shift * 2; // absolute
    }

    if (SS[m] == 'U') {
      t = 0;
    } else if (SS[m] == 'D') {
      t = 1;
    } else if (SS[m] == 'L') {
      t = 2;
    } else if (SS[m] == 'R') {
      t = 3;
    }
    int resul = (t + shift) % 4;
    if (resul == 0) {
      SS[m] = 'U';
    } else if (resul == 1) {
      SS[m] = 'D';
    } else if (resul == 2) {
      SS[m] = 'L';
    } else if (resul == 3) {
      SS[m] = 'R';
    }
  }
  // Trả về tọa độ(x,y)
  int x = 0;
  int y = 0;
  for (int z = 0; z < SS.length(); z++) {
    if (SS[z] == 'U') {
      y += 1;
    } else if (SS[z] == 'D') {
      y -= 1;
    } else if (SS[z] == 'L') {
      x -= 1;
    } else if (SS[z] == 'R') {
      x += 1;
    }
  }

  string toaDo = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
  return toaDo;
  // return "You can remove this return";
}

string decodeVfunction(const string A, const string B) {
  // return "You can remove this return";
  string str2 = "V";
  string strDataA = A;
  string strDataB = B;
  int posA = 0;
  int posB = 0;
  int cntA = 0;
  int cntB = 0;

  while ((posA = strDataA.find(str2, posA)) < strDataA.length()) {
    posA += str2.length();
    cntA++;
  }
  while ((posB = strDataB.find(str2, posB)) < strDataB.length()) {
    posB += str2.length();
    cntB++;
  }
  string resul = "";
  for (int i = 0; i < cntA * cntB; i++) {
    resul += "V(";
  }
  resul += "0";
  for (int i = 0; i < cntA * cntB; i++) {
    resul += ")";
  }
  return resul;
}

void insertionSort(vector<int> &point, vector<char> &alphabet) {
  int i, key, j;
  char key2;

  for (i = 1; i < alphabet.size(); i++) {
    key = point[i];
    key2 = alphabet[i];
    j = i - 1;
    while (j >= 0 && point[j] > key) {
      point[j + 1] = point[j];
      alphabet[j + 1] = alphabet[j];
      j = j - 1;
    }
    point[j + 1] = key;
    alphabet[j + 1] = key2;
  }
}

string findBetrayals(const string input5[], const int N5) {
  // return "You can remove this return";
  vector<char> alphabet;
  vector<int> point;

  for (int i = 65; i < 91; i++) {
    // alphabet.push_back((char)i);
    point.push_back(0);
  }

  for (int i = 0; i < N5; i++) {
    for (int j = 0; j < 6; j++) {
      bool check = false;
      for (int k = 0; k < alphabet.size(); k++) {
        if (input5[i][j] == alphabet[k]) {
          // cout << to_string(alphabet[k]) << "|";
          point[k] += 6 - j;
          check = true;
        }
      }
      if (check == false) {
        alphabet.push_back(input5[i][j]);
        point[alphabet.size() - 1] += 6 - j;
      }
    }
  }

  insertionSort(point, alphabet);

  /*for (vector<char>::iterator it1 = alphabet.begin(); it1 != alphabet.end();
       it1++) {
    cout << (*it1) << " ";
  }
  cout << endl;
  for (vector<int>::iterator it = point.begin(); it != point.end(); it++) {
    cout << (*it) << " ";
  }
  cout << endl;*/

  for (int i = 0; i < point.size(); i++) {
    int pointPivot = point[i];
    for (int j = 1; j < point.size(); j++) {
      if (pointPivot == point[j]) {
        if (alphabet[i] > alphabet[j]) {
          char temp = alphabet[i];
          alphabet[i] = alphabet[j];
          alphabet[j] = temp;
        }
      }
    }
  }

  string a = "";
  string b = "";
  string c = "";
  for (int i = 0; i < 1; i++) {
    a += alphabet[alphabet.size() - 1];
    b += alphabet[alphabet.size() - 2];
    c += alphabet[alphabet.size() - 3];
  }
  return a + b + c;
}

int attack(const string input6[]) {
  vector<char> order;
  vector<int> row;
  for (int i = 0; i < 10; i++) {
    // row.push_back(0);
    order.push_back((char)i);
  }
  for (int i = 0; i < 10; i++) {
    int cntCivil = 0;
    for (int j = 0; j < 10; j++) {
      if (input6[i][j] == '2') {
        cntCivil = 0;
        break;
      } else if (input6[i][j] == '0') {
        cntCivil += 1;
      }
    }
    row.push_back(cntCivil);
  }

  insertionSort(row, order);
  if (row[row.size() - 1] > 0) {
    return order[order.size() - 1];
  }
  return -1;
}

int calculateNoOfWaitingDays(const string input7Str,
                             const string input7Matrix[], const int k) {
  return -1;
}

#endif /* MONGOL_H */
