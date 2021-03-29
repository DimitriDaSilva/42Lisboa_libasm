		default	rel						; Set RIP-relative addressing to default

		extern	_ft_strlen, _ft_strchr

		global	_ft_atoi_base

_ft_atoi_base:
		push	rbx

.is_base_valid:
		mov		rax, 0				; Default value of ret value is FALSE

		cmp		rsi, 0				; Check if NULL pointer
		je		.error				; If true, exit with ret value 0

		cmp		byte [rsi], 0		; Check if base is empty
		je		.error				; If true, exit with ret value 0

		cmp		byte [rsi + 1], 0	; Check if base is one char long
		je		.error				; If true, exit with ret value 0

		lea		rbx, [rdi]			; Save str to use rdi
		mov		rdi, rsi			; Set base as 1st arg for strchr

		mov		rsi, '-'			; Set '-' as 2nd arg for strch
		call	_ft_strchr
		cmp		rax, 0				; If 0, means chars where not found and base is valid
		jne		.error				; If not 0, base not valid

		mov		rsi, '+'			; Set '+' as 2nd arg for strch
		call	_ft_strchr
		cmp		rax, 0				; If 0, means chars where not found and base is valid
		jne		.error				; If not 0, base not valid

		mov		rsi, ' '			; Set ' ' as 2nd arg for strch
		call	_ft_strchr
		cmp		rax, 0				; If 0, means chars where not found and base is valid
		jne		.error				; If not 0, base not valid

		lea		rdx, [rsi]			; Saving base in rdx so that has_duplicates can use rsi
		xor		rcx, rcx
		call	.has_duplicates
		cmp		rax, 1
		je		.error

.atoi:
		mov		rax, 1

.exit:
		pop		rbx
		ret

.error:
		xor		rax, rax
		jmp		.exit

.has_duplicates:
		cmp		byte [rdi + rcx], 0
		je		.no_duplicates

		cmp		byte [rdi + rcx + 1], 0
		je		.no_duplicates

		lea		rdi, [rdi + rcx + 1]
		mov		rsi, [rdi + rcx]
		call	_ft_strchr
		cmp		rax, 0
		inc		rcx
		je		.has_duplicates

.duplicates_found:
		mov		rax, 1
		ret

.no_duplicates:
		mov		rax, 0
		ret
