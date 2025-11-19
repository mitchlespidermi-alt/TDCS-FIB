/*
 * RecSubSubN_sid.h
 *
 * Code generation for model "RecSubSubN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:23:45 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: RecSubSubN_sf.c
 */

/* statically allocated instance data for model: RecSubSubN */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_RecSubSubN_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_RecSubSubN_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 38530415U);
    ssSetChecksumVal(rts, 1, 2278427616U);
    ssSetChecksumVal(rts, 2, 192287094U);
    ssSetChecksumVal(rts, 3, 2169008304U);
  }
}
