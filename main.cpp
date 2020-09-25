#include <Windows.h>
#include <iostream>

#include <peconv.h> // include libPeConv header

size_t g_PESize = 0;
BYTE* g_myPE = NULL;


int(__cdecl* __DllMainCRTStartup)(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) = nullptr;


int load_and_run(LPCSTR pe_path)
{
	g_myPE = peconv::load_pe_executable(pe_path, g_PESize);
	if (!g_myPE) {
		return -1;
	}
	return 1;
	//int(__cdecl * __DllMainCRTStartup)(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) = (int(__cdecl*)(HINSTANCE, DWORD, LPVOID))(0x5e670 + (ULONG_PTR)g_myPE);
	//return __DllMainCRTStartup((HINSTANCE)g_myPE, DLL_PROCESS_ATTACH, 0);
}





#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <cstdint>
#include <windows.h>
#include <cstddef>


using namespace std;

class Shit {
public:

    DWORD* __thiscall  xor_decrypt(DWORD* temp, int a2, int a3, int a4, int a5)
    {
        unsigned int v5; // edi

        v5 = 0;
        //  DWORD* temp = ;
        *temp = a2;
        temp[1] = a3;
        //int temp1 = a3;
        temp[2] = a4;
        //int temp2 = a4;
        temp[3] = 102;
        //int temp3 = 102;
        if (a3)
        {
            do
            {
                *(byte*)(*temp + v5) ^= *(byte*)(v5 % temp[3] + temp[2]);
            //    cout << ", xor[" << (char)*(byte*)(*temp + v5) << "]";
                ++v5;
            } while (v5 < temp[1]);
        }
        /*
        cout << "...................temp with input:" << a4 <<"\n";
        cout << *temp << "\n";
        cout << &temp << "\n";
        cout << temp << "\n";
        cout << "...................\n";
        */
        return temp;
    }


    char __thiscall result_calc(DWORD* temp)
    {
        unsigned int v1; // esi
        char result; // al

        v1 = 0;
        if (temp[1])
        {
            do
            {
                result = *(byte*)(v1 % temp[3] + temp[2]);
                cout << " , " << (char)result;
                *(byte*)(*temp + v1++) ^= result;
           //     cout << ",  " << ((char)*(byte*)(*temp + v1));
            } while (v1 < temp[1]);
        }
        /*
        cout << "calcres.................\n";
        cout << &result << "\n";
        cout << result << "\n";
        cout << *(byte*)(*temp) << "\n";
        cout << *temp << "\n";
        cout << ".........................................";
        */


        return result;

    }


    int sus(DWORD* input)
    {
        HANDLE v0; // int v0 = 1; // esi
        int v1; // ecx
        int v2; // ecx
        HANDLE v3; // eax
        DWORD v5; // [esp+Ch] [ebp-13Ch]
        DWORD* v6 = input; // [esp+10h] [ebp-138h]
        char v7; // [esp+20h] [ebp-128h]
        char v8; // [esp+88h] [ebp-C0h]
        int v9; // [esp+F0h] [ebp-58h]
        int v10; // [esp+F4h] [ebp-54h]
        int v11; // [esp+F8h] [ebp-50h]
        int v12; // [esp+FCh] [ebp-4Ch]
        int v13; // [esp+100h] [ebp-48h]
        int v14; // [esp+104h] [ebp-44h]
        int v15; // [esp+108h] [ebp-40h]
        int v16; // [esp+10Ch] [ebp-3Ch]
        int v17; // [esp+110h] [ebp-38h]
        int v18; // [esp+114h] [ebp-34h]
        int v19; // [esp+118h] [ebp-30h]
        int v20; // [esp+11Ch] [ebp-2Ch]
        int v21; // [esp+120h] [ebp-28h]
        int v22; // [esp+124h] [ebp-24h]
        int v23; // [esp+128h] [ebp-20h]
        char v24; // [esp+12Ch] [ebp-1Ch]
        int v25; // [esp+130h] [ebp-18h]
        int v26; // [esp+134h] [ebp-14h]
        int v27; // [esp+138h] [ebp-10h]
        int v28; // [esp+13Ch] [ebp-Ch]
        int v29; // [esp+140h] [ebp-8h]

        v9 = 741548835;
        v10 = 1231306510;
        strcpy(&v7, "nPTnaGLkIqdcQwvieFQKGcTGOTbfMjDNmvibfBDdFBhoPaBbtfQuuGWYomtqTFqvBSKdUMmciqKSGZaosWCSoZlcIlyQpOwkcAgw ");
        v11 = 67771914;
        v12 = 436344355;
        v13 = 604530244;
        strcpy(&v8, "KglPFOsQDxBPXmclOpmsdLDEPMRWbMDzwhDGOyqAkVMRvnBeIkpZIhFznwVylfjrkqprBPAdPuaiVoVugQAlyOQQtxBNsTdPZgDH ");
        v14 = 745804082;
        v15 = 255995178;
        v16 = 224677950;
        v17 = 387646557;
        v18 = 84096534;
        v19 = 134815796;
        v20 = 237248867;
        v21 = 1479808021;
        v22 = 981018906;
        v23 = 1482031104;
        v24 = 84;
        v25 = 989990456;
        v26 = 874199833;
        v27 = 1042484251;
        v28 = 1108412467;
        v29 = 1931350585;

        cout << "\n...........[1]........ .......\n";
        Shit::xor_decrypt(v6, (int)&v25, 20, (int)&v8, 0);

        v0 = CreateFileA((LPCSTR)v6, 0x40000000, 2, 0, 2, 128, 0);
        //  v0 = MEMORY[0x12418](v6, 0x40000000, 2, 0, 2, 128, 0);
        result_calc(v6);
        //  std::cout << "\nfinished processing shit!\n";
        //  std::cout << "Output sentence:[" << &v6<< "]";




        if (true)
        {
            LPDWORD v5 = 0;
            cout << "\n...........[2]...............\n";
            xor_decrypt(v6, (int)&v9, 61, (int)&v7, 0);
            // WriteFile(v0, &v6, 61, v5, 0);
             // MEMORY[0x123F8](v0, v6, 61, &v5, 0);
             //cout << "\n...........[2nd]...............\n";
            result_calc(v6);

            // CloseHandle(v0);
             //MEMORY[0x12426](v0);
            cout << "\n...........[3]...............\n";
            xor_decrypt(v6, (int)&v25, 20, (int)&v8, 0);
            // ShellExecuteA(0, 0, &v6, 0, 0, 0);
             //MEMORY[0x12442](0, 0, v6, 0, 0, 0);
            result_calc(v6);
            cout << "\n finaallllll:\n" << &v6;
        }

        system("pause");
        return 0;
    }

};

int main(int argc, char* argv[])
{
	const LPCSTR pe_path = "final-imp-E-2.exe"; // 
	int res = load_and_run(pe_path);
	std::cout << "Loaded file..........................: " << res << g_myPE <<"\n";

	int v9;
	DWORD* v6; 
	int v10;
	DWORD* ( *fun_18FA)() = (DWORD* (*)())(0x18FA + (ULONG_PTR)g_myPE);
	int (*fun_3D6B)() = (int (*)())(0x3D6B + (ULONG_PTR)g_myPE);
	int (*fun_3D65)() = (int (*)())(0x3D65 + (ULONG_PTR)g_myPE);
    int(*Sus)() = NULL;


	v6 = fun_18FA();
	std::cout << "called fun_18FA: " << v6 << "\n";
	v9 = *(DWORD *)fun_3D6B();
	std::cout << "called v9: " << v9 << "\n";
	v10 = *(DWORD *)fun_3D65();
	std::cout << "called v10: " << v10 << "\n";

    ULONGLONG func_offset = (ULONGLONG)g_myPE + 0x106b;
    Sus = (int(__cdecl*)())func_offset;
    int temp = Sus();

}