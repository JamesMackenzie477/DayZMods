
void MessageBox()
{
	// Construct the shellcode, preserving all volatile registers and arguments.

	// Constructs the call shellcode.
	int call[4];
	ReadMemory(call, 0x7FE, 0xFD4407C0, 4);
	// Writes the call shellcode to memory.
	WriteMemory(0x7FE, 0xFD440AD0, call, 4);
	// Constructs the redirect shellcode.
	int redirect[] = { 0xB8489090, 0xFD440AD0, 0x000007FE, 0x0000C350 };
	// Writes the redirect shellcode to the hijack function.
	WriteMemory(0x7FE, 0xFD4407C0, redirect, 4);

	// Restore original code at the end of shellcode and jump to original code.
	// Write shellcode.
	// Write the jmp in the hijacked function.
}