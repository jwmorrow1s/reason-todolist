type todo = {
    description: string,
    completed: bool,
    id: int
}

type state = {
    count: int,
    showCompleted: bool,
    todos: list(todo), 
    todoText: string
};

type action = 
  | ToggleHidden
  | AddTodo(todo)
  | UpdateText(string)
  | ToggleComplete(int);

let initialState = {
      count: 0,
      showCompleted: true,
      todoText: "",
      todos: []
};