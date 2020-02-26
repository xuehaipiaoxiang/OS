assume cs:code,ds:data
data segment
	db 0dh,0ah
	db 'the  first operating system'
	db 0dh,0ah
	db 0
data ends
code segment
	mov ax,0
	mov ds,ax
	mov si,[data]
	mov ah,0eh
	mov bx,15h
	s1 :mov al,[si]
	inc si
	cmp al,0         ; if al==0 zeroFlag=1
	jz s2                ; if zF==1 jump
	int 10h
	loop s1
	s2:hlt
	loop s2
code ends
end
