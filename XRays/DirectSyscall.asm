.386

.model flat, C

.code
	assume fs:nothing

NtQueryVirtualMemory proc
	mov eax, 23h
	call dword ptr fs:[0C0h]
	retn 18h
NtQueryVirtualMemory endp


NtReadVirtualMemory proc
	mov eax, 3Fh
	call dword ptr fs:[0C0h]
	retn 14h
NtReadVirtualMemory endp


NtWriteVirtualMemory proc
	mov eax, 3Ah
	call dword ptr fs:[0C0h]
	retn 14h
NtWriteVirtualMemory endp

end