//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any
// other libraries.

// #include <algorithm>
// #include <stdlib.h>
// #include <string.h>
// #include <string>
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

string readyForBattle(const string ID[], const int NID, const string input1[],
                      const int N1) {
  return "You can remove this return";
  // ID[] = ;
}

int decode(const string A, const string B) {
  // return -1;
  char *str = new char[A.size() + 1];
  copy(A.begin(), A.end(), str);
  char *substr = new char[B.size() + 1];
  copy(B.begin(), B.end(), substr);

  bool check = false;
  int count = 0;

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == substr[0]) {
      check = true;
      for (int j = 0; j < strlen(substr); j++) {
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
