/*
 * InverterTvF_sid.h
 *
 * Code generation for model "InverterTvF_sf".
 *
 * Model version              : 1.155
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 10:50:47 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: InverterTvF_sf.c
 */

/* statically allocated instance data for model: InverterTvF */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_InverterTvF_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_InverterTvF_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 3869760267U);
    ssSetChecksumVal(rts, 1, 3721739213U);
    ssSetChecksumVal(rts, 2, 1247245921U);
    ssSetChecksumVal(rts, 3, 1700313930U);
  }
}
