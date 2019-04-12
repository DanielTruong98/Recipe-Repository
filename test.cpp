#include <cstdlib>
#include "RecipeList.h"

int main()
{
  /*
  Recipe Sandwich("Sandwich", 5, 10);
  Sandwich.setRecipeName("Sandwich");
  Sandwich.setCookingTime(5);
  Sandwich.setPreparationTime(10);
  Sandwich.addIngredient("Bread");
  Sandwich.addIngredient("Cheese");
  Sandwich.addIngredient("Ham");
  Sandwich.getRecipeName();
  Sandwich.getCookingTime();
  Sandwich.getPreparationTime();
  Sandwich.getIngredientSize();
  Sandwich.printIngredients();
  */
  RecipeList currentList = RecipeList();
  currentList.addRecipe();

  Recipe* temporary = currentList.getCurrentRecipe();
  temporary->getRecipeName();

  temporary->printIngredients();
  currentList.findRecipe("1");
  currentList.removeRecipe("1");
  currentList.findRecipe("1");
  return 0;
}
