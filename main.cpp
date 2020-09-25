#include <Windows.h>
#include <iostream>
#include <iostream>
#include <cstring>
#include <cstdint>
#include <cstddef>

#include <peconv.h> // include libPeConv header

size_t g_PESize = 0;
BYTE* g_myPE = NULL;


int load_and_run(LPCSTR pe_path)
{
	g_myPE = peconv::load_pe_executable(pe_path, g_PESize);
	if (!g_myPE) {
		return -1;
	}
	return 1;
}

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
