#include <stdio.h>
#include <math.h>

    
int main() {
    const double half_life = 5730; // Half-life of Carbon-14
    double initial_mass;
    
    /********************************************************************/
    /* Carbon-14 Decay Model
     * 
     * Exponential equation,
     *         P(t) = P₀eᵏᵗ
     * where,
     *      P₀   -> Original mass
     *      P(t) -> Mass at half-life
     *      e    -> Euler's constant
     *      k    -> Decay constant
     *      t    -> Time
     * 
     * STEP-1:
     *      Derive decay constant by equating initial mass and half-life mass
     *      P₀      = 1   (initial mass of the artifact)
     *      P(5730) = 1/2 (mass of the artifact at half-life)
     *      
     *      Substituting the values in the exponential function
     *      
     *      P(t) = P₀eᵏᵗ
     * 
     *      -> 1/2 = 1e⁵³⁷⁰ᵏ
     *      
     *      Taking logn on both sides, we get,
     *      -> ln(1/2) = ln(e⁵³⁷⁰ᵏ)
     * 
     *      -> ln(1/2)     5370K
     *         -------  = -------
     *          5370       5370
     * 
     *      -> k = ln(1/2) / 5370
     *          = -0.000120968
     *      
     * STEP-2:
     *      Derive t using known values and decay constant
     *      P₀ = 1 (initial mass of the artifact)
     *      P(t) = x grams
     *      using exponential equation,
     *      x = 1e⁽⁻⁰.⁰⁰⁰¹²⁰⁹⁶⁸⁾ᵗ
     *      t = logn(x) / -0.000120968
     */
    initial_mass = log(0.5) / half_life;
    
    double time;
    double remaining_carbon;
    
    printf("How much carbon has been lost (0-100%%): ");
    scanf("%lf", &remaining_carbon);
    
    remaining_carbon = (100 - remaining_carbon) / 100;
    
    time = log(remaining_carbon) / initial_mass;
    
    printf("The object is %.6f years old.", time);
    
    return 0;
}