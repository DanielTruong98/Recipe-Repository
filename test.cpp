#include <cstdlib>
#include "RecipeList.h"

using std::cout;
using std::endl;

int main()
{
  RecipeList currentList = RecipeList();

  currentList.addRecipe();
  Recipe* temporary = currentList.findRecipe("val");
  temporary->printRecipeName();

  currentList.addRecipe();


  temporary->getRecipeName();
  temporary->printIngredients();
  currentList.removeRecipe("val");
  currentList.findRecipe("val");
  Recipe* temporary2 = currentList.findRecipe("val2");
  temporary2->printRecipeName();
  return 0;
}
