include Irvine32.inc
ExitProcess proto

.data
	left DD 305
	right dword 6651
	total dword ? 
	diff dword ?
	message byte "Hello World!"
	Array byte 1, 2, 4, 8, 16, 32, 64
	ArrayLength = ($ - array)

.code
main proc
	mov edx, OFFSET message
	mov eax, left
	mov ebx, right
	add eax, right
	mov ecx, eax
	mov total, ecx
	mov eax, left
	sub ebx, left
	mov edx, ebx
	mov diff, edx
	mov ebx, right
	mov esi, ArrayLength
	call DumpReg

INVOKE ExitProcess, 0
main endp
end main
