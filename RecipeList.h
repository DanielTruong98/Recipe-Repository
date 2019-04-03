#include "List.h"


class RecipeList
{
public:
//Declaration
  RecipeList();
//setters
  void addRecipe();
  void removeRecipe(std::string rName);
  void changeRecipe(int select);

//getters
  int recipeAmount();
  bool listFull();
  bool listEmpty();
  Recipe* getCurrentRecipe();
  Recipe* getNextRecipe();
  Recipe* getPreviousRecipe();
  //Sort recipe by name
  //Search through recipes
private:
  std::vector<Recipe> listRecipe;
  Recipe* current;
  Recipe* nextRecipe;
  Recipe* previousRecipe;
};
