;void	ft_list_remove_if(t_list **begin_list,
;							void *data_ref,
;							int (*cmp)(),
;							void (*free_fct)(void *));

		global	_ft_list_remove_if
		extern _free
		default	rel								; Set RIP-relative addressing to default

		section	.data

struc	s_list
		data:	resq	1
				alignb	4
		next:	resq	1
				alignb	4
endstruc

		section	.text
_ft_list_remove_if:
		; Prologue
		push	rbx
		mov		rbx, rsp

		; Save begin_list to other scratch registers to free up rdi for the function calls
		mov		r8, rdi					; begin_list

		test	r8, r8					; Check if being_list is NULL
		jz		.exit					; If null, return 0
		mov		r8, [r8]				; Set r8 as the first node

.parse_list:
		; Check if head is NULL
		test	r8, r8					
		jz		.exit

		; Compare data. rsi already holds the pointer to the data ref (2nd arg)
		mov		rdi, qword [r8 + data]	; Set 1st arg for cmp
		call	rdx						; rdx holds the address of the cmp function
		test	rax, rax				
		jnz		.continue				; If ret == 0, remove from list

		; Else remove node
		; 1st step: free data
		call	rcx						; rcx holds the address of the free_fct

		; 2st step: 



.continue:
		mov		r8, qword [r8 + next]	; Else continue with next node
		jmp		.parse_list

.exit:
		mov		rsp, rbx
		pop		rbx
		ret
