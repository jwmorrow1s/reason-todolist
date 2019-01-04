open TodoTypes;

let component = ReasonReact.statelessComponent("todos");

let make = (~todos: list(todo), ~toParent, ~showCompleted, _) => { 
    ...component,
    render:  (_) => {
        ReasonReact.array(Array.of_list(
                        List.map(todo => 
                            <div key={string_of_int(todo.id)} onClick=(_ => toParent(ToggleComplete(todo.id)))>
                                <TodoItem  todo showCompleted /> 
                            </div>, todos)
                    ))
    }
    
};