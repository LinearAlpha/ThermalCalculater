/******************************************************************************
 * Project: ThermalCalculater
 * File: Main.cpp
 * Authors: Minpyo Kim (Min Kim)
 * Date: 08/03/2020
 * Description: Calcualtes the final temperature of the gas passing thoguth
 *              consttanct heat flow in to the pipe
******************************************************************************/

// comen headers iostream, string, vector
#include "include/stdafx.h"
#include "include/calculation.h"
#include <ctype.h>
#include <cmath>
#include <locale>
#include <algorithm>
#include <cctype>
#include "../src/MultyOSCom/MultyOSCom.h"
#include "../src/BulletProof/BulletProof.h"
//#include "include/calculation.h"

//  using standared namepsace
using namespace std;

// printing mainMenu
void mainMenu(int& option);
// find a two input and returns as each value
void locatteReturn(float* tmpPass);
// checkinh user inputs, looping until user agress it it right
void aryyInputCheck(float* tmpPass, vector<string>& infos);
//checkoing user inputs
void checkUserInput(string &inptu, const float &lowBound);
float strToFloat(string input);
// processt the thick case of calculation
void thickCase();

int main()
{
	cout << "Hello World!!!" << endl;
	//pauseTerminal();
	clearScreen(); //cleanning terminal
	bool flag = true;
	int option;
	do
	{
		mainMenu(option);
		switch (option)
		{
		case 1:
			thickCase();
			break;
		case 2:
			/*code*/
			break;
		default:
			flag = false;
			break;
		}

	} while (flag == true);
	return 0;
}

void mainMenu(int& option)
{
	cout << "0. Exit" << endl;
	cout << "1. Thick wall case" << endl;
	cout << "2. Thin wall case\n>>";
	cin >> option;
	// chceking user input, if it is not in boundery it ill loop until right
	bulProof(option, 0, 2);
}

void locatteReturn(float* tmpPass)
{
	bool flag;
	//looping untile the user typer right format; true for exit
	do
	{
		cout << ">> ";
		string tmp;
		getline(cin, tmp);
		int comLoca = tmp.find(","); //find location of comma
		int comLoTmp = comLoca + 1; //to locate the emtystring location
		//frist case no comma; second ", "; final "," betwwen numder
		if (comLoca < 0)
		{
			cout << "Pleas type comma (,) betwwen numders" << endl;
			getline(cin, tmp);
			flag = false;
		}
		else if (tmp[comLoTmp] == ' ' && comLoca > 0)
		{
			comLoTmp++;
			tmpPass[0] = stof(tmp.substr(0, comLoca));
			tmpPass[1] = stof(tmp.substr(comLoTmp));
			flag = true;
		}
		else
		{
			tmpPass[0] = stof(tmp.substr(0, comLoca));
			tmpPass[1] = stof(tmp.substr(comLoTmp));
			flag = true;
		}

	} while (!flag);
}

void aryyInputCheck(float* tmpPass, vector<string>& infos)
{
	char tmpFlag;
	do
	{
		locatteReturn(tmpPass);
		//asling user it is right information or not
		cout << "\tYou entered\n\t1. " << infos[1] << " = " << tmpPass[0]
			 << infos[3] << endl;
		cout << "\t2. " << infos[2]  << " = " << tmpPass[1]
			 << infos[3] << endl;
		cout << "Is this correct? (y/n) ";
		cin >> tmpFlag;
		cleanPipe();
		if (tmpFlag == 'n' || tmpFlag == 'N')
		{
			string tmpStr = infos[1] + ", " + infos[2];
			cout << "Pleas enter it agin in order of " << tmpStr << endl;
		}
	} while (tmpFlag == 'n' || tmpFlag == 'N');

}

void checkUserInput(string &inptu, const float &lowBound)
{
	bool flag;
	do
	{
		std::transform(inptu.begin(), inptu.end(), inptu.begin(),
		[](unsigned char c){
			return std::tolower(c);
		});
		flag = false;
		int limits = inptu.size();
		for(int i = 0; i < limits; i++)
		{
			if (isalpha(inptu[i]))
			{
				if(inptu.find("e+") == false || inptu.find("e-") == false)
				{
					flag = true;
					cout <<  "please enter numers only\n>> ";
					cin >> inptu;
					cleanPipe();
					break;
				}

			}
		}	
	}while(flag);
}

float strToFloat(string input)
{
	std::transform(input.begin(), input.end(), input.begin(), 
	[](unsigned char c){
		return std::tolower(c);
	});
	cout << input;
	return 0;
}

void thickCase()
{
	cout << "\n\nYou've entered the thick wall case" << endl;
	cout << "Do you what to continue? (y/n) ";
	char tmpFalg;
	cin >> tmpFalg;
	// cleaning the pipe line of input
	cleanPipe();
	if (tmpFalg == 'y' || tmpFalg == 'Y')
	{
		Calculation datas; //class for the calculation
 		float tmpArr[2];
		// vector<string> infos; //order, first, secon, unit
		// // informations for the temperature inputs
		// infos = {"Temperature", "T_i", "t_f", " °C"};
		// // formatting part of output
		// string tmpStr = infos[1] + ", " + infos[2];
		// cout << "Please enter " << infos[0] << " in order of " << tmpStr
		// 	 << ";in" << infos[3] << endl;
		// aryyInputCheck(tmpArr, infos); // send and check the user input
		// datas.setTemperature(tmpArr); // save in to class
		// // informatiodn  for the dimaentiosn
		// infos = {"Dimenstions", "D_i", "D_o", " m"};
		// tmpStr = infos[1] + ", " + infos[2];
		// cout << "Please enter " << infos[0] << " in order of " << tmpStr
		// 	 << ";in" << infos[3] << endl;
		// aryyInputCheck(tmpArr, infos); // send and check the user input
		// datas.setDaim(tmpArr); // save in to class
		// getting flow rate
		float othereInputs[3];
		string tmpSave[3];
		string tmpStr;
		do
		{
			cout << "Whas is flow rate of your gas/liquied in kg/s?\n>> ";
			cin >> tmpStr; // need to delect in final compile
			checkUserInput(tmpStr, 0);
			tmpSave[0] = tmpStr;
			cout << "what is C_p in J/kg * K?\n>> ";
			cin >> tmpStr;
			checkUserInput(tmpStr, 0);
			tmpSave[1] = tmpStr;
			cout << "What is q_heat (heat flux) in W/m^3?\n>> ";
			checkUserInput(tmpStr, 0);
			tmpSave[2] = tmpStr;
			for(int i = 0; i < 3; i++)
			{
				othereInputs[i] = strToFloat(tmpSave[i]);
			}	
		} while (tmpFalg == 'n' || tmpFalg == 'N');
		





		 

	}
}