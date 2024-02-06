
#define Set_Bit(Var, BitNo) ((Var) |= (1 << (BitNo)))

#define Clr_Bit(Var, BitNo) ((Var) &= ~(1 << (BitNo)))

#define Toggle_Bit(Var, BitNo) ((Var) ^= (1 << (BitNo)))
