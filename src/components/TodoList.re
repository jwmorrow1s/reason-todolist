type state = {
    count: int,
    showCompleted: bool,
    todos: list(string),
    todoText: string
};

type todo = {
    description: string,
    completed: bool
};

type action = 
  | ToggleHidden
  | AddTodo(string)
  | UpdateText(string);
  
let component = ReasonReact.reducerComponent("todoList");

let str = ReasonReact.string;

let make = (_children) => {
    ...component,

    initialState: () => {count: 0, showCompleted: true, todoText: "", todos: []},

    reducer: (action, state) => 
        switch(action){
            | ToggleHidden => ReasonReact.Update({...state, showCompleted: !state.showCompleted})
            | AddTodo(todoText) => {
                ReasonReact.Update({...state, count: state.count + 1,
                     todos: String.length(todoText) > 0 ? state.todos @ [todoText] : state.todos,
                      todoText: ""});
            }
            | UpdateText(text) => {
                ReasonReact.Update({...state, todoText: text});
            };
        },
    
    render: ({state, send}) => {
        let iter = ref(0);
        let inc = (i) => {
            i := i^ + 1;
            i^;
        };
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
                            send(AddTodo(state.todoText));
                        })
                    />
                </div>/*</content-row>*/
                <VerticalSpacer size="25" />
                <div id="todo-list">
                (   List.length(state.todos) < 1 ? str("Nothing yet") :
                    ReasonReact.array(Array.of_list(
                        List.map(todo => 
                            <TodoItem key={string_of_int(inc(iter))} description={todo} />,
                                 state.todos)
                    ))
                )
                </div>/*</todo-list>*/
                <button id="hide-button">{str("Hide Completed Todos")}</button>
                <div id="todo-count">{str("Todos left: " ++ string_of_int(state.count))}</div>
            </div>/*</list-component>*/
        }
    }
};
