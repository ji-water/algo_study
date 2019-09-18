#define MAX 50000

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int Answer;

string chem[] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
"No", "Lr" };

int main(int argc, char** argv)
{
	int T, test_case;

	//����
	sort(chem, chem + 114);
	for (int i = 0; i < 114; i++) {
		chem[i][0] = tolower(chem[i][0]); //�ҹ��� ��ȯ
	}
	
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		//�ܾ��Է�
		string word;
		cin >> word;

		//�ܾ� ��
		int i_be = 0; //i �����ϴ� ���ұ�ȣ ������ 1
		int ii_be = 0; //i & i+1 �α��� �����ϴ� ���ұ�ȣ ������ 1
		int flag_i = 0; //����Ǽ� �б��� �߻���, �߻��� index+1 ���� (�б��������� ������ i+2 ���� Ž��)
		int contain_len = 0; 

		for (unsigned int i = 0; i < word.length(); ) {
			i_be=binary_search(chem, chem + 114, word.substr(i,1));
			//cout << word.substr(i,1) << ":" << i_be << endl;
			if (i < (word.length() - 1)) {
				ii_be = binary_search(chem, chem + 114, word.substr(i, 2));
				//cout << word.substr(i, 2) << ":" << ii_be << endl;
			}
			if (i_be == 0 && ii_be == 0) {
				if (flag_i == 0) //ȭ�б�ȣ�� ���� ���ư� �б����� ����
					break;
				//�б��� ������ ���
				i = flag_i;
				flag_i = 0;
				contain_len--;
			}
			else if (i_be == 0 && ii_be > 0) { //ii_be�� ����
				i = i + 2;
				contain_len+=2;
			}
			else if (i_be > 0 && ii_be == 0) {
				i = i + 1;
				contain_len++;
			}
			else if (i_be > 0 && ii_be > 0) {
				flag_i = i + 1; 
				i = i + 2;
				contain_len += 2;
			}
			i_be = 0;
			ii_be = 0;
		}
		if (contain_len == word.length())
			Answer = 1;

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		if (Answer > 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}