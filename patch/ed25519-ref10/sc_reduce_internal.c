#include "sc.h"
#include "crypto_int64.h"

/*
Input:
  s[0]+256*s[1]+...+256^63*s[63] = s

Output:
  s[0]+256*s[1]+...+256^31*s[31] = s mod l
  where l = 2^252 + 27742317777372353535851937790883648493.
  Overwrites s in place.
*/

static void sc_reduce_mul(crypto_int64 *a, crypto_int64* b, int c)
{
  int i;

  for (i = 0;i < c;++i)
  {
    a[0-i] += b[-i] * 666643;
    a[1-i] += b[-i] * 470296;
    a[2-i] += b[-i] * 654183;
    a[3-i] -= b[-i] * 997805;
    a[4-i] += b[-i] * 136657;
    a[5-i] -= b[-i] * 683901;
    b[-i] = 0;
  }
}

void sc_reduce_internal(unsigned char *t, crypto_int64 *s)
{
  int i,j;
  crypto_int64 carry0;
  crypto_int64 carry1;
  crypto_int64 carry2;
  crypto_int64 carry3;
  crypto_int64 carry4;
  crypto_int64 carry5;
  crypto_int64 carry6;
  crypto_int64 carry7;
  crypto_int64 carry8;
  crypto_int64 carry9;
  crypto_int64 carry10;
  crypto_int64 carry11;
  crypto_int64 carry12;
  crypto_int64 carry13;
  crypto_int64 carry14;
  crypto_int64 carry15;
  crypto_int64 carry16;
#if CRYPTO_SHRINK
  sc_reduce_mul(&s[11], &s[23], 6);
  sc_reduce_carry(&s[6], 6, 5);
  sc_reduce_mul(&s[5], &s[17], 6);
  sc_reduce_carry(&s[0], 6, 6);
  for (i = 0;i < 2;++i)
  {
    sc_reduce_mul(&s[0], &s[12], 1);
    for (j = 0; j < 12;++j)
    {
      carry0 = s[j] >> 21;
      s[j+1] += carry0;
      s[j] -= carry0 << 21;
    }
  }
#else
  s[11] += s[23] * 666643;
  s[12] += s[23] * 470296;
  s[13] += s[23] * 654183;
  s[14] -= s[23] * 997805;
  s[15] += s[23] * 136657;
  s[16] -= s[23] * 683901;
  s[23] = 0;

  s[10] += s[22] * 666643;
  s[11] += s[22] * 470296;
  s[12] += s[22] * 654183;
  s[13] -= s[22] * 997805;
  s[14] += s[22] * 136657;
  s[15] -= s[22] * 683901;
  s[22] = 0;

  s[9] += s[21] * 666643;
  s[10] += s[21] * 470296;
  s[11] += s[21] * 654183;
  s[12] -= s[21] * 997805;
  s[13] += s[21] * 136657;
  s[14] -= s[21] * 683901;
  s[21] = 0;

  s[8] += s[20] * 666643;
  s[9] += s[20] * 470296;
  s[10] += s[20] * 654183;
  s[11] -= s[20] * 997805;
  s[12] += s[20] * 136657;
  s[13] -= s[20] * 683901;
  s[20] = 0;

  s[7] += s[19] * 666643;
  s[8] += s[19] * 470296;
  s[9] += s[19] * 654183;
  s[10] -= s[19] * 997805;
  s[11] += s[19] * 136657;
  s[12] -= s[19] * 683901;
  s[19] = 0;

  s[6] += s[18] * 666643;
  s[7] += s[18] * 470296;
  s[8] += s[18] * 654183;
  s[9] -= s[18] * 997805;
  s[10] += s[18] * 136657;
  s[11] -= s[18] * 683901;
  s[18] = 0;

  carry6 = (s[6] + (1<<20)) >> 21; s[7] += carry6; s[6] -= carry6 << 21;
  carry8 = (s[8] + (1<<20)) >> 21; s[9] += carry8; s[8] -= carry8 << 21;
  carry10 = (s[10] + (1<<20)) >> 21; s[11] += carry10; s[10] -= carry10 << 21;
  carry12 = (s[12] + (1<<20)) >> 21; s[13] += carry12; s[12] -= carry12 << 21;
  carry14 = (s[14] + (1<<20)) >> 21; s[15] += carry14; s[14] -= carry14 << 21;
  carry16 = (s[16] + (1<<20)) >> 21; s[17] += carry16; s[16] -= carry16 << 21;

  carry7 = (s[7] + (1<<20)) >> 21; s[8] += carry7; s[7] -= carry7 << 21;
  carry9 = (s[9] + (1<<20)) >> 21; s[10] += carry9; s[9] -= carry9 << 21;
  carry11 = (s[11] + (1<<20)) >> 21; s[12] += carry11; s[11] -= carry11 << 21;
  carry13 = (s[13] + (1<<20)) >> 21; s[14] += carry13; s[13] -= carry13 << 21;
  carry15 = (s[15] + (1<<20)) >> 21; s[16] += carry15; s[15] -= carry15 << 21;

  s[5] += s[17] * 666643;
  s[6] += s[17] * 470296;
  s[7] += s[17] * 654183;
  s[8] -= s[17] * 997805;
  s[9] += s[17] * 136657;
  s[10] -= s[17] * 683901;
  s[17] = 0;

  s[4] += s[16] * 666643;
  s[5] += s[16] * 470296;
  s[6] += s[16] * 654183;
  s[7] -= s[16] * 997805;
  s[8] += s[16] * 136657;
  s[9] -= s[16] * 683901;
  s[16] = 0;

  s[3] += s[15] * 666643;
  s[4] += s[15] * 470296;
  s[5] += s[15] * 654183;
  s[6] -= s[15] * 997805;
  s[7] += s[15] * 136657;
  s[8] -= s[15] * 683901;
  s[15] = 0;

  s[2] += s[14] * 666643;
  s[3] += s[14] * 470296;
  s[4] += s[14] * 654183;
  s[5] -= s[14] * 997805;
  s[6] += s[14] * 136657;
  s[7] -= s[14] * 683901;
  s[14] = 0;

  s[1] += s[13] * 666643;
  s[2] += s[13] * 470296;
  s[3] += s[13] * 654183;
  s[4] -= s[13] * 997805;
  s[5] += s[13] * 136657;
  s[6] -= s[13] * 683901;
  s[13] = 0;

  s[0] += s[12] * 666643;
  s[1] += s[12] * 470296;
  s[2] += s[12] * 654183;
  s[3] -= s[12] * 997805;
  s[4] += s[12] * 136657;
  s[5] -= s[12] * 683901;
  s[12] = 0;

  carry0 = (s[0] + (1<<20)) >> 21; s[1] += carry0; s[0] -= carry0 << 21;
  carry2 = (s[2] + (1<<20)) >> 21; s[3] += carry2; s[2] -= carry2 << 21;
  carry4 = (s[4] + (1<<20)) >> 21; s[5] += carry4; s[4] -= carry4 << 21;
  carry6 = (s[6] + (1<<20)) >> 21; s[7] += carry6; s[6] -= carry6 << 21;
  carry8 = (s[8] + (1<<20)) >> 21; s[9] += carry8; s[8] -= carry8 << 21;
  carry10 = (s[10] + (1<<20)) >> 21; s[11] += carry10; s[10] -= carry10 << 21;

  carry1 = (s[1] + (1<<20)) >> 21; s[2] += carry1; s[1] -= carry1 << 21;
  carry3 = (s[3] + (1<<20)) >> 21; s[4] += carry3; s[3] -= carry3 << 21;
  carry5 = (s[5] + (1<<20)) >> 21; s[6] += carry5; s[5] -= carry5 << 21;
  carry7 = (s[7] + (1<<20)) >> 21; s[8] += carry7; s[7] -= carry7 << 21;
  carry9 = (s[9] + (1<<20)) >> 21; s[10] += carry9; s[9] -= carry9 << 21;
  carry11 = (s[11] + (1<<20)) >> 21; s[12] += carry11; s[11] -= carry11 << 21;

  s[0] += s[12] * 666643;
  s[1] += s[12] * 470296;
  s[2] += s[12] * 654183;
  s[3] -= s[12] * 997805;
  s[4] += s[12] * 136657;
  s[5] -= s[12] * 683901;
  s[12] = 0;

  carry0 = s[0] >> 21; s[1] += carry0; s[0] -= carry0 << 21;
  carry1 = s[1] >> 21; s[2] += carry1; s[1] -= carry1 << 21;
  carry2 = s[2] >> 21; s[3] += carry2; s[2] -= carry2 << 21;
  carry3 = s[3] >> 21; s[4] += carry3; s[3] -= carry3 << 21;
  carry4 = s[4] >> 21; s[5] += carry4; s[4] -= carry4 << 21;
  carry5 = s[5] >> 21; s[6] += carry5; s[5] -= carry5 << 21;
  carry6 = s[6] >> 21; s[7] += carry6; s[6] -= carry6 << 21;
  carry7 = s[7] >> 21; s[8] += carry7; s[7] -= carry7 << 21;
  carry8 = s[8] >> 21; s[9] += carry8; s[8] -= carry8 << 21;
  carry9 = s[9] >> 21; s[10] += carry9; s[9] -= carry9 << 21;
  carry10 = s[10] >> 21; s[11] += carry10; s[10] -= carry10 << 21;
  carry11 = s[11] >> 21; s[12] += carry11; s[11] -= carry11 << 21;

  s[0] += s[12] * 666643;
  s[1] += s[12] * 470296;
  s[2] += s[12] * 654183;
  s[3] -= s[12] * 997805;
  s[4] += s[12] * 136657;
  s[5] -= s[12] * 683901;
  s[12] = 0;

  carry0 = s[0] >> 21; s[1] += carry0; s[0] -= carry0 << 21;
  carry1 = s[1] >> 21; s[2] += carry1; s[1] -= carry1 << 21;
  carry2 = s[2] >> 21; s[3] += carry2; s[2] -= carry2 << 21;
  carry3 = s[3] >> 21; s[4] += carry3; s[3] -= carry3 << 21;
  carry4 = s[4] >> 21; s[5] += carry4; s[4] -= carry4 << 21;
  carry5 = s[5] >> 21; s[6] += carry5; s[5] -= carry5 << 21;
  carry6 = s[6] >> 21; s[7] += carry6; s[6] -= carry6 << 21;
  carry7 = s[7] >> 21; s[8] += carry7; s[7] -= carry7 << 21;
  carry8 = s[8] >> 21; s[9] += carry8; s[8] -= carry8 << 21;
  carry9 = s[9] >> 21; s[10] += carry9; s[9] -= carry9 << 21;
  carry10 = s[10] >> 21; s[11] += carry10; s[10] -= carry10 << 21;
#endif
  t[0] = s[0] >> 0;
  t[1] = s[0] >> 8;
  t[2] = (s[0] >> 16) | (s[1] << 5);
  t[3] = s[1] >> 3;
  t[4] = s[1] >> 11;
  t[5] = (s[1] >> 19) | (s[2] << 2);
  t[6] = s[2] >> 6;
  t[7] = (s[2] >> 14) | (s[3] << 7);
  t[8] = s[3] >> 1;
  t[9] = s[3] >> 9;
  t[10] = (s[3] >> 17) | (s[4] << 4);
  t[11] = s[4] >> 4;
  t[12] = s[4] >> 12;
  t[13] = (s[4] >> 20) | (s[5] << 1);
  t[14] = s[5] >> 7;
  t[15] = (s[5] >> 15) | (s[6] << 6);
  t[16] = s[6] >> 2;
  t[17] = s[6] >> 10;
  t[18] = (s[6] >> 18) | (s[7] << 3);
  t[19] = s[7] >> 5;
  t[20] = s[7] >> 13;
  t[21] = s[8] >> 0;
  t[22] = s[8] >> 8;
  t[23] = (s[8] >> 16) | (s[9] << 5);
  t[24] = s[9] >> 3;
  t[25] = s[9] >> 11;
  t[26] = (s[9] >> 19) | (s[10] << 2);
  t[27] = s[10] >> 6;
  t[28] = (s[10] >> 14) | (s[11] << 7);
  t[29] = s[11] >> 1;
  t[30] = s[11] >> 9;
  t[31] = s[11] >> 17;
}
