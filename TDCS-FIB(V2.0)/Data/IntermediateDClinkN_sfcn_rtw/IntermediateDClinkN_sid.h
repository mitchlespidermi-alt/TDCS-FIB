/*
 * IntermediateDClinkN_sid.h
 *
 * Code generation for model "IntermediateDClinkN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:25:25 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: IntermediateDClinkN_sf.c
 */

/* statically allocated instance data for model: IntermediateDClinkN */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_IntermediateDClinkN_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_IntermediateDClinkN_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1278083293U);
    ssSetChecksumVal(rts, 1, 3467109646U);
    ssSetChecksumVal(rts, 2, 714541861U);
    ssSetChecksumVal(rts, 3, 1571476783U);
  }
}
