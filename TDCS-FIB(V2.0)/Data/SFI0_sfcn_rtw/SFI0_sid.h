/*
 * SFI0_sid.h
 *
 * Code generation for model "SFI0_sf".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Apr 06 14:43:03 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: SFI0_sf.c
 */

/* statically allocated instance data for model: SFI0 */
{
  extern P_SFI0_T SFI0_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_SFI0_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_SFI0_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &SFI0_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 3117883720U);
    ssSetChecksumVal(rts, 1, 2376473107U);
    ssSetChecksumVal(rts, 2, 1699550713U);
    ssSetChecksumVal(rts, 3, 2288751716U);
  }
}
