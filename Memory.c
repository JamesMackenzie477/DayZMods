/*
 * Various functions used to interact with the game's virtual memory.
 * By hunter24957.
*/

// Casts the given address to an int array.
// Do not directly call this function.
int[] ToArrayEx(int arr[], int hiaddr, int loaddr)
{
	int delta = arr[2] - loaddr;
	if (delta % 4 != 0) return arr;
	delta = (delta / 4) + 3;
	arr[2] = loaddr;
	arr[delta] = hiaddr;
	return arr;
}

// Casts the given address to an int array.
int[] ToArray(int hiaddr, int loaddr)
{
	int arr[1];
	return ToArrayEx(arr, hiaddr, loaddr);
}

// Copys the data from the source array to the target array.
void ArrayCopy(int target[], int source[], int count)
{
	for (int i = 0; i < count; i++) target[i] = source[i];
}

// Writes the data in the source buffer to the target address.
void WriteMemory(int hiaddr, int loaddr, int source[], int count)
{
	ArrayCopy(ToArray(hiaddr, loaddr), source, count);
}

// Reads the data at the source address into the target buffer.
void ReadMemory(int target[], int hiaddr, int loaddr, int count)
{
	ArrayCopy(target, ToArray(hiaddr, loaddr), count);
}

// Reads the data from the source address and writes it to the target address.
/*void CopyMemory(int hitarget, int lotarget, int hisource, int losource, int count)
{
	ArrayCopy(ToArray(hitarget, lotarget), ToArray(hisource, losource), count);
}*/

// An array overflow exploit used to overwrite the address of the array argument.
/*bool array_exploit(int arr[], int hiaddr, int loaddr, int buffer[], int size)
{
	int delta = arr[2] - loaddr;
	if (delta % 4 != 0) return false;
	delta = (delta / 4) + 3;
	arr[2] = loaddr;
	arr[delta] = hiaddr;
	for (int i = 0; i < size; i++) arr[i] = buffer[i];
	return true;
}*/