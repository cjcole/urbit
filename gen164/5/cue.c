/* j/3/cue.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_ray T_r;

  static u2_noun                                                  //  produce
  _cue_in(u2_wire wir_r,
          u2_atom _a,                                              //  retain
          u2_atom _b,                                              //  retain
          u2_noun _m)                                              //  retain
  {
    u2_bag a, b, m;
    u2_fill(&a, _a);
    u2_fill(&b, _b);
    u2_fill(&m, _m);

    u2_bag p, q, r;

    if ( _0 == j2_mbc(Pt3, cut)(wir_r, 0, b.n, 1, a.n) ) {
      u2_bag x, c;

      u2_fill(&x, j2_mbc(Pt1, inc)(wir_r, b.n));
      u2_fill(&c, j2_mby(Pt5, rub)(wir_r, x.n, a.n));

      u2_fill(&p, j2_mbc(Pt1, inc)(wir_r, u2_h(c.n)));
      u2_fill(&q, u2_rx(wir_r, u2_t(c.n)));
      // q = u2_cs_save(wir_r, T_r, 0, b, q);
      u2_fill(&r, j2_mcc(Pt4, by, put)(wir_r, m.n, b.n, u2_t(c.n)));

      u2_rz(wir_r, c.n); u2_rz(wir_r, x.n); 
      u2_empty(&c); u2_empty(&x);
    }
    else {
      u2_bag c, l;
      u2_fill(&c, j2_mbc(Pt1, add)(wir_r, _2, b.n));
      u2_fill(&l, j2_mbc(Pt1, inc)(wir_r, b.n));

      if ( _0 == j2_mbc(Pt3, cut)(wir_r, 0, l.n, 1, a.n) ) {
        u2_bag u, v, w;
        u2_bag x, y;

        u2_fill(&u, _cue_in(wir_r, a.n, c.n, m.n));
        u2_fill(&x, j2_mbc(Pt1, add)(wir_r, u2_h(u.n), c.n));
        u2_fill(&v, _cue_in(wir_r, a.n, x.n, u2_t(u2_t(u.n))));

        u2_fill(&w, u2_bc(wir_r, u2_rx(wir_r, u2_h(u2_t(u.n))), 
                          u2_rx(wir_r, u2_h(u2_t(v.n)))));

        u2_fill(&y, j2_mbc(Pt1, add)(wir_r, u2_h(u.n), u2_h(v.n)));

        u2_fill(&p, j2_mbc(Pt1, add)(wir_r, _2, y.n));
        u2_fill(&q, w.n);
        // q = u2_cs_save(wir_r, T_r, 0, b, w);
        u2_fill(&r, j2_mcc(Pt4, by, put)(wir_r, u2_t(u2_t(v.n)), b.n, w.n));

        u2_rz(wir_r, u.n); u2_rz(wir_r, v.n);
        u2_rz(wir_r, x.n); u2_rz(wir_r, y.n);
        u2_empty(&u); u2_empty(&v); u2_empty(&w); 
        u2_empty(&x); u2_empty(&y);
      }
      else {
        u2_bag d, x;
        u2_fill(&d, j2_mby(Pt5, rub)(wir_r, c.n, a.n));
        u2_fill(&x, j2_mcc(Pt4, by, get)(wir_r, m.n, u2_t(d.n)));
        // u2_weak T = u2_cs_find(wir_r, T_r, 0, u2_t(d));

        u2_fill(&p, j2_mbc(Pt1, add)(wir_r, _2, u2_h(d.n)));
        if ( u2_nul == x.n ) {
          return u2_bl_bail(wir_r, c3__exit);
        }
#if 0
        else if ( (u2_none == T) || (u2_no == u2_sing(T, x.n)) ) {
          printf("fail!\n");
          return u2_bl_bail(wir_r, c3__fail);
        }
#endif
        u2_fill(&q, u2_rx(wir_r, u2_t(x.n)));
        u2_fill(&r, u2_rx(wir_r, m.n));

        u2_rz(wir_r, x.n); u2_rz(wir_r, d.n);
        u2_empty(&x); u2_empty(&d);
      }
      u2_rz(wir_r, l.n); u2_rz(wir_r, c.n);
      u2_empty(&l); u2_empty(&c);
    }
    u2_noun result = u2_bt(wir_r, p.n, q.n, r.n);
    u2_empty(&p); u2_empty(&q); u2_empty(&r);
    return result;
  }

  u2_noun                                                         //  transfer
  j2_mby(Pt5, cue)(u2_wire wir_r, 
                   u2_atom a)                                     //  retain
  {
#if 0
    if ( 0 == T_r ) {
      T_r = u2_cs_make(wir_r);
    }
#endif
    {
      u2_noun x = _cue_in(wir_r, a, _0, u2_nul);
      u2_noun y = u2_rx(wir_r, u2_h(u2_t(x)));

      u2_rz(wir_r, x);
      return y;
    }
  }
  u2_noun                                                         //  transfer
  j2_mb(Pt5, cue)(u2_wire wir_r, 
                  u2_noun cor)                                    //  retain
  {
    u2_noun a;

    if ( (u2_none == (a = u2_frag(u2_cv_sam, cor))) ) {
      return u2_bl_bail(wir_r, c3__fail);
    } else {
      return j2_mby(Pt5, cue)(wir_r, a);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pt5, cue)[] = {
    { ".2", c3__hevy, j2_mb(Pt5, cue), Tier3, u2_none, u2_none },
    { }
  };
