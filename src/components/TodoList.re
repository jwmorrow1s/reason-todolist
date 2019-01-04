open TodoTypes;
  
let component = ReasonReact.reducerComponent("todoList");

let str = ReasonReact.string;

let make = (_children) => {
    ...component,

    initialState: () => {count: 0, showCompleted: true, todoText: "",todos: [] },

    reducer: (action, state) => {
            let removeTodoById = (id: int) : state => {
                let theTodo = List.find(todo => todo.id == id, state.todos);
                let updatedTodo = {...theTodo, completed: !theTodo.completed};
                let todosWithoutMatch = List.filter(todo => todo.id != id, state.todos);
                let updatedList = [updatedTodo] @ todosWithoutMatch;
                let sortedList = List.sort((first, second) => first.id - second.id, updatedList);
                {...state, todos: sortedList};
            };
            switch(action){
                | ToggleHidden => ReasonReact.Update({...state, showCompleted: !state.showCompleted})
                | AddTodo(todo) => {
                    ReasonReact.Update({...state, count: state.count + 1,
                        todos: String.length(todo.description) > 0 ? state.todos @ [todo] : state.todos,
                        todoText: ""});
                }
                | UpdateText(text) => {
                    ReasonReact.Update({...state, todoText: text});
                }
                | ToggleComplete(id) => ReasonReact.Update(removeTodoById(id));
            }
        },
    
    render: ({state, send}) => {
        <div id="list_component">
            <VerticalSpacer size="50" />
            <TodoInput parentState=state toParent=send />
            <VerticalSpacer size="25" />
            <div id="todo-list">
            (   List.length(state.todos) < 1 ? str("Nothing yet") :
                <Todos todos=state.todos toParent=send showCompleted=state.showCompleted />
            )
            </div>/*</todo-list>*/
            <button 
                id="hide-button"
                onClick=(_ => send(ToggleHidden))
                >{str("Hide Completed Todos")}</button>
            <div id="todo-count">{str("Todos left: " ++ string_of_int(List.length(List.filter(todo => !todo.completed, state.todos))))}</div>
        </div>/*</list-component>*/
    }
    
};
