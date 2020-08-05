'''#############################################################################
File: thin.py
Author: Minpto Kim (Min Kim)
Date: 07/28/2020 (mm/dd/yyyy)
Projrct: Thermal Calculater
Description:
    It calculates finaltemp of gas(?)
    this is concept script of the gas calculation for testing purpose.
#############################################################################'''
#coding: utf-8
import numpy as np
import math

# in case you cannot run this file, please commented out "import numpy as np"

def delTmp(T_1, T_2):
    # finds delTmep
    T = T_2 - T_1
    return T


# def delWall(D_i, D_o):
#     # find delWall
#     D = pow(D_o, 2) - pow(D_i, 2)
#     return D


def lenght(m_flow, C_p, q_HeatFlux, D, T):
    tmpUp = m_flow * C_p
    tmpDow = math.pi * D * q_HeatFlux
    return tmpUp/tmpDow * T


# Type all of your varliable
T_1 = 25  # initial tmp in Celiues
T_2 = 500  # final tmp in Celiues
D = 0.0254  # diameter of pipe in m
m_flow = 3 * pow(10, -6)  # flwo late of gas in kg/s
C_p = 1.68 * pow(10, 3)  # heat capacity J/kg * K
q_HeatFlux = 12090.02418 # heat generation rate in W/m^2

# Calculation begines
T = delTmp(T_1, T_2)
L = lenght(m_flow, C_p, q_HeatFlux, D, T)

# preset for degree sing in unit code (utf-8)
degree_sign = u"\N{DEGREE SIGN}"
# printing reasult
print("The lenght rerueied foe the pipe is {} m".format(L))
print("Ini && Fin Temp({sing}C): {iniT}, {finT}".format(
    sing=degree_sign, iniT=T_1, finT=T_2))
print("Diameter of pipe (m): {}\n".format(D))
