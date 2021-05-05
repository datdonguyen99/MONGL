//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any
// other libraries.

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
  // return "You can remove this return";
  /*////// BEGIN DECODE TO DECIMAL ///////*/
  string ip1 = "";
  bool check = false;
  for (int i = 0; i < N1; i++) {
    for (size_t j = 0; j < input1[i].length(); check ? (j += 1) : (j += 2)) {
      if (input1[i][j] == ' ') {
        check = true;
        ip1 += ' ';
      } else {
        check = false;
        if (input1[i][j] == 48 && input1[i][j + 1] == 48) {
          ip1 += '0';
        } else if (input1[i][j] == 48 && input1[i][j + 1] == 49) {
          ip1 += '1';
        } else if (input1[i][j] == 49 && input1[i][j + 1] == 48) {
          ip1 += '2';
        } else if (input1[i][j] == 49 && input1[i][j + 1] == 49) {
          ip1 += '3';
        }
      }
    }
    ip1 += ' ';
    if (i + 1 != N1) {
      ip1 += '!';
    }
  }
  /*////// END DECODE TO DECIMAL ///////*/

  /*////// BEGIN DECODE TO ALPHABET ///////*/
  size_t pos = 0;
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
    for (size_t i = 0; i < row.length(); i += cntStep) {
      temp = row[i];
      int cnt = 0;
      for (size_t j = i; j < row.length(); j++) {
        if (temp != row[j]) {
          break;
        }
        cnt++;
      }
      cntStep = cnt;
      if (cnt > 7) {
        cnt = cnt % 7;
        if (cnt == 0) {
          cnt = 7;
        }
      }
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
    }
    decode2 += strDecode2;
    if (ip1[pos + 1] == '!') {
      decode2 += ' ';
    }
    pos += space.length();
    posTem = pos;
    pos = ip1.find(space, pos);
  }
  /*////// END DECODE TO ALPHABET ///////*/

  /*////// BEGIN DECODE # and @ ///////*/

  for (size_t i = 0; i < decode2.length(); i++) {
    if (decode2[i] == '#') {
      for (size_t j = i + 1; j < decode2.length(); j++) {
        if (decode2[j] == '#' || decode2[j] == '@' || decode2[j] == ' ' ||
            j == decode2.length() - 1) {
          if (j == decode2.length() - 1 && decode2[j] != '#' &&
              decode2[j] != '@') {
            j += 1;
          }
          char prior = (int)decode2[j - 1];
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
      size_t j = 0;
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

  for (size_t i = 0; i < decode2.length(); i++) {
    if (decode2[i] == '@' || decode2[i] == '#') {
      decode2.erase(i, 1);
    }
  }
  /*////// END DECODE # and @ ///////*/

  /*////// BEGIN CHECK VUA and THD ///////*/
  bool checkVUA = false;
  bool checkTHD = false;

  for (int i = 0; i < NID; i++) {
    string tem = "";
    for (size_t j = 0; j < ID[i].length(); j++) {
      tem = ID[i];
    }
    int fVUA = tem.find("VUA");
    int fTHD = tem.find("THD");
    if (fVUA == 0) {
      checkVUA = true;
    }
    if (fTHD != 0 && fTHD != -1 && (fTHD + 2) != (int)tem.length() - 1) {
      checkTHD = true;
    }
  }
  /*////// END CHECK VUA and THD ///////*/

  /*////// BEGIN DECODE VUA and THD ///////*/
  string decode3 = "";
  if (checkVUA) {
    string temVua = "";
    for (size_t i = 0; i < decode2.length(); i++) {
      if (decode2[i] == ' ' || i == decode2.length() - 1) {
        bool checkSpeVua = false;
        if (i == decode2.length() - 1) {
          if (decode2[i] != ' ') {
            temVua += decode2[decode2.length() - 1];
          } else {
            checkSpeVua = true;
          }
        }
        if (temVua.length() > 2) {
          if (temVua.length() % 2 == 0) {
            for (int idxCut = temVua.length() - 2; idxCut >= 0; idxCut -= 2) {
              decode3 += temVua.substr(idxCut, 2);
            }
          } else {
            for (int j = temVua.length() - 1; j >= 0; j--) {
              decode3 += temVua[j];
            }
          }
        } else {
          decode3 += temVua;
        }
        if (i != decode2.length() - 1 || checkSpeVua) {
          decode3 += ' ';
        }
        temVua = "";
      } else {
        temVua += decode2[i];
      }
    }
    for (size_t j = 0; j < decode2.length(); j++) {
      if ((int)decode3[j] < (int)decode2[j]) {
        decode3[j] = decode2[j];
      }
    }
  } else if (checkTHD) {
    string temTHD = "";
    for (size_t i = 0; i < decode2.length(); i++) {
      bool checkLast = false;
      if (decode2[i] == ' ' || decode2.length() - 1 == i) {
        bool checkSpe = false;
        if (temTHD != "") {
          if (decode2.length() - 1 == i) {
            if (decode2[i] != ' ') {
              temTHD += decode2[decode2.length() - 1];
            } else {
              checkSpe = true;
            }
          }
          int cntEra = 0;

          for (size_t j = 0; j <= temTHD.length(); j += 3) {
            if (temTHD.length() == 1) {
              checkLast = true;
            } else {
              temTHD.erase(j - cntEra, 1);
              cntEra += 1;
            }
          }

          for (size_t i = 0; i < temTHD.length() - 1; i++) {
            for (size_t j = 0; j < temTHD.length() - i - 1; j++) {
              if ((int)temTHD[j] > (int)temTHD[j + 1]) {
                char temp = temTHD[j + 1];
                temTHD[j + 1] = temTHD[j];
                temTHD[j] = temp;
              }
            }
          }

          if (!checkLast) {
            decode3 += temTHD;
          }
          temTHD = "";
        }
        if (decode2.length() - 1 != i || checkSpe) {
          decode3 += " ";
        }
      }
      if (decode2[i] != ' ') {
        temTHD += decode2[i];
      }
    }
  } else {
    decode3 += decode2;
  }
  /*////// END DECODE VUA and THD ///////*/
  return decode3;
}

int decode(const string A, const string B) {
  // return -1;
  string strB = B;
  string strDataA = A;
  size_t pos = 0;
  int cnt = 0;

  while ((pos = strDataA.find(strB, pos)) < strDataA.length()) {
    pos += strB.length();
    cnt++;
  }
  return cnt;
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
      // shiftLeft(SS, numB);
      string temp = SS.substr(0, numB);
      SS.erase(0, numB);
      SS = SS + temp;
    }
  } else if (atoi(pB) > 0) { //////////////////////////
    int numB = atoi(pB);
    int lenS = SS.length();
    if (numB >= lenS) {
      numB = numB % lenS;
    }
    if (numB != 0) {
      // shiftRight(SS, numB);
      int numNoShift = SS.length() - numB;
      string temp = SS.substr(numNoShift, numB);
      SS.erase(numNoShift, numB);
      SS = temp + SS;
    }
  }

  for (size_t m = 0; m < SS.length(); m++) {
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
  for (size_t z = 0; z < SS.length(); z++) {
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
  size_t posA = 0;
  size_t posB = 0;
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

string findBetrayals(const string input5[], const int N5) {
  vector<char> alphabet;
  vector<int> point;

  for (int i = 65; i < 91; i++) {
    // alphabet.push_back((char)i);
    point.push_back(0);
  }

  for (int i = 0; i < N5; i++) {
    for (int j = 0; j < 6; j++) {
      bool check = false;
      for (size_t k = 0; k < alphabet.size(); k++) {
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

  // insertionSort(point, alphabet);
  size_t i;
  int key, j;
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
  // for (vector<char>::iterator it1 = alphabet.begin(); it1 != alphabet.end();
  //      it1++) {
  //   cout << (*it1) << " ";
  // }
  // cout << endl;
  // for (vector<int>::iterator it = point.begin(); it != point.end(); it++) {
  //   cout << (*it) << " ";
  // }
  // cout << endl;

  for (size_t i = 0; i < point.size(); i++) {
    int pointPivot = point[i];
    for (size_t j = 1; j < point.size(); j++) {
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
  return (a + b + c);
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

  // insertionSort(row, order);
  size_t i;
  int key, j;
  char key2;

  for (i = 1; i < order.size(); i++) {
    key = row[i];
    key2 = order[i];
    j = i - 1;
    while (j >= 0 && row[j] > key) {
      row[j + 1] = row[j];
      order[j + 1] = order[j];
      j = j - 1;
    }
    row[j + 1] = key;
    order[j + 1] = key2;
  }

  if (row[row.size() - 1] > 0) {
    return order[order.size() - 1];
  }
  return -1;
}

void tich(vector<vector<int>> &A, vector<vector<int>> &B, int N7) {
  vector<vector<int>> C;
  int i, j, k;
  for (i = 0; i < N7; i++) {
    vector<int> temp1;
    for (j = 0; j < N7; j++) {
      int temp = 0;
      for (k = 0; k < N7; k++) {
        temp += A[i][k] * B[k][j];
      }
      temp1.push_back(temp);
    }
    C.push_back(temp1);
  }
  A = C;
}

int calculateNoOfWaitingDays(const string input7Str,
                             const string input7Matrix[], const int k) {
  // string space = " ";
  vector<string> vecStr7;
  string Str = input7Str;
  while (!Str.empty()) {
    vecStr7.push_back(Str.substr(0, Str.find(" ")));
    if (Str.find(" ") > Str.size()) {
      break;
    } else {
      Str.erase(0, Str.find(" ") + 1);
    }
  }
  int N7 = stoi(vecStr7[0]); // N7 elems
  int V = stoi(vecStr7[1]);
  int i = stoi(vecStr7[2]); // row
  int j = stoi(vecStr7[3]); // colum

  vector<vector<vector<int>>> Vec;
  string inputRow = "";
  string ele = "";

  for (int r = 0; r < k; r++) {
    inputRow = input7Matrix[r];
    vector<vector<int>> temp1;
    for (int i = 0; i < N7; i++) {
      vector<int> temp2;
      for (int j = 0; j < N7; j++) {
        ele = inputRow.substr(0, inputRow.find(" "));
        temp2.push_back(stoi(ele));
        inputRow.erase(0, ele.length() + 1);
      }
      temp1.push_back(temp2);
    }
    Vec.push_back(temp1);
  }

  vector<vector<int>> temp = Vec[0];
  for (int i = 1; i < (int)Vec.size(); i++) {
    tich(temp, Vec[i], N7);
  }
  int ret = temp[i][j];
  int rel = ret % V;
  if (rel < 0) {
    rel = rel - rel * 2;
  }
  return rel;
}

#endif /* MONGOL_H */
