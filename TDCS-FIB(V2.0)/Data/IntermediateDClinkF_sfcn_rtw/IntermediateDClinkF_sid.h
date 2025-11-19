/*
 * IntermediateDClinkF_sid.h
 *
 * Code generation for model "IntermediateDClinkF_sf".
 *
 * Model version              : 1.160
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:17:59 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: IntermediateDClinkF_sf.c
 */

/* statically allocated instance data for model: IntermediateDClinkF */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_IntermediateDClinkF_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_IntermediateDClinkF_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 670605268U);
    ssSetChecksumVal(rts, 1, 6542070U);
    ssSetChecksumVal(rts, 2, 4139484209U);
    ssSetChecksumVal(rts, 3, 2187813741U);
  }
}
