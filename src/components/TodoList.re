type todo = {
    description: string,
    id: int,
    completed: bool
};

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
  
let component = ReasonReact.reducerComponent("todoList");

let str = ReasonReact.string;

let iter = ref(0);
let inc = (i) => {
    i := i^ + 1;
    i^;
};

let make = (_children) => {
    ...component,

    initialState: () => {count: 0, showCompleted: true, todoText: "", todos: []},

    reducer: (action, state) => 
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
            | ToggleComplete(id) => ReasonReact.Update((id => {
                let theTodo = List.find(todo => todo.id == id, state.todos);
                let updatedTodo = {...theTodo, completed: !theTodo.completed};
                let todosWithoutMatch = List.filter(todo => todo.id != id, state.todos);
                let updatedList = [updatedTodo] @ todosWithoutMatch;
                let sortedList = List.sort((first, second) => first.id - second.id, updatedList);
                {...state, todos: sortedList};
            })(id));
        },
    
    render: ({state, send}) => {
        {
            <div id="list_component">
                <VerticalSpacer size="50" />
                <div className="contentRow">
                {str("New Todo:")}
                <input 
                    id="todo-input"
                    value=state.todoText
                    placeholder="Write something to do..."
                    onChange=((evt) => send(UpdateText(ReactEvent.Form.target(evt)##value)))
                    onKeyDown=((evt) => 
                        if(ReactEvent.Keyboard.key(evt) == "Enter"){
                            send(AddTodo({description: state.todoText, completed: false, id: inc(iter)}));
                        })
                    />
                </div>/*</content-row>*/
                <VerticalSpacer size="25" />
                <div id="todo-list">
                (   List.length(state.todos) < 1 ? str("Nothing yet") :
                    ReasonReact.array(Array.of_list(
                        List.map(todo => 
                            <div key={string_of_int(todo.id)} onClick=(_ => send(ToggleComplete(todo.id)))>
                                <TodoItem description={todo.description} showCompleted=state.showCompleted completed={todo.completed}/>
                                     
                            </div>, state.todos)
                    ))
                )
                </div>/*</todo-list>*/
                <button 
                    id="hide-button"
                    onClick=(_ => send(ToggleHidden))
                    >{str("Hide Completed Todos")}</button>
                <div id="todo-count">{str("Todos left: " ++ string_of_int(List.length(List.filter(todo => !todo.completed, state.todos))))}</div>
            </div>/*</list-component>*/
        }
    }
};
