open TodoTypes;

let component = ReasonReact.statelessComponent("todoInput");

let str = ReasonReact.string;

let iter = ref(0);
let inc = (i) => {
    i := i^ + 1;
    i^;
};

let make = (~toParent, ~parentState, _) => {
    ...component,

    render: _ => {
        <div className="contentRow">
        {str("New Todo:")}
        <input 
            id="todo-input"
            value=parentState.todoText
            placeholder="Write something to do..."
            onChange=((evt) => toParent(UpdateText(ReactEvent.Form.target(evt)##value)))
            onKeyDown=((evt) => 
                if(ReactEvent.Keyboard.key(evt) == "Enter"){
                    toParent(AddTodo({description: parentState.todoText, completed: false, id: inc(iter)}));
                })
            />
        </div>/*</content-row>*/
    }
};