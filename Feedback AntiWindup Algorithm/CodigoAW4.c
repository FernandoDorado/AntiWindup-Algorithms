/* CÓDIGO DEL CONTROLADOR */
/* Las variables utilizadas deben haber sido DECLARADAS PREVIAMENTE en "Declaraciom_de_variables.c" */ 

 /* La medida salida del sistema ya está declarada como Yk */
 /* La señal de control ya está declarado como Ureal */
 /* Hay disponible una salida auxiliar ya declarada como POutAux */
 /* El tiempo de muestreo ya está declarado como Tm */

  tiempo = ssGetT(S);  /* Tiempo de la simulación */
 
   /* Incluir código para calcular Ureal */ 
  
  /*Modifico referencia*/
  if (tiempo < 100.) Rk=70.;
  else if(tiempo<250.) Rk=100.;
  else if(tiempo<350.) Rk=500.;
  else Rk=70;
  
  /*Calculo de la señal de la salida real*/
  
  if(tiempo<100.)
    Ureal=Ueq;
  else /*Activo señal de control*/
  {
  /*Cálculo error actual*/
  ek=Rk-Yk;
  

  /*CONTROL ABSOLUTO*/
 /* Calculo incremento señal de control ui(k)=uik1*pi+Ai*ek1 */
  u1k=A1*ek;
  u2k=1*u2k1+A2*ek1;
  u3k=-0.7936*u3k1+A3*ek1;
  
 
  uk=u1k+u2k+u3k+Intss;
  
  /*Actualizamos errores y actuaciones*/
    u1k1=u1k;
    u2k1=u2k;
    u3k1=u3k;
    ek1=ek;    
 
    Ukss=Ueq+uk;

 /*Saturacion de la señal de control*/
   
 if(Ukss>Umax)
     Ureal=Umax;
    else if(Ukss<Umin)
      Ureal=Umin;   
 else 
     Ureal=Ukss;
    
  Intss+=(Tm/Tt)*(Ureal-Ukss);
 
    
    
    
  /*CONTROL NORMAL*/
 /*Calculo incremento señal de control*/