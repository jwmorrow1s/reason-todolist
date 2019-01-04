open TodoTypes;

let component = ReasonReact.statelessComponent("todoItem");

let str = ReasonReact.string;

let make = (~todo, ~showCompleted, _children) => {
    ...component,

    render: _ => {
        (!showCompleted && todo.completed) ? str("") :
        <div className="contentRow todoRow">
            <CheckBox color="black" checked=todo.completed />
            <HorizontalSpacer size="50" />
            <div className="todoItem">{str(todo.description)}</div>
        </div> /*</contentRow>*/
    }
};