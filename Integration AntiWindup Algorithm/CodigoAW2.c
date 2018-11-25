/* CÓDIGO DEL CONTROLADOR */
/* Las variables utilizadas deben haber sido DECLARADAS PREVIAMENTE en "Declaraciom_de_variables.c" */ 

 /* La medida salida del sistema ya está declarada como Yk */
 /* La señal de control ya está declarado como Ureal */
 /* Hay disponible una salida auxiliar ya declarada como POutAux */
 /* El tiempo de muestreo ya está declarado como Tm */

  tiempo = ssGetT(S);  /* Tiempo de la simulación */
 
  if(tiempo<100.) Rk=70;
  else if(tiempo<200.) Rk=100;
  else if(tiempo<350.) Rk=500;
  else Rk=70;
  
    
  
  if(tiempo<100.) Ureal=Ueq;
  else{
 
     
  ek=Rk-Yk;
  
  u1k=A0*ek;
  u2k=p1*u2k1+A1*ek1;
  u3k=p2*u3k1+A2*ek1;
  uk=u1k+u2k+u3k;

  Ureal=uk+Ueq;
  
  
  if(Ureal>Umax) {
  Ureal=Umax;
  u1k1=u1k;
  u3k1=u3k;
  ek1=ek;
  u2k=u2k1;}/*No actualizamos el efecto integral*/

  else if(Ureal<Umin) {
  Ureal=Umin;
  u1k1=u1k;
  u3k1=u3k;
  ek1=ek;
  u2k=u2k1;}

  else {  
  u1k1=u1k;
  u3k1=u3k;
  ek1=ek;
  u2k1=u2k;}
  


 
  
  }
  POutAux=Rk;
  