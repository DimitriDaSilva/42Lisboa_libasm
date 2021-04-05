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
		push	rbp
		mov		rbp, rsp

		; Preversing non-scratch registers
		push	r12
		push	r13
		push	r14

		; Save begin_list to other scratch registers to free up rdi for the function calls
		mov		r8, rdi					; begin_list
		mov		r10, rsi				; set data_ref into r10 to avoid data corruption
		mov		r12, rsi				; Store the data_ref
		mov		r13, rdx				; Store the cmp function
		mov		r14, rcx				; Store the free function

		test	r8, r8					; Check if being_list is NULL
		jz		.exit					; If null, return 0
		mov		r9, [r8]				; Set r9 as the first node

.parse_llist:
		; Check if head is NULL
		test	r9, r9					
		jz		.exit

		; Compare data. rsi already holds the pointer to the data ref (2nd arg)
		lea		rdi, qword [r9 + data]	; Set 1st arg for cmp
		mov		rsi, r12				; Set 2nd arg as data_ref
		call	r13						; r13 holds the address of the cmp function
		test	rax, rax				
		jnz		.continue				; If ret == 0, remove from list

		; Else remove node
		; 1st step: free data
		lea		rdi, qword [r9 + data]	; 1st arg is the pointer to the data
		call	r14						; rcx holds the address of the free_fct

		; 2st step: change the value the previous's node->next
		mov		r11, [r9 + next]		; r11 acts as tmp for r9->next value
		mov		[r8], r11				; *begin_list = head->next;
		push	r8

		; 3rd step: free node
		mov		rdi, r9
		call	_free

		pop		r8
		cmp		qword [r8], 0					; Check if NULL
		je		.exit

		mov		r9, [r8]
		jmp		.parse_llist

.continue:
		lea		r8, qword [r9 + next]	; Make a copy of the address of node->next just checked
		mov		r9, [r8]				; Set r9 to the next node
		jmp		.parse_llist

.exit:
		; Restoring non-scratch registers
		pop		r14
		pop		r13
		pop		r12

		; Epilogue
		mov		rsp, rbp
		pop		rbp
		ret

		; -- DEBUG --
		mov		rax, 7
		jmp		.exit
		; -- DEBUG --